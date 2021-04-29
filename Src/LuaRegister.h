#pragma once

#include <Windows.h>

#include "Variables.h"

typedef int LUA;

void lua_opencfunctions(lua_State* l);

//------------------------C Functions

LUA lua_DebugS(lua_State* l);

LUA lua_DebugFI(lua_State* l);

LUA lua_DebugUnitID(lua_State* l);

LUA lua_DisplayText(lua_State* l);

LUA lua_DisplayTextI(lua_State* l);

LUA lua_DisplayTextII(lua_State* l);

LUA lua_DisplayTextIII(lua_State* l);

LUA lua_SuicideUnit(lua_State* l);

LUA lua_SuicideUnitEx(lua_State* l);

LUA lua_Sleep(lua_State* l);

LUA lua_StartThread(lua_State* l);

LUA lua_GetAiPlayer(lua_State* l);

LUA lua_DoAiScriptDebug(lua_State* l);

LUA lua_GetHeroId(lua_State* l);

LUA lua_GetHeroLevelAI(lua_State* l);

LUA lua_SetHeroLevels(lua_State* l);

LUA lua_SetNewHeroes(lua_State* l);

LUA lua_GetUnitCount(lua_State* l);

LUA lua_GetPlayerUnitTypeCount(lua_State* l);

LUA lua_GetTownUnitCount(lua_State* l);

LUA lua_GetUnitCountDone(lua_State* l);

LUA lua_GetUpgradeLevel(lua_State* l);

LUA lua_GetUnitGoldCost(lua_State* l);

LUA lua_GetUnitWoodCost(lua_State* l);

LUA lua_GetUnitBuildTime(lua_State* l);

LUA lua_GetUpgradeGoldCost(lua_State* l);

LUA lua_GetUpgradeWoodCost(lua_State* l);

LUA lua_GetEnemyPower(lua_State* l);

LUA lua_GetMinesOwned(lua_State* l);

LUA lua_GetGoldOwned(lua_State* l);

LUA lua_TownWithMine(lua_State* l);

LUA lua_TownHasMine(lua_State* l);

LUA lua_TownHasHall(lua_State* l);

LUA lua_GetNextExpansion(lua_State* l);

LUA lua_GetExpansionPeon(lua_State* l);

LUA lua_GetEnemyExpansion(lua_State* l);

LUA lua_SetExpansion(lua_State* l);

LUA lua_GetBuilding(lua_State* l);

LUA lua_SetAllianceTarget(lua_State* l);

LUA lua_GetAllianceTarget(lua_State* l);

LUA lua_SetProduce(lua_State* l);

LUA lua_MergeUnits(lua_State* l);

LUA lua_ConvertUnits(lua_State* l);

LUA lua_SetUpgrade(lua_State* l);

LUA lua_Unsummon(lua_State* l);

LUA lua_ClearHarvestAI(lua_State* l);

LUA lua_HarvestGold(lua_State* l);

LUA lua_HarvestWood(lua_State* l);

LUA lua_StopGathering(lua_State* l);

LUA lua_AddGuardPost(lua_State* l);

LUA lua_FillGuardPosts(lua_State* l);

LUA lua_ReturnGuardPosts(lua_State* l);

LUA lua_CreateCaptains(lua_State* l);

LUA lua_SetCaptainHome(lua_State* l);

LUA lua_ResetCaptainLocs(lua_State* l);

LUA lua_ShiftTownSpot(lua_State* l);

LUA lua_SetCaptainChanges(lua_State* l);

LUA lua_TeleportCaptain(lua_State* l);

LUA lua_ClearCaptainTargets(lua_State* l);

LUA lua_CaptainVsUnits(lua_State* l);

LUA lua_CaptainVsPlayer(lua_State* l);

LUA lua_CaptainAttack(lua_State* l);

LUA lua_GroupTimedLife(lua_State* l);

LUA lua_CaptainGoHome(lua_State* l);

LUA lua_CaptainIsHome(lua_State* l);

LUA lua_CaptainRetreating(lua_State* l);

LUA lua_CaptainIsFull(lua_State* l);

LUA lua_CaptainIsEmpty(lua_State* l);

LUA lua_CaptainGroupSize(lua_State* l);

LUA lua_CaptainReadiness(lua_State* l);

LUA lua_CaptainReadinessHP(lua_State* l);

LUA lua_CaptainReadinessMa(lua_State* l);

LUA lua_CaptainInCombat(lua_State* l);

LUA lua_TownThreatened(lua_State* l);

LUA lua_CaptainAtGoal(lua_State* l);

LUA lua_CreepsOnMap(lua_State* l);

LUA lua_RemoveInjuries(lua_State* l);

LUA lua_RemoveSiege(lua_State* l);

LUA lua_IsTowered(lua_State* l);

LUA lua_DisablePathing(lua_State* l);

LUA lua_SetAmphibious(lua_State* l);

LUA lua_InitAssault(lua_State* l);

LUA lua_AddAssault(lua_State* l);

LUA lua_AddDefenders(lua_State* l);

LUA lua_GetCreepCamp(lua_State* l);

LUA lua_StartGetEnemyBase(lua_State* l);

LUA lua_WaitGetEnemyBase(lua_State* l);

LUA lua_GetMegaTarget(lua_State* l);

LUA lua_GetEnemyBase(lua_State* l);

LUA lua_GetExpansionFoe(lua_State* l);

LUA lua_GetExpansionX(lua_State* l);

LUA lua_GetExpansionY(lua_State* l);

LUA lua_SetStagePoint(lua_State* l);

LUA lua_AttackMoveKill(lua_State* l);

LUA lua_AttackMoveXY(lua_State* l);

LUA lua_LoadZepWave(lua_State* l);

LUA lua_SuicidePlayer(lua_State* l);

LUA lua_SuicidePlayerUnits(lua_State* l);

LUA lua_UnitAlive(lua_State* l);

LUA lua_UnitInvis(lua_State* l);

LUA lua_IgnoredUnits(lua_State* l);

LUA lua_CommandsWaiting(lua_State* l);

LUA lua_GetLastCommand(lua_State* l);

LUA lua_GetLastData(lua_State* l);

LUA lua_PopLastCommand(lua_State* l);

LUA lua_SetCampaignAI(lua_State* l);

LUA lua_SetMeleeAI(lua_State* l);

LUA lua_SetTargetHeroes(lua_State* l);

LUA lua_SetHeroesFlee(lua_State* l);

LUA lua_SetHeroesBuyItems(lua_State* l);

LUA lua_SetIgnoreInjured(lua_State* l);

LUA lua_SetPeonsRepair(lua_State* l);

LUA lua_SetRandomPaths(lua_State* l);

LUA lua_SetDefendPlayer(lua_State* l);

LUA lua_SetHeroesTakeItems(lua_State* l);

LUA lua_SetUnitsFlee(lua_State* l);

LUA lua_SetGroupsFlee(lua_State* l);

LUA lua_SetSlowChopping(lua_State* l);

LUA lua_SetSmartArtillery(lua_State* l);

LUA lua_SetWatchMegaTargets(lua_State* l);

LUA lua_SetReplacementCount(lua_State* l);

LUA lua_PurchaseZeppelin(lua_State* l);

LUA lua_MeleeDifficulty(lua_State* l);

LUA lua_DebugBreak(lua_State* l);

LUA lua_Deg2Rad(lua_State* l);

LUA lua_Rad2Deg(lua_State* l);

LUA lua_Sin(lua_State* l);

LUA lua_Cos(lua_State* l);

LUA lua_Tan(lua_State* l);

LUA lua_Asin(lua_State* l);

LUA lua_Acos(lua_State* l);

LUA lua_Atan(lua_State* l);

LUA lua_Atan2(lua_State* l);

LUA lua_SquareRoot(lua_State* l);

LUA lua_Pow(lua_State* l);

LUA lua_I2R(lua_State* l);

LUA lua_R2I(lua_State* l);

LUA lua_I2S(lua_State* l);

LUA lua_R2S(lua_State* l);

LUA lua_R2SW(lua_State* l);

LUA lua_S2I(lua_State* l);

LUA lua_S2R(lua_State* l);

LUA lua_GetHandleId(lua_State* l);

LUA lua_SubString(lua_State* l);

LUA lua_StringLength(lua_State* l);

LUA lua_StringCase(lua_State* l);

LUA lua_StringHash(lua_State* l);

LUA lua_GetLocalizedString(lua_State* l);

LUA lua_GetLocalizedHotkey(lua_State* l);

LUA lua_ConvertRace(lua_State* l);

LUA lua_ConvertAllianceType(lua_State* l);

LUA lua_ConvertRacePref(lua_State* l);

LUA lua_ConvertIGameState(lua_State* l);

LUA lua_ConvertFGameState(lua_State* l);

LUA lua_ConvertPlayerState(lua_State* l);

LUA lua_ConvertPlayerScore(lua_State* l);

LUA lua_ConvertStartLocPrio(lua_State* l);

LUA lua_ConvertPlayerGameResult(lua_State* l);

LUA lua_ConvertUnitState(lua_State* l);

LUA lua_ConvertAIDifficulty(lua_State* l);

LUA lua_ConvertGameEvent(lua_State* l);

LUA lua_ConvertPlayerEvent(lua_State* l);

LUA lua_ConvertPlayerUnitEvent(lua_State* l);

LUA lua_ConvertUnitEvent(lua_State* l);

LUA lua_ConvertWidgetEvent(lua_State* l);

LUA lua_ConvertDialogEvent(lua_State* l);

LUA lua_ConvertLimitOp(lua_State* l);

LUA lua_ConvertUnitType(lua_State* l);

LUA lua_ConvertGameSpeed(lua_State* l);

