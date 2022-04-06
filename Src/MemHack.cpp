#include "Global.h"
#include "MemHack.h"

auto GetDataNode = (UINT(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x4c8520);
auto GetAgentBaseData = (UINT(__fastcall*)(UINT, UINT, UINT, UINT))((UINT_PTR)gameBase + 0x2b88a0);
auto GetAgentBaseUIData = (UINT(__fastcall*)(UINT, UINT, UINT, UINT))((UINT_PTR)gameBase + 0x319810);
UINT pUnitUIDataNode = (UINT)gameBase + 0xab58d4;
UINT pGameState = (UINT)gameBase + 0xab65f4;
UINT pGameClass1 = (UINT)gameBase + 0xab7788;
UINT pGameClass2 = (UINT)gameBase + 0xab4f80;

std::vector<std::string> stringPool;

void printChat(LPCSTR text, float duration) {
	((void(__fastcall*)(UINT, UINT, UINT, UINT, LPCSTR, UINT, UINT))((UINT)gameBase + 0x2f8e40))(*(UINT*)pGameClass2, NULL, 0, 0, text, *(UINT*)&duration, 0xFFFFFFFF);
}

void printfChat(float duration, LPCSTR format, ...) {
	char text[8192] = { NULL };
	
	va_list args;
	va_start(args, format);
	vsprintf_s(text, format, args);
	va_end(args);

	printChat(text, duration);
}

UINT GetAgentBaseDataById(UINT pAgentDataNode, UINT agentId) {
	UINT retval = NULL;
	
	if (agentId) {
		UINT pData = GetDataNode((UINT)&agentId);

		if (pData) {
			return GetAgentBaseData(pAgentDataNode, NULL, pData, (UINT)&agentId);
		}
	}

	return retval;
}

UINT GetAgentBaseUIDataById(UINT pAgentDataUINode, UINT agentId) {
	UINT retval = NULL;

	if (agentId) {
		UINT pData = GetDataNode((UINT)&agentId);

		if (pData) {
			return GetAgentBaseUIData(pAgentDataUINode, NULL, pData, (UINT)&agentId);
		}
	}

	return retval;
}

UINT GetWidgetBaseDataByIdCachingEx(UINT pDataNode, UINT index, UINT id, BOOL mode) {
	UINT pData = NULL;

	if (id) {
		switch (mode)
		{
		case 0:
			pData = GetAgentBaseDataById(pDataNode, id);

			break;
		case 1:
			pData = GetAgentBaseUIDataById(pDataNode, id);

			break;
		}
	}

	return pData;
}

UINT GetWidgetBaseUIDataByIdCaching(UINT pDataNode, UINT id) {
	return GetWidgetBaseDataByIdCachingEx(pDataNode, 3, id, 1);
}

void SetWidgetBaseUIStringParamById(UINT pDataNode, UINT id, UINT pointerLevel, UINT offset, LPCSTR string) {
	if (!id) {
		return;
	}

	UINT pData = GetWidgetBaseUIDataByIdCaching(pDataNode, id);
	if (!pData) {
		return;
	}

	pData += offset;

	switch (pointerLevel)
	{
	case 0:
		for (size_t i = 0; i < stringPool.size(); i++) {
			if (stringPool[i].c_str() == *(LPCSTR*)pData) {
				stringPool.erase(stringPool.begin() + i);

				break;
			}
		}

		stringPool.push_back(string);

		*(LPCSTR*)pData = stringPool[stringPool.size() - 1].c_str();

		break;
	case 1:
		if (!*(UINT*)pData) {
			stringPool.push_back({0, 0, 0, 0});

			*(LPCSTR*)pData = stringPool[stringPool.size() - 1].c_str();
		}

		for (size_t i = 0; i < stringPool.size(); i++) {
			if (stringPool[i].c_str() == **(LPCSTR**)pData) {
				stringPool.erase(stringPool.begin() + i);

				break;
			}
		}

		stringPool.push_back(string);

		**(LPCSTR**)pData = stringPool[stringPool.size() - 1].c_str();

		break;
	}
}

LPCSTR GetWidgetBaseUIStringParamById(UINT pDataNode, UINT id, UINT pointerLevel, UINT offset) {
	LPCSTR retval = NULL;
	
	if (id) {
		UINT pData = GetWidgetBaseUIDataByIdCaching(pDataNode, id);
		if (pData) {
			pData = *(UINT*)(pData + offset);
			if (pData) {
				if (pointerLevel == 1) {
					pData = *(UINT*)pData;
				}

				if (pData)
				{
					retval = (LPCSTR)pData;
				}
			}
		}
	}
	return retval;
}

LPCSTR GetItemBaseUIStringParamById(UINT itemId, UINT pointerLevel, UINT offset) {
	return GetWidgetBaseUIStringParamById(pUnitUIDataNode, itemId, pointerLevel, offset);
}

void SetItemBaseUIStringParamById(UINT itemId, UINT pointerLevel, UINT offset, LPCSTR string) {
	SetWidgetBaseUIStringParamById(pUnitUIDataNode, itemId, pointerLevel, offset, string);
}

UINT ConvertHandleToObject(UINT handle) {
	return handle ? *(UINT*)(*(UINT*)(*(UINT*)(*(UINT*)pGameState + 0x1c) + 0x19c) + handle * 0xc - 0x2fffff * 4) : NULL;
}

UINT GetUnitAddressFloatsRelated(UINT pConvertedHandle, UINT step) {
	return pConvertedHandle ? *(UINT*)(*(UINT*)(pConvertedHandle + step) * 8 + *(UINT*)(*(UINT*)pGameClass1 + 0xc) + 4) : NULL;
}

UINT GetUnitAttackAbility(UINT unit) {
	UINT pData = ConvertHandleToObject(unit);

	return pData ? *(UINT*)(pData + 0x1e8) : NULL;
}

UINT GetUnitAttackOffsetValue(UINT unit, UINT offset) {
	UINT pData = GetUnitAttackAbility(unit);

	return pData ? *(UINT*)(pData + offset) : 0;
}

void SetUnitAttackOffsetValue(UINT unit, UINT offset, UINT value) {
	UINT pData = GetUnitAttackAbility(unit);

	if (pData) {
		*(UINT*)(pData + offset) = value;
	}
}

float GetUnitAttackSpeed(UINT unit) {
	UINT speed = GetUnitAttackOffsetValue(unit, 0x1b0);

	return *(float*)&speed;
}

void SetUnitAttackSpeed(UINT unit, float speed) {
	SetUnitAttackOffsetValue(unit, 0x1b0, *(UINT*)&speed);
}

BOOL UnitResetAttackCooldown(UINT unit) {
	UINT pData = GetUnitAttackAbility(unit);
	
	if (pData) {
		pData = *(UINT*)(pData + 0x1e4);

        if (pData) {
			*(float*)(pData + 0x1e4) = 0.f;

			return true;
        }
    }

	return false;
}

PVECTOR3 GetObjectPos(UINT object) {
	UINT pData = ConvertHandleToObject(object);

	return pData ? (PVECTOR3)(*(UINT*)(pData + 0x28) + 0xC0) : NULL;
}

float GetObjectX(UINT object) {
	PVECTOR3 objectPos = GetObjectPos(object);

	return objectPos ? objectPos->_x : 0.f;
}

float GetObjectY(UINT object) {
	PVECTOR3 objectPos = GetObjectPos(object);

	return objectPos ? objectPos->_y : 0.f;
}

float GetObjectZ(UINT object) {
	PVECTOR3 objectPos = GetObjectPos(object);

	return objectPos ? objectPos->_z : 0.f;
}

void SetObjectPos(UINT object, const VECTOR3& pos) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->operator=(pos);
}

