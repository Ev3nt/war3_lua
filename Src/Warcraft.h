#pragma once

#include <Windows.h>

#ifndef _Warcraft_h
#define _Warcraft_h
typedef struct {
	DWORD unk;
	DWORD max_size;
	DWORD array;

	UINT32 get(DWORD index) {
		DWORD result = 0;

		if (index < max_size) {
			result = array + 0x10 * index;
			++* (UINT32*)(result + 0xC);
		}

		return result;
	}

} STRING_TABLE, * PSTRING_TABLE;

typedef struct {
	BYTE unk[4];
	DWORD counter;
	DWORD* codes; // max_size = 1024

	DWORD push_code(DWORD address) {
		codes[counter] = address;
		
		return counter++;
	}

	DWORD Size() {
		return counter;
	}
} CODE_TABLE, * PCODE_TABLE;

typedef struct {
	BYTE rettype;
	BYTE type;
	BYTE reg;
	BYTE opcode;
	DWORD value;
} JASS_OPCODE, * PJASS_OPCODE;

typedef struct {
	BYTE unk0[0x20];
	PJASS_OPCODE opcode;
	BYTE unk1[0x10];
	UINT has_sleep;
	BYTE unk2[0x2818];
	DWORD index;
	BYTE unk3[0x20];
	PSTRING_TABLE string_table;
	BYTE unk4[0x10];
	PCODE_TABLE code_table;
	BYTE unk5[0x1C];
} JASS_INSTANCE, * PJASS_INSTANCE;

typedef struct {
	BYTE unk0[18];
	char access_key[12];
	DWORD wacraft_key;
	char language_ltype[8];
	BYTE unk1[8];
	DWORD language_key[8];
	char language[8];

} NetProviderLTCP, *PNetProviderLTCP;

typedef struct {
	int VirtualTable;
	int field0004;
	int field0008;
	int field000C;
	int field0010;
	int field0014;
	int field0018;
	int field001C;
	int field0020;
	int field0024;
	int field0028;
	int field002C;
	int field0030;
	int field0034;
	int field0038;
	int field003C;
	int field0040;
	int field0044;
	int field0048;
	int field004C;
	int field0050;
	int field0054;
	int field0058;
	int field005C;
	int field0060;
	int field0064;
	int field0068;
	int field006C;
	int field0070;
	int field0074;
	int field0078;
	int field007C;
	int field0080;
	int field0084;
	int field0088;
	int field008C;
	int field0090;
	int field0094;
	int field0098;
	int field009C;
	int field00A0;
	int field00A4;
	int field00A8;
	int field00AC;
	int field00B0;
} CFrame, * PCFrame;
#define FRAMELAYOUT(f) ((UINT)f + sizeof(CFrame))

