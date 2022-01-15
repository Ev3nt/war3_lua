#pragma once

#include "Warcraft.h"
#include "Mem.h"

enum EFramePoint : UINT
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

enum EFrameEvent : UINT {
	FRAMEEVENT_CONTROL_CLICK = 1, 
	FRAMEEVENT_MOUSE_ENTER,
	FRAMEEVENT_MOUSE_LEAVE,
	FRAMEEVENT_MOUSE_UP,
	FRAMEEVENT_MOUSE_DOWN,
	FRAMEEVENT_MOUSE_WHEEL,
	FRAMEEVENT_CHECKBOX_CHECKED,
	FRAMEEVENT_CHECKBOX_UNCHECKED,
	FRAMEEVENT_EDITBOX_TEXT_CHANGED,
	FRAMEEVENT_POPUPMENU_ITEM_CHANGED,
	FRAMEEVENT_MOUSE_DOUBLECLICK,
	FRAMEEVENT_SPRITE_ANIM_UPDATE,
	FRAMEEVENT_SLIDER_VALUE_CHANGED,
	FRAMEEVENT_DIALOG_CANCEL,
	FRAMEEVENT_DIALOG_ACCEPT,
	FRAMEEVENT_EDITBOX_ENTER
};

//DWORD eventType[16] = {MakePtr(gameBase, _frameevent_control_click), MakePtr(gameBase, _frameevent_control_mouseenter) };

UINT GetOriginFrame(EOriginFrame originframe, UINT index);

UINT GetPanelButton(UINT frame, BYTE row, BYTE column);

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

//---------------------------------------------------------------------------------------

void TriggerRegisterFrameEvent(UINT trigger, UINT frame, EFrameEvent event);