#include "JassNatives.h"
#include "JassMachine.h"
#include "LuaMachine.h"
#include "Global.h"

std::unordered_map<LPCSTR, JASSNATIVE> jassnatives;
std::unordered_map<DWORD, JASS_OPLIST> triggers;

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

	PCSTR get_params() {
		return (PCSTR)(push.value);
	}

	PCSTR get_name() {
		return (PCSTR)(mov_edx.value);
	}

	PVOID get_address() {
		return (PVOID)(mov_ecx.value);
	}
};

UINT GetGroupByHandle(UINT handle) {
	return ((UINT(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x3bea30))(handle);
}

UINT GetTriggerByHandle(UINT handle) {
	return ((UINT(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x3bdef0))(handle);
}

UINT GetTimerByHandle(UINT handle) {
	return ((UINT(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x3bd710))(handle);
}

//---------------------------------------------------------

UINT to_code(lua_State* l, int index, UINT objectHandle) {
	DWORD key = (DWORD)lua_topointer(l, index);

	auto it = triggers.find(key);

	if (it != triggers.end()) {
		return it->second.getcode();
	}

	JASS_OPLIST& oplist = triggers[key];

	BYTE reg = 0xD8;
	oplist.addop(OPTYPE_MOVRLITERAL, reg, objectHandle, OPCODE_VARIABLE_INTEGER);
	oplist.addop(OPTYPE_PUSH, reg);
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

JASSNATIVE::JASSNATIVE(LPVOID address, LPCSTR params) : _address(address) {
	LPCSTR it = params++;

	for (; *it; it++) {
		if (*it != ')') {
			if (isupper(*it)) {
				_params.push_back((JASS_TYPE)*it);
			}
		}
		else {
			break;
		}
	}

	_rettype = (JASS_TYPE)*(++it);
}

JASSNATIVE::JASSNATIVE() : _address(NULL), _rettype(TYPE_NONE) {}

bool JASSNATIVE::is_valid() {
	return _rettype != TYPE_NONE;
}

const std::vector<JASS_TYPE>& JASSNATIVE::get_params() {
	return _params;
}

const JASS_TYPE& JASSNATIVE::get_rettype() {
	return _rettype;
}

PVOID JASSNATIVE::get_address() {
	return _address;
}

BOOL JASSNATIVE::call(LPVOID params, size_t size) {
	PVOID function_address = _address;
	size_t params_size = size * sizeof UINT;
	LPVOID esp_ptr;

	BOOL result;

	_asm {
		sub esp, params_size
		mov esp_ptr, esp
	}

	memcpy(esp_ptr, params, params_size);

	_asm {
		call [function_address]
		mov result, eax

		mov esp, esp_ptr
		add esp, params_size
	}

	return result;
}

//---------------------------------------------------------

JASSNATIVE invalid;

JASSNATIVE& get_native(LPCSTR name) {
	for (auto& native : jassnatives) {
		if (!strcmp(native.first, name)) {
			return native.second;
		}
	}

	return invalid;
}

auto jassNativesList = (asm_register_native_function*)((UINT_PTR)gameBase + 0x3d4025);

void jassNativesParse() {
	for (asm_register_native_function* ptr = jassNativesList; ptr->verify(); ptr++) {
		jassnatives[ptr->get_name()] = JASSNATIVE(ptr->get_address(), ptr->get_params());
	}
}

void JassNatives_reset() {
	triggers.clear();
}