struct CGameUI : CFrame {
	int VirtualTable;
	int field00B8;
	int field00BC;
	int field00C0;
	int field00C4;
	int field00C8;
	int field00CC;
	int field00D0;
	int field00D4;
	int field00D8;
	int field00DC;
	int field00E0;
	int field00E4;
	int field00E8;
	int field00EC;
	int field00F0;
	int field00F4;
	int field00F8;
	int field00FC;
	int field0100;
	int field0104;
	int field0108;
	int field010C;
	int field0110;
	int field0114;
	int field0118;
	int field011C;
	int field0120;
	int field0124;
	int field0128;
	int field012C;
	int field0130;
	int field0134;
	int field0138;
	int field013C;
	int field0140;
	int field0144;
	int field0148;
	int field014C;
	int field0150;
	int field0154;
	int field0158;
	int field015C;
	int field0160;
	int field0164;
	int field0168;
	int field016C;
	int field0170;
	int field0174;
	int field0178;
	int field017C;
	int field0180;
	int field0184;
	int field0188;
	int field018C;
	int field0190;
	int field0194;
	int field0198;
	int field019C;
	int field01A0;
	int field01A4;
	int field01A8;
	int isUserInputEnabled;
	int isUserInterfaceEnabled;
	int field01B4;
	int field01B8;
	int field01BC;
	int field01C0;
	int field01C4;
	int field01C8;
	int field01CC;
	int field01D0;
	int field01D4;
	int field01D8;
	int field01DC;
	int field01E0;
	int field01E4;
	int field01E8;
	int field01EC;
	int field01F0;
	int field01F4;
	int field01F8;
	int field01FC;
	int field0200;
	int field0204;
	int field0208;
	int field020C;
	int field0210;
	int field0214;
	int field0218;
	int field021C;
	int field0220;
	int field0224;
	int field0228;
	int field022C;
	int field0230;
	int field0234;
	int field0238;
	int field023C;
	int field0240;
	int field0244;
	int field0248;
	int field024C;
	int field0250;
	int Camera;
	int isInGameMenu;
	int field025C;
	int isGamePaused;
	int field0264;
	int field0268;
	int field026C;
	int field0270;
	int field0274;
	int field0278;
	int field027C;
	int field0280;
	int field0284;
	int field0288;
	int field028C;
	int isDragSelectionEnabled;
	int isDragSelectionVisible;
	int isPreSelectionEnabled;
	int isPreSelectionVisible;
	int isSelectionEnabled;
	int isSelectionVisible;
	int field02A8;
	int field02AC;
	int field02B0;
	int field02B4;
	int field02B8;
	int field02BC;
	int field02C0;
	int field02C4;
	int field02C8;
	int field02CC;
	int field02D0;
	int field02D4;
	int field02D8;
	int field02DC;
	int field02E0;
	int field02E4;
	int field02E8;
	int field02EC;
	int field02F0;
	int field02F4;
	int field02F8;
	int field02FC;
	int field0300;
	int field0304;
	int field0308;
	int field030C;
	float MouseWorldX; // Use from WorldFrame
	float MouseWorldY;
	float MouseWorldZ;
	int field031C;
	int field0320;
	int field0324;
	int field0328;
	int field032C;
	int field0330;
	int field0334;
	int field0338;
	int field033C;
	int field0340;
	int field0344;
	int field0348;
	int field034C;
	int field0350;
	int field0354;
	int field0358;
	int field035C;
	int field0360;
	int field0364;
	int field0368;
	int field036C;
	int field0370;
	int field0374;
	int field0378;
	int field037C;
	int field0380;
	int field0384;
	int field0388;
	int field038C;
	int field0390;
	int field0394;
	int field0398;
	int field039C;
	int field03A0;
	int field03A4;
	int field03A8;
	int field03AC;
	int field03B0;
	int field03B4;
	int field03B8;
	CGameUI* WorldFrameWar3; // CWorldFrameWar3*
	CGameUI* Minimap; // CFrame*
	CGameUI* InfoBar;
	CGameUI* CommandBar;
	CGameUI* ResourceBarFrame;
	CGameUI* UpperButtonBarFrame;
	int field03D4;
	CGameUI* ClickableBlock;
	CGameUI* HeroBar;
	CGameUI* PeonBar;
	CGameUI* Message; // CSimpleMessageFrame*
	CGameUI* UnitMessage; // CSimpleMessageFrame*
	CGameUI* ChatMessage; // CSimpleMessageFrame*
	CGameUI* TopMessage; // CSimpleMessageFrame*
	CGameUI* Portrait; // CFrame*
	CGameUI* TimeOfDayIndicator; // CFrame*
	CGameUI* ChatEditBar;
	CGameUI* CinematicPanel;
	int field0404;
	CGameUI* MinimapButtons[5];
	CGameUI* FrameB; // CFrame*
	CGameUI* MouseBorders;
	CGameUI* FrameA; // CFrame*
	CGameUI* SimpleConsole;
	int QuickSaveHotKey;
	int QuickLoadHotKey;
	int QuickHelpHotKey;
	int QuickOptionsHotKey;
	int QuickQuitHotKey;
	int MinimapSignalHotKey;
	int MinimapTerrainHotKey;
	int MinimapColorsHotKey;
	int MinimapCreepsHotKey;
	int FormationToggleHotKey;
};