LUA lua_ConvertPlacement(lua_State* l);

LUA lua_ConvertGameDifficulty(lua_State* l);

LUA lua_ConvertGameType(lua_State* l);

LUA lua_ConvertMapFlag(lua_State* l);

LUA lua_ConvertMapVisibility(lua_State* l);

LUA lua_ConvertMapSetting(lua_State* l);

LUA lua_ConvertMapDensity(lua_State* l);

LUA lua_ConvertMapControl(lua_State* l);

LUA lua_ConvertPlayerColor(lua_State* l);

LUA lua_ConvertPlayerSlotState(lua_State* l);

LUA lua_ConvertVolumeGroup(lua_State* l);

LUA lua_ConvertCameraField(lua_State* l);

LUA lua_ConvertBlendMode(lua_State* l);

LUA lua_ConvertRarityControl(lua_State* l);

LUA lua_ConvertTexMapFlags(lua_State* l);

LUA lua_ConvertFogState(lua_State* l);

LUA lua_ConvertEffectType(lua_State* l);

LUA lua_ConvertVersion(lua_State* l);

LUA lua_ConvertItemType(lua_State* l);

LUA lua_ConvertAttackType(lua_State* l);

LUA lua_ConvertDamageType(lua_State* l);

LUA lua_ConvertWeaponType(lua_State* l);

LUA lua_ConvertSoundType(lua_State* l);

LUA lua_ConvertPathingType(lua_State* l);

LUA lua_SetMapName(lua_State* l);

LUA lua_SetMapDescription(lua_State* l);

LUA lua_SetTeams(lua_State* l);

LUA lua_SetPlayers(lua_State* l);

LUA lua_SetGameTypeSupported(lua_State* l);

LUA lua_SetMapFlag(lua_State* l);

LUA lua_SetGameSpeed(lua_State* l);

LUA lua_SetGamePlacement(lua_State* l);

LUA lua_SetGameDifficulty(lua_State* l);

LUA lua_SetResourceDensity(lua_State* l);

LUA lua_SetCreatureDensity(lua_State* l);

LUA lua_DefineStartLocation(lua_State* l);

LUA lua_DefineStartLocationLoc(lua_State* l);

LUA lua_SetStartLocPrioCount(lua_State* l);

LUA lua_SetStartLocPrio(lua_State* l);

LUA lua_GetStartLocPrioSlot(lua_State* l);

LUA lua_GetStartLocPrio(lua_State* l);

LUA lua_GetTeams(lua_State* l);

LUA lua_GetPlayers(lua_State* l);

LUA lua_IsGameTypeSupported(lua_State* l);

LUA lua_IsMapFlagSet(lua_State* l);

LUA lua_GetGameTypeSelected(lua_State* l);

LUA lua_GetGamePlacement(lua_State* l);

LUA lua_GetGameSpeed(lua_State* l);

LUA lua_GetGameDifficulty(lua_State* l);

LUA lua_GetResourceDensity(lua_State* l);

LUA lua_GetCreatureDensity(lua_State* l);

LUA lua_GetStartLocationX(lua_State* l);

LUA lua_GetStartLocationY(lua_State* l);

LUA lua_GetStartLocationLoc(lua_State* l);

LUA lua_SetPlayerTeam(lua_State* l);

LUA lua_SetPlayerStartLocation(lua_State* l);

LUA lua_ForcePlayerStartLocation(lua_State* l);

LUA lua_SetPlayerAlliance(lua_State* l);

LUA lua_SetPlayerTaxRate(lua_State* l);

LUA lua_SetPlayerRacePreference(lua_State* l);

LUA lua_SetPlayerRaceSelectable(lua_State* l);

LUA lua_SetPlayerController(lua_State* l);

LUA lua_SetPlayerColor(lua_State* l);

LUA lua_SetPlayerOnScoreScreen(lua_State* l);

LUA lua_SetPlayerName(lua_State* l);

LUA lua_GetPlayerTeam(lua_State* l);

LUA lua_GetPlayerName(lua_State* l);

LUA lua_GetPlayerStartLocation(lua_State* l);

LUA lua_GetPlayerStartLocationX(lua_State* l);

LUA lua_GetPlayerStartLocationY(lua_State* l);

LUA lua_GetPlayerColor(lua_State* l);

LUA lua_GetPlayerSelectable(lua_State* l);

LUA lua_GetPlayerController(lua_State* l);

LUA lua_GetPlayerSlotState(lua_State* l);

LUA lua_GetPlayerTaxRate(lua_State* l);

LUA lua_IsPlayerRacePrefSet(lua_State* l);

LUA lua_Location(lua_State* l);

LUA lua_RemoveLocation(lua_State* l);

LUA lua_MoveLocation(lua_State* l);

LUA lua_GetLocationX(lua_State* l);

LUA lua_GetLocationY(lua_State* l);

LUA lua_GetLocationZ(lua_State* l);

LUA lua_CreateTimer(lua_State* l);

LUA lua_DestroyTimer(lua_State* l);

LUA lua_TimerStart(lua_State* l);

LUA lua_TimerGetTimeout(lua_State* l);

LUA lua_TimerGetElapsed(lua_State* l);

LUA lua_TimerGetRemaining(lua_State* l);

LUA lua_PauseTimer(lua_State* l);

LUA lua_ResumeTimer(lua_State* l);

LUA lua_GetExpiredTimer(lua_State* l);

LUA lua_Condition(lua_State* l);

LUA lua_DestroyCondition(lua_State* l);

LUA lua_Filter(lua_State* l);

LUA lua_DestroyFilter(lua_State* l);

LUA lua_DestroyBoolExpr(lua_State* l);

LUA lua_And(lua_State* l);

LUA lua_Or(lua_State* l);

LUA lua_Not(lua_State* l);

LUA lua_CreateRegion(lua_State* l);

LUA lua_RemoveRegion(lua_State* l);

LUA lua_RegionAddRect(lua_State* l);

LUA lua_RegionClearRect(lua_State* l);

LUA lua_RegionAddCell(lua_State* l);

LUA lua_RegionAddCellAtLoc(lua_State* l);

LUA lua_RegionClearCell(lua_State* l);

LUA lua_RegionClearCellAtLoc(lua_State* l);

LUA lua_IsUnitInRegion(lua_State* l);

LUA lua_IsPointInRegion(lua_State* l);

LUA lua_IsLocationInRegion(lua_State* l);

LUA lua_Rect(lua_State* l);

LUA lua_RectFromLoc(lua_State* l);

LUA lua_RemoveRect(lua_State* l);

LUA lua_SetRect(lua_State* l);

LUA lua_SetRectFromLoc(lua_State* l);

LUA lua_GetRectCenterX(lua_State* l);

LUA lua_GetRectCenterY(lua_State* l);

LUA lua_MoveRectTo(lua_State* l);

LUA lua_MoveRectToLoc(lua_State* l);

LUA lua_GetRectMinX(lua_State* l);

LUA lua_GetRectMinY(lua_State* l);

LUA lua_GetRectMaxX(lua_State* l);

LUA lua_GetRectMaxY(lua_State* l);

LUA lua_GetWorldBounds(lua_State* l);

LUA lua_SetFogStateRect(lua_State* l);

LUA lua_SetFogStateRadius(lua_State* l);

LUA lua_SetFogStateRadiusLoc(lua_State* l);

LUA lua_FogMaskEnable(lua_State* l);

LUA lua_IsFogMaskEnabled(lua_State* l);

LUA lua_FogEnable(lua_State* l);

LUA lua_IsFogEnabled(lua_State* l);

LUA lua_CreateFogModifierRect(lua_State* l);

LUA lua_CreateFogModifierRadius(lua_State* l);

LUA lua_CreateFogModifierRadiusLoc(lua_State* l);

LUA lua_DestroyFogModifier(lua_State* l);

LUA lua_FogModifierStart(lua_State* l);

LUA lua_FogModifierStop(lua_State* l);

LUA lua_CreateTrigger(lua_State* l);

LUA lua_DestroyTrigger(lua_State* l);

LUA lua_ResetTrigger(lua_State* l);

LUA lua_EnableTrigger(lua_State* l);

LUA lua_DisableTrigger(lua_State* l);

LUA lua_IsTriggerEnabled(lua_State* l);

LUA lua_TriggerWaitOnSleeps(lua_State* l);

LUA lua_IsTriggerWaitOnSleeps(lua_State* l);

LUA lua_TriggerRegisterVariableEvent(lua_State* l);

LUA lua_TriggerRegisterTimerEvent(lua_State* l);

LUA lua_TriggerRegisterTimerExpireEvent(lua_State* l);

LUA lua_TriggerRegisterGameStateEvent(lua_State* l);

LUA lua_GetEventGameState(lua_State* l);

LUA lua_TriggerRegisterDialogEvent(lua_State* l);

LUA lua_TriggerRegisterDialogButtonEvent(lua_State* l);

LUA lua_GetClickedButton(lua_State* l);

LUA lua_GetClickedDialog(lua_State* l);

LUA lua_GetTournamentFinishSoonTimeRemaining(lua_State* l);

LUA lua_GetTournamentFinishNowRule(lua_State* l);

LUA lua_GetTournamentFinishNowPlayer(lua_State* l);

LUA lua_GetTournamentScore(lua_State* l);

LUA lua_GetSaveBasicFilename(lua_State* l);

LUA lua_TriggerRegisterGameEvent(lua_State* l);

LUA lua_GetWinningPlayer(lua_State* l);

LUA lua_TriggerRegisterPlayerStateEvent(lua_State* l);

LUA lua_GetEventPlayerState(lua_State* l);

LUA lua_TriggerRegisterPlayerEvent(lua_State* l);

LUA lua_TriggerRegisterPlayerUnitEvent(lua_State* l);

