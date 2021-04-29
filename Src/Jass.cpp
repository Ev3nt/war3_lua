#include "Jass.h"
#include "Variables.h"

jReal to_jReal(float fX)
{
	return *(jReal*)&fX;
}

jString to_jString(LPCSTR lpString)
{
	UINT32* string = new UINT32[8];

	string[2] = (UINT32)&string[0];
	string[7] = (UINT32)&lpString[0];

	return (jString)string;
}

LPCSTR from_jString(jString string)
{
	if (!string)
		return NULL;

	return *(LPCSTR*)((UINT32*)string)[7];
}

jInteger to_ID(LPCSTR lpID)
{
	return lpID[0] * 256 * 256 * 256 + lpID[1] * 256 * 256 + lpID[2] * 256 + lpID[3];
}

//---------------------------------------------------------

jNothing __declspec(naked) DebugS(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc0a0
		jmp eax
	}
}

jNothing __declspec(naked) DebugFI(jString, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc0b0
		jmp eax
	}
}

jNothing __declspec(naked) DebugUnitID(jString, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc0c0
		jmp eax
	}
}

jNothing __declspec(naked) DisplayText(jInteger, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc060
		jmp eax
	}
}

jNothing __declspec(naked) DisplayTextI(jInteger, jString, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc070
		jmp eax
	}
}

jNothing __declspec(naked) DisplayTextII(jInteger, jString, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc080
		jmp eax
	}
}

jNothing __declspec(naked) DisplayTextIII(jInteger, jString, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc090
		jmp eax
	}
}

jNothing __declspec(naked) SuicideUnit(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de330
		jmp eax
	}
}

jNothing __declspec(naked) SuicideUnitEx(jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de2e0
		jmp eax
	}
}

jNothing __declspec(naked) Sleep(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de380
		jmp eax
	}
}

jNothing __declspec(naked) StartThread(jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de2a0
		jmp eax
	}
}

jInteger __declspec(naked) GetAiPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dcfe0
		jmp eax
	}
}

jBoolean __declspec(naked) DoAiScriptDebug()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc0d0
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroId()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddf50
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroLevelAI()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de0e0
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroLevels(jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0b00
		jmp eax
	}
}

jNothing __declspec(naked) SetNewHeroes(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e3020
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitCount(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd050
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerUnitTypeCount(HPLAYER, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2b60
		jmp eax
	}
}

jInteger __declspec(naked) GetTownUnitCount(jInteger, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd0c0
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitCountDone(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd010
		jmp eax
	}
}

jInteger __declspec(naked) GetUpgradeLevel(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd130
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitGoldCost(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd1e0
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitWoodCost(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd240
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitBuildTime(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd190
		jmp eax
	}
}

jInteger __declspec(naked) GetUpgradeGoldCost(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd2a0
		jmp eax
	}
}

jInteger __declspec(naked) GetUpgradeWoodCost(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd2c0
		jmp eax
	}
}

jInteger __declspec(naked) GetEnemyPower()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc150
		jmp eax
	}
}

jInteger __declspec(naked) GetMinesOwned()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddfd0
		jmp eax
	}
}

jInteger __declspec(naked) GetGoldOwned()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de000
		jmp eax
	}
}

jInteger __declspec(naked) TownWithMine()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de030
		jmp eax
	}
}

jBoolean __declspec(naked) TownHasMine(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de060
		jmp eax
	}
}

jBoolean __declspec(naked) TownHasHall(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2de0a0
		jmp eax
	}
}

jInteger __declspec(naked) GetNextExpansion()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2bc0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetExpansionPeon()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd530
		jmp eax
	}
}

HUNIT  __declspec(naked) GetEnemyExpansion()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd4f0
		jmp eax
	}
}

jBoolean __declspec(naked) SetExpansion(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0570
		jmp eax
	}
}

HUNIT  __declspec(naked) GetBuilding(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2e80
		jmp eax
	}
}

jNothing __declspec(naked) SetAllianceTarget(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0630
		jmp eax
	}
}

HUNIT  __declspec(naked) GetAllianceTarget()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd570
		jmp eax
	}
}

jBoolean __declspec(naked) SetProduce(jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd450
		jmp eax
	}
}

jBoolean __declspec(naked) MergeUnits(jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd320
		jmp eax
	}
}

jBoolean __declspec(naked) ConvertUnits(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd2e0
		jmp eax
	}
}

jBoolean __declspec(naked) SetUpgrade(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd4b0
		jmp eax
	}
}

jNothing __declspec(naked) Unsummon(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e08a0
		jmp eax
	}
}

jNothing __declspec(naked) ClearHarvestAI()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd5b0
		jmp eax
	}
}

jNothing __declspec(naked) HarvestGold(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd5e0
		jmp eax
	}
}

jNothing __declspec(naked) HarvestWood(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd630
		jmp eax
	}
}

jNothing __declspec(naked) StopGathering()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dce00
		jmp eax
	}
}

jNothing __declspec(naked) AddGuardPost(jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dce30
		jmp eax
	}
}

jNothing __declspec(naked) FillGuardPosts()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dcf80
		jmp eax
	}
}

jNothing __declspec(naked) ReturnGuardPosts()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dcfb0
		jmp eax
	}
}

jNothing __declspec(naked) CreateCaptains()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd960
		jmp eax
	}
}

jNothing __declspec(naked) SetCaptainHome(jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd7b0
		jmp eax
	}
}

jNothing __declspec(naked) ResetCaptainLocs()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd780
		jmp eax
	}
}

jNothing __declspec(naked) ShiftTownSpot(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd740
		jmp eax
	}
}

jNothing __declspec(naked) SetCaptainChanges(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2d20
		jmp eax
	}
}

jNothing __declspec(naked) TeleportCaptain(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd680
		jmp eax
	}
}

jNothing __declspec(naked) ClearCaptainTargets()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd6c0
		jmp eax
	}
}

jNothing __declspec(naked) CaptainVsUnits(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2bf0
		jmp eax
	}
}

jNothing __declspec(naked) CaptainVsPlayer(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2c80
		jmp eax
	}
}

jNothing __declspec(naked) CaptainAttack(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd700
		jmp eax
	}
}

jNothing __declspec(naked) GroupTimedLife(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2d60
		jmp eax
	}
}

jNothing __declspec(naked) CaptainGoHome()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd800
		jmp eax
	}
}

jBoolean __declspec(naked) CaptainIsHome()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd870
		jmp eax
	}
}

jBoolean __declspec(naked) CaptainRetreating()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd830
		jmp eax
	}
}

jBoolean __declspec(naked) CaptainIsFull()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddb10
		jmp eax
	}
}

jBoolean __declspec(naked) CaptainIsEmpty()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddb50
		jmp eax
	}
}

jInteger __declspec(naked) CaptainGroupSize()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddb90
		jmp eax
	}
}

jInteger __declspec(naked) CaptainReadiness()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dda40
		jmp eax
	}
}

jInteger __declspec(naked) CaptainReadinessHP()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dda90
		jmp eax
	}
}

jInteger __declspec(naked) CaptainReadinessMa()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddad0
		jmp eax
	}
}

jBoolean __declspec(naked) CaptainInCombat(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd8a0
		jmp eax
	}
}

jBoolean __declspec(naked) TownThreatened()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd8e0
		jmp eax
	}
}

jBoolean __declspec(naked) CaptainAtGoal()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd930
		jmp eax
	}
}

jBoolean __declspec(naked) CreepsOnMap()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc0f0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveInjuries()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddda0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveSiege()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dde00
		jmp eax
	}
}

jBoolean __declspec(naked) IsTowered(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0950
		jmp eax
	}
}

jNothing __declspec(naked) DisablePathing()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e06e0
		jmp eax
	}
}

jNothing __declspec(naked) SetAmphibious()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0720
		jmp eax
	}
}

jNothing __declspec(naked) InitAssault()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd990
		jmp eax
	}
}

jBoolean __declspec(naked) AddAssault(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd9c0
		jmp eax
	}
}

jBoolean __declspec(naked) AddDefenders(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dda00
		jmp eax
	}
}

HUNIT  __declspec(naked) GetCreepCamp(jInteger, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e3d50
		jmp eax
	}
}

jNothing __declspec(naked) StartGetEnemyBase()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddcc0
		jmp eax
	}
}

jBoolean __declspec(naked) WaitGetEnemyBase()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddcf0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetMegaTarget()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddd60
		jmp eax
	}
}

HUNIT  __declspec(naked) GetEnemyBase()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddd20
		jmp eax
	}
}

HUNIT  __declspec(naked) GetExpansionFoe()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2e40
		jmp eax
	}
}

jInteger __declspec(naked) GetExpansionX()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2da0
		jmp eax
	}
}

jInteger __declspec(naked) GetExpansionY()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2df0
		jmp eax
	}
}

jNothing __declspec(naked) SetStagePoint(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddbd0
		jmp eax
	}
}

jNothing __declspec(naked) AttackMoveKill(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0a40
		jmp eax
	}
}

jNothing __declspec(naked) AttackMoveXY(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddc10
		jmp eax
	}
}

jNothing __declspec(naked) LoadZepWave(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddc50
		jmp eax
	}
}

jBoolean __declspec(naked) SuicidePlayer(HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2f00
		jmp eax
	}
}

jBoolean __declspec(naked) SuicidePlayerUnits(HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e2f90
		jmp eax
	}
}

jBoolean __declspec(naked) UnitAlive(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0760
		jmp eax
	}
}

jBoolean __declspec(naked) UnitInvis(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e07c0
		jmp eax
	}
}

jInteger __declspec(naked) IgnoredUnits(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dce80
		jmp eax
	}
}

jInteger __declspec(naked) CommandsWaiting()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dcdd0
		jmp eax
	}
}

jInteger __declspec(naked) GetLastCommand()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0450
		jmp eax
	}
}

jInteger __declspec(naked) GetLastData()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0490
		jmp eax
	}
}

jNothing __declspec(naked) PopLastCommand()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e04d0
		jmp eax
	}
}

jNothing __declspec(naked) SetCampaignAI()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddea0
		jmp eax
	}
}

jNothing __declspec(naked) SetMeleeAI()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddee0
		jmp eax
	}
}

jNothing __declspec(naked) SetTargetHeroes(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dde60
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroesFlee(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e3120
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroesBuyItems(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e3160
		jmp eax
	}
}

jNothing __declspec(naked) SetIgnoreInjured(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e31e0
		jmp eax
	}
}

jNothing __declspec(naked) SetPeonsRepair(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e3060
		jmp eax
	}
}

jNothing __declspec(naked) SetRandomPaths(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e30a0
		jmp eax
	}
}

jNothing __declspec(naked) SetDefendPlayer(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e30e0
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroesTakeItems(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e3220
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitsFlee(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e3260
		jmp eax
	}
}

jNothing __declspec(naked) SetGroupsFlee(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e32a0
		jmp eax
	}
}

jNothing __declspec(naked) SetSlowChopping(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e32e0
		jmp eax
	}
}

jNothing __declspec(naked) SetSmartArtillery(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2ddf10
		jmp eax
	}
}

jNothing __declspec(naked) SetWatchMegaTargets(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e31a0
		jmp eax
	}
}

jNothing __declspec(naked) SetReplacementCount(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0b30
		jmp eax
	}
}

jNothing __declspec(naked) PurchaseZeppelin()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dd410
		jmp eax
	}
}

jInteger __declspec(naked) MeleeDifficulty()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2e0500
		jmp eax
	}
}

jNothing __declspec(naked) DebugBreak(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x2dc050
		jmp eax
	}
}

jReal __declspec(naked) Deg2Rad(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b29d0
		jmp eax
	}
}

jReal __declspec(naked) Rad2Deg(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b29f0
		jmp eax
	}
}

jReal __declspec(naked) Sin(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2a10
		jmp eax
	}
}

jReal __declspec(naked) Cos(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2a30
		jmp eax
	}
}

jReal __declspec(naked) Tan(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2a50
		jmp eax
	}
}

jReal __declspec(naked) Asin(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2a70
		jmp eax
	}
}

jReal __declspec(naked) Acos(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2ab0
		jmp eax
	}
}

jReal __declspec(naked) Atan(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2af0
		jmp eax
	}
}

jReal __declspec(naked) Atan2(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2b10
		jmp eax
	}
}

jReal __declspec(naked) SquareRoot(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2ba0
		jmp eax
	}
}

jReal __declspec(naked) Pow(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2c00
		jmp eax
	}
}

jReal __declspec(naked) I2R(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2cc0
		jmp eax
	}
}

jInteger __declspec(naked) R2I(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2ce0
		jmp eax
	}
}

jString __declspec(naked) I2S(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baaa0
		jmp eax
	}
}

jString __declspec(naked) R2S(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baaf0
		jmp eax
	}
}

jString __declspec(naked) R2SW(jReal*, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bab40
		jmp eax
	}
}

jInteger __declspec(naked) S2I(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2d10
		jmp eax
	}
}

jReal __declspec(naked) S2R(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2d50
		jmp eax
	}
}

jInteger __declspec(naked) GetHandleId(HHANDLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2d00
		jmp eax
	}
}

jString __declspec(naked) SubString(jString, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baba0
		jmp eax
	}
}

jInteger __declspec(naked) StringLength(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bac20
		jmp eax
	}
}

jString __declspec(naked) StringCase(jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bac40
		jmp eax
	}
}

jInteger __declspec(naked) StringHash(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2d30
		jmp eax
	}
}

jString __declspec(naked) GetLocalizedString(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bacf0
		jmp eax
	}
}

jInteger __declspec(naked) GetLocalizedHotkey(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2d80
		jmp eax
	}
}

HRACE  __declspec(naked) ConvertRace(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2600
		jmp eax
	}
}

HALLIANCETYPE  __declspec(naked) ConvertAllianceType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2610
		jmp eax
	}
}

HRACEPREFERENCE  __declspec(naked) ConvertRacePref(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2620
		jmp eax
	}
}

HIGAMESTATE  __declspec(naked) ConvertIGameState(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2630
		jmp eax
	}
}

HFGAMESTATE  __declspec(naked) ConvertFGameState(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2640
		jmp eax
	}
}

HPLAYERSTATE  __declspec(naked) ConvertPlayerState(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2650
		jmp eax
	}
}

HPLAYERSCORE  __declspec(naked) ConvertPlayerScore(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2660
		jmp eax
	}
}

HSTARTLOCPRIO  __declspec(naked) ConvertStartLocPrio(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2740
		jmp eax
	}
}

HPLAYERGAMERESULT  __declspec(naked) ConvertPlayerGameResult(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2670
		jmp eax
	}
}

HUNITSTATE  __declspec(naked) ConvertUnitState(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2680
		jmp eax
	}
}

HAIDIFFICULTY  __declspec(naked) ConvertAIDifficulty(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2690
		jmp eax
	}
}

HGAMEEVENT  __declspec(naked) ConvertGameEvent(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b26a0
		jmp eax
	}
}

HPLAYEREVENT  __declspec(naked) ConvertPlayerEvent(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b26b0
		jmp eax
	}
}

HPLAYERUNITEVENT  __declspec(naked) ConvertPlayerUnitEvent(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b26c0
		jmp eax
	}
}