void SetObjectX(UINT object, float x) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->_x = x;
}

void SetObjectY(UINT object, float y) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->_y = y;
}

void SetObjectZ(UINT object, float z) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->_z = z;
}

//------------------------------------------------------------------------
// Lua references

float GetUnitArmor(UINT unit) {
	UINT pData = ConvertHandleToObject(unit);

	return pData ? *(float*)(pData + 0xe0) : 0.f;
}

void SetUnitArmor(UINT unit, float armorValue) {
	UINT pData = ConvertHandleToObject(unit);

	if (pData) {
		*(float*)(pData + 0xe0) = armorValue;
	}
}

float GetUnitMaxLife(UINT unit) {
	UINT pData = ConvertHandleToObject(unit);
	float hp = 0.f;

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xa0);
		if (pData) {
			hp = *(float*)(pData + 0x84);
		}
	}

	return hp;
}

void SetUnitMaxLife(UINT unit, float hp) {
	UINT pData = ConvertHandleToObject(unit);

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xa0);
		if (pData) {
			*(float*)(pData + 0x84) = hp;
		}
	}
}

float GetUnitMaxMana(UINT unit) {
	UINT pData = ConvertHandleToObject(unit);
	float hp = 0.f;

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xc0);
		if (pData) {
			hp = *(float*)(pData + 0x84);
		}
	}

	return hp;
}