LUA lua_GetAttacker(lua_State* l);

LUA lua_GetRescuer(lua_State* l);

LUA lua_GetDyingUnit(lua_State* l);

LUA lua_GetKillingUnit(lua_State* l);

LUA lua_GetDecayingUnit(lua_State* l);

LUA lua_GetConstructingStructure(lua_State* l);

LUA lua_GetCancelledStructure(lua_State* l);

LUA lua_GetConstructedStructure(lua_State* l);

LUA lua_GetTrainedUnitType(lua_State* l);

LUA lua_GetResearchingUnit(lua_State* l);

LUA lua_GetResearched(lua_State* l);

LUA lua_GetTrainedUnit(lua_State* l);

LUA lua_GetSellingUnit(lua_State* l);

LUA lua_GetSoldUnit(lua_State* l);

LUA lua_GetBuyingUnit(lua_State* l);

LUA lua_GetSoldItem(lua_State* l);

LUA lua_GetChangingUnit(lua_State* l);

LUA lua_GetChangingUnitPrevOwner(lua_State* l);

LUA lua_GetDetectedUnit(lua_State* l);

LUA lua_GetOrderedUnit(lua_State* l);

LUA lua_OrderId(lua_State* l);

LUA lua_OrderId2String(lua_State* l);

LUA lua_AbilityId(lua_State* l);

LUA lua_AbilityId2String(lua_State* l);

LUA lua_UnitId(lua_State* l);

LUA lua_UnitId2String(lua_State* l);

LUA lua_GetObjectName(lua_State* l);

LUA lua_GetIssuedOrderId(lua_State* l);

LUA lua_GetOrderPointX(lua_State* l);

LUA lua_GetOrderPointY(lua_State* l);

LUA lua_GetOrderPointLoc(lua_State* l);

LUA lua_GetOrderTarget(lua_State* l);

LUA lua_GetOrderTargetDestructable(lua_State* l);

LUA lua_GetOrderTargetItem(lua_State* l);

LUA lua_GetOrderTargetUnit(lua_State* l);

LUA lua_GetSpellAbilityUnit(lua_State* l);

LUA lua_GetSpellAbilityId(lua_State* l);

LUA lua_GetSpellAbility(lua_State* l);

LUA lua_GetSpellTargetLoc(lua_State* l);

LUA lua_GetSpellTargetX(lua_State* l);

LUA lua_GetSpellTargetY(lua_State* l);

LUA lua_GetSpellTargetDestructable(lua_State* l);

LUA lua_GetSpellTargetItem(lua_State* l);

LUA lua_GetSpellTargetUnit(lua_State* l);

LUA lua_GetLevelingUnit(lua_State* l);

LUA lua_GetLearningUnit(lua_State* l);

LUA lua_GetLearnedSkill(lua_State* l);

LUA lua_GetLearnedSkillLevel(lua_State* l);

LUA lua_GetRevivableUnit(lua_State* l);

LUA lua_GetRevivingUnit(lua_State* l);

LUA lua_GetSummoningUnit(lua_State* l);

LUA lua_GetSummonedUnit(lua_State* l);

LUA lua_GetTransportUnit(lua_State* l);

LUA lua_GetLoadedUnit(lua_State* l);

LUA lua_GetManipulatingUnit(lua_State* l);

LUA lua_GetManipulatedItem(lua_State* l);

LUA lua_TriggerRegisterPlayerAllianceChange(lua_State* l);

LUA lua_TriggerRegisterPlayerChatEvent(lua_State* l);

LUA lua_GetEventPlayerChatString(lua_State* l);

LUA lua_GetEventPlayerChatStringMatched(lua_State* l);

LUA lua_TriggerRegisterUnitStateEvent(lua_State* l);

LUA lua_GetEventUnitState(lua_State* l);

LUA lua_TriggerRegisterDeathEvent(lua_State* l);

LUA lua_TriggerRegisterUnitEvent(lua_State* l);

LUA lua_GetEventDamage(lua_State* l);

LUA lua_GetEventDamageSource(lua_State* l);

LUA lua_GetEventDetectingPlayer(lua_State* l);

LUA lua_GetEventTargetUnit(lua_State* l);

LUA lua_TriggerRegisterFilterUnitEvent(lua_State* l);

LUA lua_TriggerRegisterUnitInRange(lua_State* l);

LUA lua_TriggerRegisterEnterRegion(lua_State* l);

LUA lua_TriggerRegisterLeaveRegion(lua_State* l);

LUA lua_GetTriggeringRegion(lua_State* l);

LUA lua_GetEnteringUnit(lua_State* l);

LUA lua_GetLeavingUnit(lua_State* l);

LUA lua_TriggerAddCondition(lua_State* l);

LUA lua_TriggerRemoveCondition(lua_State* l);

LUA lua_TriggerClearConditions(lua_State* l);

LUA lua_TriggerAddAction(lua_State* l);

LUA lua_TriggerRemoveAction(lua_State* l);

LUA lua_TriggerClearActions(lua_State* l);

LUA lua_TriggerSleepAction(lua_State* l);

LUA lua_TriggerWaitForSound(lua_State* l);

LUA lua_TriggerExecute(lua_State* l);

LUA lua_TriggerExecuteWait(lua_State* l);

LUA lua_TriggerEvaluate(lua_State* l);

LUA lua_TriggerSyncStart(lua_State* l);

LUA lua_TriggerSyncReady(lua_State* l);

LUA lua_GetTriggerWidget(lua_State* l);

LUA lua_GetTriggerDestructable(lua_State* l);

LUA lua_GetTriggerUnit(lua_State* l);

LUA lua_GetTriggerPlayer(lua_State* l);

LUA lua_GetTriggeringTrigger(lua_State* l);

LUA lua_GetTriggerEventId(lua_State* l);

LUA lua_GetTriggerEvalCount(lua_State* l);

LUA lua_GetTriggerExecCount(lua_State* l);

LUA lua_GetFilterUnit(lua_State* l);

LUA lua_GetEnumUnit(lua_State* l);

LUA lua_GetEnumPlayer(lua_State* l);

LUA lua_GetFilterPlayer(lua_State* l);

LUA lua_GetFilterDestructable(lua_State* l);

LUA lua_GetEnumDestructable(lua_State* l);

LUA lua_GetFilterItem(lua_State* l);

LUA lua_GetEnumItem(lua_State* l);

LUA lua_CreateGroup(lua_State* l);

LUA lua_DestroyGroup(lua_State* l);

LUA lua_GroupAddUnit(lua_State* l);

LUA lua_GroupRemoveUnit(lua_State* l);

LUA lua_GroupClear(lua_State* l);

LUA lua_GroupEnumUnitsOfType(lua_State* l);

LUA lua_GroupEnumUnitsOfTypeCounted(lua_State* l);

LUA lua_GroupEnumUnitsInRect(lua_State* l);

LUA lua_GroupEnumUnitsInRectCounted(lua_State* l);

LUA lua_GroupEnumUnitsOfPlayer(lua_State* l);

LUA lua_GroupEnumUnitsInRange(lua_State* l);

LUA lua_GroupEnumUnitsInRangeOfLoc(lua_State* l);

LUA lua_GroupEnumUnitsInRangeCounted(lua_State* l);

LUA lua_GroupEnumUnitsInRangeOfLocCounted(lua_State* l);

LUA lua_GroupEnumUnitsSelected(lua_State* l);

LUA lua_GroupImmediateOrder(lua_State* l);

LUA lua_GroupImmediateOrderById(lua_State* l);

LUA lua_GroupPointOrder(lua_State* l);

LUA lua_GroupPointOrderLoc(lua_State* l);

LUA lua_GroupPointOrderById(lua_State* l);

LUA lua_GroupPointOrderByIdLoc(lua_State* l);

LUA lua_GroupTargetOrder(lua_State* l);

LUA lua_GroupTargetOrderById(lua_State* l);

LUA lua_ForGroup(lua_State* l);

LUA lua_FirstOfGroup(lua_State* l);

LUA lua_CreateForce(lua_State* l);

LUA lua_DestroyForce(lua_State* l);

LUA lua_ForceAddPlayer(lua_State* l);

LUA lua_ForceRemovePlayer(lua_State* l);

LUA lua_ForceClear(lua_State* l);

LUA lua_ForceEnumPlayers(lua_State* l);

LUA lua_ForceEnumPlayersCounted(lua_State* l);

LUA lua_ForceEnumAllies(lua_State* l);

LUA lua_ForceEnumEnemies(lua_State* l);

LUA lua_ForForce(lua_State* l);

LUA lua_GetWidgetLife(lua_State* l);

LUA lua_SetWidgetLife(lua_State* l);

LUA lua_GetWidgetX(lua_State* l);

LUA lua_GetWidgetY(lua_State* l);

LUA lua_CreateDestructable(lua_State* l);

LUA lua_CreateDestructableZ(lua_State* l);

LUA lua_CreateDeadDestructable(lua_State* l);

LUA lua_CreateDeadDestructableZ(lua_State* l);

LUA lua_RemoveDestructable(lua_State* l);

LUA lua_KillDestructable(lua_State* l);

LUA lua_SetDestructableInvulnerable(lua_State* l);

LUA lua_IsDestructableInvulnerable(lua_State* l);

LUA lua_EnumDestructablesInRect(lua_State* l);

LUA lua_GetDestructableTypeId(lua_State* l);

LUA lua_GetDestructableX(lua_State* l);

LUA lua_GetDestructableY(lua_State* l);

LUA lua_SetDestructableLife(lua_State* l);

LUA lua_GetDestructableLife(lua_State* l);

LUA lua_SetDestructableMaxLife(lua_State* l);

LUA lua_GetDestructableMaxLife(lua_State* l);

