#include "JassNatives.h"

#include "Variables.h"
#include "Mem.h"
#include "JassMachine.h"

std::map<LPCSTR, JASSNATIVE> jassnatives;
std::map<DWORD, JASS_OPLIST> triggers;

DWORD to_Code(lua_State* l, int index) {
	DWORD key = (DWORD)lua_topointer(l, index);
	auto it = triggers.find(key);

	if (it != triggers.end()) {
		return (DWORD)&it->second;
	}

	JASS_OPLIST& oplist = triggers[key];

	BYTE reg = 0xD8;
	oplist.addop(OPTYPE_MOVRLITERAL, reg, pushFunctionRef(l, index), OPCODE_VARIABLE_INTEGER);
	oplist.addop(OPTYPE_PUSH, reg);
	oplist.addop(OPTYPE_MOVRLITERAL, reg, (DWORD)l, OPCODE_VARIABLE_INTEGER);
	oplist.addop(OPTYPE_PUSH, reg);
	oplist.addop(OPTYPE_STARTLUATHREAD);
	oplist.addop(OPTYPE_MOVRR);
	oplist.addop(OPTYPE_RETURN);

	return oplist.getcode();
}

//---------------------------------------------------------


#pragma pack(push)
#pragma pack(1)
struct asm_opcode_5 {
	BYTE opcode;
	DWORD value;
};
#pragma pack(pop)

struct asm_register_native_function {
private:
	asm_opcode_5 push;
	asm_opcode_5 mov_edx;
	asm_opcode_5 mov_ecx;
	asm_opcode_5 call;
public:
	bool verify() {
		return ((push.opcode == 0x68) && (mov_edx.opcode == 0xBA) && (mov_ecx.opcode == 0xB9) && (call.opcode == 0xE8));
	}

	const char* get_params() {
		return (const char*)(push.value);
	}

	const char* get_name() {
		return (const char*)(mov_edx.value);
	}

	uintptr_t get_address() {
		return (uintptr_t)(mov_ecx.value);
	}
};

//---------------------------------------------------------

JASSNATIVE::JASSNATIVE(DWORD address, LPCSTR params) : _address(address) {
	LPCSTR it = params++;
	bool is_end = false;

	for (; *it; it++) {
		if (*it == ')') {
			is_end = true;
		}
		else if (isupper(*it)) {
			if (is_end) {
				_rettype = (JASS_TYPE)*it;

				break;
			}
			else {
				_params.push_back((JASS_TYPE)*it);
			}
		}
	}
}

JASSNATIVE::JASSNATIVE() : _address(NULL), _rettype(TYPE_NONE) {}

bool JASSNATIVE::is_valid() {
	return _rettype != TYPE_NONE ? true : false;
}

bool JASSNATIVE::is_sleep() {
	return has_sleep;
}

void JASSNATIVE::set_sleep(bool sleep) {
	has_sleep = sleep;
}

const std::vector<JASS_TYPE>& JASSNATIVE::get_params() {
	return _params;
}

const JASS_TYPE& JASSNATIVE::get_rettype() {
	return _rettype;
}

DWORD JASSNATIVE::get_address() {
	return _address;
}

DWORD JASSNATIVE::call(const std::vector<DWORD> params) {
	uintptr_t func_address = _address;
	DWORD retval;
	uintptr_t esp_ptr;
	size_t params_size = params.size() * sizeof DWORD;

	_asm {
		sub esp, params_size
		mov esp_ptr, esp
	}

	memcpy((LPVOID)esp_ptr, (LPVOID)params.data(), params_size);

	_asm {
		call[func_address]
		mov esp, esp_ptr
		add esp, params_size
		mov retval, eax
	}

	return retval;
}

//---------------------------------------------------------

JASSNATIVE& get_native(LPCSTR lpName) {
	for (auto& e : jassnatives) {
		if (!strcmp(e.first, lpName)) {
			return e.second;
		}
	}

	return *(JASSNATIVE*)NULL;
}

void jassNativesInitialize() {
	for (asm_register_native_function* ptr = (asm_register_native_function*)MakePtr(gameBase, _jassNativesList); ptr->verify(); ptr++) {
		jassnatives[ptr->get_name()] = JASSNATIVE(ptr->get_address(), ptr->get_params());
	}
}