HUNITEVENT  __declspec(naked) ConvertUnitEvent(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b26d0
		jmp eax
	}
}

HWIDGETEVENT  __declspec(naked) ConvertWidgetEvent(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b26e0
		jmp eax
	}
}

HDIALOGEVENT  __declspec(naked) ConvertDialogEvent(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b26f0
		jmp eax
	}
}

HLIMITOP  __declspec(naked) ConvertLimitOp(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2700
		jmp eax
	}
}

HUNITTYPE  __declspec(naked) ConvertUnitType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2710
		jmp eax
	}
}

HGAMESPEED  __declspec(naked) ConvertGameSpeed(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2720
		jmp eax
	}
}

HPLACEMENT  __declspec(naked) ConvertPlacement(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2730
		jmp eax
	}
}

HGAMEDIFFICULTY  __declspec(naked) ConvertGameDifficulty(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2750
		jmp eax
	}
}

HGAMETYPE  __declspec(naked) ConvertGameType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2760
		jmp eax
	}
}

HMAPFLAG  __declspec(naked) ConvertMapFlag(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2770
		jmp eax
	}
}

HMAPVISIBILITY  __declspec(naked) ConvertMapVisibility(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2780
		jmp eax
	}
}

HMAPSETTING  __declspec(naked) ConvertMapSetting(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2790
		jmp eax
	}
}

HMAPDENSITY  __declspec(naked) ConvertMapDensity(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b27a0
		jmp eax
	}
}

HMAPCONTROL  __declspec(naked) ConvertMapControl(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b27b0
		jmp eax
	}
}

HPLAYERCOLOR  __declspec(naked) ConvertPlayerColor(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b27c0
		jmp eax
	}
}

HPLAYERSLOTSTATE  __declspec(naked) ConvertPlayerSlotState(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b27d0
		jmp eax
	}
}

HVOLUMEGROUP  __declspec(naked) ConvertVolumeGroup(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b27e0
		jmp eax
	}
}

HCAMERAFIELD  __declspec(naked) ConvertCameraField(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b27f0
		jmp eax
	}
}

HBLENDMODE  __declspec(naked) ConvertBlendMode(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2810
		jmp eax
	}
}

HRARITYCONTROL  __declspec(naked) ConvertRarityControl(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2800
		jmp eax
	}
}

HTEXMAPFLAGS  __declspec(naked) ConvertTexMapFlags(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2820
		jmp eax
	}
}

HFOGSTATE  __declspec(naked) ConvertFogState(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2830
		jmp eax
	}
}

HEFFECTTYPE  __declspec(naked) ConvertEffectType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2840
		jmp eax
	}
}

HVERSION  __declspec(naked) ConvertVersion(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2850
		jmp eax
	}
}

HITEMTYPE  __declspec(naked) ConvertItemType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2860
		jmp eax
	}
}

HATTACKTYPE  __declspec(naked) ConvertAttackType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2870
		jmp eax
	}
}

HDAMAGETYPE  __declspec(naked) ConvertDamageType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2880
		jmp eax
	}
}

HWEAPONTYPE  __declspec(naked) ConvertWeaponType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2890
		jmp eax
	}
}

HSOUNDTYPE  __declspec(naked) ConvertSoundType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b28a0
		jmp eax
	}
}

HPATHINGTYPE  __declspec(naked) ConvertPathingType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b28b0
		jmp eax
	}
}

jNothing __declspec(naked) SetMapName(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bada0
		jmp eax
	}
}

jNothing __declspec(naked) SetMapDescription(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3badc0
		jmp eax
	}
}

jNothing __declspec(naked) SetTeams(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d4000
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayers(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3badf0
		jmp eax
	}
}

jNothing __declspec(naked) SetGameTypeSupported(HGAMETYPE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bae10
		jmp eax
	}
}

jNothing __declspec(naked) SetMapFlag(HMAPFLAG, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bae70
		jmp eax
	}
}

jNothing __declspec(naked) SetGameSpeed(HGAMESPEED)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baed0
		jmp eax
	}
}

jNothing __declspec(naked) SetGamePlacement(HPLACEMENT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baef0
		jmp eax
	}
}

jNothing __declspec(naked) SetGameDifficulty(HGAMEDIFFICULTY)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf10
		jmp eax
	}
}

jNothing __declspec(naked) SetResourceDensity(HMAPDENSITY)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf30
		jmp eax
	}
}

jNothing __declspec(naked) SetCreatureDensity(HMAPDENSITY)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf50
		jmp eax
	}
}

jNothing __declspec(naked) DefineStartLocation(jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf70
		jmp eax
	}
}

jNothing __declspec(naked) DefineStartLocationLoc(jInteger, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0ea0
		jmp eax
	}
}

jNothing __declspec(naked) SetStartLocPrioCount(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf90
		jmp eax
	}
}

jNothing __declspec(naked) SetStartLocPrio(jInteger, jInteger, jInteger, HSTARTLOCPRIO)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bafc0
		jmp eax
	}
}

jInteger __declspec(naked) GetStartLocPrioSlot(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb000
		jmp eax
	}
}

HSTARTLOCPRIO  __declspec(naked) GetStartLocPrio(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb030
		jmp eax
	}
}

jInteger __declspec(naked) GetTeams()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bade0
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayers()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bae00
		jmp eax
	}
}

jBoolean __declspec(naked) IsGameTypeSupported(HGAMETYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bae40
		jmp eax
	}
}

jBoolean __declspec(naked) IsMapFlagSet(HMAPFLAG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baea0
		jmp eax
	}
}

HGAMETYPE  __declspec(naked) GetGameTypeSelected()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bae60
		jmp eax
	}
}

HPLACEMENT  __declspec(naked) GetGamePlacement()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf00
		jmp eax
	}
}

HGAMESPEED  __declspec(naked) GetGameSpeed()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baec0
		jmp eax
	}
}

HGAMEDIFFICULTY  __declspec(naked) GetGameDifficulty()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf20
		jmp eax
	}
}

HMAPDENSITY  __declspec(naked) GetResourceDensity()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf40
		jmp eax
	}
}

HMAPDENSITY  __declspec(naked) GetCreatureDensity()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3baf60
		jmp eax
	}
}

jReal __declspec(naked) GetStartLocationX(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb060
		jmp eax
	}
}

jReal __declspec(naked) GetStartLocationY(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb080
		jmp eax
	}
}

HLOCATION  __declspec(naked) GetStartLocationLoc(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d04b0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerTeam(HPLAYER, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0ee0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerStartLocation(HPLAYER, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0f80
		jmp eax
	}
}

jNothing __declspec(naked) ForcePlayerStartLocation(HPLAYER, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0fa0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerAlliance(HPLAYER, HPLAYER, HALLIANCETYPE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1050
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerTaxRate(HPLAYER, HPLAYER, HPLAYERSTATE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c10e0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerRacePreference(HPLAYER, HRACEPREFERENCE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c11a0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerRaceSelectable(HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c11d0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerController(HPLAYER, HMAPCONTROL)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1200
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerColor(HPLAYER, HPLAYERCOLOR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1220
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerOnScoreScreen(HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9800
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerName(HPLAYER, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0f10
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerTeam(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0f40
		jmp eax
	}
}

/*jString __declspec(naked) GetPlayerName(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0f60
		jmp eax
	}
}*/

// Rewrited
LPCSTR __declspec(naked) GetPlayerName(HPLAYER whichPlayer)
{
	_asm
	{
		mov ecx, [esp + 4]
		mov eax, hGame
		add eax, 0x3bd4d0
		call eax
		test eax, eax
		jne pSuccessful
		ret
	pSuccessful :
		push 1
		mov ecx, eax
		mov eax, hGame
		add eax, 0x40aff0
		call eax
		ret
	}
}

jInteger __declspec(naked) GetPlayerStartLocation(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0fd0
		jmp eax
	}
}

jReal __declspec(naked) GetPlayerStartLocationX(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0ff0
		jmp eax
	}
}

jReal __declspec(naked) GetPlayerStartLocationY(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1020
		jmp eax
	}
}

HPLAYERCOLOR  __declspec(naked) GetPlayerColor(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1240
		jmp eax
	}
}

jBoolean __declspec(naked) GetPlayerSelectable(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1290
		jmp eax
	}
}

HMAPCONTROL  __declspec(naked) GetPlayerController(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c12b0
		jmp eax
	}
}

HPLAYERSLOTSTATE  __declspec(naked) GetPlayerSlotState(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c12d0
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerTaxRate(HPLAYER, HPLAYER, HPLAYERSTATE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1150
		jmp eax
	}
}

jBoolean __declspec(naked) IsPlayerRacePrefSet(HPLAYER, HRACEPREFERENCE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1260
		jmp eax
	}
}

HLOCATION  __declspec(naked) Location(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d03b0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveLocation(HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0dd0
		jmp eax
	}
}

jNothing __declspec(naked) MoveLocation(HLOCATION, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0df0
		jmp eax
	}
}

jReal __declspec(naked) GetLocationX(HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0e10
		jmp eax
	}
}

jReal __declspec(naked) GetLocationY(HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0e30
		jmp eax
	}
}

jReal __declspec(naked) GetLocationZ(HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0e50
		jmp eax
	}
}

HTIMER  __declspec(naked) CreateTimer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0500
		jmp eax
	}
}

jNothing __declspec(naked) DestroyTimer(HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1350
		jmp eax
	}
}

jNothing __declspec(naked) TimerStart(HTIMER, jReal*, jBoolean, jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1370
		jmp eax
	}
}

jReal __declspec(naked) TimerGetTimeout(HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c13e0
		jmp eax
	}
}

jReal __declspec(naked) TimerGetElapsed(HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c13a0
		jmp eax
	}
}

jReal __declspec(naked) TimerGetRemaining(HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c13c0
		jmp eax
	}
}

jNothing __declspec(naked) PauseTimer(HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1400
		jmp eax
	}
}

jNothing __declspec(naked) ResumeTimer(HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1420
		jmp eax
	}
}

HTIMER  __declspec(naked) GetExpiredTimer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1d80
		jmp eax
	}
}

HCONDITIONFUNC  __declspec(naked) Condition(jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb0a0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyCondition(HCONDITIONFUNC)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1440
		jmp eax
	}
}

HFILTERFUNC  __declspec(naked) Filter(jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb140
		jmp eax
	}
}

jNothing __declspec(naked) DestroyFilter(HFILTERFUNC)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1470
		jmp eax
	}
}

jNothing __declspec(naked) DestroyBoolExpr(HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c14a0
		jmp eax
	}
}

HBOOLEXPR  __declspec(naked) And(HBOOLEXPR, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d05f0
		jmp eax
	}
}

HBOOLEXPR  __declspec(naked) Or(HBOOLEXPR, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0710
		jmp eax
	}
}

HBOOLEXPR  __declspec(naked) Not(HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0830
		jmp eax
	}
}

HREGION  __declspec(naked) CreateRegion()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0930
		jmp eax
	}
}

jNothing __declspec(naked) RemoveRegion(HREGION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c14c0
		jmp eax
	}
}

jNothing __declspec(naked) RegionAddRect(HREGION, HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c14e0
		jmp eax
	}
}

jNothing __declspec(naked) RegionClearRect(HREGION, HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1530
		jmp eax
	}
}

jNothing __declspec(naked) RegionAddCell(HREGION, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1580
		jmp eax
	}
}

jNothing __declspec(naked) RegionAddCellAtLoc(HREGION, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c15b0
		jmp eax
	}
}

jNothing __declspec(naked) RegionClearCell(HREGION, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c15f0
		jmp eax
	}
}

jNothing __declspec(naked) RegionClearCellAtLoc(HREGION, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1620
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInRegion(HREGION, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1660
		jmp eax
	}
}

jBoolean __declspec(naked) IsPointInRegion(HREGION, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1690
		jmp eax
	}
}

jBoolean __declspec(naked) IsLocationInRegion(HREGION, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c16b0
		jmp eax
	}
}

HRECT  __declspec(naked) Rect(jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0a20
		jmp eax
	}
}

HRECT  __declspec(naked) RectFromLoc(HLOCATION, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0bd0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveRect(HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c16f0
		jmp eax
	}
}

jNothing __declspec(naked) SetRect(HRECT, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1710
		jmp eax
	}
}

jNothing __declspec(naked) SetRectFromLoc(HRECT, HLOCATION, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c17f0
		jmp eax
	}
}

jReal __declspec(naked) GetRectCenterX(HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c18e0
		jmp eax
	}
}

jReal __declspec(naked) GetRectCenterY(HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1910
		jmp eax
	}
}

jNothing __declspec(naked) MoveRectTo(HRECT, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c19c0
		jmp eax
	}
}

jNothing __declspec(naked) MoveRectToLoc(HRECT, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c19f0
		jmp eax
	}
}

jReal __declspec(naked) GetRectMinX(HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1940
		jmp eax
	}
}

jReal __declspec(naked) GetRectMinY(HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1960
		jmp eax
	}
}

jReal __declspec(naked) GetRectMaxX(HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1980
		jmp eax
	}
}

jReal __declspec(naked) GetRectMaxY(HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c19a0
		jmp eax
	}
}

HRECT  __declspec(naked) GetWorldBounds()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0d60
		jmp eax
	}
}

jNothing __declspec(naked) SetFogStateRect(HPLAYER, HFOGSTATE, HRECT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1a30
		jmp eax
	}
}

jNothing __declspec(naked) SetFogStateRadius(HPLAYER, HFOGSTATE, jReal*, jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1ab0
		jmp eax
	}
}

jNothing __declspec(naked) SetFogStateRadiusLoc(HPLAYER, HFOGSTATE, HLOCATION, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1b20
		jmp eax
	}
}

jNothing __declspec(naked) FogMaskEnable(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb210
		jmp eax
	}
}

jBoolean __declspec(naked) IsFogMaskEnabled()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb230
		jmp eax
	}
}

jNothing __declspec(naked) FogEnable(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb1e0
		jmp eax
	}
}

jBoolean __declspec(naked) IsFogEnabled()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb200
		jmp eax
	}
}

HFOGMODIFIER  __declspec(naked) CreateFogModifierRect(HPLAYER, HFOGSTATE, HRECT, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0e70
		jmp eax
	}
}

HFOGMODIFIER  __declspec(naked) CreateFogModifierRadius(HPLAYER, HFOGSTATE, jReal*, jReal*, jReal*, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0f90
		jmp eax
	}
}

HFOGMODIFIER  __declspec(naked) CreateFogModifierRadiusLoc(HPLAYER, HFOGSTATE, HLOCATION, jReal*, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d10f0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyFogModifier(HFOGMODIFIER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1ba0
		jmp eax
	}
}

jNothing __declspec(naked) FogModifierStart(HFOGMODIFIER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1bc0
		jmp eax
	}
}

jNothing __declspec(naked) FogModifierStop(HFOGMODIFIER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1be0
		jmp eax
	}
}

jTrigger __declspec(naked) CreateTrigger()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d11f0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyTrigger(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1c00
		jmp eax
	}
}

jNothing __declspec(naked) ResetTrigger(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1c20
		jmp eax
	}
}

jNothing __declspec(naked) EnableTrigger(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1c40
		jmp eax
	}
}

jNothing __declspec(naked) DisableTrigger(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1c60
		jmp eax
	}
}

