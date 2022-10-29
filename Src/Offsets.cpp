#include "pch.h"
#include "Warcraft.h"
#include "Offsets.h"

UINT_PTR pOffsets[(size_t)Offset::SIZE];

bool InitOffsets() {
	switch (Warcraft::GetWarcraftVersion()) {
	case Warcraft::Version::V124e:
		pOffsets[(UINT)Offset::CGameEventHandler] = 0x62a230;
		pOffsets[(UINT)Offset::GetWarcraftVersionKey] = 0x5389d0;
		pOffsets[(UINT)Offset::OpcodeList] = 0x45f56a;
		pOffsets[(UINT)Offset::OpcodeSize] = 0x45f56d;
		pOffsets[(UINT)Offset::OpcodeDefaultOutput] = 0x4602aa;
		pOffsets[(UINT)Offset::jStringToString] = 0x3bb560;
		pOffsets[(UINT)Offset::LastPlayedMap] = 0xac55e0;
		pOffsets[(UINT)Offset::GameTLSIndex] = 0xacea4c;
		pOffsets[(UINT)Offset::GameObject] = 0xacd44c;
		pOffsets[(UINT)Offset::GetGameUI] = 0x301250;
		pOffsets[(UINT)Offset::DisplayTimedTextToPlayer] = 0x2f9980;
		pOffsets[(UINT)Offset::GlobalDeallocator] = 0x1f70;
		pOffsets[(UINT)Offset::OnProcMain] = 0x6c7240;
		pOffsets[(UINT)Offset::GetjVariableByName] = 0x44d6d0;

		break;
	case Warcraft::Version::V126a:
		pOffsets[(UINT)Offset::CGameEventHandler] = 0x629a90;
		pOffsets[(UINT)Offset::GetWarcraftVersionKey] = 0x537ed0;
		pOffsets[(UINT)Offset::OpcodeList] = 0x45ea5a;
		pOffsets[(UINT)Offset::OpcodeSize] = 0x45ea4d;
		pOffsets[(UINT)Offset::OpcodeDefaultOutput] = 0x45f79a;
		pOffsets[(UINT)Offset::jStringToString] = 0x3baa20;
		pOffsets[(UINT)Offset::LastPlayedMap] = 0xaae788;
		pOffsets[(UINT)Offset::GameTLSIndex] = 0xab7bf4;
		pOffsets[(UINT)Offset::GameObject] = 0xab65f4;
		pOffsets[(UINT)Offset::GetGameUI] = 0x300710;
		pOffsets[(UINT)Offset::DisplayTimedTextToPlayer] = 0x2f8e40;
		pOffsets[(UINT)Offset::GlobalDeallocator] = 0x1f70;
		pOffsets[(UINT)Offset::OnProcMain] = 0x6c6aa0;
		pOffsets[(UINT)Offset::GetjVariableByName] = 0x44cbc0;

		break;
	case Warcraft::Version::V127a:
		pOffsets[(UINT)Offset::CGameEventHandler] = 0x0562e0;
		pOffsets[(UINT)Offset::GetWarcraftVersionKey] = 0x30d970;
		pOffsets[(UINT)Offset::OpcodeList] = 0x7f1aaa;
		pOffsets[(UINT)Offset::OpcodeSize] = 0x7f1aad;
		pOffsets[(UINT)Offset::OpcodeDefaultOutput] = 0x7f1c3e;
		pOffsets[(UINT)Offset::jStringToString] = 0x1da520;
		pOffsets[(UINT)Offset::LastPlayedMap] = 0xbee150;
		pOffsets[(UINT)Offset::GameTLSIndex] = 0xbb8628;
		pOffsets[(UINT)Offset::GameObject] = 0xbe4238;
		pOffsets[(UINT)Offset::GetGameUI] = 0x34f3a0;
		pOffsets[(UINT)Offset::DisplayTimedTextToPlayer] = 0x357640;
		pOffsets[(UINT)Offset::GlobalDeallocator] = 0x218c0;
		pOffsets[(UINT)Offset::OnProcMain] = 0x153710;
		pOffsets[(UINT)Offset::GetjVariableByName] = 0x7e5820;

		break;
	case Warcraft::Version::V127b:
		pOffsets[(UINT)Offset::CGameEventHandler] = 0x071da0;
		pOffsets[(UINT)Offset::GetWarcraftVersionKey] = 0x32b0e0;
		pOffsets[(UINT)Offset::OpcodeList] = 0x91b4ea;
		pOffsets[(UINT)Offset::OpcodeSize] = 0x91b4ed;
		pOffsets[(UINT)Offset::OpcodeDefaultOutput] = 0x91c1d5;
		pOffsets[(UINT)Offset::jStringToString] = 0x1f7f60;
		pOffsets[(UINT)Offset::LastPlayedMap] = 0xd726b8;
		pOffsets[(UINT)Offset::GameTLSIndex] = 0xd3cb98;
		pOffsets[(UINT)Offset::GameObject] = 0xd687a8;
		pOffsets[(UINT)Offset::GetGameUI] = 0x36cb20;
		pOffsets[(UINT)Offset::DisplayTimedTextToPlayer] = 0x374de0;
		pOffsets[(UINT)Offset::GlobalDeallocator] = 0x3e9c0;
		pOffsets[(UINT)Offset::OnProcMain] = 0x0913d0;
		pOffsets[(UINT)Offset::GetjVariableByName] = 0x90f230;

		break;
	case Warcraft::Version::V128f:
		pOffsets[(UINT)Offset::CGameEventHandler] = 0x09b9d0;
		pOffsets[(UINT)Offset::GetWarcraftVersionKey] = 0x35ed70;
		pOffsets[(UINT)Offset::OpcodeList] = 0x8d043a;
		pOffsets[(UINT)Offset::OpcodeSize] = 0x8d043d;
		pOffsets[(UINT)Offset::OpcodeDefaultOutput] = 0x8d1125;
		pOffsets[(UINT)Offset::jStringToString] = 0x22a770;
		pOffsets[(UINT)Offset::LastPlayedMap] = 0xd3A4f0;
		pOffsets[(UINT)Offset::GameTLSIndex] = 0xd047a8;
		pOffsets[(UINT)Offset::GameObject] = 0xd305e0;
		pOffsets[(UINT)Offset::GetGameUI] = 0x3a0b70;
		pOffsets[(UINT)Offset::DisplayTimedTextToPlayer] = 0x3a8eb0;
		pOffsets[(UINT)Offset::GlobalDeallocator] = 0x69a50;
		pOffsets[(UINT)Offset::OnProcMain] = 0x0bad40;
		pOffsets[(UINT)Offset::GetjVariableByName] = 0x8c4180;

		break;
	default:
		return false;
	}

	for (auto& offset : pOffsets) {
		offset += offset ? (UINT_PTR)gameBase : NULL;
	}

	return true;
}