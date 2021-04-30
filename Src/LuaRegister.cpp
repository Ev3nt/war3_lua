#include "LuaRegister.h"
#include "Jass.h"

void lua_opencfunctions(lua_State* l)
{
	lua_register(l, "DebugS", lua_DebugS);
	lua_register(l, "DebugFI", lua_DebugFI);
	lua_register(l, "DebugUnitID", lua_DebugUnitID);
	lua_register(l, "DisplayText", lua_DisplayText);
	lua_register(l, "DisplayTextI", lua_DisplayTextI);
	lua_register(l, "DisplayTextII", lua_DisplayTextII);
	lua_register(l, "DisplayTextIII", lua_DisplayTextIII);
	lua_register(l, "SuicideUnit", lua_SuicideUnit);
	lua_register(l, "SuicideUnitEx", lua_SuicideUnitEx);
	lua_register(l, "Sleep", lua_Sleep);
	lua_register(l, "StartThread", lua_StartThread);
	lua_register(l, "GetAiPlayer", lua_GetAiPlayer);
	lua_register(l, "DoAiScriptDebug", lua_DoAiScriptDebug);
	lua_register(l, "GetHeroId", lua_GetHeroId);
	lua_register(l, "GetHeroLevelAI", lua_GetHeroLevelAI);
	lua_register(l, "SetHeroLevels", lua_SetHeroLevels);
	lua_register(l, "SetNewHeroes", lua_SetNewHeroes);
	lua_register(l, "GetUnitCount", lua_GetUnitCount);
	lua_register(l, "GetPlayerUnitTypeCount", lua_GetPlayerUnitTypeCount);
	lua_register(l, "GetTownUnitCount", lua_GetTownUnitCount);
	lua_register(l, "GetUnitCountDone", lua_GetUnitCountDone);
	lua_register(l, "GetUpgradeLevel", lua_GetUpgradeLevel);
	lua_register(l, "GetUnitGoldCost", lua_GetUnitGoldCost);
	lua_register(l, "GetUnitWoodCost", lua_GetUnitWoodCost);
	lua_register(l, "GetUnitBuildTime", lua_GetUnitBuildTime);
	lua_register(l, "GetUpgradeGoldCost", lua_GetUpgradeGoldCost);
	lua_register(l, "GetUpgradeWoodCost", lua_GetUpgradeWoodCost);
	lua_register(l, "GetEnemyPower", lua_GetEnemyPower);
	lua_register(l, "GetMinesOwned", lua_GetMinesOwned);
	lua_register(l, "GetGoldOwned", lua_GetGoldOwned);
	lua_register(l, "TownWithMine", lua_TownWithMine);
	lua_register(l, "TownHasMine", lua_TownHasMine);
	lua_register(l, "TownHasHall", lua_TownHasHall);
	lua_register(l, "GetNextExpansion", lua_GetNextExpansion);
	lua_register(l, "GetExpansionPeon", lua_GetExpansionPeon);
	lua_register(l, "GetEnemyExpansion", lua_GetEnemyExpansion);
	lua_register(l, "SetExpansion", lua_SetExpansion);
	lua_register(l, "GetBuilding", lua_GetBuilding);
	lua_register(l, "SetAllianceTarget", lua_SetAllianceTarget);
	lua_register(l, "GetAllianceTarget", lua_GetAllianceTarget);
	lua_register(l, "SetProduce", lua_SetProduce);
	lua_register(l, "MergeUnits", lua_MergeUnits);
	lua_register(l, "ConvertUnits", lua_ConvertUnits);
	lua_register(l, "SetUpgrade", lua_SetUpgrade);
	lua_register(l, "Unsummon", lua_Unsummon);
	lua_register(l, "ClearHarvestAI", lua_ClearHarvestAI);
	lua_register(l, "HarvestGold", lua_HarvestGold);
	lua_register(l, "HarvestWood", lua_HarvestWood);
	lua_register(l, "StopGathering", lua_StopGathering);
	lua_register(l, "AddGuardPost", lua_AddGuardPost);
	lua_register(l, "FillGuardPosts", lua_FillGuardPosts);
	lua_register(l, "ReturnGuardPosts", lua_ReturnGuardPosts);
	lua_register(l, "CreateCaptains", lua_CreateCaptains);
	lua_register(l, "SetCaptainHome", lua_SetCaptainHome);
	lua_register(l, "ResetCaptainLocs", lua_ResetCaptainLocs);
	lua_register(l, "ShiftTownSpot", lua_ShiftTownSpot);
	lua_register(l, "SetCaptainChanges", lua_SetCaptainChanges);
	lua_register(l, "TeleportCaptain", lua_TeleportCaptain);
	lua_register(l, "ClearCaptainTargets", lua_ClearCaptainTargets);
	lua_register(l, "CaptainVsUnits", lua_CaptainVsUnits);
	lua_register(l, "CaptainVsPlayer", lua_CaptainVsPlayer);
	lua_register(l, "CaptainAttack", lua_CaptainAttack);
	lua_register(l, "GroupTimedLife", lua_GroupTimedLife);
	lua_register(l, "CaptainGoHome", lua_CaptainGoHome);
	lua_register(l, "CaptainIsHome", lua_CaptainIsHome);
	lua_register(l, "CaptainRetreating", lua_CaptainRetreating);
	lua_register(l, "CaptainIsFull", lua_CaptainIsFull);
	lua_register(l, "CaptainIsEmpty", lua_CaptainIsEmpty);
	lua_register(l, "CaptainGroupSize", lua_CaptainGroupSize);
	lua_register(l, "CaptainReadiness", lua_CaptainReadiness);
	lua_register(l, "CaptainReadinessHP", lua_CaptainReadinessHP);
	lua_register(l, "CaptainReadinessMa", lua_CaptainReadinessMa);
	lua_register(l, "CaptainInCombat", lua_CaptainInCombat);
	lua_register(l, "TownThreatened", lua_TownThreatened);
	lua_register(l, "CaptainAtGoal", lua_CaptainAtGoal);
	lua_register(l, "CreepsOnMap", lua_CreepsOnMap);
	lua_register(l, "RemoveInjuries", lua_RemoveInjuries);
	lua_register(l, "RemoveSiege", lua_RemoveSiege);
	lua_register(l, "IsTowered", lua_IsTowered);
	lua_register(l, "DisablePathing", lua_DisablePathing);
	lua_register(l, "SetAmphibious", lua_SetAmphibious);
	lua_register(l, "InitAssault", lua_InitAssault);
	lua_register(l, "AddAssault", lua_AddAssault);
	lua_register(l, "AddDefenders", lua_AddDefenders);
	lua_register(l, "GetCreepCamp", lua_GetCreepCamp);
	lua_register(l, "StartGetEnemyBase", lua_StartGetEnemyBase);
	lua_register(l, "WaitGetEnemyBase", lua_WaitGetEnemyBase);
	lua_register(l, "GetMegaTarget", lua_GetMegaTarget);
	lua_register(l, "GetEnemyBase", lua_GetEnemyBase);
	lua_register(l, "GetExpansionFoe", lua_GetExpansionFoe);
	lua_register(l, "GetExpansionX", lua_GetExpansionX);
	lua_register(l, "GetExpansionY", lua_GetExpansionY);
	lua_register(l, "SetStagePoint", lua_SetStagePoint);
	lua_register(l, "AttackMoveKill", lua_AttackMoveKill);
	lua_register(l, "AttackMoveXY", lua_AttackMoveXY);
	lua_register(l, "LoadZepWave", lua_LoadZepWave);
	lua_register(l, "SuicidePlayer", lua_SuicidePlayer);
	lua_register(l, "SuicidePlayerUnits", lua_SuicidePlayerUnits);
	lua_register(l, "UnitAlive", lua_UnitAlive);
	lua_register(l, "UnitInvis", lua_UnitInvis);
	lua_register(l, "IgnoredUnits", lua_IgnoredUnits);
	lua_register(l, "CommandsWaiting", lua_CommandsWaiting);
	lua_register(l, "GetLastCommand", lua_GetLastCommand);
	lua_register(l, "GetLastData", lua_GetLastData);
	lua_register(l, "PopLastCommand", lua_PopLastCommand);
	lua_register(l, "SetCampaignAI", lua_SetCampaignAI);
	lua_register(l, "SetMeleeAI", lua_SetMeleeAI);
	lua_register(l, "SetTargetHeroes", lua_SetTargetHeroes);
	lua_register(l, "SetHeroesFlee", lua_SetHeroesFlee);
	lua_register(l, "SetHeroesBuyItems", lua_SetHeroesBuyItems);
	lua_register(l, "SetIgnoreInjured", lua_SetIgnoreInjured);
	lua_register(l, "SetPeonsRepair", lua_SetPeonsRepair);
	lua_register(l, "SetRandomPaths", lua_SetRandomPaths);
	lua_register(l, "SetDefendPlayer", lua_SetDefendPlayer);
	lua_register(l, "SetHeroesTakeItems", lua_SetHeroesTakeItems);
	lua_register(l, "SetUnitsFlee", lua_SetUnitsFlee);
	lua_register(l, "SetGroupsFlee", lua_SetGroupsFlee);
	lua_register(l, "SetSlowChopping", lua_SetSlowChopping);
	lua_register(l, "SetSmartArtillery", lua_SetSmartArtillery);
	lua_register(l, "SetWatchMegaTargets", lua_SetWatchMegaTargets);
	lua_register(l, "SetReplacementCount", lua_SetReplacementCount);
	lua_register(l, "PurchaseZeppelin", lua_PurchaseZeppelin);
	lua_register(l, "MeleeDifficulty", lua_MeleeDifficulty);
	lua_register(l, "DebugBreak", lua_DebugBreak);
	lua_register(l, "Deg2Rad", lua_Deg2Rad);
	lua_register(l, "Rad2Deg", lua_Rad2Deg);
	lua_register(l, "Sin", lua_Sin);
	lua_register(l, "Cos", lua_Cos);
	lua_register(l, "Tan", lua_Tan);
	lua_register(l, "Asin", lua_Asin);
	lua_register(l, "Acos", lua_Acos);
	lua_register(l, "Atan", lua_Atan);
	lua_register(l, "Atan2", lua_Atan2);
	lua_register(l, "SquareRoot", lua_SquareRoot);
	lua_register(l, "Pow", lua_Pow);
	lua_register(l, "I2R", lua_I2R);
	lua_register(l, "R2I", lua_R2I);
	lua_register(l, "I2S", lua_I2S);
	lua_register(l, "R2S", lua_R2S);
	lua_register(l, "R2SW", lua_R2SW);
	lua_register(l, "S2I", lua_S2I);
	lua_register(l, "S2R", lua_S2R);
	lua_register(l, "GetHandleId", lua_GetHandleId);
	lua_register(l, "SubString", lua_SubString);
	lua_register(l, "StringLength", lua_StringLength);
	lua_register(l, "StringCase", lua_StringCase);
	lua_register(l, "StringHash", lua_StringHash);
	lua_register(l, "GetLocalizedString", lua_GetLocalizedString);
	lua_register(l, "GetLocalizedHotkey", lua_GetLocalizedHotkey);
	lua_register(l, "ConvertRace", lua_ConvertRace);
	lua_register(l, "ConvertAllianceType", lua_ConvertAllianceType);
	lua_register(l, "ConvertRacePref", lua_ConvertRacePref);
	lua_register(l, "ConvertIGameState", lua_ConvertIGameState);
	lua_register(l, "ConvertFGameState", lua_ConvertFGameState);
	lua_register(l, "ConvertPlayerState", lua_ConvertPlayerState);
	lua_register(l, "ConvertPlayerScore", lua_ConvertPlayerScore);
	lua_register(l, "ConvertStartLocPrio", lua_ConvertStartLocPrio);
	lua_register(l, "ConvertPlayerGameResult", lua_ConvertPlayerGameResult);
	lua_register(l, "ConvertUnitState", lua_ConvertUnitState);
	lua_register(l, "ConvertAIDifficulty", lua_ConvertAIDifficulty);
	lua_register(l, "ConvertGameEvent", lua_ConvertGameEvent);
	lua_register(l, "ConvertPlayerEvent", lua_ConvertPlayerEvent);
	lua_register(l, "ConvertPlayerUnitEvent", lua_ConvertPlayerUnitEvent);
	lua_register(l, "ConvertUnitEvent", lua_ConvertUnitEvent);
	lua_register(l, "ConvertWidgetEvent", lua_ConvertWidgetEvent);
	lua_register(l, "ConvertDialogEvent", lua_ConvertDialogEvent);
	lua_register(l, "ConvertLimitOp", lua_ConvertLimitOp);
	lua_register(l, "ConvertUnitType", lua_ConvertUnitType);
	lua_register(l, "ConvertGameSpeed", lua_ConvertGameSpeed);
	lua_register(l, "ConvertPlacement", lua_ConvertPlacement);
	lua_register(l, "ConvertGameDifficulty", lua_ConvertGameDifficulty);
	lua_register(l, "ConvertGameType", lua_ConvertGameType);
	lua_register(l, "ConvertMapFlag", lua_ConvertMapFlag);
	lua_register(l, "ConvertMapVisibility", lua_ConvertMapVisibility);
	lua_register(l, "ConvertMapSetting", lua_ConvertMapSetting);
	lua_register(l, "ConvertMapDensity", lua_ConvertMapDensity);
	lua_register(l, "ConvertMapControl", lua_ConvertMapControl);
	lua_register(l, "ConvertPlayerColor", lua_ConvertPlayerColor);
	lua_register(l, "ConvertPlayerSlotState", lua_ConvertPlayerSlotState);
	lua_register(l, "ConvertVolumeGroup", lua_ConvertVolumeGroup);
	lua_register(l, "ConvertCameraField", lua_ConvertCameraField);
	lua_register(l, "ConvertBlendMode", lua_ConvertBlendMode);
	lua_register(l, "ConvertRarityControl", lua_ConvertRarityControl);
	lua_register(l, "ConvertTexMapFlags", lua_ConvertTexMapFlags);
	lua_register(l, "ConvertFogState", lua_ConvertFogState);
	lua_register(l, "ConvertEffectType", lua_ConvertEffectType);
	lua_register(l, "ConvertVersion", lua_ConvertVersion);
	lua_register(l, "ConvertItemType", lua_ConvertItemType);
	lua_register(l, "ConvertAttackType", lua_ConvertAttackType);
	lua_register(l, "ConvertDamageType", lua_ConvertDamageType);
	lua_register(l, "ConvertWeaponType", lua_ConvertWeaponType);
	lua_register(l, "ConvertSoundType", lua_ConvertSoundType);
	lua_register(l, "ConvertPathingType", lua_ConvertPathingType);
	lua_register(l, "SetMapName", lua_SetMapName);
	lua_register(l, "SetMapDescription", lua_SetMapDescription);
	lua_register(l, "SetTeams", lua_SetTeams);
	lua_register(l, "SetPlayers", lua_SetPlayers);
	lua_register(l, "SetGameTypeSupported", lua_SetGameTypeSupported);
	lua_register(l, "SetMapFlag", lua_SetMapFlag);
	lua_register(l, "SetGameSpeed", lua_SetGameSpeed);
	lua_register(l, "SetGamePlacement", lua_SetGamePlacement);
	lua_register(l, "SetGameDifficulty", lua_SetGameDifficulty);
	lua_register(l, "SetResourceDensity", lua_SetResourceDensity);
	lua_register(l, "SetCreatureDensity", lua_SetCreatureDensity);
	lua_register(l, "DefineStartLocation", lua_DefineStartLocation);
	lua_register(l, "DefineStartLocationLoc", lua_DefineStartLocationLoc);
	lua_register(l, "SetStartLocPrioCount", lua_SetStartLocPrioCount);
	lua_register(l, "SetStartLocPrio", lua_SetStartLocPrio);
	lua_register(l, "GetStartLocPrioSlot", lua_GetStartLocPrioSlot);
	lua_register(l, "GetStartLocPrio", lua_GetStartLocPrio);
	lua_register(l, "GetTeams", lua_GetTeams);
	lua_register(l, "GetPlayers", lua_GetPlayers);
	lua_register(l, "IsGameTypeSupported", lua_IsGameTypeSupported);
	lua_register(l, "IsMapFlagSet", lua_IsMapFlagSet);
	lua_register(l, "GetGameTypeSelected", lua_GetGameTypeSelected);
	lua_register(l, "GetGamePlacement", lua_GetGamePlacement);
	lua_register(l, "GetGameSpeed", lua_GetGameSpeed);
	lua_register(l, "GetGameDifficulty", lua_GetGameDifficulty);
	lua_register(l, "GetResourceDensity", lua_GetResourceDensity);
	lua_register(l, "GetCreatureDensity", lua_GetCreatureDensity);
	lua_register(l, "GetStartLocationX", lua_GetStartLocationX);
	lua_register(l, "GetStartLocationY", lua_GetStartLocationY);
	lua_register(l, "GetStartLocationLoc", lua_GetStartLocationLoc);
	lua_register(l, "SetPlayerTeam", lua_SetPlayerTeam);
	lua_register(l, "SetPlayerStartLocation", lua_SetPlayerStartLocation);
	lua_register(l, "ForcePlayerStartLocation", lua_ForcePlayerStartLocation);
	lua_register(l, "SetPlayerAlliance", lua_SetPlayerAlliance);
	lua_register(l, "SetPlayerTaxRate", lua_SetPlayerTaxRate);
	lua_register(l, "SetPlayerRacePreference", lua_SetPlayerRacePreference);
	lua_register(l, "SetPlayerRaceSelectable", lua_SetPlayerRaceSelectable);
	lua_register(l, "SetPlayerController", lua_SetPlayerController);
	lua_register(l, "SetPlayerColor", lua_SetPlayerColor);
	lua_register(l, "SetPlayerOnScoreScreen", lua_SetPlayerOnScoreScreen);
	lua_register(l, "SetPlayerName", lua_SetPlayerName);
	lua_register(l, "GetPlayerTeam", lua_GetPlayerTeam);
	lua_register(l, "GetPlayerName", lua_GetPlayerName);
	lua_register(l, "GetPlayerStartLocation", lua_GetPlayerStartLocation);
	lua_register(l, "GetPlayerStartLocationX", lua_GetPlayerStartLocationX);
	lua_register(l, "GetPlayerStartLocationY", lua_GetPlayerStartLocationY);
	lua_register(l, "GetPlayerColor", lua_GetPlayerColor);
	lua_register(l, "GetPlayerSelectable", lua_GetPlayerSelectable);
	lua_register(l, "GetPlayerController", lua_GetPlayerController);
	lua_register(l, "GetPlayerSlotState", lua_GetPlayerSlotState);
	lua_register(l, "GetPlayerTaxRate", lua_GetPlayerTaxRate);
	lua_register(l, "IsPlayerRacePrefSet", lua_IsPlayerRacePrefSet);
	lua_register(l, "Location", lua_Location);
	lua_register(l, "RemoveLocation", lua_RemoveLocation);
	lua_register(l, "MoveLocation", lua_MoveLocation);
	lua_register(l, "GetLocationX", lua_GetLocationX);
	lua_register(l, "GetLocationY", lua_GetLocationY);
	lua_register(l, "GetLocationZ", lua_GetLocationZ);
	lua_register(l, "CreateTimer", lua_CreateTimer);
	lua_register(l, "DestroyTimer", lua_DestroyTimer);
	lua_register(l, "TimerStart", lua_TimerStart);
	lua_register(l, "TimerGetTimeout", lua_TimerGetTimeout);
	lua_register(l, "TimerGetElapsed", lua_TimerGetElapsed);
	lua_register(l, "TimerGetRemaining", lua_TimerGetRemaining);
	lua_register(l, "PauseTimer", lua_PauseTimer);
	lua_register(l, "ResumeTimer", lua_ResumeTimer);
	lua_register(l, "GetExpiredTimer", lua_GetExpiredTimer);
	lua_register(l, "Condition", lua_Condition);
	lua_register(l, "DestroyCondition", lua_DestroyCondition);
	lua_register(l, "Filter", lua_Filter);
	lua_register(l, "DestroyFilter", lua_DestroyFilter);
	lua_register(l, "DestroyBoolExpr", lua_DestroyBoolExpr);
	lua_register(l, "And", lua_And);
	lua_register(l, "Or", lua_Or);
	lua_register(l, "Not", lua_Not);
	lua_register(l, "CreateRegion", lua_CreateRegion);
	lua_register(l, "RemoveRegion", lua_RemoveRegion);
	lua_register(l, "RegionAddRect", lua_RegionAddRect);
	lua_register(l, "RegionClearRect", lua_RegionClearRect);
	lua_register(l, "RegionAddCell", lua_RegionAddCell);
	lua_register(l, "RegionAddCellAtLoc", lua_RegionAddCellAtLoc);
	lua_register(l, "RegionClearCell", lua_RegionClearCell);
	lua_register(l, "RegionClearCellAtLoc", lua_RegionClearCellAtLoc);
	lua_register(l, "IsUnitInRegion", lua_IsUnitInRegion);
	lua_register(l, "IsPointInRegion", lua_IsPointInRegion);
	lua_register(l, "IsLocationInRegion", lua_IsLocationInRegion);
	lua_register(l, "Rect", lua_Rect);
	lua_register(l, "RectFromLoc", lua_RectFromLoc);
	lua_register(l, "RemoveRect", lua_RemoveRect);
	lua_register(l, "SetRect", lua_SetRect);
	lua_register(l, "SetRectFromLoc", lua_SetRectFromLoc);
	lua_register(l, "GetRectCenterX", lua_GetRectCenterX);
	lua_register(l, "GetRectCenterY", lua_GetRectCenterY);
	lua_register(l, "MoveRectTo", lua_MoveRectTo);
	lua_register(l, "MoveRectToLoc", lua_MoveRectToLoc);
	lua_register(l, "GetRectMinX", lua_GetRectMinX);
	lua_register(l, "GetRectMinY", lua_GetRectMinY);
	lua_register(l, "GetRectMaxX", lua_GetRectMaxX);
	lua_register(l, "GetRectMaxY", lua_GetRectMaxY);
	lua_register(l, "GetWorldBounds", lua_GetWorldBounds);
	lua_register(l, "SetFogStateRect", lua_SetFogStateRect);
	lua_register(l, "SetFogStateRadius", lua_SetFogStateRadius);
	lua_register(l, "SetFogStateRadiusLoc", lua_SetFogStateRadiusLoc);
	lua_register(l, "FogMaskEnable", lua_FogMaskEnable);
	lua_register(l, "IsFogMaskEnabled", lua_IsFogMaskEnabled);
	lua_register(l, "FogEnable", lua_FogEnable);
	lua_register(l, "IsFogEnabled", lua_IsFogEnabled);
	lua_register(l, "CreateFogModifierRect", lua_CreateFogModifierRect);
	lua_register(l, "CreateFogModifierRadius", lua_CreateFogModifierRadius);
	lua_register(l, "CreateFogModifierRadiusLoc", lua_CreateFogModifierRadiusLoc);
	lua_register(l, "DestroyFogModifier", lua_DestroyFogModifier);
	lua_register(l, "FogModifierStart", lua_FogModifierStart);
	lua_register(l, "FogModifierStop", lua_FogModifierStop);
	lua_register(l, "CreateTrigger", lua_CreateTrigger);
	lua_register(l, "DestroyTrigger", lua_DestroyTrigger);
	lua_register(l, "ResetTrigger", lua_ResetTrigger);
	lua_register(l, "EnableTrigger", lua_EnableTrigger);
	lua_register(l, "DisableTrigger", lua_DisableTrigger);
	lua_register(l, "IsTriggerEnabled", lua_IsTriggerEnabled);
	lua_register(l, "TriggerWaitOnSleeps", lua_TriggerWaitOnSleeps);
	lua_register(l, "IsTriggerWaitOnSleeps", lua_IsTriggerWaitOnSleeps);
	lua_register(l, "TriggerRegisterVariableEvent", lua_TriggerRegisterVariableEvent);
	lua_register(l, "TriggerRegisterTimerEvent", lua_TriggerRegisterTimerEvent);
	lua_register(l, "TriggerRegisterTimerExpireEvent", lua_TriggerRegisterTimerExpireEvent);
	lua_register(l, "TriggerRegisterGameStateEvent", lua_TriggerRegisterGameStateEvent);
	lua_register(l, "GetEventGameState", lua_GetEventGameState);
	lua_register(l, "TriggerRegisterDialogEvent", lua_TriggerRegisterDialogEvent);
	lua_register(l, "TriggerRegisterDialogButtonEvent", lua_TriggerRegisterDialogButtonEvent);
	lua_register(l, "GetClickedButton", lua_GetClickedButton);
	lua_register(l, "GetClickedDialog", lua_GetClickedDialog);
	lua_register(l, "GetTournamentFinishSoonTimeRemaining", lua_GetTournamentFinishSoonTimeRemaining);
	lua_register(l, "GetTournamentFinishNowRule", lua_GetTournamentFinishNowRule);
	lua_register(l, "GetTournamentFinishNowPlayer", lua_GetTournamentFinishNowPlayer);
	lua_register(l, "GetTournamentScore", lua_GetTournamentScore);
	lua_register(l, "GetSaveBasicFilename", lua_GetSaveBasicFilename);
	lua_register(l, "TriggerRegisterGameEvent", lua_TriggerRegisterGameEvent);
	lua_register(l, "GetWinningPlayer", lua_GetWinningPlayer);
	lua_register(l, "TriggerRegisterPlayerStateEvent", lua_TriggerRegisterPlayerStateEvent);
	lua_register(l, "GetEventPlayerState", lua_GetEventPlayerState);
	lua_register(l, "TriggerRegisterPlayerEvent", lua_TriggerRegisterPlayerEvent);
	lua_register(l, "TriggerRegisterPlayerUnitEvent", lua_TriggerRegisterPlayerUnitEvent);
	lua_register(l, "GetAttacker", lua_GetAttacker);
	lua_register(l, "GetRescuer", lua_GetRescuer);
	lua_register(l, "GetDyingUnit", lua_GetDyingUnit);
	lua_register(l, "GetKillingUnit", lua_GetKillingUnit);
	lua_register(l, "GetDecayingUnit", lua_GetDecayingUnit);
	lua_register(l, "GetConstructingStructure", lua_GetConstructingStructure);
	lua_register(l, "GetCancelledStructure", lua_GetCancelledStructure);
	lua_register(l, "GetConstructedStructure", lua_GetConstructedStructure);
	lua_register(l, "GetTrainedUnitType", lua_GetTrainedUnitType);
	lua_register(l, "GetResearchingUnit", lua_GetResearchingUnit);
	lua_register(l, "GetResearched", lua_GetResearched);
	lua_register(l, "GetTrainedUnit", lua_GetTrainedUnit);
	lua_register(l, "GetSellingUnit", lua_GetSellingUnit);
	lua_register(l, "GetSoldUnit", lua_GetSoldUnit);
	lua_register(l, "GetBuyingUnit", lua_GetBuyingUnit);
	lua_register(l, "GetSoldItem", lua_GetSoldItem);
	lua_register(l, "GetChangingUnit", lua_GetChangingUnit);
	lua_register(l, "GetChangingUnitPrevOwner", lua_GetChangingUnitPrevOwner);
	lua_register(l, "GetDetectedUnit", lua_GetDetectedUnit);
	lua_register(l, "GetOrderedUnit", lua_GetOrderedUnit);
	lua_register(l, "OrderId", lua_OrderId);
	lua_register(l, "OrderId2String", lua_OrderId2String);
	lua_register(l, "AbilityId", lua_AbilityId);
	lua_register(l, "AbilityId2String", lua_AbilityId2String);
	lua_register(l, "UnitId", lua_UnitId);
	lua_register(l, "UnitId2String", lua_UnitId2String);
	lua_register(l, "GetObjectName", lua_GetObjectName);
	lua_register(l, "GetIssuedOrderId", lua_GetIssuedOrderId);
	lua_register(l, "GetOrderPointX", lua_GetOrderPointX);
	lua_register(l, "GetOrderPointY", lua_GetOrderPointY);
	lua_register(l, "GetOrderPointLoc", lua_GetOrderPointLoc);
	lua_register(l, "GetOrderTarget", lua_GetOrderTarget);
	lua_register(l, "GetOrderTargetDestructable", lua_GetOrderTargetDestructable);
	lua_register(l, "GetOrderTargetItem", lua_GetOrderTargetItem);
	lua_register(l, "GetOrderTargetUnit", lua_GetOrderTargetUnit);
	lua_register(l, "GetSpellAbilityUnit", lua_GetSpellAbilityUnit);
	lua_register(l, "GetSpellAbilityId", lua_GetSpellAbilityId);
	lua_register(l, "GetSpellAbility", lua_GetSpellAbility);
	lua_register(l, "GetSpellTargetLoc", lua_GetSpellTargetLoc);
	lua_register(l, "GetSpellTargetX", lua_GetSpellTargetX);
	lua_register(l, "GetSpellTargetY", lua_GetSpellTargetY);
	lua_register(l, "GetSpellTargetDestructable", lua_GetSpellTargetDestructable);
	lua_register(l, "GetSpellTargetItem", lua_GetSpellTargetItem);
	lua_register(l, "GetSpellTargetUnit", lua_GetSpellTargetUnit);
	lua_register(l, "GetLevelingUnit", lua_GetLevelingUnit);
	lua_register(l, "GetLearningUnit", lua_GetLearningUnit);
	lua_register(l, "GetLearnedSkill", lua_GetLearnedSkill);
	lua_register(l, "GetLearnedSkillLevel", lua_GetLearnedSkillLevel);
	lua_register(l, "GetRevivableUnit", lua_GetRevivableUnit);
	lua_register(l, "GetRevivingUnit", lua_GetRevivingUnit);
	lua_register(l, "GetSummoningUnit", lua_GetSummoningUnit);
	lua_register(l, "GetSummonedUnit", lua_GetSummonedUnit);
	lua_register(l, "GetTransportUnit", lua_GetTransportUnit);
	lua_register(l, "GetLoadedUnit", lua_GetLoadedUnit);
	lua_register(l, "GetManipulatingUnit", lua_GetManipulatingUnit);
	lua_register(l, "GetManipulatedItem", lua_GetManipulatedItem);
	lua_register(l, "TriggerRegisterPlayerAllianceChange", lua_TriggerRegisterPlayerAllianceChange);
	lua_register(l, "TriggerRegisterPlayerChatEvent", lua_TriggerRegisterPlayerChatEvent);
	lua_register(l, "GetEventPlayerChatString", lua_GetEventPlayerChatString);
	lua_register(l, "GetEventPlayerChatStringMatched", lua_GetEventPlayerChatStringMatched);
	lua_register(l, "TriggerRegisterUnitStateEvent", lua_TriggerRegisterUnitStateEvent);
	lua_register(l, "GetEventUnitState", lua_GetEventUnitState);
	lua_register(l, "TriggerRegisterDeathEvent", lua_TriggerRegisterDeathEvent);
	lua_register(l, "TriggerRegisterUnitEvent", lua_TriggerRegisterUnitEvent);
	lua_register(l, "GetEventDamage", lua_GetEventDamage);
	lua_register(l, "GetEventDamageSource", lua_GetEventDamageSource);
	lua_register(l, "GetEventDetectingPlayer", lua_GetEventDetectingPlayer);
	lua_register(l, "GetEventTargetUnit", lua_GetEventTargetUnit);
	lua_register(l, "TriggerRegisterFilterUnitEvent", lua_TriggerRegisterFilterUnitEvent);
	lua_register(l, "TriggerRegisterUnitInRange", lua_TriggerRegisterUnitInRange);
	lua_register(l, "TriggerRegisterEnterRegion", lua_TriggerRegisterEnterRegion);
	lua_register(l, "TriggerRegisterLeaveRegion", lua_TriggerRegisterLeaveRegion);
	lua_register(l, "GetTriggeringRegion", lua_GetTriggeringRegion);
	lua_register(l, "GetEnteringUnit", lua_GetEnteringUnit);
	lua_register(l, "GetLeavingUnit", lua_GetLeavingUnit);
	lua_register(l, "TriggerAddCondition", lua_TriggerAddCondition);
	lua_register(l, "TriggerRemoveCondition", lua_TriggerRemoveCondition);
	lua_register(l, "TriggerClearConditions", lua_TriggerClearConditions);
	lua_register(l, "TriggerAddAction", lua_TriggerAddAction);
	lua_register(l, "TriggerRemoveAction", lua_TriggerRemoveAction);
	lua_register(l, "TriggerClearActions", lua_TriggerClearActions);
	lua_register(l, "TriggerSleepAction", lua_TriggerSleepAction);
	lua_register(l, "TriggerWaitForSound", lua_TriggerWaitForSound);
	lua_register(l, "TriggerExecute", lua_TriggerExecute);
	lua_register(l, "TriggerExecuteWait", lua_TriggerExecuteWait);
	lua_register(l, "TriggerEvaluate", lua_TriggerEvaluate);
	lua_register(l, "TriggerSyncStart", lua_TriggerSyncStart);
	lua_register(l, "TriggerSyncReady", lua_TriggerSyncReady);
	lua_register(l, "GetTriggerWidget", lua_GetTriggerWidget);
	lua_register(l, "GetTriggerDestructable", lua_GetTriggerDestructable);
	lua_register(l, "GetTriggerUnit", lua_GetTriggerUnit);
	lua_register(l, "GetTriggerPlayer", lua_GetTriggerPlayer);
	lua_register(l, "GetTriggeringTrigger", lua_GetTriggeringTrigger);
	lua_register(l, "GetTriggerEventId", lua_GetTriggerEventId);
	lua_register(l, "GetTriggerEvalCount", lua_GetTriggerEvalCount);
	lua_register(l, "GetTriggerExecCount", lua_GetTriggerExecCount);
	lua_register(l, "GetFilterUnit", lua_GetFilterUnit);
	lua_register(l, "GetEnumUnit", lua_GetEnumUnit);
	lua_register(l, "GetEnumPlayer", lua_GetEnumPlayer);
	lua_register(l, "GetFilterPlayer", lua_GetFilterPlayer);
	lua_register(l, "GetFilterDestructable", lua_GetFilterDestructable);
	lua_register(l, "GetEnumDestructable", lua_GetEnumDestructable);
	lua_register(l, "GetFilterItem", lua_GetFilterItem);
	lua_register(l, "GetEnumItem", lua_GetEnumItem);
	lua_register(l, "CreateGroup", lua_CreateGroup);
	lua_register(l, "DestroyGroup", lua_DestroyGroup);
	lua_register(l, "GroupAddUnit", lua_GroupAddUnit);
	lua_register(l, "GroupRemoveUnit", lua_GroupRemoveUnit);
	lua_register(l, "GroupClear", lua_GroupClear);
	lua_register(l, "GroupEnumUnitsOfType", lua_GroupEnumUnitsOfType);
	lua_register(l, "GroupEnumUnitsOfTypeCounted", lua_GroupEnumUnitsOfTypeCounted);
	lua_register(l, "GroupEnumUnitsInRect", lua_GroupEnumUnitsInRect);
	lua_register(l, "GroupEnumUnitsInRectCounted", lua_GroupEnumUnitsInRectCounted);
	lua_register(l, "GroupEnumUnitsOfPlayer", lua_GroupEnumUnitsOfPlayer);
	lua_register(l, "GroupEnumUnitsInRange", lua_GroupEnumUnitsInRange);
	lua_register(l, "GroupEnumUnitsInRangeOfLoc", lua_GroupEnumUnitsInRangeOfLoc);
	lua_register(l, "GroupEnumUnitsInRangeCounted", lua_GroupEnumUnitsInRangeCounted);
	lua_register(l, "GroupEnumUnitsInRangeOfLocCounted", lua_GroupEnumUnitsInRangeOfLocCounted);
	lua_register(l, "GroupEnumUnitsSelected", lua_GroupEnumUnitsSelected);
	lua_register(l, "GroupImmediateOrder", lua_GroupImmediateOrder);
	lua_register(l, "GroupImmediateOrderById", lua_GroupImmediateOrderById);
	lua_register(l, "GroupPointOrder", lua_GroupPointOrder);
	lua_register(l, "GroupPointOrderLoc", lua_GroupPointOrderLoc);
	lua_register(l, "GroupPointOrderById", lua_GroupPointOrderById);
	lua_register(l, "GroupPointOrderByIdLoc", lua_GroupPointOrderByIdLoc);
	lua_register(l, "GroupTargetOrder", lua_GroupTargetOrder);
	lua_register(l, "GroupTargetOrderById", lua_GroupTargetOrderById);
	lua_register(l, "ForGroup", lua_ForGroup);
	lua_register(l, "FirstOfGroup", lua_FirstOfGroup);
	lua_register(l, "CreateForce", lua_CreateForce);
	lua_register(l, "DestroyForce", lua_DestroyForce);
	lua_register(l, "ForceAddPlayer", lua_ForceAddPlayer);
	lua_register(l, "ForceRemovePlayer", lua_ForceRemovePlayer);
	lua_register(l, "ForceClear", lua_ForceClear);
	lua_register(l, "ForceEnumPlayers", lua_ForceEnumPlayers);
	lua_register(l, "ForceEnumPlayersCounted", lua_ForceEnumPlayersCounted);
	lua_register(l, "ForceEnumAllies", lua_ForceEnumAllies);
	lua_register(l, "ForceEnumEnemies", lua_ForceEnumEnemies);
	lua_register(l, "ForForce", lua_ForForce);
	lua_register(l, "GetWidgetLife", lua_GetWidgetLife);
	lua_register(l, "SetWidgetLife", lua_SetWidgetLife);
	lua_register(l, "GetWidgetX", lua_GetWidgetX);
	lua_register(l, "GetWidgetY", lua_GetWidgetY);
	lua_register(l, "CreateDestructable", lua_CreateDestructable);
	lua_register(l, "CreateDestructableZ", lua_CreateDestructableZ);
	lua_register(l, "CreateDeadDestructable", lua_CreateDeadDestructable);
	lua_register(l, "CreateDeadDestructableZ", lua_CreateDeadDestructableZ);
	lua_register(l, "RemoveDestructable", lua_RemoveDestructable);
	lua_register(l, "KillDestructable", lua_KillDestructable);
	lua_register(l, "SetDestructableInvulnerable", lua_SetDestructableInvulnerable);
	lua_register(l, "IsDestructableInvulnerable", lua_IsDestructableInvulnerable);
	lua_register(l, "EnumDestructablesInRect", lua_EnumDestructablesInRect);
	lua_register(l, "GetDestructableTypeId", lua_GetDestructableTypeId);
	lua_register(l, "GetDestructableX", lua_GetDestructableX);
	lua_register(l, "GetDestructableY", lua_GetDestructableY);
	lua_register(l, "SetDestructableLife", lua_SetDestructableLife);
	lua_register(l, "GetDestructableLife", lua_GetDestructableLife);
	lua_register(l, "SetDestructableMaxLife", lua_SetDestructableMaxLife);
	lua_register(l, "GetDestructableMaxLife", lua_GetDestructableMaxLife);
	lua_register(l, "DestructableRestoreLife", lua_DestructableRestoreLife);
	lua_register(l, "QueueDestructableAnimation", lua_QueueDestructableAnimation);
	lua_register(l, "SetDestructableAnimation", lua_SetDestructableAnimation);
	lua_register(l, "SetDestructableAnimationSpeed", lua_SetDestructableAnimationSpeed);
	lua_register(l, "ShowDestructable", lua_ShowDestructable);
	lua_register(l, "GetDestructableOccluderHeight", lua_GetDestructableOccluderHeight);
	lua_register(l, "SetDestructableOccluderHeight", lua_SetDestructableOccluderHeight);
	lua_register(l, "GetDestructableName", lua_GetDestructableName);
	lua_register(l, "CreateUnit", lua_CreateUnit);
	lua_register(l, "CreateUnitByName", lua_CreateUnitByName);
	lua_register(l, "CreateUnitAtLoc", lua_CreateUnitAtLoc);
	lua_register(l, "CreateUnitAtLocByName", lua_CreateUnitAtLocByName);
	lua_register(l, "CreateCorpse", lua_CreateCorpse);
	lua_register(l, "GetUnitState", lua_GetUnitState);
	lua_register(l, "GetUnitFoodUsed", lua_GetUnitFoodUsed);
	lua_register(l, "GetUnitFoodMade", lua_GetUnitFoodMade);
	lua_register(l, "GetFoodMade", lua_GetFoodMade);
	lua_register(l, "GetFoodUsed", lua_GetFoodUsed);
	lua_register(l, "SetUnitUseFood", lua_SetUnitUseFood);
	lua_register(l, "GetUnitX", lua_GetUnitX);
	lua_register(l, "GetUnitY", lua_GetUnitY);
	lua_register(l, "GetUnitLoc", lua_GetUnitLoc);
	lua_register(l, "GetUnitRallyPoint", lua_GetUnitRallyPoint);
	lua_register(l, "GetUnitRallyUnit", lua_GetUnitRallyUnit);
	lua_register(l, "GetUnitRallyDestructable", lua_GetUnitRallyDestructable);
	lua_register(l, "GetUnitFacing", lua_GetUnitFacing);
	lua_register(l, "GetUnitMoveSpeed", lua_GetUnitMoveSpeed);
	lua_register(l, "GetUnitDefaultMoveSpeed", lua_GetUnitDefaultMoveSpeed);
	lua_register(l, "GetUnitTypeId", lua_GetUnitTypeId);
	lua_register(l, "GetUnitRace", lua_GetUnitRace);
	lua_register(l, "GetUnitName", lua_GetUnitName);
	lua_register(l, "GetUnitPointValue", lua_GetUnitPointValue);
	lua_register(l, "GetUnitPointValueByType", lua_GetUnitPointValueByType);
	lua_register(l, "SetUnitX", lua_SetUnitX);
	lua_register(l, "SetUnitY", lua_SetUnitY);
	lua_register(l, "SetUnitPosition", lua_SetUnitPosition);
	lua_register(l, "SetUnitPositionLoc", lua_SetUnitPositionLoc);
	lua_register(l, "SetUnitFacing", lua_SetUnitFacing);
	lua_register(l, "SetUnitFacingTimed", lua_SetUnitFacingTimed);
	lua_register(l, "SetUnitFlyHeight", lua_SetUnitFlyHeight);
	lua_register(l, "SetUnitMoveSpeed", lua_SetUnitMoveSpeed);
	lua_register(l, "SetUnitTurnSpeed", lua_SetUnitTurnSpeed);
	lua_register(l, "SetUnitPropWindow", lua_SetUnitPropWindow);
	lua_register(l, "SetUnitCreepGuard", lua_SetUnitCreepGuard);
	lua_register(l, "GetUnitAcquireRange", lua_GetUnitAcquireRange);
	lua_register(l, "GetUnitTurnSpeed", lua_GetUnitTurnSpeed);
	lua_register(l, "GetUnitPropWindow", lua_GetUnitPropWindow);
	lua_register(l, "GetUnitFlyHeight", lua_GetUnitFlyHeight);
	lua_register(l, "GetUnitDefaultAcquireRange", lua_GetUnitDefaultAcquireRange);
	lua_register(l, "GetUnitDefaultTurnSpeed", lua_GetUnitDefaultTurnSpeed);
	lua_register(l, "GetUnitDefaultPropWindow", lua_GetUnitDefaultPropWindow);
	lua_register(l, "GetUnitDefaultFlyHeight", lua_GetUnitDefaultFlyHeight);
	lua_register(l, "SetUnitAcquireRange", lua_SetUnitAcquireRange);
	lua_register(l, "SetUnitState", lua_SetUnitState);
	lua_register(l, "SetUnitOwner", lua_SetUnitOwner);
	lua_register(l, "SetUnitRescuable", lua_SetUnitRescuable);
	lua_register(l, "SetUnitRescueRange", lua_SetUnitRescueRange);
	lua_register(l, "SetUnitColor", lua_SetUnitColor);
	lua_register(l, "QueueUnitAnimation", lua_QueueUnitAnimation);
	lua_register(l, "SetUnitAnimation", lua_SetUnitAnimation);
	lua_register(l, "SetUnitAnimationWithRarity", lua_SetUnitAnimationWithRarity);
	lua_register(l, "SetUnitAnimationByIndex", lua_SetUnitAnimationByIndex);
	lua_register(l, "AddUnitAnimationProperties", lua_AddUnitAnimationProperties);
	lua_register(l, "SetUnitScale", lua_SetUnitScale);
	lua_register(l, "SetUnitTimeScale", lua_SetUnitTimeScale);
	lua_register(l, "SetUnitBlendTime", lua_SetUnitBlendTime);
	lua_register(l, "SetUnitVertexColor", lua_SetUnitVertexColor);
	lua_register(l, "SetUnitLookAt", lua_SetUnitLookAt);
	lua_register(l, "SetUnitPathing", lua_SetUnitPathing);
	lua_register(l, "ResetUnitLookAt", lua_ResetUnitLookAt);
	lua_register(l, "SetHeroStr", lua_SetHeroStr);
	lua_register(l, "SetHeroAgi", lua_SetHeroAgi);
	lua_register(l, "SetHeroInt", lua_SetHeroInt);
	lua_register(l, "GetHeroStr", lua_GetHeroStr);
	lua_register(l, "GetHeroAgi", lua_GetHeroAgi);
	lua_register(l, "GetHeroInt", lua_GetHeroInt);
	lua_register(l, "GetHeroSkillPoints", lua_GetHeroSkillPoints);
	lua_register(l, "UnitStripHeroLevel", lua_UnitStripHeroLevel);
	lua_register(l, "UnitModifySkillPoints", lua_UnitModifySkillPoints);
	lua_register(l, "GetHeroXP", lua_GetHeroXP);
	lua_register(l, "SetHeroXP", lua_SetHeroXP);
	lua_register(l, "AddHeroXP", lua_AddHeroXP);
	lua_register(l, "SetHeroLevel", lua_SetHeroLevel);
	lua_register(l, "GetHeroLevel", lua_GetHeroLevel);
	lua_register(l, "GetUnitLevel", lua_GetUnitLevel);
	lua_register(l, "GetHeroProperName", lua_GetHeroProperName);
	lua_register(l, "SuspendHeroXP", lua_SuspendHeroXP);
	lua_register(l, "IsSuspendedXP", lua_IsSuspendedXP);
	lua_register(l, "SelectHeroSkill", lua_SelectHeroSkill);
	lua_register(l, "GetUnitAbilityLevel", lua_GetUnitAbilityLevel);
	lua_register(l, "ReviveHero", lua_ReviveHero);
	lua_register(l, "ReviveHeroLoc", lua_ReviveHeroLoc);
	lua_register(l, "SetUnitExploded", lua_SetUnitExploded);
	lua_register(l, "SetUnitInvulnerable", lua_SetUnitInvulnerable);
	lua_register(l, "PauseUnit", lua_PauseUnit);
	lua_register(l, "IsUnitPaused", lua_IsUnitPaused);
	lua_register(l, "UnitAddItem", lua_UnitAddItem);
	lua_register(l, "UnitAddItemById", lua_UnitAddItemById);
	lua_register(l, "UnitAddItemToSlotById", lua_UnitAddItemToSlotById);
	lua_register(l, "UnitRemoveItem", lua_UnitRemoveItem);
	lua_register(l, "UnitRemoveItemFromSlot", lua_UnitRemoveItemFromSlot);
	lua_register(l, "UnitHasItem", lua_UnitHasItem);
	lua_register(l, "UnitItemInSlot", lua_UnitItemInSlot);
	lua_register(l, "UnitInventorySize", lua_UnitInventorySize);
	lua_register(l, "UnitDropItemPoint", lua_UnitDropItemPoint);
	lua_register(l, "UnitDropItemSlot", lua_UnitDropItemSlot);
	lua_register(l, "UnitDropItemTarget", lua_UnitDropItemTarget);
	lua_register(l, "UnitUseItem", lua_UnitUseItem);
	lua_register(l, "UnitUseItemPoint", lua_UnitUseItemPoint);
	lua_register(l, "UnitUseItemTarget", lua_UnitUseItemTarget);
	lua_register(l, "GetUnitCurrentOrder", lua_GetUnitCurrentOrder);
	lua_register(l, "SetResourceAmount", lua_SetResourceAmount);
	lua_register(l, "AddResourceAmount", lua_AddResourceAmount);
	lua_register(l, "GetResourceAmount", lua_GetResourceAmount);
	lua_register(l, "SelectUnit", lua_SelectUnit);
	lua_register(l, "ClearSelection", lua_ClearSelection);
	lua_register(l, "UnitAddIndicator", lua_UnitAddIndicator);
	lua_register(l, "AddIndicator", lua_AddIndicator);
	lua_register(l, "KillUnit", lua_KillUnit);
	lua_register(l, "RemoveUnit", lua_RemoveUnit);
	lua_register(l, "ShowUnit", lua_ShowUnit);
	lua_register(l, "IsUnitInForce", lua_IsUnitInForce);
	lua_register(l, "IsUnitInGroup", lua_IsUnitInGroup);
	lua_register(l, "IsUnitOwnedByPlayer", lua_IsUnitOwnedByPlayer);
	lua_register(l, "IsUnitAlly", lua_IsUnitAlly);
	lua_register(l, "IsUnitEnemy", lua_IsUnitEnemy);
	lua_register(l, "IsUnitVisible", lua_IsUnitVisible);
	lua_register(l, "IsUnitDetected", lua_IsUnitDetected);
	lua_register(l, "IsUnitInvisible", lua_IsUnitInvisible);
	lua_register(l, "IsUnitFogged", lua_IsUnitFogged);
	lua_register(l, "IsUnitMasked", lua_IsUnitMasked);
	lua_register(l, "IsUnitSelected", lua_IsUnitSelected);
	lua_register(l, "IsUnitRace", lua_IsUnitRace);
	lua_register(l, "IsUnitType", lua_IsUnitType);
	lua_register(l, "IsUnit", lua_IsUnit);
	lua_register(l, "IsUnitInRange", lua_IsUnitInRange);
	lua_register(l, "IsUnitInRangeXY", lua_IsUnitInRangeXY);
	lua_register(l, "IsUnitInRangeLoc", lua_IsUnitInRangeLoc);
	lua_register(l, "IsUnitHidden", lua_IsUnitHidden);
	lua_register(l, "IsUnitIllusion", lua_IsUnitIllusion);
	lua_register(l, "IsUnitInTransport", lua_IsUnitInTransport);
	lua_register(l, "IsUnitLoaded", lua_IsUnitLoaded);
	lua_register(l, "IsHeroUnitId", lua_IsHeroUnitId);
	lua_register(l, "IsUnitIdType", lua_IsUnitIdType);
	lua_register(l, "GetOwningPlayer", lua_GetOwningPlayer);
	lua_register(l, "UnitShareVision", lua_UnitShareVision);
	lua_register(l, "UnitSuspendDecay", lua_UnitSuspendDecay);
	lua_register(l, "UnitAddType", lua_UnitAddType);
	lua_register(l, "UnitRemoveType", lua_UnitRemoveType);
	lua_register(l, "UnitAddAbility", lua_UnitAddAbility);
	lua_register(l, "UnitRemoveAbility", lua_UnitRemoveAbility);
	lua_register(l, "UnitMakeAbilityPermanent", lua_UnitMakeAbilityPermanent);
	lua_register(l, "UnitHasBuffsEx", lua_UnitHasBuffsEx);
	lua_register(l, "UnitCountBuffsEx", lua_UnitCountBuffsEx);
	lua_register(l, "UnitRemoveBuffs", lua_UnitRemoveBuffs);
	lua_register(l, "UnitRemoveBuffsEx", lua_UnitRemoveBuffsEx);
	lua_register(l, "UnitAddSleep", lua_UnitAddSleep);
	lua_register(l, "UnitCanSleep", lua_UnitCanSleep);
	lua_register(l, "UnitAddSleepPerm", lua_UnitAddSleepPerm);
	lua_register(l, "UnitCanSleepPerm", lua_UnitCanSleepPerm);
	lua_register(l, "UnitIsSleeping", lua_UnitIsSleeping);
	lua_register(l, "UnitWakeUp", lua_UnitWakeUp);
	lua_register(l, "UnitApplyTimedLife", lua_UnitApplyTimedLife);
	lua_register(l, "UnitIgnoreAlarm", lua_UnitIgnoreAlarm);
	lua_register(l, "UnitIgnoreAlarmToggled", lua_UnitIgnoreAlarmToggled);
	lua_register(l, "UnitDamagePoint", lua_UnitDamagePoint);
	lua_register(l, "UnitDamageTarget", lua_UnitDamageTarget);
	lua_register(l, "DecUnitAbilityLevel", lua_DecUnitAbilityLevel);
	lua_register(l, "IncUnitAbilityLevel", lua_IncUnitAbilityLevel);
	lua_register(l, "SetUnitAbilityLevel", lua_SetUnitAbilityLevel);
	lua_register(l, "UnitResetCooldown", lua_UnitResetCooldown);
	lua_register(l, "UnitSetConstructionProgress", lua_UnitSetConstructionProgress);
	lua_register(l, "UnitSetUpgradeProgress", lua_UnitSetUpgradeProgress);
	lua_register(l, "UnitPauseTimedLife", lua_UnitPauseTimedLife);
	lua_register(l, "UnitSetUsesAltIcon", lua_UnitSetUsesAltIcon);
	lua_register(l, "IssueImmediateOrderById", lua_IssueImmediateOrderById);
	lua_register(l, "IssuePointOrderById", lua_IssuePointOrderById);
	lua_register(l, "IssuePointOrderByIdLoc", lua_IssuePointOrderByIdLoc);
	lua_register(l, "IssueTargetOrderById", lua_IssueTargetOrderById);
	lua_register(l, "IssueInstantPointOrderById", lua_IssueInstantPointOrderById);
	lua_register(l, "IssueInstantTargetOrderById", lua_IssueInstantTargetOrderById);
	lua_register(l, "IssueBuildOrderById", lua_IssueBuildOrderById);
	lua_register(l, "IssueNeutralImmediateOrderById", lua_IssueNeutralImmediateOrderById);
	lua_register(l, "IssueNeutralPointOrderById", lua_IssueNeutralPointOrderById);
	lua_register(l, "IssueNeutralTargetOrderById", lua_IssueNeutralTargetOrderById);
	lua_register(l, "IssueImmediateOrder", lua_IssueImmediateOrder);
	lua_register(l, "IssuePointOrder", lua_IssuePointOrder);
	lua_register(l, "IssuePointOrderLoc", lua_IssuePointOrderLoc);
	lua_register(l, "IssueTargetOrder", lua_IssueTargetOrder);
	lua_register(l, "IssueInstantPointOrder", lua_IssueInstantPointOrder);
	lua_register(l, "IssueInstantTargetOrder", lua_IssueInstantTargetOrder);
	lua_register(l, "IssueBuildOrder", lua_IssueBuildOrder);
	lua_register(l, "IssueNeutralImmediateOrder", lua_IssueNeutralImmediateOrder);
	lua_register(l, "IssueNeutralPointOrder", lua_IssueNeutralPointOrder);
	lua_register(l, "IssueNeutralTargetOrder", lua_IssueNeutralTargetOrder);
	lua_register(l, "WaygateGetDestinationX", lua_WaygateGetDestinationX);
	lua_register(l, "WaygateGetDestinationY", lua_WaygateGetDestinationY);
	lua_register(l, "WaygateSetDestination", lua_WaygateSetDestination);
	lua_register(l, "WaygateActivate", lua_WaygateActivate);
	lua_register(l, "WaygateIsActive", lua_WaygateIsActive);
	lua_register(l, "AddItemToAllStock", lua_AddItemToAllStock);
	lua_register(l, "AddItemToStock", lua_AddItemToStock);
	lua_register(l, "AddUnitToAllStock", lua_AddUnitToAllStock);
	lua_register(l, "AddUnitToStock", lua_AddUnitToStock);
	lua_register(l, "RemoveItemFromAllStock", lua_RemoveItemFromAllStock);
	lua_register(l, "RemoveItemFromStock", lua_RemoveItemFromStock);
	lua_register(l, "RemoveUnitFromAllStock", lua_RemoveUnitFromAllStock);
	lua_register(l, "RemoveUnitFromStock", lua_RemoveUnitFromStock);
	lua_register(l, "SetAllItemTypeSlots", lua_SetAllItemTypeSlots);
	lua_register(l, "SetAllUnitTypeSlots", lua_SetAllUnitTypeSlots);
	lua_register(l, "SetItemTypeSlots", lua_SetItemTypeSlots);
	lua_register(l, "SetUnitTypeSlots", lua_SetUnitTypeSlots);
	lua_register(l, "GetUnitUserData", lua_GetUnitUserData);
	lua_register(l, "SetUnitUserData", lua_SetUnitUserData);
	lua_register(l, "CreateItem", lua_CreateItem);
	lua_register(l, "RemoveItem", lua_RemoveItem);
	lua_register(l, "GetItemPlayer", lua_GetItemPlayer);
	lua_register(l, "GetItemTypeId", lua_GetItemTypeId);
	lua_register(l, "GetItemX", lua_GetItemX);
	lua_register(l, "GetItemY", lua_GetItemY);
	lua_register(l, "SetItemPosition", lua_SetItemPosition);
	lua_register(l, "SetItemDropOnDeath", lua_SetItemDropOnDeath);
	lua_register(l, "SetItemDroppable", lua_SetItemDroppable);
	lua_register(l, "SetItemPawnable", lua_SetItemPawnable);
	lua_register(l, "SetItemPlayer", lua_SetItemPlayer);
	lua_register(l, "SetItemInvulnerable", lua_SetItemInvulnerable);
	lua_register(l, "IsItemInvulnerable", lua_IsItemInvulnerable);
	lua_register(l, "GetItemLevel", lua_GetItemLevel);
	lua_register(l, "GetItemType", lua_GetItemType);
	lua_register(l, "SetItemVisible", lua_SetItemVisible);
	lua_register(l, "IsItemVisible", lua_IsItemVisible);
	lua_register(l, "EnumItemsInRect", lua_EnumItemsInRect);
	lua_register(l, "IsItemOwned", lua_IsItemOwned);
	lua_register(l, "IsItemPowerup", lua_IsItemPowerup);
	lua_register(l, "IsItemSellable", lua_IsItemSellable);
	lua_register(l, "IsItemPawnable", lua_IsItemPawnable);
	lua_register(l, "IsItemIdPowerup", lua_IsItemIdPowerup);
	lua_register(l, "IsItemIdSellable", lua_IsItemIdSellable);
	lua_register(l, "IsItemIdPawnable", lua_IsItemIdPawnable);
	lua_register(l, "SetItemDropID", lua_SetItemDropID);
	lua_register(l, "GetItemName", lua_GetItemName);
	lua_register(l, "GetItemCharges", lua_GetItemCharges);
	lua_register(l, "SetItemCharges", lua_SetItemCharges);
	lua_register(l, "GetItemUserData", lua_GetItemUserData);
	lua_register(l, "SetItemUserData", lua_SetItemUserData);
	lua_register(l, "Player", lua_Player);
	lua_register(l, "GetLocalPlayer", lua_GetLocalPlayer);
	lua_register(l, "IsPlayerAlly", lua_IsPlayerAlly);
	lua_register(l, "IsPlayerEnemy", lua_IsPlayerEnemy);
	lua_register(l, "IsPlayerInForce", lua_IsPlayerInForce);
	lua_register(l, "IsPlayerObserver", lua_IsPlayerObserver);
	lua_register(l, "GetPlayerRace", lua_GetPlayerRace);
	lua_register(l, "GetPlayerId", lua_GetPlayerId);
	lua_register(l, "SetPlayerTechMaxAllowed", lua_SetPlayerTechMaxAllowed);
	lua_register(l, "GetPlayerTechMaxAllowed", lua_GetPlayerTechMaxAllowed);
	lua_register(l, "AddPlayerTechResearched", lua_AddPlayerTechResearched);
	lua_register(l, "SetPlayerTechResearched", lua_SetPlayerTechResearched);
	lua_register(l, "GetPlayerTechResearched", lua_GetPlayerTechResearched);
	lua_register(l, "GetPlayerTechCount", lua_GetPlayerTechCount);
	lua_register(l, "SetPlayerAbilityAvailable", lua_SetPlayerAbilityAvailable);
	lua_register(l, "GetPlayerUnitCount", lua_GetPlayerUnitCount);
	lua_register(l, "GetPlayerTypedUnitCount", lua_GetPlayerTypedUnitCount);
	lua_register(l, "GetPlayerStructureCount", lua_GetPlayerStructureCount);
	lua_register(l, "IsVisibleToPlayer", lua_IsVisibleToPlayer);
	lua_register(l, "IsLocationVisibleToPlayer", lua_IsLocationVisibleToPlayer);
	lua_register(l, "IsFoggedToPlayer", lua_IsFoggedToPlayer);
	lua_register(l, "IsLocationFoggedToPlayer", lua_IsLocationFoggedToPlayer);
	lua_register(l, "IsMaskedToPlayer", lua_IsMaskedToPlayer);
	lua_register(l, "IsLocationMaskedToPlayer", lua_IsLocationMaskedToPlayer);
	lua_register(l, "SetPlayerState", lua_SetPlayerState);
	lua_register(l, "GetPlayerState", lua_GetPlayerState);
	lua_register(l, "GetPlayerScore", lua_GetPlayerScore);
	lua_register(l, "GetPlayerAlliance", lua_GetPlayerAlliance);
	lua_register(l, "RemovePlayer", lua_RemovePlayer);
	lua_register(l, "CachePlayerHeroData", lua_CachePlayerHeroData);
	lua_register(l, "GetPlayerHandicap", lua_GetPlayerHandicap);
	lua_register(l, "SetPlayerHandicap", lua_SetPlayerHandicap);
	lua_register(l, "GetPlayerHandicapXP", lua_GetPlayerHandicapXP);
	lua_register(l, "SetPlayerHandicapXP", lua_SetPlayerHandicapXP);
	lua_register(l, "SetPlayerUnitsOwner", lua_SetPlayerUnitsOwner);
	lua_register(l, "CripplePlayer", lua_CripplePlayer);
	lua_register(l, "VersionGet", lua_VersionGet);
	lua_register(l, "VersionCompatible", lua_VersionCompatible);
	lua_register(l, "VersionSupported", lua_VersionSupported);
	lua_register(l, "EndGame", lua_EndGame);
	lua_register(l, "ChangeLevel", lua_ChangeLevel);
	lua_register(l, "RestartGame", lua_RestartGame);
	lua_register(l, "ReloadGame", lua_ReloadGame);
	lua_register(l, "LoadGame", lua_LoadGame);
	lua_register(l, "SaveGame", lua_SaveGame);
	lua_register(l, "RenameSaveDirectory", lua_RenameSaveDirectory);
	lua_register(l, "RemoveSaveDirectory", lua_RemoveSaveDirectory);
	lua_register(l, "CopySaveGame", lua_CopySaveGame);
	lua_register(l, "SaveGameExists", lua_SaveGameExists);
	lua_register(l, "SetFloatGameState", lua_SetFloatGameState);
	lua_register(l, "GetFloatGameState", lua_GetFloatGameState);
	lua_register(l, "SetIntegerGameState", lua_SetIntegerGameState);
	lua_register(l, "GetIntegerGameState", lua_GetIntegerGameState);
	lua_register(l, "SyncSelections", lua_SyncSelections);
	lua_register(l, "DialogCreate", lua_DialogCreate);
	lua_register(l, "DialogDestroy", lua_DialogDestroy);
	lua_register(l, "DialogSetAsync", lua_DialogSetAsync);
	lua_register(l, "DialogClear", lua_DialogClear);
	lua_register(l, "DialogSetMessage", lua_DialogSetMessage);
	lua_register(l, "DialogAddButton", lua_DialogAddButton);
	lua_register(l, "DialogAddQuitButton", lua_DialogAddQuitButton);
	lua_register(l, "DialogDisplay", lua_DialogDisplay);
	lua_register(l, "SetMissionAvailable", lua_SetMissionAvailable);
	lua_register(l, "SetCampaignAvailable", lua_SetCampaignAvailable);
	lua_register(l, "SetCampaignMenuRace", lua_SetCampaignMenuRace);
	lua_register(l, "SetCampaignMenuRaceEx", lua_SetCampaignMenuRaceEx);
	lua_register(l, "ForceCampaignSelectScreen", lua_ForceCampaignSelectScreen);
	lua_register(l, "SetOpCinematicAvailable", lua_SetOpCinematicAvailable);
	lua_register(l, "SetEdCinematicAvailable", lua_SetEdCinematicAvailable);
	lua_register(l, "SetTutorialCleared", lua_SetTutorialCleared);
	lua_register(l, "GetDefaultDifficulty", lua_GetDefaultDifficulty);
	lua_register(l, "SetDefaultDifficulty", lua_SetDefaultDifficulty);
	lua_register(l, "ReloadGameCachesFromDisk", lua_ReloadGameCachesFromDisk);
	lua_register(l, "SetCustomCampaignButtonVisible", lua_SetCustomCampaignButtonVisible);
	lua_register(l, "GetCustomCampaignButtonVisible", lua_GetCustomCampaignButtonVisible);
	lua_register(l, "DoNotSaveReplay", lua_DoNotSaveReplay);
	lua_register(l, "InitGameCache", lua_InitGameCache);
	lua_register(l, "SaveGameCache", lua_SaveGameCache);
	lua_register(l, "StoreInteger", lua_StoreInteger);
	lua_register(l, "StoreReal", lua_StoreReal);
	lua_register(l, "StoreBoolean", lua_StoreBoolean);
	lua_register(l, "StoreUnit", lua_StoreUnit);
	lua_register(l, "StoreString", lua_StoreString);
	lua_register(l, "SaveInteger", lua_SaveInteger);
	lua_register(l, "SaveReal", lua_SaveReal);
	lua_register(l, "SaveBoolean", lua_SaveBoolean);
	lua_register(l, "SaveStr", lua_SaveStr);
	lua_register(l, "SavePlayerHandle", lua_SavePlayerHandle);
	lua_register(l, "SaveWidgetHandle", lua_SaveWidgetHandle);
	lua_register(l, "SaveDestructableHandle", lua_SaveDestructableHandle);
	lua_register(l, "SaveItemHandle", lua_SaveItemHandle);
	lua_register(l, "SaveUnitHandle", lua_SaveUnitHandle);
	lua_register(l, "SaveAbilityHandle", lua_SaveAbilityHandle);
	lua_register(l, "SaveTimerHandle", lua_SaveTimerHandle);
	lua_register(l, "SaveRegionHandle", lua_SaveRegionHandle);
	lua_register(l, "SaveTriggerHandle", lua_SaveTriggerHandle);
	lua_register(l, "SaveTriggerConditionHandle", lua_SaveTriggerConditionHandle);
	lua_register(l, "SaveTriggerActionHandle", lua_SaveTriggerActionHandle);
	lua_register(l, "SaveTriggerEventHandle", lua_SaveTriggerEventHandle);
	lua_register(l, "SaveForceHandle", lua_SaveForceHandle);
	lua_register(l, "SaveGroupHandle", lua_SaveGroupHandle);
	lua_register(l, "SaveLocationHandle", lua_SaveLocationHandle);
	lua_register(l, "SaveRectHandle", lua_SaveRectHandle);
	lua_register(l, "SaveBooleanExprHandle", lua_SaveBooleanExprHandle);
	lua_register(l, "SaveSoundHandle", lua_SaveSoundHandle);
	lua_register(l, "SaveEffectHandle", lua_SaveEffectHandle);
	lua_register(l, "SaveUnitPoolHandle", lua_SaveUnitPoolHandle);
	lua_register(l, "SaveItemPoolHandle", lua_SaveItemPoolHandle);
	lua_register(l, "SaveQuestHandle", lua_SaveQuestHandle);
	lua_register(l, "SaveQuestItemHandle", lua_SaveQuestItemHandle);
	lua_register(l, "SaveDefeatConditionHandle", lua_SaveDefeatConditionHandle);
	lua_register(l, "SaveTimerDialogHandle", lua_SaveTimerDialogHandle);
	lua_register(l, "SaveLeaderboardHandle", lua_SaveLeaderboardHandle);
	lua_register(l, "SaveMultiboardHandle", lua_SaveMultiboardHandle);
	lua_register(l, "SaveMultiboardItemHandle", lua_SaveMultiboardItemHandle);
	lua_register(l, "SaveTrackableHandle", lua_SaveTrackableHandle);
	lua_register(l, "SaveDialogHandle", lua_SaveDialogHandle);
	lua_register(l, "SaveButtonHandle", lua_SaveButtonHandle);
	lua_register(l, "SaveTextTagHandle", lua_SaveTextTagHandle);
	lua_register(l, "SaveLightningHandle", lua_SaveLightningHandle);
	lua_register(l, "SaveImageHandle", lua_SaveImageHandle);
	lua_register(l, "SaveUbersplatHandle", lua_SaveUbersplatHandle);
	lua_register(l, "SaveFogStateHandle", lua_SaveFogStateHandle);
	lua_register(l, "SaveFogModifierHandle", lua_SaveFogModifierHandle);
	lua_register(l, "SaveAgentHandle", lua_SaveAgentHandle);
	lua_register(l, "SaveHashtableHandle", lua_SaveHashtableHandle);
	lua_register(l, "SyncStoredInteger", lua_SyncStoredInteger);
	lua_register(l, "SyncStoredReal", lua_SyncStoredReal);
	lua_register(l, "SyncStoredBoolean", lua_SyncStoredBoolean);
	lua_register(l, "SyncStoredUnit", lua_SyncStoredUnit);
	lua_register(l, "SyncStoredString", lua_SyncStoredString);
	lua_register(l, "GetStoredInteger", lua_GetStoredInteger);
	lua_register(l, "GetStoredReal", lua_GetStoredReal);
	lua_register(l, "GetStoredBoolean", lua_GetStoredBoolean);
	lua_register(l, "RestoreUnit", lua_RestoreUnit);
	lua_register(l, "GetStoredString", lua_GetStoredString);
	lua_register(l, "HaveStoredInteger", lua_HaveStoredInteger);
	lua_register(l, "HaveStoredReal", lua_HaveStoredReal);
	lua_register(l, "HaveStoredBoolean", lua_HaveStoredBoolean);
	lua_register(l, "HaveStoredUnit", lua_HaveStoredUnit);
	lua_register(l, "HaveStoredString", lua_HaveStoredString);
	lua_register(l, "FlushGameCache", lua_FlushGameCache);
	lua_register(l, "FlushStoredMission", lua_FlushStoredMission);
	lua_register(l, "FlushStoredInteger", lua_FlushStoredInteger);
	lua_register(l, "FlushStoredReal", lua_FlushStoredReal);
	lua_register(l, "FlushStoredBoolean", lua_FlushStoredBoolean);
	lua_register(l, "FlushStoredUnit", lua_FlushStoredUnit);
	lua_register(l, "FlushStoredString", lua_FlushStoredString);
	lua_register(l, "InitHashtable", lua_InitHashtable);
	lua_register(l, "LoadInteger", lua_LoadInteger);
	lua_register(l, "LoadReal", lua_LoadReal);
	lua_register(l, "LoadBoolean", lua_LoadBoolean);
	lua_register(l, "LoadStr", lua_LoadStr);
	lua_register(l, "LoadPlayerHandle", lua_LoadPlayerHandle);
	lua_register(l, "LoadWidgetHandle", lua_LoadWidgetHandle);
	lua_register(l, "LoadDestructableHandle", lua_LoadDestructableHandle);
	lua_register(l, "LoadItemHandle", lua_LoadItemHandle);
	lua_register(l, "LoadUnitHandle", lua_LoadUnitHandle);
	lua_register(l, "LoadAbilityHandle", lua_LoadAbilityHandle);
	lua_register(l, "LoadTimerHandle", lua_LoadTimerHandle);
	lua_register(l, "LoadRegionHandle", lua_LoadRegionHandle);
	lua_register(l, "LoadTriggerHandle", lua_LoadTriggerHandle);
	lua_register(l, "LoadTriggerConditionHandle", lua_LoadTriggerConditionHandle);
	lua_register(l, "LoadTriggerActionHandle", lua_LoadTriggerActionHandle);
	lua_register(l, "LoadTriggerEventHandle", lua_LoadTriggerEventHandle);
	lua_register(l, "LoadForceHandle", lua_LoadForceHandle);
	lua_register(l, "LoadGroupHandle", lua_LoadGroupHandle);
	lua_register(l, "LoadLocationHandle", lua_LoadLocationHandle);
	lua_register(l, "LoadRectHandle", lua_LoadRectHandle);
	lua_register(l, "LoadBooleanExprHandle", lua_LoadBooleanExprHandle);
	lua_register(l, "LoadSoundHandle", lua_LoadSoundHandle);
	lua_register(l, "LoadEffectHandle", lua_LoadEffectHandle);
	lua_register(l, "LoadUnitPoolHandle", lua_LoadUnitPoolHandle);
	lua_register(l, "LoadItemPoolHandle", lua_LoadItemPoolHandle);
	lua_register(l, "LoadQuestHandle", lua_LoadQuestHandle);
	lua_register(l, "LoadQuestItemHandle", lua_LoadQuestItemHandle);
	lua_register(l, "LoadDefeatConditionHandle", lua_LoadDefeatConditionHandle);
	lua_register(l, "LoadTimerDialogHandle", lua_LoadTimerDialogHandle);
	lua_register(l, "LoadLeaderboardHandle", lua_LoadLeaderboardHandle);
	lua_register(l, "LoadMultiboardHandle", lua_LoadMultiboardHandle);
	lua_register(l, "LoadMultiboardItemHandle", lua_LoadMultiboardItemHandle);
	lua_register(l, "LoadTrackableHandle", lua_LoadTrackableHandle);
	lua_register(l, "LoadDialogHandle", lua_LoadDialogHandle);
	lua_register(l, "LoadButtonHandle", lua_LoadButtonHandle);
	lua_register(l, "LoadTextTagHandle", lua_LoadTextTagHandle);
	lua_register(l, "LoadLightningHandle", lua_LoadLightningHandle);
	lua_register(l, "LoadImageHandle", lua_LoadImageHandle);
	lua_register(l, "LoadUbersplatHandle", lua_LoadUbersplatHandle);
	lua_register(l, "LoadFogStateHandle", lua_LoadFogStateHandle);
	lua_register(l, "LoadFogModifierHandle", lua_LoadFogModifierHandle);
	lua_register(l, "LoadHashtableHandle", lua_LoadHashtableHandle);
	lua_register(l, "HaveSavedInteger", lua_HaveSavedInteger);
	lua_register(l, "HaveSavedReal", lua_HaveSavedReal);
	lua_register(l, "HaveSavedBoolean", lua_HaveSavedBoolean);
	lua_register(l, "HaveSavedString", lua_HaveSavedString);
	lua_register(l, "HaveSavedHandle", lua_HaveSavedHandle);
	lua_register(l, "RemoveSavedInteger", lua_RemoveSavedInteger);
	lua_register(l, "RemoveSavedReal", lua_RemoveSavedReal);
	lua_register(l, "RemoveSavedBoolean", lua_RemoveSavedBoolean);
	lua_register(l, "RemoveSavedString", lua_RemoveSavedString);
	lua_register(l, "RemoveSavedHandle", lua_RemoveSavedHandle);
	lua_register(l, "FlushParentHashtable", lua_FlushParentHashtable);
	lua_register(l, "FlushChildHashtable", lua_FlushChildHashtable);
	lua_register(l, "GetRandomInt", lua_GetRandomInt);
	lua_register(l, "GetRandomReal", lua_GetRandomReal);
	lua_register(l, "CreateUnitPool", lua_CreateUnitPool);
	lua_register(l, "DestroyUnitPool", lua_DestroyUnitPool);
	lua_register(l, "UnitPoolAddUnitType", lua_UnitPoolAddUnitType);
	lua_register(l, "UnitPoolRemoveUnitType", lua_UnitPoolRemoveUnitType);
	lua_register(l, "PlaceRandomUnit", lua_PlaceRandomUnit);
	lua_register(l, "CreateItemPool", lua_CreateItemPool);
	lua_register(l, "DestroyItemPool", lua_DestroyItemPool);
	lua_register(l, "ItemPoolAddItemType", lua_ItemPoolAddItemType);
	lua_register(l, "ItemPoolRemoveItemType", lua_ItemPoolRemoveItemType);
	lua_register(l, "PlaceRandomItem", lua_PlaceRandomItem);
	lua_register(l, "ChooseRandomCreep", lua_ChooseRandomCreep);
	lua_register(l, "ChooseRandomNPBuilding", lua_ChooseRandomNPBuilding);
	lua_register(l, "ChooseRandomItem", lua_ChooseRandomItem);
	lua_register(l, "ChooseRandomItemEx", lua_ChooseRandomItemEx);
	lua_register(l, "SetRandomSeed", lua_SetRandomSeed);
	lua_register(l, "DisplayTextToPlayer", lua_DisplayTextToPlayer);
	lua_register(l, "DisplayTimedTextToPlayer", lua_DisplayTimedTextToPlayer);
	lua_register(l, "DisplayTimedTextFromPlayer", lua_DisplayTimedTextFromPlayer);
	lua_register(l, "ClearTextMessages", lua_ClearTextMessages);
	lua_register(l, "EnableUserControl", lua_EnableUserControl);
	lua_register(l, "EnableUserUI", lua_EnableUserUI);
	lua_register(l, "DisableRestartMission", lua_DisableRestartMission);
	lua_register(l, "ForceUIKey", lua_ForceUIKey);
	lua_register(l, "ForceUICancel", lua_ForceUICancel);
	lua_register(l, "DisplayLoadDialog", lua_DisplayLoadDialog);
	lua_register(l, "SetTerrainFog", lua_SetTerrainFog);
	lua_register(l, "SetUnitFog", lua_SetUnitFog);
	lua_register(l, "SetTerrainFogEx", lua_SetTerrainFogEx);
	lua_register(l, "ResetTerrainFog", lua_ResetTerrainFog);
	lua_register(l, "SetDayNightModels", lua_SetDayNightModels);
	lua_register(l, "SetSkyModel", lua_SetSkyModel);
	lua_register(l, "SuspendTimeOfDay", lua_SuspendTimeOfDay);
	lua_register(l, "SetTimeOfDayScale", lua_SetTimeOfDayScale);
	lua_register(l, "GetTimeOfDayScale", lua_GetTimeOfDayScale);
	lua_register(l, "ShowInterface", lua_ShowInterface);
	lua_register(l, "PauseGame", lua_PauseGame);
	lua_register(l, "PingMinimap", lua_PingMinimap);
	lua_register(l, "PingMinimapEx", lua_PingMinimapEx);
	lua_register(l, "SetIntroShotText", lua_SetIntroShotText);
	lua_register(l, "SetIntroShotModel", lua_SetIntroShotModel);
	lua_register(l, "EnableOcclusion", lua_EnableOcclusion);
	lua_register(l, "EnableWorldFogBoundary", lua_EnableWorldFogBoundary);
	lua_register(l, "PlayModelCinematic", lua_PlayModelCinematic);
	lua_register(l, "PlayCinematic", lua_PlayCinematic);
	lua_register(l, "SetAltMinimapIcon", lua_SetAltMinimapIcon);
	lua_register(l, "CreateTextTag", lua_CreateTextTag);
	lua_register(l, "DestroyTextTag", lua_DestroyTextTag);
	lua_register(l, "SetTextTagText", lua_SetTextTagText);
	lua_register(l, "SetTextTagPos", lua_SetTextTagPos);
	lua_register(l, "SetTextTagPosUnit", lua_SetTextTagPosUnit);
	lua_register(l, "SetTextTagColor", lua_SetTextTagColor);
	lua_register(l, "SetTextTagVelocity", lua_SetTextTagVelocity);
	lua_register(l, "SetTextTagVisibility", lua_SetTextTagVisibility);
	lua_register(l, "SetTextTagSuspended", lua_SetTextTagSuspended);
	lua_register(l, "SetTextTagPermanent", lua_SetTextTagPermanent);
	lua_register(l, "SetTextTagAge", lua_SetTextTagAge);
	lua_register(l, "SetTextTagLifespan", lua_SetTextTagLifespan);
	lua_register(l, "SetTextTagFadepoint", lua_SetTextTagFadepoint);
	lua_register(l, "SetReservedLocalHeroButtons", lua_SetReservedLocalHeroButtons);
	lua_register(l, "GetAllyColorFilterState", lua_GetAllyColorFilterState);
	lua_register(l, "SetAllyColorFilterState", lua_SetAllyColorFilterState);
	lua_register(l, "GetCreepCampFilterState", lua_GetCreepCampFilterState);
	lua_register(l, "SetCreepCampFilterState", lua_SetCreepCampFilterState);
	lua_register(l, "EnableMinimapFilterButtons", lua_EnableMinimapFilterButtons);
	lua_register(l, "EnableDragSelect", lua_EnableDragSelect);
	lua_register(l, "EnablePreSelect", lua_EnablePreSelect);
	lua_register(l, "EnableSelect", lua_EnableSelect);
	lua_register(l, "CreateTrackable", lua_CreateTrackable);
	lua_register(l, "TriggerRegisterTrackableHitEvent", lua_TriggerRegisterTrackableHitEvent);
	lua_register(l, "TriggerRegisterTrackableTrackEvent", lua_TriggerRegisterTrackableTrackEvent);
	lua_register(l, "GetTriggeringTrackable", lua_GetTriggeringTrackable);
	lua_register(l, "CreateQuest", lua_CreateQuest);
	lua_register(l, "DestroyQuest", lua_DestroyQuest);
	lua_register(l, "QuestSetTitle", lua_QuestSetTitle);
	lua_register(l, "QuestSetDescription", lua_QuestSetDescription);
	lua_register(l, "QuestSetIconPath", lua_QuestSetIconPath);
	lua_register(l, "QuestSetRequired", lua_QuestSetRequired);
	lua_register(l, "QuestSetCompleted", lua_QuestSetCompleted);
	lua_register(l, "QuestSetDiscovered", lua_QuestSetDiscovered);
	lua_register(l, "QuestSetFailed", lua_QuestSetFailed);
	lua_register(l, "QuestSetEnabled", lua_QuestSetEnabled);
	lua_register(l, "IsQuestRequired", lua_IsQuestRequired);
	lua_register(l, "IsQuestCompleted", lua_IsQuestCompleted);
	lua_register(l, "IsQuestDiscovered", lua_IsQuestDiscovered);
	lua_register(l, "IsQuestFailed", lua_IsQuestFailed);
	lua_register(l, "IsQuestEnabled", lua_IsQuestEnabled);
	lua_register(l, "QuestCreateItem", lua_QuestCreateItem);
	lua_register(l, "QuestItemSetDescription", lua_QuestItemSetDescription);
	lua_register(l, "QuestItemSetCompleted", lua_QuestItemSetCompleted);
	lua_register(l, "IsQuestItemCompleted", lua_IsQuestItemCompleted);
	lua_register(l, "CreateDefeatCondition", lua_CreateDefeatCondition);
	lua_register(l, "DestroyDefeatCondition", lua_DestroyDefeatCondition);
	lua_register(l, "DefeatConditionSetDescription", lua_DefeatConditionSetDescription);
	lua_register(l, "FlashQuestDialogButton", lua_FlashQuestDialogButton);
	lua_register(l, "ForceQuestDialogUpdate", lua_ForceQuestDialogUpdate);
	lua_register(l, "CreateTimerDialog", lua_CreateTimerDialog);
	lua_register(l, "DestroyTimerDialog", lua_DestroyTimerDialog);
	lua_register(l, "TimerDialogSetTitle", lua_TimerDialogSetTitle);
	lua_register(l, "TimerDialogSetTitleColor", lua_TimerDialogSetTitleColor);
	lua_register(l, "TimerDialogSetTimeColor", lua_TimerDialogSetTimeColor);
	lua_register(l, "TimerDialogSetSpeed", lua_TimerDialogSetSpeed);
	lua_register(l, "TimerDialogDisplay", lua_TimerDialogDisplay);
	lua_register(l, "IsTimerDialogDisplayed", lua_IsTimerDialogDisplayed);
	lua_register(l, "TimerDialogSetRealTimeRemaining", lua_TimerDialogSetRealTimeRemaining);
	lua_register(l, "CreateLeaderboard", lua_CreateLeaderboard);
	lua_register(l, "DestroyLeaderboard", lua_DestroyLeaderboard);
	lua_register(l, "LeaderboardGetItemCount", lua_LeaderboardGetItemCount);
	lua_register(l, "LeaderboardSetSizeByItemCount", lua_LeaderboardSetSizeByItemCount);
	lua_register(l, "LeaderboardAddItem", lua_LeaderboardAddItem);
	lua_register(l, "LeaderboardRemoveItem", lua_LeaderboardRemoveItem);
	lua_register(l, "LeaderboardRemovePlayerItem", lua_LeaderboardRemovePlayerItem);
	lua_register(l, "LeaderboardSortItemsByValue", lua_LeaderboardSortItemsByValue);
	lua_register(l, "LeaderboardSortItemsByPlayer", lua_LeaderboardSortItemsByPlayer);
	lua_register(l, "LeaderboardSortItemsByLabel", lua_LeaderboardSortItemsByLabel);
	lua_register(l, "LeaderboardClear", lua_LeaderboardClear);
	lua_register(l, "LeaderboardDisplay", lua_LeaderboardDisplay);
	lua_register(l, "IsLeaderboardDisplayed", lua_IsLeaderboardDisplayed);
	lua_register(l, "LeaderboardGetLabelText", lua_LeaderboardGetLabelText);
	lua_register(l, "PlayerSetLeaderboard", lua_PlayerSetLeaderboard);
	lua_register(l, "PlayerGetLeaderboard", lua_PlayerGetLeaderboard);
	lua_register(l, "LeaderboardHasPlayerItem", lua_LeaderboardHasPlayerItem);
	lua_register(l, "LeaderboardGetPlayerIndex", lua_LeaderboardGetPlayerIndex);
	lua_register(l, "LeaderboardSetLabel", lua_LeaderboardSetLabel);
	lua_register(l, "LeaderboardSetLabelColor", lua_LeaderboardSetLabelColor);
	lua_register(l, "LeaderboardSetValueColor", lua_LeaderboardSetValueColor);
	lua_register(l, "LeaderboardSetStyle", lua_LeaderboardSetStyle);
	lua_register(l, "LeaderboardSetItemValue", lua_LeaderboardSetItemValue);
	lua_register(l, "LeaderboardSetItemLabel", lua_LeaderboardSetItemLabel);
	lua_register(l, "LeaderboardSetItemStyle", lua_LeaderboardSetItemStyle);
	lua_register(l, "LeaderboardSetItemLabelColor", lua_LeaderboardSetItemLabelColor);
	lua_register(l, "LeaderboardSetItemValueColor", lua_LeaderboardSetItemValueColor);
	lua_register(l, "CreateMultiboard", lua_CreateMultiboard);
	lua_register(l, "DestroyMultiboard", lua_DestroyMultiboard);
	lua_register(l, "MultiboardDisplay", lua_MultiboardDisplay);
	lua_register(l, "MultiboardMinimize", lua_MultiboardMinimize);
	lua_register(l, "IsMultiboardDisplayed", lua_IsMultiboardDisplayed);
	lua_register(l, "IsMultiboardMinimized", lua_IsMultiboardMinimized);
	lua_register(l, "MultiboardClear", lua_MultiboardClear);
	lua_register(l, "MultiboardSetTitleText", lua_MultiboardSetTitleText);
	lua_register(l, "MultiboardGetTitleText", lua_MultiboardGetTitleText);
	lua_register(l, "MultiboardSetTitleTextColor", lua_MultiboardSetTitleTextColor);
	lua_register(l, "MultiboardGetRowCount", lua_MultiboardGetRowCount);
	lua_register(l, "MultiboardGetColumnCount", lua_MultiboardGetColumnCount);
	lua_register(l, "MultiboardSetColumnCount", lua_MultiboardSetColumnCount);
	lua_register(l, "MultiboardSetRowCount", lua_MultiboardSetRowCount);
	lua_register(l, "MultiboardSetItemsStyle", lua_MultiboardSetItemsStyle);
	lua_register(l, "MultiboardSetItemsValueColor", lua_MultiboardSetItemsValueColor);
	lua_register(l, "MultiboardSetItemsValue", lua_MultiboardSetItemsValue);
	lua_register(l, "MultiboardSetItemsWidth", lua_MultiboardSetItemsWidth);
	lua_register(l, "MultiboardSetItemsIcon", lua_MultiboardSetItemsIcon);
	lua_register(l, "MultiboardGetItem", lua_MultiboardGetItem);
	lua_register(l, "MultiboardReleaseItem", lua_MultiboardReleaseItem);
	lua_register(l, "MultiboardSetItemStyle", lua_MultiboardSetItemStyle);
	lua_register(l, "MultiboardSetItemValue", lua_MultiboardSetItemValue);
	lua_register(l, "MultiboardSetItemValueColor", lua_MultiboardSetItemValueColor);
	lua_register(l, "MultiboardSetItemWidth", lua_MultiboardSetItemWidth);
	lua_register(l, "MultiboardSetItemIcon", lua_MultiboardSetItemIcon);
	lua_register(l, "MultiboardSuppressDisplay", lua_MultiboardSuppressDisplay);
	lua_register(l, "SetCameraBounds", lua_SetCameraBounds);
	lua_register(l, "SetCameraPosition", lua_SetCameraPosition);
	lua_register(l, "SetCameraQuickPosition", lua_SetCameraQuickPosition);
	lua_register(l, "ResetToGameCamera", lua_ResetToGameCamera);
	lua_register(l, "StopCamera", lua_StopCamera);
	lua_register(l, "PanCameraTo", lua_PanCameraTo);
	lua_register(l, "PanCameraToTimed", lua_PanCameraToTimed);
	lua_register(l, "PanCameraToWithZ", lua_PanCameraToWithZ);
	lua_register(l, "PanCameraToTimedWithZ", lua_PanCameraToTimedWithZ);
	lua_register(l, "SetCinematicCamera", lua_SetCinematicCamera);
	lua_register(l, "SetCameraField", lua_SetCameraField);
	lua_register(l, "AdjustCameraField", lua_AdjustCameraField);
	lua_register(l, "SetCameraTargetController", lua_SetCameraTargetController);
	lua_register(l, "SetCameraOrientController", lua_SetCameraOrientController);
	lua_register(l, "SetCameraRotateMode", lua_SetCameraRotateMode);
	lua_register(l, "CreateCameraSetup", lua_CreateCameraSetup);
	lua_register(l, "CameraSetupSetField", lua_CameraSetupSetField);
	lua_register(l, "CameraSetupGetField", lua_CameraSetupGetField);
	lua_register(l, "CameraSetupSetDestPosition", lua_CameraSetupSetDestPosition);
	lua_register(l, "CameraSetupGetDestPositionLoc", lua_CameraSetupGetDestPositionLoc);
	lua_register(l, "CameraSetupGetDestPositionX", lua_CameraSetupGetDestPositionX);
	lua_register(l, "CameraSetupGetDestPositionY", lua_CameraSetupGetDestPositionY);
	lua_register(l, "CameraSetupApply", lua_CameraSetupApply);
	lua_register(l, "CameraSetupApplyWithZ", lua_CameraSetupApplyWithZ);
	lua_register(l, "CameraSetupApplyForceDuration", lua_CameraSetupApplyForceDuration);
	lua_register(l, "CameraSetupApplyForceDurationWithZ", lua_CameraSetupApplyForceDurationWithZ);
	lua_register(l, "CameraSetTargetNoise", lua_CameraSetTargetNoise);
	lua_register(l, "CameraSetSourceNoise", lua_CameraSetSourceNoise);
	lua_register(l, "CameraSetTargetNoiseEx", lua_CameraSetTargetNoiseEx);
	lua_register(l, "CameraSetSourceNoiseEx", lua_CameraSetSourceNoiseEx);
	lua_register(l, "CameraSetSmoothingFactor", lua_CameraSetSmoothingFactor);
	lua_register(l, "GetCameraMargin", lua_GetCameraMargin);
	lua_register(l, "GetCameraBoundMinX", lua_GetCameraBoundMinX);
	lua_register(l, "GetCameraBoundMinY", lua_GetCameraBoundMinY);
	lua_register(l, "GetCameraBoundMaxX", lua_GetCameraBoundMaxX);
	lua_register(l, "GetCameraBoundMaxY", lua_GetCameraBoundMaxY);
	lua_register(l, "GetCameraField", lua_GetCameraField);
	lua_register(l, "GetCameraTargetPositionX", lua_GetCameraTargetPositionX);
	lua_register(l, "GetCameraTargetPositionY", lua_GetCameraTargetPositionY);
	lua_register(l, "GetCameraTargetPositionZ", lua_GetCameraTargetPositionZ);
	lua_register(l, "GetCameraTargetPositionLoc", lua_GetCameraTargetPositionLoc);
	lua_register(l, "GetCameraEyePositionX", lua_GetCameraEyePositionX);
	lua_register(l, "GetCameraEyePositionY", lua_GetCameraEyePositionY);
	lua_register(l, "GetCameraEyePositionZ", lua_GetCameraEyePositionZ);
	lua_register(l, "GetCameraEyePositionLoc", lua_GetCameraEyePositionLoc);
	lua_register(l, "SetCineFilterTexture", lua_SetCineFilterTexture);
	lua_register(l, "SetCineFilterBlendMode", lua_SetCineFilterBlendMode);
	lua_register(l, "SetCineFilterTexMapFlags", lua_SetCineFilterTexMapFlags);
	lua_register(l, "SetCineFilterStartUV", lua_SetCineFilterStartUV);
	lua_register(l, "SetCineFilterEndUV", lua_SetCineFilterEndUV);
	lua_register(l, "SetCineFilterStartColor", lua_SetCineFilterStartColor);
	lua_register(l, "SetCineFilterEndColor", lua_SetCineFilterEndColor);
	lua_register(l, "SetCineFilterDuration", lua_SetCineFilterDuration);
	lua_register(l, "DisplayCineFilter", lua_DisplayCineFilter);
	lua_register(l, "IsCineFilterDisplayed", lua_IsCineFilterDisplayed);
	lua_register(l, "SetCinematicScene", lua_SetCinematicScene);
	lua_register(l, "EndCinematicScene", lua_EndCinematicScene);
	lua_register(l, "ForceCinematicSubtitles", lua_ForceCinematicSubtitles);
	lua_register(l, "NewSoundEnvironment", lua_NewSoundEnvironment);
	lua_register(l, "CreateSound", lua_CreateSound);
	lua_register(l, "CreateSoundFilenameWithLabel", lua_CreateSoundFilenameWithLabel);
	lua_register(l, "CreateSoundFromLabel", lua_CreateSoundFromLabel);
	lua_register(l, "CreateMIDISound", lua_CreateMIDISound);
	lua_register(l, "SetStackedSound", lua_SetStackedSound);
	lua_register(l, "ClearStackedSound", lua_ClearStackedSound);
	lua_register(l, "SetStackedSoundRect", lua_SetStackedSoundRect);
	lua_register(l, "ClearStackedSoundRect", lua_ClearStackedSoundRect);
	lua_register(l, "SetSoundParamsFromLabel", lua_SetSoundParamsFromLabel);
	lua_register(l, "SetSoundChannel", lua_SetSoundChannel);
	lua_register(l, "SetSoundVolume", lua_SetSoundVolume);
	lua_register(l, "SetSoundPitch", lua_SetSoundPitch);
	lua_register(l, "SetSoundPlayPosition", lua_SetSoundPlayPosition);
	lua_register(l, "SetSoundDistances", lua_SetSoundDistances);
	lua_register(l, "SetSoundDistanceCutoff", lua_SetSoundDistanceCutoff);
	lua_register(l, "SetSoundConeAngles", lua_SetSoundConeAngles);
	lua_register(l, "SetSoundConeOrientation", lua_SetSoundConeOrientation);
	lua_register(l, "SetSoundPosition", lua_SetSoundPosition);
	lua_register(l, "SetSoundVelocity", lua_SetSoundVelocity);
	lua_register(l, "AttachSoundToUnit", lua_AttachSoundToUnit);
	lua_register(l, "StartSound", lua_StartSound);
	lua_register(l, "StopSound", lua_StopSound);
	lua_register(l, "KillSoundWhenDone", lua_KillSoundWhenDone);
	lua_register(l, "SetMapMusic", lua_SetMapMusic);
	lua_register(l, "ClearMapMusic", lua_ClearMapMusic);
	lua_register(l, "PlayMusic", lua_PlayMusic);
	lua_register(l, "PlayMusicEx", lua_PlayMusicEx);
	lua_register(l, "StopMusic", lua_StopMusic);
	lua_register(l, "ResumeMusic", lua_ResumeMusic);
	lua_register(l, "PlayThematicMusic", lua_PlayThematicMusic);
	lua_register(l, "PlayThematicMusicEx", lua_PlayThematicMusicEx);
	lua_register(l, "EndThematicMusic", lua_EndThematicMusic);
	lua_register(l, "SetMusicVolume", lua_SetMusicVolume);
	lua_register(l, "SetMusicPlayPosition", lua_SetMusicPlayPosition);
	lua_register(l, "SetThematicMusicPlayPosition", lua_SetThematicMusicPlayPosition);
	lua_register(l, "SetSoundDuration", lua_SetSoundDuration);
	lua_register(l, "GetSoundDuration", lua_GetSoundDuration);
	lua_register(l, "GetSoundFileDuration", lua_GetSoundFileDuration);
	lua_register(l, "VolumeGroupSetVolume", lua_VolumeGroupSetVolume);
	lua_register(l, "VolumeGroupReset", lua_VolumeGroupReset);
	lua_register(l, "GetSoundIsPlaying", lua_GetSoundIsPlaying);
	lua_register(l, "GetSoundIsLoading", lua_GetSoundIsLoading);
	lua_register(l, "RegisterStackedSound", lua_RegisterStackedSound);
	lua_register(l, "UnregisterStackedSound", lua_UnregisterStackedSound);
	lua_register(l, "AddWeatherEffect", lua_AddWeatherEffect);
	lua_register(l, "RemoveWeatherEffect", lua_RemoveWeatherEffect);
	lua_register(l, "EnableWeatherEffect", lua_EnableWeatherEffect);
	lua_register(l, "TerrainDeformCrater", lua_TerrainDeformCrater);
	lua_register(l, "TerrainDeformRipple", lua_TerrainDeformRipple);
	lua_register(l, "TerrainDeformWave", lua_TerrainDeformWave);
	lua_register(l, "TerrainDeformRandom", lua_TerrainDeformRandom);
	lua_register(l, "TerrainDeformStop", lua_TerrainDeformStop);
	lua_register(l, "TerrainDeformStopAll", lua_TerrainDeformStopAll);
	lua_register(l, "DestroyEffect", lua_DestroyEffect);
	lua_register(l, "AddSpecialEffect", lua_AddSpecialEffect);
	lua_register(l, "AddSpecialEffectLoc", lua_AddSpecialEffectLoc);
	lua_register(l, "AddSpecialEffectTarget", lua_AddSpecialEffectTarget);
	lua_register(l, "AddSpellEffect", lua_AddSpellEffect);
	lua_register(l, "AddSpellEffectLoc", lua_AddSpellEffectLoc);
	lua_register(l, "AddSpellEffectById", lua_AddSpellEffectById);
	lua_register(l, "AddSpellEffectByIdLoc", lua_AddSpellEffectByIdLoc);
	lua_register(l, "AddSpellEffectTarget", lua_AddSpellEffectTarget);
	lua_register(l, "AddSpellEffectTargetById", lua_AddSpellEffectTargetById);
	lua_register(l, "AddLightning", lua_AddLightning);
	lua_register(l, "AddLightningEx", lua_AddLightningEx);
	lua_register(l, "DestroyLightning", lua_DestroyLightning);
	lua_register(l, "GetLightningColorA", lua_GetLightningColorA);
	lua_register(l, "GetLightningColorR", lua_GetLightningColorR);
	lua_register(l, "GetLightningColorG", lua_GetLightningColorG);
	lua_register(l, "GetLightningColorB", lua_GetLightningColorB);
	lua_register(l, "MoveLightning", lua_MoveLightning);
	lua_register(l, "MoveLightningEx", lua_MoveLightningEx);
	lua_register(l, "SetLightningColor", lua_SetLightningColor);
	lua_register(l, "GetAbilityEffect", lua_GetAbilityEffect);
	lua_register(l, "GetAbilityEffectById", lua_GetAbilityEffectById);
	lua_register(l, "GetAbilitySound", lua_GetAbilitySound);
	lua_register(l, "GetAbilitySoundById", lua_GetAbilitySoundById);
	lua_register(l, "GetTerrainCliffLevel", lua_GetTerrainCliffLevel);
	lua_register(l, "SetWaterBaseColor", lua_SetWaterBaseColor);
	lua_register(l, "SetWaterDeforms", lua_SetWaterDeforms);
	lua_register(l, "GetTerrainType", lua_GetTerrainType);
	lua_register(l, "GetTerrainVariance", lua_GetTerrainVariance);
	lua_register(l, "SetTerrainType", lua_SetTerrainType);
	lua_register(l, "IsTerrainPathable", lua_IsTerrainPathable);
	lua_register(l, "SetTerrainPathable", lua_SetTerrainPathable);
	lua_register(l, "CreateImage", lua_CreateImage);
	lua_register(l, "DestroyImage", lua_DestroyImage);
	lua_register(l, "ShowImage", lua_ShowImage);
	lua_register(l, "SetImageConstantHeight", lua_SetImageConstantHeight);
	lua_register(l, "SetImagePosition", lua_SetImagePosition);
	lua_register(l, "SetImageColor", lua_SetImageColor);
	lua_register(l, "SetImageRender", lua_SetImageRender);
	lua_register(l, "SetImageRenderAlways", lua_SetImageRenderAlways);
	lua_register(l, "SetImageAboveWater", lua_SetImageAboveWater);
	lua_register(l, "SetImageType", lua_SetImageType);
	lua_register(l, "CreateUbersplat", lua_CreateUbersplat);
	lua_register(l, "DestroyUbersplat", lua_DestroyUbersplat);
	lua_register(l, "ResetUbersplat", lua_ResetUbersplat);
	lua_register(l, "FinishUbersplat", lua_FinishUbersplat);
	lua_register(l, "ShowUbersplat", lua_ShowUbersplat);
	lua_register(l, "SetUbersplatRender", lua_SetUbersplatRender);
	lua_register(l, "SetUbersplatRenderAlways", lua_SetUbersplatRenderAlways);
	lua_register(l, "SetBlight", lua_SetBlight);
	lua_register(l, "SetBlightLoc", lua_SetBlightLoc);
	lua_register(l, "SetBlightRect", lua_SetBlightRect);
	lua_register(l, "SetBlightPoint", lua_SetBlightPoint);
	lua_register(l, "CreateBlightedGoldmine", lua_CreateBlightedGoldmine);
	lua_register(l, "IsPointBlighted", lua_IsPointBlighted);
	lua_register(l, "SetDoodadAnimation", lua_SetDoodadAnimation);
	lua_register(l, "SetDoodadAnimationRect", lua_SetDoodadAnimationRect);
	lua_register(l, "StartMeleeAI", lua_StartMeleeAI);
	lua_register(l, "StartCampaignAI", lua_StartCampaignAI);
	lua_register(l, "CommandAI", lua_CommandAI);
	lua_register(l, "PauseCompAI", lua_PauseCompAI);
	lua_register(l, "GetAIDifficulty", lua_GetAIDifficulty);
	lua_register(l, "RemoveGuardPosition", lua_RemoveGuardPosition);
	lua_register(l, "RecycleGuardPosition", lua_RecycleGuardPosition);
	lua_register(l, "RemoveAllGuardPositions", lua_RemoveAllGuardPositions);
	lua_register(l, "ExecuteFunc", lua_ExecuteFunc);
	lua_register(l, "Cheat", lua_Cheat);
	lua_register(l, "IsNoVictoryCheat", lua_IsNoVictoryCheat);
	lua_register(l, "IsNoDefeatCheat", lua_IsNoDefeatCheat);
	lua_register(l, "Preload", lua_Preload);
	lua_register(l, "PreloadEnd", lua_PreloadEnd);
	lua_register(l, "PreloadStart", lua_PreloadStart);
	lua_register(l, "PreloadRefresh", lua_PreloadRefresh);
	lua_register(l, "PreloadEndEx", lua_PreloadEndEx);
	lua_register(l, "PreloadGenStart", lua_PreloadGenStart);
	lua_register(l, "PreloadGenClear", lua_PreloadGenClear);
	lua_register(l, "PreloadGenEnd", lua_PreloadGenEnd);
	lua_register(l, "Preloader", lua_Preloader);

}