jBoolean __declspec(naked) IsTriggerEnabled(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1c80
		jmp eax
	}
}

jNothing __declspec(naked) TriggerWaitOnSleeps(jTrigger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1ca0
		jmp eax
	}
}

jBoolean __declspec(naked) IsTriggerWaitOnSleeps(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1cc0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterVariableEvent(jTrigger, jString, HLIMITOP, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d12e0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterTimerEvent(jTrigger, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1420
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterTimerExpireEvent(jTrigger, HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1550
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterGameStateEvent(jTrigger, HGAMESTATE, HLIMITOP, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1630
		jmp eax
	}
}

HGAMESTATE  __declspec(naked) GetEventGameState()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2020
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterDialogEvent(jTrigger, HDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d17a0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterDialogButtonEvent(jTrigger, HBUTTON)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1880
		jmp eax
	}
}

HBUTTON  __declspec(naked) GetClickedButton()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1de0
		jmp eax
	}
}

HDIALOG  __declspec(naked) GetClickedDialog()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1e30
		jmp eax
	}
}

jReal  __declspec(naked) GetTournamentFinishSoonTimeRemaining()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1ea0
		jmp eax
	}
}

jInteger  __declspec(naked) GetTournamentFinishNowRule()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1ed0
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetTournamentFinishNowPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1f00
		jmp eax
	}
}

jInteger __declspec(naked) GetTournamentScore(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1f60
		jmp eax
	}
}

jString __declspec(naked) GetSaveBasicFilename()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1f80
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterGameEvent(jTrigger, HGAMEEVENT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1960
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetWinningPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb3e0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterPlayerStateEvent(jTrigger, HPLAYER, HPLAYERSTATE, HLIMITOP, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1a60
		jmp eax
	}
}

HPLAYERSTATE  __declspec(naked) GetEventPlayerState()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2050
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterPlayerEvent(jTrigger, HPLAYER, HPLAYEREVENT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1c90
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterPlayerUnitEvent(jTrigger, HPLAYER, HPLAYERUNITEVENT, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1dd0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetAttacker()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c20f0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetRescuer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2390
		jmp eax
	}
}

HUNIT  __declspec(naked) GetDyingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb410
		jmp eax
	}
}

HUNIT  __declspec(naked) GetKillingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c23f0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetDecayingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb430
		jmp eax
	}
}

HUNIT  __declspec(naked) GetConstructingStructure()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb450
		jmp eax
	}
}

HUNIT  __declspec(naked) GetCancelledStructure()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb470
		jmp eax
	}
}

HUNIT  __declspec(naked) GetConstructedStructure()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb490
		jmp eax
	}
}

jInteger __declspec(naked) GetTrainedUnitType()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2450
		jmp eax
	}
}

HUNIT  __declspec(naked) GetResearchingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb4d0
		jmp eax
	}
}

jInteger __declspec(naked) GetResearched()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2870
		jmp eax
	}
}

HUNIT  __declspec(naked) GetTrainedUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2500
		jmp eax
	}
}

HUNIT  __declspec(naked) GetSellingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2560
		jmp eax
	}
}

HUNIT  __declspec(naked) GetSoldUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2750
		jmp eax
	}
}

HUNIT  __declspec(naked) GetBuyingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c27b0
		jmp eax
	}
}

HITEM  __declspec(naked) GetSoldItem()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c25f0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetChangingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2680
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetChangingUnitPrevOwner()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c26e0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetDetectedUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb4b0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetOrderedUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb530
		jmp eax
	}
}

jInteger __declspec(naked) OrderId(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb590
		jmp eax
	}
}

jString __declspec(naked) OrderId2String(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb5c0
		jmp eax
	}
}

jInteger __declspec(naked) AbilityId(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb5f0
		jmp eax
	}
}

jString __declspec(naked) AbilityId2String(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb620
		jmp eax
	}
}

jInteger __declspec(naked) UnitId(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb650
		jmp eax
	}
}

jString __declspec(naked) UnitId2String(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb680
		jmp eax
	}
}

jString __declspec(naked) GetObjectName(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb6b0
		jmp eax
	}
}

jInteger __declspec(naked) GetIssuedOrderId()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2c80
		jmp eax
	}
}

jReal __declspec(naked) GetOrderPointX()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2d00
		jmp eax
	}
}

jReal __declspec(naked) GetOrderPointY()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2d50
		jmp eax
	}
}

HLOCATION  __declspec(naked) GetOrderPointLoc()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1ff0
		jmp eax
	}
}

HWIDGET  __declspec(naked) GetOrderTarget()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2de0
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) GetOrderTargetDestructable()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2f10
		jmp eax
	}
}

HITEM  __declspec(naked) GetOrderTargetItem()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3040
		jmp eax
	}
}

HUNIT  __declspec(naked) GetOrderTargetUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3170
		jmp eax
	}
}

HUNIT  __declspec(naked) GetSpellAbilityUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3470
		jmp eax
	}
}

jInteger __declspec(naked) GetSpellAbilityId()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c32a0
		jmp eax
	}
}

HABILITY  __declspec(naked) GetSpellAbility()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3380
		jmp eax
	}
}

HLOCATION  __declspec(naked) GetSpellTargetLoc()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2090
		jmp eax
	}
}

jReal __declspec(naked) GetSpellTargetX()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3580
		jmp eax
	}
}

jReal __declspec(naked) GetSpellTargetY()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3670
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) GetSpellTargetDestructable()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3760
		jmp eax
	}
}

HITEM  __declspec(naked) GetSpellTargetItem()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c38f0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetSpellTargetUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3a80
		jmp eax
	}
}

HUNIT  __declspec(naked) GetLevelingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2150
		jmp eax
	}
}

HUNIT  __declspec(naked) GetLearningUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c21b0
		jmp eax
	}
}

jInteger __declspec(naked) GetLearnedSkill()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2210
		jmp eax
	}
}

jInteger __declspec(naked) GetLearnedSkillLevel()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2250
		jmp eax
	}
}

HUNIT  __declspec(naked) GetRevivableUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2290
		jmp eax
	}
}

HUNIT  __declspec(naked) GetRevivingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c22f0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetSummoningUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c28f0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetSummonedUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2950
		jmp eax
	}
}

HUNIT  __declspec(naked) GetTransportUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c29a0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetLoadedUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2a00
		jmp eax
	}
}

HUNIT  __declspec(naked) GetManipulatingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2a60
		jmp eax
	}
}

HITEM  __declspec(naked) GetManipulatedItem()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2b00
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterPlayerAllianceChange(jTrigger, HPLAYER, HALLIANCETYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1ba0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterPlayerChatEvent(jTrigger, HPLAYER, jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1ef0
		jmp eax
	}
}

jString __declspec(naked) GetEventPlayerChatString()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c20b0
		jmp eax
	}
}

jString __declspec(naked) GetEventPlayerChatStringMatched()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c2080
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterUnitStateEvent(jTrigger, HUNIT, HUNITSTATE, HLIMITOP, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d21b0
		jmp eax
	}
}

HUNITSTATE  __declspec(naked) GetEventUnitState()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3c10
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterDeathEvent(jTrigger, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d22c0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterUnitEvent(jTrigger, HUNIT, HUNITEVENT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d23b0
		jmp eax
	}
}

jReal __declspec(naked) GetEventDamage()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3c40
		jmp eax
	}
}

HUNIT  __declspec(naked) GetEventDamageSource()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3c60
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetEventDetectingPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3cb0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetEventTargetUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3d00
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterFilterUnitEvent(jTrigger, HUNIT, HUNITEVENT, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d24d0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterUnitInRange(jTrigger, HUNIT, jReal*, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d25f0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterEnterRegion(jTrigger, HREGION, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2700
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterLeaveRegion(jTrigger, HREGION, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2800
		jmp eax
	}
}

HREGION  __declspec(naked) GetTriggeringRegion()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3d50
		jmp eax
	}
}

HUNIT  __declspec(naked) GetEnteringUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb6d0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetLeavingUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb6f0
		jmp eax
	}
}

HTRIGGERCONDITION  __declspec(naked) TriggerAddCondition(jTrigger, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3df0
		jmp eax
	}
}

jNothing __declspec(naked) TriggerRemoveCondition(jTrigger, HTRIGGERCONDITION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3e40
		jmp eax
	}
}

jNothing __declspec(naked) TriggerClearConditions(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3e70
		jmp eax
	}
}

HTRIGGERACTION __declspec(naked) TriggerAddAction(jTrigger, jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3e90
		jmp eax
	}
}

jNothing __declspec(naked) TriggerRemoveAction(jTrigger, HTRIGGERACTION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3ed0
		jmp eax
	}
}

jNothing __declspec(naked) TriggerClearActions(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3f00
		jmp eax
	}
}

jNothing __declspec(naked) TriggerSleepAction(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2db0
		jmp eax
	}
}

jNothing __declspec(naked) TriggerWaitForSound(HSOUND, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3f20
		jmp eax
	}
}

jNothing __declspec(naked) TriggerExecute(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3f40
		jmp eax
	}
}

jNothing __declspec(naked) TriggerExecuteWait(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3f60
		jmp eax
	}
}

jBoolean __declspec(naked) TriggerEvaluate(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3f80
		jmp eax
	}
}

jNothing __declspec(naked) TriggerSyncStart()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2dc0
		jmp eax
	}
}

jNothing __declspec(naked) TriggerSyncReady()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb710
		jmp eax
	}
}

HWIDGET  __declspec(naked) GetTriggerWidget()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb260
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) GetTriggerDestructable()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1d20
		jmp eax
	}
}

HUNIT  __declspec(naked) GetTriggerUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb240
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetTriggerPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb280
		jmp eax
	}
}

jTrigger  __declspec(naked) GetTriggeringTrigger()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb2a0
		jmp eax
	}
}

HEVENTID  __declspec(naked) GetTriggerEventId()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb2c0
		jmp eax
	}
}

jInteger __declspec(naked) GetTriggerEvalCount(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1ce0
		jmp eax
	}
}

jInteger __declspec(naked) GetTriggerExecCount(jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1d00
		jmp eax
	}
}

HUNIT  __declspec(naked) GetFilterUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb2e0
		jmp eax
	}
}

HUNIT  __declspec(naked) GetEnumUnit()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb300
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetEnumPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb320
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetFilterPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb340
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) GetFilterDestructable()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb380
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) GetEnumDestructable()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb360
		jmp eax
	}
}

HITEM  __declspec(naked) GetFilterItem()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb3c0
		jmp eax
	}
}

HITEM  __declspec(naked) GetEnumItem()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb3a0
		jmp eax
	}
}

HGROUP  __declspec(naked) CreateGroup()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2900
		jmp eax
	}
}

jNothing __declspec(naked) DestroyGroup(HGROUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3fa0
		jmp eax
	}
}

jNothing __declspec(naked) GroupAddUnit(HGROUP, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3fc0
		jmp eax
	}
}

jNothing __declspec(naked) GroupRemoveUnit(HGROUP, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3ff0
		jmp eax
	}
}

jNothing __declspec(naked) GroupClear(HGROUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4020
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsOfType(HGROUP, jString, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4040
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsOfTypeCounted(HGROUP, jString, HBOOLEXPR, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4090
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsInRect(HGROUP, HRECT, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c40e0
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsInRectCounted(HGROUP, HRECT, HBOOLEXPR, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4140
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsOfPlayer(HGROUP, HPLAYER, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c42c0
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsInRange(HGROUP, jReal*, jReal*, jReal*, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c41a0
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsInRangeOfLoc(HGROUP, HLOCATION, jReal*, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c41e0
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsInRangeCounted(HGROUP, jReal*, jReal*, jReal*, HBOOLEXPR, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4230
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsInRangeOfLocCounted(HGROUP, HLOCATION, jReal*, HBOOLEXPR, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4270
		jmp eax
	}
}

jNothing __declspec(naked) GroupEnumUnitsSelected(HGROUP, HPLAYER, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce590
		jmp eax
	}
}

jBoolean __declspec(naked) GroupImmediateOrder(HGROUP, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4320
		jmp eax
	}
}

jBoolean __declspec(naked) GroupImmediateOrderById(HGROUP, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4300
		jmp eax
	}
}

jBoolean __declspec(naked) GroupPointOrder(HGROUP, jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4370
		jmp eax
	}
}

jBoolean __declspec(naked) GroupPointOrderLoc(HGROUP, jString, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c43e0
		jmp eax
	}
}

jBoolean __declspec(naked) GroupPointOrderById(HGROUP, jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4340
		jmp eax
	}
}

jBoolean __declspec(naked) GroupPointOrderByIdLoc(HGROUP, jInteger, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4390
		jmp eax
	}
}

jBoolean __declspec(naked) GroupTargetOrder(HGROUP, jString, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4440
		jmp eax
	}
}

jBoolean __declspec(naked) GroupTargetOrderById(HGROUP, jInteger, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4400
		jmp eax
	}
}

jNothing __declspec(naked) ForGroup(HGROUP, jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c44a0
		jmp eax
	}
}

HUNIT  __declspec(naked) FirstOfGroup(HGROUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4460
		jmp eax
	}
}

HFORCE  __declspec(naked) CreateForce()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d29f0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyForce(HFORCE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c44c0
		jmp eax
	}
}

jNothing __declspec(naked) ForceAddPlayer(HFORCE, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c44e0
		jmp eax
	}
}

jNothing __declspec(naked) ForceRemovePlayer(HFORCE, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4510
		jmp eax
	}
}

jNothing __declspec(naked) ForceClear(HFORCE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4540
		jmp eax
	}
}

jNothing __declspec(naked) ForceEnumPlayers(HFORCE, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4560
		jmp eax
	}
}

jNothing __declspec(naked) ForceEnumPlayersCounted(HFORCE, HBOOLEXPR, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4590
		jmp eax
	}
}

jNothing __declspec(naked) ForceEnumAllies(HFORCE, HPLAYER, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c45c0
		jmp eax
	}
}

jNothing __declspec(naked) ForceEnumEnemies(HFORCE, HPLAYER, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4600
		jmp eax
	}
}

jNothing __declspec(naked) ForForce(HFORCE, jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4640
		jmp eax
	}
}

jReal __declspec(naked) GetWidgetLife(HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4660
		jmp eax
	}
}

jNothing __declspec(naked) SetWidgetLife(HWIDGET, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4690
		jmp eax
	}
}

jReal __declspec(naked) GetWidgetX(HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c46b0
		jmp eax
	}
}

jReal __declspec(naked) GetWidgetY(HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c46f0
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) CreateDestructable(jInteger, jReal*, jReal*, jReal*, jReal*, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb790
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) CreateDestructableZ(jInteger, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb7e0
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) CreateDeadDestructable(jInteger, jReal*, jReal*, jReal*, jReal*, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb840
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) CreateDeadDestructableZ(jInteger, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb890
		jmp eax
	}
}

jNothing __declspec(naked) RemoveDestructable(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4730
		jmp eax
	}
}

jNothing __declspec(naked) KillDestructable(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4750
		jmp eax
	}
}

jNothing __declspec(naked) SetDestructableInvulnerable(HDESTRUCTABLE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4770
		jmp eax
	}
}

jBoolean __declspec(naked) IsDestructableInvulnerable(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4790
		jmp eax
	}
}

