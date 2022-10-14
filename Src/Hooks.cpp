#include "pch.h"
#include "Hooks.h"
#include "Offsets.h"
#include "LuaMachine.h"

namespace Hooks {
	enum class EventTypes : UINT {
		EVENT_CNET_GAME_START = 0x4009007e,
		EVENT_CNET_GAME_LEAVE = 0x40090081,
	};

	enum class ObserverRegistryTypes : UINT {
		GAME_START_LOADING =  0x00402000, // 010000000010000000000000
		GAME_FINISH_LOADING2 =  0x130800, // 000100110000100000000000
		GAME_FINISH_LOADING = 0x00140800  // 000101000000100000000000
	};

	typedef struct {
		PVOID  vtable;   // 0x0
		size_t refCount; // 0x4
		UINT*  registry; // 0x8 ObserverRegistry 
	} CObserver;

	typedef struct {
		PVOID	vtable;		// 0x0
		UINT	unk_04;		// 0x4
		UINT	id;			// 0x8
		PVOID	object;		// 0xC
		DWORD	data;		// 0x10 | serves as keyCode for KeyEvent
	} CEvent;

	BOOL CGameProcessEvent(CObserver* observer, CEvent* cevent) {
		return pOffsets[(UINT)Offset::CGameEventHandler] ? this_call<BOOL>(pOffsets[(UINT)Offset::CGameEventHandler], observer, cevent) : NULL;
	}

	DWORD GetWarcraftVersionKey() {
		return pOffsets[(UINT)Offset::GetWarcraftVersionKey] ? std_call<DWORD>(pOffsets[(UINT)Offset::GetWarcraftVersionKey]) : NULL;
	}

	BOOL __fastcall GlobalDeallocator(UINT handle) {
		lua_State* l = LuaMachine::GetMainState(false);
		if (l) {
			LuaMachine::DeleteUserdataByHandle(l , handle);
		}

		return pOffsets[(UINT)Offset::GlobalDeallocator] ? this_call<BOOL>(pOffsets[(UINT)Offset::GlobalDeallocator], handle) : NULL;
	}

	//--------------------------------------------

	DWORD GetLuaVersionKey() {
		return *(DWORD*)GAME_ID;
	}

	BOOL __fastcall CGameEventHandler(CObserver* observer, PVOID, CEvent* cevent) {
		if (observer && cevent) {
			switch (cevent->id) {
			case (UINT)EventTypes::EVENT_CNET_GAME_START:
				if (*observer->registry & 0x100800) { // When map loading finished (000100000000100000000000)
					LuaMachine::StartLua();
				}

				break;
			case (UINT)EventTypes::EVENT_CNET_GAME_LEAVE:
				LuaMachine::DestroyLua();

				break;
			}
		}

		return CGameProcessEvent(observer, cevent);
	}

	void SetHooksState(bool flag) {
		Detour::SetState(flag, &pOffsets[(UINT)Offset::CGameEventHandler], (UINT_PTR)CGameEventHandler);
		Detour::SetState(flag, &pOffsets[(UINT)Offset::GetWarcraftVersionKey], (UINT_PTR)GetLuaVersionKey);
		Detour::SetState(flag, &pOffsets[(UINT)Offset::GlobalDeallocator], (UINT_PTR)GlobalDeallocator);
	}
}