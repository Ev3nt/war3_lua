#pragma once

enum class Offset : UINT {
	CGameEventHandler,
	GetWarcraftVersionKey,
	OpcodeList,
	OpcodeSize,
	OpcodeDefaultOutput,
	jStringToString,
	LastPlayedMap,
	GameTLSIndex,
	GameObject,
	GetGameUI,
	DisplayTimedTextToPlayer,
	SIZE
};

extern UINT_PTR pOffsets[(size_t)Offset::SIZE];

bool InitOffsets();