jNothing __declspec(naked) EnumDestructablesInRect(HRECT, HBOOLEXPR, jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4a90
		jmp eax
	}
}

jInteger __declspec(naked) GetDestructableTypeId(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c47b0
		jmp eax
	}
}

jReal __declspec(naked) GetDestructableX(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c47d0
		jmp eax
	}
}

jReal __declspec(naked) GetDestructableY(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4810
		jmp eax
	}
}

jNothing __declspec(naked) SetDestructableLife(HDESTRUCTABLE, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4850
		jmp eax
	}
}

jReal __declspec(naked) GetDestructableLife(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4890
		jmp eax
	}
}

jNothing __declspec(naked) SetDestructableMaxLife(HDESTRUCTABLE, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c48d0
		jmp eax
	}
}

jReal __declspec(naked) GetDestructableMaxLife(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4920
		jmp eax
	}
}

jNothing __declspec(naked) DestructableRestoreLife(HDESTRUCTABLE, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4870
		jmp eax
	}
}

jNothing __declspec(naked) QueueDestructableAnimation(HDESTRUCTABLE, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4a00
		jmp eax
	}
}

jNothing __declspec(naked) SetDestructableAnimation(HDESTRUCTABLE, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4a20
		jmp eax
	}
}

jNothing __declspec(naked) SetDestructableAnimationSpeed(HDESTRUCTABLE, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4a40
		jmp eax
	}
}

jNothing __declspec(naked) ShowDestructable(HDESTRUCTABLE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4a60
		jmp eax
	}
}

jReal __declspec(naked) GetDestructableOccluderHeight(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4bb0
		jmp eax
	}
}

jNothing __declspec(naked) SetDestructableOccluderHeight(HDESTRUCTABLE, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4bd0
		jmp eax
	}
}

jString __declspec(naked) GetDestructableName(HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4c10
		jmp eax
	}
}

HUNIT  __declspec(naked) CreateUnit(HPLAYER, jInteger, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5230
		jmp eax
	}
}

HUNIT  __declspec(naked) CreateUnitByName(HPLAYER, jString, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c52a0
		jmp eax
	}
}

HUNIT  __declspec(naked) CreateUnitAtLoc(HPLAYER, jInteger, HLOCATION, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c52d0
		jmp eax
	}
}

HUNIT  __declspec(naked) CreateUnitAtLocByName(HPLAYER, jString, HLOCATION, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5320
		jmp eax
	}
}

HUNIT  __declspec(naked) CreateCorpse(HPLAYER, jInteger, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5350
		jmp eax
	}
}

jReal __declspec(naked) GetUnitState(HUNIT, HUNITSTATE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5400
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitFoodUsed(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5440
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitFoodMade(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5460
		jmp eax
	}
}

jInteger __declspec(naked) GetFoodMade(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2e00
		jmp eax
	}
}

jInteger __declspec(naked) GetFoodUsed(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2e10
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitUseFood(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c54a0
		jmp eax
	}
}

jReal __declspec(naked) GetUnitX(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5510
		jmp eax
	}
}

jReal __declspec(naked) GetUnitY(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5550
		jmp eax
	}
}

HLOCATION  __declspec(naked) GetUnitLoc(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2ae0
		jmp eax
	}
}

HLOCATION  __declspec(naked) GetUnitRallyPoint(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2b40
		jmp eax
	}
}

HUNIT  __declspec(naked) GetUnitRallyUnit(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5590
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) GetUnitRallyDestructable(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5690
		jmp eax
	}
}

jReal __declspec(naked) GetUnitFacing(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5790
		jmp eax
	}
}

jReal __declspec(naked) GetUnitMoveSpeed(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5810
		jmp eax
	}
}

jReal __declspec(naked) GetUnitDefaultMoveSpeed(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5870
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitTypeId(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5910
		jmp eax
	}
}

HRACE  __declspec(naked) GetUnitRace(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5930
		jmp eax
	}
}

jString __declspec(naked) GetUnitName(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5950
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitPointValue(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5e80
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitPointValueByType(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2e20
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitX(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5970
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitY(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c59e0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitPosition(HUNIT, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5a50
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitPositionLoc(HUNIT, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5ab0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitFacing(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5af0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitFacingTimed(HUNIT, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5b30
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitFlyHeight(HUNIT, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5c60
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitMoveSpeed(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5c40
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitTurnSpeed(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5cb0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitPropWindow(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5cd0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitCreepGuard(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5480
		jmp eax
	}
}

jReal __declspec(naked) GetUnitAcquireRange(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5d10
		jmp eax
	}
}

jReal __declspec(naked) GetUnitTurnSpeed(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5d40
		jmp eax
	}
}

jReal __declspec(naked) GetUnitPropWindow(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5d70
		jmp eax
	}
}

jReal __declspec(naked) GetUnitFlyHeight(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5da0
		jmp eax
	}
}

jReal __declspec(naked) GetUnitDefaultAcquireRange(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5dc0
		jmp eax
	}
}

jReal __declspec(naked) GetUnitDefaultTurnSpeed(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5df0
		jmp eax
	}
}

jReal __declspec(naked) GetUnitDefaultPropWindow(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5e20
		jmp eax
	}
}

jReal __declspec(naked) GetUnitDefaultFlyHeight(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5e50
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitAcquireRange(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5cf0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitState(HUNIT, HUNITSTATE, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5ea0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitOwner(HUNIT, HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5ed0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitRescuable(HUNIT, HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5f10
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitRescueRange(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5f40
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitColor(HUNIT, HPLAYERCOLOR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5f60
		jmp eax
	}
}

jNothing __declspec(naked) QueueUnitAnimation(HUNIT, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6180
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitAnimation(HUNIT, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c61a0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitAnimationWithRarity(HUNIT, jString, HRARITYCONTROL)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c61c0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitAnimationByIndex(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c61f0
		jmp eax
	}
}

jNothing __declspec(naked) AddUnitAnimationProperties(HUNIT, jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6220
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitScale(HUNIT, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c62d0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitTimeScale(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6300
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitBlendTime(HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6320
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitVertexColor(HUNIT, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6340
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitLookAt(HUNIT, jString, HUNIT, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c64c0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitPathing(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5fa0
		jmp eax
	}
}

jNothing __declspec(naked) ResetUnitLookAt(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c65f0
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroStr(HUNIT, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6630
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroAgi(HUNIT, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c66a0
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroInt(HUNIT, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6710
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroStr(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c67e0
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroAgi(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6850
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroInt(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c68c0
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroSkillPoints(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6780
		jmp eax
	}
}

jBoolean __declspec(naked) UnitStripHeroLevel(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6930
		jmp eax
	}
}

jBoolean __declspec(naked) UnitModifySkillPoints(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c69a0
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroXP(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6a10
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroXP(HUNIT, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6a70
		jmp eax
	}
}

jNothing __declspec(naked) AddHeroXP(HUNIT, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6cf0
		jmp eax
	}
}

jNothing __declspec(naked) SetHeroLevel(HUNIT, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6d70
		jmp eax
	}
}

jInteger __declspec(naked) GetHeroLevel(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6ed0
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitLevel(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6f30
		jmp eax
	}
}

jString __declspec(naked) GetHeroProperName(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6fa0
		jmp eax
	}
}

jNothing __declspec(naked) SuspendHeroXP(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6e10
		jmp eax
	}
}

jBoolean __declspec(naked) IsSuspendedXP(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6e70
		jmp eax
	}
}

jNothing __declspec(naked) SelectHeroSkill(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7050
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitAbilityLevel(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7290
		jmp eax
	}
}

jBoolean __declspec(naked) ReviveHero(HUNIT, jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6af0
		jmp eax
	}
}

jBoolean __declspec(naked) ReviveHeroLoc(HUNIT, HLOCATION, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6b80
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitExploded(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce6d0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitInvulnerable(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c72f0
		jmp eax
	}
}

jNothing __declspec(naked) PauseUnit(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7340
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitPaused(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c73a0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitAddItem(HUNIT, HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c73f0
		jmp eax
	}
}

HITEM  __declspec(naked) UnitAddItemById(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c74f0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitAddItemToSlotById(HUNIT, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c75b0
		jmp eax
	}
}

jNothing __declspec(naked) UnitRemoveItem(HUNIT, HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7660
		jmp eax
	}
}

HITEM  __declspec(naked) UnitRemoveItemFromSlot(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c76a0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitHasItem(HUNIT, HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c76f0
		jmp eax
	}
}

HITEM  __declspec(naked) UnitItemInSlot(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7730
		jmp eax
	}
}

jInteger __declspec(naked) UnitInventorySize(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8f00
		jmp eax
	}
}

jBoolean __declspec(naked) UnitDropItemPoint(HUNIT, HITEM, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8f30
		jmp eax
	}
}

jBoolean __declspec(naked) UnitDropItemSlot(HUNIT, HITEM, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9010
		jmp eax
	}
}

jBoolean __declspec(naked) UnitDropItemTarget(HUNIT, HITEM, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8fa0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitUseItem(HUNIT, HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9090
		jmp eax
	}
}

jBoolean __declspec(naked) UnitUseItemPoint(HUNIT, HITEM, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9100
		jmp eax
	}
}

jBoolean __declspec(naked) UnitUseItemTarget(HUNIT, HITEM, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9170
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitCurrentOrder(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7780
		jmp eax
	}
}

jNothing __declspec(naked) SetResourceAmount(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c77f0
		jmp eax
	}
}

jNothing __declspec(naked) AddResourceAmount(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7850
		jmp eax
	}
}

jInteger __declspec(naked) GetResourceAmount(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c78b0
		jmp eax
	}
}

jNothing __declspec(naked) SelectUnit(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7910
		jmp eax
	}
}

jNothing __declspec(naked) ClearSelection()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbaa0
		jmp eax
	}
}

jNothing __declspec(naked) UnitAddIndicator(HUNIT, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6bd0
		jmp eax
	}
}

jNothing __declspec(naked) AddIndicator(HWIDGET, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c6c60
		jmp eax
	}
}

jNothing __declspec(naked) KillUnit(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8040
		jmp eax
	}
}

jNothing __declspec(naked) RemoveUnit(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8060
		jmp eax
	}
}

jNothing __declspec(naked) ShowUnit(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce730
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInForce(HUNIT, HFORCE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c79c0
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInGroup(HUNIT, HGROUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7a00
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitOwnedByPlayer(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7a30
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitAlly(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7a70
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitEnemy(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7ad0
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitVisible(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7af0
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitDetected(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7c80
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInvisible(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7cc0
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitFogged(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7d00
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitMasked(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7d80
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitSelected(HUNIT, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7e00
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitRace(HUNIT, HRACE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7e60
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitType(HUNIT, HUNITTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7e90
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnit(HUNIT, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8020
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInRange(HUNIT, HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8090
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInRangeXY(HUNIT, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c80e0
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInRangeLoc(HUNIT, HLOCATION, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8140
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitHidden(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7b30
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitIllusion(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7b50
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitInTransport(HUNIT, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7b70
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitLoaded(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7ba0
		jmp eax
	}
}

jBoolean __declspec(naked) IsHeroUnitId(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2e90
		jmp eax
	}
}

jBoolean __declspec(naked) IsUnitIdType(jInteger, HUNITTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b7f60
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetOwningPlayer(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8190
		jmp eax
	}
}

jNothing __declspec(naked) UnitShareVision(HUNIT, HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c81c0
		jmp eax
	}
}

jNothing __declspec(naked) UnitSuspendDecay(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c81f0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitAddType(HUNIT, HUNITTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7bc0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitRemoveType(HUNIT, HUNITTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7c20
		jmp eax
	}
}

jBoolean __declspec(naked) UnitAddAbility(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c82a0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitRemoveAbility(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8310
		jmp eax
	}
}

jBoolean __declspec(naked) UnitMakeAbilityPermanent(HUNIT, jBoolean, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8250
		jmp eax
	}
}

jBoolean __declspec(naked) UnitHasBuffsEx(HUNIT, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8360
		jmp eax
	}
}

jInteger __declspec(naked) UnitCountBuffsEx(HUNIT, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c83a0
		jmp eax
	}
}

jNothing __declspec(naked) UnitRemoveBuffs(HUNIT, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c83e0
		jmp eax
	}
}

jNothing __declspec(naked) UnitRemoveBuffsEx(HUNIT, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8410
		jmp eax
	}
}

jNothing __declspec(naked) UnitAddSleep(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8450
		jmp eax
	}
}

jBoolean __declspec(naked) UnitCanSleep(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c84a0
		jmp eax
	}
}

jNothing __declspec(naked) UnitAddSleepPerm(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c84d0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitCanSleepPerm(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8520
		jmp eax
	}
}

jBoolean __declspec(naked) UnitIsSleeping(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8550
		jmp eax
	}
}

jNothing __declspec(naked) UnitWakeUp(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8590
		jmp eax
	}
}

jNothing __declspec(naked) UnitApplyTimedLife(HUNIT, jInteger, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c85d0
		jmp eax
	}
}

jBoolean __declspec(naked) UnitIgnoreAlarm(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8640
		jmp eax
	}
}

jBoolean __declspec(naked) UnitIgnoreAlarmToggled(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8690
		jmp eax
	}
}

jBoolean __declspec(naked) UnitDamagePoint(HUNIT, jReal*, jReal*, jReal*, jReal*, jReal*, jBoolean, jBoolean, HATTACKTYPE, HDAMAGETYPE, HWEAPONTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8770
		jmp eax
	}
}

jBoolean __declspec(naked) UnitDamageTarget(HUNIT, HWIDGET, jReal*, jBoolean, jBoolean, HATTACKTYPE, HDAMAGETYPE, HWEAPONTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8850
		jmp eax
	}
}

jInteger __declspec(naked) DecUnitAbilityLevel(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c70b0
		jmp eax
	}
}

jInteger __declspec(naked) IncUnitAbilityLevel(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c7130
		jmp eax
	}
}

jInteger __declspec(naked) SetUnitAbilityLevel(HUNIT, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c71b0
		jmp eax
	}
}

jNothing __declspec(naked) UnitResetCooldown(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c86d0
		jmp eax
	}
}

jNothing __declspec(naked) UnitSetConstructionProgress(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c86f0
		jmp eax
	}
}

jNothing __declspec(naked) UnitSetUpgradeProgress(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8720
		jmp eax
	}
}

jNothing __declspec(naked) UnitPauseTimedLife(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8750
		jmp eax
	}
}

jNothing __declspec(naked) UnitSetUsesAltIcon(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb860
		jmp eax
	}
}

jBoolean __declspec(naked) IssueImmediateOrderById(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8900
		jmp eax
	}
}

jBoolean __declspec(naked) IssuePointOrderById(HUNIT, jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8940
		jmp eax
	}
}

jBoolean __declspec(naked) IssuePointOrderByIdLoc(HUNIT, jInteger, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8980
		jmp eax
	}
}

jBoolean __declspec(naked) IssueTargetOrderById(HUNIT, jInteger, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c89d0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueInstantPointOrderById(HUNIT, jInteger, jReal*, jReal*, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8a20
		jmp eax
	}
}

