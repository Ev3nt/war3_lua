#pragma once

#include <Windows.h>
#include <vector>

#include "LuaMachine.h"

typedef void   jNothing;
typedef UINT32 jBoolean;
typedef UINT32 jCode;
typedef UINT32 jHandle;
typedef INT32  jInteger;
typedef UINT32 jReal;
typedef UINT32 jString;
typedef UINT32 jTrigger;

const jBoolean jTrue = 1;
const jBoolean jFalse = 0;
const jHandle jNull = 0;

typedef DWORD HUNIT;
typedef DWORD HWIDGET;
typedef DWORD HLIGHTNING;
typedef DWORD HPLAYER;
typedef DWORD HEFFECT;
typedef DWORD HLOCATION;
typedef DWORD HEFFECTTYPE;
typedef DWORD HRECT;
typedef DWORD HWEATHEREFFECT;
typedef DWORD HCAMERAFIELD;
typedef DWORD HBOOLEXPR;
typedef DWORD HSOUND;
typedef DWORD HCAMERASETUP;
typedef DWORD HITEMTYPE;
typedef DWORD HCONDITIONFUNC;
typedef DWORD HAIDIFFICULTY;
typedef DWORD HALLIANCETYPE;
typedef DWORD HATTACKTYPE;
typedef DWORD HBLENDMODE;
typedef DWORD HDAMAGETYPE;
typedef DWORD HDIALOGEVENT;
typedef DWORD HFGAMESTATE;
typedef DWORD HFOGSTATE;
typedef DWORD HGAMEDIFFICULTY;
typedef DWORD HGAMEEVENT;
typedef DWORD HGAMESPEED;
typedef DWORD HGAMETYPE;
typedef DWORD HIGAMESTATE;
typedef DWORD HLIMITOP;
typedef DWORD HMAPCONTROL;
typedef DWORD HMAPDENSITY;
typedef DWORD HMAPFLAG;
typedef DWORD HMAPSETTING;
typedef DWORD HMAPVISIBILITY;
typedef DWORD HPATHINGTYPE;
typedef DWORD HPLACEMENT;
typedef DWORD HPLAYERCOLOR;
typedef DWORD HPLAYEREVENT;
typedef DWORD HPLAYERGAMERESULT;
typedef DWORD HPLAYERSCORE;
typedef DWORD HPLAYERSLOTSTATE;
typedef DWORD HPLAYERSTATE;
typedef DWORD HPLAYERUNITEVENT;
typedef DWORD HRACE;
typedef DWORD HRACEPREFERENCE;
typedef DWORD HRARITYCONTROL;
typedef DWORD HSOUNDTYPE;
typedef DWORD HSTARTLOCPRIO;
typedef DWORD HTEXMAPFLAGS;
typedef DWORD HUNITEVENT;
typedef DWORD HUNITSTATE;
typedef DWORD HUNITTYPE;
typedef DWORD HVERSION;
typedef DWORD HVOLUMEGROUP;
typedef DWORD HWEAPONTYPE;
typedef DWORD HWIDGETEVENT;
typedef DWORD HDESTRUCTABLE;
typedef DWORD HDEFEATCONDITION;
typedef DWORD HFOGMODIFIER;
typedef DWORD HFORCE;
typedef DWORD HGROUP;
typedef DWORD HIMAGE;
typedef DWORD HITEM;
typedef DWORD HITEMPOOL;
typedef DWORD HLEADERBOARD;
typedef DWORD HMULTIBOARD;
typedef DWORD HQUEST;
typedef DWORD HREGION;
typedef DWORD HTEXTTAG;
typedef DWORD HTIMER;
typedef DWORD HTIMERDIALOG;
typedef DWORD HTRACKABLE;
typedef DWORD HUBERSPLAT;
typedef DWORD HUNITPOOL;
typedef DWORD HFILTERFUNC;
typedef DWORD HDIALOG;
typedef DWORD HBUTTON;
typedef DWORD HHASHTABLE;
typedef DWORD HGAMECACHE;
typedef DWORD HGAMESTATE;
typedef DWORD HHANDLE;
typedef DWORD HABILITY;
typedef DWORD HEVENTID;
typedef DWORD HQUESTITEM;
typedef DWORD HMULTIBOARDITEM;
typedef DWORD HTRIGGERACTION;
typedef DWORD HTRIGGERCONDITION;
typedef DWORD HEVENT;
typedef DWORD HAGENT;
typedef DWORD HTERRAINDEFORMATION;

enum JASS_TYPE {
	TYPE_NONE = 0,
	TYPE_BOOLEAN = 'B',
	TYPE_CODE = 'C',
	TYPE_HANDLE = 'H',
	TYPE_INTEGER = 'I',
	TYPE_REAL = 'R',
	TYPE_STRING = 'S',
	TYPE_NOTHING = 'V',
};

inline jReal to_jReal(float fX) {
	return *(jReal*)&fX;
}

inline float from_jReal(jReal val) {
	return *(float*)&val;
}

inline jString to_jString(LPCSTR lpString) {
	UINT32* string = new UINT32[8];

	string[2] = (UINT32)&string[0];
	string[7] = (UINT32)&lpString[0];

	return (jString)string;
}

inline LPCSTR from_jString(jString string) {
	if (!string) {
		return NULL;
	}

	string = ((jString*)string)[2];

	if (!string) {
		return NULL;
	}

	return (LPCSTR)((jString*)string)[7];
}

DWORD to_Code(lua_State* l, int index);

inline jInteger to_ID(LPCSTR lpID) {
	return (lpID[0] << 24) + (lpID[1] << 16) + (lpID[2] << 8) + lpID[3];
}

//---------------------------------------------------------

#ifndef _JassNatives_h
#define _JassNatives_h
class JASSNATIVE {
public:
	JASSNATIVE(DWORD address, LPCSTR params);
	JASSNATIVE();

	bool is_valid();
	bool is_sleep();
	void set_sleep(bool sleep);
	const std::vector<JASS_TYPE>& get_params();
	const JASS_TYPE& get_rettype();
	DWORD get_address();

	DWORD call(const std::vector<DWORD> params);
private:
	DWORD _address;
	std::vector<JASS_TYPE> _params;
	JASS_TYPE _rettype;
	bool has_sleep = false;
};
#endif

//---------------------------------------------------------

JASSNATIVE& get_native(LPCSTR lpName);

void jassNativesInitialize();