LUA lua_DestructableRestoreLife(lua_State* l);

LUA lua_QueueDestructableAnimation(lua_State* l);

LUA lua_SetDestructableAnimation(lua_State* l);

LUA lua_SetDestructableAnimationSpeed(lua_State* l);

LUA lua_ShowDestructable(lua_State* l);

LUA lua_GetDestructableOccluderHeight(lua_State* l);

LUA lua_SetDestructableOccluderHeight(lua_State* l);

LUA lua_GetDestructableName(lua_State* l);

LUA lua_CreateUnit(lua_State* l);

LUA lua_CreateUnitByName(lua_State* l);

LUA lua_CreateUnitAtLoc(lua_State* l);

LUA lua_CreateUnitAtLocByName(lua_State* l);

LUA lua_CreateCorpse(lua_State* l);

LUA lua_GetUnitState(lua_State* l);

LUA lua_GetUnitFoodUsed(lua_State* l);

LUA lua_GetUnitFoodMade(lua_State* l);

LUA lua_GetFoodMade(lua_State* l);

LUA lua_GetFoodUsed(lua_State* l);

LUA lua_SetUnitUseFood(lua_State* l);

LUA lua_GetUnitX(lua_State* l);

LUA lua_GetUnitY(lua_State* l);

LUA lua_GetUnitLoc(lua_State* l);

LUA lua_GetUnitRallyPoint(lua_State* l);

LUA lua_GetUnitRallyUnit(lua_State* l);

LUA lua_GetUnitRallyDestructable(lua_State* l);

LUA lua_GetUnitFacing(lua_State* l);

LUA lua_GetUnitMoveSpeed(lua_State* l);

LUA lua_GetUnitDefaultMoveSpeed(lua_State* l);

LUA lua_GetUnitTypeId(lua_State* l);

LUA lua_GetUnitRace(lua_State* l);

LUA lua_GetUnitName(lua_State* l);

LUA lua_GetUnitPointValue(lua_State* l);

LUA lua_GetUnitPointValueByType(lua_State* l);

LUA lua_SetUnitX(lua_State* l);

LUA lua_SetUnitY(lua_State* l);

LUA lua_SetUnitPosition(lua_State* l);

LUA lua_SetUnitPositionLoc(lua_State* l);

LUA lua_SetUnitFacing(lua_State* l);

LUA lua_SetUnitFacingTimed(lua_State* l);

LUA lua_SetUnitFlyHeight(lua_State* l);

LUA lua_SetUnitMoveSpeed(lua_State* l);

LUA lua_SetUnitTurnSpeed(lua_State* l);

LUA lua_SetUnitPropWindow(lua_State* l);

LUA lua_SetUnitCreepGuard(lua_State* l);

LUA lua_GetUnitAcquireRange(lua_State* l);

LUA lua_GetUnitTurnSpeed(lua_State* l);

LUA lua_GetUnitPropWindow(lua_State* l);

LUA lua_GetUnitFlyHeight(lua_State* l);

LUA lua_GetUnitDefaultAcquireRange(lua_State* l);

LUA lua_GetUnitDefaultTurnSpeed(lua_State* l);

LUA lua_GetUnitDefaultPropWindow(lua_State* l);

LUA lua_GetUnitDefaultFlyHeight(lua_State* l);

LUA lua_SetUnitAcquireRange(lua_State* l);

LUA lua_SetUnitState(lua_State* l);

LUA lua_SetUnitOwner(lua_State* l);

LUA lua_SetUnitRescuable(lua_State* l);

LUA lua_SetUnitRescueRange(lua_State* l);

LUA lua_SetUnitColor(lua_State* l);

LUA lua_QueueUnitAnimation(lua_State* l);

LUA lua_SetUnitAnimation(lua_State* l);

LUA lua_SetUnitAnimationWithRarity(lua_State* l);

LUA lua_SetUnitAnimationByIndex(lua_State* l);

LUA lua_AddUnitAnimationProperties(lua_State* l);

LUA lua_SetUnitScale(lua_State* l);

LUA lua_SetUnitTimeScale(lua_State* l);

LUA lua_SetUnitBlendTime(lua_State* l);

LUA lua_SetUnitVertexColor(lua_State* l);

LUA lua_SetUnitLookAt(lua_State* l);

LUA lua_SetUnitPathing(lua_State* l);

LUA lua_ResetUnitLookAt(lua_State* l);

LUA lua_SetHeroStr(lua_State* l);

LUA lua_SetHeroAgi(lua_State* l);

LUA lua_SetHeroInt(lua_State* l);

LUA lua_GetHeroStr(lua_State* l);

LUA lua_GetHeroAgi(lua_State* l);

LUA lua_GetHeroInt(lua_State* l);

LUA lua_GetHeroSkillPoints(lua_State* l);

LUA lua_UnitStripHeroLevel(lua_State* l);

LUA lua_UnitModifySkillPoints(lua_State* l);

LUA lua_GetHeroXP(lua_State* l);

LUA lua_SetHeroXP(lua_State* l);

LUA lua_AddHeroXP(lua_State* l);

LUA lua_SetHeroLevel(lua_State* l);

LUA lua_GetHeroLevel(lua_State* l);

LUA lua_GetUnitLevel(lua_State* l);

LUA lua_GetHeroProperName(lua_State* l);

LUA lua_SuspendHeroXP(lua_State* l);

LUA lua_IsSuspendedXP(lua_State* l);

LUA lua_SelectHeroSkill(lua_State* l);

LUA lua_GetUnitAbilityLevel(lua_State* l);

LUA lua_ReviveHero(lua_State* l);

LUA lua_ReviveHeroLoc(lua_State* l);

LUA lua_SetUnitExploded(lua_State* l);

LUA lua_SetUnitInvulnerable(lua_State* l);

LUA lua_PauseUnit(lua_State* l);

LUA lua_IsUnitPaused(lua_State* l);

LUA lua_UnitAddItem(lua_State* l);

LUA lua_UnitAddItemById(lua_State* l);

LUA lua_UnitAddItemToSlotById(lua_State* l);

LUA lua_UnitRemoveItem(lua_State* l);

LUA lua_UnitRemoveItemFromSlot(lua_State* l);

LUA lua_UnitHasItem(lua_State* l);

LUA lua_UnitItemInSlot(lua_State* l);

LUA lua_UnitInventorySize(lua_State* l);

LUA lua_UnitDropItemPoint(lua_State* l);

LUA lua_UnitDropItemSlot(lua_State* l);

LUA lua_UnitDropItemTarget(lua_State* l);

LUA lua_UnitUseItem(lua_State* l);

LUA lua_UnitUseItemPoint(lua_State* l);

LUA lua_UnitUseItemTarget(lua_State* l);

LUA lua_GetUnitCurrentOrder(lua_State* l);

LUA lua_SetResourceAmount(lua_State* l);

LUA lua_AddResourceAmount(lua_State* l);

LUA lua_GetResourceAmount(lua_State* l);

LUA lua_SelectUnit(lua_State* l);

LUA lua_ClearSelection(lua_State* l);

LUA lua_UnitAddIndicator(lua_State* l);

LUA lua_AddIndicator(lua_State* l);

LUA lua_KillUnit(lua_State* l);

LUA lua_RemoveUnit(lua_State* l);

LUA lua_ShowUnit(lua_State* l);

LUA lua_IsUnitInForce(lua_State* l);

LUA lua_IsUnitInGroup(lua_State* l);

LUA lua_IsUnitOwnedByPlayer(lua_State* l);

LUA lua_IsUnitAlly(lua_State* l);

LUA lua_IsUnitEnemy(lua_State* l);

LUA lua_IsUnitVisible(lua_State* l);

LUA lua_IsUnitDetected(lua_State* l);

LUA lua_IsUnitInvisible(lua_State* l);

LUA lua_IsUnitFogged(lua_State* l);

LUA lua_IsUnitMasked(lua_State* l);

LUA lua_IsUnitSelected(lua_State* l);

LUA lua_IsUnitRace(lua_State* l);

LUA lua_IsUnitType(lua_State* l);

LUA lua_IsUnit(lua_State* l);

LUA lua_IsUnitInRange(lua_State* l);

LUA lua_IsUnitInRangeXY(lua_State* l);

LUA lua_IsUnitInRangeLoc(lua_State* l);

LUA lua_IsUnitHidden(lua_State* l);

LUA lua_IsUnitIllusion(lua_State* l);

LUA lua_IsUnitInTransport(lua_State* l);

LUA lua_IsUnitLoaded(lua_State* l);

LUA lua_IsHeroUnitId(lua_State* l);

LUA lua_IsUnitIdType(lua_State* l);

LUA lua_GetOwningPlayer(lua_State* l);

LUA lua_UnitShareVision(lua_State* l);

LUA lua_UnitSuspendDecay(lua_State* l);

LUA lua_UnitAddType(lua_State* l);

LUA lua_UnitRemoveType(lua_State* l);

LUA lua_UnitAddAbility(lua_State* l);

LUA lua_UnitRemoveAbility(lua_State* l);

LUA lua_UnitMakeAbilityPermanent(lua_State* l);

LUA lua_UnitHasBuffsEx(lua_State* l);

LUA lua_UnitCountBuffsEx(lua_State* l);

LUA lua_UnitRemoveBuffs(lua_State* l);

LUA lua_UnitRemoveBuffsEx(lua_State* l);

LUA lua_UnitAddSleep(lua_State* l);

LUA lua_UnitCanSleep(lua_State* l);

LUA lua_UnitAddSleepPerm(lua_State* l);

LUA lua_UnitCanSleepPerm(lua_State* l);

LUA lua_UnitIsSleeping(lua_State* l);