struct CGameWar3 {
	int field0000; // Pointer
	int field0004;
	int field0008;
	int field000C;
	int field0010;
	int field0014; // Pointer
	int field0018;
	int field001C; // CGameState
	int field0020; // CGameIdMaps
	int field0024;
	int field0028;
	int field002C;
	int field0030; // CMapSetupWar3
	int field0034; // CFogOfWarMap
	int field0038; // Pointer
	int field003C;
	int field0040; // CStringRep
	int field0044;
	int field0048;
	int field004C;
	int field0050;
	int field0054;
	int field0058; // CPlayerWar3
	int field005C; // CPlayerWar3
	int field0060; // CPlayerWar3
	int field0064; // CPlayerWar3
	int field0068; // CPlayerWar3
	int field006C; // CPlayerWar3
	int field0070; // CPlayerWar3
	int field0074; // CPlayerWar3
	int field0078; // CPlayerWar3
	int field007C; // CPlayerWar3
	int field0080; // CPlayerWar3
	int field0084; // CPlayerWar3
	int field0088; // CPlayerWar3
	int field008C; // CPlayerWar3
	int field0090; // CPlayerWar3
	int field0094; // CPlayerWar3
	int field0098; //  16
	int field009C; //  12
	int field00A0; // Pointer
	int field00A4;
	int field00A8; // 12
	float field00AC; // 320
	float field00B0; // -3264
	int field00B4;
	int field00B8;
	int field00BC; // Pointer
	int field00C0;
	int field00C4;
	int field00C8;
	int field00CC;
	int field00D0;
	int field00D4;
	float field00D8; // -192
	float field00DC; // 2304
	int field00E0;
	int field00E4;
	int field00E8; // Pointer
	int field00EC;
	int field00F0;
	int field00F4;
	int field00F8;
	int field00FC;
	int field0100;
	int field0104;
	int field0108;
	int field010C;
	int field0110;
	int field0114;
	int field0118;
	int field011C;
	int field0120;
	int field0124;
	int field0128;
	int field012C;
	int field0130;
	int field0134;
	int field0138;
	int field013C;
	int field0140;
	int field0144;
	int field0148;
	int field014C;
	int field0150;
	int field0154;
	int field0158;
	int field015C;
	int field0160;
	int field0164;
	int field0168;
	int field016C;
	int field0170;
	int field0174;
	int field0178;
	int field017C;
	int field0180;
	int field0184;
	int field0188;
	int field018C;
	int field0190;
	int field0194;
	int field0198;
	int field019C;
	int field01A0;
	int field01A4;
	int field01A8;
	int field01AC;
	int field01B0;
	int field01B4;
	int field01B8;
	int field01BC;
	int field01C0;
	int field01C4;
	int field01C8;
	int field01CC;
	int field01D0;
	int field01D4;
	int field01D8;
	int field01DC;
	int field01E0;
	int field01E4;
	int field01E8;
	int field01EC;
	int field01F0;
	int field01F4;
	int field01F8;
	int field01FC;
	int field0200;
	int field0204;
	int field0208;
	int field020C;
	int field0210;
	int field0214;
	int field0218;
	int field021C;
	int field0220;
	int field0224;
	int field0228;
	int field022C;
	int field0230;
	int field0234;
	int field0238;
	int field023C;
	int field0240;
	int field0244;
	int field0248;
	int field024C;
	int field0250;
	int field0254;
	int field0258;
	int field025C;
	int field0260;
	int field0264;
	int field0268;
	int field026C;
	int field0270;
	int field0274;
	int field0278;
	int field027C;
	int field0280;
	int field0284;
	int field0288;
	int field028C;
	int field0290;
	int field0294;
	int field0298;
	int field029C;
	int field02A0;
	int field02A4;
	int field02A8;
	int field02AC;
	int field02B0;
	int field02B4;
	int field02B8;
	int field02BC;
	int field02C0;
	int field02C4;
	int field02C8;
	int field02CC;
	int field02D0;
	int field02D4;
	float field02D8; // -0.0000232331422
	int field02DC;
	int field02E0;
	BYTE field02E4; // 157
	BYTE field02E5; // 92
	BYTE field02E6; // 101
	BYTE field02E7; // 111
	float field02E8; // -0.003639792325
	int field02EC; // Pointer
	int field02F0; // Pointer
	int field02F4;
	int field02F8; // CStringRep
	int field02FC; // Pointer
	int field0300;
	int field0304; // CStringRep
	int field0308; // Pointer
	int field030C;
	int field0310; // CStringRep
	int field0314; // Pointer
	int field0318;
	int field031C; // CStringRep
	int field0320;
	int field0324;
	int field0328;
	int field032C;
	int field0330;
	int field0334;
	int field0338;
	int field033C;
	int field0340;
	int field0344;
	int field0348;
	int field034C;
	int field0350;
	int field0354;
	int field0358;
	int field035C;
	int field0360;
	int field0364;
	int field0368;
	int field036C;
	int field0370;
	int field0374;
	int field0378;
	int field037C;
	int field0380;
	int field0384;
	int field0388;
	int field038C;
	int field0390;
	int field0394;
	int field0398;
	int field039C;
	int field03A0;
	int field03A4;
	int field03A8;
	int field03AC;
	int field03B0;
	int field03B4;
	int field03B8;
	int field03BC;
	int field03C0;
	int field03C4;
	int field03C8;
	int field03CC; // Pointer
	int field03D0;
	int field03D4; // CStringRep
	int field03D8;
	int field03DC;
	int field03E0;
	int field03E4;
	int field03E8;
	int field03EC; // Pointer
	int field03F0;
	int field03F4;
	int field03F8;
	int field03FC;
	int field0400; // CGameCacheManager
	int field0404; // CGameHashTableManager
	int field0408;
	int field040C;
	int field0410;
	int field0414;
	int field0418;
	int field041C;
	int field0420;
	int field0424;
	int field0428;
	int field042C;
	int field0430;
	int field0434;
	int field0438;
	int field043C;
	int field0440;
	int field0444;
	int field0448;
	int field044C;
	int field0450;
	int field0454;
	int field0458;
	int field045C;
	int field0460;
	int field0464;
	int field0468;
	int field046C;
	int field0470;
	int field0474;
	int field0478;
	int field047C;
	int field0480;
	int field0484;
	int field0488;
	int field048C;
	int field0490;
	int field0494;
	int field0498;
	int field049C;
	int field04A0;
	int field04A4;
	int field04A8;
	int field04AC;
	int field04B0;
	int field04B4;
	int field04B8;
	int field04BC;
	int field04C0;
	int field04C4;
	int field04C8;
	int field04CC;
	int field04D0;
	int field04D4;
	int field04D8;
	int field04DC;
	int field04E0;
	int field04E4;
	int field04E8;
	int field04EC;
	int field04F0;
	int field04F4;
	int field04F8;
	int field04FC;
	int field0500;
	int field0504;
	int field0508;
	int field050C;
	int field0510;
	int field0514;
	int field0518;
	int field051C;
	int field0520;
	int field0524;
	int field0528;
	int field052C;
	int field0530;
	int field0534;
	int field0538;
	int field053C;
	int field0540;
	int field0544;
	int field0548;
	int field054C;
	int field0550;
	int field0554;
	int field0558;
	int field055C;
	int field0560;
	int field0564;
	int field0568;
	int field056C;
	int field0570;
	int field0574;
	int field0578;
	int field057C;
	int field0580;
	int field0584;
	int field0588;
	int field058C;
	int field0590;
	int field0594;
	int field0598;
	int field059C;
	int field05A0;
	int field05A4;
	int field05A8;
	int field05AC;
	int field05B0;
	int field05B4;
	int field05B8;
	int field05BC;
	int field05C0;
	int field05C4;
	int field05C8;
	int field05CC;
	int field05D0;
	int field05D4;
	int field05D8;
	int field05DC;
	int field05E0;
	int field05E4;
	int field05E8;
	int field05EC;
	int field05F0;
	int field05F4;
	int field05F8;
	int field05FC;
	int field0600;
	int field0604;
	int field0608;
	int field060C;
	int field0610;
	int field0614;
	int field0618;
	int field061C;
	int field0620;
	int field0624;
	int field0628;
	int field062C;
	int field0630;
	int field0634;
	int field0638;
	int field063C;
	int field0640;
	int field0644;
	int field0648;
	int field064C;
	int field0650;
	int field0654;
	int field0658;
	int field065C;
	int field0660;
	int field0664;
	int field0668;
	int field066C;
	int field0670;
	int field0674;
	int field0678;
	int field067C;
	int field0680;
	int field0684;
	int field0688;
	int field068C;
	int field0690;
	int field0694;
	int field0698;
	int field069C;
	int field06A0;
	int field06A4;
	int field06A8;
	int field06AC;
	int field06B0;
	int field06B4;
	int field06B8;
	int field06BC;
	int field06C0;
	int field06C4;
	int field06C8;
	int field06CC;
	int field06D0;
	int field06D4;
	int field06D8;
	int field06DC;
	int field06E0;
	int field06E4;
	int field06E8;
	int field06EC;
	int field06F0;
	int field06F4;
	int field06F8;
	int field06FC;
	int field0700;
	int field0704;
	int field0708;
	int field070C;
	int field0710;
	int field0714;
	int field0718;
	int field071C;
	int field0720;
	int field0724;
	int field0728;
	int field072C;
	int field0730;
	int field0734;
	int field0738;
	int field073C;
	int field0740;
	int field0744;
	int field0748;
	int field074C;
	int field0750;
	int field0754;
	int field0758;
	int field075C;
	int field0760;
	int field0764;
	int field0768;
	int field076C;
	int field0770;
	int field0774;
	int field0778;
	int field077C;
	int field0780;
	int field0784;
	int field0788;
	int field078C;
	int field0790;
	int field0794;
	int field0798;
	int field079C;
	int field07A0;
	int field07A4;
	int field07A8;
	int field07AC;
	int field07B0;
	int field07B4;
	int field07B8;
	int field07BC;
	int field07C0;
	int field07C4;
	int field07C8;
	int field07CC;
	int field07D0;
	int field07D4;
	int field07D8;
	int field07DC;
	int field07E0;
	int field07E4;
	int field07E8;
	int field07EC;
	int field07F0;
	int field07F4;
	int field07F8;
	int field07FC;
	int field0800;
	int field0804;
	int field0808;
	int field080C;
	int field0810;
	int field0814;
	int field0818;
	int field081C;
	int field0820;
	int field0824;
	int field0828;
	int field082C;
	int field0830;
	int field0834;
	int field0838;
	int field083C;
	int field0840;
	int field0844;
	int field0848;
	int field084C;
	int field0850;
	int field0854;
	int field0858;
	int field085C;
	int field0860;
	int field0864;
	int field0868;
	int field086C;
	int field0870;
	int field0874;
	int field0878;
	int field087C;
	int field0880;
	int field0884;
	int field0888;
	int field088C;
	int field0890;
	int field0894;
	int field0898;
	int field089C;
	int field08A0;
	int field08A4;
	int field08A8;
	int field08AC;
	int field08B0;
	int field08B4;
	int field08B8;
	int field08BC;
	int field08C0;
	int field08C4;
	int field08C8;
	int field08CC;
	int field08D0;
	int field08D4;
	int field08D8;
	int field08DC;
	int field08E0;
	int field08E4;
	int field08E8;
	int field08EC;
	int field08F0;
	int field08F4;
	int field08F8;
	int field08FC;
	int field0900;
	int field0904;
	int field0908;
	int field090C;
	int field0910;
	int field0914;
	int field0918;
	int field091C;
	int field0920;
	int field0924;
	int field0928;
	int field092C;
	int field0930;
	int field0934;
	int field0938;
	int field093C;
	int field0940;
	int field0944;
	int field0948;
	int field094C;
	int field0950;
	int field0954;
	int field0958;
	int field095C;
	int field0960;
	int field0964;
	int field0968;
	int field096C;
	int field0970;
	int field0974;
	int field0978;
	int field097C;
	int field0980;
	int field0984;
	int field0988;
	int field098C;
	int field0990;
	int field0994;
	int field0998;
	int field099C;
	int field09A0;
	int field09A4;
	int field09A8;
	int field09AC;
	int field09B0;
	int field09B4;
	int field09B8;
	int field09BC;
	int field09C0;
	int field09C4;
	int field09C8;
	int field09CC;
	int field09D0;
	int field09D4;
	int field09D8;
	int field09DC;
	int field09E0;
	int field09E4;
	int field09E8;
	int field09EC;
	int field09F0;
	int field09F4;
	int field09F8;
	int field09FC;
	int field0A00;
	int field0A04;
	int field0A08;
	int field0A0C;
	int field0A10;
	int field0A14;
	int field0A18;
	int field0A1C;
	int field0A20;
	int field0A24;
	int field0A28;
	int field0A2C;
	int field0A30;
	int field0A34;
	int field0A38;
	int field0A3C;
	int field0A40;
	int field0A44;
	int field0A48;
	int field0A4C;
	int field0A50;
	int field0A54;
	int field0A58;
	int field0A5C;
	int field0A60;
	int field0A64;
	int field0A68;
	int field0A6C;
	int field0A70;
	int field0A74;
	int field0A78;
	int field0A7C;
	int field0A80;
	int field0A84;
	int field0A88;
	int field0A8C;
	int field0A90;
	int field0A94;
	int field0A98;
	int field0A9C;
	int field0AA0;
	int field0AA4;
	int field0AA8;
	int field0AAC;
	int field0AB0;
	int field0AB4;
	int field0AB8;
	int field0ABC;
	int field0AC0;
	int field0AC4;
	int field0AC8;
	int field0ACC;
	int field0AD0;
	int field0AD4;
	int field0AD8;
	int field0ADC;
	int field0AE0;
	int field0AE4;
	int field0AE8;
	int field0AEC;
	int field0AF0;
	int field0AF4;
	int field0AF8;
	int field0AFC;
	int field0B00;
	int field0B04;
	int field0B08;
	int field0B0C;
	int field0B10;
	int field0B14;
	int field0B18;
	int field0B1C;
	int field0B20;
	int field0B24;
	int field0B28;
	int field0B2C;
	int field0B30;
	int field0B34;
	int field0B38;
	int field0B3C;
	int field0B40;
	int field0B44;
	int field0B48;
	int field0B4C;
	int field0B50;
	int field0B54;
	int field0B58;
	int field0B5C;
	int field0B60;
	int field0B64;
	int field0B68;
	int field0B6C;
	int field0B70;
	int field0B74;
	int field0B78;
	int field0B7C;
	int field0B80;
	int field0B84;
	int field0B88;
	int field0B8C;
	int field0B90;
	int field0B94;
	int field0B98;
	int field0B9C;
	int field0BA0;
	int field0BA4;
	int field0BA8;
	int field0BAC;
	int field0BB0;
	int field0BB4;
	int field0BB8;
	int field0BBC;
	int field0BC0;
	int field0BC4;
	int field0BC8;
	int field0BCC;
	int field0BD0;
	int field0BD4;
	int field0BD8;
	int field0BDC;
	int field0BE0;
	int field0BE4;
	int field0BE8;
	int field0BEC;
	int field0BF0;
	int field0BF4;
	int field0BF8;
	int field0BFC;
	int field0C00;
	int field0C04;
	int field0C08;
	int field0C0C;
	int field0C10;
	int field0C14;
	int field0C18;
	int field0C1C;
	int field0C20;
	int field0C24;
	int field0C28;
	int field0C2C;
	int field0C30;
	int field0C34;
	int field0C38;
	int field0C3C;
	int field0C40;
	int field0C44;
	int field0C48;
	int field0C4C;
	int field0C50;
	int field0C54;
	int field0C58;
	int field0C5C;
	int field0C60;
	int field0C64;
	int field0C68;
	int field0C6C;
	int field0C70;
	int field0C74;
	int field0C78;
	int field0C7C;
	int field0C80;
	int field0C84;
	int field0C88;
	int field0C8C;
	int field0C90;
	int field0C94;
	int field0C98;
	int field0C9C;
	int field0CA0;
	int field0CA4;
	int field0CA8;
	int field0CAC;
	int field0CB0;
	int field0CB4;
	int field0CB8;
	int field0CBC;
	int field0CC0;
	int field0CC4;
	int field0CC8;
	int field0CCC;
	int field0CD0;
	int field0CD4;
	int field0CD8;
	int field0CDC;
	int field0CE0;
	int field0CE4;
	int field0CE8;
	int field0CEC;
	int field0CF0;
	int field0CF4;
	int field0CF8;
	int field0CFC;
	int field0D00;
	int field0D04;
	int field0D08;
	int field0D0C;
	int field0D10;
	int field0D14;
	int field0D18;
	int field0D1C;
	int field0D20;
	int field0D24;
	int field0D28;
	int field0D2C;
	int field0D30;
	int field0D34;
	int field0D38;
	int field0D3C;
	int field0D40;
	int field0D44;
	int field0D48;
	int field0D4C;
	int field0D50;
	int field0D54;
	int field0D58;
	int field0D5C;
	int field0D60;
	int field0D64;
	int field0D68;
	int field0D6C;
	int field0D70;
	int field0D74;
	int field0D78;
	int field0D7C;
	int field0D80;
	int field0D84;
	int field0D88;
	int field0D8C;
	int field0D90;
	int field0D94;
	int field0D98;
	int field0D9C;
	int field0DA0;
	int field0DA4;
	int field0DA8;
	int field0DAC;
	int field0DB0;
	int field0DB4;
	int field0DB8;
	int field0DBC;
	int field0DC0;
	int field0DC4;
	int field0DC8;
	int field0DCC;
	int field0DD0;
	int field0DD4;
	int field0DD8;
	int field0DDC;
	int field0DE0;
	int field0DE4;
	int field0DE8;
	int field0DEC;
	int field0DF0;
	int field0DF4;
	int field0DF8;
	int field0DFC;
	int field0E00;
	int field0E04;
	int field0E08;
	int field0E0C;
	int field0E10;
	int field0E14;
	int field0E18;
	int field0E1C;
	int field0E20;
	int field0E24;
	int field0E28;
	int field0E2C;
	int field0E30;
	int field0E34;
	int field0E38;
	int field0E3C;
	int field0E40;
	int field0E44;
	int field0E48;
	int field0E4C;
	int field0E50;
	int field0E54;
	int field0E58;
	int field0E5C;
	int field0E60;
	int field0E64;
	int field0E68;
	int field0E6C;
	int field0E70;
	int field0E74;
	int field0E78;
	int field0E7C;
	int field0E80;
	int field0E84;
	int field0E88;
	int field0E8C;
	int field0E90;
	int field0E94;
	int field0E98;
	int field0E9C;
	int field0EA0;
	int field0EA4;
	int field0EA8;
	int field0EAC;
	int field0EB0;
	int field0EB4;
	int field0EB8;
	int field0EBC;
	int field0EC0;
	int field0EC4;
	int field0EC8;
	int field0ECC;
	int field0ED0;
	int field0ED4;
	int field0ED8;
	int field0EDC;
	int field0EE0;
	int field0EE4;
	int field0EE8;
	int field0EEC;
	int field0EF0;
	int field0EF4;
	int field0EF8;
	int field0EFC;
	int field0F00;
	int field0F04;
	int field0F08;
	int field0F0C;
	int field0F10;
	int field0F14;
	int field0F18;
	int field0F1C;
	int field0F20;
	int field0F24;
	int field0F28;
	int field0F2C;
	int field0F30;
	int field0F34;
	int field0F38;
	int field0F3C;
};
#endif

