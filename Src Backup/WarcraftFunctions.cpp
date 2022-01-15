#include "WarcraftFunctions.h"
#include "Warcraft.h"

PVECTOR3 GetMouseWorldPos() {
	CGameUI* gameUI = GetGameUI();

	return gameUI ? (PVECTOR3)&gameUI->WorldFrameWar3->MouseWorldX : NULL;
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

UINT_PTR ConvertHandleToObject(UINT handle) {
	return handle ? *(UINT_PTR*)(*(UINT_PTR*)((GetGameWar3()->field001C) + 0x19C) + handle * 0xC - 0x2FFFFF * 4) : NULL;
}

PVECTOR3 GetObjectPos(UINT_PTR object) {
	return object ? (PVECTOR3)(*(UINT_PTR*)(object + 0x28) + 0xC0) : NULL;
}

float GetObjectX(UINT_PTR object) {
	PVECTOR3 objectPos = GetObjectPos(object);

	return objectPos ? objectPos->_x : 0.f;
}

float GetObjectY(UINT_PTR object) {
	PVECTOR3 objectPos = GetObjectPos(object);

	return objectPos ? objectPos->_y : 0.f;
}

float GetObjectZ(UINT_PTR object) {
	PVECTOR3 objectPos = GetObjectPos(object);

	return objectPos ? objectPos->_z : 0.f;
}

void SetObjectPos(UINT_PTR object, const VECTOR3& pos) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->operator=(pos);
}

void SetObjectX(UINT_PTR object, float x) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->_x = x;
}

void SetObjectY(UINT_PTR object, float y) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->_y = y;
}

void SetObjectZ(UINT_PTR object, float z) {
	PVECTOR3 objectPos = GetObjectPos(object);

	if (!objectPos) {
		return;
	}

	objectPos->_z = z;
}