jBoolean __declspec(naked) IssueInstantTargetOrderById(HUNIT, jInteger, HWIDGET, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8ab0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueBuildOrderById(HUNIT, jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8be0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueNeutralImmediateOrderById(HPLAYER, HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8ca0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueNeutralPointOrderById(HPLAYER, HUNIT, jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8ce0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueNeutralTargetOrderById(HPLAYER, HUNIT, jInteger, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8d30
		jmp eax
	}
}

jBoolean __declspec(naked) IssueImmediateOrder(HUNIT, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8d80
		jmp eax
	}
}

jBoolean __declspec(naked) IssuePointOrder(HUNIT, jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8da0
		jmp eax
	}
}

jBoolean __declspec(naked) IssuePointOrderLoc(HUNIT, jString, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8dc0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueTargetOrder(HUNIT, jString, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8e20
		jmp eax
	}
}

jBoolean __declspec(naked) IssueInstantPointOrder(HUNIT, jString, jReal*, jReal*, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8e40
		jmp eax
	}
}

jBoolean __declspec(naked) IssueInstantTargetOrder(HUNIT, jString, HWIDGET, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8e60
		jmp eax
	}
}

jBoolean __declspec(naked) IssueBuildOrder(HUNIT, jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8e80
		jmp eax
	}
}

jBoolean __declspec(naked) IssueNeutralImmediateOrder(HPLAYER, HUNIT, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8ea0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueNeutralPointOrder(HPLAYER, HUNIT, jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8ec0
		jmp eax
	}
}

jBoolean __declspec(naked) IssueNeutralTargetOrder(HPLAYER, HUNIT, jString, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c8ee0
		jmp eax
	}
}

jReal __declspec(naked) WaygateGetDestinationX(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c91f0
		jmp eax
	}
}

jReal __declspec(naked) WaygateGetDestinationY(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9240
		jmp eax
	}
}

jNothing __declspec(naked) WaygateSetDestination(HUNIT, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9290
		jmp eax
	}
}

jNothing __declspec(naked) WaygateActivate(HUNIT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c92d0
		jmp eax
	}
}

jBoolean __declspec(naked) WaygateIsActive(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9310
		jmp eax
	}
}

jNothing __declspec(naked) AddItemToAllStock(jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3270
		jmp eax
	}
}

jNothing __declspec(naked) AddItemToStock(HUNIT, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9350
		jmp eax
	}
}

jNothing __declspec(naked) AddUnitToAllStock(jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3290
		jmp eax
	}
}

jNothing __declspec(naked) AddUnitToStock(HUNIT, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c93a0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveItemFromAllStock(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b32b0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveItemFromStock(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c93f0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveUnitFromAllStock(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b32c0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveUnitFromStock(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9430
		jmp eax
	}
}

jNothing __declspec(naked) SetAllItemTypeSlots(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b32d0
		jmp eax
	}
}

jNothing __declspec(naked) SetAllUnitTypeSlots(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b32e0
		jmp eax
	}
}

jNothing __declspec(naked) SetItemTypeSlots(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9470
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitTypeSlots(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c94b0
		jmp eax
	}
}

jInteger __declspec(naked) GetUnitUserData(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c94f0
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitUserData(HUNIT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9510
		jmp eax
	}
}

HITEM  __declspec(naked) CreateItem(jInteger, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb9a0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveItem(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4c30
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetItemPlayer(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4e10
		jmp eax
	}
}

jInteger __declspec(naked) GetItemTypeId(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4c60
		jmp eax
	}
}

jReal __declspec(naked) GetItemX(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4d90
		jmp eax
	}
}

jReal __declspec(naked) GetItemY(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4dd0
		jmp eax
	}
}

jNothing __declspec(naked) SetItemPosition(HITEM, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4c80
		jmp eax
	}
}

jNothing __declspec(naked) SetItemDropOnDeath(HITEM, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4d00
		jmp eax
	}
}

jNothing __declspec(naked) SetItemDroppable(HITEM, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4d30
		jmp eax
	}
}

jNothing __declspec(naked) SetItemPawnable(HITEM, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4d60
		jmp eax
	}
}

jNothing __declspec(naked) SetItemPlayer(HITEM, HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4eb0
		jmp eax
	}
}

jNothing __declspec(naked) SetItemInvulnerable(HITEM, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4ee0
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemInvulnerable(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4f00
		jmp eax
	}
}

jInteger __declspec(naked) GetItemLevel(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4e50
		jmp eax
	}
}

HITEMTYPE  __declspec(naked) GetItemType(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4e70
		jmp eax
	}
}

jNothing __declspec(naked) SetItemVisible(HITEM, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4f20
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemVisible(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4f70
		jmp eax
	}
}

jNothing __declspec(naked) EnumItemsInRect(HRECT, HBOOLEXPR, jCode)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5110
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemOwned(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4f90
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemPowerup(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4fd0
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemSellable(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4ff0
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemPawnable(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5010
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemIdPowerup(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2dd0
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemIdSellable(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2de0
		jmp eax
	}
}

jBoolean __declspec(naked) IsItemIdPawnable(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b2df0
		jmp eax
	}
}

jNothing __declspec(naked) SetItemDropID(HITEM, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5030
		jmp eax
	}
}

jString __declspec(naked) GetItemName(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c4e90
		jmp eax
	}
}

jInteger __declspec(naked) GetItemCharges(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5050
		jmp eax
	}
}

jNothing __declspec(naked) SetItemCharges(HITEM, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5070
		jmp eax
	}
}

jInteger __declspec(naked) GetItemUserData(HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c50d0
		jmp eax
	}
}

jNothing __declspec(naked) SetItemUserData(HITEM, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c50f0
		jmp eax
	}
}

HPLAYER  __declspec(naked) Player(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbb30
		jmp eax
	}
}

HPLAYER  __declspec(naked) GetLocalPlayer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbb60
		jmp eax
	}
}

jBoolean __declspec(naked) IsPlayerAlly(HPLAYER, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9530
		jmp eax
	}
}

jBoolean __declspec(naked) IsPlayerEnemy(HPLAYER, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9580
		jmp eax
	}
}

jBoolean __declspec(naked) IsPlayerInForce(HPLAYER, HFORCE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c95d0
		jmp eax
	}
}

jBoolean __declspec(naked) IsPlayerObserver(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9600
		jmp eax
	}
}

HRACE  __declspec(naked) GetPlayerRace(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9620
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerId(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9640
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerTechMaxAllowed(HPLAYER, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9660
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerTechMaxAllowed(HPLAYER, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9690
		jmp eax
	}
}

jNothing __declspec(naked) AddPlayerTechResearched(HPLAYER, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c96d0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerTechResearched(HPLAYER, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9730
		jmp eax
	}
}

jBoolean __declspec(naked) GetPlayerTechResearched(HPLAYER, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9770
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerTechCount(HPLAYER, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c97a0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerAbilityAvailable(HPLAYER, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c97d0
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerUnitCount(HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9820
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerTypedUnitCount(HPLAYER, jString, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9850
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerStructureCount(HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c98c0
		jmp eax
	}
}

jBoolean __declspec(naked) IsVisibleToPlayer(jReal*, jReal*, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c98f0
		jmp eax
	}
}

jBoolean __declspec(naked) IsLocationVisibleToPlayer(HLOCATION, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9940
		jmp eax
	}
}

jBoolean __declspec(naked) IsFoggedToPlayer(jReal*, jReal*, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9980
		jmp eax
	}
}

jBoolean __declspec(naked) IsLocationFoggedToPlayer(HLOCATION, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c99d0
		jmp eax
	}
}

jBoolean __declspec(naked) IsMaskedToPlayer(jReal*, jReal*, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9a10
		jmp eax
	}
}

jBoolean __declspec(naked) IsLocationMaskedToPlayer(HLOCATION, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9a60
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerState(HPLAYER, HPLAYERSTATE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9aa0
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerState(HPLAYER, HPLAYERSTATE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9b00
		jmp eax
	}
}

jInteger __declspec(naked) GetPlayerScore(HPLAYER, HPLAYERSCORE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9b70
		jmp eax
	}
}

jBoolean __declspec(naked) GetPlayerAlliance(HPLAYER, HPLAYER, HALLIANCETYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9d70
		jmp eax
	}
}

jNothing __declspec(naked) RemovePlayer(HPLAYER, HPLAYERGAMERESULT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9dc0
		jmp eax
	}
}

jNothing __declspec(naked) CachePlayerHeroData(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9de0
		jmp eax
	}
}

jReal __declspec(naked) GetPlayerHandicap(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9e10
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerHandicap(HPLAYER, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9e30
		jmp eax
	}
}

jReal __declspec(naked) GetPlayerHandicapXP(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9ec0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerHandicapXP(HPLAYER, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9ee0
		jmp eax
	}
}

jNothing __declspec(naked) SetPlayerUnitsOwner(HPLAYER, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c12f0
		jmp eax
	}
}

jNothing __declspec(naked) CripplePlayer(HPLAYER, HFORCE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1310
		jmp eax
	}
}

HVERSION  __declspec(naked) VersionGet()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b32f0
		jmp eax
	}
}

jBoolean __declspec(naked) VersionCompatible(HVERSION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3300
		jmp eax
	}
}

jBoolean __declspec(naked) VersionSupported(HVERSION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3310
		jmp eax
	}
}

jNothing __declspec(naked) EndGame(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbbb0
		jmp eax
	}
}

jNothing __declspec(naked) ChangeLevel(jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbc30
		jmp eax
	}
}

jNothing __declspec(naked) RestartGame(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbc00
		jmp eax
	}
}

jNothing __declspec(naked) ReloadGame()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbbe0
		jmp eax
	}
}

jNothing __declspec(naked) LoadGame(jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbe60
		jmp eax
	}
}

jNothing __declspec(naked) SaveGame(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbee0
		jmp eax
	}
}

jBoolean __declspec(naked) RenameSaveDirectory(jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbfb0
		jmp eax
	}
}

jBoolean __declspec(naked) RemoveSaveDirectory(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc070
		jmp eax
	}
}

jBoolean __declspec(naked) CopySaveGame(jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc180
		jmp eax
	}
}

jBoolean __declspec(naked) SaveGameExists(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc100
		jmp eax
	}
}

jNothing __declspec(naked) SetFloatGameState(HFGAMESTATE, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc2e0
		jmp eax
	}
}

jReal __declspec(naked) GetFloatGameState(HFGAMESTATE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc310
		jmp eax
	}
}

jNothing __declspec(naked) SetIntegerGameState(HIGAMESTATE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc350
		jmp eax
	}
}

jInteger __declspec(naked) GetIntegerGameState(HIGAMESTATE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc380
		jmp eax
	}
}

jNothing __declspec(naked) SyncSelections()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bb740
		jmp eax
	}
}

HDIALOG  __declspec(naked) DialogCreate()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2bc0
		jmp eax
	}
}

jNothing __declspec(naked) DialogDestroy(HDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9f00
		jmp eax
	}
}

jNothing __declspec(naked) DialogSetAsync(HDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9f20
		jmp eax
	}
}

jNothing __declspec(naked) DialogClear(HDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9f40
		jmp eax
	}
}

jNothing __declspec(naked) DialogSetMessage(HDIALOG, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9f60
		jmp eax
	}
}

HBUTTON  __declspec(naked) DialogAddButton(HDIALOG, jString, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9f90
		jmp eax
	}
}

HBUTTON  __declspec(naked) DialogAddQuitButton(HDIALOG, jBoolean, jString, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c9fe0
		jmp eax
	}
}

jNothing __declspec(naked) DialogDisplay(HPLAYER, HDIALOG, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca030
		jmp eax
	}
}

jNothing __declspec(naked) SetMissionAvailable(jInteger, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3340
		jmp eax
	}
}

jNothing __declspec(naked) SetCampaignAvailable(jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3370
		jmp eax
	}
}

jNothing __declspec(naked) SetCampaignMenuRace(HRACE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc3d0
		jmp eax
	}
}

jNothing __declspec(naked) SetCampaignMenuRaceEx(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc3b0
		jmp eax
	}
}

jNothing __declspec(naked) ForceCampaignSelectScreen()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc400
		jmp eax
	}
}

jNothing __declspec(naked) SetOpCinematicAvailable(jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3400
		jmp eax
	}
}

jNothing __declspec(naked) SetEdCinematicAvailable(jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3460
		jmp eax
	}
}

jNothing __declspec(naked) SetTutorialCleared(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3430
		jmp eax
	}
}

HGAMEDIFFICULTY  __declspec(naked) GetDefaultDifficulty()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b33a0
		jmp eax
	}
}

jNothing __declspec(naked) SetDefaultDifficulty(HGAMEDIFFICULTY)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b33d0
		jmp eax
	}
}

jBoolean __declspec(naked) ReloadGameCachesFromDisk()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc430
		jmp eax
	}
}

jNothing __declspec(naked) SetCustomCampaignButtonVisible(jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3510
		jmp eax
	}
}

jBoolean __declspec(naked) GetCustomCampaignButtonVisible(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3530
		jmp eax
	}
}

jNothing __declspec(naked) DoNotSaveReplay()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3550
		jmp eax
	}
}

HGAMECACHE  __declspec(naked) InitGameCache(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2cc0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveGameCache(HGAMECACHE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca080
		jmp eax
	}
}

jNothing __declspec(naked) StoreInteger(HGAMECACHE, jString, jString, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca0a0
		jmp eax
	}
}

jNothing __declspec(naked) StoreReal(HGAMECACHE, jString, jString, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca0f0
		jmp eax
	}
}

jNothing __declspec(naked) StoreBoolean(HGAMECACHE, jString, jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca140
		jmp eax
	}
}

jBoolean __declspec(naked) StoreUnit(HGAMECACHE, jString, jString, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca1a0
		jmp eax
	}
}

jBoolean __declspec(naked) StoreString(HGAMECACHE, jString, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca680
		jmp eax
	}
}

jNothing __declspec(naked) SaveInteger(HHASHTABLE, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca200
		jmp eax
	}
}

jNothing __declspec(naked) SaveReal(HHASHTABLE, jInteger, jInteger, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca240
		jmp eax
	}
}

jNothing __declspec(naked) SaveBoolean(HHASHTABLE, jInteger, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca280
		jmp eax
	}
}

jBoolean __declspec(naked) SaveStr(HHASHTABLE, jInteger, jInteger, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca2c0
		jmp eax
	}
}

jBoolean __declspec(naked) SavePlayerHandle(HHASHTABLE, jInteger, jInteger, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca300
		jmp eax
	}
}

jBoolean __declspec(naked) SaveWidgetHandle(HHASHTABLE, jInteger, jInteger, HWIDGET)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca320
		jmp eax
	}
}

jBoolean __declspec(naked) SaveDestructableHandle(HHASHTABLE, jInteger, jInteger, HDESTRUCTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca340
		jmp eax
	}
}

jBoolean __declspec(naked) SaveItemHandle(HHASHTABLE, jInteger, jInteger, HITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca360
		jmp eax
	}
}

jBoolean __declspec(naked) SaveUnitHandle(HHASHTABLE, jInteger, jInteger, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca380
		jmp eax
	}
}