enum class EFramePoint : UINT
{
	TopLeft = 0,
	Top = 1,
	TopRight = 2,
	Left = 3,
	Center = 4,
	Right = 5,
	BottomLeft = 6,
	Bottom = 7,
	BottomRight = 8
};

enum EOriginFrame : UINT {
	ORIGIN_FRAME_GAME_UI,
	ORIGIN_FRAME_WORLD_FRAME,
	ORIGIN_FRAME_HERO_BAR,
	ORIGIN_FRAME_HERO_BUTTON,
	ORIGIN_FRAME_HERO_HP_BAR,
	ORIGIN_FRAME_HERO_MANA_BAR,
	ORIGIN_FRAME_HERO_BUTTON_INDICATOR,
	ORIGIN_FRAME_ITEM_BUTTON,
	ORIGIN_FRAME_COMMAND_BUTTON,
	ORIGIN_FRAME_SYSTEM_BUTTON,
	ORIGIN_FRAME_PORTRAIT,
	ORIGIN_FRAME_MINIMAP,
	ORIGIN_FRAME_MINIMAP_BUTTON,
	ORIGIN_FRAME_TOOLTIP,
	ORIGIN_FRAME_UBERTOOLTIP,
	ORIGIN_FRAME_CHAT_MSG,
	ORIGIN_FRAME_UNIT_MSG,
	ORIGIN_FRAME_TOP_MSG
};