LUA lua_UnitWakeUp(lua_State* l);

LUA lua_UnitApplyTimedLife(lua_State* l);

LUA lua_UnitIgnoreAlarm(lua_State* l);

LUA lua_UnitIgnoreAlarmToggled(lua_State* l);

LUA lua_UnitDamagePoint(lua_State* l);

LUA lua_UnitDamageTarget(lua_State* l);

LUA lua_DecUnitAbilityLevel(lua_State* l);

LUA lua_IncUnitAbilityLevel(lua_State* l);

LUA lua_SetUnitAbilityLevel(lua_State* l);

LUA lua_UnitResetCooldown(lua_State* l);

LUA lua_UnitSetConstructionProgress(lua_State* l);

LUA lua_UnitSetUpgradeProgress(lua_State* l);

LUA lua_UnitPauseTimedLife(lua_State* l);

LUA lua_UnitSetUsesAltIcon(lua_State* l);

LUA lua_IssueImmediateOrderById(lua_State* l);

LUA lua_IssuePointOrderById(lua_State* l);

LUA lua_IssuePointOrderByIdLoc(lua_State* l);

LUA lua_IssueTargetOrderById(lua_State* l);

LUA lua_IssueInstantPointOrderById(lua_State* l);

LUA lua_IssueInstantTargetOrderById(lua_State* l);

LUA lua_IssueBuildOrderById(lua_State* l);

LUA lua_IssueNeutralImmediateOrderById(lua_State* l);

LUA lua_IssueNeutralPointOrderById(lua_State* l);

LUA lua_IssueNeutralTargetOrderById(lua_State* l);

LUA lua_IssueImmediateOrder(lua_State* l);

LUA lua_IssuePointOrder(lua_State* l);

LUA lua_IssuePointOrderLoc(lua_State* l);

LUA lua_IssueTargetOrder(lua_State* l);

LUA lua_IssueInstantPointOrder(lua_State* l);

LUA lua_IssueInstantTargetOrder(lua_State* l);

LUA lua_IssueBuildOrder(lua_State* l);

LUA lua_IssueNeutralImmediateOrder(lua_State* l);

LUA lua_IssueNeutralPointOrder(lua_State* l);

LUA lua_IssueNeutralTargetOrder(lua_State* l);

LUA lua_WaygateGetDestinationX(lua_State* l);

LUA lua_WaygateGetDestinationY(lua_State* l);

LUA lua_WaygateSetDestination(lua_State* l);

LUA lua_WaygateActivate(lua_State* l);

LUA lua_WaygateIsActive(lua_State* l);

LUA lua_AddItemToAllStock(lua_State* l);

LUA lua_AddItemToStock(lua_State* l);

LUA lua_AddUnitToAllStock(lua_State* l);

LUA lua_AddUnitToStock(lua_State* l);

LUA lua_RemoveItemFromAllStock(lua_State* l);

LUA lua_RemoveItemFromStock(lua_State* l);

LUA lua_RemoveUnitFromAllStock(lua_State* l);

LUA lua_RemoveUnitFromStock(lua_State* l);

LUA lua_SetAllItemTypeSlots(lua_State* l);

LUA lua_SetAllUnitTypeSlots(lua_State* l);

LUA lua_SetItemTypeSlots(lua_State* l);

LUA lua_SetUnitTypeSlots(lua_State* l);

LUA lua_GetUnitUserData(lua_State* l);

LUA lua_SetUnitUserData(lua_State* l);

LUA lua_CreateItem(lua_State* l);

LUA lua_RemoveItem(lua_State* l);

LUA lua_GetItemPlayer(lua_State* l);

LUA lua_GetItemTypeId(lua_State* l);

LUA lua_GetItemX(lua_State* l);

LUA lua_GetItemY(lua_State* l);

LUA lua_SetItemPosition(lua_State* l);

LUA lua_SetItemDropOnDeath(lua_State* l);

LUA lua_SetItemDroppable(lua_State* l);

LUA lua_SetItemPawnable(lua_State* l);

LUA lua_SetItemPlayer(lua_State* l);

LUA lua_SetItemInvulnerable(lua_State* l);

LUA lua_IsItemInvulnerable(lua_State* l);

LUA lua_GetItemLevel(lua_State* l);

LUA lua_GetItemType(lua_State* l);

LUA lua_SetItemVisible(lua_State* l);

LUA lua_IsItemVisible(lua_State* l);

LUA lua_EnumItemsInRect(lua_State* l);

LUA lua_IsItemOwned(lua_State* l);

LUA lua_IsItemPowerup(lua_State* l);

LUA lua_IsItemSellable(lua_State* l);

LUA lua_IsItemPawnable(lua_State* l);

LUA lua_IsItemIdPowerup(lua_State* l);

LUA lua_IsItemIdSellable(lua_State* l);

LUA lua_IsItemIdPawnable(lua_State* l);

LUA lua_SetItemDropID(lua_State* l);

LUA lua_GetItemName(lua_State* l);

LUA lua_GetItemCharges(lua_State* l);

LUA lua_SetItemCharges(lua_State* l);

LUA lua_GetItemUserData(lua_State* l);

LUA lua_SetItemUserData(lua_State* l);

LUA lua_Player(lua_State* l);

LUA lua_GetLocalPlayer(lua_State* l);

LUA lua_IsPlayerAlly(lua_State* l);

LUA lua_IsPlayerEnemy(lua_State* l);

LUA lua_IsPlayerInForce(lua_State* l);

LUA lua_IsPlayerObserver(lua_State* l);

LUA lua_GetPlayerRace(lua_State* l);

LUA lua_GetPlayerId(lua_State* l);

LUA lua_SetPlayerTechMaxAllowed(lua_State* l);

LUA lua_GetPlayerTechMaxAllowed(lua_State* l);

LUA lua_AddPlayerTechResearched(lua_State* l);

LUA lua_SetPlayerTechResearched(lua_State* l);

LUA lua_GetPlayerTechResearched(lua_State* l);

LUA lua_GetPlayerTechCount(lua_State* l);

LUA lua_SetPlayerAbilityAvailable(lua_State* l);

LUA lua_GetPlayerUnitCount(lua_State* l);

LUA lua_GetPlayerTypedUnitCount(lua_State* l);

LUA lua_GetPlayerStructureCount(lua_State* l);

LUA lua_IsVisibleToPlayer(lua_State* l);

LUA lua_IsLocationVisibleToPlayer(lua_State* l);

LUA lua_IsFoggedToPlayer(lua_State* l);

LUA lua_IsLocationFoggedToPlayer(lua_State* l);

LUA lua_IsMaskedToPlayer(lua_State* l);

LUA lua_IsLocationMaskedToPlayer(lua_State* l);

LUA lua_SetPlayerState(lua_State* l);

LUA lua_GetPlayerState(lua_State* l);

LUA lua_GetPlayerScore(lua_State* l);

LUA lua_GetPlayerAlliance(lua_State* l);

LUA lua_RemovePlayer(lua_State* l);

LUA lua_CachePlayerHeroData(lua_State* l);

LUA lua_GetPlayerHandicap(lua_State* l);

LUA lua_SetPlayerHandicap(lua_State* l);

LUA lua_GetPlayerHandicapXP(lua_State* l);

LUA lua_SetPlayerHandicapXP(lua_State* l);

LUA lua_SetPlayerUnitsOwner(lua_State* l);

LUA lua_CripplePlayer(lua_State* l);

LUA lua_VersionGet(lua_State* l);

LUA lua_VersionCompatible(lua_State* l);

LUA lua_VersionSupported(lua_State* l);

LUA lua_EndGame(lua_State* l);

LUA lua_ChangeLevel(lua_State* l);

LUA lua_RestartGame(lua_State* l);

LUA lua_ReloadGame(lua_State* l);

LUA lua_LoadGame(lua_State* l);

LUA lua_SaveGame(lua_State* l);

LUA lua_RenameSaveDirectory(lua_State* l);

LUA lua_RemoveSaveDirectory(lua_State* l);

LUA lua_CopySaveGame(lua_State* l);

LUA lua_SaveGameExists(lua_State* l);

LUA lua_SetFloatGameState(lua_State* l);

LUA lua_GetFloatGameState(lua_State* l);

LUA lua_SetIntegerGameState(lua_State* l);

LUA lua_GetIntegerGameState(lua_State* l);

LUA lua_SyncSelections(lua_State* l);

LUA lua_DialogCreate(lua_State* l);

LUA lua_DialogDestroy(lua_State* l);

LUA lua_DialogSetAsync(lua_State* l);

LUA lua_DialogClear(lua_State* l);

LUA lua_DialogSetMessage(lua_State* l);

LUA lua_DialogAddButton(lua_State* l);

LUA lua_DialogAddQuitButton(lua_State* l);

LUA lua_DialogDisplay(lua_State* l);

LUA lua_SetMissionAvailable(lua_State* l);

LUA lua_SetCampaignAvailable(lua_State* l);

LUA lua_SetCampaignMenuRace(lua_State* l);

LUA lua_SetCampaignMenuRaceEx(lua_State* l);

LUA lua_ForceCampaignSelectScreen(lua_State* l);

LUA lua_SetOpCinematicAvailable(lua_State* l);

LUA lua_SetEdCinematicAvailable(lua_State* l);

LUA lua_SetTutorialCleared(lua_State* l);

LUA lua_GetDefaultDifficulty(lua_State* l);

LUA lua_SetDefaultDifficulty(lua_State* l);

LUA lua_ReloadGameCachesFromDisk(lua_State* l);

LUA lua_SetCustomCampaignButtonVisible(lua_State* l);

LUA lua_GetCustomCampaignButtonVisible(lua_State* l);

LUA lua_DoNotSaveReplay(lua_State* l);