jBoolean __declspec(naked) SaveAbilityHandle(HHASHTABLE, jInteger, jInteger, HABILITY)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce8c0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTimerHandle(HHASHTABLE, jInteger, jInteger, HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca3a0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveRegionHandle(HHASHTABLE, jInteger, jInteger, HREGION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca3c0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTriggerHandle(HHASHTABLE, jInteger, jInteger, jTrigger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca3e0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTriggerConditionHandle(HHASHTABLE, jInteger, jInteger, HTRIGGERCONDITION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca400
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTriggerActionHandle(HHASHTABLE, jInteger, jInteger, HTRIGGERACTION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca420
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTriggerEventHandle(HHASHTABLE, jInteger, jInteger, HEVENT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca440
		jmp eax
	}
}

jBoolean __declspec(naked) SaveForceHandle(HHASHTABLE, jInteger, jInteger, HFORCE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca460
		jmp eax
	}
}

jBoolean __declspec(naked) SaveGroupHandle(HHASHTABLE, jInteger, jInteger, HGROUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca480
		jmp eax
	}
}

jBoolean __declspec(naked) SaveLocationHandle(HHASHTABLE, jInteger, jInteger, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca4a0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveRectHandle(HHASHTABLE, jInteger, jInteger, HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca4c0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveBooleanExprHandle(HHASHTABLE, jInteger, jInteger, HBOOLEXPR)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca4e0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveSoundHandle(HHASHTABLE, jInteger, jInteger, HSOUND)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca500
		jmp eax
	}
}

jBoolean __declspec(naked) SaveEffectHandle(HHASHTABLE, jInteger, jInteger, HEFFECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce8e0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveUnitPoolHandle(HHASHTABLE, jInteger, jInteger, HUNITPOOL)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce900
		jmp eax
	}
}

jBoolean __declspec(naked) SaveItemPoolHandle(HHASHTABLE, jInteger, jInteger, HITEMPOOL)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce920
		jmp eax
	}
}

jBoolean __declspec(naked) SaveQuestHandle(HHASHTABLE, jInteger, jInteger, HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce940
		jmp eax
	}
}

jBoolean __declspec(naked) SaveQuestItemHandle(HHASHTABLE, jInteger, jInteger, HQUESTITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce960
		jmp eax
	}
}

jBoolean __declspec(naked) SaveDefeatConditionHandle(HHASHTABLE, jInteger, jInteger, HDEFEATCONDITION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce980
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTimerDialogHandle(HHASHTABLE, jInteger, jInteger, HTIMERDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce9a0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveLeaderboardHandle(HHASHTABLE, jInteger, jInteger, HLEADERBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce9c0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveMultiboardHandle(HHASHTABLE, jInteger, jInteger, HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ce9e0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveMultiboardItemHandle(HHASHTABLE, jInteger, jInteger, HMULTIBOARDITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cea00
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTrackableHandle(HHASHTABLE, jInteger, jInteger, HTRACKABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cea20
		jmp eax
	}
}

jBoolean __declspec(naked) SaveDialogHandle(HHASHTABLE, jInteger, jInteger, HDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca520
		jmp eax
	}
}

jBoolean __declspec(naked) SaveButtonHandle(HHASHTABLE, jInteger, jInteger, HBUTTON)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca540
		jmp eax
	}
}

jBoolean __declspec(naked) SaveTextTagHandle(HHASHTABLE, jInteger, jInteger, HTEXTTAG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca5a0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveLightningHandle(HHASHTABLE, jInteger, jInteger, HLIGHTNING)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca5c0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveImageHandle(HHASHTABLE, jInteger, jInteger, HIMAGE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca5e0
		jmp eax
	}
}

jBoolean __declspec(naked) SaveUbersplatHandle(HHASHTABLE, jInteger, jInteger, HUBERSPLAT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca600
		jmp eax
	}
}

jBoolean __declspec(naked) SaveFogStateHandle(HHASHTABLE, jInteger, jInteger, HFOGSTATE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca620
		jmp eax
	}
}

jBoolean __declspec(naked) SaveFogModifierHandle(HHASHTABLE, jInteger, jInteger, HFOGMODIFIER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca640
		jmp eax
	}
}

jBoolean __declspec(naked) SaveAgentHandle(HHASHTABLE, jInteger, jInteger, HAGENT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cea40
		jmp eax
	}
}

jBoolean __declspec(naked) SaveHashtableHandle(HHASHTABLE, jInteger, jInteger, HHASHTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca660
		jmp eax
	}
}

jNothing __declspec(naked) SyncStoredInteger(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca6e0
		jmp eax
	}
}

jNothing __declspec(naked) SyncStoredReal(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca730
		jmp eax
	}
}

jNothing __declspec(naked) SyncStoredBoolean(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca780
		jmp eax
	}
}

jNothing __declspec(naked) SyncStoredUnit(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca7d0
		jmp eax
	}
}

jNothing __declspec(naked) SyncStoredString(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca820
		jmp eax
	}
}

jInteger __declspec(naked) GetStoredInteger(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca870
		jmp eax
	}
}

jReal __declspec(naked) GetStoredReal(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca8c0
		jmp eax
	}
}

jBoolean __declspec(naked) GetStoredBoolean(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca920
		jmp eax
	}
}

HUNIT  __declspec(naked) RestoreUnit(HGAMECACHE, jString, jString, HPLAYER, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ca970
		jmp eax
	}
}

jString __declspec(naked) GetStoredString(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caa40
		jmp eax
	}
}

jBoolean __declspec(naked) HaveStoredInteger(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caf30
		jmp eax
	}
}

jBoolean __declspec(naked) HaveStoredReal(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caf80
		jmp eax
	}
}

jBoolean __declspec(naked) HaveStoredBoolean(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cafd0
		jmp eax
	}
}

jBoolean __declspec(naked) HaveStoredUnit(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb020
		jmp eax
	}
}

jBoolean __declspec(naked) HaveStoredString(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb070
		jmp eax
	}
}

jNothing __declspec(naked) FlushGameCache(HGAMECACHE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb200
		jmp eax
	}
}

jNothing __declspec(naked) FlushStoredMission(HGAMECACHE, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb240
		jmp eax
	}
}

jNothing __declspec(naked) FlushStoredInteger(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb280
		jmp eax
	}
}

jNothing __declspec(naked) FlushStoredReal(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb2d0
		jmp eax
	}
}

jNothing __declspec(naked) FlushStoredBoolean(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb320
		jmp eax
	}
}

jNothing __declspec(naked) FlushStoredUnit(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb370
		jmp eax
	}
}

jNothing __declspec(naked) FlushStoredString(HGAMECACHE, jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb3c0
		jmp eax
	}
}

HHASHTABLE  __declspec(naked) InitHashtable()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2df0
		jmp eax
	}
}

jInteger  __declspec(naked) LoadInteger(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caa90
		jmp eax
	}
}

jReal  __declspec(naked) LoadReal(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caad0
		jmp eax
	}
}

jBoolean  __declspec(naked) LoadBoolean(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cab10
		jmp eax
	}
}

jString  __declspec(naked) LoadStr(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cab50
		jmp eax
	}
}

HPLAYER  __declspec(naked) LoadPlayerHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cab90
		jmp eax
	}
}

HWIDGET  __declspec(naked) LoadWidgetHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cabb0
		jmp eax
	}
}

HDESTRUCTABLE  __declspec(naked) LoadDestructableHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cabd0
		jmp eax
	}
}

HITEM  __declspec(naked) LoadItemHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cabf0
		jmp eax
	}
}

HUNIT  __declspec(naked) LoadUnitHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cac10
		jmp eax
	}
}

HABILITY  __declspec(naked) LoadAbilityHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cea60
		jmp eax
	}
}

HTIMER  __declspec(naked) LoadTimerHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cac30
		jmp eax
	}
}

HREGION  __declspec(naked) LoadRegionHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cac50
		jmp eax
	}
}

jTrigger  __declspec(naked) LoadTriggerHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cac70
		jmp eax
	}
}

HTRIGGERCONDITION  __declspec(naked) LoadTriggerConditionHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cac90
		jmp eax
	}
}

HTRIGGERACTION __declspec(naked) LoadTriggerActionHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cacb0
		jmp eax
	}
}

HEVENT  __declspec(naked) LoadTriggerEventHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cacd0
		jmp eax
	}
}

HFORCE  __declspec(naked) LoadForceHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cacf0
		jmp eax
	}
}

HGROUP  __declspec(naked) LoadGroupHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cad10
		jmp eax
	}
}

HLOCATION  __declspec(naked) LoadLocationHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cad30
		jmp eax
	}
}

HRECT  __declspec(naked) LoadRectHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cad50
		jmp eax
	}
}

HBOOLEXPR  __declspec(naked) LoadBooleanExprHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cad70
		jmp eax
	}
}

HSOUND  __declspec(naked) LoadSoundHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cad90
		jmp eax
	}
}

HEFFECT  __declspec(naked) LoadEffectHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cea80
		jmp eax
	}
}

HUNITPOOL  __declspec(naked) LoadUnitPoolHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceaa0
		jmp eax
	}
}

HITEMPOOL  __declspec(naked) LoadItemPoolHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceac0
		jmp eax
	}
}

HQUEST  __declspec(naked) LoadQuestHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceae0
		jmp eax
	}
}

HQUESTITEM  __declspec(naked) LoadQuestItemHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceb00
		jmp eax
	}
}

HDEFEATCONDITION  __declspec(naked) LoadDefeatConditionHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceb20
		jmp eax
	}
}

HTIMERDIALOG  __declspec(naked) LoadTimerDialogHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceb40
		jmp eax
	}
}

HLEADERBOARD  __declspec(naked) LoadLeaderboardHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceb60
		jmp eax
	}
}

HMULTIBOARD  __declspec(naked) LoadMultiboardHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceb80
		jmp eax
	}
}

HMULTIBOARDITEM  __declspec(naked) LoadMultiboardItemHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ceba0
		jmp eax
	}
}

HTRACKABLE  __declspec(naked) LoadTrackableHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cebc0
		jmp eax
	}
}

HDIALOG  __declspec(naked) LoadDialogHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cadb0
		jmp eax
	}
}

HBUTTON  __declspec(naked) LoadButtonHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cadd0
		jmp eax
	}
}

HTEXTTAG  __declspec(naked) LoadTextTagHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cae50
		jmp eax
	}
}

HLIGHTNING  __declspec(naked) LoadLightningHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cae70
		jmp eax
	}
}

HIMAGE  __declspec(naked) LoadImageHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cae90
		jmp eax
	}
}

HUBERSPLAT  __declspec(naked) LoadUbersplatHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caeb0
		jmp eax
	}
}

HFOGSTATE  __declspec(naked) LoadFogStateHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caed0
		jmp eax
	}
}

HFOGMODIFIER  __declspec(naked) LoadFogModifierHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caef0
		jmp eax
	}
}

HHASHTABLE  __declspec(naked) LoadHashtableHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3caf10
		jmp eax
	}
}

jBoolean __declspec(naked) HaveSavedInteger(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb0c0
		jmp eax
	}
}

jBoolean __declspec(naked) HaveSavedReal(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb100
		jmp eax
	}
}

jBoolean __declspec(naked) HaveSavedBoolean(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb140
		jmp eax
	}
}

jBoolean __declspec(naked) HaveSavedString(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb180
		jmp eax
	}
}

jBoolean __declspec(naked) HaveSavedHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb1c0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveSavedInteger(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb410
		jmp eax
	}
}

jNothing __declspec(naked) RemoveSavedReal(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb450
		jmp eax
	}
}

jNothing __declspec(naked) RemoveSavedBoolean(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb490
		jmp eax
	}
}

jNothing __declspec(naked) RemoveSavedString(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb4d0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveSavedHandle(HHASHTABLE, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb510
		jmp eax
	}
}

jNothing __declspec(naked) FlushParentHashtable(HHASHTABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb550
		jmp eax
	}
}

jNothing __declspec(naked) FlushChildHashtable(HHASHTABLE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb590
		jmp eax
	}
}

jInteger __declspec(naked) GetRandomInt(jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3560
		jmp eax
	}
}

jReal __declspec(naked) GetRandomReal(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b35a0
		jmp eax
	}
}

HUNITPOOL  __declspec(naked) CreateUnitPool()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2ed0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyUnitPool(HUNITPOOL)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb5c0
		jmp eax
	}
}

jNothing __declspec(naked) UnitPoolAddUnitType(HUNITPOOL, jInteger, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb5e0
		jmp eax
	}
}

jNothing __declspec(naked) UnitPoolRemoveUnitType(HUNITPOOL, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb600
		jmp eax
	}
}

HUNIT  __declspec(naked) PlaceRandomUnit(HUNITPOOL, HPLAYER, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb620
		jmp eax
	}
}

HITEMPOOL  __declspec(naked) CreateItemPool()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d2fc0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyItemPool(HITEMPOOL)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb6a0
		jmp eax
	}
}

jNothing __declspec(naked) ItemPoolAddItemType(HITEMPOOL, jInteger, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb6c0
		jmp eax
	}
}

jNothing __declspec(naked) ItemPoolRemoveItemType(HITEMPOOL, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb6e0
		jmp eax
	}
}

HITEM  __declspec(naked) PlaceRandomItem(HITEMPOOL, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb700
		jmp eax
	}
}

jInteger __declspec(naked) ChooseRandomCreep(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3660
		jmp eax
	}
}

jInteger __declspec(naked) ChooseRandomNPBuilding()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3680
		jmp eax
	}
}

jInteger __declspec(naked) ChooseRandomItem(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3690
		jmp eax
	}
}

jInteger __declspec(naked) ChooseRandomItemEx(HITEMTYPE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b36b0
		jmp eax
	}
}

jNothing __declspec(naked) SetRandomSeed(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b36d0
		jmp eax
	}
}

jNothing __declspec(naked) DisplayTextToPlayer(HPLAYER, jReal*, jReal*, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb900
		jmp eax
	}
}

jNothing __declspec(naked) DisplayTimedTextToPlayer(HPLAYER, jReal*, jReal*, jReal*, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb9b0
		jmp eax
	}
}

jNothing __declspec(naked) DisplayTimedTextFromPlayer(HPLAYER, jReal*, jReal*, jReal*, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cba30
		jmp eax
	}
}

jNothing __declspec(naked) ClearTextMessages()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4e60
		jmp eax
	}
}

jNothing __declspec(naked) EnableUserControl(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3880
		jmp eax
	}
}

jNothing __declspec(naked) EnableUserUI(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b38a0
		jmp eax
	}
}

jNothing __declspec(naked) DisableRestartMission(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b38c0
		jmp eax
	}
}

jNothing __declspec(naked) ForceUIKey(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b38e0
		jmp eax
	}
}

jNothing __declspec(naked) ForceUICancel()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3990
		jmp eax
	}
}

jNothing __declspec(naked) DisplayLoadDialog()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3a10
		jmp eax
	}
}

jNothing __declspec(naked) SetTerrainFog(jReal*, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3840
		jmp eax
	}
}

jNothing __declspec(naked) SetUnitFog(jReal*, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3850
		jmp eax
	}
}

jNothing __declspec(naked) SetTerrainFogEx(jInteger, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b81b0
		jmp eax
	}
}

