#include "pch.h"
#include "JassNatives.h"
#include "LuaMachine.h"
#include "JassMachine.h"

namespace Jass {
	std::unordered_map<std::string, JASSNATIVE> jassnatives;
	std::unordered_map<DWORD, JassMachine::JASS_OPLIST> jassopcodes;

	//---------------------------------------------------------

	UINT ToCode(lua_State* l, int index) {
		DWORD key = (DWORD)lua_topointer(l, index);
		
		auto it = jassopcodes.find(key);

		if (it != jassopcodes.end()) {
			return it->second.GetCode();
		}

		JassMachine::JASS_OPLIST& oplist = jassopcodes[key];

		BYTE reg = 0xD8;
		oplist.AddOperation(JassMachine::OPTYPE_MOVRLITERAL, reg, LuaMachine::PushFunctionRef(l, index), JassMachine::OPCODE_VARIABLE_INTEGER);
		oplist.AddOperation(JassMachine::OPTYPE_PUSH, reg);
		oplist.AddOperation(JassMachine::OPTYPE_STARTLUATHREAD);
		oplist.AddOperation(JassMachine::OPTYPE_MOVRR);
		oplist.AddOperation(JassMachine::OPTYPE_RETURN);

		return oplist.GetCode();
	}

	//---------------------------------------------------------

	JASSNATIVE::JASSNATIVE(LPVOID address, std::string params) : m_address(address) {
		for (size_t i = 1; i < params.size(); i++) {
			if (params[i] == ')') {
				break;
			}

			size_t beg = i++;
			for (; i < params.size() && !isupper(params[i]) && params[i] != ')'; i++);

			std::string type = params.substr(beg, i-- - beg);
			if (type[0] == 'H') {
				type = type.substr(1, type.size() - 2);

				LuaMachine::handlemetatypes[type] = true;
			}

			m_params.push_back(type);
		}

		if (size_t beg = params.find(')') + 1) {
			std::string type = params.substr(beg);
			if (type[0] == 'H') {
				type = type.substr(1, type.size() - 2);

				LuaMachine::handlemetatypes[type] = true;
			}

			m_returntype = type;
		}
	}

	JASSNATIVE::JASSNATIVE() : m_address(NULL) {}

	bool JASSNATIVE::IsValid() {
		return m_address && !m_returntype.empty();
	}

	const std::vector<std::string>& JASSNATIVE::GetParams() {
		return m_params;
	}

	const std::string& JASSNATIVE::GetReturnType() {
		return m_returntype;
	}

	PVOID JASSNATIVE::GetAddress() {
		return m_address;
	}

	DWORD JASSNATIVE::Invoke(LPVOID params, size_t size) {
		if (!params && size) {
			return NULL;
		}

		PVOID function_address = m_address;
		size_t params_size = size * sizeof UINT;
		LPVOID esp_ptr;

		DWORD result;

		_asm {
			sub esp, params_size
			mov esp_ptr, esp
		}

		if (size) {
			CopyMemory(esp_ptr, params, params_size);
		}

		_asm {
			call [function_address]
			mov result, eax

			mov esp, esp_ptr
			add esp, params_size
		}

		return result;
	}

	//---------------------------------------------------------

	JASSNATIVE& GetNative(std::string name) {
		for (auto& native : jassnatives) {
			if (native.first == name) {
				return native.second;
			}
		}

		JASSNATIVE nothing;

		return nothing;
	}

	void JassNativesParse() {
		size_t size = 0;
		JassMachine::PJASS_THREAD_LOCAL jassThreadLocal = JassMachine::GetJassThreadLocal();
		for (auto native = jassThreadLocal->firstNative; native < jassThreadLocal->lastNative; native = native->next) {
			//printf("%s %s = %d\n", native->name, native->arguments, ++size);
			jassnatives[native->name] = JASSNATIVE(native->callback, native->arguments);
		}

	}

	void JassNativesReset() {
		std::unordered_map<std::string, JASSNATIVE>().swap(jassnatives);
	}

	void JassOpcodesReset() {
		jassopcodes.clear();
	}
}