//------------------------C Functions

LUA lua_DebugS(lua_State* l)
{
	DebugS(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_DebugFI(lua_State* l)
{
	DebugFI(to_jString(lua_tostring(l, 1)), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_DebugUnitID(lua_State* l)
{
	DebugUnitID(to_jString(lua_tostring(l, 1)), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_DisplayText(lua_State* l)
{
	DisplayText((jInteger)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_DisplayTextI(lua_State* l)
{
	DisplayTextI((jInteger)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_DisplayTextII(lua_State* l)
{
	DisplayTextII((jInteger)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_DisplayTextIII(lua_State* l)
{
	DisplayTextIII((jInteger)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_SuicideUnit(lua_State* l)
{
	SuicideUnit((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SuicideUnitEx(lua_State* l)
{
	SuicideUnitEx((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_Sleep(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	Sleep(&a1);

	return 0;
}

LUA lua_StartThread(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 1);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	StartThread((jCode)trigger);

	return 0;
}

LUA lua_GetAiPlayer(lua_State* l)
{
	lua_pushinteger(l, GetAiPlayer());

	return 1;
}

LUA lua_DoAiScriptDebug(lua_State* l)
{
	lua_pushboolean(l, DoAiScriptDebug());

	return 1;
}

LUA lua_GetHeroId(lua_State* l)
{
	lua_pushinteger(l, GetHeroId());

	return 1;
}

LUA lua_GetHeroLevelAI(lua_State* l)
{
	lua_pushinteger(l, GetHeroLevelAI());

	return 1;
}

LUA lua_SetHeroLevels(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 1);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	SetHeroLevels((jCode)trigger);

	return 0;
}

LUA lua_SetNewHeroes(lua_State* l)
{
	SetNewHeroes(lua_toboolean(l, 1));

	return 0;
}

LUA lua_GetUnitCount(lua_State* l)
{
	lua_pushinteger(l, GetUnitCount((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerUnitTypeCount(lua_State* l)
{
	lua_pushinteger(l, GetPlayerUnitTypeCount((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetTownUnitCount(lua_State* l)
{
	lua_pushinteger(l, GetTownUnitCount((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3)));

	return 1;
}

LUA lua_GetUnitCountDone(lua_State* l)
{
	lua_pushinteger(l, GetUnitCountDone((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUpgradeLevel(lua_State* l)
{
	lua_pushinteger(l, GetUpgradeLevel((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitGoldCost(lua_State* l)
{
	lua_pushinteger(l, GetUnitGoldCost((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitWoodCost(lua_State* l)
{
	lua_pushinteger(l, GetUnitWoodCost((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitBuildTime(lua_State* l)
{
	lua_pushinteger(l, GetUnitBuildTime((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUpgradeGoldCost(lua_State* l)
{
	lua_pushinteger(l, GetUpgradeGoldCost((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUpgradeWoodCost(lua_State* l)
{
	lua_pushinteger(l, GetUpgradeWoodCost((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetEnemyPower(lua_State* l)
{
	lua_pushinteger(l, GetEnemyPower());

	return 1;
}

LUA lua_GetMinesOwned(lua_State* l)
{
	lua_pushinteger(l, GetMinesOwned());

	return 1;
}

LUA lua_GetGoldOwned(lua_State* l)
{
	lua_pushinteger(l, GetGoldOwned());

	return 1;
}

LUA lua_TownWithMine(lua_State* l)
{
	lua_pushinteger(l, TownWithMine());

	return 1;
}

LUA lua_TownHasMine(lua_State* l)
{
	lua_pushboolean(l, TownHasMine((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_TownHasHall(lua_State* l)
{
	lua_pushboolean(l, TownHasHall((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetNextExpansion(lua_State* l)
{
	lua_pushinteger(l, GetNextExpansion());

	return 1;
}

LUA lua_GetExpansionPeon(lua_State* l)
{
	lua_pushinteger(l, GetExpansionPeon());

	return 1;
}

LUA lua_GetEnemyExpansion(lua_State* l)
{
	lua_pushinteger(l, GetEnemyExpansion());

	return 1;
}

LUA lua_SetExpansion(lua_State* l)
{
	lua_pushboolean(l, SetExpansion((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetBuilding(lua_State* l)
{
	lua_pushinteger(l, GetBuilding((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetAllianceTarget(lua_State* l)
{
	SetAllianceTarget((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GetAllianceTarget(lua_State* l)
{
	lua_pushinteger(l, GetAllianceTarget());

	return 1;
}

LUA lua_SetProduce(lua_State* l)
{
	lua_pushboolean(l, SetProduce((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_MergeUnits(lua_State* l)
{
	lua_pushboolean(l, MergeUnits((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_ConvertUnits(lua_State* l)
{
	lua_pushboolean(l, ConvertUnits((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_SetUpgrade(lua_State* l)
{
	lua_pushboolean(l, SetUpgrade((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_Unsummon(lua_State* l)
{
	Unsummon((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ClearHarvestAI(lua_State* l)
{
	ClearHarvestAI();

	return 0;
}

LUA lua_HarvestGold(lua_State* l)
{
	HarvestGold((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_HarvestWood(lua_State* l)
{
	HarvestWood((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_StopGathering(lua_State* l)
{
	StopGathering();

	return 0;
}

LUA lua_AddGuardPost(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	AddGuardPost((jInteger)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_FillGuardPosts(lua_State* l)
{
	FillGuardPosts();

	return 0;
}

LUA lua_ReturnGuardPosts(lua_State* l)
{
	ReturnGuardPosts();

	return 0;
}

LUA lua_CreateCaptains(lua_State* l)
{
	CreateCaptains();

	return 0;
}

LUA lua_SetCaptainHome(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetCaptainHome((jInteger)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_ResetCaptainLocs(lua_State* l)
{
	ResetCaptainLocs();

	return 0;
}

LUA lua_ShiftTownSpot(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	ShiftTownSpot(&a1, &a2);

	return 0;
}

LUA lua_SetCaptainChanges(lua_State* l)
{
	SetCaptainChanges(lua_toboolean(l, 1));

	return 0;
}

LUA lua_TeleportCaptain(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	TeleportCaptain(&a1, &a2);

	return 0;
}

LUA lua_ClearCaptainTargets(lua_State* l)
{
	ClearCaptainTargets();

	return 0;
}

LUA lua_CaptainVsUnits(lua_State* l)
{
	CaptainVsUnits((HPLAYER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_CaptainVsPlayer(lua_State* l)
{
	CaptainVsPlayer((HPLAYER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_CaptainAttack(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	CaptainAttack(&a1, &a2);

	return 0;
}

LUA lua_GroupTimedLife(lua_State* l)
{
	GroupTimedLife(lua_toboolean(l, 1));

	return 0;
}

LUA lua_CaptainGoHome(lua_State* l)
{
	CaptainGoHome();

	return 0;
}

LUA lua_CaptainIsHome(lua_State* l)
{
	lua_pushboolean(l, CaptainIsHome());

	return 1;
}

LUA lua_CaptainRetreating(lua_State* l)
{
	lua_pushboolean(l, CaptainRetreating());

	return 1;
}

LUA lua_CaptainIsFull(lua_State* l)
{
	lua_pushboolean(l, CaptainIsFull());

	return 1;
}

LUA lua_CaptainIsEmpty(lua_State* l)
{
	lua_pushboolean(l, CaptainIsEmpty());

	return 1;
}

LUA lua_CaptainGroupSize(lua_State* l)
{
	lua_pushinteger(l, CaptainGroupSize());

	return 1;
}

LUA lua_CaptainReadiness(lua_State* l)
{
	lua_pushinteger(l, CaptainReadiness());

	return 1;
}

LUA lua_CaptainReadinessHP(lua_State* l)
{
	lua_pushinteger(l, CaptainReadinessHP());

	return 1;
}

LUA lua_CaptainReadinessMa(lua_State* l)
{
	lua_pushinteger(l, CaptainReadinessMa());

	return 1;
}

LUA lua_CaptainInCombat(lua_State* l)
{
	lua_pushboolean(l, CaptainInCombat(lua_toboolean(l, 1)));

	return 1;
}

LUA lua_TownThreatened(lua_State* l)
{
	lua_pushboolean(l, TownThreatened());

	return 1;
}

LUA lua_CaptainAtGoal(lua_State* l)
{
	lua_pushboolean(l, CaptainAtGoal());

	return 1;
}

LUA lua_CreepsOnMap(lua_State* l)
{
	lua_pushboolean(l, CreepsOnMap());

	return 1;
}

LUA lua_RemoveInjuries(lua_State* l)
{
	RemoveInjuries();

	return 0;
}

LUA lua_RemoveSiege(lua_State* l)
{
	RemoveSiege();

	return 0;
}

LUA lua_IsTowered(lua_State* l)
{
	lua_pushboolean(l, IsTowered((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_DisablePathing(lua_State* l)
{
	DisablePathing();

	return 0;
}

LUA lua_SetAmphibious(lua_State* l)
{
	SetAmphibious();

	return 0;
}

LUA lua_InitAssault(lua_State* l)
{
	InitAssault();

	return 0;
}

LUA lua_AddAssault(lua_State* l)
{
	lua_pushboolean(l, AddAssault((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_AddDefenders(lua_State* l)
{
	lua_pushboolean(l, AddDefenders((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetCreepCamp(lua_State* l)
{
	lua_pushinteger(l, GetCreepCamp((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3)));

	return 1;
}

LUA lua_StartGetEnemyBase(lua_State* l)
{
	StartGetEnemyBase();

	return 0;
}

LUA lua_WaitGetEnemyBase(lua_State* l)
{
	lua_pushboolean(l, WaitGetEnemyBase());

	return 1;
}

LUA lua_GetMegaTarget(lua_State* l)
{
	lua_pushinteger(l, GetMegaTarget());

	return 1;
}

LUA lua_GetEnemyBase(lua_State* l)
{
	lua_pushinteger(l, GetEnemyBase());

	return 1;
}

LUA lua_GetExpansionFoe(lua_State* l)
{
	lua_pushinteger(l, GetExpansionFoe());

	return 1;
}

LUA lua_GetExpansionX(lua_State* l)
{
	lua_pushinteger(l, GetExpansionX());

	return 1;
}

LUA lua_GetExpansionY(lua_State* l)
{
	lua_pushinteger(l, GetExpansionY());

	return 1;
}

LUA lua_SetStagePoint(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetStagePoint(&a1, &a2);

	return 0;
}

LUA lua_AttackMoveKill(lua_State* l)
{
	AttackMoveKill((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_AttackMoveXY(lua_State* l)
{
	AttackMoveXY((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_LoadZepWave(lua_State* l)
{
	LoadZepWave((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SuicidePlayer(lua_State* l)
{
	lua_pushboolean(l, SuicidePlayer((HPLAYER)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_SuicidePlayerUnits(lua_State* l)
{
	lua_pushboolean(l, SuicidePlayerUnits((HPLAYER)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_UnitAlive(lua_State* l)
{
	lua_pushboolean(l, UnitAlive((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitInvis(lua_State* l)
{
	lua_pushboolean(l, UnitInvis((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IgnoredUnits(lua_State* l)
{
	lua_pushinteger(l, IgnoredUnits((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CommandsWaiting(lua_State* l)
{
	lua_pushinteger(l, CommandsWaiting());

	return 1;
}

LUA lua_GetLastCommand(lua_State* l)
{
	lua_pushinteger(l, GetLastCommand());

	return 1;
}

LUA lua_GetLastData(lua_State* l)
{
	lua_pushinteger(l, GetLastData());

	return 1;
}

LUA lua_PopLastCommand(lua_State* l)
{
	PopLastCommand();

	return 0;
}

LUA lua_SetCampaignAI(lua_State* l)
{
	SetCampaignAI();

	return 0;
}

LUA lua_SetMeleeAI(lua_State* l)
{
	SetMeleeAI();

	return 0;
}

LUA lua_SetTargetHeroes(lua_State* l)
{
	SetTargetHeroes(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetHeroesFlee(lua_State* l)
{
	SetHeroesFlee(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetHeroesBuyItems(lua_State* l)
{
	SetHeroesBuyItems(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetIgnoreInjured(lua_State* l)
{
	SetIgnoreInjured(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetPeonsRepair(lua_State* l)
{
	SetPeonsRepair(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetRandomPaths(lua_State* l)
{
	SetRandomPaths(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetDefendPlayer(lua_State* l)
{
	SetDefendPlayer(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetHeroesTakeItems(lua_State* l)
{
	SetHeroesTakeItems(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetUnitsFlee(lua_State* l)
{
	SetUnitsFlee(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetGroupsFlee(lua_State* l)
{
	SetGroupsFlee(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetSlowChopping(lua_State* l)
{
	SetSlowChopping(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetSmartArtillery(lua_State* l)
{
	SetSmartArtillery(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetWatchMegaTargets(lua_State* l)
{
	SetWatchMegaTargets(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetReplacementCount(lua_State* l)
{
	SetReplacementCount((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_PurchaseZeppelin(lua_State* l)
{
	PurchaseZeppelin();

	return 0;
}

LUA lua_MeleeDifficulty(lua_State* l)
{
	lua_pushinteger(l, MeleeDifficulty());

	return 1;
}

LUA lua_DebugBreak(lua_State* l)
{
	DebugBreak((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_Deg2Rad(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(Deg2Rad(&a1)));

	return 1;
}

LUA lua_Rad2Deg(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(Rad2Deg(&a1)));

	return 1;
}

LUA lua_Sin(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	
	lua_pushnumber(l, from_jReal(Sin(&a1)));

	return 1;
}

LUA lua_Cos(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(Cos(&a1)));

	return 1;
}

LUA lua_Tan(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(Tan(&a1)));

	return 1;
}

LUA lua_Asin(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(Asin(&a1)));

	return 1;
}

LUA lua_Acos(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(Acos(&a1)));

	return 1;
}

LUA lua_Atan(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(Atan(&a1)));

	return 1;
}

LUA lua_Atan2(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushnumber(l, from_jReal(Atan2(&a1, &a2)));

	return 1;
}

LUA lua_SquareRoot(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushnumber(l, from_jReal(SquareRoot(&a1)));

	return 1;
}

LUA lua_Pow(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushnumber(l, from_jReal(Pow(&a1, &a2)));

	return 1;
}

LUA lua_I2R(lua_State* l)
{
	lua_pushnumber(l, from_jReal(I2R((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_R2I(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushinteger(l, R2I(&a1));

	return 1;
}

LUA lua_I2S(lua_State* l)
{
	lua_pushstring(l, from_jString(I2S((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_R2S(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushstring(l, from_jString(R2S(&a1)));

	return 1;
}

LUA lua_R2SW(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	lua_pushstring(l, from_jString(R2SW(&a1, (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3))));

	return 1;
}

LUA lua_S2I(lua_State* l)
{
	lua_pushinteger(l, S2I(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_S2R(lua_State* l)
{
	lua_pushnumber(l, from_jReal(S2R(to_jString(lua_tostring(l, 1)))));

	return 1;
}

LUA lua_GetHandleId(lua_State* l)
{
	lua_pushinteger(l, GetHandleId((HHANDLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SubString(lua_State* l)
{
	lua_pushstring(l, from_jString(SubString(to_jString(lua_tostring(l, 1)), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3))));

	return 1;
}

LUA lua_StringLength(lua_State* l)
{
	lua_pushinteger(l, StringLength(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_StringCase(lua_State* l)
{
	lua_pushstring(l, from_jString(StringCase(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2))));

	return 1;
}

LUA lua_StringHash(lua_State* l)
{
	lua_pushinteger(l, StringHash(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_GetLocalizedString(lua_State* l)
{
	lua_pushstring(l, from_jString(GetLocalizedString(to_jString(lua_tostring(l, 1)))));

	return 1;
}

LUA lua_GetLocalizedHotkey(lua_State* l)
{
	lua_pushinteger(l, GetLocalizedHotkey(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_ConvertRace(lua_State* l)
{
	lua_pushinteger(l, ConvertRace((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertAllianceType(lua_State* l)
{
	lua_pushinteger(l, ConvertAllianceType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertRacePref(lua_State* l)
{
	lua_pushinteger(l, ConvertRacePref((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertIGameState(lua_State* l)
{
	lua_pushinteger(l, ConvertIGameState((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertFGameState(lua_State* l)
{
	lua_pushinteger(l, ConvertFGameState((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlayerState(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerState((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlayerScore(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerScore((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertStartLocPrio(lua_State* l)
{
	lua_pushinteger(l, ConvertStartLocPrio((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlayerGameResult(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerGameResult((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertUnitState(lua_State* l)
{
	lua_pushinteger(l, ConvertUnitState((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertAIDifficulty(lua_State* l)
{
	lua_pushinteger(l, ConvertAIDifficulty((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertGameEvent(lua_State* l)
{
	lua_pushinteger(l, ConvertGameEvent((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlayerEvent(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerEvent((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlayerUnitEvent(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerUnitEvent((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertUnitEvent(lua_State* l)
{
	lua_pushinteger(l, ConvertUnitEvent((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertWidgetEvent(lua_State* l)
{
	lua_pushinteger(l, ConvertWidgetEvent((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertDialogEvent(lua_State* l)
{
	lua_pushinteger(l, ConvertDialogEvent((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertLimitOp(lua_State* l)
{
	lua_pushinteger(l, ConvertLimitOp((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertUnitType(lua_State* l)
{
	lua_pushinteger(l, ConvertUnitType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertGameSpeed(lua_State* l)
{
	lua_pushinteger(l, ConvertGameSpeed((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlacement(lua_State* l)
{
	lua_pushinteger(l, ConvertPlacement((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertGameDifficulty(lua_State* l)
{
	lua_pushinteger(l, ConvertGameDifficulty((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertGameType(lua_State* l)
{
	lua_pushinteger(l, ConvertGameType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertMapFlag(lua_State* l)
{
	lua_pushinteger(l, ConvertMapFlag((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertMapVisibility(lua_State* l)
{
	lua_pushinteger(l, ConvertMapVisibility((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertMapSetting(lua_State* l)
{
	lua_pushinteger(l, ConvertMapSetting((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertMapDensity(lua_State* l)
{
	lua_pushinteger(l, ConvertMapDensity((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertMapControl(lua_State* l)
{
	lua_pushinteger(l, ConvertMapControl((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlayerColor(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerColor((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPlayerSlotState(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerSlotState((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertVolumeGroup(lua_State* l)
{
	lua_pushinteger(l, ConvertVolumeGroup((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertCameraField(lua_State* l)
{
	lua_pushinteger(l, ConvertCameraField((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertBlendMode(lua_State* l)
{
	lua_pushinteger(l, ConvertBlendMode((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertRarityControl(lua_State* l)
{
	lua_pushinteger(l, ConvertRarityControl((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertTexMapFlags(lua_State* l)
{
	lua_pushinteger(l, ConvertTexMapFlags((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertFogState(lua_State* l)
{
	lua_pushinteger(l, ConvertFogState((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertEffectType(lua_State* l)
{
	lua_pushinteger(l, ConvertEffectType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertVersion(lua_State* l)
{
	lua_pushinteger(l, ConvertVersion((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertItemType(lua_State* l)
{
	lua_pushinteger(l, ConvertItemType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertAttackType(lua_State* l)
{
	lua_pushinteger(l, ConvertAttackType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertDamageType(lua_State* l)
{
	lua_pushinteger(l, ConvertDamageType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertWeaponType(lua_State* l)
{
	lua_pushinteger(l, ConvertWeaponType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertSoundType(lua_State* l)
{
	lua_pushinteger(l, ConvertSoundType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ConvertPathingType(lua_State* l)
{
	lua_pushinteger(l, ConvertPathingType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetMapName(lua_State* l)
{
	SetMapName(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_SetMapDescription(lua_State* l)
{
	SetMapDescription(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_SetTeams(lua_State* l)
{
	SetTeams((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetPlayers(lua_State* l)
{
	SetPlayers((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetGameTypeSupported(lua_State* l)
{
	SetGameTypeSupported((HGAMETYPE)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetMapFlag(lua_State* l)
{
	SetMapFlag((HMAPFLAG)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetGameSpeed(lua_State* l)
{
	SetGameSpeed((HGAMESPEED)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetGamePlacement(lua_State* l)
{
	SetGamePlacement((HPLACEMENT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetGameDifficulty(lua_State* l)
{
	SetGameDifficulty((HGAMEDIFFICULTY)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetResourceDensity(lua_State* l)
{
	SetResourceDensity((HMAPDENSITY)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetCreatureDensity(lua_State* l)
{
	SetCreatureDensity((HMAPDENSITY)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DefineStartLocation(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	DefineStartLocation((jInteger)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_DefineStartLocationLoc(lua_State* l)
{
	DefineStartLocationLoc((jInteger)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetStartLocPrioCount(lua_State* l)
{
	SetStartLocPrioCount((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetStartLocPrio(lua_State* l)
{
	SetStartLocPrio((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HSTARTLOCPRIO)lua_tointeger(l, 4));

	return 0;
}

LUA lua_GetStartLocPrioSlot(lua_State* l)
{
	lua_pushinteger(l, GetStartLocPrioSlot((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetStartLocPrio(lua_State* l)
{
	lua_pushinteger(l, GetStartLocPrio((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetTeams(lua_State* l)
{
	lua_pushinteger(l, GetTeams());

	return 1;
}

LUA lua_GetPlayers(lua_State* l)
{
	lua_pushinteger(l, GetPlayers());

	return 1;
}

LUA lua_IsGameTypeSupported(lua_State* l)
{
	lua_pushboolean(l, IsGameTypeSupported((HGAMETYPE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsMapFlagSet(lua_State* l)
{
	lua_pushboolean(l, IsMapFlagSet((HMAPFLAG)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetGameTypeSelected(lua_State* l)
{
	lua_pushinteger(l, GetGameTypeSelected());

	return 1;
}

LUA lua_GetGamePlacement(lua_State* l)
{
	lua_pushinteger(l, GetGamePlacement());

	return 1;
}

LUA lua_GetGameSpeed(lua_State* l)
{
	lua_pushinteger(l, GetGameSpeed());

	return 1;
}

LUA lua_GetGameDifficulty(lua_State* l)
{
	lua_pushinteger(l, GetGameDifficulty());

	return 1;
}

LUA lua_GetResourceDensity(lua_State* l)
{
	lua_pushinteger(l, GetResourceDensity());

	return 1;
}

LUA lua_GetCreatureDensity(lua_State* l)
{
	lua_pushinteger(l, GetCreatureDensity());

	return 1;
}

LUA lua_GetStartLocationX(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetStartLocationX((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetStartLocationY(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetStartLocationY((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetStartLocationLoc(lua_State* l)
{
	lua_pushinteger(l, GetStartLocationLoc((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetPlayerTeam(lua_State* l)
{
	SetPlayerTeam((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetPlayerStartLocation(lua_State* l)
{
	SetPlayerStartLocation((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_ForcePlayerStartLocation(lua_State* l)
{
	ForcePlayerStartLocation((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetPlayerAlliance(lua_State* l)
{
	SetPlayerAlliance((HPLAYER)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HALLIANCETYPE)lua_tointeger(l, 3), lua_toboolean(l, 4));

	return 0;
}

LUA lua_SetPlayerTaxRate(lua_State* l)
{
	SetPlayerTaxRate((HPLAYER)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HPLAYERSTATE)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_SetPlayerRacePreference(lua_State* l)
{
	SetPlayerRacePreference((HPLAYER)lua_tointeger(l, 1), (HRACEPREFERENCE)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetPlayerRaceSelectable(lua_State* l)
{
	SetPlayerRaceSelectable((HPLAYER)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetPlayerController(lua_State* l)
{
	SetPlayerController((HPLAYER)lua_tointeger(l, 1), (HMAPCONTROL)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetPlayerColor(lua_State* l)
{
	SetPlayerColor((HPLAYER)lua_tointeger(l, 1), (HPLAYERCOLOR)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetPlayerOnScoreScreen(lua_State* l)
{
	SetPlayerOnScoreScreen((HPLAYER)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetPlayerName(lua_State* l)
{
	SetPlayerName((HPLAYER)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_GetPlayerTeam(lua_State* l)
{
	lua_pushinteger(l, GetPlayerTeam((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerName(lua_State* l)
{
	lua_pushstring(l, GetPlayerName((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerStartLocation(lua_State* l)
{
	lua_pushinteger(l, GetPlayerStartLocation((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerStartLocationX(lua_State* l)
{
	lua_pushinteger(l, GetPlayerStartLocationX((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerStartLocationY(lua_State* l)
{
	lua_pushinteger(l, GetPlayerStartLocationY((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerColor(lua_State* l)
{
	lua_pushinteger(l, GetPlayerColor((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerSelectable(lua_State* l)
{
	lua_pushboolean(l, GetPlayerSelectable((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerController(lua_State* l)
{
	lua_pushinteger(l, GetPlayerController((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerSlotState(lua_State* l)
{
	lua_pushinteger(l, GetPlayerSlotState((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerTaxRate(lua_State* l)
{
	lua_pushinteger(l, GetPlayerTaxRate((HPLAYER)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HPLAYERSTATE)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IsPlayerRacePrefSet(lua_State* l)
{
	lua_pushboolean(l, IsPlayerRacePrefSet((HPLAYER)lua_tointeger(l, 1), (HRACEPREFERENCE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_Location(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushinteger(l, Location(&a1, &a2));

	return 1;
}

LUA lua_RemoveLocation(lua_State* l)
{
	RemoveLocation((HLOCATION)lua_tointeger(l, 1));

	return 0;
}

LUA lua_MoveLocation(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	MoveLocation((HLOCATION)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_GetLocationX(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetLocationX((HLOCATION)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetLocationY(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetLocationY((HLOCATION)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetLocationZ(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetLocationZ((HLOCATION)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_CreateTimer(lua_State* l)
{
	lua_pushinteger(l, CreateTimer());

	return 1;
}

LUA lua_DestroyTimer(lua_State* l)
{
	DestroyTimer((HTIMER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_TimerStart(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 4);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	TimerStart((HTIMER)lua_tointeger(l, 1), &a2, lua_toboolean(l, 3), (jCode)trigger);

	return 0;
}

LUA lua_TimerGetTimeout(lua_State* l)
{
	lua_pushnumber(l, from_jReal(TimerGetTimeout((HTIMER)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_TimerGetElapsed(lua_State* l)
{
	lua_pushnumber(l, from_jReal(TimerGetElapsed((HTIMER)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_TimerGetRemaining(lua_State* l)
{
	lua_pushnumber(l, from_jReal(TimerGetRemaining((HTIMER)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_PauseTimer(lua_State* l)
{
	PauseTimer((HTIMER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ResumeTimer(lua_State* l)
{
	ResumeTimer((HTIMER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GetExpiredTimer(lua_State* l)
{
	lua_pushinteger(l, GetExpiredTimer());

	return 1;
}

LUA lua_Condition(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_CONDITION_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 1);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	lua_pushinteger(l, Condition((jCode)trigger));

	return 1;
}

LUA lua_DestroyCondition(lua_State* l)
{
	DestroyCondition((HCONDITIONFUNC)lua_tointeger(l, 1));

	return 0;
}

LUA lua_Filter(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_CONDITION_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 1);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	lua_pushinteger(l, Filter((jCode)trigger));

	return 1;
}

LUA lua_DestroyFilter(lua_State* l)
{
	DestroyFilter((HFILTERFUNC)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DestroyBoolExpr(lua_State* l)
{
	DestroyBoolExpr((HBOOLEXPR)lua_tointeger(l, 1));

	return 0;
}

LUA lua_And(lua_State* l)
{
	lua_pushinteger(l, And((HBOOLEXPR)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_Or(lua_State* l)
{
	lua_pushinteger(l, Or((HBOOLEXPR)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_Not(lua_State* l)
{
	lua_pushinteger(l, Not((HBOOLEXPR)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CreateRegion(lua_State* l)
{
	lua_pushinteger(l, CreateRegion());

	return 1;
}

LUA lua_RemoveRegion(lua_State* l)
{
	RemoveRegion((HREGION)lua_tointeger(l, 1));

	return 0;
}

LUA lua_RegionAddRect(lua_State* l)
{
	RegionAddRect((HREGION)lua_tointeger(l, 1), (HRECT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_RegionClearRect(lua_State* l)
{
	RegionClearRect((HREGION)lua_tointeger(l, 1), (HRECT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_RegionAddCell(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	RegionAddCell((HREGION)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_RegionAddCellAtLoc(lua_State* l)
{
	RegionAddCellAtLoc((HREGION)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2));

	return 0;
}

LUA lua_RegionClearCell(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	RegionClearCell((HREGION)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_RegionClearCellAtLoc(lua_State* l)
{
	RegionClearCellAtLoc((HREGION)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2));

	return 0;
}

LUA lua_IsUnitInRegion(lua_State* l)
{
	lua_pushboolean(l, IsUnitInRegion((HREGION)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsPointInRegion(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushboolean(l, IsPointInRegion((HREGION)lua_tointeger(l, 1), &a2, &a3));

	return 1;
}

LUA lua_IsLocationInRegion(lua_State* l)
{
	lua_pushboolean(l, IsLocationInRegion((HREGION)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_Rect(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, Rect(&a1, &a2, &a3, &a4));

	return 1;
}

LUA lua_RectFromLoc(lua_State* l)
{
	lua_pushinteger(l, RectFromLoc((HLOCATION)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_RemoveRect(lua_State* l)
{
	RemoveRect((HRECT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetRect(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	SetRect((HRECT)lua_tointeger(l, 1), &a2, &a3, &a4, &a5);

	return 0;
}

LUA lua_SetRectFromLoc(lua_State* l)
{
	SetRectFromLoc((HRECT)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2), (HLOCATION)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GetRectCenterX(lua_State* l)
{
	lua_pushinteger(l, GetRectCenterX((HRECT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetRectCenterY(lua_State* l)
{
	lua_pushinteger(l, GetRectCenterY((HRECT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_MoveRectTo(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	MoveRectTo((HRECT)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_MoveRectToLoc(lua_State* l)
{
	MoveRectToLoc((HRECT)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetRectMinX(lua_State* l)
{
	lua_pushinteger(l, GetRectMinX((HRECT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetRectMinY(lua_State* l)
{
	lua_pushinteger(l, GetRectMinY((HRECT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetRectMaxX(lua_State* l)
{
	lua_pushinteger(l, GetRectMaxX((HRECT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetRectMaxY(lua_State* l)
{
	lua_pushinteger(l, GetRectMaxY((HRECT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetWorldBounds(lua_State* l)
{
	lua_pushinteger(l, GetWorldBounds());

	return 1;
}

LUA lua_SetFogStateRect(lua_State* l)
{
	SetFogStateRect((HPLAYER)lua_tointeger(l, 1), (HFOGSTATE)lua_tointeger(l, 2), (HRECT)lua_tointeger(l, 3), lua_toboolean(l, 4));

	return 0;
}

LUA lua_SetFogStateRadius(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	SetFogStateRadius((HPLAYER)lua_tointeger(l, 1), (HFOGSTATE)lua_tointeger(l, 2), &a3, &a4, &a5, lua_toboolean(l, 6));

	return 0;
}

LUA lua_SetFogStateRadiusLoc(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetFogStateRadiusLoc((HPLAYER)lua_tointeger(l, 1), (HFOGSTATE)lua_tointeger(l, 2), (HLOCATION)lua_tointeger(l, 3), &a4, lua_toboolean(l, 5));

	return 0;
}

LUA lua_FogMaskEnable(lua_State* l)
{
	FogMaskEnable(lua_toboolean(l, 1));

	return 0;
}

LUA lua_IsFogMaskEnabled(lua_State* l)
{
	lua_pushboolean(l, IsFogMaskEnabled());

	return 1;
}

LUA lua_FogEnable(lua_State* l)
{
	FogEnable(lua_toboolean(l, 1));

	return 0;
}

LUA lua_IsFogEnabled(lua_State* l)
{
	lua_pushboolean(l, IsFogEnabled());

	return 1;
}

LUA lua_CreateFogModifierRect(lua_State* l)
{
	lua_pushinteger(l, CreateFogModifierRect((HPLAYER)lua_tointeger(l, 1), (HFOGSTATE)lua_tointeger(l, 2), (HRECT)lua_tointeger(l, 3), lua_toboolean(l, 4), lua_toboolean(l, 5)));

	return 1;
}

LUA lua_CreateFogModifierRadius(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, CreateFogModifierRadius((HPLAYER)lua_tointeger(l, 1), (HFOGSTATE)lua_tointeger(l, 2), &a3, &a4, &a5, lua_toboolean(l, 6), lua_toboolean(l, 7)));

	return 1;
}

LUA lua_CreateFogModifierRadiusLoc(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, CreateFogModifierRadiusLoc((HPLAYER)lua_tointeger(l, 1), (HFOGSTATE)lua_tointeger(l, 2), (HLOCATION)lua_tointeger(l, 3), &a4, lua_toboolean(l, 5), lua_toboolean(l, 6)));

	return 1;
}

LUA lua_DestroyFogModifier(lua_State* l)
{
	DestroyFogModifier((HFOGMODIFIER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_FogModifierStart(lua_State* l)
{
	FogModifierStart((HFOGMODIFIER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_FogModifierStop(lua_State* l)
{
	FogModifierStop((HFOGMODIFIER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_CreateTrigger(lua_State* l)
{
	lua_pushinteger(l, CreateTrigger());

	return 1;
}

LUA lua_DestroyTrigger(lua_State* l)
{
	DestroyTrigger((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ResetTrigger(lua_State* l)
{
	ResetTrigger((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_EnableTrigger(lua_State* l)
{
	EnableTrigger((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DisableTrigger(lua_State* l)
{
	DisableTrigger((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_IsTriggerEnabled(lua_State* l)
{
	lua_pushboolean(l, IsTriggerEnabled((jTrigger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_TriggerWaitOnSleeps(lua_State* l)
{
	TriggerWaitOnSleeps((jTrigger)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsTriggerWaitOnSleeps(lua_State* l)
{
	lua_pushboolean(l, IsTriggerWaitOnSleeps((jTrigger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_TriggerRegisterVariableEvent(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, TriggerRegisterVariableEvent((jTrigger)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HLIMITOP)lua_tointeger(l, 3), &a4));

	return 1;
}

LUA lua_TriggerRegisterTimerEvent(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushinteger(l, TriggerRegisterTimerEvent((jTrigger)lua_tointeger(l, 1), &a2, lua_toboolean(l, 3)));

	return 1;
}

LUA lua_TriggerRegisterTimerExpireEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterTimerExpireEvent((jTrigger)lua_tointeger(l, 1), (HTIMER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_TriggerRegisterGameStateEvent(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, TriggerRegisterGameStateEvent((jTrigger)lua_tointeger(l, 1), (HGAMESTATE)lua_tointeger(l, 2), (HLIMITOP)lua_tointeger(l, 3), &a4));

	return 1;
}

LUA lua_GetEventGameState(lua_State* l)
{
	lua_pushinteger(l, GetEventGameState());

	return 1;
}

LUA lua_TriggerRegisterDialogEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterDialogEvent((jTrigger)lua_tointeger(l, 1), (HDIALOG)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_TriggerRegisterDialogButtonEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterDialogButtonEvent((jTrigger)lua_tointeger(l, 1), (HBUTTON)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetClickedButton(lua_State* l)
{
	lua_pushinteger(l, GetClickedButton());

	return 1;
}

LUA lua_GetClickedDialog(lua_State* l)
{
	lua_pushinteger(l, GetClickedDialog());

	return 1;
}

LUA lua_GetTournamentFinishSoonTimeRemaining(lua_State* l)
{
	lua_pushinteger(l, GetTournamentFinishSoonTimeRemaining());

	return 1;
}

LUA lua_GetTournamentFinishNowRule(lua_State* l)
{
	lua_pushinteger(l, GetTournamentFinishNowRule());

	return 1;
}

LUA lua_GetTournamentFinishNowPlayer(lua_State* l)
{
	lua_pushinteger(l, GetTournamentFinishNowPlayer());

	return 1;
}

LUA lua_GetTournamentScore(lua_State* l)
{
	lua_pushinteger(l, GetTournamentScore((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetSaveBasicFilename(lua_State* l)
{
	lua_pushstring(l, from_jString(GetSaveBasicFilename()));

	return 1;
}

LUA lua_TriggerRegisterGameEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterGameEvent((jTrigger)lua_tointeger(l, 1), (HGAMEEVENT)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetWinningPlayer(lua_State* l)
{
	lua_pushinteger(l, GetWinningPlayer());

	return 1;
}

LUA lua_TriggerRegisterPlayerStateEvent(lua_State* l)
{
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, TriggerRegisterPlayerStateEvent((jTrigger)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HPLAYERSTATE)lua_tointeger(l, 3), (HLIMITOP)lua_tointeger(l, 4), &a5));

	return 1;
}

LUA lua_GetEventPlayerState(lua_State* l)
{
	lua_pushinteger(l, GetEventPlayerState());

	return 1;
}

LUA lua_TriggerRegisterPlayerEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterPlayerEvent((jTrigger)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HPLAYEREVENT)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_TriggerRegisterPlayerUnitEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterPlayerUnitEvent((jTrigger)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HPLAYERUNITEVENT)lua_tointeger(l, 3), (HBOOLEXPR)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_GetAttacker(lua_State* l)
{
	lua_pushinteger(l, GetAttacker());

	return 1;
}

LUA lua_GetRescuer(lua_State* l)
{
	lua_pushinteger(l, GetRescuer());

	return 1;
}

LUA lua_GetDyingUnit(lua_State* l)
{
	lua_pushinteger(l, GetDyingUnit());

	return 1;
}

LUA lua_GetKillingUnit(lua_State* l)
{
	lua_pushinteger(l, GetKillingUnit());

	return 1;
}

LUA lua_GetDecayingUnit(lua_State* l)
{
	lua_pushinteger(l, GetDecayingUnit());

	return 1;
}

LUA lua_GetConstructingStructure(lua_State* l)
{
	lua_pushinteger(l, GetConstructingStructure());

	return 1;
}

LUA lua_GetCancelledStructure(lua_State* l)
{
	lua_pushinteger(l, GetCancelledStructure());

	return 1;
}

LUA lua_GetConstructedStructure(lua_State* l)
{
	lua_pushinteger(l, GetConstructedStructure());

	return 1;
}

LUA lua_GetTrainedUnitType(lua_State* l)
{
	lua_pushinteger(l, GetTrainedUnitType());

	return 1;
}

LUA lua_GetResearchingUnit(lua_State* l)
{
	lua_pushinteger(l, GetResearchingUnit());

	return 1;
}

LUA lua_GetResearched(lua_State* l)
{
	lua_pushinteger(l, GetResearched());

	return 1;
}

LUA lua_GetTrainedUnit(lua_State* l)
{
	lua_pushinteger(l, GetTrainedUnit());

	return 1;
}

LUA lua_GetSellingUnit(lua_State* l)
{
	lua_pushinteger(l, GetSellingUnit());

	return 1;
}

LUA lua_GetSoldUnit(lua_State* l)
{
	lua_pushinteger(l, GetSoldUnit());

	return 1;
}

LUA lua_GetBuyingUnit(lua_State* l)
{
	lua_pushinteger(l, GetBuyingUnit());

	return 1;
}

LUA lua_GetSoldItem(lua_State* l)
{
	lua_pushinteger(l, GetSoldItem());

	return 1;
}

LUA lua_GetChangingUnit(lua_State* l)
{
	lua_pushinteger(l, GetChangingUnit());

	return 1;
}

LUA lua_GetChangingUnitPrevOwner(lua_State* l)
{
	lua_pushinteger(l, GetChangingUnitPrevOwner());

	return 1;
}

LUA lua_GetDetectedUnit(lua_State* l)
{
	lua_pushinteger(l, GetDetectedUnit());

	return 1;
}

LUA lua_GetOrderedUnit(lua_State* l)
{
	lua_pushinteger(l, GetOrderedUnit());

	return 1;
}

LUA lua_OrderId(lua_State* l)
{
	lua_pushinteger(l, OrderId(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_OrderId2String(lua_State* l)
{
	lua_pushstring(l, from_jString(OrderId2String((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_AbilityId(lua_State* l)
{
	lua_pushinteger(l, AbilityId(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_AbilityId2String(lua_State* l)
{
	lua_pushstring(l, from_jString(AbilityId2String((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_UnitId(lua_State* l)
{
	lua_pushinteger(l, UnitId(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_UnitId2String(lua_State* l)
{
	lua_pushstring(l, from_jString(UnitId2String((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetObjectName(lua_State* l)
{
	lua_pushstring(l, from_jString(GetObjectName((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetIssuedOrderId(lua_State* l)
{
	lua_pushinteger(l, GetIssuedOrderId());

	return 1;
}

LUA lua_GetOrderPointX(lua_State* l)
{
	lua_pushinteger(l, GetOrderPointX());

	return 1;
}

LUA lua_GetOrderPointY(lua_State* l)
{
	lua_pushinteger(l, GetOrderPointY());

	return 1;
}

LUA lua_GetOrderPointLoc(lua_State* l)
{
	lua_pushinteger(l, GetOrderPointLoc());

	return 1;
}

LUA lua_GetOrderTarget(lua_State* l)
{
	lua_pushinteger(l, GetOrderTarget());

	return 1;
}

LUA lua_GetOrderTargetDestructable(lua_State* l)
{
	lua_pushinteger(l, GetOrderTargetDestructable());

	return 1;
}

LUA lua_GetOrderTargetItem(lua_State* l)
{
	lua_pushinteger(l, GetOrderTargetItem());

	return 1;
}

LUA lua_GetOrderTargetUnit(lua_State* l)
{
	lua_pushinteger(l, GetOrderTargetUnit());

	return 1;
}

LUA lua_GetSpellAbilityUnit(lua_State* l)
{
	lua_pushinteger(l, GetSpellAbilityUnit());

	return 1;
}

LUA lua_GetSpellAbilityId(lua_State* l)
{
	lua_pushinteger(l, GetSpellAbilityId());

	return 1;
}

LUA lua_GetSpellAbility(lua_State* l)
{
	lua_pushinteger(l, GetSpellAbility());

	return 1;
}

LUA lua_GetSpellTargetLoc(lua_State* l)
{
	lua_pushinteger(l, GetSpellTargetLoc());

	return 1;
}

LUA lua_GetSpellTargetX(lua_State* l)
{
	lua_pushinteger(l, GetSpellTargetX());

	return 1;
}

LUA lua_GetSpellTargetY(lua_State* l)
{
	lua_pushinteger(l, GetSpellTargetY());

	return 1;
}

LUA lua_GetSpellTargetDestructable(lua_State* l)
{
	lua_pushinteger(l, GetSpellTargetDestructable());

	return 1;
}

LUA lua_GetSpellTargetItem(lua_State* l)
{
	lua_pushinteger(l, GetSpellTargetItem());

	return 1;
}

LUA lua_GetSpellTargetUnit(lua_State* l)
{
	lua_pushinteger(l, GetSpellTargetUnit());

	return 1;
}

LUA lua_GetLevelingUnit(lua_State* l)
{
	lua_pushinteger(l, GetLevelingUnit());

	return 1;
}

LUA lua_GetLearningUnit(lua_State* l)
{
	lua_pushinteger(l, GetLearningUnit());

	return 1;
}

LUA lua_GetLearnedSkill(lua_State* l)
{
	lua_pushinteger(l, GetLearnedSkill());

	return 1;
}

LUA lua_GetLearnedSkillLevel(lua_State* l)
{
	lua_pushinteger(l, GetLearnedSkillLevel());

	return 1;
}

LUA lua_GetRevivableUnit(lua_State* l)
{
	lua_pushinteger(l, GetRevivableUnit());

	return 1;
}

LUA lua_GetRevivingUnit(lua_State* l)
{
	lua_pushinteger(l, GetRevivingUnit());

	return 1;
}

LUA lua_GetSummoningUnit(lua_State* l)
{
	lua_pushinteger(l, GetSummoningUnit());

	return 1;
}

LUA lua_GetSummonedUnit(lua_State* l)
{
	lua_pushinteger(l, GetSummonedUnit());

	return 1;
}

LUA lua_GetTransportUnit(lua_State* l)
{
	lua_pushinteger(l, GetTransportUnit());

	return 1;
}

LUA lua_GetLoadedUnit(lua_State* l)
{
	lua_pushinteger(l, GetLoadedUnit());

	return 1;
}

LUA lua_GetManipulatingUnit(lua_State* l)
{
	lua_pushinteger(l, GetManipulatingUnit());

	return 1;
}

LUA lua_GetManipulatedItem(lua_State* l)
{
	lua_pushinteger(l, GetManipulatedItem());

	return 1;
}

LUA lua_TriggerRegisterPlayerAllianceChange(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterPlayerAllianceChange((jTrigger)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HALLIANCETYPE)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_TriggerRegisterPlayerChatEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterPlayerChatEvent((jTrigger)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3)), lua_toboolean(l, 4)));

	return 1;
}

LUA lua_GetEventPlayerChatString(lua_State* l)
{
	lua_pushstring(l, GetEventPlayerChatString());

	return 1;
}

LUA lua_GetEventPlayerChatStringMatched(lua_State* l)
{
	lua_pushstring(l, from_jString(GetEventPlayerChatStringMatched()));

	return 1;
}

LUA lua_TriggerRegisterUnitStateEvent(lua_State* l)
{
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, TriggerRegisterUnitStateEvent((jTrigger)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), (HUNITSTATE)lua_tointeger(l, 3), (HLIMITOP)lua_tointeger(l, 4), &a5));

	return 1;
}

LUA lua_GetEventUnitState(lua_State* l)
{
	lua_pushinteger(l, GetEventUnitState());

	return 1;
}

LUA lua_TriggerRegisterDeathEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterDeathEvent((jTrigger)lua_tointeger(l, 1), (HWIDGET)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_TriggerRegisterUnitEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterUnitEvent((jTrigger)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), (HUNITEVENT)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_GetEventDamage(lua_State* l)
{
	lua_pushinteger(l, GetEventDamage());

	return 1;
}

LUA lua_GetEventDamageSource(lua_State* l)
{
	lua_pushinteger(l, GetEventDamageSource());

	return 1;
}

LUA lua_GetEventDetectingPlayer(lua_State* l)
{
	lua_pushinteger(l, GetEventDetectingPlayer());

	return 1;
}

LUA lua_GetEventTargetUnit(lua_State* l)
{
	lua_pushinteger(l, GetEventTargetUnit());

	return 1;
}

LUA lua_TriggerRegisterFilterUnitEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterFilterUnitEvent((jTrigger)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), (HUNITEVENT)lua_tointeger(l, 3), (HBOOLEXPR)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_TriggerRegisterUnitInRange(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushinteger(l, TriggerRegisterUnitInRange((jTrigger)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), &a3, (HBOOLEXPR)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_TriggerRegisterEnterRegion(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterEnterRegion((jTrigger)lua_tointeger(l, 1), (HREGION)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_TriggerRegisterLeaveRegion(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterLeaveRegion((jTrigger)lua_tointeger(l, 1), (HREGION)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_GetTriggeringRegion(lua_State* l)
{
	lua_pushinteger(l, GetTriggeringRegion());

	return 1;
}

LUA lua_GetEnteringUnit(lua_State* l)
{
	lua_pushinteger(l, GetEnteringUnit());

	return 1;
}

LUA lua_GetLeavingUnit(lua_State* l)
{
	lua_pushinteger(l, GetLeavingUnit());

	return 1;
}

LUA lua_TriggerAddCondition(lua_State* l)
{
	lua_pushinteger(l, TriggerAddCondition((jTrigger)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_TriggerRemoveCondition(lua_State* l)
{
	TriggerRemoveCondition((jTrigger)lua_tointeger(l, 1), (HTRIGGERCONDITION)lua_tointeger(l, 2));

	return 0;
}

LUA lua_TriggerClearConditions(lua_State* l)
{
	TriggerClearConditions((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_TriggerAddAction(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 2);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	lua_pushinteger(l, TriggerAddAction((jTrigger)lua_tointeger(l, 1), (jCode)trigger));

	return 1;
}

LUA lua_TriggerRemoveAction(lua_State* l)
{
	TriggerRemoveAction((jTrigger)lua_tointeger(l, 1), (HTRIGGERACTION)lua_tointeger(l, 2));

	return 0;
}

LUA lua_TriggerClearActions(lua_State* l)
{
	TriggerClearActions((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_TriggerSleepAction(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	TriggerSleepAction(&a1);

	return 0;
}

LUA lua_TriggerWaitForSound(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	TriggerWaitForSound((HSOUND)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_TriggerExecute(lua_State* l)
{
	TriggerExecute((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_TriggerExecuteWait(lua_State* l)
{
	TriggerExecuteWait((jTrigger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_TriggerEvaluate(lua_State* l)
{
	lua_pushboolean(l, TriggerEvaluate((jTrigger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_TriggerSyncStart(lua_State* l)
{
	TriggerSyncStart();

	return 0;
}

LUA lua_TriggerSyncReady(lua_State* l)
{
	TriggerSyncReady();

	return 0;
}

LUA lua_GetTriggerWidget(lua_State* l)
{
	lua_pushinteger(l, GetTriggerWidget());

	return 1;
}

LUA lua_GetTriggerDestructable(lua_State* l)
{
	lua_pushinteger(l, GetTriggerDestructable());

	return 1;
}

LUA lua_GetTriggerUnit(lua_State* l)
{
	lua_pushinteger(l, GetTriggerUnit());

	return 1;
}

LUA lua_GetTriggerPlayer(lua_State* l)
{
	lua_pushinteger(l, GetTriggerPlayer());

	return 1;
}

LUA lua_GetTriggeringTrigger(lua_State* l)
{
	lua_pushinteger(l, GetTriggeringTrigger());

	return 1;
}

LUA lua_GetTriggerEventId(lua_State* l)
{
	lua_pushinteger(l, GetTriggerEventId());

	return 1;
}

LUA lua_GetTriggerEvalCount(lua_State* l)
{
	lua_pushinteger(l, GetTriggerEvalCount((jTrigger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetTriggerExecCount(lua_State* l)
{
	lua_pushinteger(l, GetTriggerExecCount((jTrigger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetFilterUnit(lua_State* l)
{
	lua_pushinteger(l, GetFilterUnit());

	return 1;
}

LUA lua_GetEnumUnit(lua_State* l)
{
	lua_pushinteger(l, GetEnumUnit());

	return 1;
}

LUA lua_GetEnumPlayer(lua_State* l)
{
	lua_pushinteger(l, GetEnumPlayer());

	return 1;
}

LUA lua_GetFilterPlayer(lua_State* l)
{
	lua_pushinteger(l, GetFilterPlayer());

	return 1;
}

LUA lua_GetFilterDestructable(lua_State* l)
{
	lua_pushinteger(l, GetFilterDestructable());

	return 1;
}

LUA lua_GetEnumDestructable(lua_State* l)
{
	lua_pushinteger(l, GetEnumDestructable());

	return 1;
}

LUA lua_GetFilterItem(lua_State* l)
{
	lua_pushinteger(l, GetFilterItem());

	return 1;
}

LUA lua_GetEnumItem(lua_State* l)
{
	lua_pushinteger(l, GetEnumItem());

	return 1;
}

LUA lua_CreateGroup(lua_State* l)
{
	lua_pushinteger(l, CreateGroup());

	return 1;
}

LUA lua_DestroyGroup(lua_State* l)
{
	DestroyGroup((HGROUP)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GroupAddUnit(lua_State* l)
{
	GroupAddUnit((HGROUP)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GroupRemoveUnit(lua_State* l)
{
	GroupRemoveUnit((HGROUP)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GroupClear(lua_State* l)
{
	GroupClear((HGROUP)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GroupEnumUnitsOfType(lua_State* l)
{
	GroupEnumUnitsOfType((HGROUP)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HBOOLEXPR)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GroupEnumUnitsOfTypeCounted(lua_State* l)
{
	GroupEnumUnitsOfTypeCounted((HGROUP)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HBOOLEXPR)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_GroupEnumUnitsInRect(lua_State* l)
{
	GroupEnumUnitsInRect((HGROUP)lua_tointeger(l, 1), (HRECT)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GroupEnumUnitsInRectCounted(lua_State* l)
{
	GroupEnumUnitsInRectCounted((HGROUP)lua_tointeger(l, 1), (HRECT)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_GroupEnumUnitsOfPlayer(lua_State* l)
{
	GroupEnumUnitsOfPlayer((HGROUP)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GroupEnumUnitsInRange(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	GroupEnumUnitsInRange((HGROUP)lua_tointeger(l, 1), &a2, &a3, &a4, (HBOOLEXPR)lua_tointeger(l, 5));

	return 0;
}

LUA lua_GroupEnumUnitsInRangeOfLoc(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	GroupEnumUnitsInRangeOfLoc((HGROUP)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2), &a3, (HBOOLEXPR)lua_tointeger(l, 4));

	return 0;
}

LUA lua_GroupEnumUnitsInRangeCounted(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	GroupEnumUnitsInRangeCounted((HGROUP)lua_tointeger(l, 1), &a2, &a3, &a4, (HBOOLEXPR)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6));

	return 0;
}

LUA lua_GroupEnumUnitsInRangeOfLocCounted(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	GroupEnumUnitsInRangeOfLocCounted((HGROUP)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2), &a3, (HBOOLEXPR)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_GroupEnumUnitsSelected(lua_State* l)
{
	GroupEnumUnitsSelected((HGROUP)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GroupImmediateOrder(lua_State* l)
{
	lua_pushboolean(l, GroupImmediateOrder((HGROUP)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2))));

	return 1;
}

LUA lua_GroupImmediateOrderById(lua_State* l)
{
	lua_pushboolean(l, GroupImmediateOrderById((HGROUP)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GroupPointOrder(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, GroupPointOrder((HGROUP)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), &a3, &a4));

	return 1;
}

LUA lua_GroupPointOrderLoc(lua_State* l)
{
	lua_pushboolean(l, GroupPointOrderLoc((HGROUP)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HLOCATION)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_GroupPointOrderById(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, GroupPointOrderById((HGROUP)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3, &a4));

	return 1;
}

LUA lua_GroupPointOrderByIdLoc(lua_State* l)
{
	lua_pushboolean(l, GroupPointOrderByIdLoc((HGROUP)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (HLOCATION)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_GroupTargetOrder(lua_State* l)
{
	lua_pushboolean(l, GroupTargetOrder((HGROUP)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HWIDGET)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_GroupTargetOrderById(lua_State* l)
{
	lua_pushboolean(l, GroupTargetOrderById((HGROUP)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (HWIDGET)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_ForGroup(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 2);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	ForGroup((HGROUP)lua_tointeger(l, 1), (jCode)trigger);

	return 0;
}

LUA lua_FirstOfGroup(lua_State* l)
{
	lua_pushinteger(l, FirstOfGroup((HGROUP)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CreateForce(lua_State* l)
{
	lua_pushinteger(l, CreateForce());

	return 1;
}

LUA lua_DestroyForce(lua_State* l)
{
	DestroyForce((HFORCE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ForceAddPlayer(lua_State* l)
{
	ForceAddPlayer((HFORCE)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2));

	return 0;
}

LUA lua_ForceRemovePlayer(lua_State* l)
{
	ForceRemovePlayer((HFORCE)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2));

	return 0;
}

LUA lua_ForceClear(lua_State* l)
{
	ForceClear((HFORCE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ForceEnumPlayers(lua_State* l)
{
	ForceEnumPlayers((HFORCE)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2));

	return 0;
}

LUA lua_ForceEnumPlayersCounted(lua_State* l)
{
	ForceEnumPlayersCounted((HFORCE)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_ForceEnumAllies(lua_State* l)
{
	ForceEnumAllies((HFORCE)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3));

	return 0;
}

LUA lua_ForceEnumEnemies(lua_State* l)
{
	ForceEnumEnemies((HFORCE)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HBOOLEXPR)lua_tointeger(l, 3));

	return 0;
}

LUA lua_ForForce(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 2);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	ForForce((HFORCE)lua_tointeger(l, 1), (jCode)trigger);

	return 0;
}

LUA lua_GetWidgetLife(lua_State* l)
{
	lua_pushinteger(l, GetWidgetLife((HWIDGET)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetWidgetLife(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetWidgetLife((HWIDGET)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_GetWidgetX(lua_State* l)
{
	lua_pushinteger(l, GetWidgetX((HWIDGET)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetWidgetY(lua_State* l)
{
	lua_pushinteger(l, GetWidgetY((HWIDGET)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CreateDestructable(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, CreateDestructable((jInteger)lua_tointeger(l, 1), &a2, &a3, &a4, &a5, (jInteger)lua_tointeger(l, 6)));

	return 1;
}

LUA lua_CreateDestructableZ(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));

	lua_pushinteger(l, CreateDestructableZ((jInteger)lua_tointeger(l, 1), &a2, &a3, &a4, &a5, &a6, (jInteger)lua_tointeger(l, 7)));

	return 1;
}

LUA lua_CreateDeadDestructable(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, CreateDeadDestructable((jInteger)lua_tointeger(l, 1), &a2, &a3, &a4, &a5, (jInteger)lua_tointeger(l, 6)));

	return 1;
}

LUA lua_CreateDeadDestructableZ(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));

	lua_pushinteger(l, CreateDeadDestructableZ((jInteger)lua_tointeger(l, 1), &a2, &a3, &a4, &a5, &a6, (jInteger)lua_tointeger(l, 7)));

	return 1;
}

LUA lua_RemoveDestructable(lua_State* l)
{
	RemoveDestructable((HDESTRUCTABLE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_KillDestructable(lua_State* l)
{
	KillDestructable((HDESTRUCTABLE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetDestructableInvulnerable(lua_State* l)
{
	SetDestructableInvulnerable((HDESTRUCTABLE)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsDestructableInvulnerable(lua_State* l)
{
	lua_pushboolean(l, IsDestructableInvulnerable((HDESTRUCTABLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_EnumDestructablesInRect(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 3);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	EnumDestructablesInRect((HRECT)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2), (jCode)trigger);

	return 0;
}

LUA lua_GetDestructableTypeId(lua_State* l)
{
	lua_pushinteger(l, GetDestructableTypeId((HDESTRUCTABLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetDestructableX(lua_State* l)
{
	lua_pushinteger(l, GetDestructableX((HDESTRUCTABLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetDestructableY(lua_State* l)
{
	lua_pushinteger(l, GetDestructableY((HDESTRUCTABLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetDestructableLife(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetDestructableLife((HDESTRUCTABLE)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_GetDestructableLife(lua_State* l)
{
	lua_pushinteger(l, GetDestructableLife((HDESTRUCTABLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetDestructableMaxLife(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetDestructableMaxLife((HDESTRUCTABLE)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_GetDestructableMaxLife(lua_State* l)
{
	lua_pushinteger(l, GetDestructableMaxLife((HDESTRUCTABLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_DestructableRestoreLife(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	DestructableRestoreLife((HDESTRUCTABLE)lua_tointeger(l, 1), &a2, lua_toboolean(l, 3));

	return 0;
}

LUA lua_QueueDestructableAnimation(lua_State* l)
{
	QueueDestructableAnimation((HDESTRUCTABLE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_SetDestructableAnimation(lua_State* l)
{
	SetDestructableAnimation((HDESTRUCTABLE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_SetDestructableAnimationSpeed(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetDestructableAnimationSpeed((HDESTRUCTABLE)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_ShowDestructable(lua_State* l)
{
	ShowDestructable((HDESTRUCTABLE)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_GetDestructableOccluderHeight(lua_State* l)
{
	lua_pushinteger(l, GetDestructableOccluderHeight((HDESTRUCTABLE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetDestructableOccluderHeight(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetDestructableOccluderHeight((HDESTRUCTABLE)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_GetDestructableName(lua_State* l)
{
	lua_pushstring(l, from_jString(GetDestructableName((HDESTRUCTABLE)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_CreateUnit(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, CreateUnit((HPLAYER)lua_tointeger(l, 1), to_ID(lua_tostring(l, 2)), &a3, &a4, &a5));

	return 1;
}

LUA lua_CreateUnitByName(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, CreateUnitByName((HPLAYER)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), &a3, &a4, &a5));

	return 1;
}

LUA lua_CreateUnitAtLoc(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, CreateUnitAtLoc((HPLAYER)lua_tointeger(l, 1), to_ID(lua_tostring(l, 2)), (HLOCATION)lua_tointeger(l, 3), &a4));

	return 1;
}

LUA lua_CreateUnitAtLocByName(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, CreateUnitAtLocByName((HPLAYER)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HLOCATION)lua_tointeger(l, 3), &a4));

	return 1;
}

LUA lua_CreateCorpse(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, CreateCorpse((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3, &a4, &a5));

	return 1;
}

LUA lua_GetUnitState(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetUnitState((HUNIT)lua_tointeger(l, 1), (HUNITSTATE)lua_tointeger(l, 2))));

	return 1;
}

LUA lua_GetUnitFoodUsed(lua_State* l)
{
	lua_pushinteger(l, GetUnitFoodUsed((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitFoodMade(lua_State* l)
{
	lua_pushinteger(l, GetUnitFoodMade((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetFoodMade(lua_State* l)
{
	lua_pushinteger(l, GetFoodMade((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetFoodUsed(lua_State* l)
{
	lua_pushinteger(l, GetFoodUsed((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetUnitUseFood(lua_State* l)
{
	SetUnitUseFood((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_GetUnitX(lua_State* l)
{
	lua_pushinteger(l, GetUnitX((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitY(lua_State* l)
{
	lua_pushinteger(l, GetUnitY((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitLoc(lua_State* l)
{
	lua_pushinteger(l, GetUnitLoc((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitRallyPoint(lua_State* l)
{
	lua_pushinteger(l, GetUnitRallyPoint((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitRallyUnit(lua_State* l)
{
	lua_pushinteger(l, GetUnitRallyUnit((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitRallyDestructable(lua_State* l)
{
	lua_pushinteger(l, GetUnitRallyDestructable((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitFacing(lua_State* l)
{
	lua_pushinteger(l, GetUnitFacing((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitMoveSpeed(lua_State* l)
{
	lua_pushinteger(l, GetUnitMoveSpeed((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitDefaultMoveSpeed(lua_State* l)
{
	lua_pushinteger(l, GetUnitDefaultMoveSpeed((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitTypeId(lua_State* l)
{
	lua_pushinteger(l, GetUnitTypeId((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitRace(lua_State* l)
{
	lua_pushinteger(l, GetUnitRace((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitName(lua_State* l)
{
	lua_pushstring(l, from_jString(GetUnitName((HUNIT)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetUnitPointValue(lua_State* l)
{
	lua_pushinteger(l, GetUnitPointValue((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitPointValueByType(lua_State* l)
{
	lua_pushinteger(l, GetUnitPointValueByType((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetUnitX(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitX((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitY(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitY((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitPosition(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetUnitPosition((HUNIT)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetUnitPositionLoc(lua_State* l)
{
	SetUnitPositionLoc((HUNIT)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetUnitFacing(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitFacing((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitFacingTimed(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetUnitFacingTimed((HUNIT)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetUnitFlyHeight(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetUnitFlyHeight((HUNIT)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetUnitMoveSpeed(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitMoveSpeed((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitTurnSpeed(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitTurnSpeed((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitPropWindow(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitPropWindow((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitCreepGuard(lua_State* l)
{
	SetUnitCreepGuard((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_GetUnitAcquireRange(lua_State* l)
{
	lua_pushinteger(l, GetUnitAcquireRange((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitTurnSpeed(lua_State* l)
{
	lua_pushinteger(l, GetUnitTurnSpeed((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitPropWindow(lua_State* l)
{
	lua_pushinteger(l, GetUnitPropWindow((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitFlyHeight(lua_State* l)
{
	lua_pushinteger(l, GetUnitFlyHeight((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitDefaultAcquireRange(lua_State* l)
{
	lua_pushinteger(l, GetUnitDefaultAcquireRange((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitDefaultTurnSpeed(lua_State* l)
{
	lua_pushinteger(l, GetUnitDefaultTurnSpeed((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitDefaultPropWindow(lua_State* l)
{
	lua_pushinteger(l, GetUnitDefaultPropWindow((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitDefaultFlyHeight(lua_State* l)
{
	lua_pushinteger(l, GetUnitDefaultFlyHeight((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetUnitAcquireRange(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitAcquireRange((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitState(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetUnitState((HUNIT)lua_tointeger(l, 1), (HUNITSTATE)lua_tointeger(l, 2), &a3);

	return 0;
}

LUA lua_SetUnitOwner(lua_State* l)
{
	SetUnitOwner((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetUnitRescuable(lua_State* l)
{
	SetUnitRescuable((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetUnitRescueRange(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitRescueRange((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitColor(lua_State* l)
{
	SetUnitColor((HUNIT)lua_tointeger(l, 1), (HPLAYERCOLOR)lua_tointeger(l, 2));

	return 0;
}

LUA lua_QueueUnitAnimation(lua_State* l)
{
	QueueUnitAnimation((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_SetUnitAnimation(lua_State* l)
{
	SetUnitAnimation((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_SetUnitAnimationWithRarity(lua_State* l)
{
	SetUnitAnimationWithRarity((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HRARITYCONTROL)lua_tointeger(l, 3));

	return 0;
}

LUA lua_SetUnitAnimationByIndex(lua_State* l)
{
	SetUnitAnimationByIndex((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_AddUnitAnimationProperties(lua_State* l)
{
	AddUnitAnimationProperties((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetUnitScale(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetUnitScale((HUNIT)lua_tointeger(l, 1), &a2, &a3, &a4);

	return 0;
}

LUA lua_SetUnitTimeScale(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitTimeScale((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitBlendTime(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetUnitBlendTime((HUNIT)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetUnitVertexColor(lua_State* l)
{
	SetUnitVertexColor((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_SetUnitLookAt(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));

	SetUnitLookAt((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HUNIT)lua_tointeger(l, 3), &a4, &a5, &a6);

	return 0;
}

LUA lua_SetUnitPathing(lua_State* l)
{
	SetUnitPathing((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_ResetUnitLookAt(lua_State* l)
{
	ResetUnitLookAt((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetHeroStr(lua_State* l)
{
	SetHeroStr((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetHeroAgi(lua_State* l)
{
	SetHeroAgi((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetHeroInt(lua_State* l)
{
	SetHeroInt((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_GetHeroStr(lua_State* l)
{
	lua_pushinteger(l, GetHeroStr((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_GetHeroAgi(lua_State* l)
{
	lua_pushinteger(l, GetHeroAgi((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_GetHeroInt(lua_State* l)
{
	lua_pushinteger(l, GetHeroInt((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_GetHeroSkillPoints(lua_State* l)
{
	lua_pushinteger(l, GetHeroSkillPoints((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitStripHeroLevel(lua_State* l)
{
	lua_pushboolean(l, UnitStripHeroLevel((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitModifySkillPoints(lua_State* l)
{
	lua_pushboolean(l, UnitModifySkillPoints((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetHeroXP(lua_State* l)
{
	lua_pushinteger(l, GetHeroXP((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetHeroXP(lua_State* l)
{
	SetHeroXP((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_AddHeroXP(lua_State* l)
{
	AddHeroXP((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetHeroLevel(lua_State* l)
{
	SetHeroLevel((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_GetHeroLevel(lua_State* l)
{
	lua_pushinteger(l, GetHeroLevel((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetUnitLevel(lua_State* l)
{
	lua_pushinteger(l, GetUnitLevel((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetHeroProperName(lua_State* l)
{
	lua_pushstring(l, from_jString(GetHeroProperName((HUNIT)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_SuspendHeroXP(lua_State* l)
{
	SuspendHeroXP((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsSuspendedXP(lua_State* l)
{
	lua_pushboolean(l, IsSuspendedXP((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SelectHeroSkill(lua_State* l)
{
	SelectHeroSkill((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetUnitAbilityLevel(lua_State* l)
{
	lua_pushinteger(l, GetUnitAbilityLevel((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_ReviveHero(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushboolean(l, ReviveHero((HUNIT)lua_tointeger(l, 1), &a2, &a3, lua_toboolean(l, 4)));

	return 1;
}

LUA lua_ReviveHeroLoc(lua_State* l)
{
	lua_pushboolean(l, ReviveHeroLoc((HUNIT)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2), lua_toboolean(l, 3)));

	return 1;
}

LUA lua_SetUnitExploded(lua_State* l)
{
	SetUnitExploded((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetUnitInvulnerable(lua_State* l)
{
	SetUnitInvulnerable((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_PauseUnit(lua_State* l)
{
	PauseUnit((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsUnitPaused(lua_State* l)
{
	lua_pushboolean(l, IsUnitPaused((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitAddItem(lua_State* l)
{
	lua_pushboolean(l, UnitAddItem((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitAddItemById(lua_State* l)
{
	lua_pushinteger(l, UnitAddItemById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitAddItemToSlotById(lua_State* l)
{
	lua_pushboolean(l, UnitAddItemToSlotById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_UnitRemoveItem(lua_State* l)
{
	UnitRemoveItem((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2));

	return 0;
}

LUA lua_UnitRemoveItemFromSlot(lua_State* l)
{
	lua_pushinteger(l, UnitRemoveItemFromSlot((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitHasItem(lua_State* l)
{
	lua_pushboolean(l, UnitHasItem((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitItemInSlot(lua_State* l)
{
	lua_pushinteger(l, UnitItemInSlot((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitInventorySize(lua_State* l)
{
	lua_pushinteger(l, UnitInventorySize((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitDropItemPoint(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, UnitDropItemPoint((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2), &a3, &a4));

	return 1;
}

LUA lua_UnitDropItemSlot(lua_State* l)
{
	lua_pushboolean(l, UnitDropItemSlot((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_UnitDropItemTarget(lua_State* l)
{
	lua_pushboolean(l, UnitDropItemTarget((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2), (HWIDGET)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_UnitUseItem(lua_State* l)
{
	lua_pushboolean(l, UnitUseItem((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitUseItemPoint(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, UnitUseItemPoint((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2), &a3, &a4));

	return 1;
}

LUA lua_UnitUseItemTarget(lua_State* l)
{
	lua_pushboolean(l, UnitUseItemTarget((HUNIT)lua_tointeger(l, 1), (HITEM)lua_tointeger(l, 2), (HWIDGET)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_GetUnitCurrentOrder(lua_State* l)
{
	lua_pushinteger(l, GetUnitCurrentOrder((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetResourceAmount(lua_State* l)
{
	SetResourceAmount((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_AddResourceAmount(lua_State* l)
{
	AddResourceAmount((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetResourceAmount(lua_State* l)
{
	lua_pushinteger(l, GetResourceAmount((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SelectUnit(lua_State* l)
{
	SelectUnit((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_ClearSelection(lua_State* l)
{
	ClearSelection();

	return 0;
}

LUA lua_UnitAddIndicator(lua_State* l)
{
	UnitAddIndicator((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_AddIndicator(lua_State* l)
{
	AddIndicator((HWIDGET)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_KillUnit(lua_State* l)
{
	KillUnit((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_RemoveUnit(lua_State* l)
{
	RemoveUnit((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ShowUnit(lua_State* l)
{
	ShowUnit((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsUnitInForce(lua_State* l)
{
	lua_pushboolean(l, IsUnitInForce((HUNIT)lua_tointeger(l, 1), (HFORCE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitInGroup(lua_State* l)
{
	lua_pushboolean(l, IsUnitInGroup((HUNIT)lua_tointeger(l, 1), (HGROUP)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitOwnedByPlayer(lua_State* l)
{
	lua_pushboolean(l, IsUnitOwnedByPlayer((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitAlly(lua_State* l)
{
	lua_pushboolean(l, IsUnitAlly((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitEnemy(lua_State* l)
{
	lua_pushboolean(l, IsUnitEnemy((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitVisible(lua_State* l)
{
	lua_pushboolean(l, IsUnitVisible((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitDetected(lua_State* l)
{
	lua_pushboolean(l, IsUnitDetected((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitInvisible(lua_State* l)
{
	lua_pushboolean(l, IsUnitInvisible((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitFogged(lua_State* l)
{
	lua_pushboolean(l, IsUnitFogged((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitMasked(lua_State* l)
{
	lua_pushboolean(l, IsUnitMasked((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitSelected(lua_State* l)
{
	lua_pushboolean(l, IsUnitSelected((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitRace(lua_State* l)
{
	lua_pushboolean(l, IsUnitRace((HUNIT)lua_tointeger(l, 1), (HRACE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitType(lua_State* l)
{
	lua_pushboolean(l, IsUnitType((HUNIT)lua_tointeger(l, 1), (HUNITTYPE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnit(lua_State* l)
{
	lua_pushboolean(l, IsUnit((HUNIT)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitInRange(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushboolean(l, IsUnitInRange((HUNIT)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), &a3));

	return 1;
}

LUA lua_IsUnitInRangeXY(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, IsUnitInRangeXY((HUNIT)lua_tointeger(l, 1), &a2, &a3, &a4));

	return 1;
}

LUA lua_IsUnitInRangeLoc(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushboolean(l, IsUnitInRangeLoc((HUNIT)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2), &a3));

	return 1;
}

LUA lua_IsUnitHidden(lua_State* l)
{
	lua_pushboolean(l, IsUnitHidden((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsUnitIllusion(lua_State* l)
{
	lua_pushboolean(l, IsUnitIllusion((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsUnitInTransport(lua_State* l)
{
	lua_pushboolean(l, IsUnitInTransport((HUNIT)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsUnitLoaded(lua_State* l)
{
	lua_pushboolean(l, IsUnitLoaded((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsHeroUnitId(lua_State* l)
{
	lua_pushboolean(l, IsHeroUnitId((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsUnitIdType(lua_State* l)
{
	lua_pushboolean(l, IsUnitIdType((jInteger)lua_tointeger(l, 1), (HUNITTYPE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetOwningPlayer(lua_State* l)
{
	lua_pushinteger(l, GetOwningPlayer((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitShareVision(lua_State* l)
{
	UnitShareVision((HUNIT)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_UnitSuspendDecay(lua_State* l)
{
	UnitSuspendDecay((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_UnitAddType(lua_State* l)
{
	lua_pushboolean(l, UnitAddType((HUNIT)lua_tointeger(l, 1), (HUNITTYPE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitRemoveType(lua_State* l)
{
	lua_pushboolean(l, UnitRemoveType((HUNIT)lua_tointeger(l, 1), (HUNITTYPE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitAddAbility(lua_State* l)
{
	lua_pushboolean(l, UnitAddAbility((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitRemoveAbility(lua_State* l)
{
	lua_pushboolean(l, UnitRemoveAbility((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_UnitMakeAbilityPermanent(lua_State* l)
{
	lua_pushboolean(l, UnitMakeAbilityPermanent((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_UnitHasBuffsEx(lua_State* l)
{
	lua_pushboolean(l, UnitHasBuffsEx((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), lua_toboolean(l, 5), lua_toboolean(l, 6), lua_toboolean(l, 7), lua_toboolean(l, 8)));

	return 1;
}

LUA lua_UnitCountBuffsEx(lua_State* l)
{
	lua_pushinteger(l, UnitCountBuffsEx((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), lua_toboolean(l, 5), lua_toboolean(l, 6), lua_toboolean(l, 7), lua_toboolean(l, 8)));

	return 1;
}

LUA lua_UnitRemoveBuffs(lua_State* l)
{
	UnitRemoveBuffs((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_UnitRemoveBuffsEx(lua_State* l)
{
	UnitRemoveBuffsEx((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), lua_toboolean(l, 5), lua_toboolean(l, 6), lua_toboolean(l, 7), lua_toboolean(l, 8));

	return 0;
}

LUA lua_UnitAddSleep(lua_State* l)
{
	UnitAddSleep((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_UnitCanSleep(lua_State* l)
{
	lua_pushboolean(l, UnitCanSleep((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitAddSleepPerm(lua_State* l)
{
	UnitAddSleepPerm((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_UnitCanSleepPerm(lua_State* l)
{
	lua_pushboolean(l, UnitCanSleepPerm((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitIsSleeping(lua_State* l)
{
	lua_pushboolean(l, UnitIsSleeping((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitWakeUp(lua_State* l)
{
	UnitWakeUp((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_UnitApplyTimedLife(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	UnitApplyTimedLife((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3);

	return 0;
}

LUA lua_UnitIgnoreAlarm(lua_State* l)
{
	lua_pushboolean(l, UnitIgnoreAlarm((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_UnitIgnoreAlarmToggled(lua_State* l)
{
	lua_pushboolean(l, UnitIgnoreAlarmToggled((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_UnitDamagePoint(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));

	lua_pushboolean(l, UnitDamagePoint((HUNIT)lua_tointeger(l, 1), &a2, &a3, &a4, &a5, &a6, lua_toboolean(l, 7), lua_toboolean(l, 8), (HATTACKTYPE)lua_tointeger(l, 9), (HDAMAGETYPE)lua_tointeger(l, 10), (HWEAPONTYPE)lua_tointeger(l, 11)));

	return 1;
}

LUA lua_UnitDamageTarget(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushboolean(l, UnitDamageTarget((HUNIT)lua_tointeger(l, 1), (HWIDGET)lua_tointeger(l, 2), &a3, lua_toboolean(l, 4), lua_toboolean(l, 5), (HATTACKTYPE)lua_tointeger(l, 6), (HDAMAGETYPE)lua_tointeger(l, 7), (HWEAPONTYPE)lua_tointeger(l, 8)));

	return 1;
}

LUA lua_DecUnitAbilityLevel(lua_State* l)
{
	lua_pushinteger(l, DecUnitAbilityLevel((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IncUnitAbilityLevel(lua_State* l)
{
	lua_pushinteger(l, IncUnitAbilityLevel((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_SetUnitAbilityLevel(lua_State* l)
{
	lua_pushinteger(l, SetUnitAbilityLevel((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_UnitResetCooldown(lua_State* l)
{
	UnitResetCooldown((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_UnitSetConstructionProgress(lua_State* l)
{
	UnitSetConstructionProgress((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_UnitSetUpgradeProgress(lua_State* l)
{
	UnitSetUpgradeProgress((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_UnitPauseTimedLife(lua_State* l)
{
	UnitPauseTimedLife((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_UnitSetUsesAltIcon(lua_State* l)
{
	UnitSetUsesAltIcon((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IssueImmediateOrderById(lua_State* l)
{
	lua_pushboolean(l, IssueImmediateOrderById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IssuePointOrderById(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, IssuePointOrderById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3, &a4));

	return 1;
}

LUA lua_IssuePointOrderByIdLoc(lua_State* l)
{
	lua_pushboolean(l, IssuePointOrderByIdLoc((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (HLOCATION)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IssueTargetOrderById(lua_State* l)
{
	lua_pushboolean(l, IssueTargetOrderById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (HWIDGET)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IssueInstantPointOrderById(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, IssueInstantPointOrderById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3, &a4, (HWIDGET)lua_tointeger(l, 5)));

	return 1;
}

LUA lua_IssueInstantTargetOrderById(lua_State* l)
{
	lua_pushboolean(l, IssueInstantTargetOrderById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (HWIDGET)lua_tointeger(l, 3), (HWIDGET)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_IssueBuildOrderById(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, IssueBuildOrderById((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3, &a4));

	return 1;
}

LUA lua_IssueNeutralImmediateOrderById(lua_State* l)
{
	lua_pushboolean(l, IssueNeutralImmediateOrderById((HPLAYER)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IssueNeutralPointOrderById(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushboolean(l, IssueNeutralPointOrderById((HPLAYER)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), &a4, &a5));

	return 1;
}

LUA lua_IssueNeutralTargetOrderById(lua_State* l)
{
	lua_pushboolean(l, IssueNeutralTargetOrderById((HPLAYER)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HWIDGET)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_IssueImmediateOrder(lua_State* l)
{
	lua_pushboolean(l, IssueImmediateOrder((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2))));

	return 1;
}

LUA lua_IssuePointOrder(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, IssuePointOrder((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), &a3, &a4));

	return 1;
}

LUA lua_IssuePointOrderLoc(lua_State* l)
{
	lua_pushboolean(l, IssuePointOrderLoc((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HLOCATION)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IssueTargetOrder(lua_State* l)
{
	lua_pushboolean(l, IssueTargetOrder((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HWIDGET)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IssueInstantPointOrder(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, IssueInstantPointOrder((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), &a3, &a4, (HWIDGET)lua_tointeger(l, 5)));

	return 1;
}

LUA lua_IssueInstantTargetOrder(lua_State* l)
{
	lua_pushboolean(l, IssueInstantTargetOrder((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (HWIDGET)lua_tointeger(l, 3), (HWIDGET)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_IssueBuildOrder(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushboolean(l, IssueBuildOrder((HUNIT)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), &a3, &a4));

	return 1;
}

LUA lua_IssueNeutralImmediateOrder(lua_State* l)
{
	lua_pushboolean(l, IssueNeutralImmediateOrder((HPLAYER)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_IssueNeutralPointOrder(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushboolean(l, IssueNeutralPointOrder((HPLAYER)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3)), &a4, &a5));

	return 1;
}

LUA lua_IssueNeutralTargetOrder(lua_State* l)
{
	lua_pushboolean(l, IssueNeutralTargetOrder((HPLAYER)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3)), (HWIDGET)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_WaygateGetDestinationX(lua_State* l)
{
	lua_pushinteger(l, WaygateGetDestinationX((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_WaygateGetDestinationY(lua_State* l)
{
	lua_pushinteger(l, WaygateGetDestinationY((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_WaygateSetDestination(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	WaygateSetDestination((HUNIT)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_WaygateActivate(lua_State* l)
{
	WaygateActivate((HUNIT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_WaygateIsActive(lua_State* l)
{
	lua_pushboolean(l, WaygateIsActive((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_AddItemToAllStock(lua_State* l)
{
	AddItemToAllStock((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_AddItemToStock(lua_State* l)
{
	AddItemToStock((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_AddUnitToAllStock(lua_State* l)
{
	AddUnitToAllStock((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_AddUnitToStock(lua_State* l)
{
	AddUnitToStock((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_RemoveItemFromAllStock(lua_State* l)
{
	RemoveItemFromAllStock((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_RemoveItemFromStock(lua_State* l)
{
	RemoveItemFromStock((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_RemoveUnitFromAllStock(lua_State* l)
{
	RemoveUnitFromAllStock((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_RemoveUnitFromStock(lua_State* l)
{
	RemoveUnitFromStock((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetAllItemTypeSlots(lua_State* l)
{
	SetAllItemTypeSlots((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetAllUnitTypeSlots(lua_State* l)
{
	SetAllUnitTypeSlots((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetItemTypeSlots(lua_State* l)
{
	SetItemTypeSlots((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetUnitTypeSlots(lua_State* l)
{
	SetUnitTypeSlots((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetUnitUserData(lua_State* l)
{
	lua_pushinteger(l, GetUnitUserData((HUNIT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetUnitUserData(lua_State* l)
{
	SetUnitUserData((HUNIT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_CreateItem(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushinteger(l, CreateItem((jInteger)lua_tointeger(l, 1), &a2, &a3));

	return 1;
}

LUA lua_RemoveItem(lua_State* l)
{
	RemoveItem((HITEM)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GetItemPlayer(lua_State* l)
{
	lua_pushinteger(l, GetItemPlayer((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetItemTypeId(lua_State* l)
{
	lua_pushinteger(l, GetItemTypeId((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetItemX(lua_State* l)
{
	lua_pushinteger(l, GetItemX((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetItemY(lua_State* l)
{
	lua_pushinteger(l, GetItemY((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetItemPosition(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetItemPosition((HITEM)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetItemDropOnDeath(lua_State* l)
{
	SetItemDropOnDeath((HITEM)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetItemDroppable(lua_State* l)
{
	SetItemDroppable((HITEM)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetItemPawnable(lua_State* l)
{
	SetItemPawnable((HITEM)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetItemPlayer(lua_State* l)
{
	SetItemPlayer((HITEM)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetItemInvulnerable(lua_State* l)
{
	SetItemInvulnerable((HITEM)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsItemInvulnerable(lua_State* l)
{
	lua_pushboolean(l, IsItemInvulnerable((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetItemLevel(lua_State* l)
{
	lua_pushinteger(l, GetItemLevel((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetItemType(lua_State* l)
{
	lua_pushinteger(l, GetItemType((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetItemVisible(lua_State* l)
{
	SetItemVisible((HITEM)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsItemVisible(lua_State* l)
{
	lua_pushboolean(l, IsItemVisible((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_EnumItemsInRect(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 3);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	EnumItemsInRect((HRECT)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2), (jCode)trigger);

	return 0;
}

LUA lua_IsItemOwned(lua_State* l)
{
	lua_pushboolean(l, IsItemOwned((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsItemPowerup(lua_State* l)
{
	lua_pushboolean(l, IsItemPowerup((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsItemSellable(lua_State* l)
{
	lua_pushboolean(l, IsItemSellable((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsItemPawnable(lua_State* l)
{
	lua_pushboolean(l, IsItemPawnable((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsItemIdPowerup(lua_State* l)
{
	lua_pushboolean(l, IsItemIdPowerup((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsItemIdSellable(lua_State* l)
{
	lua_pushboolean(l, IsItemIdSellable((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsItemIdPawnable(lua_State* l)
{
	lua_pushboolean(l, IsItemIdPawnable((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetItemDropID(lua_State* l)
{
	SetItemDropID((HITEM)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetItemName(lua_State* l)
{
	lua_pushstring(l, from_jString(GetItemName((HITEM)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetItemCharges(lua_State* l)
{
	lua_pushinteger(l, GetItemCharges((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetItemCharges(lua_State* l)
{
	SetItemCharges((HITEM)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetItemUserData(lua_State* l)
{
	lua_pushinteger(l, GetItemUserData((HITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetItemUserData(lua_State* l)
{
	SetItemUserData((HITEM)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_Player(lua_State* l)
{
	lua_pushinteger(l, Player((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetLocalPlayer(lua_State* l)
{
	lua_pushinteger(l, GetLocalPlayer());

	return 1;
}

LUA lua_IsPlayerAlly(lua_State* l)
{
	lua_pushboolean(l, IsPlayerAlly((HPLAYER)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsPlayerEnemy(lua_State* l)
{
	lua_pushboolean(l, IsPlayerEnemy((HPLAYER)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsPlayerInForce(lua_State* l)
{
	lua_pushboolean(l, IsPlayerInForce((HPLAYER)lua_tointeger(l, 1), (HFORCE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsPlayerObserver(lua_State* l)
{
	lua_pushboolean(l, IsPlayerObserver((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerRace(lua_State* l)
{
	lua_pushinteger(l, GetPlayerRace((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetPlayerId(lua_State* l)
{
	lua_pushinteger(l, GetPlayerId((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetPlayerTechMaxAllowed(lua_State* l)
{
	SetPlayerTechMaxAllowed((HPLAYER)lua_tointeger(l, 1), to_ID(lua_tostring(l, 2)), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GetPlayerTechMaxAllowed(lua_State* l)
{
	lua_pushinteger(l, GetPlayerTechMaxAllowed((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_AddPlayerTechResearched(lua_State* l)
{
	AddPlayerTechResearched((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_SetPlayerTechResearched(lua_State* l)
{
	SetPlayerTechResearched((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GetPlayerTechResearched(lua_State* l)
{
	lua_pushboolean(l, GetPlayerTechResearched((HPLAYER)lua_tointeger(l, 1), to_ID(lua_tostring(l, 2)), lua_toboolean(l, 3)));

	return 1;
}

LUA lua_GetPlayerTechCount(lua_State* l)
{
	lua_pushinteger(l, GetPlayerTechCount((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3)));

	return 1;
}

LUA lua_SetPlayerAbilityAvailable(lua_State* l)
{
	SetPlayerAbilityAvailable((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_GetPlayerUnitCount(lua_State* l)
{
	lua_pushinteger(l, GetPlayerUnitCount((HPLAYER)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_GetPlayerTypedUnitCount(lua_State* l)
{
	lua_pushinteger(l, GetPlayerTypedUnitCount((HPLAYER)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), lua_toboolean(l, 3), lua_toboolean(l, 4)));

	return 1;
}

LUA lua_GetPlayerStructureCount(lua_State* l)
{
	lua_pushinteger(l, GetPlayerStructureCount((HPLAYER)lua_tointeger(l, 1), lua_toboolean(l, 2)));

	return 1;
}

LUA lua_IsVisibleToPlayer(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushboolean(l, IsVisibleToPlayer(&a1, &a2, (HPLAYER)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IsLocationVisibleToPlayer(lua_State* l)
{
	lua_pushboolean(l, IsLocationVisibleToPlayer((HLOCATION)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsFoggedToPlayer(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushboolean(l, IsFoggedToPlayer(&a1, &a2, (HPLAYER)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IsLocationFoggedToPlayer(lua_State* l)
{
	lua_pushboolean(l, IsLocationFoggedToPlayer((HLOCATION)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_IsMaskedToPlayer(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushboolean(l, IsMaskedToPlayer(&a1, &a2, (HPLAYER)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_IsLocationMaskedToPlayer(lua_State* l)
{
	lua_pushboolean(l, IsLocationMaskedToPlayer((HLOCATION)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_SetPlayerState(lua_State* l)
{
	SetPlayerState((HPLAYER)lua_tointeger(l, 1), (HPLAYERSTATE)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_GetPlayerState(lua_State* l)
{
	lua_pushinteger(l, GetPlayerState((HPLAYER)lua_tointeger(l, 1), (HPLAYERSTATE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetPlayerScore(lua_State* l)
{
	lua_pushinteger(l, GetPlayerScore((HPLAYER)lua_tointeger(l, 1), (HPLAYERSCORE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetPlayerAlliance(lua_State* l)
{
	lua_pushboolean(l, GetPlayerAlliance((HPLAYER)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HALLIANCETYPE)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_RemovePlayer(lua_State* l)
{
	RemovePlayer((HPLAYER)lua_tointeger(l, 1), (HPLAYERGAMERESULT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_CachePlayerHeroData(lua_State* l)
{
	CachePlayerHeroData((HPLAYER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GetPlayerHandicap(lua_State* l)
{
	lua_pushinteger(l, GetPlayerHandicap((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetPlayerHandicap(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetPlayerHandicap((HPLAYER)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_GetPlayerHandicapXP(lua_State* l)
{
	lua_pushinteger(l, GetPlayerHandicapXP((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetPlayerHandicapXP(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetPlayerHandicapXP((HPLAYER)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetPlayerUnitsOwner(lua_State* l)
{
	SetPlayerUnitsOwner((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_CripplePlayer(lua_State* l)
{
	CripplePlayer((HPLAYER)lua_tointeger(l, 1), (HFORCE)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_VersionGet(lua_State* l)
{
	lua_pushinteger(l, VersionGet());

	return 1;
}

LUA lua_VersionCompatible(lua_State* l)
{
	lua_pushboolean(l, VersionCompatible((HVERSION)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_VersionSupported(lua_State* l)
{
	lua_pushboolean(l, VersionSupported((HVERSION)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_EndGame(lua_State* l)
{
	EndGame(lua_toboolean(l, 1));

	return 0;
}

LUA lua_ChangeLevel(lua_State* l)
{
	ChangeLevel(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2));

	return 0;
}

LUA lua_RestartGame(lua_State* l)
{
	RestartGame(lua_toboolean(l, 1));

	return 0;
}

LUA lua_ReloadGame(lua_State* l)
{
	ReloadGame();

	return 0;
}

LUA lua_LoadGame(lua_State* l)
{
	LoadGame(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SaveGame(lua_State* l)
{
	SaveGame(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_RenameSaveDirectory(lua_State* l)
{
	lua_pushboolean(l, RenameSaveDirectory(to_jString(lua_tostring(l, 1)), to_jString(lua_tostring(l, 2))));

	return 1;
}

LUA lua_RemoveSaveDirectory(lua_State* l)
{
	lua_pushboolean(l, RemoveSaveDirectory(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_CopySaveGame(lua_State* l)
{
	lua_pushboolean(l, CopySaveGame(to_jString(lua_tostring(l, 1)), to_jString(lua_tostring(l, 2))));

	return 1;
}

LUA lua_SaveGameExists(lua_State* l)
{
	lua_pushboolean(l, SaveGameExists(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_SetFloatGameState(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetFloatGameState((HFGAMESTATE)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_GetFloatGameState(lua_State* l)
{
	lua_pushinteger(l, GetFloatGameState((HFGAMESTATE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetIntegerGameState(lua_State* l)
{
	SetIntegerGameState((HIGAMESTATE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetIntegerGameState(lua_State* l)
{
	lua_pushinteger(l, GetIntegerGameState((HIGAMESTATE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SyncSelections(lua_State* l)
{
	SyncSelections();

	return 0;
}

LUA lua_DialogCreate(lua_State* l)
{
	lua_pushinteger(l, DialogCreate());

	return 1;
}

LUA lua_DialogDestroy(lua_State* l)
{
	DialogDestroy((HDIALOG)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DialogSetAsync(lua_State* l)
{
	DialogSetAsync((HDIALOG)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DialogClear(lua_State* l)
{
	DialogClear((HDIALOG)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DialogSetMessage(lua_State* l)
{
	DialogSetMessage((HDIALOG)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_DialogAddButton(lua_State* l)
{
	lua_pushinteger(l, DialogAddButton((HDIALOG)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_DialogAddQuitButton(lua_State* l)
{
	lua_pushinteger(l, DialogAddQuitButton((HDIALOG)lua_tointeger(l, 1), lua_toboolean(l, 2), to_jString(lua_tostring(l, 3)), (jInteger)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_DialogDisplay(lua_State* l)
{
	DialogDisplay((HPLAYER)lua_tointeger(l, 1), (HDIALOG)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetMissionAvailable(lua_State* l)
{
	SetMissionAvailable((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetCampaignAvailable(lua_State* l)
{
	SetCampaignAvailable((jInteger)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetCampaignMenuRace(lua_State* l)
{
	SetCampaignMenuRace((HRACE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetCampaignMenuRaceEx(lua_State* l)
{
	SetCampaignMenuRaceEx((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ForceCampaignSelectScreen(lua_State* l)
{
	ForceCampaignSelectScreen();

	return 0;
}

LUA lua_SetOpCinematicAvailable(lua_State* l)
{
	SetOpCinematicAvailable((jInteger)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetEdCinematicAvailable(lua_State* l)
{
	SetEdCinematicAvailable((jInteger)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetTutorialCleared(lua_State* l)
{
	SetTutorialCleared(lua_toboolean(l, 1));

	return 0;
}

LUA lua_GetDefaultDifficulty(lua_State* l)
{
	lua_pushinteger(l, GetDefaultDifficulty());

	return 1;
}

LUA lua_SetDefaultDifficulty(lua_State* l)
{
	SetDefaultDifficulty((HGAMEDIFFICULTY)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ReloadGameCachesFromDisk(lua_State* l)
{
	lua_pushboolean(l, ReloadGameCachesFromDisk());

	return 1;
}

LUA lua_SetCustomCampaignButtonVisible(lua_State* l)
{
	SetCustomCampaignButtonVisible((jInteger)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_GetCustomCampaignButtonVisible(lua_State* l)
{
	lua_pushboolean(l, GetCustomCampaignButtonVisible((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_DoNotSaveReplay(lua_State* l)
{
	DoNotSaveReplay();

	return 0;
}

LUA lua_InitGameCache(lua_State* l)
{
	lua_pushinteger(l, InitGameCache(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_SaveGameCache(lua_State* l)
{
	lua_pushboolean(l, SaveGameCache((HGAMECACHE)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_StoreInteger(lua_State* l)
{
	StoreInteger((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_StoreReal(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	StoreReal((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)), &a4);

	return 0;
}

LUA lua_StoreBoolean(lua_State* l)
{
	StoreBoolean((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)), lua_toboolean(l, 4));

	return 0;
}

LUA lua_StoreUnit(lua_State* l)
{
	lua_pushboolean(l, StoreUnit((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)), (HUNIT)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_StoreString(lua_State* l)
{
	lua_pushboolean(l, StoreString((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)), to_jString(lua_tostring(l, 4))));

	return 1;
}

LUA lua_SaveInteger(lua_State* l)
{
	SaveInteger((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_SaveReal(lua_State* l)
{
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SaveReal((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), &a4);

	return 0;
}

LUA lua_SaveBoolean(lua_State* l)
{
	SaveBoolean((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), lua_toboolean(l, 4));

	return 0;
}

LUA lua_SaveStr(lua_State* l)
{
	lua_pushboolean(l, SaveStr((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), to_jString(lua_tostring(l, 4))));

	return 1;
}

LUA lua_SavePlayerHandle(lua_State* l)
{
	lua_pushboolean(l, SavePlayerHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HPLAYER)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveWidgetHandle(lua_State* l)
{
	lua_pushboolean(l, SaveWidgetHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HWIDGET)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveDestructableHandle(lua_State* l)
{
	lua_pushboolean(l, SaveDestructableHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HDESTRUCTABLE)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveItemHandle(lua_State* l)
{
	lua_pushboolean(l, SaveItemHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HITEM)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveUnitHandle(lua_State* l)
{
	lua_pushboolean(l, SaveUnitHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HUNIT)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveAbilityHandle(lua_State* l)
{
	lua_pushboolean(l, SaveAbilityHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HABILITY)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTimerHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTimerHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HTIMER)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveRegionHandle(lua_State* l)
{
	lua_pushboolean(l, SaveRegionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HREGION)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTriggerHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTriggerHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jTrigger)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTriggerConditionHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTriggerConditionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HTRIGGERCONDITION)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTriggerActionHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTriggerActionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HTRIGGERACTION)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTriggerEventHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTriggerEventHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HEVENT)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveForceHandle(lua_State* l)
{
	lua_pushboolean(l, SaveForceHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HFORCE)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveGroupHandle(lua_State* l)
{
	lua_pushboolean(l, SaveGroupHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HGROUP)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveLocationHandle(lua_State* l)
{
	lua_pushboolean(l, SaveLocationHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HLOCATION)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveRectHandle(lua_State* l)
{
	lua_pushboolean(l, SaveRectHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HRECT)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveBooleanExprHandle(lua_State* l)
{
	lua_pushboolean(l, SaveBooleanExprHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HBOOLEXPR)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveSoundHandle(lua_State* l)
{
	lua_pushboolean(l, SaveSoundHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HSOUND)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveEffectHandle(lua_State* l)
{
	lua_pushboolean(l, SaveEffectHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HEFFECT)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveUnitPoolHandle(lua_State* l)
{
	lua_pushboolean(l, SaveUnitPoolHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HUNITPOOL)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveItemPoolHandle(lua_State* l)
{
	lua_pushboolean(l, SaveItemPoolHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HITEMPOOL)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveQuestHandle(lua_State* l)
{
	lua_pushboolean(l, SaveQuestHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HQUEST)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveQuestItemHandle(lua_State* l)
{
	lua_pushboolean(l, SaveQuestItemHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HQUESTITEM)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveDefeatConditionHandle(lua_State* l)
{
	lua_pushboolean(l, SaveDefeatConditionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HDEFEATCONDITION)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTimerDialogHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTimerDialogHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HTIMERDIALOG)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveLeaderboardHandle(lua_State* l)
{
	lua_pushboolean(l, SaveLeaderboardHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HLEADERBOARD)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveMultiboardHandle(lua_State* l)
{
	lua_pushboolean(l, SaveMultiboardHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HMULTIBOARD)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveMultiboardItemHandle(lua_State* l)
{
	lua_pushboolean(l, SaveMultiboardItemHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HMULTIBOARDITEM)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTrackableHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTrackableHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HTRACKABLE)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveDialogHandle(lua_State* l)
{
	lua_pushboolean(l, SaveDialogHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HDIALOG)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveButtonHandle(lua_State* l)
{
	lua_pushboolean(l, SaveButtonHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HBUTTON)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveTextTagHandle(lua_State* l)
{
	lua_pushboolean(l, SaveTextTagHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HTEXTTAG)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveLightningHandle(lua_State* l)
{
	lua_pushboolean(l, SaveLightningHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HLIGHTNING)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveImageHandle(lua_State* l)
{
	lua_pushboolean(l, SaveImageHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HIMAGE)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveUbersplatHandle(lua_State* l)
{
	lua_pushboolean(l, SaveUbersplatHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HUBERSPLAT)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveFogStateHandle(lua_State* l)
{
	lua_pushboolean(l, SaveFogStateHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HFOGSTATE)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveFogModifierHandle(lua_State* l)
{
	lua_pushboolean(l, SaveFogModifierHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HFOGMODIFIER)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveAgentHandle(lua_State* l)
{
	lua_pushboolean(l, SaveAgentHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HAGENT)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SaveHashtableHandle(lua_State* l)
{
	lua_pushboolean(l, SaveHashtableHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (HHASHTABLE)lua_tointeger(l, 4)));

	return 1;
}

LUA lua_SyncStoredInteger(lua_State* l)
{
	SyncStoredInteger((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_SyncStoredReal(lua_State* l)
{
	SyncStoredReal((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_SyncStoredBoolean(lua_State* l)
{
	SyncStoredBoolean((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_SyncStoredUnit(lua_State* l)
{
	SyncStoredUnit((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_SyncStoredString(lua_State* l)
{
	SyncStoredString((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_GetStoredInteger(lua_State* l)
{
	lua_pushinteger(l, GetStoredInteger((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_GetStoredReal(lua_State* l)
{
	lua_pushinteger(l, GetStoredReal((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_GetStoredBoolean(lua_State* l)
{
	lua_pushboolean(l, GetStoredBoolean((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_RestoreUnit(lua_State* l)
{
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));
	jReal a7 = to_jReal((float)lua_tonumber(l, 7));

	lua_pushinteger(l, RestoreUnit((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)), (HPLAYER)lua_tointeger(l, 4), &a5, &a6, &a7));

	return 1;
}

LUA lua_GetStoredString(lua_State* l)
{
	lua_pushstring(l, from_jString(GetStoredString((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)))));

	return 1;
}

LUA lua_HaveStoredInteger(lua_State* l)
{
	lua_pushboolean(l, HaveStoredInteger((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_HaveStoredReal(lua_State* l)
{
	lua_pushboolean(l, HaveStoredReal((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_HaveStoredBoolean(lua_State* l)
{
	lua_pushboolean(l, HaveStoredBoolean((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_HaveStoredUnit(lua_State* l)
{
	lua_pushboolean(l, HaveStoredUnit((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_HaveStoredString(lua_State* l)
{
	lua_pushboolean(l, HaveStoredString((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_FlushGameCache(lua_State* l)
{
	FlushGameCache((HGAMECACHE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_FlushStoredMission(lua_State* l)
{
	FlushStoredMission((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_FlushStoredInteger(lua_State* l)
{
	FlushStoredInteger((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_FlushStoredReal(lua_State* l)
{
	FlushStoredReal((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_FlushStoredBoolean(lua_State* l)
{
	FlushStoredBoolean((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_FlushStoredUnit(lua_State* l)
{
	FlushStoredUnit((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_FlushStoredString(lua_State* l)
{
	FlushStoredString((HGAMECACHE)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_InitHashtable(lua_State* l)
{
	lua_pushinteger(l, InitHashtable());

	return 1;
}

LUA lua_LoadInteger(lua_State* l)
{
	lua_pushinteger(l, LoadInteger((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadReal(lua_State* l)
{
	lua_pushinteger(l, LoadReal((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadBoolean(lua_State* l)
{
	lua_pushboolean(l, LoadBoolean((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadStr(lua_State* l)
{
	lua_pushstring(l, from_jString(LoadStr((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3))));

	return 1;
}

LUA lua_LoadPlayerHandle(lua_State* l)
{
	lua_pushinteger(l, LoadPlayerHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadWidgetHandle(lua_State* l)
{
	lua_pushinteger(l, LoadWidgetHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadDestructableHandle(lua_State* l)
{
	lua_pushinteger(l, LoadDestructableHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadItemHandle(lua_State* l)
{
	lua_pushinteger(l, LoadItemHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadUnitHandle(lua_State* l)
{
	lua_pushinteger(l, LoadUnitHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadAbilityHandle(lua_State* l)
{
	lua_pushinteger(l, LoadAbilityHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTimerHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTimerHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadRegionHandle(lua_State* l)
{
	lua_pushinteger(l, LoadRegionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTriggerHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTriggerHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTriggerConditionHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTriggerConditionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTriggerActionHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTriggerActionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTriggerEventHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTriggerEventHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadForceHandle(lua_State* l)
{
	lua_pushinteger(l, LoadForceHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadGroupHandle(lua_State* l)
{
	lua_pushinteger(l, LoadGroupHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadLocationHandle(lua_State* l)
{
	lua_pushinteger(l, LoadLocationHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadRectHandle(lua_State* l)
{
	lua_pushinteger(l, LoadRectHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadBooleanExprHandle(lua_State* l)
{
	lua_pushinteger(l, LoadBooleanExprHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadSoundHandle(lua_State* l)
{
	lua_pushinteger(l, LoadSoundHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadEffectHandle(lua_State* l)
{
	lua_pushinteger(l, LoadEffectHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadUnitPoolHandle(lua_State* l)
{
	lua_pushinteger(l, LoadUnitPoolHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadItemPoolHandle(lua_State* l)
{
	lua_pushinteger(l, LoadItemPoolHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadQuestHandle(lua_State* l)
{
	lua_pushinteger(l, LoadQuestHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadQuestItemHandle(lua_State* l)
{
	lua_pushinteger(l, LoadQuestItemHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadDefeatConditionHandle(lua_State* l)
{
	lua_pushinteger(l, LoadDefeatConditionHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTimerDialogHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTimerDialogHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadLeaderboardHandle(lua_State* l)
{
	lua_pushinteger(l, LoadLeaderboardHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadMultiboardHandle(lua_State* l)
{
	lua_pushinteger(l, LoadMultiboardHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadMultiboardItemHandle(lua_State* l)
{
	lua_pushinteger(l, LoadMultiboardItemHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTrackableHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTrackableHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadDialogHandle(lua_State* l)
{
	lua_pushinteger(l, LoadDialogHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadButtonHandle(lua_State* l)
{
	lua_pushinteger(l, LoadButtonHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadTextTagHandle(lua_State* l)
{
	lua_pushinteger(l, LoadTextTagHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadLightningHandle(lua_State* l)
{
	lua_pushinteger(l, LoadLightningHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadImageHandle(lua_State* l)
{
	lua_pushinteger(l, LoadImageHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadUbersplatHandle(lua_State* l)
{
	lua_pushinteger(l, LoadUbersplatHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadFogStateHandle(lua_State* l)
{
	lua_pushinteger(l, LoadFogStateHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadFogModifierHandle(lua_State* l)
{
	lua_pushinteger(l, LoadFogModifierHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_LoadHashtableHandle(lua_State* l)
{
	lua_pushinteger(l, LoadHashtableHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_HaveSavedInteger(lua_State* l)
{
	lua_pushboolean(l, HaveSavedInteger((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_HaveSavedReal(lua_State* l)
{
	lua_pushboolean(l, HaveSavedReal((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_HaveSavedBoolean(lua_State* l)
{
	lua_pushboolean(l, HaveSavedBoolean((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_HaveSavedString(lua_State* l)
{
	lua_pushboolean(l, HaveSavedString((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_HaveSavedHandle(lua_State* l)
{
	lua_pushboolean(l, HaveSavedHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_RemoveSavedInteger(lua_State* l)
{
	RemoveSavedInteger((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_RemoveSavedReal(lua_State* l)
{
	RemoveSavedReal((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_RemoveSavedBoolean(lua_State* l)
{
	RemoveSavedBoolean((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_RemoveSavedString(lua_State* l)
{
	RemoveSavedString((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_RemoveSavedHandle(lua_State* l)
{
	RemoveSavedHandle((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_FlushParentHashtable(lua_State* l)
{
	FlushParentHashtable((HHASHTABLE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_FlushChildHashtable(lua_State* l)
{
	FlushChildHashtable((HHASHTABLE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetRandomInt(lua_State* l)
{
	lua_pushinteger(l, GetRandomInt((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetRandomReal(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushinteger(l, GetRandomReal(&a1, &a2));

	return 1;
}

LUA lua_CreateUnitPool(lua_State* l)
{
	lua_pushinteger(l, CreateUnitPool());

	return 1;
}

LUA lua_DestroyUnitPool(lua_State* l)
{
	DestroyUnitPool((HUNITPOOL)lua_tointeger(l, 1));

	return 0;
}

LUA lua_UnitPoolAddUnitType(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	UnitPoolAddUnitType((HUNITPOOL)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3);

	return 0;
}

LUA lua_UnitPoolRemoveUnitType(lua_State* l)
{
	UnitPoolRemoveUnitType((HUNITPOOL)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_PlaceRandomUnit(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, PlaceRandomUnit((HUNITPOOL)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), &a3, &a4, &a5));

	return 1;
}

LUA lua_CreateItemPool(lua_State* l)
{
	lua_pushinteger(l, CreateItemPool());

	return 1;
}

LUA lua_DestroyItemPool(lua_State* l)
{
	DestroyItemPool((HITEMPOOL)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ItemPoolAddItemType(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	ItemPoolAddItemType((HITEMPOOL)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), &a3);

	return 0;
}

LUA lua_ItemPoolRemoveItemType(lua_State* l)
{
	ItemPoolRemoveItemType((HITEMPOOL)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_PlaceRandomItem(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushinteger(l, PlaceRandomItem((HITEMPOOL)lua_tointeger(l, 1), &a2, &a3));

	return 1;
}

LUA lua_ChooseRandomCreep(lua_State* l)
{
	lua_pushinteger(l, ChooseRandomCreep((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ChooseRandomNPBuilding(lua_State* l)
{
	lua_pushinteger(l, ChooseRandomNPBuilding());

	return 1;
}

LUA lua_ChooseRandomItem(lua_State* l)
{
	lua_pushinteger(l, ChooseRandomItem((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_ChooseRandomItemEx(lua_State* l)
{
	lua_pushinteger(l, ChooseRandomItemEx((HITEMTYPE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_SetRandomSeed(lua_State* l)
{
	SetRandomSeed((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DisplayTextToPlayer(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	DisplayTextToPlayer((HPLAYER)lua_tointeger(l, 1), &a2, &a3, to_jString(lua_tostring(l, 4)));

	return 0;
}

LUA lua_DisplayTimedTextToPlayer(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	DisplayTimedTextToPlayer((HPLAYER)lua_tointeger(l, 1), &a2, &a3, &a4, to_jString(lua_tostring(l, 5)));

	return 0;
}

LUA lua_DisplayTimedTextFromPlayer(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	DisplayTimedTextFromPlayer((HPLAYER)lua_tointeger(l, 1), &a2, &a3, &a4, to_jString(lua_tostring(l, 5)));

	return 0;
}

LUA lua_ClearTextMessages(lua_State* l)
{
	ClearTextMessages();

	return 0;
}

LUA lua_EnableUserControl(lua_State* l)
{
	EnableUserControl(lua_toboolean(l, 1));

	return 0;
}

LUA lua_EnableUserUI(lua_State* l)
{
	EnableUserUI(lua_toboolean(l, 1));

	return 0;
}

LUA lua_DisableRestartMission(lua_State* l)
{
	DisableRestartMission(lua_toboolean(l, 1));

	return 0;
}

LUA lua_ForceUIKey(lua_State* l)
{
	ForceUIKey(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_ForceUICancel(lua_State* l)
{
	ForceUICancel();

	return 0;
}

LUA lua_DisplayLoadDialog(lua_State* l)
{
	DisplayLoadDialog();

	return 0;
}

LUA lua_SetTerrainFog(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	SetTerrainFog(&a1, &a2, &a3, &a4, &a5);

	return 0;
}

LUA lua_SetUnitFog(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	SetUnitFog(&a1, &a2, &a3, &a4, &a5);

	return 0;
}

LUA lua_SetTerrainFogEx(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));
	jReal a7 = to_jReal((float)lua_tonumber(l, 7));

	SetTerrainFogEx((jInteger)lua_tointeger(l, 1), &a2, &a3, &a4, &a5, &a6, &a7);

	return 0;
}

LUA lua_ResetTerrainFog(lua_State* l)
{
	ResetTerrainFog();

	return 0;
}

LUA lua_SetDayNightModels(lua_State* l)
{
	SetDayNightModels(to_jString(lua_tostring(l, 1)), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_SetSkyModel(lua_State* l)
{
	SetSkyModel(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_SuspendTimeOfDay(lua_State* l)
{
	SuspendTimeOfDay(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetTimeOfDayScale(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	SetTimeOfDayScale(&a1);

	return 0;
}

LUA lua_GetTimeOfDayScale(lua_State* l)
{
	lua_pushinteger(l, GetTimeOfDayScale());

	return 1;
}

LUA lua_ShowInterface(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	ShowInterface(lua_toboolean(l, 1), &a2);

	return 0;
}

LUA lua_PauseGame(lua_State* l)
{
	PauseGame(lua_toboolean(l, 1));

	return 0;
}

LUA lua_PingMinimap(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	PingMinimap(&a1, &a2, &a3);

	return 0;
}

LUA lua_PingMinimapEx(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	PingMinimapEx(&a1, &a2, &a3, (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6), lua_toboolean(l, 7));

	return 0;
}

LUA lua_SetIntroShotText(lua_State* l)
{
	SetIntroShotText(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_SetIntroShotModel(lua_State* l)
{
	SetIntroShotModel(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_EnableOcclusion(lua_State* l)
{
	EnableOcclusion(lua_toboolean(l, 1));

	return 0;
}

LUA lua_EnableWorldFogBoundary(lua_State* l)
{
	EnableWorldFogBoundary(lua_toboolean(l, 1));

	return 0;
}

LUA lua_PlayModelCinematic(lua_State* l)
{
	PlayModelCinematic(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_PlayCinematic(lua_State* l)
{
	PlayCinematic(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_SetAltMinimapIcon(lua_State* l)
{
	SetAltMinimapIcon(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_CreateTextTag(lua_State* l)
{
	lua_pushinteger(l, CreateTextTag());

	return 1;
}

LUA lua_DestroyTextTag(lua_State* l)
{
	DestroyTextTag((HTEXTTAG)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetTextTagText(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetTextTagText((HTEXTTAG)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), &a3);

	return 0;
}

LUA lua_SetTextTagPos(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetTextTagPos((HTEXTTAG)lua_tointeger(l, 1), &a2, &a3, &a4);

	return 0;
}

LUA lua_SetTextTagPosUnit(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetTextTagPosUnit((HTEXTTAG)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2), &a3);

	return 0;
}

LUA lua_SetTextTagColor(lua_State* l)
{
	SetTextTagColor((HTEXTTAG)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_SetTextTagVelocity(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetTextTagVelocity((HTEXTTAG)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetTextTagVisibility(lua_State* l)
{
	SetTextTagVisibility((HTEXTTAG)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetTextTagSuspended(lua_State* l)
{
	SetTextTagSuspended((HTEXTTAG)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetTextTagPermanent(lua_State* l)
{
	SetTextTagPermanent((HTEXTTAG)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetTextTagAge(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetTextTagAge((HTEXTTAG)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetTextTagLifespan(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetTextTagLifespan((HTEXTTAG)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetTextTagFadepoint(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetTextTagFadepoint((HTEXTTAG)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetReservedLocalHeroButtons(lua_State* l)
{
	SetReservedLocalHeroButtons((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GetAllyColorFilterState(lua_State* l)
{
	lua_pushinteger(l, GetAllyColorFilterState());

	return 1;
}

LUA lua_SetAllyColorFilterState(lua_State* l)
{
	SetAllyColorFilterState((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_GetCreepCampFilterState(lua_State* l)
{
	lua_pushboolean(l, GetCreepCampFilterState());

	return 1;
}

LUA lua_SetCreepCampFilterState(lua_State* l)
{
	SetCreepCampFilterState(lua_toboolean(l, 1));

	return 0;
}

LUA lua_EnableMinimapFilterButtons(lua_State* l)
{
	EnableMinimapFilterButtons(lua_toboolean(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_EnableDragSelect(lua_State* l)
{
	EnableDragSelect(lua_toboolean(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_EnablePreSelect(lua_State* l)
{
	EnablePreSelect(lua_toboolean(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_EnableSelect(lua_State* l)
{
	EnableSelect(lua_toboolean(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_CreateTrackable(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, CreateTrackable(to_jString(lua_tostring(l, 1)), &a2, &a3, &a4));

	return 1;
}

LUA lua_TriggerRegisterTrackableHitEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterTrackableHitEvent((jTrigger)lua_tointeger(l, 1), (HTRACKABLE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_TriggerRegisterTrackableTrackEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterTrackableTrackEvent((jTrigger)lua_tointeger(l, 1), (HTRACKABLE)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetTriggeringTrackable(lua_State* l)
{
	lua_pushinteger(l, GetTriggeringTrackable());

	return 1;
}

LUA lua_CreateQuest(lua_State* l)
{
	lua_pushinteger(l, CreateQuest());

	return 1;
}

LUA lua_DestroyQuest(lua_State* l)
{
	DestroyQuest((HQUEST)lua_tointeger(l, 1));

	return 0;
}

LUA lua_QuestSetTitle(lua_State* l)
{
	QuestSetTitle((HQUEST)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_QuestSetDescription(lua_State* l)
{
	QuestSetDescription((HQUEST)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_QuestSetIconPath(lua_State* l)
{
	QuestSetIconPath((HQUEST)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_QuestSetRequired(lua_State* l)
{
	QuestSetRequired((HQUEST)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_QuestSetCompleted(lua_State* l)
{
	QuestSetCompleted((HQUEST)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_QuestSetDiscovered(lua_State* l)
{
	QuestSetDiscovered((HQUEST)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_QuestSetFailed(lua_State* l)
{
	QuestSetFailed((HQUEST)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_QuestSetEnabled(lua_State* l)
{
	QuestSetEnabled((HQUEST)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsQuestRequired(lua_State* l)
{
	lua_pushboolean(l, IsQuestRequired((HQUEST)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsQuestCompleted(lua_State* l)
{
	lua_pushboolean(l, IsQuestCompleted((HQUEST)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsQuestDiscovered(lua_State* l)
{
	lua_pushboolean(l, IsQuestDiscovered((HQUEST)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsQuestFailed(lua_State* l)
{
	lua_pushboolean(l, IsQuestFailed((HQUEST)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsQuestEnabled(lua_State* l)
{
	lua_pushboolean(l, IsQuestEnabled((HQUEST)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_QuestCreateItem(lua_State* l)
{
	lua_pushinteger(l, QuestCreateItem((HQUEST)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_QuestItemSetDescription(lua_State* l)
{
	QuestItemSetDescription((HQUESTITEM)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_QuestItemSetCompleted(lua_State* l)
{
	QuestItemSetCompleted((HQUESTITEM)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsQuestItemCompleted(lua_State* l)
{
	lua_pushboolean(l, IsQuestItemCompleted((HQUESTITEM)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CreateDefeatCondition(lua_State* l)
{
	lua_pushinteger(l, CreateDefeatCondition());

	return 1;
}

LUA lua_DestroyDefeatCondition(lua_State* l)
{
	DestroyDefeatCondition((HDEFEATCONDITION)lua_tointeger(l, 1));

	return 0;
}

LUA lua_DefeatConditionSetDescription(lua_State* l)
{
	DefeatConditionSetDescription((HDEFEATCONDITION)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_FlashQuestDialogButton(lua_State* l)
{
	FlashQuestDialogButton();

	return 0;
}

LUA lua_ForceQuestDialogUpdate(lua_State* l)
{
	ForceQuestDialogUpdate();

	return 0;
}

LUA lua_CreateTimerDialog(lua_State* l)
{
	lua_pushinteger(l, CreateTimerDialog((HTIMER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_DestroyTimerDialog(lua_State* l)
{
	DestroyTimerDialog((HTIMERDIALOG)lua_tointeger(l, 1));

	return 0;
}

LUA lua_TimerDialogSetTitle(lua_State* l)
{
	TimerDialogSetTitle((HTIMERDIALOG)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_TimerDialogSetTitleColor(lua_State* l)
{
	TimerDialogSetTitleColor((HTIMERDIALOG)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_TimerDialogSetTimeColor(lua_State* l)
{
	TimerDialogSetTimeColor((HTIMERDIALOG)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_TimerDialogSetSpeed(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	TimerDialogSetSpeed((HTIMERDIALOG)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_TimerDialogDisplay(lua_State* l)
{
	TimerDialogDisplay((HTIMERDIALOG)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsTimerDialogDisplayed(lua_State* l)
{
	lua_pushboolean(l, IsTimerDialogDisplayed((HTIMERDIALOG)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_TimerDialogSetRealTimeRemaining(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	TimerDialogSetRealTimeRemaining((HTIMERDIALOG)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_CreateLeaderboard(lua_State* l)
{
	lua_pushinteger(l, CreateLeaderboard());

	return 1;
}

LUA lua_DestroyLeaderboard(lua_State* l)
{
	DestroyLeaderboard((HLEADERBOARD)lua_tointeger(l, 1));

	return 0;
}

LUA lua_LeaderboardGetItemCount(lua_State* l)
{
	lua_pushinteger(l, LeaderboardGetItemCount((HLEADERBOARD)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_LeaderboardSetSizeByItemCount(lua_State* l)
{
	LeaderboardSetSizeByItemCount((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_LeaderboardAddItem(lua_State* l)
{
	LeaderboardAddItem((HLEADERBOARD)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)), (jInteger)lua_tointeger(l, 3), (HPLAYER)lua_tointeger(l, 4));

	return 0;
}

LUA lua_LeaderboardRemoveItem(lua_State* l)
{
	LeaderboardRemoveItem((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_LeaderboardRemovePlayerItem(lua_State* l)
{
	LeaderboardRemovePlayerItem((HLEADERBOARD)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2));

	return 0;
}

LUA lua_LeaderboardSortItemsByValue(lua_State* l)
{
	LeaderboardSortItemsByValue((HLEADERBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_LeaderboardSortItemsByPlayer(lua_State* l)
{
	LeaderboardSortItemsByPlayer((HLEADERBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_LeaderboardSortItemsByLabel(lua_State* l)
{
	LeaderboardSortItemsByLabel((HLEADERBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_LeaderboardClear(lua_State* l)
{
	LeaderboardClear((HLEADERBOARD)lua_tointeger(l, 1));

	return 0;
}

LUA lua_LeaderboardDisplay(lua_State* l)
{
	LeaderboardDisplay((HLEADERBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsLeaderboardDisplayed(lua_State* l)
{
	lua_pushboolean(l, IsLeaderboardDisplayed((HLEADERBOARD)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_LeaderboardGetLabelText(lua_State* l)
{
	lua_pushstring(l, from_jString(LeaderboardGetLabelText((HLEADERBOARD)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_PlayerSetLeaderboard(lua_State* l)
{
	PlayerSetLeaderboard((HPLAYER)lua_tointeger(l, 1), (HLEADERBOARD)lua_tointeger(l, 2));

	return 0;
}

LUA lua_PlayerGetLeaderboard(lua_State* l)
{
	lua_pushinteger(l, PlayerGetLeaderboard((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_LeaderboardHasPlayerItem(lua_State* l)
{
	lua_pushboolean(l, LeaderboardHasPlayerItem((HLEADERBOARD)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_LeaderboardGetPlayerIndex(lua_State* l)
{
	lua_pushinteger(l, LeaderboardGetPlayerIndex((HLEADERBOARD)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_LeaderboardSetLabel(lua_State* l)
{
	LeaderboardSetLabel((HLEADERBOARD)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_LeaderboardSetLabelColor(lua_State* l)
{
	LeaderboardSetLabelColor((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_LeaderboardSetValueColor(lua_State* l)
{
	LeaderboardSetValueColor((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_LeaderboardSetStyle(lua_State* l)
{
	LeaderboardSetStyle((HLEADERBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), lua_toboolean(l, 5));

	return 0;
}

LUA lua_LeaderboardSetItemValue(lua_State* l)
{
	LeaderboardSetItemValue((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_LeaderboardSetItemLabel(lua_State* l)
{
	LeaderboardSetItemLabel((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3)));

	return 0;
}

LUA lua_LeaderboardSetItemStyle(lua_State* l)
{
	LeaderboardSetItemStyle((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), lua_toboolean(l, 5));

	return 0;
}

LUA lua_LeaderboardSetItemLabelColor(lua_State* l)
{
	LeaderboardSetItemLabelColor((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6));

	return 0;
}

LUA lua_LeaderboardSetItemValueColor(lua_State* l)
{
	LeaderboardSetItemValueColor((HLEADERBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6));

	return 0;
}

LUA lua_CreateMultiboard(lua_State* l)
{
	lua_pushinteger(l, CreateMultiboard());

	return 1;
}

LUA lua_DestroyMultiboard(lua_State* l)
{
	DestroyMultiboard((HMULTIBOARD)lua_tointeger(l, 1));

	return 0;
}

LUA lua_MultiboardDisplay(lua_State* l)
{
	MultiboardDisplay((HMULTIBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_MultiboardMinimize(lua_State* l)
{
	MultiboardMinimize((HMULTIBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_IsMultiboardDisplayed(lua_State* l)
{
	lua_pushboolean(l, IsMultiboardDisplayed((HMULTIBOARD)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_IsMultiboardMinimized(lua_State* l)
{
	lua_pushboolean(l, IsMultiboardMinimized((HMULTIBOARD)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_MultiboardClear(lua_State* l)
{
	MultiboardClear((HMULTIBOARD)lua_tointeger(l, 1));

	return 0;
}

LUA lua_MultiboardSetTitleText(lua_State* l)
{
	MultiboardSetTitleText((HMULTIBOARD)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_MultiboardGetTitleText(lua_State* l)
{
	lua_pushstring(l, from_jString(MultiboardGetTitleText((HMULTIBOARD)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_MultiboardSetTitleTextColor(lua_State* l)
{
	MultiboardSetTitleTextColor((HMULTIBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_MultiboardGetRowCount(lua_State* l)
{
	lua_pushinteger(l, MultiboardGetRowCount((HMULTIBOARD)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_MultiboardGetColumnCount(lua_State* l)
{
	lua_pushinteger(l, MultiboardGetColumnCount((HMULTIBOARD)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_MultiboardSetColumnCount(lua_State* l)
{
	MultiboardSetColumnCount((HMULTIBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_MultiboardSetRowCount(lua_State* l)
{
	MultiboardSetRowCount((HMULTIBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_MultiboardSetItemsStyle(lua_State* l)
{
	MultiboardSetItemsStyle((HMULTIBOARD)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_MultiboardSetItemsValueColor(lua_State* l)
{
	MultiboardSetItemsValueColor((HMULTIBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_MultiboardSetItemsValue(lua_State* l)
{
	MultiboardSetItemsValue((HMULTIBOARD)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_MultiboardSetItemsWidth(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	MultiboardSetItemsWidth((HMULTIBOARD)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_MultiboardSetItemsIcon(lua_State* l)
{
	MultiboardSetItemsIcon((HMULTIBOARD)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_MultiboardGetItem(lua_State* l)
{
	lua_pushinteger(l, MultiboardGetItem((HMULTIBOARD)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_MultiboardReleaseItem(lua_State* l)
{
	MultiboardReleaseItem((HMULTIBOARDITEM)lua_tointeger(l, 1));

	return 0;
}

LUA lua_MultiboardSetItemStyle(lua_State* l)
{
	MultiboardSetItemStyle((HMULTIBOARDITEM)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_MultiboardSetItemValue(lua_State* l)
{
	MultiboardSetItemValue((HMULTIBOARDITEM)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_MultiboardSetItemValueColor(lua_State* l)
{
	MultiboardSetItemValueColor((HMULTIBOARDITEM)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_MultiboardSetItemWidth(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	MultiboardSetItemWidth((HMULTIBOARDITEM)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_MultiboardSetItemIcon(lua_State* l)
{
	MultiboardSetItemIcon((HMULTIBOARDITEM)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_MultiboardSuppressDisplay(lua_State* l)
{
	MultiboardSuppressDisplay(lua_toboolean(l, 1));

	return 0;
}

LUA lua_SetCameraBounds(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));
	jReal a7 = to_jReal((float)lua_tonumber(l, 7));
	jReal a8 = to_jReal((float)lua_tonumber(l, 8));

	SetCameraBounds(&a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8);

	return 0;
}

LUA lua_SetCameraPosition(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetCameraPosition(&a1, &a2);

	return 0;
}

LUA lua_SetCameraQuickPosition(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetCameraQuickPosition(&a1, &a2);

	return 0;
}

LUA lua_ResetToGameCamera(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	ResetToGameCamera(&a1);

	return 0;
}

LUA lua_StopCamera(lua_State* l)
{
	StopCamera();

	return 0;
}

LUA lua_PanCameraTo(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	PanCameraTo(&a1, &a2);

	return 0;
}

LUA lua_PanCameraToTimed(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	PanCameraToTimed(&a1, &a2, &a3);

	return 0;
}

LUA lua_PanCameraToWithZ(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	PanCameraToWithZ(&a1, &a2, &a3);

	return 0;
}

LUA lua_PanCameraToTimedWithZ(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	PanCameraToTimedWithZ(&a1, &a2, &a3, &a4);

	return 0;
}

LUA lua_SetCinematicCamera(lua_State* l)
{
	SetCinematicCamera(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_SetCameraField(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetCameraField((HCAMERAFIELD)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_AdjustCameraField(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	AdjustCameraField((HCAMERAFIELD)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetCameraTargetController(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetCameraTargetController((HUNIT)lua_tointeger(l, 1), &a2, &a3, lua_toboolean(l, 4));

	return 0;
}

LUA lua_SetCameraOrientController(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetCameraOrientController((HUNIT)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetCameraRotateMode(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetCameraRotateMode(&a1, &a2, &a3, &a4);

	return 0;
}

LUA lua_CreateCameraSetup(lua_State* l)
{
	lua_pushinteger(l, CreateCameraSetup());

	return 1;
}

LUA lua_CameraSetupSetField(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	CameraSetupSetField((HCAMERASETUP)lua_tointeger(l, 1), (HCAMERAFIELD)lua_tointeger(l, 2), &a3, &a4);

	return 0;
}

LUA lua_CameraSetupGetField(lua_State* l)
{
	lua_pushinteger(l, CameraSetupGetField((HCAMERASETUP)lua_tointeger(l, 1), (HCAMERAFIELD)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_CameraSetupSetDestPosition(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	CameraSetupSetDestPosition((HCAMERASETUP)lua_tointeger(l, 1), &a2, &a3, &a4);

	return 0;
}

LUA lua_CameraSetupGetDestPositionLoc(lua_State* l)
{
	lua_pushinteger(l, CameraSetupGetDestPositionLoc((HCAMERASETUP)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CameraSetupGetDestPositionX(lua_State* l)
{
	lua_pushinteger(l, CameraSetupGetDestPositionX((HCAMERASETUP)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CameraSetupGetDestPositionY(lua_State* l)
{
	lua_pushinteger(l, CameraSetupGetDestPositionY((HCAMERASETUP)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_CameraSetupApply(lua_State* l)
{
	CameraSetupApply((HCAMERASETUP)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_CameraSetupApplyWithZ(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	CameraSetupApplyWithZ((HCAMERASETUP)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_CameraSetupApplyForceDuration(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	CameraSetupApplyForceDuration((HCAMERASETUP)lua_tointeger(l, 1), lua_toboolean(l, 2), &a3);

	return 0;
}

LUA lua_CameraSetupApplyForceDurationWithZ(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	CameraSetupApplyForceDurationWithZ((HCAMERASETUP)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_CameraSetTargetNoise(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	CameraSetTargetNoise(&a1, &a2);

	return 0;
}

LUA lua_CameraSetSourceNoise(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	CameraSetSourceNoise(&a1, &a2);

	return 0;
}

LUA lua_CameraSetTargetNoiseEx(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	CameraSetTargetNoiseEx(&a1, &a2, lua_toboolean(l, 3));

	return 0;
}

LUA lua_CameraSetSourceNoiseEx(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	CameraSetSourceNoiseEx(&a1, &a2, lua_toboolean(l, 3));

	return 0;
}

LUA lua_CameraSetSmoothingFactor(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	CameraSetSmoothingFactor(&a1);

	return 0;
}

LUA lua_GetCameraMargin(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetCameraMargin((jInteger)lua_tointeger(l, 1))));

	return 1;
}

LUA lua_GetCameraBoundMinX(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetCameraBoundMinX()));

	return 1;
}

LUA lua_GetCameraBoundMinY(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetCameraBoundMinY()));

	return 1;
}

LUA lua_GetCameraBoundMaxX(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetCameraBoundMaxX()));

	return 1;
}

LUA lua_GetCameraBoundMaxY(lua_State* l)
{
	lua_pushnumber(l, from_jReal(GetCameraBoundMaxY()));

	return 1;
}

LUA lua_GetCameraField(lua_State* l)
{
	lua_pushinteger(l, GetCameraField((HCAMERAFIELD)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetCameraTargetPositionX(lua_State* l)
{
	lua_pushinteger(l, GetCameraTargetPositionX());

	return 1;
}

LUA lua_GetCameraTargetPositionY(lua_State* l)
{
	lua_pushinteger(l, GetCameraTargetPositionY());

	return 1;
}

LUA lua_GetCameraTargetPositionZ(lua_State* l)
{
	lua_pushinteger(l, GetCameraTargetPositionZ());

	return 1;
}

LUA lua_GetCameraTargetPositionLoc(lua_State* l)
{
	lua_pushinteger(l, GetCameraTargetPositionLoc());

	return 1;
}

LUA lua_GetCameraEyePositionX(lua_State* l)
{
	lua_pushinteger(l, GetCameraEyePositionX());

	return 1;
}

LUA lua_GetCameraEyePositionY(lua_State* l)
{
	lua_pushinteger(l, GetCameraEyePositionY());

	return 1;
}

LUA lua_GetCameraEyePositionZ(lua_State* l)
{
	lua_pushinteger(l, GetCameraEyePositionZ());

	return 1;
}

LUA lua_GetCameraEyePositionLoc(lua_State* l)
{
	lua_pushinteger(l, GetCameraEyePositionLoc());

	return 1;
}

LUA lua_SetCineFilterTexture(lua_State* l)
{
	SetCineFilterTexture(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_SetCineFilterBlendMode(lua_State* l)
{
	SetCineFilterBlendMode((HBLENDMODE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetCineFilterTexMapFlags(lua_State* l)
{
	SetCineFilterTexMapFlags((HTEXMAPFLAGS)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetCineFilterStartUV(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetCineFilterStartUV(&a1, &a2, &a3, &a4);

	return 0;
}

LUA lua_SetCineFilterEndUV(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetCineFilterEndUV(&a1, &a2, &a3, &a4);

	return 0;
}

LUA lua_SetCineFilterStartColor(lua_State* l)
{
	SetCineFilterStartColor((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_SetCineFilterEndColor(lua_State* l)
{
	SetCineFilterEndColor((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_SetCineFilterDuration(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	SetCineFilterDuration(&a1);

	return 0;
}

LUA lua_DisplayCineFilter(lua_State* l)
{
	DisplayCineFilter(lua_toboolean(l, 1));

	return 0;
}

LUA lua_IsCineFilterDisplayed(lua_State* l)
{
	lua_pushboolean(l, IsCineFilterDisplayed());

	return 1;
}

LUA lua_SetCinematicScene(lua_State* l)
{
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));

	SetCinematicScene((jInteger)lua_tointeger(l, 1), (HPLAYERCOLOR)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3)), to_jString(lua_tostring(l, 4)), &a5, &a6);

	return 0;
}

LUA lua_EndCinematicScene(lua_State* l)
{
	EndCinematicScene();

	return 0;
}

LUA lua_ForceCinematicSubtitles(lua_State* l)
{
	ForceCinematicSubtitles(lua_toboolean(l, 1));

	return 0;
}

LUA lua_NewSoundEnvironment(lua_State* l)
{
	NewSoundEnvironment(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_CreateSound(lua_State* l)
{
	lua_pushinteger(l, CreateSound(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6), to_jString(lua_tostring(l, 7))));

	return 1;
}

LUA lua_CreateSoundFilenameWithLabel(lua_State* l)
{
	lua_pushinteger(l, CreateSoundFilenameWithLabel(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6), to_jString(lua_tostring(l, 7))));

	return 1;
}

LUA lua_CreateSoundFromLabel(lua_State* l)
{
	lua_pushinteger(l, CreateSoundFromLabel(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2), lua_toboolean(l, 3), lua_toboolean(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6)));

	return 1;
}

LUA lua_CreateMIDISound(lua_State* l)
{
	lua_pushinteger(l, CreateMIDISound(to_jString(lua_tostring(l, 1)), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_SetStackedSound(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetStackedSound(to_jString(lua_tostring(l, 1)), &a2, &a3);

	return 0;
}

LUA lua_ClearStackedSound(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	ClearStackedSound(to_jString(lua_tostring(l, 1)), &a2, &a3);

	return 0;
}

LUA lua_SetStackedSoundRect(lua_State* l)
{
	SetStackedSoundRect(to_jString(lua_tostring(l, 1)), (HRECT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_ClearStackedSoundRect(lua_State* l)
{
	ClearStackedSoundRect(to_jString(lua_tostring(l, 1)), (HRECT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetSoundParamsFromLabel(lua_State* l)
{
	SetSoundParamsFromLabel((HSOUND)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_SetSoundChannel(lua_State* l)
{
	SetSoundChannel((HSOUND)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetSoundVolume(lua_State* l)
{
	SetSoundVolume((HSOUND)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetSoundPitch(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetSoundPitch((HSOUND)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetSoundPlayPosition(lua_State* l)
{
	SetSoundPlayPosition((HSOUND)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_SetSoundDistances(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetSoundDistances((HSOUND)lua_tointeger(l, 1), &a2, &a3);

	return 0;
}

LUA lua_SetSoundDistanceCutoff(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetSoundDistanceCutoff((HSOUND)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_SetSoundConeAngles(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetSoundConeAngles((HSOUND)lua_tointeger(l, 1), &a2, &a3, (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_SetSoundConeOrientation(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetSoundConeOrientation((HSOUND)lua_tointeger(l, 1), &a2, &a3, &a4);

	return 0;
}

LUA lua_SetSoundPosition(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetSoundPosition((HSOUND)lua_tointeger(l, 1), &a2, &a3, &a4);

	return 0;
}

LUA lua_SetSoundVelocity(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetSoundVelocity((HSOUND)lua_tointeger(l, 1), &a2, &a3, &a4);

	return 0;
}

LUA lua_AttachSoundToUnit(lua_State* l)
{
	AttachSoundToUnit((HSOUND)lua_tointeger(l, 1), (HUNIT)lua_tointeger(l, 2));

	return 0;
}

LUA lua_StartSound(lua_State* l)
{
	StartSound((HSOUND)lua_tointeger(l, 1));

	return 0;
}

LUA lua_StopSound(lua_State* l)
{
	StopSound((HSOUND)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_KillSoundWhenDone(lua_State* l)
{
	KillSoundWhenDone((HSOUND)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetMapMusic(lua_State* l)
{
	SetMapMusic(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_ClearMapMusic(lua_State* l)
{
	ClearMapMusic();

	return 0;
}

LUA lua_PlayMusic(lua_State* l)
{
	PlayMusic(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_PlayMusicEx(lua_State* l)
{
	PlayMusicEx(to_jString(lua_tostring(l, 1)), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_StopMusic(lua_State* l)
{
	StopMusic(lua_toboolean(l, 1));

	return 0;
}

LUA lua_ResumeMusic(lua_State* l)
{
	ResumeMusic();

	return 0;
}

LUA lua_PlayThematicMusic(lua_State* l)
{
	PlayThematicMusic(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_PlayThematicMusicEx(lua_State* l)
{
	PlayThematicMusicEx(to_jString(lua_tostring(l, 1)), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_EndThematicMusic(lua_State* l)
{
	EndThematicMusic();

	return 0;
}

LUA lua_SetMusicVolume(lua_State* l)
{
	SetMusicVolume((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetMusicPlayPosition(lua_State* l)
{
	SetMusicPlayPosition((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetThematicMusicPlayPosition(lua_State* l)
{
	SetThematicMusicPlayPosition((jInteger)lua_tointeger(l, 1));

	return 0;
}

LUA lua_SetSoundDuration(lua_State* l)
{
	SetSoundDuration((HSOUND)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_GetSoundDuration(lua_State* l)
{
	lua_pushinteger(l, GetSoundDuration((HSOUND)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetSoundFileDuration(lua_State* l)
{
	lua_pushinteger(l, GetSoundFileDuration(to_jString(lua_tostring(l, 1))));

	return 1;
}

LUA lua_VolumeGroupSetVolume(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	VolumeGroupSetVolume((HVOLUMEGROUP)lua_tointeger(l, 1), &a2);

	return 0;
}

LUA lua_VolumeGroupReset(lua_State* l)
{
	VolumeGroupReset();

	return 0;
}

LUA lua_GetSoundIsPlaying(lua_State* l)
{
	lua_pushboolean(l, GetSoundIsPlaying((HSOUND)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetSoundIsLoading(lua_State* l)
{
	lua_pushboolean(l, GetSoundIsLoading((HSOUND)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_RegisterStackedSound(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	RegisterStackedSound((HSOUND)lua_tointeger(l, 1), lua_toboolean(l, 2), &a3, &a4);

	return 0;
}

LUA lua_UnregisterStackedSound(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	UnregisterStackedSound((HSOUND)lua_tointeger(l, 1), lua_toboolean(l, 2), &a3, &a4);

	return 0;
}

LUA lua_AddWeatherEffect(lua_State* l)
{
	lua_pushinteger(l, AddWeatherEffect((HRECT)lua_tointeger(l, 1), to_ID(lua_tostring(l, 2))));

	return 1;
}

LUA lua_RemoveWeatherEffect(lua_State* l)
{
	RemoveWeatherEffect((HWEATHEREFFECT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_EnableWeatherEffect(lua_State* l)
{
	EnableWeatherEffect((HWEATHEREFFECT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_TerrainDeformCrater(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, TerrainDeformCrater(&a1, &a2, &a3, &a4, (jInteger)lua_tointeger(l, 5), lua_toboolean(l, 6)));

	return 1;
}

LUA lua_TerrainDeformRipple(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	jReal a7 = to_jReal((float)lua_tonumber(l, 7));
	jReal a8 = to_jReal((float)lua_tonumber(l, 8));
	jReal a9 = to_jReal((float)lua_tonumber(l, 9));

	lua_pushinteger(l, TerrainDeformRipple(&a1, &a2, &a3, &a4, (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6), &a7, &a8, &a9, lua_toboolean(l, 10)));

	return 1;
}

LUA lua_TerrainDeformWave(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));
	jReal a7 = to_jReal((float)lua_tonumber(l, 7));
	jReal a8 = to_jReal((float)lua_tonumber(l, 8));

	lua_pushinteger(l, TerrainDeformWave(&a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, (jInteger)lua_tointeger(l, 9), (jInteger)lua_tointeger(l, 10)));

	return 1;
}

LUA lua_TerrainDeformRandom(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushinteger(l, TerrainDeformRandom(&a1, &a2, &a3, &a4, &a5, (jInteger)lua_tointeger(l, 6), (jInteger)lua_tointeger(l, 7)));

	return 1;
}

LUA lua_TerrainDeformStop(lua_State* l)
{
	TerrainDeformStop((HTERRAINDEFORMATION)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_TerrainDeformStopAll(lua_State* l)
{
	TerrainDeformStopAll();

	return 0;
}

LUA lua_DestroyEffect(lua_State* l)
{
	DestroyEffect((HEFFECT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_AddSpecialEffect(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	lua_pushinteger(l, AddSpecialEffect(to_jString(lua_tostring(l, 1)), &a2, &a3));

	return 1;
}

LUA lua_AddSpecialEffectLoc(lua_State* l)
{
	lua_pushinteger(l, AddSpecialEffectLoc(to_jString(lua_tostring(l, 1)), (HLOCATION)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_AddSpecialEffectTarget(lua_State* l)
{
	lua_pushinteger(l, AddSpecialEffectTarget(to_jString(lua_tostring(l, 1)), (HWIDGET)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3))));

	return 1;
}

LUA lua_AddSpellEffect(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, AddSpellEffect(to_jString(lua_tostring(l, 1)), (HEFFECTTYPE)lua_tointeger(l, 2), &a3, &a4));

	return 1;
}

LUA lua_AddSpellEffectLoc(lua_State* l)
{
	lua_pushinteger(l, AddSpellEffectLoc(to_jString(lua_tostring(l, 1)), (HEFFECTTYPE)lua_tointeger(l, 2), (HLOCATION)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_AddSpellEffectById(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, AddSpellEffectById((jInteger)lua_tointeger(l, 1), (HEFFECTTYPE)lua_tointeger(l, 2), &a3, &a4));

	return 1;
}

LUA lua_AddSpellEffectByIdLoc(lua_State* l)
{
	lua_pushinteger(l, AddSpellEffectByIdLoc((jInteger)lua_tointeger(l, 1), (HEFFECTTYPE)lua_tointeger(l, 2), (HLOCATION)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_AddSpellEffectTarget(lua_State* l)
{
	lua_pushinteger(l, AddSpellEffectTarget(to_jString(lua_tostring(l, 1)), (HEFFECTTYPE)lua_tointeger(l, 2), (HWIDGET)lua_tointeger(l, 3), to_jString(lua_tostring(l, 4))));

	return 1;
}

LUA lua_AddSpellEffectTargetById(lua_State* l)
{
	lua_pushinteger(l, AddSpellEffectTargetById((jInteger)lua_tointeger(l, 1), (HEFFECTTYPE)lua_tointeger(l, 2), (HWIDGET)lua_tointeger(l, 3), to_jString(lua_tostring(l, 4))));

	return 1;
}

LUA lua_AddLightning(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));

	lua_pushinteger(l, AddLightning(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2), &a3, &a4, &a5, &a6));

	return 1;
}

LUA lua_AddLightningEx(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));
	jReal a7 = to_jReal((float)lua_tonumber(l, 7));
	jReal a8 = to_jReal((float)lua_tonumber(l, 8));

	lua_pushinteger(l, AddLightningEx(to_jString(lua_tostring(l, 1)), lua_toboolean(l, 2), &a3, &a4, &a5, &a6, &a7, &a8));

	return 1;
}

LUA lua_DestroyLightning(lua_State* l)
{
	lua_pushboolean(l, DestroyLightning((HLIGHTNING)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetLightningColorA(lua_State* l)
{
	lua_pushinteger(l, GetLightningColorA((HLIGHTNING)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetLightningColorR(lua_State* l)
{
	lua_pushinteger(l, GetLightningColorR((HLIGHTNING)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetLightningColorG(lua_State* l)
{
	lua_pushinteger(l, GetLightningColorG((HLIGHTNING)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetLightningColorB(lua_State* l)
{
	lua_pushinteger(l, GetLightningColorB((HLIGHTNING)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_MoveLightning(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));

	lua_pushboolean(l, MoveLightning((HLIGHTNING)lua_tointeger(l, 1), lua_toboolean(l, 2), &a3, &a4, &a5, &a6));

	return 1;
}

LUA lua_MoveLightningEx(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));
	jReal a7 = to_jReal((float)lua_tonumber(l, 7));
	jReal a8 = to_jReal((float)lua_tonumber(l, 8));

	lua_pushboolean(l, MoveLightningEx((HLIGHTNING)lua_tointeger(l, 1), lua_toboolean(l, 2), &a3, &a4, &a5, &a6, &a7, &a8));

	return 1;
}

LUA lua_SetLightningColor(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));

	lua_pushboolean(l, SetLightningColor((HLIGHTNING)lua_tointeger(l, 1), &a2, &a3, &a4, &a5));

	return 1;
}

LUA lua_GetAbilityEffect(lua_State* l)
{
	lua_pushstring(l, from_jString(GetAbilityEffect(to_jString(lua_tostring(l, 1)), (HEFFECTTYPE)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3))));

	return 1;
}

LUA lua_GetAbilityEffectById(lua_State* l)
{
	lua_pushstring(l, from_jString(GetAbilityEffectById((jInteger)lua_tointeger(l, 1), (HEFFECTTYPE)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3))));

	return 1;
}

LUA lua_GetAbilitySound(lua_State* l)
{
	lua_pushstring(l, from_jString(GetAbilitySound(to_jString(lua_tostring(l, 1)), (HSOUNDTYPE)lua_tointeger(l, 2))));

	return 1;
}

LUA lua_GetAbilitySoundById(lua_State* l)
{
	lua_pushstring(l, from_jString(GetAbilitySoundById((jInteger)lua_tointeger(l, 1), (HSOUNDTYPE)lua_tointeger(l, 2))));

	return 1;
}

LUA lua_GetTerrainCliffLevel(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushinteger(l, GetTerrainCliffLevel(&a1, &a2));

	return 1;
}

LUA lua_SetWaterBaseColor(lua_State* l)
{
	SetWaterBaseColor((jInteger)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4));

	return 0;
}

LUA lua_SetWaterDeforms(lua_State* l)
{
	SetWaterDeforms(lua_toboolean(l, 1));

	return 0;
}

LUA lua_GetTerrainType(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushinteger(l, GetTerrainType(&a1, &a2));

	return 1;
}

LUA lua_GetTerrainVariance(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushinteger(l, GetTerrainVariance(&a1, &a2));

	return 1;
}

LUA lua_SetTerrainType(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetTerrainType(&a1, &a2, (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6));

	return 0;
}

LUA lua_IsTerrainPathable(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushboolean(l, IsTerrainPathable(&a1, &a2, (HPATHINGTYPE)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_SetTerrainPathable(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	SetTerrainPathable(&a1, &a2, (HPATHINGTYPE)lua_tointeger(l, 3), lua_toboolean(l, 4));

	return 0;
}

LUA lua_CreateImage(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));
	jReal a5 = to_jReal((float)lua_tonumber(l, 5));
	jReal a6 = to_jReal((float)lua_tonumber(l, 6));
	jReal a7 = to_jReal((float)lua_tonumber(l, 7));
	jReal a8 = to_jReal((float)lua_tonumber(l, 8));
	jReal a9 = to_jReal((float)lua_tonumber(l, 9));
	jReal a10 = to_jReal((float)lua_tonumber(l, 10));

	lua_pushinteger(l, CreateImage(to_jString(lua_tostring(l, 1)), &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, (jInteger)lua_tointeger(l, 11)));

	return 1;
}

LUA lua_DestroyImage(lua_State* l)
{
	DestroyImage((HIMAGE)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ShowImage(lua_State* l)
{
	ShowImage((HIMAGE)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetImageConstantHeight(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetImageConstantHeight((HIMAGE)lua_tointeger(l, 1), lua_toboolean(l, 2), &a3);

	return 0;
}

LUA lua_SetImagePosition(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetImagePosition((HIMAGE)lua_tointeger(l, 1), &a2, &a3, &a4);

	return 0;
}

LUA lua_SetImageColor(lua_State* l)
{
	SetImageColor((HIMAGE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5));

	return 0;
}

LUA lua_SetImageRender(lua_State* l)
{
	SetImageRender((HIMAGE)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetImageRenderAlways(lua_State* l)
{
	SetImageRenderAlways((HIMAGE)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetImageAboveWater(lua_State* l)
{
	SetImageAboveWater((HIMAGE)lua_tointeger(l, 1), lua_toboolean(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetImageType(lua_State* l)
{
	SetImageType((HIMAGE)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2));

	return 0;
}

LUA lua_CreateUbersplat(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushinteger(l, CreateUbersplat(&a1, &a2, to_jString(lua_tostring(l, 3)), (jInteger)lua_tointeger(l, 4), (jInteger)lua_tointeger(l, 5), (jInteger)lua_tointeger(l, 6), (jInteger)lua_tointeger(l, 7), lua_toboolean(l, 8), lua_toboolean(l, 9)));

	return 1;
}

LUA lua_DestroyUbersplat(lua_State* l)
{
	DestroyUbersplat((HUBERSPLAT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ResetUbersplat(lua_State* l)
{
	ResetUbersplat((HUBERSPLAT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_FinishUbersplat(lua_State* l)
{
	FinishUbersplat((HUBERSPLAT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ShowUbersplat(lua_State* l)
{
	ShowUbersplat((HUBERSPLAT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetUbersplatRender(lua_State* l)
{
	SetUbersplatRender((HUBERSPLAT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetUbersplatRenderAlways(lua_State* l)
{
	SetUbersplatRenderAlways((HUBERSPLAT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_SetBlight(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	SetBlight((HPLAYER)lua_tointeger(l, 1), &a2, &a3, &a4, lua_toboolean(l, 5));

	return 0;
}

LUA lua_SetBlightLoc(lua_State* l)
{
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetBlightLoc((HPLAYER)lua_tointeger(l, 1), (HLOCATION)lua_tointeger(l, 2), &a3, lua_toboolean(l, 4));

	return 0;
}

LUA lua_SetBlightRect(lua_State* l)
{
	SetBlightRect((HPLAYER)lua_tointeger(l, 1), (HRECT)lua_tointeger(l, 2), lua_toboolean(l, 3));

	return 0;
}

LUA lua_SetBlightPoint(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetBlightPoint((HPLAYER)lua_tointeger(l, 1), &a2, &a3, lua_toboolean(l, 4));

	return 0;
}

LUA lua_CreateBlightedGoldmine(lua_State* l)
{
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));
	jReal a4 = to_jReal((float)lua_tonumber(l, 4));

	lua_pushinteger(l, CreateBlightedGoldmine((HPLAYER)lua_tointeger(l, 1), &a2, &a3, &a4));

	return 1;
}

LUA lua_IsPointBlighted(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));

	lua_pushboolean(l, IsPointBlighted(&a1, &a2));

	return 1;
}

LUA lua_SetDoodadAnimation(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));
	jReal a2 = to_jReal((float)lua_tonumber(l, 2));
	jReal a3 = to_jReal((float)lua_tonumber(l, 3));

	SetDoodadAnimation(&a1, &a2, &a3, (jInteger)lua_tointeger(l, 4), lua_toboolean(l, 5), to_jString(lua_tostring(l, 6)), lua_toboolean(l, 7));

	return 0;
}

LUA lua_SetDoodadAnimationRect(lua_State* l)
{
	SetDoodadAnimationRect((HRECT)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3)), lua_toboolean(l, 4));

	return 0;
}

LUA lua_StartMeleeAI(lua_State* l)
{
	StartMeleeAI((HPLAYER)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_StartCampaignAI(lua_State* l)
{
	StartCampaignAI((HPLAYER)lua_tointeger(l, 1), to_jString(lua_tostring(l, 2)));

	return 0;
}

LUA lua_CommandAI(lua_State* l)
{
	CommandAI((HPLAYER)lua_tointeger(l, 1), (jInteger)lua_tointeger(l, 2), (jInteger)lua_tointeger(l, 3));

	return 0;
}

LUA lua_PauseCompAI(lua_State* l)
{
	PauseCompAI((HPLAYER)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

LUA lua_GetAIDifficulty(lua_State* l)
{
	lua_pushinteger(l, GetAIDifficulty((HPLAYER)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_RemoveGuardPosition(lua_State* l)
{
	RemoveGuardPosition((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_RecycleGuardPosition(lua_State* l)
{
	RecycleGuardPosition((HUNIT)lua_tointeger(l, 1));

	return 0;
}

LUA lua_RemoveAllGuardPositions(lua_State* l)
{
	RemoveAllGuardPositions((HPLAYER)lua_tointeger(l, 1));

	return 0;
}

LUA lua_ExecuteFunc(lua_State* l)
{
	ExecuteFunc(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_Cheat(lua_State* l)
{
	Cheat(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_IsNoVictoryCheat(lua_State* l)
{
	lua_pushboolean(l, IsNoVictoryCheat());

	return 1;
}

LUA lua_IsNoDefeatCheat(lua_State* l)
{
	lua_pushboolean(l, IsNoDefeatCheat());

	return 1;
}

LUA lua_Preload(lua_State* l)
{
	Preload(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_PreloadEnd(lua_State* l)
{
	jReal a1 = to_jReal((float)lua_tonumber(l, 1));

	PreloadEnd(&a1);

	return 0;
}

LUA lua_PreloadStart(lua_State* l)
{
	PreloadStart();

	return 0;
}

LUA lua_PreloadRefresh(lua_State* l)
{
	PreloadRefresh();

	return 0;
}

LUA lua_PreloadEndEx(lua_State* l)
{
	PreloadEndEx();

	return 0;
}

LUA lua_PreloadGenStart(lua_State* l)
{
	PreloadGenStart();

	return 0;
}

LUA lua_PreloadGenClear(lua_State* l)
{
	PreloadGenClear();

	return 0;
}

LUA lua_PreloadGenEnd(lua_State* l)
{
	PreloadGenEnd(to_jString(lua_tostring(l, 1)));

	return 0;
}

LUA lua_Preloader(lua_State* l)
{
	Preloader(to_jString(lua_tostring(l, 1)));

	return 0;
}

