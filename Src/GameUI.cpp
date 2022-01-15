#include "GameUI.h"
#include "Global.h"

auto getGameUITrue = (CGameUI*(__fastcall*)(UINT, UINT))((UINT_PTR)gameBase + 0x300710);
auto getTooltipFrameTrue = (UINT(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x337240);

auto GrowStringHashNodeListArray = (void(__fastcall*)(LPVOID, UINT, DWORD))((UINT_PTR)gameBase + 0x5ca9b0);
auto GrowBaseFrameHashNodeListArray = (void(__fastcall*)(LPVOID, UINT, DWORD))((UINT_PTR)gameBase + 0x5d5650);
auto ReadFDFFile = (BOOL(__fastcall*)(LPCSTR, LPVOID, LPVOID, LPVOID))((UINT_PTR)gameBase + 0x5d8de0);

auto GetCFrameByName = (UINT(__fastcall*)(LPCSTR, UINT))((UINT_PTR)gameBase + 0x5fa970);
auto CreateCFrame = (UINT(__fastcall*)(LPCSTR, UINT, EFramePoint, EFramePoint, UINT))((UINT_PTR)gameBase + 0x5c9560);
auto SetCTextFrameText = (void(__fastcall*)(UINT, UINT, LPCSTR))((UINT_PTR)gameBase + 0x611d40);
auto SetCFrameTextColor = (void(__fastcall*)(UINT, UINT, DWORD*))((UINT_PTR)gameBase + 0x611590);
auto GetCFrameTextHeight = (float(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x6118a0);
auto SetCEditBoxText = (void(__fastcall*)(UINT, UINT, LPCSTR, UINT))((UINT_PTR)gameBase + 0x615B50);
auto SetCTextAreaText = (void(__fastcall*)(UINT, UINT, LPCSTR))((UINT_PTR)gameBase + 0x61E090);
auto SetCEditBoxFont = (void(__fastcall*)(UINT, UINT, LPCSTR, float, UINT))((UINT_PTR)gameBase + 0x613CA0);
auto SetCLayerFont = (void(__fastcall*)(UINT, UINT, LPCSTR, float, UINT))((UINT_PTR)gameBase + 0x5FB960);
auto SetCLayoutFrameWidth = (void(__fastcall*)(UINT, UINT, float))((UINT_PTR)gameBase + 0x605d90);
auto SetCLayoutFrameHeight = (void(__fastcall*)(UINT, UINT, float))((UINT_PTR)gameBase + 0x605db0);
auto SetCLayoutFrameScale = (void(__fastcall*)(UINT, UINT, float))((UINT_PTR)gameBase + 0x605d40);
auto SetCLayoutFramePoint = (void(__fastcall*)(UINT, UINT, EFramePoint, UINT, EFramePoint, float, float, UINT))((UINT_PTR)gameBase + 0x606770);
auto SetCSliderCurrentValue = (void(__fastcall*)(UINT, UINT, float, UINT))((UINT_PTR)gameBase + 0x61ee70);
auto SetCSimpleStatusBarTexture = (void(__fastcall*)(UINT, UINT, LPCSTR, BOOL))((UINT_PTR)gameBase + 0x60e610);
auto SetCSimpleStatusBarValue = (void(__fastcall*)(UINT, UINT, float))((UINT_PTR)gameBase + 0x60e430);
auto SetCSimpleStatusBarMinMaxValue = (void(__fastcall*)(UINT, UINT, float, float))((UINT_PTR)gameBase + 0x60e3b0);
//auto clearCLayoutFrameAllPoints = (void(__fastcall*)(UINT, UINT))((UINT_PTR)gameBase + 0x606270);
auto SetCLayoutFrameAbsolutePoint = (void(__fastcall*)(UINT, UINT, EFramePoint, float, float, UINT))((UINT_PTR)gameBase + 0x6061b0);
//auto setCLayoutFrameCageMouse = (void(__fastcall*)(UINT, UINT))((UINT_PTR)gameBase + 0x604fc0);
//auto setCLayoutFrameAllPoints = (void(__fastcall*)(UINT, UINT))((UINT_PTR)gameBase + 0x6067f0);
auto SetCBackDropFrameTexture = (void(__fastcall*)(UINT, UINT, LPCSTR, UINT, BOOL, UINT, UINT))((UINT_PTR)gameBase + 0x6212d0);
auto SetCSimpleTextureTexture = (void(__fastcall*)(UINT, UINT, LPCSTR, BOOL))((UINT_PTR)gameBase + 0x60e090);
auto SetCControlState = (void(__fastcall*)(UINT, UINT, BOOL))((UINT_PTR)gameBase + 0x336c20);
//auto SetCControlState = (void(__fastcall*)(UINT, UINT, BOOL))((UINT_PTR)gameBase + 0x601de0);
auto ClickCFrame = (void(__fastcall*)(UINT, UINT, UINT))((UINT_PTR)gameBase + 0x601f20);
auto AddCModelFrameModel = (void(__fastcall*)(UINT, UINT, LPCSTR, UINT))((UINT_PTR)gameBase + 0x6215d0);
auto SetCSpriteFrameArt = (void(__fastcall*)(UINT, UINT, LPCSTR, UINT, BOOL))((UINT_PTR)gameBase + 0x60f360);
auto SetCStatusBarArt = (void(__fastcall*)(UINT, UINT, LPCSTR, UINT))((UINT_PTR)gameBase + 0x6279a0);
auto SetCStatusBarMinMaxValue = (void(__fastcall*)(UINT, UINT, float, float))((UINT_PTR)gameBase + 0x6277c0);
auto DestroyCFrame = (void(__fastcall*)(UINT, UINT, UINT))((UINT_PTR)gameBase + 0x606910);
auto ShowCFrame = (void(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x5fe690);
auto HideCFrame = (void(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x5fe6f0);

auto TriggerEvaluate = (BOOL(__cdecl*)(UINT))((UINT_PTR)gameBase + 0x3c3f80);
auto TriggerExecute = (BOOL(__cdecl*)(UINT))((UINT_PTR)gameBase + 0x3c3f40);

int* pWheelState = (int*)((UINT_PTR)gameBase + 0xa9a844);

const std::map<EFrameType, std::pair<DWORD, DWORD>> frameTypes = {
	{BackdropFrame, {0x96f3f4, 0x96f3cc}},
	{ButtonFrame, {0x96F6FC, 0x96F6D4}},
	{ChatMode, {0x93A8BC, NULL}},
	{CommandButton, {0x93EBC4, NULL}},
	{CursorFrame, {0x97063C, 0x970610}},
	{EditBox, {0x96ECEC, 0x96ECC0}},
	{Frame, {0x96DEB4, 0x96DE8C}},
	{FloatingFrame, {0x96FAB4, 0x96FA88}},
	{GameUI, {0x93631C, 0x9362F4}},
	{HeroBarButton, {0x93F8DC, NULL}}, // 0x93F8BC ??
	{HighlightFrame, {0x96F974, 0x96F94C}},
	{LayoutFrame, {0x96DE48, NULL}},
	{MessageFrame, {0x96F864, 0x96F83C}},
	{Minimap, {0x94002C, 0x940004}},
	{ModelFrame, {0x96F5AC, 0x96F584}},
	{PortraitButton, {0x9401E4, 0x9401BC}},
	{ScreenFrame, {0x96E07C, 0x96E054}},
	{SimpleButton, {0x96DC8C, NULL}},
	{SimpleFontString, {0x96E404, NULL}},
	{SimpleFrame, {0x96DFB4, NULL}},
	{SimpleGlueFrame, {0x96EE04, NULL}},
	{Uknown_1, {NULL, NULL}},
	{SimpleMessageFrame, {0x96DD84, NULL}},
	{Slider, {0x96F274, 0x96F24C}},
	{SpriteFrame, {0x96E584, 0x96E558}},
	{StatBar, {0x93E604, NULL}},
	{TextArea, {0x96EFD4, 0x96EFAC}},
	{TextButtonFrame, {0x96F114, 0x96F0E8}},
	{TextFrame, {0x96E9B4, 0x96E988}},
	{UberToolTipWar3, {0x93F68C, NULL}},
	{WorldFrameWar3, {0x94157C, 0x941550}},
	{GlueButtonWar3, {0x95C92C, 0x95C900}},
	{GlueTextButtonWar3, {0x95A00C, 0x959FE0}},
	{GlueCheckBoxWar3, {0x95C7EC, 0x95C7C0}},
	{GluePopupMenuWar3, {0x959E84, 0x959E5C}},
	{GlueEditBoxWar3, {0x95CA6C, 0x95CA40}},
	{SlashChatBox, {0x95DAEC, 0x95DAC4}},
	{TimerTextFrame, {0x95A564, 0x95A538}},
	{SimpleStatusBar, {0x96E48C, NULL}},
	{StatusBar, {0x970264, 0x97023C}},
	{UpperButtonBar, {0x93C3E4, 0x93C3C4}},
	{ResourceBar, {0x93D22C, NULL}},
	{SimpleConsole, {0x93BD2C, NULL}},
	{PeonBar, {0x93FC0C, 0x93FBF0}},
	{HeroBar, {0x93F974, 0x93F958}},
	{TimeOfDayIndicator, {0x93FE64, 0x93FE38}},
	{InfoBar, {0x94066C, NULL}},
	{TimeCover, {0x93C054, 0x93C028}},
	{ProgressIndicator, {0x93834C, NULL}},
	{HeroLevelBar, {0x93FA24, NULL}},
	{BuildTimeIndicator, {0x93D684, NULL}},
	{InfoPanelDestructableDetail, {0x93CE54, NULL}},
	{InfoPanelItemDetail, {0x93B4C4, NULL}},
	{InfoPanelIconAlly, {0x93B374, NULL}},
	{InfoPanelIconHero, {0x93B284, NULL}},
	{InfoPanelIconGold, {0x93B20C, NULL}},
	{InfoPanelIconFood, {0x93B194, NULL}},
	{InfoPanelIconRank, {0x93B11C, NULL}},
	{InfoPanelIconArmor, {0x93B0A4, NULL}},
	{InfoPanelIconDamage, {0x93B02C, NULL}},
	{InfoPanelCargoDetail, {0x93CF8C, NULL}},
	{InfoPanelBuildingDetail, {0x93DE9C, NULL}},
	{InfoPanelUnitDetail, {0x93CF0C, NULL}},
	{SimpleTexture, {0x96E440, NULL}}
}; // Type = {TypeAddress, LayoutAddress}

const std::map<EFrameEvent, UINT> frameEvents = {
	{FRAMEEVENT_CONTROL_CLICK, 0x40090064},
	{FRAMEEVENT_MOUSE_MOVE, 0x40090066},
	{FRAMEEVENT_MOUSE_UP, 0x4009006a},
	{FRAMEEVENT_MOUSE_DOWN, NULL},
	{FRAMEEVENT_MOUSE_WHEEL, 0x4009006b},
	{FRAMEEVENT_CHECKBOX_CHECK, 0x400c0064},
	{FRAMEEVENT_EDITBOX_BUTTON_DOWN, 0x40060066},
	{FRAMEEVENT_POPUPMENU_ITEM_CHANGED, NULL},
	{FRAMEEVENT_MOUSE_DOUBLECLICK, NULL},
	{FRAMEEVENT_SPRITE_ANIM_UPDATE, NULL},
	{FRAMEEVENT_SLIDER_VALUE_CHANGED, 0x40100064},
	{FRAMEEVENT_DIALOG_CANCEL, NULL},
	{FRAMEEVENT_DIALOG_ACCEPT, NULL}
};

std::map<UINT, std::unordered_map<EFrameEvent, UINT>> frameEventHashTable;

std::vector<UINT> frames;

UINT triggerFrame = NULL;
EFrameEvent triggerEvent = FRAMEEVENT_NONE;

PVOID pStringHastTable = (PVOID)((UINT_PTR)gameBase + 0xacd214);
PVOID pFDFHashTable = (PVOID)((UINT_PTR)gameBase + 0xacd264);
PVOID pCFrameDefaultStatus = (PVOID)((UINT_PTR)gameBase + 0xa8c804);

EFrameEvent GetFrameEventType(UINT eventtype) {
	for (const auto& frameEvent : frameEvents) {
		if (frameEvent.second == eventtype) {
			EFrameEvent event = (EFrameEvent)frameEvent.first;

			return event;
		}
	}

	return FRAMEEVENT_NONE;
}

EFrameType GetFrameType(UINT frame) {
	if (frame) {
		UINT_PTR typeOffset = *(UINT*)frame - (UINT_PTR)gameBase;

		for (const auto& frameType : frameTypes) {
			if (frameType.second.first == typeOffset || frameType.second.second == typeOffset) {
				return frameType.first;
			}
		}
	}

	return MissingFrame;
}

UINT GetFrameLayout(UINT frame) {
	if (!frame) {
		return NULL;
	}

	UINT_PTR typeOffset = *(UINT_PTR*)frame - (UINT_PTR)gameBase;

	for (const auto& frameType : frameTypes) {
		if (frameType.second.first == typeOffset || frameType.second.second == typeOffset) {
			return frameType.second.second ? (frame + 0xB4) : frame;
		}
	}

	return NULL;
}

bool IsFrameLayout(UINT frame) {
	if (!frame) {
		return false;
	}

	UINT_PTR typeOffset = *(UINT_PTR*)frame - (UINT_PTR)gameBase;

	for (const auto& frameType : frameTypes) {
		if (frameType.second.first == typeOffset || frameType.second.second == typeOffset) {
			return frameType.second.second == typeOffset;
		}
	}

	return false;
}

CGameUI* GetGameUI(UINT unknown1, UINT unknown2) {
	return getGameUITrue(unknown1, unknown2);
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
	return *(UINT*)(*(DWORD*)(16 * row + *((DWORD*)frame + 85) + 8) + 4 * column);
}

UINT GetTooltipFrame(UINT unknown1) {
	return getTooltipFrameTrue(unknown1);
}

BOOL LoadTOCFile(LPCSTR filename) {
	if (*(int*)((UINT_PTR)pStringHastTable + 0x14) < 0xFFFF) {
		GrowStringHashNodeListArray(pStringHastTable, NULL, 0xFFFF);
	}

	if (*(int*)((UINT_PTR)pFDFHashTable + 0x14) < 0xFFFF) {
		GrowBaseFrameHashNodeListArray(pFDFHashTable, NULL, 0xFFFF);
	}

	return ReadFDFFile(filename, pStringHastTable, pFDFHashTable, pCFrameDefaultStatus);
}

UINT GetFrameByName(LPCSTR framename, UINT id) {
	return GetCFrameByName(framename, id);
}

UINT GetFrameParent(UINT frame) {
	return GetFrameType(frame) ? (IsFrameLayout(frame) ? *(UINT*)(frame + 0x68) : *(UINT*)(frame + 0x20)) : NULL;
}

UINT GetFrameChildrenCount(UINT frame) {
	if (frame) {
		UINT childtable = *(UINT*)(frame + 0x1c);
		UINT i = 0;

		for (; (int)childtable > NULL; i++, childtable = *(UINT*)(childtable + 8));
		// for (; ReadProcessMemory(GetCurrentProcess(), (LPVOID)(childtable + 8), &childtable, sizeof(childtable), NULL); i++);
		
		return i;
	}

	return NULL;
	// return frame ? *(UINT*)(frame + 4) - 1 : NULL; ??
}

UINT GetFrameChild(UINT frame, UINT index) {
	if (frame) {
		UINT count = GetFrameChildrenCount(frame);

		if (count && index < count) {
			UINT childtable = *(UINT*)(frame + 0x1c);
			for (UINT i = 0; i < index; i++, childtable = *(UINT*)(childtable + 8));

			return *(UINT*)(childtable + 0xc);
		}
	}

	return NULL;
}

void TriggerRegisterFrameEvent(UINT trigger, UINT frame, EFrameEvent event) {
	frameEventHashTable[frame][event] = trigger;
}

UINT CreateFrame(LPCSTR baseframe, UINT parentframe, EFramePoint point, EFramePoint relativepoint) {
	UINT prevframe = NULL;

	if (frames.size()) {
		prevframe = frames[frames.size() - 1];
	}

	UINT frame = CreateCFrame(baseframe, parentframe, point, relativepoint, prevframe ? (IsFrameLayout(prevframe) ? *(UINT*)(prevframe + 0xB0) + 1 : *(UINT*)(prevframe + 0x164) + 1) : 0);
	frames.push_back(frame);

	return frame;
}

void SetFrameText(UINT frame, LPCSTR text) {
	if (!frame) {
		return;
	}

	switch (GetFrameType(frame))
	{
	case EditBox:
	case GlueEditBoxWar3:
	case SlashChatBox:
		SetCEditBoxText(frame, NULL, text, 1);

		break;
	case TextArea:
		SetCTextAreaText(frame, NULL, text);

		break;
	case TextButtonFrame:
	case GlueTextButtonWar3:
		frame = *(UINT*)(frame + 0x1e4);
	case TextFrame:
	case TimerTextFrame:
		SetCTextFrameText(frame, NULL, text);

		break;
	}
}

LPCSTR GetFrameText(UINT frame) {
	if (frame) {
		switch (GetFrameType(frame))
		{
		case EditBox:
		case TextButtonFrame:
			return *(LPCSTR*)(frame + 0x1e4);
		case TextArea:
			return *(LPCSTR*)(frame + 0x230);
		case GlueTextButtonWar3:
			frame = *(UINT*)(frame + 0x1e4);
		case TextFrame:
			return *(LPCSTR*)(frame + 0x1e8);
		}
	}

	return "";
}

void SetFrameTextColor(UINT frame, BYTE red, BYTE green, BYTE blue, BYTE alpha) {
	if (!frame) {
		return;
	}

	DWORD color = ((alpha << 24) + (red << 16) + (green << 8) + blue);

	switch (GetFrameType(frame))
	{
	case TextArea:
		frame = *(UINT*)(frame + 0x230);

		break;
	case TextButtonFrame:
	case GlueTextButtonWar3:
		frame = *(UINT*)(frame + 0x1e4);
	case TextFrame:
		break;
	case EditBox:
		SetCFrameTextColor(*(UINT*)(frame + 0x254), NULL, &color);
		SetCFrameTextColor(*(UINT*)(frame + 0x258), NULL, &color);
	default:
		return;
	}

	SetCFrameTextColor(frame, NULL, &color);
}

float GetFrameTextHeight(UINT frame) {
	if (frame) {
		switch (GetFrameType(frame))
		{
		case EditBox:
			frame = *(UINT*)(frame + 0x254);

			break;
		case TextArea:
			frame = *(UINT*)(frame + 0x230);
		case TextFrame:
			break;
		case TextButtonFrame:
		case GlueTextButtonWar3:
			frame = *(UINT*)(frame + 0x1e4);

			break;
		default:
			return 0.f;
		}

		return GetCFrameTextHeight(frame);
	}

	return 0.f;
}

void SetFrameFont(UINT frame, LPCSTR filename, float height, UINT flag) {
	if (frame) {
		switch (GetFrameType(frame))
		{
		case MissingFrame:
			break;
		case EditBox:
			SetCEditBoxFont(frame, NULL, filename, height, flag);

			break;
		default:
			SetCLayerFont(frame, NULL, filename, height, flag);

			break;
		}
	}
}

void SetFrameWidth(UINT frame, float width) {
	UINT layout = GetFrameLayout(frame);

	if (!layout) {
		return;
	}

	SetCLayoutFrameWidth(layout, NULL, width);
}

void SetFrameHeight(UINT frame, float height) {
	UINT layout = GetFrameLayout(frame);

	if (!layout) {
		return;
	}

	SetCLayoutFrameHeight(layout, NULL, height);
}

void SetFrameSize(UINT frame, float width, float height) {
	SetFrameWidth(frame, width);
	SetFrameHeight(frame, height);
}

void SetFrameScale(UINT frame, float scale) {
	UINT layout = GetFrameLayout(frame);

	if (!layout) {
		return;
	}

	SetCLayoutFrameScale(layout, NULL, scale);
}

void SetFrameAbsolutePoint(UINT frame, EFramePoint point, float offsetX, float offsetY) {
	UINT layout = GetFrameLayout(frame);

	if (!layout) {
		return;
	}

	SetCLayoutFrameAbsolutePoint(layout, NULL, point, offsetX, offsetY, 1);
}

void SetFramePoint(UINT frame, EFramePoint point, UINT relativeframe, EFramePoint relativepoint, float offsetX, float offsetY) {
	UINT layout = GetFrameLayout(frame);
	UINT relativelayout = GetFrameLayout(relativeframe);

	if (!layout || !relativelayout) {
		return;
	}

	SetCLayoutFramePoint(layout, NULL, point, relativelayout, relativepoint, offsetX, offsetY, 1);
}

float GetFrameWidth(UINT frame) {
	UINT layout = GetFrameLayout(frame);

	if (!layout) {
		return NULL;
	}

	return *(float*)(layout + 0x58);
}

float GetFrameHeight(UINT frame) {
	UINT layout = GetFrameLayout(frame);

	if (!layout) {
		return NULL;
	}

	return *(float*)(layout + 0x5c);
}

UINT GetFramePoint(UINT frame, EFramePoint point) {
	UINT layout = GetFrameLayout(frame);

	if (!layout) {
		return NULL;
	}

	return *(UINT*)(layout + 4 * (UINT)point + 8);
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

UINT GetTriggerFrame() {
	return triggerFrame;
}

float GetFrameValue(UINT frame) {
	switch (GetFrameType(frame))
	{
	case Slider:
		return *(float*)(frame + 0x1f4);
	case SimpleStatusBar:
		return *(float*)(frame + 0x130);
	case StatusBar:
		return *(float*)(frame + 0x1bc);
	}

	return 0.f;
}

float GetTriggerFrameValue() {
	if (triggerEvent == FRAMEEVENT_MOUSE_WHEEL) {
		return (float)*pWheelState;
	}

	return GetFrameValue(triggerFrame);
}

void SetFrameValue(UINT frame, float value) {
	switch (GetFrameType(frame))
	{
	case Slider:
		SetCSliderCurrentValue(frame, NULL, value, 1);

		break;
	case SimpleStatusBar:
		SetCSimpleStatusBarValue(frame, NULL, value);

		break;
	case StatusBar:
		float min = *(float*)(frame + 0x1b4);
		// float max = *(float*)(frame + 0x1b8);

		value = value < min ? min : value;

		*(float*)(frame + 0x1bc) = value;

		break;
	}
}

void SetFrameMinMaxValue(UINT frame, float minValue, float maxValue) {
	float value = 0.f;
	
	switch (GetFrameType(frame)) {
	case Slider:
		value = *(float*)(frame + 0x1f4);

		*(float*)(frame + 0x1ec) = minValue;
		*(float*)(frame + 0x1f0) = maxValue;

		value = value >= minValue ? (value <= maxValue ? value : maxValue) : minValue;

		SetCSliderCurrentValue(frame, NULL, value, 1);

		break;
	case SimpleStatusBar:
		SetCSimpleStatusBarMinMaxValue(frame, NULL, minValue, maxValue);

		break;
	case StatusBar:
		SetCStatusBarMinMaxValue(frame, NULL, minValue, maxValue);

		break;
	}
}

void SetFrameStepSize(UINT frame, float stepSize) {
	if (GetFrameType(frame) == Slider) {
		*(float*)(frame + 0x1f8) = stepSize;
	}
}

void SetFrameTexture(UINT frame, LPCSTR texFile, BOOL flag) {
	switch (GetFrameType(frame))
	{
	case BackdropFrame:
		SetCBackDropFrameTexture(frame, NULL, texFile, NULL, flag, NULL, 1);

		break;
	case SimpleStatusBar:
		SetCSimpleStatusBarTexture(frame, NULL, texFile, flag);

		break;
	case SimpleTexture:
		SetCSimpleTextureTexture(frame, NULL, texFile, flag);

		break;
	}
}

void SetFrameEnable(UINT frame, BOOL enabled) {
	if (frame) {
		SetCControlState(frame, NULL, enabled);
	}
}

void ClickFrame(UINT frame) {
	if (frame) {
		ClickCFrame(frame, NULL, 1);
	}
}

void SetFrameModel(UINT frame, LPCSTR modelFile, UINT modeltype, BOOL flag) {
	switch (GetFrameType(frame))
	{
	case ModelFrame:
		AddCModelFrameModel(frame, NULL, modelFile, modeltype);

		break;
	case SpriteFrame:
		SetCSpriteFrameArt(frame, NULL, modelFile, modeltype, flag);

		break;
	case StatusBar:
		SetCStatusBarArt(frame, NULL, modelFile, modeltype);

		break;
	}
}

void DestroyFrame(UINT frame) {
	if (frame) {
		for (size_t i = 0; i < frames.size(); i++) {
			if (frames[i] == frame) {
				frames.erase(frames.begin() + i);
			}
		}

		auto frameevent = frameEventHashTable.find(frame);
		if (frameevent != frameEventHashTable.end()) {
			//frameevent->second.clear();
			frameEventHashTable.erase(frameevent);
		}

		DestroyCFrame(frame, NULL, 1);
	}
}

void SetFrameVisible(UINT frame, BOOL visible) {
	if (frame) {
		if (visible) {
			ShowCFrame(frame);
		}
		else {
			HideCFrame(frame);
		}
	}
}

void SetGameUIVisible(BOOL visible) {
	CGameUI* gameui = GetGameUI(0, 0);

	if (visible) {
		HideCFrame((UINT)gameui->SimpleConsole);
		ShowCFrame((UINT)gameui->TimeOfDayIndicator);
		ShowCFrame((UINT)gameui->Portrait);
		ShowCFrame((UINT)gameui->Minimap);

		SetFramePoint((UINT)gameui->WorldFrameWar3, FRAMEPOINT_TOPRIGHT, (UINT)gameui, FRAMEPOINT_TOPRIGHT, 0.f, -0.02f);
		SetFramePoint((UINT)gameui->WorldFrameWar3, FRAMEPOINT_BOTTOMLEFT, (UINT)gameui, FRAMEPOINT_BOTTOMLEFT, 0.f, 0.13f);
	}
	else {
		ShowCFrame((UINT)gameui->SimpleConsole);
		HideCFrame((UINT)gameui->TimeOfDayIndicator);
		HideCFrame((UINT)gameui->Portrait);
		HideCFrame((UINT)gameui->Minimap);
		
		SetFramePoint((UINT)gameui->WorldFrameWar3, FRAMEPOINT_TOPRIGHT, (UINT)gameui, FRAMEPOINT_TOPRIGHT, 0.f, 0.f);
		SetFramePoint((UINT)gameui->WorldFrameWar3, FRAMEPOINT_BOTTOMLEFT, (UINT)gameui, FRAMEPOINT_BOTTOMLEFT, 0.f, 0.f);
	}
}

void SetFrameCheck(UINT frame, BOOL check) {
	if (GetFrameType(frame) == GlueCheckBoxWar3) {
		*(BOOL*)(frame + 0x1d4) = *(BOOL*)(frame + 0x1d4) ^ (check << 5);
	}
}

//---------------------------------------------------------

BOOL __stdcall eventCallback(UINT frame, UINT eventtype, DWORD eventaddress) {
	EFrameEvent event = GetFrameEventType(eventtype);
	UINT eventData = *(UINT*)(eventaddress + 0x10);

	switch (event)
	{
	case FRAMEEVENT_MOUSE_MOVE:
		event = eventData ? FRAMEEVENT_MOUSE_ENTER : FRAMEEVENT_MOUSE_LEAVE;

		break;
	case FRAMEEVENT_CHECKBOX_CHECK:
		event = eventData ? FRAMEEVENT_CHECKBOX_CHECKED : FRAMEEVENT_CHECKBOX_UNCHECKED;

		break;
	case FRAMEEVENT_EDITBOX_BUTTON_DOWN:
		event = (eventData == 0x201) ? FRAMEEVENT_EDITBOX_ENTER : FRAMEEVENT_EDITBOX_TEXT_CHANGED;

		break;
	}

	auto frameevent = frameEventHashTable[frame].find(event);
	if (frameevent != frameEventHashTable[frame].end()) {
		triggerFrame = frame;
		triggerEvent = event;

		UINT trigger = frameevent->second;
		if (TriggerEvaluate(trigger)) {
			TriggerExecute(trigger);

			return TRUE;
		}

		return FALSE;
	}

	return -1;
}

void GameUI_reset() {
	frameEventHashTable.clear();
	frames.clear();
	triggerFrame = NULL;
	triggerEvent = FRAMEEVENT_NONE;
}