#include "Warcraft.h"

#include "Variables.h"
#include "fcalls.h"
#include "Mem.h"

PJASS_INSTANCE getJassMachine(DWORD index) {
	DWORD jass_thread = *(DWORD*)(*(DWORD*)(getInstance(5) + 0x90) + index * 4);

	return jass_thread ? (PJASS_INSTANCE)jass_thread : NULL;
}

PJASS_INSTANCE getJassInstance() {
	DWORD instance = getInstance(5);

	return *(DWORD*)(instance + 0x14) ? *(PJASS_INSTANCE*)(*(DWORD*)(instance + 0xc) + *(DWORD*)(instance + 0x14) * 4 - 4) : NULL;
}

DWORD getInstance(DWORD index) {
	return fastcall<DWORD>(MakePtr(gameBase, _getInstanceProc), index);
}



UINT GetOriginFrame(EOriginFrame originframe, UINT index) {
	CGameUI* gameui = GetGameUI();

	switch (originframe) {
	case ORIGIN_FRAME_GAME_UI:
		return (UINT)gameui;
	case ORIGIN_FRAME_WORLD_FRAME:
		return (UINT)gameui->WorldFrameWar3;
	case ORIGIN_FRAME_HERO_BAR:
		return (UINT)gameui->HeroBar;
	case ORIGIN_FRAME_HERO_BUTTON:
		return (UINT)GetPanelButton((UINT)gameui->HeroBar, index, 0);
	case ORIGIN_FRAME_HERO_HP_BAR:
		return *(UINT*)((UINT)GetPanelButton((UINT)gameui->HeroBar, index, 0) + 0x1cc);
	case ORIGIN_FRAME_HERO_MANA_BAR:
		return *(UINT*)((UINT)GetPanelButton((UINT)gameui->HeroBar, index, 0) + 0x1d0);
	case ORIGIN_FRAME_HERO_BUTTON_INDICATOR:
		// Undefined
		break;
	case ORIGIN_FRAME_ITEM_BUTTON:
		return *(UINT*)(*(UINT*)(*(UINT*)(gameui->InfoBar + 0x148) + 0x130) + 8 * index + 4);
	case ORIGIN_FRAME_COMMAND_BUTTON:
		return (UINT)GetPanelButton((UINT)gameui->CommandBar, index / 4, index % 4);
	case ORIGIN_FRAME_SYSTEM_BUTTON:
		// Undefined
		break;
	case ORIGIN_FRAME_PORTRAIT:
		return (UINT)gameui->Portrait;
	case ORIGIN_FRAME_MINIMAP:
		return (UINT)gameui->Minimap;
	case ORIGIN_FRAME_MINIMAP_BUTTON:
		return (UINT)gameui->MinimapButtons[index];
	case ORIGIN_FRAME_TOOLTIP:
		return GetTooltipFrame();
	case ORIGIN_FRAME_UBERTOOLTIP:
		// Undefined
		break;
	case ORIGIN_FRAME_CHAT_MSG:
		return (UINT)gameui->ChatMessage;
	case ORIGIN_FRAME_UNIT_MSG:
		return (UINT)gameui->UnitMessage;
	case ORIGIN_FRAME_TOP_MSG:
		return (UINT)gameui->TopMessage;
	default:
		break;
	}

	return NULL;
}

UINT GetPanelButton(UINT frame, BYTE row, BYTE column) {
	return *(UINT*)(*(DWORD*)(16 * row + *((DWORD*)frame + 85) + 8) + 4 * column) - sizeof(CFrame);
}

CGameUI* GetGameUI(UINT unknown0, UINT unknown1) {
	return fastcall<CGameUI*>(MakePtr(gameBase, _getGameUI), unknown0, unknown1);
}

CGameWar3* GetGameWar3(UINT unknown0) {
	return fastcall<CGameWar3*>(MakePtr(gameBase, _getGameWar3), unknown0);
}

UINT GetTooltipFrame(UINT unknown0) {
	return fastcall<UINT>(MakePtr(gameBase, _getTooltipFrame), unknown0);
}