jNothing __declspec(naked) ResetTerrainFog()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3860
		jmp eax
	}
}

jNothing __declspec(naked) SetDayNightModels(jString, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3790
		jmp eax
	}
}

jNothing __declspec(naked) SetSkyModel(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b37d0
		jmp eax
	}
}

jNothing __declspec(naked) SuspendTimeOfDay(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc460
		jmp eax
	}
}

jNothing __declspec(naked) SetTimeOfDayScale(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc490
		jmp eax
	}
}

jReal __declspec(naked) GetTimeOfDayScale()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc4b0
		jmp eax
	}
}

jNothing __declspec(naked) ShowInterface(jBoolean, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3810
		jmp eax
	}
}

jNothing __declspec(naked) PauseGame(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc4d0
		jmp eax
	}
}

jNothing __declspec(naked) PingMinimap(jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4650
		jmp eax
	}
}

jNothing __declspec(naked) PingMinimapEx(jReal*, jReal*, jReal*, jInteger, jInteger, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b8660
		jmp eax
	}
}

jNothing __declspec(naked) SetIntroShotText(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc880
		jmp eax
	}
}

jNothing __declspec(naked) SetIntroShotModel(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc8a0
		jmp eax
	}
}

jNothing __declspec(naked) EnableOcclusion(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3b90
		jmp eax
	}
}

jNothing __declspec(naked) EnableWorldFogBoundary(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3bb0
		jmp eax
	}
}

jNothing __declspec(naked) PlayModelCinematic(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc500
		jmp eax
	}
}

jNothing __declspec(naked) PlayCinematic(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc520
		jmp eax
	}
}

jNothing __declspec(naked) SetAltMinimapIcon(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc540
		jmp eax
	}
}

HTEXTTAG  __declspec(naked) CreateTextTag()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc580
		jmp eax
	}
}

jNothing __declspec(naked) DestroyTextTag(HTEXTTAG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc5a0
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagText(HTEXTTAG, jString, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc5d0
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagPos(HTEXTTAG, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc610
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagPosUnit(HTEXTTAG, HUNIT, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb890
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagColor(HTEXTTAG, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc6a0
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagVelocity(HTEXTTAG, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc700
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagVisibility(HTEXTTAG, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc760
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagSuspended(HTEXTTAG, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc790
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagPermanent(HTEXTTAG, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc7c0
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagAge(HTEXTTAG, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc7f0
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagLifespan(HTEXTTAG, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc820
		jmp eax
	}
}

jNothing __declspec(naked) SetTextTagFadepoint(HTEXTTAG, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc850
		jmp eax
	}
}

jNothing __declspec(naked) SetReservedLocalHeroButtons(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3a30
		jmp eax
	}
}

jInteger __declspec(naked) GetAllyColorFilterState()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3a50
		jmp eax
	}
}

jNothing __declspec(naked) SetAllyColorFilterState(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3a70
		jmp eax
	}
}

jBoolean __declspec(naked) GetCreepCampFilterState()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3aa0
		jmp eax
	}
}

jNothing __declspec(naked) SetCreepCampFilterState(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3ac0
		jmp eax
	}
}

jNothing __declspec(naked) EnableMinimapFilterButtons(jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3af0
		jmp eax
	}
}

jNothing __declspec(naked) EnableDragSelect(jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3b30
		jmp eax
	}
}

jNothing __declspec(naked) EnablePreSelect(jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3b50
		jmp eax
	}
}

jNothing __declspec(naked) EnableSelect(jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3b70
		jmp eax
	}
}

HTRACKABLE  __declspec(naked) CreateTrackable(jString, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d30b0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterTrackableHitEvent(jTrigger, HTRACKABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d31c0
		jmp eax
	}
}

HEVENT  __declspec(naked) TriggerRegisterTrackableTrackEvent(jTrigger, HTRACKABLE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d32a0
		jmp eax
	}
}

HTRACKABLE  __declspec(naked) GetTriggeringTrackable()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3da0
		jmp eax
	}
}

HQUEST  __declspec(naked) CreateQuest()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc970
		jmp eax
	}
}

jNothing __declspec(naked) DestroyQuest(HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbb20
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetTitle(HQUEST, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbb70
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetDescription(HQUEST, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbba0
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetIconPath(HQUEST, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbbd0
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetRequired(HQUEST, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbc00
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetCompleted(HQUEST, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbc20
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetDiscovered(HQUEST, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbc60
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetFailed(HQUEST, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbc40
		jmp eax
	}
}

jNothing __declspec(naked) QuestSetEnabled(HQUEST, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbc80
		jmp eax
	}
}

jBoolean __declspec(naked) IsQuestRequired(HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbca0
		jmp eax
	}
}

jBoolean __declspec(naked) IsQuestCompleted(HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbcc0
		jmp eax
	}
}

jBoolean __declspec(naked) IsQuestDiscovered(HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbce0
		jmp eax
	}
}

jBoolean __declspec(naked) IsQuestFailed(HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbd00
		jmp eax
	}
}

jBoolean __declspec(naked) IsQuestEnabled(HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbd20
		jmp eax
	}
}

HQUESTITEM  __declspec(naked) QuestCreateItem(HQUEST)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3380
		jmp eax
	}
}

jNothing __declspec(naked) QuestItemSetDescription(HQUESTITEM, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbd40
		jmp eax
	}
}

jNothing __declspec(naked) QuestItemSetCompleted(HQUESTITEM, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbd70
		jmp eax
	}
}

jBoolean __declspec(naked) IsQuestItemCompleted(HQUESTITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbd90
		jmp eax
	}
}

HDEFEATCONDITION  __declspec(naked) CreateDefeatCondition()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc9e0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyDefeatCondition(HDEFEATCONDITION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbdb0
		jmp eax
	}
}

jNothing __declspec(naked) DefeatConditionSetDescription(HDEFEATCONDITION, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbe00
		jmp eax
	}
}

jNothing __declspec(naked) FlashQuestDialogButton()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc920
		jmp eax
	}
}

jNothing __declspec(naked) ForceQuestDialogUpdate()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3be0
		jmp eax
	}
}

HTIMERDIALOG  __declspec(naked) CreateTimerDialog(HTIMER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d34b0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyTimerDialog(HTIMERDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbe30
		jmp eax
	}
}

jNothing __declspec(naked) TimerDialogSetTitle(HTIMERDIALOG, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbe50
		jmp eax
	}
}

jNothing __declspec(naked) TimerDialogSetTitleColor(HTIMERDIALOG, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbe80
		jmp eax
	}
}

jNothing __declspec(naked) TimerDialogSetTimeColor(HTIMERDIALOG, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbed0
		jmp eax
	}
}

jNothing __declspec(naked) TimerDialogSetSpeed(HTIMERDIALOG, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbf20
		jmp eax
	}
}

jNothing __declspec(naked) TimerDialogDisplay(HTIMERDIALOG, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbf50
		jmp eax
	}
}

jBoolean __declspec(naked) IsTimerDialogDisplayed(HTIMERDIALOG)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbf70
		jmp eax
	}
}

jNothing __declspec(naked) TimerDialogSetRealTimeRemaining(HTIMERDIALOG, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbfa0
		jmp eax
	}
}

HLEADERBOARD  __declspec(naked) CreateLeaderboard()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d35b0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyLeaderboard(HLEADERBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cbfd0
		jmp eax
	}
}

jInteger __declspec(naked) LeaderboardGetItemCount(HLEADERBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc000
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetSizeByItemCount(HLEADERBOARD, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc030
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardAddItem(HLEADERBOARD, jString, jInteger, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc060
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardRemoveItem(HLEADERBOARD, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc0b0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardRemovePlayerItem(HLEADERBOARD, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc0e0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSortItemsByValue(HLEADERBOARD, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc120
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSortItemsByPlayer(HLEADERBOARD, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc150
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSortItemsByLabel(HLEADERBOARD, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc180
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardClear(HLEADERBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc1b0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardDisplay(HLEADERBOARD, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc1d0
		jmp eax
	}
}

jBoolean __declspec(naked) IsLeaderboardDisplayed(HLEADERBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc220
		jmp eax
	}
}

jString __declspec(naked) LeaderboardGetLabelText(HLEADERBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc2f0
		jmp eax
	}
}

jNothing __declspec(naked) PlayerSetLeaderboard(HPLAYER, HLEADERBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc340
		jmp eax
	}
}

HLEADERBOARD  __declspec(naked) PlayerGetLeaderboard(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc380
		jmp eax
	}
}

jBoolean __declspec(naked) LeaderboardHasPlayerItem(HLEADERBOARD, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc250
		jmp eax
	}
}

jInteger __declspec(naked) LeaderboardGetPlayerIndex(HLEADERBOARD, HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc2a0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetLabel(HLEADERBOARD, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc3d0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetLabelColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc400
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetValueColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc450
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetStyle(HLEADERBOARD, jBoolean, jBoolean, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc4a0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetItemValue(HLEADERBOARD, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc4f0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetItemLabel(HLEADERBOARD, jInteger, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc520
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetItemStyle(HLEADERBOARD, jInteger, jBoolean, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc560
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetItemLabelColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc5b0
		jmp eax
	}
}

jNothing __declspec(naked) LeaderboardSetItemValueColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc600
		jmp eax
	}
}

HMULTIBOARD  __declspec(naked) CreateMultiboard()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d36b0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyMultiboard(HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc650
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardDisplay(HMULTIBOARD, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc670
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardMinimize(HMULTIBOARD, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc6b0
		jmp eax
	}
}

jBoolean __declspec(naked) IsMultiboardDisplayed(HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc690
		jmp eax
	}
}

jBoolean __declspec(naked) IsMultiboardMinimized(HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc6d0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardClear(HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc6f0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetTitleText(HMULTIBOARD, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc720
		jmp eax
	}
}

jString __declspec(naked) MultiboardGetTitleText(HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc750
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetTitleTextColor(HMULTIBOARD, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc770
		jmp eax
	}
}

jInteger __declspec(naked) MultiboardGetRowCount(HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc7b0
		jmp eax
	}
}

jInteger __declspec(naked) MultiboardGetColumnCount(HMULTIBOARD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc7d0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetColumnCount(HMULTIBOARD, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc7f0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetRowCount(HMULTIBOARD, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc810
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemsStyle(HMULTIBOARD, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc830
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemsValueColor(HMULTIBOARD, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc8a0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemsValue(HMULTIBOARD, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc870
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemsWidth(HMULTIBOARD, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc8f0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemsIcon(HMULTIBOARD, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc920
		jmp eax
	}
}

HMULTIBOARDITEM  __declspec(naked) MultiboardGetItem(HMULTIBOARD, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d37b0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardReleaseItem(HMULTIBOARDITEM)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc950
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemStyle(HMULTIBOARDITEM, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc970
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemValue(HMULTIBOARDITEM, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc990
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemValueColor(HMULTIBOARDITEM, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cc9c0
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemWidth(HMULTIBOARDITEM, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cca00
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSetItemIcon(HMULTIBOARDITEM, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cca20
		jmp eax
	}
}

jNothing __declspec(naked) MultiboardSuppressDisplay(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3c00
		jmp eax
	}
}

jNothing __declspec(naked) SetCameraBounds(jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b86f0
		jmp eax
	}
}

jNothing __declspec(naked) SetCameraPosition(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b45d0
		jmp eax
	}
}

jNothing __declspec(naked) SetCameraQuickPosition(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4610
		jmp eax
	}
}

jNothing __declspec(naked) ResetToGameCamera(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b46b0
		jmp eax
	}
}

jNothing __declspec(naked) StopCamera()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b46e0
		jmp eax
	}
}

jNothing __declspec(naked) PanCameraTo(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4700
		jmp eax
	}
}

jNothing __declspec(naked) PanCameraToTimed(jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4740
		jmp eax
	}
}

jNothing __declspec(naked) PanCameraToWithZ(jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4790
		jmp eax
	}
}

jNothing __declspec(naked) PanCameraToTimedWithZ(jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b47d0
		jmp eax
	}
}

jNothing __declspec(naked) SetCinematicCamera(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4820
		jmp eax
	}
}

jNothing __declspec(naked) SetCameraField(HCAMERAFIELD, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b48b0
		jmp eax
	}
}

jNothing __declspec(naked) AdjustCameraField(HCAMERAFIELD, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b48f0
		jmp eax
	}
}

jNothing __declspec(naked) SetCameraTargetController(HUNIT, jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd760
		jmp eax
	}
}

jNothing __declspec(naked) SetCameraOrientController(HUNIT, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd7b0
		jmp eax
	}
}

jNothing __declspec(naked) SetCameraRotateMode(jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4850
		jmp eax
	}
}

HCAMERASETUP  __declspec(naked) CreateCameraSetup()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3d40
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetupSetField(HCAMERASETUP, HCAMERAFIELD, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd800
		jmp eax
	}
}

jReal __declspec(naked) CameraSetupGetField(HCAMERASETUP, HCAMERAFIELD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd830
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetupSetDestPosition(HCAMERASETUP, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd870
		jmp eax
	}
}

HLOCATION  __declspec(naked) CameraSetupGetDestPositionLoc(HCAMERASETUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3e40
		jmp eax
	}
}

jReal __declspec(naked) CameraSetupGetDestPositionX(HCAMERASETUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd8c0
		jmp eax
	}
}

jReal __declspec(naked) CameraSetupGetDestPositionY(HCAMERASETUP)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd8e0
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetupApply(HCAMERASETUP, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd900
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetupApplyWithZ(HCAMERASETUP, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd930
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetupApplyForceDuration(HCAMERASETUP, jBoolean, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd960
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetupApplyForceDurationWithZ(HCAMERASETUP, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd990
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetTargetNoise(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4930
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetSourceNoise(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b49e0
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetTargetNoiseEx(jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4a70
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetSourceNoiseEx(jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4b20
		jmp eax
	}
}

jNothing __declspec(naked) CameraSetSmoothingFactor(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4bb0
		jmp eax
	}
}

jReal __declspec(naked) GetCameraMargin(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4be0
		jmp eax
	}
}

jReal __declspec(naked) GetCameraBoundMinX()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4c50
		jmp eax
	}
}

jReal __declspec(naked) GetCameraBoundMinY()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4c70
		jmp eax
	}
}

jReal __declspec(naked) GetCameraBoundMaxX()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4c90
		jmp eax
	}
}

jReal __declspec(naked) GetCameraBoundMaxY()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4cb0
		jmp eax
	}
}

jReal __declspec(naked) GetCameraField(HCAMERAFIELD)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4cd0
		jmp eax
	}
}

jReal __declspec(naked) GetCameraTargetPositionX()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4d00
		jmp eax
	}
}

jReal __declspec(naked) GetCameraTargetPositionY()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4d30
		jmp eax
	}
}

jReal __declspec(naked) GetCameraTargetPositionZ()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4d60
		jmp eax
	}
}

HLOCATION  __declspec(naked) GetCameraTargetPositionLoc()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3e90
		jmp eax
	}
}

jReal __declspec(naked) GetCameraEyePositionX()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4d90
		jmp eax
	}
}

jReal __declspec(naked) GetCameraEyePositionY()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4dc0
		jmp eax
	}
}

