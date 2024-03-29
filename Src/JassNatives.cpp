#include "pch.h"
#include "JassNatives.h"
#include "LuaMachine.h"
#include "JassMachine.h"

namespace Jass {
	std::unordered_map<std::string, JASSNATIVE> jassnatives;

	//---------------------------------------------------------

	UINT ToCode(lua_State* l, int index, int keyIndex) {
		LuaMachine::GetGlobalTable(l, "_LUA_WARCRAFT_CODES", true, false);
		lua_pushvalue(l, keyIndex);

		if (lua_rawget(l, -2) == LUA_TNIL) {
			lua_pop(l, 1);

			lua_newtable(l);
			lua_pushvalue(l, keyIndex);
			lua_pushvalue(l, -2);
			lua_rawset(l, -4);
		}

		JassMachine::JASS_OPLIST* oplist;
		DWORD key = (DWORD)lua_topointer(l, index);
		if (lua_rawgeti(l, -1, key) == LUA_TNIL) {
			lua_pop(l, 1);

			lua_newtable(l);
			lua_pushvalue(l, -1);
			lua_rawseti(l, -3, key);

			lua_pushvalue(l, index);
			lua_setfield(l, -2, "callback");

			oplist = new JassMachine::JASS_OPLIST;

			BYTE reg = 0xD8;
			oplist->AddOperation(OPCODE_TYPE::MOVRLITERAL, reg, LuaMachine::PushFunctionByKey(l, index, key), OPCODE_VARIABLE::TYPE_INTEGER);
			oplist->AddOperation(OPCODE_TYPE::PUSH, reg);
			oplist->AddOperation(OPCODE_TYPE::STARTLUATHREAD);
			oplist->AddOperation(OPCODE_TYPE::MOVRR);
			oplist->AddOperation(OPCODE_TYPE::RETURN);

			lua_pushlightuserdata(l, oplist);
			lua_setfield(l, -2, "oplist");

			luaL_setmetatable(l, JASS2LUA);
		}

		lua_getfield(l, -1, "oplist");
		oplist = (JassMachine::JASS_OPLIST*)lua_touserdata(l, -1);
		lua_pop(l, 4);


		return oplist->GetCode();
	}

	//---------------------------------------------------------

	JASSNATIVE::JASSNATIVE(LPVOID address, std::string params) : m_address(address), m_realsCount(0) {
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

			m_realsCount += (size_t)(type == "R");
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

	const size_t JASSNATIVE::GetRealsCount() {
		return m_realsCount;
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
		JassMachine::PJASS_THREAD_LOCAL jassThreadLocal = JassMachine::GetJassThreadLocal();
		for (auto native = jassThreadLocal->firstNative; native < jassThreadLocal->lastNative; native = native->next) {
			jassnatives[native->name] = JASSNATIVE(native->callback, native->arguments);
		}

	}

	void JassNativesReset() {
		jassnatives.clear();
	}
}