BOOL LoadTOCFile(LPCSTR filename) {
	DWORD stringHastTable = MakePtr(gameBase, _stringHastTable);
	DWORD FDFHashTable = MakePtr(gameBase, _FDFHashTable);

	if (*(int*)(stringHastTable + 0x14) < 0xFFFF) {
		thiscall<void>(MakePtr(gameBase, _stringHashNodeGrowListArray), stringHastTable, 0xFFFF);
	}

	if (*(int*)(FDFHashTable + 0x14) < 0xFFFF) {
		thiscall<void>(MakePtr(gameBase, _baseFrameHashNodeGrowListArray), FDFHashTable, 0xFFFF);
	}

	return fastcall<BOOL>(MakePtr(gameBase, _readFDFFile), filename, stringHastTable, FDFHashTable, MakePtr(gameBase, _CFrameDefStatus));
}

UINT GetFrameByName(LPCSTR framename, UINT id) {
	return fastcall<UINT>(MakePtr(gameBase, _getCFrameByName), framename, id);
}

UINT CreateFrame(LPCSTR baseframe, UINT parentframe, EFramePoint point, EFramePoint relativepoint, UINT id) {
	return fastcall<UINT>(MakePtr(gameBase, _createCFrame), baseframe, parentframe, point, relativepoint, id);
}

void SetFrameText(UINT frame, LPCSTR text) {
	thiscall<void>(MakePtr(gameBase, _setCFrameText), *(UINT*)(FRAMELAYOUT(frame) + 0x130), text);
}

void SetFrameTextColor(UINT frame, BYTE red, BYTE green, BYTE blue, BYTE alpha) {
	DWORD color = ((alpha << 24) + (red << 16) + (green << 8) + blue);
	thiscall<void>(MakePtr(gameBase, _setCFrameTextColor), FRAMELAYOUT(frame), &color);
}

float GetFrameTextHeight(UINT frame) {
	return thiscall<float>(MakePtr(gameBase, _getCFrameTextHeight), FRAMELAYOUT(frame));
}

void SetFrameWidth(UINT frame, float width) {
	thiscall<void>(MakePtr(gameBase, _setCLayoutFrameWidth), FRAMELAYOUT(frame), width);
}

void SetFrameHeight(UINT frame, float height) {
	thiscall<void>(MakePtr(gameBase, _setCLayoutFrameHeight), FRAMELAYOUT(frame), height);
}

void SetFrameSize(UINT frame, float width, float height) {
	SetFrameWidth(frame, width);
	SetFrameHeight(frame, height);
}

void SetFrameScale(UINT frame, float scale) {
	thiscall<void>(MakePtr(gameBase, _setCLayoutFrameScale), FRAMELAYOUT(frame), scale);
}

void SetFrameAbsolutePoint(UINT frame, EFramePoint point, float offsetX, float offsetY) {
	thiscall<void>(MakePtr(gameBase, _setCLayoutFrameAbsolutePoint), FRAMELAYOUT(frame), point, offsetX, offsetY, 1);
}

void SetFramePoint(UINT frame, EFramePoint point, UINT parentframe, EFramePoint relativepoint, float offsetX, float offsetY) {
	thiscall<void>(MakePtr(gameBase, _setCLayoutFramePoint), FRAMELAYOUT(frame), point, FRAMELAYOUT(parentframe), relativepoint, offsetX, offsetY, 1);
}

float GetFrameWidth(UINT frame) {
	return *(float*)(FRAMELAYOUT(frame) + 0x58);
}

float GetFrameHeight(UINT frame) {
	return *(float*)(FRAMELAYOUT(frame) + 0x5c);
}

UINT GetFramePoint(UINT frame, EFramePoint point) {
	return *(UINT*)(FRAMELAYOUT(frame) + 4 * (UINT)point + 8);
}

UINT GetFramePointParent(UINT frame, EFramePoint point) {
	return *(UINT*)(GetFramePoint(frame, point) + 4);
}

UINT GetFramePointRelativePoint(UINT frame, EFramePoint point) {
	return *(UINT*)(GetFramePoint(frame, point) + 8);
}

float GetFramePointX(UINT frame, EFramePoint point) {
	return *(float*)(GetFramePoint(frame, point) + 12);
}

float GetFramePointY(UINT frame, EFramePoint point) {
	return *(float*)(GetFramePoint(frame, point) + 16);
}