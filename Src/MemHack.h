#pragma once

#include <Windows.h>
#include <vector>
#include <string>

#ifndef _MemHack_h_
#define _MemHack_h_
typedef struct VECTOR3 {
	VECTOR3(float x, float y, float z) : _x(x), _y(y), _z(z) {}
	VECTOR3& operator=(const VECTOR3& from) {
		if (this == &from) {
			return *this;
		}

		this->_x = from._x;
		this->_y = from._y;
		this->_z = from._z;

		return *this;
	}
	float _x;
	float _y;
	float _z;
} *PVECTOR3, * LPVECTOR3;
#endif

void printChat(LPCSTR text, float duration);
void printfChat(float duration, LPCSTR format, ...);

float GetUnitArmor(UINT unit);
void SetUnitArmor(UINT unit, float armorValue);
float GetUnitMaxLife(UINT unit);
void SetUnitMaxLife(UINT unit, float hp);
float GetUnitMaxMana(UINT unit);
void SetUnitMaxMana(UINT unit, float mana);
float GetUnitLifeRegen(UINT unit);
void SetUnitLifeRegen(UINT unit, float lifeRegen);
float GetUnitManaRegen(UINT unit);
void SetUnitManaRegen(UINT unit, float manaRegen);
UINT GetUnitBaseDamage(UINT unit);
void SetUnitBaseDamage(UINT unit, UINT damage);
float GetUnitAttackSpeed(UINT unit);
void SetUnitAttackSpeed(UINT unit, float speed);
BOOL UnitResetAttackCooldown(UINT unit);
LPCSTR GetItemBaseNameById(UINT itemId);
void SetItemBaseNameById(UINT itemId, LPCSTR name);
LPCSTR GetItemBaseUbertipById(UINT itemId);
void SetItemBaseUbertipById(UINT itemId, LPCSTR ubertip);
LPCSTR GetItemBaseIconPathById(UINT itemId);
void SetItemBaseIconPathById(UINT itemId, LPCSTR path);
PVECTOR3 GetMouseWorldPos();
float GetMouseWorldX();
float GetMouseWorldY();
float GetMouseWorldZ();
PVECTOR3 GetEffectPos(UINT object);
float GetEffectX(UINT object);
float GetEffectY(UINT object);
float GetEffectZ(UINT object);
void SetEffectPos(UINT object, const VECTOR3& pos);
void SetEffectX(UINT object, float x);
void SetEffectY(UINT object, float y);
void SetEffectZ(UINT object, float z);

void MemHack_reset();