LUA lua_InitGameCache(lua_State* l);

LUA lua_SaveGameCache(lua_State* l);

LUA lua_StoreInteger(lua_State* l);

LUA lua_StoreReal(lua_State* l);

LUA lua_StoreBoolean(lua_State* l);

LUA lua_StoreUnit(lua_State* l);

LUA lua_StoreString(lua_State* l);

LUA lua_SaveInteger(lua_State* l);

LUA lua_SaveReal(lua_State* l);

LUA lua_SaveBoolean(lua_State* l);

LUA lua_SaveStr(lua_State* l);

LUA lua_SavePlayerHandle(lua_State* l);

LUA lua_SaveWidgetHandle(lua_State* l);

LUA lua_SaveDestructableHandle(lua_State* l);

LUA lua_SaveItemHandle(lua_State* l);

LUA lua_SaveUnitHandle(lua_State* l);

LUA lua_SaveAbilityHandle(lua_State* l);

LUA lua_SaveTimerHandle(lua_State* l);

LUA lua_SaveRegionHandle(lua_State* l);

LUA lua_SaveTriggerHandle(lua_State* l);

LUA lua_SaveTriggerConditionHandle(lua_State* l);

LUA lua_SaveTriggerActionHandle(lua_State* l);

LUA lua_SaveTriggerEventHandle(lua_State* l);

LUA lua_SaveForceHandle(lua_State* l);

LUA lua_SaveGroupHandle(lua_State* l);

LUA lua_SaveLocationHandle(lua_State* l);

LUA lua_SaveRectHandle(lua_State* l);

LUA lua_SaveBooleanExprHandle(lua_State* l);

LUA lua_SaveSoundHandle(lua_State* l);

LUA lua_SaveEffectHandle(lua_State* l);

LUA lua_SaveUnitPoolHandle(lua_State* l);

LUA lua_SaveItemPoolHandle(lua_State* l);

LUA lua_SaveQuestHandle(lua_State* l);

LUA lua_SaveQuestItemHandle(lua_State* l);

LUA lua_SaveDefeatConditionHandle(lua_State* l);

LUA lua_SaveTimerDialogHandle(lua_State* l);

LUA lua_SaveLeaderboardHandle(lua_State* l);

LUA lua_SaveMultiboardHandle(lua_State* l);

LUA lua_SaveMultiboardItemHandle(lua_State* l);

LUA lua_SaveTrackableHandle(lua_State* l);

LUA lua_SaveDialogHandle(lua_State* l);

LUA lua_SaveButtonHandle(lua_State* l);

LUA lua_SaveTextTagHandle(lua_State* l);

LUA lua_SaveLightningHandle(lua_State* l);

LUA lua_SaveImageHandle(lua_State* l);

LUA lua_SaveUbersplatHandle(lua_State* l);

LUA lua_SaveFogStateHandle(lua_State* l);

LUA lua_SaveFogModifierHandle(lua_State* l);

LUA lua_SaveAgentHandle(lua_State* l);

LUA lua_SaveHashtableHandle(lua_State* l);

LUA lua_SyncStoredInteger(lua_State* l);

LUA lua_SyncStoredReal(lua_State* l);

LUA lua_SyncStoredBoolean(lua_State* l);

LUA lua_SyncStoredUnit(lua_State* l);

LUA lua_SyncStoredString(lua_State* l);

LUA lua_GetStoredInteger(lua_State* l);

LUA lua_GetStoredReal(lua_State* l);

LUA lua_GetStoredBoolean(lua_State* l);

LUA lua_RestoreUnit(lua_State* l);

LUA lua_GetStoredString(lua_State* l);

LUA lua_HaveStoredInteger(lua_State* l);

LUA lua_HaveStoredReal(lua_State* l);

LUA lua_HaveStoredBoolean(lua_State* l);

LUA lua_HaveStoredUnit(lua_State* l);

LUA lua_HaveStoredString(lua_State* l);

LUA lua_FlushGameCache(lua_State* l);

LUA lua_FlushStoredMission(lua_State* l);

LUA lua_FlushStoredInteger(lua_State* l);

LUA lua_FlushStoredReal(lua_State* l);

LUA lua_FlushStoredBoolean(lua_State* l);

LUA lua_FlushStoredUnit(lua_State* l);

LUA lua_FlushStoredString(lua_State* l);

LUA lua_InitHashtable(lua_State* l);

LUA lua_LoadInteger(lua_State* l);

LUA lua_LoadReal(lua_State* l);

LUA lua_LoadBoolean(lua_State* l);

LUA lua_LoadStr(lua_State* l);

LUA lua_LoadPlayerHandle(lua_State* l);

LUA lua_LoadWidgetHandle(lua_State* l);

LUA lua_LoadDestructableHandle(lua_State* l);

LUA lua_LoadItemHandle(lua_State* l);

LUA lua_LoadUnitHandle(lua_State* l);

LUA lua_LoadAbilityHandle(lua_State* l);

LUA lua_LoadTimerHandle(lua_State* l);

LUA lua_LoadRegionHandle(lua_State* l);

LUA lua_LoadTriggerHandle(lua_State* l);

LUA lua_LoadTriggerConditionHandle(lua_State* l);

LUA lua_LoadTriggerActionHandle(lua_State* l);

LUA lua_LoadTriggerEventHandle(lua_State* l);

LUA lua_LoadForceHandle(lua_State* l);

LUA lua_LoadGroupHandle(lua_State* l);

LUA lua_LoadLocationHandle(lua_State* l);

LUA lua_LoadRectHandle(lua_State* l);

LUA lua_LoadBooleanExprHandle(lua_State* l);

LUA lua_LoadSoundHandle(lua_State* l);

LUA lua_LoadEffectHandle(lua_State* l);

LUA lua_LoadUnitPoolHandle(lua_State* l);

LUA lua_LoadItemPoolHandle(lua_State* l);

LUA lua_LoadQuestHandle(lua_State* l);

LUA lua_LoadQuestItemHandle(lua_State* l);

LUA lua_LoadDefeatConditionHandle(lua_State* l);

LUA lua_LoadTimerDialogHandle(lua_State* l);

LUA lua_LoadLeaderboardHandle(lua_State* l);

LUA lua_LoadMultiboardHandle(lua_State* l);

LUA lua_LoadMultiboardItemHandle(lua_State* l);

LUA lua_LoadTrackableHandle(lua_State* l);

LUA lua_LoadDialogHandle(lua_State* l);

LUA lua_LoadButtonHandle(lua_State* l);

LUA lua_LoadTextTagHandle(lua_State* l);

LUA lua_LoadLightningHandle(lua_State* l);

LUA lua_LoadImageHandle(lua_State* l);

LUA lua_LoadUbersplatHandle(lua_State* l);

LUA lua_LoadFogStateHandle(lua_State* l);

LUA lua_LoadFogModifierHandle(lua_State* l);

LUA lua_LoadHashtableHandle(lua_State* l);

LUA lua_HaveSavedInteger(lua_State* l);

LUA lua_HaveSavedReal(lua_State* l);

LUA lua_HaveSavedBoolean(lua_State* l);

LUA lua_HaveSavedString(lua_State* l);

LUA lua_HaveSavedHandle(lua_State* l);

LUA lua_RemoveSavedInteger(lua_State* l);

LUA lua_RemoveSavedReal(lua_State* l);

LUA lua_RemoveSavedBoolean(lua_State* l);

LUA lua_RemoveSavedString(lua_State* l);

LUA lua_RemoveSavedHandle(lua_State* l);

LUA lua_FlushParentHashtable(lua_State* l);

LUA lua_FlushChildHashtable(lua_State* l);

LUA lua_GetRandomInt(lua_State* l);

LUA lua_GetRandomReal(lua_State* l);

LUA lua_CreateUnitPool(lua_State* l);

LUA lua_DestroyUnitPool(lua_State* l);

LUA lua_UnitPoolAddUnitType(lua_State* l);

LUA lua_UnitPoolRemoveUnitType(lua_State* l);

LUA lua_PlaceRandomUnit(lua_State* l);

LUA lua_CreateItemPool(lua_State* l);

LUA lua_DestroyItemPool(lua_State* l);

LUA lua_ItemPoolAddItemType(lua_State* l);

LUA lua_ItemPoolRemoveItemType(lua_State* l);

LUA lua_PlaceRandomItem(lua_State* l);

LUA lua_ChooseRandomCreep(lua_State* l);

LUA lua_ChooseRandomNPBuilding(lua_State* l);

LUA lua_ChooseRandomItem(lua_State* l);

LUA lua_ChooseRandomItemEx(lua_State* l);

LUA lua_SetRandomSeed(lua_State* l);

LUA lua_DisplayTextToPlayer(lua_State* l);

LUA lua_DisplayTimedTextToPlayer(lua_State* l);

LUA lua_DisplayTimedTextFromPlayer(lua_State* l);

LUA lua_ClearTextMessages(lua_State* l);

LUA lua_EnableUserControl(lua_State* l);

LUA lua_EnableUserUI(lua_State* l);

LUA lua_DisableRestartMission(lua_State* l);

LUA lua_ForceUIKey(lua_State* l);

LUA lua_ForceUICancel(lua_State* l);

LUA lua_DisplayLoadDialog(lua_State* l);

LUA lua_SetTerrainFog(lua_State* l);

LUA lua_SetUnitFog(lua_State* l);

LUA lua_SetTerrainFogEx(lua_State* l);

LUA lua_ResetTerrainFog(lua_State* l);

LUA lua_SetDayNightModels(lua_State* l);

LUA lua_SetSkyModel(lua_State* l);

LUA lua_SuspendTimeOfDay(lua_State* l);

LUA lua_SetTimeOfDayScale(lua_State* l);