jReal __declspec(naked) GetCameraEyePositionZ()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4df0
		jmp eax
	}
}

HLOCATION  __declspec(naked) GetCameraEyePositionLoc()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3ee0
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterTexture(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4e80
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterBlendMode(HBLENDMODE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4eb0
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterTexMapFlags(HTEXMAPFLAGS)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4ef0
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterStartUV(jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4f40
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterEndUV(jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5020
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterStartColor(jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cebe0
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterEndColor(jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cecd0
		jmp eax
	}
}

jNothing __declspec(naked) SetCineFilterDuration(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5100
		jmp eax
	}
}

jNothing __declspec(naked) DisplayCineFilter(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5120
		jmp eax
	}
}

jBoolean __declspec(naked) IsCineFilterDisplayed()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5150
		jmp eax
	}
}

jNothing __declspec(naked) SetCinematicScene(jInteger, HPLAYERCOLOR, jString, jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcf80
		jmp eax
	}
}

jNothing __declspec(naked) EndCinematicScene()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4e20
		jmp eax
	}
}

jNothing __declspec(naked) ForceCinematicSubtitles(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4e40
		jmp eax
	}
}

jNothing __declspec(naked) NewSoundEnvironment(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e60
		jmp eax
	}
}

HSOUND  __declspec(naked) CreateSound(jString, jBoolean, jBoolean, jBoolean, jInteger, jInteger, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d38d0
		jmp eax
	}
}

HSOUND  __declspec(naked) CreateSoundFilenameWithLabel(jString, jBoolean, jBoolean, jBoolean, jInteger, jInteger, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d39f0
		jmp eax
	}
}

HSOUND  __declspec(naked) CreateSoundFromLabel(jString, jBoolean, jBoolean, jBoolean, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3b10
		jmp eax
	}
}

HSOUND  __declspec(naked) CreateMIDISound(jString, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3c30
		jmp eax
	}
}

jNothing __declspec(naked) SetStackedSound(jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3c20
		jmp eax
	}
}

jNothing __declspec(naked) ClearStackedSound(jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3c80
		jmp eax
	}
}

jNothing __declspec(naked) SetStackedSoundRect(jString, HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cca50
		jmp eax
	}
}

jNothing __declspec(naked) ClearStackedSoundRect(jString, HRECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccb20
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundParamsFromLabel(HSOUND, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccbf0
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundChannel(HSOUND, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccc20
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundVolume(HSOUND, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccc40
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundPitch(HSOUND, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccc60
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundPlayPosition(HSOUND, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccc80
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundDistances(HSOUND, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccca0
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundDistanceCutoff(HSOUND, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cccd0
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundConeAngles(HSOUND, jReal*, jReal*, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cccf0
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundConeOrientation(HSOUND, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccd30
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundPosition(HSOUND, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccd90
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundVelocity(HSOUND, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccdf0
		jmp eax
	}
}

jNothing __declspec(naked) AttachSoundToUnit(HSOUND, HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cce50
		jmp eax
	}
}

jNothing __declspec(naked) StartSound(HSOUND)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cce80
		jmp eax
	}
}

jNothing __declspec(naked) StopSound(HSOUND, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cceb0
		jmp eax
	}
}

jNothing __declspec(naked) KillSoundWhenDone(HSOUND)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cced0
		jmp eax
	}
}

jNothing __declspec(naked) SetMapMusic(jString, jBoolean, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3ce0
		jmp eax
	}
}

jNothing __declspec(naked) ClearMapMusic()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3d20
		jmp eax
	}
}

jNothing __declspec(naked) PlayMusic(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3d30
		jmp eax
	}
}

jNothing __declspec(naked) PlayMusicEx(jString, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3d50
		jmp eax
	}
}

jNothing __declspec(naked) StopMusic(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3d80
		jmp eax
	}
}

jNothing __declspec(naked) ResumeMusic()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3d90
		jmp eax
	}
}

jNothing __declspec(naked) PlayThematicMusic(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3da0
		jmp eax
	}
}

jNothing __declspec(naked) PlayThematicMusicEx(jString, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3dc0
		jmp eax
	}
}

jNothing __declspec(naked) EndThematicMusic()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3de0
		jmp eax
	}
}

jNothing __declspec(naked) SetMusicVolume(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3df0
		jmp eax
	}
}

jNothing __declspec(naked) SetMusicPlayPosition(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e00
		jmp eax
	}
}

jNothing __declspec(naked) SetThematicMusicPlayPosition(jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e10
		jmp eax
	}
}

jNothing __declspec(naked) SetSoundDuration(HSOUND, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccef0
		jmp eax
	}
}

jInteger __declspec(naked) GetSoundDuration(HSOUND)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccf20
		jmp eax
	}
}

jInteger __declspec(naked) GetSoundFileDuration(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e20
		jmp eax
	}
}

jNothing __declspec(naked) VolumeGroupSetVolume(HVOLUMEGROUP, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e30
		jmp eax
	}
}

jNothing __declspec(naked) VolumeGroupReset()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e50
		jmp eax
	}
}

jBoolean __declspec(naked) GetSoundIsPlaying(HSOUND)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccf40
		jmp eax
	}
}

jBoolean __declspec(naked) GetSoundIsLoading(HSOUND)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccf60
		jmp eax
	}
}

jNothing __declspec(naked) RegisterStackedSound(HSOUND, jBoolean, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccf80
		jmp eax
	}
}

jNothing __declspec(naked) UnregisterStackedSound(HSOUND, jBoolean, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccfb0
		jmp eax
	}
}

HWEATHEREFFECT  __declspec(naked) AddWeatherEffect(HRECT, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3ccfe0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveWeatherEffect(HWEATHEREFFECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e70
		jmp eax
	}
}

jNothing __declspec(naked) EnableWeatherEffect(HWEATHEREFFECT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e80
		jmp eax
	}
}

HTERRAINDEFORMATION  __declspec(naked) TerrainDeformCrater(jReal*, jReal*, jReal*, jReal*, jInteger, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3e90
		jmp eax
	}
}

HTERRAINDEFORMATION  __declspec(naked) TerrainDeformRipple(jReal*, jReal*, jReal*, jReal*, jInteger, jInteger, jReal*, jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3f00
		jmp eax
	}
}

HTERRAINDEFORMATION  __declspec(naked) TerrainDeformWave(jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3fa0
		jmp eax
	}
}

HTERRAINDEFORMATION  __declspec(naked) TerrainDeformRandom(jReal*, jReal*, jReal*, jReal*, jReal*, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4040
		jmp eax
	}
}

jNothing __declspec(naked) TerrainDeformStop(HTERRAINDEFORMATION, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b40b0
		jmp eax
	}
}

jNothing __declspec(naked) TerrainDeformStopAll()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b40c0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyEffect(HEFFECT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd240
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpecialEffect(jString, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bca90
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpecialEffectLoc(jString, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd260
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpecialEffectTarget(jString, HWIDGET, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd2a0
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpellEffect(jString, HEFFECTTYPE, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcb10
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpellEffectLoc(jString, HEFFECTTYPE, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd320
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpellEffectById(jInteger, HEFFECTTYPE, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcae0
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpellEffectByIdLoc(jInteger, HEFFECTTYPE, HLOCATION)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd2d0
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpellEffectTarget(jString, HEFFECTTYPE, HWIDGET, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd4a0
		jmp eax
	}
}

HEFFECT  __declspec(naked) AddSpellEffectTargetById(jInteger, HEFFECTTYPE, HWIDGET, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd380
		jmp eax
	}
}

HLIGHTNING  __declspec(naked) AddLightning(jString, jBoolean, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcc20
		jmp eax
	}
}

HLIGHTNING  __declspec(naked) AddLightningEx(jString, jBoolean, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcb30
		jmp eax
	}
}

jBoolean __declspec(naked) DestroyLightning(HLIGHTNING)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4150
		jmp eax
	}
}

jReal __declspec(naked) GetLightningColorA(HLIGHTNING)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b8310
		jmp eax
	}
}

jReal __declspec(naked) GetLightningColorR(HLIGHTNING)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b8370
		jmp eax
	}
}

jReal __declspec(naked) GetLightningColorG(HLIGHTNING)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b83d0
		jmp eax
	}
}

jReal __declspec(naked) GetLightningColorB(HLIGHTNING)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b8430
		jmp eax
	}
}

jBoolean __declspec(naked) MoveLightning(HLIGHTNING, jBoolean, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcda0
		jmp eax
	}
}

jBoolean __declspec(naked) MoveLightningEx(HLIGHTNING, jBoolean, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bccc0
		jmp eax
	}
}

jBoolean __declspec(naked) SetLightningColor(HLIGHTNING, jReal*, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b8490
		jmp eax
	}
}

jString __declspec(naked) GetAbilityEffect(jString, HEFFECTTYPE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcab0
		jmp eax
	}
}

jString __declspec(naked) GetAbilityEffectById(jInteger, HEFFECTTYPE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bce40
		jmp eax
	}
}

jString __declspec(naked) GetAbilitySound(jString, HSOUNDTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bce60
		jmp eax
	}
}

jString __declspec(naked) GetAbilitySoundById(jInteger, HSOUNDTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcea0
		jmp eax
	}
}

jInteger __declspec(naked) GetTerrainCliffLevel(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4190
		jmp eax
	}
}

jNothing __declspec(naked) SetWaterBaseColor(jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b8580
		jmp eax
	}
}

jNothing __declspec(naked) SetWaterDeforms(jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4240
		jmp eax
	}
}

jInteger __declspec(naked) GetTerrainType(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bced0
		jmp eax
	}
}

jInteger __declspec(naked) GetTerrainVariance(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4250
		jmp eax
	}
}

jNothing __declspec(naked) SetTerrainType(jReal*, jReal*, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bcf20
		jmp eax
	}
}

jBoolean __declspec(naked) IsTerrainPathable(jReal*, jReal*, HPATHINGTYPE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b42d0
		jmp eax
	}
}

jNothing __declspec(naked) SetTerrainPathable(jReal*, jReal*, HPATHINGTYPE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b42f0
		jmp eax
	}
}

HIMAGE  __declspec(naked) CreateImage(jString, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4320
		jmp eax
	}
}

jNothing __declspec(naked) DestroyImage(HIMAGE)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b43b0
		jmp eax
	}
}

jNothing __declspec(naked) ShowImage(HIMAGE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b43c0
		jmp eax
	}
}

jNothing __declspec(naked) SetImageConstantHeight(HIMAGE, jBoolean, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b43e0
		jmp eax
	}
}

jNothing __declspec(naked) SetImagePosition(HIMAGE, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4400
		jmp eax
	}
}

jNothing __declspec(naked) SetImageColor(HIMAGE, jInteger, jInteger, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b85b0
		jmp eax
	}
}

jNothing __declspec(naked) SetImageRender(HIMAGE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4440
		jmp eax
	}
}

jNothing __declspec(naked) SetImageRenderAlways(HIMAGE, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4460
		jmp eax
	}
}

jNothing __declspec(naked) SetImageAboveWater(HIMAGE, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4480
		jmp eax
	}
}

jNothing __declspec(naked) SetImageType(HIMAGE, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b44a0
		jmp eax
	}
}

HUBERSPLAT  __declspec(naked) CreateUbersplat(jReal*, jReal*, jString, jInteger, jInteger, jInteger, jInteger, jBoolean, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b85f0
		jmp eax
	}
}

jNothing __declspec(naked) DestroyUbersplat(HUBERSPLAT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b44c0
		jmp eax
	}
}

jNothing __declspec(naked) ResetUbersplat(HUBERSPLAT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b44d0
		jmp eax
	}
}

jNothing __declspec(naked) FinishUbersplat(HUBERSPLAT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b44e0
		jmp eax
	}
}

jNothing __declspec(naked) ShowUbersplat(HUBERSPLAT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b44f0
		jmp eax
	}
}

jNothing __declspec(naked) SetUbersplatRender(HUBERSPLAT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4510
		jmp eax
	}
}

jNothing __declspec(naked) SetUbersplatRenderAlways(HUBERSPLAT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4530
		jmp eax
	}
}

jNothing __declspec(naked) SetBlight(HPLAYER, jReal*, jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd4c0
		jmp eax
	}
}

jNothing __declspec(naked) SetBlightLoc(HPLAYER, HLOCATION, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd5d0
		jmp eax
	}
}

jNothing __declspec(naked) SetBlightRect(HPLAYER, HRECT, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd520
		jmp eax
	}
}

jNothing __declspec(naked) SetBlightPoint(HPLAYER, jReal*, jReal*, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd580
		jmp eax
	}
}

HUNIT  __declspec(naked) CreateBlightedGoldmine(HPLAYER, jReal*, jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd630
		jmp eax
	}
}

jBoolean __declspec(naked) IsPointBlighted(jReal*, jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4550
		jmp eax
	}
}

jNothing __declspec(naked) SetDoodadAnimation(jReal*, jReal*, jReal*, jInteger, jBoolean, jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b4570
		jmp eax
	}
}

jNothing __declspec(naked) SetDoodadAnimationRect(HRECT, jInteger, jString, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cd6f0
		jmp eax
	}
}

jNothing __declspec(naked) StartMeleeAI(HPLAYER, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb740
		jmp eax
	}
}

jNothing __declspec(naked) StartCampaignAI(HPLAYER, jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb770
		jmp eax
	}
}

jNothing __declspec(naked) CommandAI(HPLAYER, jInteger, jInteger)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb7a0
		jmp eax
	}
}

jNothing __declspec(naked) PauseCompAI(HPLAYER, jBoolean)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb7c0
		jmp eax
	}
}

HAIDIFFICULTY  __declspec(naked) GetAIDifficulty(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb7e0
		jmp eax
	}
}

jNothing __declspec(naked) RemoveGuardPosition(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb820
		jmp eax
	}
}

jNothing __declspec(naked) RecycleGuardPosition(HUNIT)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb800
		jmp eax
	}
}

jNothing __declspec(naked) RemoveAllGuardPositions(HPLAYER)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb840
		jmp eax
	}
}

jNothing __declspec(naked) ExecuteFunc(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d3f30
		jmp eax
	}
}

jNothing __declspec(naked) Cheat(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b3bc0
		jmp eax
	}
}

jBoolean __declspec(naked) IsNoVictoryCheat()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc8c0
		jmp eax
	}
}

jBoolean __declspec(naked) IsNoDefeatCheat()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bc8f0
		jmp eax
	}
}

jNothing __declspec(naked) Preload(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5170
		jmp eax
	}
}

jNothing __declspec(naked) PreloadEnd(jReal*)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5190
		jmp eax
	}
}

jNothing __declspec(naked) PreloadStart()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b51f0
		jmp eax
	}
}

jNothing __declspec(naked) PreloadRefresh()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5210
		jmp eax
	}
}

jNothing __declspec(naked) PreloadEndEx()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5220
		jmp eax
	}
}

jNothing __declspec(naked) PreloadGenStart()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5290
		jmp eax
	}
}

jNothing __declspec(naked) PreloadGenClear()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b52b0
		jmp eax
	}
}

jNothing __declspec(naked) PreloadGenEnd(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b52d0
		jmp eax
	}
}

jNothing __declspec(naked) Preloader(jString)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b5310
		jmp eax
	}
}

