#pragma once

#include <Windows.h>

#ifndef _WarcraftFunctions_h
#define _WarcraftFunctions_h
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
} * PVECTOR3, * LPVECTOR3;
#endif

PVECTOR3 GetMouseWorldPos();
float GetMouseWorldX();
float GetMouseWorldY();
float GetMouseWorldZ();

UINT_PTR ConvertHandleToObject(UINT handle);

PVECTOR3 GetObjectPos(UINT_PTR object);
float GetObjectX(UINT_PTR object);
float GetObjectY(UINT_PTR object);
float GetObjectZ(UINT_PTR object);

void SetObjectPos(UINT_PTR object, const VECTOR3& pos);
void SetObjectX(UINT_PTR object, float x);
void SetObjectY(UINT_PTR object, float y);
void SetObjectZ(UINT_PTR object, float z);