LUA lua_GetTimeOfDayScale(lua_State* l);

LUA lua_ShowInterface(lua_State* l);

LUA lua_PauseGame(lua_State* l);

LUA lua_PingMinimap(lua_State* l);

LUA lua_PingMinimapEx(lua_State* l);

LUA lua_SetIntroShotText(lua_State* l);

LUA lua_SetIntroShotModel(lua_State* l);

LUA lua_EnableOcclusion(lua_State* l);

LUA lua_EnableWorldFogBoundary(lua_State* l);

LUA lua_PlayModelCinematic(lua_State* l);

LUA lua_PlayCinematic(lua_State* l);

LUA lua_SetAltMinimapIcon(lua_State* l);

LUA lua_CreateTextTag(lua_State* l);

LUA lua_DestroyTextTag(lua_State* l);

LUA lua_SetTextTagText(lua_State* l);

LUA lua_SetTextTagPos(lua_State* l);

LUA lua_SetTextTagPosUnit(lua_State* l);

LUA lua_SetTextTagColor(lua_State* l);

LUA lua_SetTextTagVelocity(lua_State* l);

LUA lua_SetTextTagVisibility(lua_State* l);

LUA lua_SetTextTagSuspended(lua_State* l);

LUA lua_SetTextTagPermanent(lua_State* l);

LUA lua_SetTextTagAge(lua_State* l);

LUA lua_SetTextTagLifespan(lua_State* l);

LUA lua_SetTextTagFadepoint(lua_State* l);

LUA lua_SetReservedLocalHeroButtons(lua_State* l);

LUA lua_GetAllyColorFilterState(lua_State* l);

LUA lua_SetAllyColorFilterState(lua_State* l);

LUA lua_GetCreepCampFilterState(lua_State* l);

LUA lua_SetCreepCampFilterState(lua_State* l);

LUA lua_EnableMinimapFilterButtons(lua_State* l);

LUA lua_EnableDragSelect(lua_State* l);

LUA lua_EnablePreSelect(lua_State* l);

LUA lua_EnableSelect(lua_State* l);

LUA lua_CreateTrackable(lua_State* l);

LUA lua_TriggerRegisterTrackableHitEvent(lua_State* l);

LUA lua_TriggerRegisterTrackableTrackEvent(lua_State* l);

LUA lua_GetTriggeringTrackable(lua_State* l);

LUA lua_CreateQuest(lua_State* l);

LUA lua_DestroyQuest(lua_State* l);

LUA lua_QuestSetTitle(lua_State* l);

LUA lua_QuestSetDescription(lua_State* l);

LUA lua_QuestSetIconPath(lua_State* l);

LUA lua_QuestSetRequired(lua_State* l);

LUA lua_QuestSetCompleted(lua_State* l);

LUA lua_QuestSetDiscovered(lua_State* l);

LUA lua_QuestSetFailed(lua_State* l);

LUA lua_QuestSetEnabled(lua_State* l);

LUA lua_IsQuestRequired(lua_State* l);

LUA lua_IsQuestCompleted(lua_State* l);

LUA lua_IsQuestDiscovered(lua_State* l);

LUA lua_IsQuestFailed(lua_State* l);

LUA lua_IsQuestEnabled(lua_State* l);

LUA lua_QuestCreateItem(lua_State* l);

LUA lua_QuestItemSetDescription(lua_State* l);

LUA lua_QuestItemSetCompleted(lua_State* l);

LUA lua_IsQuestItemCompleted(lua_State* l);

LUA lua_CreateDefeatCondition(lua_State* l);

LUA lua_DestroyDefeatCondition(lua_State* l);

LUA lua_DefeatConditionSetDescription(lua_State* l);

LUA lua_FlashQuestDialogButton(lua_State* l);

LUA lua_ForceQuestDialogUpdate(lua_State* l);

LUA lua_CreateTimerDialog(lua_State* l);

LUA lua_DestroyTimerDialog(lua_State* l);

LUA lua_TimerDialogSetTitle(lua_State* l);

LUA lua_TimerDialogSetTitleColor(lua_State* l);

LUA lua_TimerDialogSetTimeColor(lua_State* l);

LUA lua_TimerDialogSetSpeed(lua_State* l);

LUA lua_TimerDialogDisplay(lua_State* l);

LUA lua_IsTimerDialogDisplayed(lua_State* l);

LUA lua_TimerDialogSetRealTimeRemaining(lua_State* l);

LUA lua_CreateLeaderboard(lua_State* l);

LUA lua_DestroyLeaderboard(lua_State* l);

LUA lua_LeaderboardGetItemCount(lua_State* l);

LUA lua_LeaderboardSetSizeByItemCount(lua_State* l);

LUA lua_LeaderboardAddItem(lua_State* l);

LUA lua_LeaderboardRemoveItem(lua_State* l);

LUA lua_LeaderboardRemovePlayerItem(lua_State* l);

LUA lua_LeaderboardSortItemsByValue(lua_State* l);

LUA lua_LeaderboardSortItemsByPlayer(lua_State* l);

LUA lua_LeaderboardSortItemsByLabel(lua_State* l);

LUA lua_LeaderboardClear(lua_State* l);

LUA lua_LeaderboardDisplay(lua_State* l);

LUA lua_IsLeaderboardDisplayed(lua_State* l);

LUA lua_LeaderboardGetLabelText(lua_State* l);

LUA lua_PlayerSetLeaderboard(lua_State* l);

LUA lua_PlayerGetLeaderboard(lua_State* l);

LUA lua_LeaderboardHasPlayerItem(lua_State* l);

LUA lua_LeaderboardGetPlayerIndex(lua_State* l);

LUA lua_LeaderboardSetLabel(lua_State* l);

LUA lua_LeaderboardSetLabelColor(lua_State* l);

LUA lua_LeaderboardSetValueColor(lua_State* l);

LUA lua_LeaderboardSetStyle(lua_State* l);

LUA lua_LeaderboardSetItemValue(lua_State* l);

LUA lua_LeaderboardSetItemLabel(lua_State* l);

LUA lua_LeaderboardSetItemStyle(lua_State* l);

LUA lua_LeaderboardSetItemLabelColor(lua_State* l);

LUA lua_LeaderboardSetItemValueColor(lua_State* l);

LUA lua_CreateMultiboard(lua_State* l);

LUA lua_DestroyMultiboard(lua_State* l);

LUA lua_MultiboardDisplay(lua_State* l);

LUA lua_MultiboardMinimize(lua_State* l);

LUA lua_IsMultiboardDisplayed(lua_State* l);

LUA lua_IsMultiboardMinimized(lua_State* l);

LUA lua_MultiboardClear(lua_State* l);

LUA lua_MultiboardSetTitleText(lua_State* l);

LUA lua_MultiboardGetTitleText(lua_State* l);

LUA lua_MultiboardSetTitleTextColor(lua_State* l);

LUA lua_MultiboardGetRowCount(lua_State* l);

LUA lua_MultiboardGetColumnCount(lua_State* l);

LUA lua_MultiboardSetColumnCount(lua_State* l);

LUA lua_MultiboardSetRowCount(lua_State* l);

LUA lua_MultiboardSetItemsStyle(lua_State* l);

LUA lua_MultiboardSetItemsValueColor(lua_State* l);

LUA lua_MultiboardSetItemsValue(lua_State* l);

LUA lua_MultiboardSetItemsWidth(lua_State* l);

LUA lua_MultiboardSetItemsIcon(lua_State* l);

LUA lua_MultiboardGetItem(lua_State* l);

LUA lua_MultiboardReleaseItem(lua_State* l);

LUA lua_MultiboardSetItemStyle(lua_State* l);

LUA lua_MultiboardSetItemValue(lua_State* l);

LUA lua_MultiboardSetItemValueColor(lua_State* l);

LUA lua_MultiboardSetItemWidth(lua_State* l);

LUA lua_MultiboardSetItemIcon(lua_State* l);

LUA lua_MultiboardSuppressDisplay(lua_State* l);

LUA lua_SetCameraBounds(lua_State* l);

LUA lua_SetCameraPosition(lua_State* l);

LUA lua_SetCameraQuickPosition(lua_State* l);

LUA lua_ResetToGameCamera(lua_State* l);

LUA lua_StopCamera(lua_State* l);

LUA lua_PanCameraTo(lua_State* l);

LUA lua_PanCameraToTimed(lua_State* l);

LUA lua_PanCameraToWithZ(lua_State* l);

LUA lua_PanCameraToTimedWithZ(lua_State* l);

LUA lua_SetCinematicCamera(lua_State* l);

LUA lua_SetCameraField(lua_State* l);

LUA lua_AdjustCameraField(lua_State* l);

LUA lua_SetCameraTargetController(lua_State* l);

LUA lua_SetCameraOrientController(lua_State* l);

LUA lua_SetCameraRotateMode(lua_State* l);

LUA lua_CreateCameraSetup(lua_State* l);

LUA lua_CameraSetupSetField(lua_State* l);

LUA lua_CameraSetupGetField(lua_State* l);

LUA lua_CameraSetupSetDestPosition(lua_State* l);

LUA lua_CameraSetupGetDestPositionLoc(lua_State* l);

LUA lua_CameraSetupGetDestPositionX(lua_State* l);

LUA lua_CameraSetupGetDestPositionY(lua_State* l);

LUA lua_CameraSetupApply(lua_State* l);

LUA lua_CameraSetupApplyWithZ(lua_State* l);

LUA lua_CameraSetupApplyForceDuration(lua_State* l);

LUA lua_CameraSetupApplyForceDurationWithZ(lua_State* l);

LUA lua_CameraSetTargetNoise(lua_State* l);

LUA lua_CameraSetSourceNoise(lua_State* l);