void SetUnitMaxMana(UINT unit, float mana) {
	UINT pData = ConvertHandleToObject(unit);

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xc0);
		if (pData) {
			*(float*)(pData + 0x84) = mana;
		}
	}
}

float GetUnitLifeRegen(UINT unit) {
	UINT pData = ConvertHandleToObject(unit);
	float lifeRegen = 0.f;

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xa0);
		if (pData) {
			lifeRegen = *(float*)(pData + 0x7c);
		}
	}

	return lifeRegen;
}

void SetUnitLifeRegen(UINT unit, float lifeRegen) {
	UINT pData = ConvertHandleToObject(unit);

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xa0);
		if (pData) {
			*(float*)(pData + 0x7c) = lifeRegen;
		}
	}
}

float GetUnitManaRegen(UINT unit) {
	UINT pData = ConvertHandleToObject(unit);
	float manaRegen = 0.f;

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xc0);
		if (pData) {
			manaRegen = *(float*)(pData + 0x7c);
		}
	}

	return manaRegen;
}

void SetUnitManaRegen(UINT unit, float manaRegen) {
	UINT pData = ConvertHandleToObject(unit);

	if (pData) {
		pData = GetUnitAddressFloatsRelated(pData, 0xc0);
		if (pData) {
			*(float*)(pData + 0x7c) = manaRegen;
		}
	}
}

UINT GetUnitBaseDamage(UINT unit) {
	return GetUnitAttackOffsetValue(unit, 0xa0);
}

void SetUnitBaseDamage(UINT unit, UINT damage) {
	SetUnitAttackOffsetValue(unit, 0xa0, damage);
}

LPCSTR GetItemBaseNameById(UINT itemId) {
	return GetItemBaseUIStringParamById(itemId, 1, 0x2c);
}

void SetItemBaseNameById(UINT itemId, LPCSTR name) {
	SetItemBaseUIStringParamById(itemId, 1, 0x2c, name);
}

LPCSTR GetItemBaseUbertipById(UINT itemId) {
	return GetItemBaseUIStringParamById(itemId, 1, 0x26c);
}

void SetItemBaseUbertipById(UINT itemId, LPCSTR ubertip) {
	SetItemBaseUIStringParamById(itemId, 1, 0x26c, ubertip);
}

LPCSTR GetItemBaseIconPathById(UINT itemId) {
	return GetItemBaseUIStringParamById(itemId, 1, 0x24c);
}

void SetItemBaseIconPathById(UINT itemId, LPCSTR path) {
	SetItemBaseUIStringParamById(itemId, 1, 0x24c, path);
}

PVECTOR3 GetMouseWorldPos() {
	UINT pWorldFrame = *(UINT*)(*(UINT*)pGameClass2 + 0x3bc);

	return pWorldFrame ? (PVECTOR3)(pWorldFrame + 0x310) : NULL;
}

float GetMouseWorldX() {
	PVECTOR3 mousePos = GetMouseWorldPos();

	return mousePos ? mousePos->_x : 0.f;
}

float GetMouseWorldY() {
	PVECTOR3 mousePos = GetMouseWorldPos();

	return mousePos ? mousePos->_y : 0.f;
}

float GetMouseWorldZ() {
	PVECTOR3 mousePos = GetMouseWorldPos();

	return mousePos ? mousePos->_z : 0.f;
}

PVECTOR3 GetEffectPos(UINT object) {
	return GetObjectPos(object);
}

float GetEffectX(UINT object) {
	return GetObjectX(object);
}

float GetEffectY(UINT object) {
	return GetObjectY(object);
}

float GetEffectZ(UINT object) {
	return GetObjectZ(object);
}

void SetEffectPos(UINT object, const VECTOR3& pos) {
	SetObjectPos(object, pos);
}

void SetEffectX(UINT object, float x) {
	SetObjectX(object, x);
}

void SetEffectY(UINT object, float y) {
	SetObjectY(object, y);
}

void SetEffectZ(UINT object, float z) {
	SetObjectZ(object, z);
}

//------------------------------------------------------------------------

void MemHack_reset() {
	stringPool.clear();
}