PJASS_INSTANCE getJassMachine(DWORD index = 1);

PJASS_INSTANCE getJassInstance();

DWORD getInstance(DWORD index);

UINT GetOriginFrame(EOriginFrame originframe, UINT index);

UINT GetPanelButton(UINT frame, BYTE row, BYTE column);

CGameUI* GetGameUI(UINT unknown0 = NULL, UINT unknown1 = NULL);

CGameWar3* GetGameWar3(UINT unknown0 = NULL);

UINT GetTooltipFrame(UINT unknown0 = NULL);

BOOL LoadTOCFile(LPCSTR filename);

UINT GetFrameByName(LPCSTR framename, UINT id);

UINT CreateFrame(LPCSTR baseframe, UINT parentframe, EFramePoint point, EFramePoint relativepoint, UINT id);

void SetFrameText(UINT frame, LPCSTR text);

void SetFrameTextColor(UINT frame, BYTE red, BYTE green, BYTE blue, BYTE alpha);

float GetFrameTextHeight(UINT frame);

void SetFrameWidth(UINT frame, float width);

void SetFrameHeight(UINT frame, float height);

void SetFrameSize(UINT frame, float width, float height);

void SetFrameScale(UINT frame, float scale);

void SetFrameAbsolutePoint(UINT frame, EFramePoint point, float offsetX, float offsetY);

void SetFramePoint(UINT frame, EFramePoint point, UINT parentframe, EFramePoint relativepoint, float offsetX, float offsetY);

float GetFrameWidth(UINT frame);

float GetFrameHeight(UINT frame);

UINT GetFramePointParent(UINT frame, EFramePoint point);

UINT GetFramePointRelativePoint(UINT frame, EFramePoint point);

float GetFramePointX(UINT frame, EFramePoint point);

float GetFramePointY(UINT frame, EFramePoint point);