LUA lua_CameraSetTargetNoiseEx(lua_State* l);

LUA lua_CameraSetSourceNoiseEx(lua_State* l);

LUA lua_CameraSetSmoothingFactor(lua_State* l);

LUA lua_GetCameraMargin(lua_State* l);

LUA lua_GetCameraBoundMinX(lua_State* l);

LUA lua_GetCameraBoundMinY(lua_State* l);

LUA lua_GetCameraBoundMaxX(lua_State* l);

LUA lua_GetCameraBoundMaxY(lua_State* l);

LUA lua_GetCameraField(lua_State* l);

LUA lua_GetCameraTargetPositionX(lua_State* l);

LUA lua_GetCameraTargetPositionY(lua_State* l);

LUA lua_GetCameraTargetPositionZ(lua_State* l);

LUA lua_GetCameraTargetPositionLoc(lua_State* l);

LUA lua_GetCameraEyePositionX(lua_State* l);

LUA lua_GetCameraEyePositionY(lua_State* l);

LUA lua_GetCameraEyePositionZ(lua_State* l);

LUA lua_GetCameraEyePositionLoc(lua_State* l);

LUA lua_SetCineFilterTexture(lua_State* l);

LUA lua_SetCineFilterBlendMode(lua_State* l);

LUA lua_SetCineFilterTexMapFlags(lua_State* l);

LUA lua_SetCineFilterStartUV(lua_State* l);

LUA lua_SetCineFilterEndUV(lua_State* l);

LUA lua_SetCineFilterStartColor(lua_State* l);

LUA lua_SetCineFilterEndColor(lua_State* l);

LUA lua_SetCineFilterDuration(lua_State* l);

LUA lua_DisplayCineFilter(lua_State* l);

LUA lua_IsCineFilterDisplayed(lua_State* l);

LUA lua_SetCinematicScene(lua_State* l);

LUA lua_EndCinematicScene(lua_State* l);

LUA lua_ForceCinematicSubtitles(lua_State* l);

LUA lua_NewSoundEnvironment(lua_State* l);

LUA lua_CreateSound(lua_State* l);

LUA lua_CreateSoundFilenameWithLabel(lua_State* l);

LUA lua_CreateSoundFromLabel(lua_State* l);

LUA lua_CreateMIDISound(lua_State* l);

LUA lua_SetStackedSound(lua_State* l);

LUA lua_ClearStackedSound(lua_State* l);

LUA lua_SetStackedSoundRect(lua_State* l);

LUA lua_ClearStackedSoundRect(lua_State* l);

LUA lua_SetSoundParamsFromLabel(lua_State* l);

LUA lua_SetSoundChannel(lua_State* l);

LUA lua_SetSoundVolume(lua_State* l);

LUA lua_SetSoundPitch(lua_State* l);

LUA lua_SetSoundPlayPosition(lua_State* l);

LUA lua_SetSoundDistances(lua_State* l);

LUA lua_SetSoundDistanceCutoff(lua_State* l);

LUA lua_SetSoundConeAngles(lua_State* l);

LUA lua_SetSoundConeOrientation(lua_State* l);

LUA lua_SetSoundPosition(lua_State* l);

LUA lua_SetSoundVelocity(lua_State* l);

LUA lua_AttachSoundToUnit(lua_State* l);

LUA lua_StartSound(lua_State* l);

LUA lua_StopSound(lua_State* l);

LUA lua_KillSoundWhenDone(lua_State* l);

LUA lua_SetMapMusic(lua_State* l);

LUA lua_ClearMapMusic(lua_State* l);

LUA lua_PlayMusic(lua_State* l);

LUA lua_PlayMusicEx(lua_State* l);

LUA lua_StopMusic(lua_State* l);

LUA lua_ResumeMusic(lua_State* l);

LUA lua_PlayThematicMusic(lua_State* l);

LUA lua_PlayThematicMusicEx(lua_State* l);

LUA lua_EndThematicMusic(lua_State* l);

LUA lua_SetMusicVolume(lua_State* l);

LUA lua_SetMusicPlayPosition(lua_State* l);

LUA lua_SetThematicMusicPlayPosition(lua_State* l);

LUA lua_SetSoundDuration(lua_State* l);

LUA lua_GetSoundDuration(lua_State* l);

LUA lua_GetSoundFileDuration(lua_State* l);

LUA lua_VolumeGroupSetVolume(lua_State* l);

LUA lua_VolumeGroupReset(lua_State* l);

LUA lua_GetSoundIsPlaying(lua_State* l);

LUA lua_GetSoundIsLoading(lua_State* l);

LUA lua_RegisterStackedSound(lua_State* l);

LUA lua_UnregisterStackedSound(lua_State* l);

LUA lua_AddWeatherEffect(lua_State* l);

LUA lua_RemoveWeatherEffect(lua_State* l);

LUA lua_EnableWeatherEffect(lua_State* l);

LUA lua_TerrainDeformCrater(lua_State* l);

LUA lua_TerrainDeformRipple(lua_State* l);

LUA lua_TerrainDeformWave(lua_State* l);

LUA lua_TerrainDeformRandom(lua_State* l);

LUA lua_TerrainDeformStop(lua_State* l);

LUA lua_TerrainDeformStopAll(lua_State* l);

LUA lua_DestroyEffect(lua_State* l);

LUA lua_AddSpecialEffect(lua_State* l);

LUA lua_AddSpecialEffectLoc(lua_State* l);

LUA lua_AddSpecialEffectTarget(lua_State* l);

LUA lua_AddSpellEffect(lua_State* l);

LUA lua_AddSpellEffectLoc(lua_State* l);

LUA lua_AddSpellEffectById(lua_State* l);

LUA lua_AddSpellEffectByIdLoc(lua_State* l);

LUA lua_AddSpellEffectTarget(lua_State* l);

LUA lua_AddSpellEffectTargetById(lua_State* l);

LUA lua_AddLightning(lua_State* l);

LUA lua_AddLightningEx(lua_State* l);

LUA lua_DestroyLightning(lua_State* l);

LUA lua_GetLightningColorA(lua_State* l);

LUA lua_GetLightningColorR(lua_State* l);

LUA lua_GetLightningColorG(lua_State* l);

LUA lua_GetLightningColorB(lua_State* l);

LUA lua_MoveLightning(lua_State* l);

LUA lua_MoveLightningEx(lua_State* l);

LUA lua_SetLightningColor(lua_State* l);

LUA lua_GetAbilityEffect(lua_State* l);

LUA lua_GetAbilityEffectById(lua_State* l);

LUA lua_GetAbilitySound(lua_State* l);

LUA lua_GetAbilitySoundById(lua_State* l);

LUA lua_GetTerrainCliffLevel(lua_State* l);

LUA lua_SetWaterBaseColor(lua_State* l);

LUA lua_SetWaterDeforms(lua_State* l);

LUA lua_GetTerrainType(lua_State* l);

LUA lua_GetTerrainVariance(lua_State* l);

LUA lua_SetTerrainType(lua_State* l);

LUA lua_IsTerrainPathable(lua_State* l);

LUA lua_SetTerrainPathable(lua_State* l);

LUA lua_CreateImage(lua_State* l);

LUA lua_DestroyImage(lua_State* l);

LUA lua_ShowImage(lua_State* l);

LUA lua_SetImageConstantHeight(lua_State* l);

LUA lua_SetImagePosition(lua_State* l);

LUA lua_SetImageColor(lua_State* l);

LUA lua_SetImageRender(lua_State* l);

LUA lua_SetImageRenderAlways(lua_State* l);

LUA lua_SetImageAboveWater(lua_State* l);

LUA lua_SetImageType(lua_State* l);

LUA lua_CreateUbersplat(lua_State* l);

LUA lua_DestroyUbersplat(lua_State* l);

LUA lua_ResetUbersplat(lua_State* l);

LUA lua_FinishUbersplat(lua_State* l);

LUA lua_ShowUbersplat(lua_State* l);

LUA lua_SetUbersplatRender(lua_State* l);

LUA lua_SetUbersplatRenderAlways(lua_State* l);

LUA lua_SetBlight(lua_State* l);

LUA lua_SetBlightLoc(lua_State* l);

LUA lua_SetBlightRect(lua_State* l);

LUA lua_SetBlightPoint(lua_State* l);

LUA lua_CreateBlightedGoldmine(lua_State* l);

LUA lua_IsPointBlighted(lua_State* l);

LUA lua_SetDoodadAnimation(lua_State* l);

LUA lua_SetDoodadAnimationRect(lua_State* l);

LUA lua_StartMeleeAI(lua_State* l);

LUA lua_StartCampaignAI(lua_State* l);

LUA lua_CommandAI(lua_State* l);

LUA lua_PauseCompAI(lua_State* l);

LUA lua_GetAIDifficulty(lua_State* l);

LUA lua_RemoveGuardPosition(lua_State* l);

LUA lua_RecycleGuardPosition(lua_State* l);

LUA lua_RemoveAllGuardPositions(lua_State* l);

LUA lua_ExecuteFunc(lua_State* l);

LUA lua_Cheat(lua_State* l);

LUA lua_IsNoVictoryCheat(lua_State* l);

LUA lua_IsNoDefeatCheat(lua_State* l);

LUA lua_Preload(lua_State* l);

LUA lua_PreloadEnd(lua_State* l);

LUA lua_PreloadStart(lua_State* l);

LUA lua_PreloadRefresh(lua_State* l);

LUA lua_PreloadEndEx(lua_State* l);

LUA lua_PreloadGenStart(lua_State* l);

LUA lua_PreloadGenClear(lua_State* l);

LUA lua_PreloadGenEnd(lua_State* l);

LUA lua_Preloader(lua_State* l);

