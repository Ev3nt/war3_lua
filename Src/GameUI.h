#pragma once

#include <Windows.h>
#include <map>
#include <unordered_map>

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

enum EFramePoint : UINT {
	FRAMEPOINT_TOPLEFT,
	FRAMEPOINT_TOP,
	FRAMEPOINT_TOPRIGHT,
	FRAMEPOINT_LEFT,
	FRAMEPOINT_CENTER,
	FRAMEPOINT_RIGHT,
	FRAMEPOINT_BOTTOMLEFT,
	FRAMEPOINT_BOTTOM,
	FRAMEPOINT_BOTTOMRIGHT
};

enum EFrameType : UINT {
	MissingFrame, // Frame doesn't exist
	BackdropFrame,
	ButtonFrame,
	ChatMode,
	CommandButton,
	CursorFrame,
	EditBox,
	Frame,
	FloatingFrame,
	GameUI,
	HeroBarButton,
	HighlightFrame,
	LayoutFrame,
	MessageFrame,
	Minimap,
	ModelFrame,
	PortraitButton,
	ScreenFrame,
	SimpleButton,
	SimpleFontString,
	SimpleFrame,
	SimpleGlueFrame,
	Uknown_1,
	SimpleMessageFrame,
	Slider,
	SpriteFrame,
	StatBar,
	TextArea,
	TextButtonFrame,
	TextFrame,
	UberToolTipWar3,
	WorldFrameWar3,
	GlueButtonWar3,
	GlueTextButtonWar3,
	GlueCheckBoxWar3,
	GluePopupMenuWar3,
	GlueEditBoxWar3,
	SlashChatBox,
	TimerTextFrame,
	SimpleStatusBar,
	StatusBar,
	UpperButtonBar,
	ResourceBar,
	SimpleConsole,
	PeonBar,
	HeroBar,
	TimeOfDayIndicator,
	InfoBar,
	TimeCover,
	ProgressIndicator,
	HeroLevelBar,
	BuildTimeIndicator,
	InfoPanelDestructableDetail,
	InfoPanelItemDetail,
	InfoPanelIconAlly,
	InfoPanelIconHero,
	InfoPanelIconGold,
	InfoPanelIconFood,
	InfoPanelIconRank,
	InfoPanelIconArmor,
	InfoPanelIconDamage,
	InfoPanelCargoDetail,
	InfoPanelBuildingDetail,
	InfoPanelUnitDetail,
	SimpleTexture
};

EFrameType GetFrameType(UINT frame);

enum EFrameEvent : UINT {
	FRAMEEVENT_NONE,
	FRAMEEVENT_CONTROL_CLICK,
	FRAMEEVENT_MOUSE_MOVE,
	FRAMEEVENT_MOUSE_ENTER = 2,
	FRAMEEVENT_MOUSE_LEAVE,
	FRAMEEVENT_MOUSE_UP,
	FRAMEEVENT_MOUSE_DOWN,
	FRAMEEVENT_MOUSE_WHEEL,
	FRAMEEVENT_CHECKBOX_CHECK,
	FRAMEEVENT_CHECKBOX_CHECKED = 7,
	FRAMEEVENT_CHECKBOX_UNCHECKED,
	FRAMEEVENT_EDITBOX_BUTTON_DOWN,
	FRAMEEVENT_EDITBOX_TEXT_CHANGED = 9,
	FRAMEEVENT_POPUPMENU_ITEM_CHANGED,
	FRAMEEVENT_MOUSE_DOUBLECLICK,
	FRAMEEVENT_SPRITE_ANIM_UPDATE,
	FRAMEEVENT_SLIDER_VALUE_CHANGED,
	FRAMEEVENT_DIALOG_CANCEL,
	FRAMEEVENT_DIALOG_ACCEPT,
	FRAMEEVENT_EDITBOX_ENTER
};

struct CGameUI {
	int FrameType;
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
	int LayoutType;
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

EFrameType GetFrameType(UINT frame);

UINT GetFrameLayout(UINT frame);

CGameUI* GetGameUI(UINT unknown1 = NULL, UINT unknown2 = NULL);

UINT GetOriginFrame(EOriginFrame originframe, UINT index);

UINT GetPanelButton(UINT frame, BYTE row, BYTE column);

UINT GetTooltipFrame(UINT unknown0 = NULL);

BOOL LoadTOCFile(LPCSTR filename);

UINT GetFrameByName(LPCSTR framename, UINT id);

UINT GetFrameParent(UINT frame);

UINT GetFrameChildrenCount(UINT frame);

UINT GetFrameChild(UINT frame, UINT index);

void TriggerRegisterFrameEvent(UINT trigger, UINT frame, EFrameEvent event);

UINT CreateFrame(LPCSTR baseframe, UINT parentframe, EFramePoint point, EFramePoint relativepoint);

void SetFrameText(UINT frame, LPCSTR text);

LPCSTR GetFrameText(UINT frame);

void SetFrameTextColor(UINT frame, BYTE red, BYTE green, BYTE blue, BYTE alpha);

float GetFrameTextHeight(UINT frame);

void SetFrameFont(UINT frame, LPCSTR filename, float height, UINT flag);

void SetFrameWidth(UINT frame, float width);

void SetFrameHeight(UINT frame, float height);

void SetFrameSize(UINT frame, float width, float height);

void SetFrameScale(UINT frame, float scale);

void SetFrameAbsolutePoint(UINT frame, EFramePoint point, float offsetX, float offsetY);

void SetFramePoint(UINT frame, EFramePoint point, UINT relativeframe, EFramePoint relativepoint, float offsetX, float offsetY);

float GetFrameWidth(UINT frame);

float GetFrameHeight(UINT frame);

UINT GetFramePointParent(UINT frame, EFramePoint point);

UINT GetFramePointRelativePoint(UINT frame, EFramePoint point);

float GetFramePointX(UINT frame, EFramePoint point);

float GetFramePointY(UINT frame, EFramePoint point);

UINT GetTriggerFrame();

float GetFrameValue(UINT frame);

float GetTriggerFrameValue();

void SetFrameValue(UINT frame, float value);

void SetFrameMinMaxValue(UINT frame, float minValue, float maxValue);

void SetFrameStepSize(UINT frame, float stepSize);

void SetFrameTexture(UINT frame, LPCSTR texFile, BOOL flag);

void SetFrameEnable(UINT frame, BOOL enabled);

void ClickFrame(UINT frame);

void SetFrameModel(UINT frame, LPCSTR modelFile, UINT modeltype, BOOL flag);

void DestroyFrame(UINT frame);

void SetFrameVisible(UINT frame, BOOL visible);

void SetGameUIVisible(BOOL visible);

void SetFrameCheck(UINT frame, BOOL check);

//---------------------------------------------------------

BOOL __stdcall eventCallback(UINT frame, UINT eventtype, DWORD eventaddress);

void GameUI_reset();

//---------------------------------------------------------

extern std::map<UINT, std::unordered_map<EFrameEvent, UINT>> frameEventHashTable;

extern std::vector<UINT> frames;