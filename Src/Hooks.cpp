#include "pch.h"
#include "Hooks.h"
#include "Offsets.h"
#include "LuaMachine.h"
#include "Logger.h"

#define WM_PROGRAM_RECEIVE_LAUNCHER WM_USER + 1
#define WM_PROGRAM_CONTROL WM_USER + 2

#define WP_START_BYTE 0
#define WP_RECEIVE_BYTE 1
#define WP_END_BYTE 2

#define WP_START_UINT32 3
#define WP_RECEIVE_UINT32 4
#define WP_END_UINT32 5

#define WP_START_STRING 10
#define WP_RECEIVE_STRING 11
#define WP_SEND_STRING WP_RECEIVE_STRING
#define WP_END_STRING 12

#define WP_LUA_CODES 50
#define WP_LUA_DEV_MODE WP_LUA_CODES + 1
#define WP_LUA_CONSOLE_MODE WP_LUA_CODES + 2
#define WP_LUA_DEVCONSOLE_MODE WP_LUA_CODES + 3

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



	// Special for Unryze :D
	// P.s. don't touch it, Ev3nt, it's a bible.
	std::string sReceived;

	LRESULT SendMessageToWindow( HWND _hwnd, uint32_t _Msg, WPARAM _wParam, LPARAM _lParam, bool defcall )
    {
        if ( pOffsets[ (UINT)Offset::OnProcMain ] != NULL && !defcall )
        {
            return fast_call<LRESULT>( pOffsets[ (UINT)Offset::OnProcMain ], _hwnd, _Msg, _wParam, _lParam );
        }

        return DefWindowProc( _hwnd, _Msg, _wParam, _lParam );
    }

	LRESULT __fastcall GameProc( HWND _hWnd, uint32_t _Msg, WPARAM _wParam, LPARAM _lParam )
	{
		bool IsDefaultCall = false;

		switch ( _Msg )
		{
			case WM_PROGRAM_CONTROL:
			{
				switch( _wParam )
				{
					case WP_START_BYTE:
					{
						//bVecReceived.clear( );
						break;
					}
					case WP_RECEIVE_BYTE:
					{
						//bVecReceived.push_back( (BYTE)( _lParam & 0xFF ) );
						break;
					}
					case WP_END_BYTE:
					{
						//if ( GetCommandId( bVecReceived ) == 0 )
						//{
						//	Jass::CustomNatives::InitCustomNatives( true );
						//	//Debug::General::EnableConsole( IsDebug = Debug::General::IsConsole = true );
						//	//MessageBoxA( NULL, "startnatives", NULL, NULL );
						//}

						//bVecReceived.clear( );
						//Detour::InstallEx( false, &Features::GameWindow::pOffsets[ Features::GameWindow::Enum::Offsets::OnProcMain ], (uintptr_t)GameProc );
						//sReceived = std::string( );
						break;
					}
					case WP_START_STRING:
					{
						//sReceived = std::string( );
						break;
					}
					case WP_RECEIVE_STRING:
					{
						//sReceived += (char)_lParam;
						break;
					}
					case WP_END_STRING:
					{
						/*std::string find = "-loadfile";
						std::size_t pos = sReceived.find( find );

						if ( pos != std::string::npos )
						{
							std::string loadFile = sReceived.substr( pos + find.length( ) + 1 );

							for ( std::size_t i = 0; i < loadFile.size( ); i++ ) 
							{
								if( loadFile[i] == '\\')
								{
									loadFile.insert( i, "\\" );
									i++;
								}
							}

							pos = loadFile.find_first_of( "\"" );

							if ( pos != std::string::npos )
							{
								loadFile = loadFile.substr( pos + 1 );
							}

							pos = loadFile.find_first_of( "\"" );

							if ( pos != std::string::npos )
							{
								loadFile = loadFile.substr( 0, pos );
							}
						}*/

						break;
					}
					case WP_LUA_DEV_MODE:
					{
						developerMode = !developerMode;

						break;
					}
					case WP_LUA_CONSOLE_MODE:
					case WP_LUA_DEVCONSOLE_MODE:
					{
						if (_wParam == WP_LUA_DEVCONSOLE_MODE) {
							developerMode = true;
						}

						if (!Logger::isConsole) {
							Logger::OpenConsole(developerMode ? "UjAPI Lua Console [Developer]" : "UjAPI Lua Console");

							system("cls");
							printf("%s\n%s (%s)\n\n", LUA_COPYRIGHT, WAR3_LUA, WAR3_LUA_VERSION_NAME);
						}
						else {
							Logger::CloseConsole();
						}

						break;
					}

				}
				break;
			}
		}

		return SendMessageToWindow( _hWnd, _Msg, _wParam, _lParam, IsDefaultCall );
	}

	// End of bible. You can touch code below this line. :D

	void SetHooksState(bool flag) {
		Detour::SetState(flag, &pOffsets[(UINT)Offset::CGameEventHandler], (UINT_PTR)CGameEventHandler);
		Detour::SetState(flag, &pOffsets[(UINT)Offset::GetWarcraftVersionKey], (UINT_PTR)GetLuaVersionKey);
		Detour::SetState(flag, &pOffsets[(UINT)Offset::GlobalDeallocator], (UINT_PTR)GlobalDeallocator);
		Detour::SetState(flag, &pOffsets[(UINT)Offset::OnProcMain], (UINT_PTR)GameProc);
	}
}