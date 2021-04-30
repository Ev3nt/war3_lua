#pragma once

#include <Windows.h>

typedef void   jNothing;
typedef UINT32 jBoolean;
typedef UINT32 jCode;
typedef UINT32 jHandle;
typedef INT32  jInteger;
typedef UINT32 jReal;
typedef UINT32 jString;
typedef UINT32 jTrigger;

const jBoolean jTrue = 1;
const jBoolean jFalse = 0;
const jHandle jNull = 0;

typedef DWORD HUNIT;
typedef DWORD HWIDGET;
typedef DWORD HLIGHTNING;
typedef DWORD HPLAYER;
typedef DWORD HEFFECT;
typedef DWORD HLOCATION;
typedef DWORD HEFFECTTYPE;
typedef DWORD HRECT;
typedef DWORD HWEATHEREFFECT;
typedef DWORD HCAMERAFIELD;
typedef DWORD HBOOLEXPR;
typedef DWORD HSOUND;
typedef DWORD HCAMERASETUP;
typedef DWORD HITEMTYPE;
typedef DWORD HCONDITIONFUNC;
typedef DWORD HAIDIFFICULTY;
typedef DWORD HALLIANCETYPE;
typedef DWORD HATTACKTYPE;
typedef DWORD HBLENDMODE;
typedef DWORD HDAMAGETYPE;
typedef DWORD HDIALOGEVENT;
typedef DWORD HFGAMESTATE;
typedef DWORD HFOGSTATE;
typedef DWORD HGAMEDIFFICULTY;
typedef DWORD HGAMEEVENT;
typedef DWORD HGAMESPEED;
typedef DWORD HGAMETYPE;
typedef DWORD HIGAMESTATE;
typedef DWORD HLIMITOP;
typedef DWORD HMAPCONTROL;
typedef DWORD HMAPDENSITY;
typedef DWORD HMAPFLAG;
typedef DWORD HMAPSETTING;
typedef DWORD HMAPVISIBILITY;
typedef DWORD HPATHINGTYPE;
typedef DWORD HPLACEMENT;
typedef DWORD HPLAYERCOLOR;
typedef DWORD HPLAYEREVENT;
typedef DWORD HPLAYERGAMERESULT;
typedef DWORD HPLAYERSCORE;
typedef DWORD HPLAYERSLOTSTATE;
typedef DWORD HPLAYERSTATE;
typedef DWORD HPLAYERUNITEVENT;
typedef DWORD HRACE;
typedef DWORD HRACEPREFERENCE;
typedef DWORD HRARITYCONTROL;
typedef DWORD HSOUNDTYPE;
typedef DWORD HSTARTLOCPRIO;
typedef DWORD HTEXMAPFLAGS;
typedef DWORD HUNITEVENT;
typedef DWORD HUNITSTATE;
typedef DWORD HUNITTYPE;
typedef DWORD HVERSION;
typedef DWORD HVOLUMEGROUP;
typedef DWORD HWEAPONTYPE;
typedef DWORD HWIDGETEVENT;
typedef DWORD HDESTRUCTABLE;
typedef DWORD HDEFEATCONDITION;
typedef DWORD HFOGMODIFIER;
typedef DWORD HFORCE;
typedef DWORD HGROUP;
typedef DWORD HIMAGE;
typedef DWORD HITEM;
typedef DWORD HITEMPOOL;
typedef DWORD HLEADERBOARD;
typedef DWORD HMULTIBOARD;
typedef DWORD HQUEST;
typedef DWORD HREGION;
typedef DWORD HTEXTTAG;
typedef DWORD HTIMER;
typedef DWORD HTIMERDIALOG;
typedef DWORD HTRACKABLE;
typedef DWORD HUBERSPLAT;
typedef DWORD HUNITPOOL;
typedef DWORD HFILTERFUNC;
typedef DWORD HDIALOG;
typedef DWORD HBUTTON;
typedef DWORD HHASHTABLE;
typedef DWORD HGAMECACHE;
typedef DWORD HGAMESTATE;
typedef DWORD HHANDLE;
typedef DWORD HABILITY;
typedef DWORD HEVENTID;
typedef DWORD HQUESTITEM;
typedef DWORD HMULTIBOARDITEM;
typedef DWORD HTRIGGERACTION;
typedef DWORD HTRIGGERCONDITION;
typedef DWORD HEVENT;
typedef DWORD HAGENT;
typedef DWORD HTERRAINDEFORMATION;

jReal to_jReal(float fX);
float from_jReal(jReal val);
jString to_jString(LPCSTR lpString);
LPCSTR from_jString(jString string);
jInteger to_ID(LPCSTR lpID);

//---------------------------------------------------------

jNothing DebugS(jString);

jNothing DebugFI(jString, jInteger);

jNothing DebugUnitID(jString, jInteger);

jNothing DisplayText(jInteger, jString);

jNothing DisplayTextI(jInteger, jString, jInteger);

jNothing DisplayTextII(jInteger, jString, jInteger, jInteger);

jNothing DisplayTextIII(jInteger, jString, jInteger, jInteger, jInteger);

jNothing SuicideUnit(jInteger, jInteger);

jNothing SuicideUnitEx(jInteger, jInteger, jInteger);

jNothing Sleep(jReal*);

jNothing StartThread(jCode);

jInteger GetAiPlayer();

jBoolean DoAiScriptDebug();

jInteger GetHeroId();

jInteger GetHeroLevelAI();

jNothing SetHeroLevels(jCode);

jNothing SetNewHeroes(jBoolean);

jInteger GetUnitCount(jInteger);

jInteger GetPlayerUnitTypeCount(HPLAYER, jInteger);

jInteger GetTownUnitCount(jInteger, jInteger, jBoolean);

jInteger GetUnitCountDone(jInteger);

jInteger GetUpgradeLevel(jInteger);

jInteger GetUnitGoldCost(jInteger);

jInteger GetUnitWoodCost(jInteger);

jInteger GetUnitBuildTime(jInteger);

jInteger GetUpgradeGoldCost(jInteger);

jInteger GetUpgradeWoodCost(jInteger);

jInteger GetEnemyPower();

jInteger GetMinesOwned();

jInteger GetGoldOwned();

jInteger TownWithMine();

jBoolean TownHasMine(jInteger);

jBoolean TownHasHall(jInteger);

jInteger GetNextExpansion();

HUNIT  GetExpansionPeon();

HUNIT  GetEnemyExpansion();

jBoolean SetExpansion(HUNIT, jInteger);

HUNIT  GetBuilding(HPLAYER);

jNothing SetAllianceTarget(HUNIT);

HUNIT  GetAllianceTarget();

jBoolean SetProduce(jInteger, jInteger, jInteger);

jBoolean MergeUnits(jInteger, jInteger, jInteger, jInteger);

jBoolean ConvertUnits(jInteger, jInteger);

jBoolean SetUpgrade(jInteger);

jNothing Unsummon(HUNIT);

jNothing ClearHarvestAI();

jNothing HarvestGold(jInteger, jInteger);

jNothing HarvestWood(jInteger, jInteger);

jNothing StopGathering();

jNothing AddGuardPost(jInteger, jReal*, jReal*);

jNothing FillGuardPosts();

jNothing ReturnGuardPosts();

jNothing CreateCaptains();

jNothing SetCaptainHome(jInteger, jReal*, jReal*);

jNothing ResetCaptainLocs();

jNothing ShiftTownSpot(jReal*, jReal*);

jNothing SetCaptainChanges(jBoolean);

jNothing TeleportCaptain(jReal*, jReal*);

jNothing ClearCaptainTargets();

jNothing CaptainVsUnits(HPLAYER);

jNothing CaptainVsPlayer(HPLAYER);

jNothing CaptainAttack(jReal*, jReal*);

jNothing GroupTimedLife(jBoolean);

jNothing CaptainGoHome();

jBoolean CaptainIsHome();

jBoolean CaptainRetreating();

jBoolean CaptainIsFull();

jBoolean CaptainIsEmpty();

jInteger CaptainGroupSize();

jInteger CaptainReadiness();

jInteger CaptainReadinessHP();

jInteger CaptainReadinessMa();

jBoolean CaptainInCombat(jBoolean);

jBoolean TownThreatened();

jBoolean CaptainAtGoal();

jBoolean CreepsOnMap();

jNothing RemoveInjuries();

jNothing RemoveSiege();

jBoolean IsTowered(HUNIT);

jNothing DisablePathing();

jNothing SetAmphibious();

jNothing InitAssault();

jBoolean AddAssault(jInteger, jInteger);

jBoolean AddDefenders(jInteger, jInteger);

HUNIT  GetCreepCamp(jInteger, jInteger, jBoolean);

jNothing StartGetEnemyBase();

jBoolean WaitGetEnemyBase();

HUNIT  GetMegaTarget();

HUNIT  GetEnemyBase();

HUNIT  GetExpansionFoe();

jInteger GetExpansionX();

jInteger GetExpansionY();

jNothing SetStagePoint(jReal*, jReal*);

jNothing AttackMoveKill(HUNIT);

jNothing AttackMoveXY(jInteger, jInteger);

jNothing LoadZepWave(jInteger, jInteger);

jBoolean SuicidePlayer(HPLAYER, jBoolean);

jBoolean SuicidePlayerUnits(HPLAYER, jBoolean);

jBoolean UnitAlive(HUNIT);

jBoolean UnitInvis(HUNIT);

jInteger IgnoredUnits(jInteger);

jInteger CommandsWaiting();

jInteger GetLastCommand();

jInteger GetLastData();

jNothing PopLastCommand();

jNothing SetCampaignAI();

jNothing SetMeleeAI();

jNothing SetTargetHeroes(jBoolean);

jNothing SetHeroesFlee(jBoolean);

jNothing SetHeroesBuyItems(jBoolean);

jNothing SetIgnoreInjured(jBoolean);

jNothing SetPeonsRepair(jBoolean);

jNothing SetRandomPaths(jBoolean);

jNothing SetDefendPlayer(jBoolean);

jNothing SetHeroesTakeItems(jBoolean);

jNothing SetUnitsFlee(jBoolean);

jNothing SetGroupsFlee(jBoolean);

jNothing SetSlowChopping(jBoolean);

jNothing SetSmartArtillery(jBoolean);

jNothing SetWatchMegaTargets(jBoolean);

jNothing SetReplacementCount(jInteger);

jNothing PurchaseZeppelin();

jInteger MeleeDifficulty();

jNothing DebugBreak(jInteger);

jReal Deg2Rad(jReal*);

jReal Rad2Deg(jReal*);

jReal Sin(jReal*);

jReal Cos(jReal*);

jReal Tan(jReal*);

jReal Asin(jReal*);

jReal Acos(jReal*);

jReal Atan(jReal*);

jReal Atan2(jReal*, jReal*);

jReal SquareRoot(jReal*);

jReal Pow(jReal*, jReal*);

jReal I2R(jInteger);

jInteger R2I(jReal*);

jString I2S(jInteger);

jString R2S(jReal*);

jString R2SW(jReal*, jInteger, jInteger);

jInteger S2I(jString);

jReal S2R(jString);

jInteger GetHandleId(HHANDLE);

jString SubString(jString, jInteger, jInteger);

jInteger StringLength(jString);

jString StringCase(jString, jBoolean);

jInteger StringHash(jString);

jString GetLocalizedString(jString);

jInteger GetLocalizedHotkey(jString);

HRACE  ConvertRace(jInteger);

HALLIANCETYPE  ConvertAllianceType(jInteger);

HRACEPREFERENCE  ConvertRacePref(jInteger);

HIGAMESTATE  ConvertIGameState(jInteger);

HFGAMESTATE  ConvertFGameState(jInteger);

HPLAYERSTATE  ConvertPlayerState(jInteger);

HPLAYERSCORE  ConvertPlayerScore(jInteger);

HSTARTLOCPRIO  ConvertStartLocPrio(jInteger);

HPLAYERGAMERESULT  ConvertPlayerGameResult(jInteger);

HUNITSTATE  ConvertUnitState(jInteger);

HAIDIFFICULTY  ConvertAIDifficulty(jInteger);

HGAMEEVENT  ConvertGameEvent(jInteger);

HPLAYEREVENT  ConvertPlayerEvent(jInteger);

HPLAYERUNITEVENT  ConvertPlayerUnitEvent(jInteger);

HUNITEVENT  ConvertUnitEvent(jInteger);

HWIDGETEVENT  ConvertWidgetEvent(jInteger);

HDIALOGEVENT  ConvertDialogEvent(jInteger);

HLIMITOP  ConvertLimitOp(jInteger);

HUNITTYPE  ConvertUnitType(jInteger);

HGAMESPEED  ConvertGameSpeed(jInteger);

HPLACEMENT  ConvertPlacement(jInteger);

HGAMEDIFFICULTY  ConvertGameDifficulty(jInteger);

HGAMETYPE  ConvertGameType(jInteger);

HMAPFLAG  ConvertMapFlag(jInteger);

HMAPVISIBILITY  ConvertMapVisibility(jInteger);

HMAPSETTING  ConvertMapSetting(jInteger);

HMAPDENSITY  ConvertMapDensity(jInteger);

HMAPCONTROL  ConvertMapControl(jInteger);

HPLAYERCOLOR  ConvertPlayerColor(jInteger);

HPLAYERSLOTSTATE  ConvertPlayerSlotState(jInteger);

HVOLUMEGROUP  ConvertVolumeGroup(jInteger);

HCAMERAFIELD  ConvertCameraField(jInteger);

HBLENDMODE  ConvertBlendMode(jInteger);

HRARITYCONTROL  ConvertRarityControl(jInteger);

HTEXMAPFLAGS  ConvertTexMapFlags(jInteger);

HFOGSTATE  ConvertFogState(jInteger);

HEFFECTTYPE  ConvertEffectType(jInteger);

HVERSION  ConvertVersion(jInteger);

HITEMTYPE  ConvertItemType(jInteger);

HATTACKTYPE  ConvertAttackType(jInteger);

HDAMAGETYPE  ConvertDamageType(jInteger);

HWEAPONTYPE  ConvertWeaponType(jInteger);

HSOUNDTYPE  ConvertSoundType(jInteger);

HPATHINGTYPE  ConvertPathingType(jInteger);

jNothing SetMapName(jString);

jNothing SetMapDescription(jString);

jNothing SetTeams(jInteger);

jNothing SetPlayers(jInteger);

jNothing SetGameTypeSupported(HGAMETYPE, jBoolean);

jNothing SetMapFlag(HMAPFLAG, jBoolean);

jNothing SetGameSpeed(HGAMESPEED);

jNothing SetGamePlacement(HPLACEMENT);

jNothing SetGameDifficulty(HGAMEDIFFICULTY);

jNothing SetResourceDensity(HMAPDENSITY);

jNothing SetCreatureDensity(HMAPDENSITY);

jNothing DefineStartLocation(jInteger, jReal*, jReal*);

jNothing DefineStartLocationLoc(jInteger, HLOCATION);

jNothing SetStartLocPrioCount(jInteger, jInteger);

jNothing SetStartLocPrio(jInteger, jInteger, jInteger, HSTARTLOCPRIO);

jInteger GetStartLocPrioSlot(jInteger, jInteger);

HSTARTLOCPRIO  GetStartLocPrio(jInteger, jInteger);

jInteger GetTeams();

jInteger GetPlayers();

jBoolean IsGameTypeSupported(HGAMETYPE);

jBoolean IsMapFlagSet(HMAPFLAG);

HGAMETYPE  GetGameTypeSelected();

HPLACEMENT  GetGamePlacement();

HGAMESPEED  GetGameSpeed();

HGAMEDIFFICULTY  GetGameDifficulty();

HMAPDENSITY  GetResourceDensity();

HMAPDENSITY  GetCreatureDensity();

jReal GetStartLocationX(jInteger);

jReal GetStartLocationY(jInteger);

HLOCATION  GetStartLocationLoc(jInteger);

jNothing SetPlayerTeam(HPLAYER, jInteger);

jNothing SetPlayerStartLocation(HPLAYER, jInteger);

jNothing ForcePlayerStartLocation(HPLAYER, jInteger);

jNothing SetPlayerAlliance(HPLAYER, HPLAYER, HALLIANCETYPE, jBoolean);

jNothing SetPlayerTaxRate(HPLAYER, HPLAYER, HPLAYERSTATE, jInteger);

jNothing SetPlayerRacePreference(HPLAYER, HRACEPREFERENCE);

jNothing SetPlayerRaceSelectable(HPLAYER, jBoolean);

jNothing SetPlayerController(HPLAYER, HMAPCONTROL);

jNothing SetPlayerColor(HPLAYER, HPLAYERCOLOR);

jNothing SetPlayerOnScoreScreen(HPLAYER, jBoolean);

jNothing SetPlayerName(HPLAYER, jString);

jInteger GetPlayerTeam(HPLAYER);

//jString GetPlayerName(HPLAYER whichPlayer);

// Rewrited
LPCSTR GetPlayerName(HPLAYER whichPlayer);

jInteger GetPlayerStartLocation(HPLAYER);

jReal GetPlayerStartLocationX(HPLAYER);

jReal GetPlayerStartLocationY(HPLAYER);

HPLAYERCOLOR  GetPlayerColor(HPLAYER);

jBoolean GetPlayerSelectable(HPLAYER);

HMAPCONTROL  GetPlayerController(HPLAYER);

HPLAYERSLOTSTATE  GetPlayerSlotState(HPLAYER);

jInteger GetPlayerTaxRate(HPLAYER, HPLAYER, HPLAYERSTATE);

jBoolean IsPlayerRacePrefSet(HPLAYER, HRACEPREFERENCE);

HLOCATION  Location(jReal*, jReal*);

jNothing RemoveLocation(HLOCATION);

jNothing MoveLocation(HLOCATION, jReal*, jReal*);

jReal GetLocationX(HLOCATION);

jReal GetLocationY(HLOCATION);

jReal GetLocationZ(HLOCATION);

HTIMER  CreateTimer();

jNothing DestroyTimer(HTIMER);

jNothing TimerStart(HTIMER, jReal*, jBoolean, jCode);

jReal TimerGetTimeout(HTIMER);

jReal TimerGetElapsed(HTIMER);

jReal TimerGetRemaining(HTIMER);

jNothing PauseTimer(HTIMER);

jNothing ResumeTimer(HTIMER);

HTIMER  GetExpiredTimer();

HCONDITIONFUNC  Condition(jCode);

jNothing DestroyCondition(HCONDITIONFUNC);

HFILTERFUNC  Filter(jCode);

jNothing DestroyFilter(HFILTERFUNC);

jNothing DestroyBoolExpr(HBOOLEXPR);

HBOOLEXPR  And(HBOOLEXPR, HBOOLEXPR);

HBOOLEXPR  Or(HBOOLEXPR, HBOOLEXPR);

HBOOLEXPR  Not(HBOOLEXPR);

HREGION  CreateRegion();

jNothing RemoveRegion(HREGION);

jNothing RegionAddRect(HREGION, HRECT);

jNothing RegionClearRect(HREGION, HRECT);

jNothing RegionAddCell(HREGION, jReal*, jReal*);

jNothing RegionAddCellAtLoc(HREGION, HLOCATION);

jNothing RegionClearCell(HREGION, jReal*, jReal*);

jNothing RegionClearCellAtLoc(HREGION, HLOCATION);

jBoolean IsUnitInRegion(HREGION, HUNIT);

jBoolean IsPointInRegion(HREGION, jReal*, jReal*);

jBoolean IsLocationInRegion(HREGION, HLOCATION);

HRECT  Rect(jReal*, jReal*, jReal*, jReal*);

HRECT  RectFromLoc(HLOCATION, HLOCATION);

jNothing RemoveRect(HRECT);

jNothing SetRect(HRECT, jReal*, jReal*, jReal*, jReal*);

jNothing SetRectFromLoc(HRECT, HLOCATION, HLOCATION);

jReal GetRectCenterX(HRECT);

jReal GetRectCenterY(HRECT);

jNothing MoveRectTo(HRECT, jReal*, jReal*);

jNothing MoveRectToLoc(HRECT, HLOCATION);

jReal GetRectMinX(HRECT);

jReal GetRectMinY(HRECT);

jReal GetRectMaxX(HRECT);

jReal GetRectMaxY(HRECT);

HRECT  GetWorldBounds();

jNothing SetFogStateRect(HPLAYER, HFOGSTATE, HRECT, jBoolean);

jNothing SetFogStateRadius(HPLAYER, HFOGSTATE, jReal*, jReal*, jReal*, jBoolean);

jNothing SetFogStateRadiusLoc(HPLAYER, HFOGSTATE, HLOCATION, jReal*, jBoolean);

jNothing FogMaskEnable(jBoolean);

jBoolean IsFogMaskEnabled();

jNothing FogEnable(jBoolean);

jBoolean IsFogEnabled();

HFOGMODIFIER  CreateFogModifierRect(HPLAYER, HFOGSTATE, HRECT, jBoolean, jBoolean);

HFOGMODIFIER  CreateFogModifierRadius(HPLAYER, HFOGSTATE, jReal*, jReal*, jReal*, jBoolean, jBoolean);

HFOGMODIFIER  CreateFogModifierRadiusLoc(HPLAYER, HFOGSTATE, HLOCATION, jReal*, jBoolean, jBoolean);

jNothing DestroyFogModifier(HFOGMODIFIER);

jNothing FogModifierStart(HFOGMODIFIER);

jNothing FogModifierStop(HFOGMODIFIER);

jTrigger CreateTrigger();

jNothing DestroyTrigger(jTrigger);

jNothing ResetTrigger(jTrigger);

jNothing EnableTrigger(jTrigger);

jNothing DisableTrigger(jTrigger);

jBoolean IsTriggerEnabled(jTrigger);

jNothing TriggerWaitOnSleeps(jTrigger, jBoolean);

jBoolean IsTriggerWaitOnSleeps(jTrigger);

HEVENT  TriggerRegisterVariableEvent(jTrigger, jString, HLIMITOP, jReal*);

HEVENT  TriggerRegisterTimerEvent(jTrigger, jReal*, jBoolean);

HEVENT  TriggerRegisterTimerExpireEvent(jTrigger, HTIMER);

HEVENT  TriggerRegisterGameStateEvent(jTrigger, HGAMESTATE, HLIMITOP, jReal*);

HGAMESTATE  GetEventGameState();

HEVENT  TriggerRegisterDialogEvent(jTrigger, HDIALOG);

HEVENT  TriggerRegisterDialogButtonEvent(jTrigger, HBUTTON);

HBUTTON  GetClickedButton();

HDIALOG  GetClickedDialog();

jReal  GetTournamentFinishSoonTimeRemaining();

jInteger  GetTournamentFinishNowRule();

HPLAYER  GetTournamentFinishNowPlayer();

jInteger GetTournamentScore(HPLAYER);

jString GetSaveBasicFilename();

HEVENT  TriggerRegisterGameEvent(jTrigger, HGAMEEVENT);

HPLAYER  GetWinningPlayer();

HEVENT  TriggerRegisterPlayerStateEvent(jTrigger, HPLAYER, HPLAYERSTATE, HLIMITOP, jReal*);

HPLAYERSTATE  GetEventPlayerState();

HEVENT  TriggerRegisterPlayerEvent(jTrigger, HPLAYER, HPLAYEREVENT);

HEVENT  TriggerRegisterPlayerUnitEvent(jTrigger, HPLAYER, HPLAYERUNITEVENT, HBOOLEXPR);

HUNIT  GetAttacker();

HUNIT  GetRescuer();

HUNIT  GetDyingUnit();

HUNIT  GetKillingUnit();

HUNIT  GetDecayingUnit();

HUNIT  GetConstructingStructure();

HUNIT  GetCancelledStructure();

HUNIT  GetConstructedStructure();

jInteger GetTrainedUnitType();

HUNIT  GetResearchingUnit();

jInteger GetResearched();

HUNIT  GetTrainedUnit();

HUNIT  GetSellingUnit();

HUNIT  GetSoldUnit();

HUNIT  GetBuyingUnit();

HITEM  GetSoldItem();

HUNIT  GetChangingUnit();

HPLAYER  GetChangingUnitPrevOwner();

HUNIT  GetDetectedUnit();

HUNIT  GetOrderedUnit();

jInteger OrderId(jString);

jString OrderId2String(jInteger);

jInteger AbilityId(jString);

jString AbilityId2String(jInteger);

jInteger UnitId(jString);

jString UnitId2String(jInteger);

jString GetObjectName(jInteger);

jInteger GetIssuedOrderId();

jReal GetOrderPointX();

jReal GetOrderPointY();

HLOCATION  GetOrderPointLoc();

HWIDGET  GetOrderTarget();

HDESTRUCTABLE  GetOrderTargetDestructable();

HITEM  GetOrderTargetItem();

HUNIT  GetOrderTargetUnit();

HUNIT  GetSpellAbilityUnit();

jInteger GetSpellAbilityId();

HABILITY  GetSpellAbility();

HLOCATION  GetSpellTargetLoc();

jReal GetSpellTargetX();

jReal GetSpellTargetY();

HDESTRUCTABLE  GetSpellTargetDestructable();

HITEM  GetSpellTargetItem();

HUNIT  GetSpellTargetUnit();

HUNIT  GetLevelingUnit();

HUNIT  GetLearningUnit();

jInteger GetLearnedSkill();

jInteger GetLearnedSkillLevel();

HUNIT  GetRevivableUnit();

HUNIT  GetRevivingUnit();

HUNIT  GetSummoningUnit();

HUNIT  GetSummonedUnit();

HUNIT  GetTransportUnit();

HUNIT  GetLoadedUnit();

HUNIT  GetManipulatingUnit();

HITEM  GetManipulatedItem();

HEVENT  TriggerRegisterPlayerAllianceChange(jTrigger, HPLAYER, HALLIANCETYPE);

HEVENT  TriggerRegisterPlayerChatEvent(jTrigger, HPLAYER, jString, jBoolean);

//jString GetEventPlayerChatString();

// Rewrited
LPCSTR GetEventPlayerChatString();

jString GetEventPlayerChatStringMatched();

HEVENT  TriggerRegisterUnitStateEvent(jTrigger, HUNIT, HUNITSTATE, HLIMITOP, jReal*);

HUNITSTATE  GetEventUnitState();

HEVENT  TriggerRegisterDeathEvent(jTrigger, HWIDGET);

HEVENT  TriggerRegisterUnitEvent(jTrigger, HUNIT, HUNITEVENT);

jReal GetEventDamage();

HUNIT  GetEventDamageSource();

HPLAYER  GetEventDetectingPlayer();

HUNIT  GetEventTargetUnit();

HEVENT  TriggerRegisterFilterUnitEvent(jTrigger, HUNIT, HUNITEVENT, HBOOLEXPR);

HEVENT  TriggerRegisterUnitInRange(jTrigger, HUNIT, jReal*, HBOOLEXPR);

HEVENT  TriggerRegisterEnterRegion(jTrigger, HREGION, HBOOLEXPR);

HEVENT  TriggerRegisterLeaveRegion(jTrigger, HREGION, HBOOLEXPR);

HREGION  GetTriggeringRegion();

HUNIT  GetEnteringUnit();

HUNIT  GetLeavingUnit();

HTRIGGERCONDITION  TriggerAddCondition(jTrigger, HBOOLEXPR);

jNothing TriggerRemoveCondition(jTrigger, HTRIGGERCONDITION);

jNothing TriggerClearConditions(jTrigger);

HTRIGGERACTION  TriggerAddAction(jTrigger, jCode);

jNothing TriggerRemoveAction(jTrigger, HTRIGGERACTION);

jNothing TriggerClearActions(jTrigger);

jNothing TriggerSleepAction(jReal*);

jNothing TriggerWaitForSound(HSOUND, jReal*);

jNothing TriggerExecute(jTrigger);

jNothing TriggerExecuteWait(jTrigger);

jBoolean TriggerEvaluate(jTrigger);

jNothing TriggerSyncStart();

jNothing TriggerSyncReady();

HWIDGET  GetTriggerWidget();

HDESTRUCTABLE  GetTriggerDestructable();

HUNIT  GetTriggerUnit();

HPLAYER  GetTriggerPlayer();

jTrigger  GetTriggeringTrigger();

HEVENTID  GetTriggerEventId();

jInteger GetTriggerEvalCount(jTrigger);

jInteger GetTriggerExecCount(jTrigger);

HUNIT  GetFilterUnit();

HUNIT  GetEnumUnit();

HPLAYER  GetEnumPlayer();

HPLAYER  GetFilterPlayer();

HDESTRUCTABLE  GetFilterDestructable();

HDESTRUCTABLE  GetEnumDestructable();

HITEM  GetFilterItem();

HITEM  GetEnumItem();

HGROUP  CreateGroup();

jNothing DestroyGroup(HGROUP);

jNothing GroupAddUnit(HGROUP, HUNIT);

jNothing GroupRemoveUnit(HGROUP, HUNIT);

jNothing GroupClear(HGROUP);

jNothing GroupEnumUnitsOfType(HGROUP, jString, HBOOLEXPR);

jNothing GroupEnumUnitsOfTypeCounted(HGROUP, jString, HBOOLEXPR, jInteger);

jNothing GroupEnumUnitsInRect(HGROUP, HRECT, HBOOLEXPR);

jNothing GroupEnumUnitsInRectCounted(HGROUP, HRECT, HBOOLEXPR, jInteger);

jNothing GroupEnumUnitsOfPlayer(HGROUP, HPLAYER, HBOOLEXPR);

jNothing GroupEnumUnitsInRange(HGROUP, jReal*, jReal*, jReal*, HBOOLEXPR);

jNothing GroupEnumUnitsInRangeOfLoc(HGROUP, HLOCATION, jReal*, HBOOLEXPR);

jNothing GroupEnumUnitsInRangeCounted(HGROUP, jReal*, jReal*, jReal*, HBOOLEXPR, jInteger);

jNothing GroupEnumUnitsInRangeOfLocCounted(HGROUP, HLOCATION, jReal*, HBOOLEXPR, jInteger);

jNothing GroupEnumUnitsSelected(HGROUP, HPLAYER, HBOOLEXPR);

jBoolean GroupImmediateOrder(HGROUP, jString);

jBoolean GroupImmediateOrderById(HGROUP, jInteger);

jBoolean GroupPointOrder(HGROUP, jString, jReal*, jReal*);

jBoolean GroupPointOrderLoc(HGROUP, jString, HLOCATION);

jBoolean GroupPointOrderById(HGROUP, jInteger, jReal*, jReal*);

jBoolean GroupPointOrderByIdLoc(HGROUP, jInteger, HLOCATION);

jBoolean GroupTargetOrder(HGROUP, jString, HWIDGET);

jBoolean GroupTargetOrderById(HGROUP, jInteger, HWIDGET);

jNothing ForGroup(HGROUP, jCode);

HUNIT  FirstOfGroup(HGROUP);

HFORCE  CreateForce();

jNothing DestroyForce(HFORCE);

jNothing ForceAddPlayer(HFORCE, HPLAYER);

jNothing ForceRemovePlayer(HFORCE, HPLAYER);

jNothing ForceClear(HFORCE);

jNothing ForceEnumPlayers(HFORCE, HBOOLEXPR);

jNothing ForceEnumPlayersCounted(HFORCE, HBOOLEXPR, jInteger);

jNothing ForceEnumAllies(HFORCE, HPLAYER, HBOOLEXPR);

jNothing ForceEnumEnemies(HFORCE, HPLAYER, HBOOLEXPR);

jNothing ForForce(HFORCE, jCode);

jReal GetWidgetLife(HWIDGET);

jNothing SetWidgetLife(HWIDGET, jReal*);

jReal GetWidgetX(HWIDGET);

jReal GetWidgetY(HWIDGET);

HDESTRUCTABLE  CreateDestructable(jInteger, jReal*, jReal*, jReal*, jReal*, jInteger);

HDESTRUCTABLE  CreateDestructableZ(jInteger, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger);

HDESTRUCTABLE  CreateDeadDestructable(jInteger, jReal*, jReal*, jReal*, jReal*, jInteger);

HDESTRUCTABLE  CreateDeadDestructableZ(jInteger, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger);

jNothing RemoveDestructable(HDESTRUCTABLE);

jNothing KillDestructable(HDESTRUCTABLE);

jNothing SetDestructableInvulnerable(HDESTRUCTABLE, jBoolean);

jBoolean IsDestructableInvulnerable(HDESTRUCTABLE);

jNothing EnumDestructablesInRect(HRECT, HBOOLEXPR, jCode);

jInteger GetDestructableTypeId(HDESTRUCTABLE);

jReal GetDestructableX(HDESTRUCTABLE);

jReal GetDestructableY(HDESTRUCTABLE);

jNothing SetDestructableLife(HDESTRUCTABLE, jReal*);

jReal GetDestructableLife(HDESTRUCTABLE);

jNothing SetDestructableMaxLife(HDESTRUCTABLE, jReal*);

jReal GetDestructableMaxLife(HDESTRUCTABLE);

jNothing DestructableRestoreLife(HDESTRUCTABLE, jReal*, jBoolean);

jNothing QueueDestructableAnimation(HDESTRUCTABLE, jString);

jNothing SetDestructableAnimation(HDESTRUCTABLE, jString);

jNothing SetDestructableAnimationSpeed(HDESTRUCTABLE, jReal*);

jNothing ShowDestructable(HDESTRUCTABLE, jBoolean);

jReal GetDestructableOccluderHeight(HDESTRUCTABLE);

jNothing SetDestructableOccluderHeight(HDESTRUCTABLE, jReal*);

jString GetDestructableName(HDESTRUCTABLE);

HUNIT  CreateUnit(HPLAYER, jInteger, jReal*, jReal*, jReal*);

HUNIT  CreateUnitByName(HPLAYER, jString, jReal*, jReal*, jReal*);

HUNIT  CreateUnitAtLoc(HPLAYER, jInteger, HLOCATION, jReal*);

HUNIT  CreateUnitAtLocByName(HPLAYER, jString, HLOCATION, jReal*);

HUNIT  CreateCorpse(HPLAYER, jInteger, jReal*, jReal*, jReal*);

jReal GetUnitState(HUNIT, HUNITSTATE);

jInteger GetUnitFoodUsed(HUNIT);

jInteger GetUnitFoodMade(HUNIT);

jInteger GetFoodMade(jInteger);

jInteger GetFoodUsed(jInteger);

jNothing SetUnitUseFood(HUNIT, jBoolean);

jReal GetUnitX(HUNIT);

jReal GetUnitY(HUNIT);

HLOCATION  GetUnitLoc(HUNIT);

HLOCATION  GetUnitRallyPoint(HUNIT);

HUNIT  GetUnitRallyUnit(HUNIT);

HDESTRUCTABLE  GetUnitRallyDestructable(HUNIT);

jReal GetUnitFacing(HUNIT);

jReal GetUnitMoveSpeed(HUNIT);

jReal GetUnitDefaultMoveSpeed(HUNIT);

jInteger GetUnitTypeId(HUNIT);

HRACE  GetUnitRace(HUNIT);

jString GetUnitName(HUNIT);

jInteger GetUnitPointValue(HUNIT);

jInteger GetUnitPointValueByType(jInteger);

jNothing SetUnitX(HUNIT, jReal*);

jNothing SetUnitY(HUNIT, jReal*);

jNothing SetUnitPosition(HUNIT, jReal*, jReal*);

jNothing SetUnitPositionLoc(HUNIT, HLOCATION);

jNothing SetUnitFacing(HUNIT, jReal*);

jNothing SetUnitFacingTimed(HUNIT, jReal*, jReal*);

jNothing SetUnitFlyHeight(HUNIT, jReal*, jReal*);

jNothing SetUnitMoveSpeed(HUNIT, jReal*);

jNothing SetUnitTurnSpeed(HUNIT, jReal*);

jNothing SetUnitPropWindow(HUNIT, jReal*);

jNothing SetUnitCreepGuard(HUNIT, jBoolean);

jReal GetUnitAcquireRange(HUNIT);

jReal GetUnitTurnSpeed(HUNIT);

jReal GetUnitPropWindow(HUNIT);

jReal GetUnitFlyHeight(HUNIT);

jReal GetUnitDefaultAcquireRange(HUNIT);

jReal GetUnitDefaultTurnSpeed(HUNIT);

jReal GetUnitDefaultPropWindow(HUNIT);

jReal GetUnitDefaultFlyHeight(HUNIT);

jNothing SetUnitAcquireRange(HUNIT, jReal*);

jNothing SetUnitState(HUNIT, HUNITSTATE, jReal*);

jNothing SetUnitOwner(HUNIT, HPLAYER, jBoolean);

jNothing SetUnitRescuable(HUNIT, HPLAYER, jBoolean);

jNothing SetUnitRescueRange(HUNIT, jReal*);

jNothing SetUnitColor(HUNIT, HPLAYERCOLOR);

jNothing QueueUnitAnimation(HUNIT, jString);

jNothing SetUnitAnimation(HUNIT, jString);

jNothing SetUnitAnimationWithRarity(HUNIT, jString, HRARITYCONTROL);

jNothing SetUnitAnimationByIndex(HUNIT, jInteger);

jNothing AddUnitAnimationProperties(HUNIT, jString, jBoolean);

jNothing SetUnitScale(HUNIT, jReal*, jReal*, jReal*);

jNothing SetUnitTimeScale(HUNIT, jReal*);

jNothing SetUnitBlendTime(HUNIT, jReal*);

jNothing SetUnitVertexColor(HUNIT, jInteger, jInteger, jInteger, jInteger);

jNothing SetUnitLookAt(HUNIT, jString, HUNIT, jReal*, jReal*, jReal*);

jNothing SetUnitPathing(HUNIT, jBoolean);

jNothing ResetUnitLookAt(HUNIT);

jNothing SetHeroStr(HUNIT, jInteger, jBoolean);

jNothing SetHeroAgi(HUNIT, jInteger, jBoolean);

jNothing SetHeroInt(HUNIT, jInteger, jBoolean);

jInteger GetHeroStr(HUNIT, jBoolean);

jInteger GetHeroAgi(HUNIT, jBoolean);

jInteger GetHeroInt(HUNIT, jBoolean);

jInteger GetHeroSkillPoints(HUNIT);

jBoolean UnitStripHeroLevel(HUNIT, jInteger);

jBoolean UnitModifySkillPoints(HUNIT, jInteger);

jInteger GetHeroXP(HUNIT);

jNothing SetHeroXP(HUNIT, jInteger, jBoolean);

jNothing AddHeroXP(HUNIT, jInteger, jBoolean);

jNothing SetHeroLevel(HUNIT, jInteger, jBoolean);

jInteger GetHeroLevel(HUNIT);

jInteger GetUnitLevel(HUNIT);

jString GetHeroProperName(HUNIT);

jNothing SuspendHeroXP(HUNIT, jBoolean);

jBoolean IsSuspendedXP(HUNIT);

jNothing SelectHeroSkill(HUNIT, jInteger);

jInteger GetUnitAbilityLevel(HUNIT, jInteger);

jBoolean ReviveHero(HUNIT, jReal*, jReal*, jBoolean);

jBoolean ReviveHeroLoc(HUNIT, HLOCATION, jBoolean);

jNothing SetUnitExploded(HUNIT, jBoolean);

jNothing SetUnitInvulnerable(HUNIT, jBoolean);

jNothing PauseUnit(HUNIT, jBoolean);

jBoolean IsUnitPaused(HUNIT);

jBoolean UnitAddItem(HUNIT, HITEM);

HITEM  UnitAddItemById(HUNIT, jInteger);

jBoolean UnitAddItemToSlotById(HUNIT, jInteger, jInteger);

jNothing UnitRemoveItem(HUNIT, HITEM);

HITEM  UnitRemoveItemFromSlot(HUNIT, jInteger);

jBoolean UnitHasItem(HUNIT, HITEM);

HITEM  UnitItemInSlot(HUNIT, jInteger);

jInteger UnitInventorySize(HUNIT);

jBoolean UnitDropItemPoint(HUNIT, HITEM, jReal*, jReal*);

jBoolean UnitDropItemSlot(HUNIT, HITEM, jInteger);

jBoolean UnitDropItemTarget(HUNIT, HITEM, HWIDGET);

jBoolean UnitUseItem(HUNIT, HITEM);

jBoolean UnitUseItemPoint(HUNIT, HITEM, jReal*, jReal*);

jBoolean UnitUseItemTarget(HUNIT, HITEM, HWIDGET);

jInteger GetUnitCurrentOrder(HUNIT);

jNothing SetResourceAmount(HUNIT, jInteger);

jNothing AddResourceAmount(HUNIT, jInteger);

jInteger GetResourceAmount(HUNIT);

jNothing SelectUnit(HUNIT, jBoolean);

jNothing ClearSelection();

jNothing UnitAddIndicator(HUNIT, jInteger, jInteger, jInteger, jInteger);

jNothing AddIndicator(HWIDGET, jInteger, jInteger, jInteger, jInteger);

jNothing KillUnit(HUNIT);

jNothing RemoveUnit(HUNIT);

jNothing ShowUnit(HUNIT, jBoolean);

jBoolean IsUnitInForce(HUNIT, HFORCE);

jBoolean IsUnitInGroup(HUNIT, HGROUP);

jBoolean IsUnitOwnedByPlayer(HUNIT, HPLAYER);

jBoolean IsUnitAlly(HUNIT, HPLAYER);

jBoolean IsUnitEnemy(HUNIT, HPLAYER);

jBoolean IsUnitVisible(HUNIT, HPLAYER);

jBoolean IsUnitDetected(HUNIT, HPLAYER);

jBoolean IsUnitInvisible(HUNIT, HPLAYER);

jBoolean IsUnitFogged(HUNIT, HPLAYER);

jBoolean IsUnitMasked(HUNIT, HPLAYER);

jBoolean IsUnitSelected(HUNIT, HPLAYER);

jBoolean IsUnitRace(HUNIT, HRACE);

jBoolean IsUnitType(HUNIT, HUNITTYPE);

jBoolean IsUnit(HUNIT, HUNIT);

jBoolean IsUnitInRange(HUNIT, HUNIT, jReal*);

jBoolean IsUnitInRangeXY(HUNIT, jReal*, jReal*, jReal*);

jBoolean IsUnitInRangeLoc(HUNIT, HLOCATION, jReal*);

jBoolean IsUnitHidden(HUNIT);

jBoolean IsUnitIllusion(HUNIT);

jBoolean IsUnitInTransport(HUNIT, HUNIT);

jBoolean IsUnitLoaded(HUNIT);

jBoolean IsHeroUnitId(jInteger);

jBoolean IsUnitIdType(jInteger, HUNITTYPE);

HPLAYER  GetOwningPlayer(HUNIT);

jNothing UnitShareVision(HUNIT, HPLAYER, jBoolean);

jNothing UnitSuspendDecay(HUNIT, jBoolean);

jBoolean UnitAddType(HUNIT, HUNITTYPE);

jBoolean UnitRemoveType(HUNIT, HUNITTYPE);

jBoolean UnitAddAbility(HUNIT, jInteger);

jBoolean UnitRemoveAbility(HUNIT, jInteger);

jBoolean UnitMakeAbilityPermanent(HUNIT, jBoolean, jInteger);

jBoolean UnitHasBuffsEx(HUNIT, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean);

jInteger UnitCountBuffsEx(HUNIT, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean);

jNothing UnitRemoveBuffs(HUNIT, jBoolean, jBoolean);

jNothing UnitRemoveBuffsEx(HUNIT, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean, jBoolean);

jNothing UnitAddSleep(HUNIT, jBoolean);

jBoolean UnitCanSleep(HUNIT);

jNothing UnitAddSleepPerm(HUNIT, jBoolean);

jBoolean UnitCanSleepPerm(HUNIT);

jBoolean UnitIsSleeping(HUNIT);

jNothing UnitWakeUp(HUNIT);

jNothing UnitApplyTimedLife(HUNIT, jInteger, jReal*);

jBoolean UnitIgnoreAlarm(HUNIT, jBoolean);

jBoolean UnitIgnoreAlarmToggled(HUNIT);

jBoolean UnitDamagePoint(HUNIT, jReal*, jReal*, jReal*, jReal*, jReal*, jBoolean, jBoolean, HATTACKTYPE, HDAMAGETYPE, HWEAPONTYPE);

jBoolean UnitDamageTarget(HUNIT, HWIDGET, jReal*, jBoolean, jBoolean, HATTACKTYPE, HDAMAGETYPE, HWEAPONTYPE);

jInteger DecUnitAbilityLevel(HUNIT, jInteger);

jInteger IncUnitAbilityLevel(HUNIT, jInteger);

jInteger SetUnitAbilityLevel(HUNIT, jInteger, jInteger);

jNothing UnitResetCooldown(HUNIT);

jNothing UnitSetConstructionProgress(HUNIT, jInteger);

jNothing UnitSetUpgradeProgress(HUNIT, jInteger);

jNothing UnitPauseTimedLife(HUNIT, jBoolean);

jNothing UnitSetUsesAltIcon(HUNIT, jBoolean);

jBoolean IssueImmediateOrderById(HUNIT, jInteger);

jBoolean IssuePointOrderById(HUNIT, jInteger, jReal*, jReal*);

jBoolean IssuePointOrderByIdLoc(HUNIT, jInteger, HLOCATION);

jBoolean IssueTargetOrderById(HUNIT, jInteger, HWIDGET);

jBoolean IssueInstantPointOrderById(HUNIT, jInteger, jReal*, jReal*, HWIDGET);

jBoolean IssueInstantTargetOrderById(HUNIT, jInteger, HWIDGET, HWIDGET);

jBoolean IssueBuildOrderById(HUNIT, jInteger, jReal*, jReal*);

jBoolean IssueNeutralImmediateOrderById(HPLAYER, HUNIT, jInteger);

jBoolean IssueNeutralPointOrderById(HPLAYER, HUNIT, jInteger, jReal*, jReal*);

jBoolean IssueNeutralTargetOrderById(HPLAYER, HUNIT, jInteger, HWIDGET);

jBoolean IssueImmediateOrder(HUNIT, jString);

jBoolean IssuePointOrder(HUNIT, jString, jReal*, jReal*);

jBoolean IssuePointOrderLoc(HUNIT, jString, HLOCATION);

jBoolean IssueTargetOrder(HUNIT, jString, HWIDGET);

jBoolean IssueInstantPointOrder(HUNIT, jString, jReal*, jReal*, HWIDGET);

jBoolean IssueInstantTargetOrder(HUNIT, jString, HWIDGET, HWIDGET);

jBoolean IssueBuildOrder(HUNIT, jString, jReal*, jReal*);

jBoolean IssueNeutralImmediateOrder(HPLAYER, HUNIT, jString);

jBoolean IssueNeutralPointOrder(HPLAYER, HUNIT, jString, jReal*, jReal*);

jBoolean IssueNeutralTargetOrder(HPLAYER, HUNIT, jString, HWIDGET);

jReal WaygateGetDestinationX(HUNIT);

jReal WaygateGetDestinationY(HUNIT);

jNothing WaygateSetDestination(HUNIT, jReal*, jReal*);

jNothing WaygateActivate(HUNIT, jBoolean);

jBoolean WaygateIsActive(HUNIT);

jNothing AddItemToAllStock(jInteger, jInteger, jInteger);

jNothing AddItemToStock(HUNIT, jInteger, jInteger, jInteger);

jNothing AddUnitToAllStock(jInteger, jInteger, jInteger);

jNothing AddUnitToStock(HUNIT, jInteger, jInteger, jInteger);

jNothing RemoveItemFromAllStock(jInteger);

jNothing RemoveItemFromStock(HUNIT, jInteger);

jNothing RemoveUnitFromAllStock(jInteger);

jNothing RemoveUnitFromStock(HUNIT, jInteger);

jNothing SetAllItemTypeSlots(jInteger);

jNothing SetAllUnitTypeSlots(jInteger);

jNothing SetItemTypeSlots(HUNIT, jInteger);

jNothing SetUnitTypeSlots(HUNIT, jInteger);

jInteger GetUnitUserData(HUNIT);

jNothing SetUnitUserData(HUNIT, jInteger);

HITEM  CreateItem(jInteger, jReal*, jReal*);

jNothing RemoveItem(HITEM);

HPLAYER  GetItemPlayer(HITEM);

jInteger GetItemTypeId(HITEM);

jReal GetItemX(HITEM);

jReal GetItemY(HITEM);

jNothing SetItemPosition(HITEM, jReal*, jReal*);

jNothing SetItemDropOnDeath(HITEM, jBoolean);

jNothing SetItemDroppable(HITEM, jBoolean);

jNothing SetItemPawnable(HITEM, jBoolean);

jNothing SetItemPlayer(HITEM, HPLAYER, jBoolean);

jNothing SetItemInvulnerable(HITEM, jBoolean);

jBoolean IsItemInvulnerable(HITEM);

jInteger GetItemLevel(HITEM);

HITEMTYPE  GetItemType(HITEM);

jNothing SetItemVisible(HITEM, jBoolean);

jBoolean IsItemVisible(HITEM);

jNothing EnumItemsInRect(HRECT, HBOOLEXPR, jCode);

jBoolean IsItemOwned(HITEM);

jBoolean IsItemPowerup(HITEM);

jBoolean IsItemSellable(HITEM);

jBoolean IsItemPawnable(HITEM);

jBoolean IsItemIdPowerup(jInteger);

jBoolean IsItemIdSellable(jInteger);

jBoolean IsItemIdPawnable(jInteger);

jNothing SetItemDropID(HITEM, jInteger);

jString GetItemName(HITEM);

jInteger GetItemCharges(HITEM);

jNothing SetItemCharges(HITEM, jInteger);

jInteger GetItemUserData(HITEM);

jNothing SetItemUserData(HITEM, jInteger);

HPLAYER  Player(jInteger);

HPLAYER  GetLocalPlayer();

jBoolean IsPlayerAlly(HPLAYER, HPLAYER);

jBoolean IsPlayerEnemy(HPLAYER, HPLAYER);

jBoolean IsPlayerInForce(HPLAYER, HFORCE);

jBoolean IsPlayerObserver(HPLAYER);

HRACE  GetPlayerRace(HPLAYER);

jInteger GetPlayerId(HPLAYER);

jNothing SetPlayerTechMaxAllowed(HPLAYER, jInteger, jInteger);

jInteger GetPlayerTechMaxAllowed(HPLAYER, jInteger);

jNothing AddPlayerTechResearched(HPLAYER, jInteger, jInteger);

jNothing SetPlayerTechResearched(HPLAYER, jInteger, jInteger);

jBoolean GetPlayerTechResearched(HPLAYER, jInteger, jBoolean);

jInteger GetPlayerTechCount(HPLAYER, jInteger, jBoolean);

jNothing SetPlayerAbilityAvailable(HPLAYER, jInteger, jBoolean);

jInteger GetPlayerUnitCount(HPLAYER, jBoolean);

jInteger GetPlayerTypedUnitCount(HPLAYER, jString, jBoolean, jBoolean);

jInteger GetPlayerStructureCount(HPLAYER, jBoolean);

jBoolean IsVisibleToPlayer(jReal*, jReal*, HPLAYER);

jBoolean IsLocationVisibleToPlayer(HLOCATION, HPLAYER);

jBoolean IsFoggedToPlayer(jReal*, jReal*, HPLAYER);

jBoolean IsLocationFoggedToPlayer(HLOCATION, HPLAYER);

jBoolean IsMaskedToPlayer(jReal*, jReal*, HPLAYER);

jBoolean IsLocationMaskedToPlayer(HLOCATION, HPLAYER);

jNothing SetPlayerState(HPLAYER, HPLAYERSTATE, jInteger);

jInteger GetPlayerState(HPLAYER, HPLAYERSTATE);

jInteger GetPlayerScore(HPLAYER, HPLAYERSCORE);

jBoolean GetPlayerAlliance(HPLAYER, HPLAYER, HALLIANCETYPE);

jNothing RemovePlayer(HPLAYER, HPLAYERGAMERESULT);

jNothing CachePlayerHeroData(HPLAYER);

jReal GetPlayerHandicap(HPLAYER);

jNothing SetPlayerHandicap(HPLAYER, jReal*);

jReal GetPlayerHandicapXP(HPLAYER);

jNothing SetPlayerHandicapXP(HPLAYER, jReal*);

jNothing SetPlayerUnitsOwner(HPLAYER, jInteger);

jNothing CripplePlayer(HPLAYER, HFORCE, jBoolean);

HVERSION  VersionGet();

jBoolean VersionCompatible(HVERSION);

jBoolean VersionSupported(HVERSION);

jNothing EndGame(jBoolean);

jNothing ChangeLevel(jString, jBoolean);

jNothing RestartGame(jBoolean);

jNothing ReloadGame();

jNothing LoadGame(jString, jBoolean);

jNothing SaveGame(jString);

jBoolean RenameSaveDirectory(jString, jString);

jBoolean RemoveSaveDirectory(jString);

jBoolean CopySaveGame(jString, jString);

jBoolean SaveGameExists(jString);

jNothing SetFloatGameState(HFGAMESTATE, jReal*);

jReal GetFloatGameState(HFGAMESTATE);

jNothing SetIntegerGameState(HIGAMESTATE, jInteger);

jInteger GetIntegerGameState(HIGAMESTATE);

jNothing SyncSelections();

HDIALOG  DialogCreate();

jNothing DialogDestroy(HDIALOG);

jNothing DialogSetAsync(HDIALOG);

jNothing DialogClear(HDIALOG);

jNothing DialogSetMessage(HDIALOG, jString);

HBUTTON  DialogAddButton(HDIALOG, jString, jInteger);

HBUTTON  DialogAddQuitButton(HDIALOG, jBoolean, jString, jInteger);

jNothing DialogDisplay(HPLAYER, HDIALOG, jBoolean);

jNothing SetMissionAvailable(jInteger, jInteger, jBoolean);

jNothing SetCampaignAvailable(jInteger, jBoolean);

jNothing SetCampaignMenuRace(HRACE);

jNothing SetCampaignMenuRaceEx(jInteger);

jNothing ForceCampaignSelectScreen();

jNothing SetOpCinematicAvailable(jInteger, jBoolean);

jNothing SetEdCinematicAvailable(jInteger, jBoolean);

jNothing SetTutorialCleared(jBoolean);

HGAMEDIFFICULTY  GetDefaultDifficulty();

jNothing SetDefaultDifficulty(HGAMEDIFFICULTY);

jBoolean ReloadGameCachesFromDisk();

jNothing SetCustomCampaignButtonVisible(jInteger, jBoolean);

jBoolean GetCustomCampaignButtonVisible(jInteger);

jNothing DoNotSaveReplay();

HGAMECACHE  InitGameCache(jString);

jBoolean SaveGameCache(HGAMECACHE);

jNothing StoreInteger(HGAMECACHE, jString, jString, jInteger);

jNothing StoreReal(HGAMECACHE, jString, jString, jReal*);

jNothing StoreBoolean(HGAMECACHE, jString, jString, jBoolean);

jBoolean StoreUnit(HGAMECACHE, jString, jString, HUNIT);

jBoolean StoreString(HGAMECACHE, jString, jString, jString);

jNothing SaveInteger(HHASHTABLE, jInteger, jInteger, jInteger);

jNothing SaveReal(HHASHTABLE, jInteger, jInteger, jReal*);

jNothing SaveBoolean(HHASHTABLE, jInteger, jInteger, jBoolean);

jBoolean SaveStr(HHASHTABLE, jInteger, jInteger, jString);

jBoolean SavePlayerHandle(HHASHTABLE, jInteger, jInteger, HPLAYER);

jBoolean SaveWidgetHandle(HHASHTABLE, jInteger, jInteger, HWIDGET);

jBoolean SaveDestructableHandle(HHASHTABLE, jInteger, jInteger, HDESTRUCTABLE);

jBoolean SaveItemHandle(HHASHTABLE, jInteger, jInteger, HITEM);

jBoolean SaveUnitHandle(HHASHTABLE, jInteger, jInteger, HUNIT);

jBoolean SaveAbilityHandle(HHASHTABLE, jInteger, jInteger, HABILITY);

jBoolean SaveTimerHandle(HHASHTABLE, jInteger, jInteger, HTIMER);

jBoolean SaveRegionHandle(HHASHTABLE, jInteger, jInteger, HREGION);

jBoolean SaveTriggerHandle(HHASHTABLE, jInteger, jInteger, jTrigger);

jBoolean SaveTriggerConditionHandle(HHASHTABLE, jInteger, jInteger, HTRIGGERCONDITION);

jBoolean SaveTriggerActionHandle(HHASHTABLE, jInteger, jInteger, HTRIGGERACTION);

jBoolean SaveTriggerEventHandle(HHASHTABLE, jInteger, jInteger, HEVENT);

jBoolean SaveForceHandle(HHASHTABLE, jInteger, jInteger, HFORCE);

jBoolean SaveGroupHandle(HHASHTABLE, jInteger, jInteger, HGROUP);

jBoolean SaveLocationHandle(HHASHTABLE, jInteger, jInteger, HLOCATION);

jBoolean SaveRectHandle(HHASHTABLE, jInteger, jInteger, HRECT);

jBoolean SaveBooleanExprHandle(HHASHTABLE, jInteger, jInteger, HBOOLEXPR);

jBoolean SaveSoundHandle(HHASHTABLE, jInteger, jInteger, HSOUND);

jBoolean SaveEffectHandle(HHASHTABLE, jInteger, jInteger, HEFFECT);

jBoolean SaveUnitPoolHandle(HHASHTABLE, jInteger, jInteger, HUNITPOOL);

jBoolean SaveItemPoolHandle(HHASHTABLE, jInteger, jInteger, HITEMPOOL);

jBoolean SaveQuestHandle(HHASHTABLE, jInteger, jInteger, HQUEST);

jBoolean SaveQuestItemHandle(HHASHTABLE, jInteger, jInteger, HQUESTITEM);

jBoolean SaveDefeatConditionHandle(HHASHTABLE, jInteger, jInteger, HDEFEATCONDITION);

jBoolean SaveTimerDialogHandle(HHASHTABLE, jInteger, jInteger, HTIMERDIALOG);

jBoolean SaveLeaderboardHandle(HHASHTABLE, jInteger, jInteger, HLEADERBOARD);

jBoolean SaveMultiboardHandle(HHASHTABLE, jInteger, jInteger, HMULTIBOARD);

jBoolean SaveMultiboardItemHandle(HHASHTABLE, jInteger, jInteger, HMULTIBOARDITEM);

jBoolean SaveTrackableHandle(HHASHTABLE, jInteger, jInteger, HTRACKABLE);

jBoolean SaveDialogHandle(HHASHTABLE, jInteger, jInteger, HDIALOG);

jBoolean SaveButtonHandle(HHASHTABLE, jInteger, jInteger, HBUTTON);

jBoolean SaveTextTagHandle(HHASHTABLE, jInteger, jInteger, HTEXTTAG);

jBoolean SaveLightningHandle(HHASHTABLE, jInteger, jInteger, HLIGHTNING);

jBoolean SaveImageHandle(HHASHTABLE, jInteger, jInteger, HIMAGE);

jBoolean SaveUbersplatHandle(HHASHTABLE, jInteger, jInteger, HUBERSPLAT);

jBoolean SaveFogStateHandle(HHASHTABLE, jInteger, jInteger, HFOGSTATE);

jBoolean SaveFogModifierHandle(HHASHTABLE, jInteger, jInteger, HFOGMODIFIER);

jBoolean SaveAgentHandle(HHASHTABLE, jInteger, jInteger, HAGENT);

jBoolean SaveHashtableHandle(HHASHTABLE, jInteger, jInteger, HHASHTABLE);

jNothing SyncStoredInteger(HGAMECACHE, jString, jString);

jNothing SyncStoredReal(HGAMECACHE, jString, jString);

jNothing SyncStoredBoolean(HGAMECACHE, jString, jString);

jNothing SyncStoredUnit(HGAMECACHE, jString, jString);

jNothing SyncStoredString(HGAMECACHE, jString, jString);

jInteger GetStoredInteger(HGAMECACHE, jString, jString);

jReal GetStoredReal(HGAMECACHE, jString, jString);

jBoolean GetStoredBoolean(HGAMECACHE, jString, jString);

HUNIT  RestoreUnit(HGAMECACHE, jString, jString, HPLAYER, jReal*, jReal*, jReal*);

jString GetStoredString(HGAMECACHE, jString, jString);

jBoolean HaveStoredInteger(HGAMECACHE, jString, jString);

jBoolean HaveStoredReal(HGAMECACHE, jString, jString);

jBoolean HaveStoredBoolean(HGAMECACHE, jString, jString);

jBoolean HaveStoredUnit(HGAMECACHE, jString, jString);

jBoolean HaveStoredString(HGAMECACHE, jString, jString);

jNothing FlushGameCache(HGAMECACHE);

jNothing FlushStoredMission(HGAMECACHE, jString);

jNothing FlushStoredInteger(HGAMECACHE, jString, jString);

jNothing FlushStoredReal(HGAMECACHE, jString, jString);

jNothing FlushStoredBoolean(HGAMECACHE, jString, jString);

jNothing FlushStoredUnit(HGAMECACHE, jString, jString);

jNothing FlushStoredString(HGAMECACHE, jString, jString);

HHASHTABLE  InitHashtable();

jInteger  LoadInteger(HHASHTABLE, jInteger, jInteger);

jReal  LoadReal(HHASHTABLE, jInteger, jInteger);

jBoolean  LoadBoolean(HHASHTABLE, jInteger, jInteger);

jString  LoadStr(HHASHTABLE, jInteger, jInteger);

HPLAYER  LoadPlayerHandle(HHASHTABLE, jInteger, jInteger);

HWIDGET  LoadWidgetHandle(HHASHTABLE, jInteger, jInteger);

HDESTRUCTABLE  LoadDestructableHandle(HHASHTABLE, jInteger, jInteger);

HITEM  LoadItemHandle(HHASHTABLE, jInteger, jInteger);

HUNIT  LoadUnitHandle(HHASHTABLE, jInteger, jInteger);

HABILITY  LoadAbilityHandle(HHASHTABLE, jInteger, jInteger);

HTIMER  LoadTimerHandle(HHASHTABLE, jInteger, jInteger);

HREGION  LoadRegionHandle(HHASHTABLE, jInteger, jInteger);

jTrigger  LoadTriggerHandle(HHASHTABLE, jInteger, jInteger);

HTRIGGERCONDITION  LoadTriggerConditionHandle(HHASHTABLE, jInteger, jInteger);

HTRIGGERACTION  LoadTriggerActionHandle(HHASHTABLE, jInteger, jInteger);

HEVENT  LoadTriggerEventHandle(HHASHTABLE, jInteger, jInteger);

HFORCE  LoadForceHandle(HHASHTABLE, jInteger, jInteger);

HGROUP  LoadGroupHandle(HHASHTABLE, jInteger, jInteger);

HLOCATION  LoadLocationHandle(HHASHTABLE, jInteger, jInteger);

HRECT  LoadRectHandle(HHASHTABLE, jInteger, jInteger);

HBOOLEXPR  LoadBooleanExprHandle(HHASHTABLE, jInteger, jInteger);

HSOUND  LoadSoundHandle(HHASHTABLE, jInteger, jInteger);

HEFFECT  LoadEffectHandle(HHASHTABLE, jInteger, jInteger);

HUNITPOOL  LoadUnitPoolHandle(HHASHTABLE, jInteger, jInteger);

HITEMPOOL  LoadItemPoolHandle(HHASHTABLE, jInteger, jInteger);

HQUEST  LoadQuestHandle(HHASHTABLE, jInteger, jInteger);

HQUESTITEM  LoadQuestItemHandle(HHASHTABLE, jInteger, jInteger);

HDEFEATCONDITION  LoadDefeatConditionHandle(HHASHTABLE, jInteger, jInteger);

HTIMERDIALOG  LoadTimerDialogHandle(HHASHTABLE, jInteger, jInteger);

HLEADERBOARD  LoadLeaderboardHandle(HHASHTABLE, jInteger, jInteger);

HMULTIBOARD  LoadMultiboardHandle(HHASHTABLE, jInteger, jInteger);

HMULTIBOARDITEM  LoadMultiboardItemHandle(HHASHTABLE, jInteger, jInteger);

HTRACKABLE  LoadTrackableHandle(HHASHTABLE, jInteger, jInteger);

HDIALOG  LoadDialogHandle(HHASHTABLE, jInteger, jInteger);

HBUTTON  LoadButtonHandle(HHASHTABLE, jInteger, jInteger);

HTEXTTAG  LoadTextTagHandle(HHASHTABLE, jInteger, jInteger);

HLIGHTNING  LoadLightningHandle(HHASHTABLE, jInteger, jInteger);

HIMAGE  LoadImageHandle(HHASHTABLE, jInteger, jInteger);

HUBERSPLAT  LoadUbersplatHandle(HHASHTABLE, jInteger, jInteger);

HFOGSTATE  LoadFogStateHandle(HHASHTABLE, jInteger, jInteger);

HFOGMODIFIER  LoadFogModifierHandle(HHASHTABLE, jInteger, jInteger);

HHASHTABLE  LoadHashtableHandle(HHASHTABLE, jInteger, jInteger);

jBoolean HaveSavedInteger(HHASHTABLE, jInteger, jInteger);

jBoolean HaveSavedReal(HHASHTABLE, jInteger, jInteger);

jBoolean HaveSavedBoolean(HHASHTABLE, jInteger, jInteger);

jBoolean HaveSavedString(HHASHTABLE, jInteger, jInteger);

jBoolean HaveSavedHandle(HHASHTABLE, jInteger, jInteger);

jNothing RemoveSavedInteger(HHASHTABLE, jInteger, jInteger);

jNothing RemoveSavedReal(HHASHTABLE, jInteger, jInteger);

jNothing RemoveSavedBoolean(HHASHTABLE, jInteger, jInteger);

jNothing RemoveSavedString(HHASHTABLE, jInteger, jInteger);

jNothing RemoveSavedHandle(HHASHTABLE, jInteger, jInteger);

jNothing FlushParentHashtable(HHASHTABLE);

jNothing FlushChildHashtable(HHASHTABLE, jInteger);

jInteger GetRandomInt(jInteger, jInteger);

jReal GetRandomReal(jReal*, jReal*);

HUNITPOOL  CreateUnitPool();

jNothing DestroyUnitPool(HUNITPOOL);

jNothing UnitPoolAddUnitType(HUNITPOOL, jInteger, jReal*);

jNothing UnitPoolRemoveUnitType(HUNITPOOL, jInteger);

HUNIT  PlaceRandomUnit(HUNITPOOL, HPLAYER, jReal*, jReal*, jReal*);

HITEMPOOL  CreateItemPool();

jNothing DestroyItemPool(HITEMPOOL);

jNothing ItemPoolAddItemType(HITEMPOOL, jInteger, jReal*);

jNothing ItemPoolRemoveItemType(HITEMPOOL, jInteger);

HITEM  PlaceRandomItem(HITEMPOOL, jReal*, jReal*);

jInteger ChooseRandomCreep(jInteger);

jInteger ChooseRandomNPBuilding();

jInteger ChooseRandomItem(jInteger);

jInteger ChooseRandomItemEx(HITEMTYPE, jInteger);

jNothing SetRandomSeed(jInteger);

jNothing DisplayTextToPlayer(HPLAYER, jReal*, jReal*, jString);

jNothing DisplayTimedTextToPlayer(HPLAYER, jReal*, jReal*, jReal*, jString);

jNothing DisplayTimedTextFromPlayer(HPLAYER, jReal*, jReal*, jReal*, jString);

jNothing ClearTextMessages();

jNothing EnableUserControl(jBoolean);

jNothing EnableUserUI(jBoolean);

jNothing DisableRestartMission(jBoolean);

jNothing ForceUIKey(jString);

jNothing ForceUICancel();

jNothing DisplayLoadDialog();

jNothing SetTerrainFog(jReal*, jReal*, jReal*, jReal*, jReal*);

jNothing SetUnitFog(jReal*, jReal*, jReal*, jReal*, jReal*);

jNothing SetTerrainFogEx(jInteger, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*);

jNothing ResetTerrainFog();

jNothing SetDayNightModels(jString, jString);

jNothing SetSkyModel(jString);

jNothing SuspendTimeOfDay(jBoolean);

jNothing SetTimeOfDayScale(jReal*);

jReal GetTimeOfDayScale();

jNothing ShowInterface(jBoolean, jReal*);

jNothing PauseGame(jBoolean);

jNothing PingMinimap(jReal*, jReal*, jReal*);

jNothing PingMinimapEx(jReal*, jReal*, jReal*, jInteger, jInteger, jInteger, jBoolean);

jNothing SetIntroShotText(jString);

jNothing SetIntroShotModel(jString);

jNothing EnableOcclusion(jBoolean);

jNothing EnableWorldFogBoundary(jBoolean);

jNothing PlayModelCinematic(jString);

jNothing PlayCinematic(jString);

jNothing SetAltMinimapIcon(jString);

HTEXTTAG  CreateTextTag();

jNothing DestroyTextTag(HTEXTTAG);

jNothing SetTextTagText(HTEXTTAG, jString, jReal*);

jNothing SetTextTagPos(HTEXTTAG, jReal*, jReal*, jReal*);

jNothing SetTextTagPosUnit(HTEXTTAG, HUNIT, jReal*);

jNothing SetTextTagColor(HTEXTTAG, jInteger, jInteger, jInteger, jInteger);

jNothing SetTextTagVelocity(HTEXTTAG, jReal*, jReal*);

jNothing SetTextTagVisibility(HTEXTTAG, jBoolean);

jNothing SetTextTagSuspended(HTEXTTAG, jBoolean);

jNothing SetTextTagPermanent(HTEXTTAG, jBoolean);

jNothing SetTextTagAge(HTEXTTAG, jReal*);

jNothing SetTextTagLifespan(HTEXTTAG, jReal*);

jNothing SetTextTagFadepoint(HTEXTTAG, jReal*);

jNothing SetReservedLocalHeroButtons(jInteger);

jInteger GetAllyColorFilterState();

jNothing SetAllyColorFilterState(jInteger);

jBoolean GetCreepCampFilterState();

jNothing SetCreepCampFilterState(jBoolean);

jNothing EnableMinimapFilterButtons(jBoolean, jBoolean);

jNothing EnableDragSelect(jBoolean, jBoolean);

jNothing EnablePreSelect(jBoolean, jBoolean);

jNothing EnableSelect(jBoolean, jBoolean);

HTRACKABLE  CreateTrackable(jString, jReal*, jReal*, jReal*);

HEVENT  TriggerRegisterTrackableHitEvent(jTrigger, HTRACKABLE);

HEVENT  TriggerRegisterTrackableTrackEvent(jTrigger, HTRACKABLE);

HTRACKABLE  GetTriggeringTrackable();

HQUEST  CreateQuest();

jNothing DestroyQuest(HQUEST);

jNothing QuestSetTitle(HQUEST, jString);

jNothing QuestSetDescription(HQUEST, jString);

jNothing QuestSetIconPath(HQUEST, jString);

jNothing QuestSetRequired(HQUEST, jBoolean);

jNothing QuestSetCompleted(HQUEST, jBoolean);

jNothing QuestSetDiscovered(HQUEST, jBoolean);

jNothing QuestSetFailed(HQUEST, jBoolean);

jNothing QuestSetEnabled(HQUEST, jBoolean);

jBoolean IsQuestRequired(HQUEST);

jBoolean IsQuestCompleted(HQUEST);

jBoolean IsQuestDiscovered(HQUEST);

jBoolean IsQuestFailed(HQUEST);

jBoolean IsQuestEnabled(HQUEST);

HQUESTITEM  QuestCreateItem(HQUEST);

jNothing QuestItemSetDescription(HQUESTITEM, jString);

jNothing QuestItemSetCompleted(HQUESTITEM, jBoolean);

jBoolean IsQuestItemCompleted(HQUESTITEM);

HDEFEATCONDITION  CreateDefeatCondition();

jNothing DestroyDefeatCondition(HDEFEATCONDITION);

jNothing DefeatConditionSetDescription(HDEFEATCONDITION, jString);

jNothing FlashQuestDialogButton();

jNothing ForceQuestDialogUpdate();

HTIMERDIALOG  CreateTimerDialog(HTIMER);

jNothing DestroyTimerDialog(HTIMERDIALOG);

jNothing TimerDialogSetTitle(HTIMERDIALOG, jString);

jNothing TimerDialogSetTitleColor(HTIMERDIALOG, jInteger, jInteger, jInteger, jInteger);

jNothing TimerDialogSetTimeColor(HTIMERDIALOG, jInteger, jInteger, jInteger, jInteger);

jNothing TimerDialogSetSpeed(HTIMERDIALOG, jReal*);

jNothing TimerDialogDisplay(HTIMERDIALOG, jBoolean);

jBoolean IsTimerDialogDisplayed(HTIMERDIALOG);

jNothing TimerDialogSetRealTimeRemaining(HTIMERDIALOG, jReal*);

HLEADERBOARD  CreateLeaderboard();

jNothing DestroyLeaderboard(HLEADERBOARD);

jInteger LeaderboardGetItemCount(HLEADERBOARD);

jNothing LeaderboardSetSizeByItemCount(HLEADERBOARD, jInteger);

jNothing LeaderboardAddItem(HLEADERBOARD, jString, jInteger, HPLAYER);

jNothing LeaderboardRemoveItem(HLEADERBOARD, jInteger);

jNothing LeaderboardRemovePlayerItem(HLEADERBOARD, HPLAYER);

jNothing LeaderboardSortItemsByValue(HLEADERBOARD, jBoolean);

jNothing LeaderboardSortItemsByPlayer(HLEADERBOARD, jBoolean);

jNothing LeaderboardSortItemsByLabel(HLEADERBOARD, jBoolean);

jNothing LeaderboardClear(HLEADERBOARD);

jNothing LeaderboardDisplay(HLEADERBOARD, jBoolean);

jBoolean IsLeaderboardDisplayed(HLEADERBOARD);

jString LeaderboardGetLabelText(HLEADERBOARD);

jNothing PlayerSetLeaderboard(HPLAYER, HLEADERBOARD);

HLEADERBOARD  PlayerGetLeaderboard(HPLAYER);

jBoolean LeaderboardHasPlayerItem(HLEADERBOARD, HPLAYER);

jInteger LeaderboardGetPlayerIndex(HLEADERBOARD, HPLAYER);

jNothing LeaderboardSetLabel(HLEADERBOARD, jString);

jNothing LeaderboardSetLabelColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger);

jNothing LeaderboardSetValueColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger);

jNothing LeaderboardSetStyle(HLEADERBOARD, jBoolean, jBoolean, jBoolean, jBoolean);

jNothing LeaderboardSetItemValue(HLEADERBOARD, jInteger, jInteger);

jNothing LeaderboardSetItemLabel(HLEADERBOARD, jInteger, jString);

jNothing LeaderboardSetItemStyle(HLEADERBOARD, jInteger, jBoolean, jBoolean, jBoolean);

jNothing LeaderboardSetItemLabelColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger, jInteger);

jNothing LeaderboardSetItemValueColor(HLEADERBOARD, jInteger, jInteger, jInteger, jInteger, jInteger);

HMULTIBOARD  CreateMultiboard();

jNothing DestroyMultiboard(HMULTIBOARD);

jNothing MultiboardDisplay(HMULTIBOARD, jBoolean);

jNothing MultiboardMinimize(HMULTIBOARD, jBoolean);

jBoolean IsMultiboardDisplayed(HMULTIBOARD);

jBoolean IsMultiboardMinimized(HMULTIBOARD);

jNothing MultiboardClear(HMULTIBOARD);

jNothing MultiboardSetTitleText(HMULTIBOARD, jString);

jString MultiboardGetTitleText(HMULTIBOARD);

jNothing MultiboardSetTitleTextColor(HMULTIBOARD, jInteger, jInteger, jInteger, jInteger);

jInteger MultiboardGetRowCount(HMULTIBOARD);

jInteger MultiboardGetColumnCount(HMULTIBOARD);

jNothing MultiboardSetColumnCount(HMULTIBOARD, jInteger);

jNothing MultiboardSetRowCount(HMULTIBOARD, jInteger);

jNothing MultiboardSetItemsStyle(HMULTIBOARD, jBoolean, jBoolean);

jNothing MultiboardSetItemsValueColor(HMULTIBOARD, jInteger, jInteger, jInteger, jInteger);

jNothing MultiboardSetItemsValue(HMULTIBOARD, jString);

jNothing MultiboardSetItemsWidth(HMULTIBOARD, jReal*);

jNothing MultiboardSetItemsIcon(HMULTIBOARD, jString);

HMULTIBOARDITEM  MultiboardGetItem(HMULTIBOARD, jInteger, jInteger);

jNothing MultiboardReleaseItem(HMULTIBOARDITEM);

jNothing MultiboardSetItemStyle(HMULTIBOARDITEM, jBoolean, jBoolean);

jNothing MultiboardSetItemValue(HMULTIBOARDITEM, jString);

jNothing MultiboardSetItemValueColor(HMULTIBOARDITEM, jInteger, jInteger, jInteger, jInteger);

jNothing MultiboardSetItemWidth(HMULTIBOARDITEM, jReal*);

jNothing MultiboardSetItemIcon(HMULTIBOARDITEM, jString);

jNothing MultiboardSuppressDisplay(jBoolean);

jNothing SetCameraBounds(jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*);

jNothing SetCameraPosition(jReal*, jReal*);

jNothing SetCameraQuickPosition(jReal*, jReal*);

jNothing ResetToGameCamera(jReal*);

jNothing StopCamera();

jNothing PanCameraTo(jReal*, jReal*);

jNothing PanCameraToTimed(jReal*, jReal*, jReal*);

jNothing PanCameraToWithZ(jReal*, jReal*, jReal*);

jNothing PanCameraToTimedWithZ(jReal*, jReal*, jReal*, jReal*);

jNothing SetCinematicCamera(jString);

jNothing SetCameraField(HCAMERAFIELD, jReal*, jReal*);

jNothing AdjustCameraField(HCAMERAFIELD, jReal*, jReal*);

jNothing SetCameraTargetController(HUNIT, jReal*, jReal*, jBoolean);

jNothing SetCameraOrientController(HUNIT, jReal*, jReal*);

jNothing SetCameraRotateMode(jReal*, jReal*, jReal*, jReal*);

HCAMERASETUP  CreateCameraSetup();

jNothing CameraSetupSetField(HCAMERASETUP, HCAMERAFIELD, jReal*, jReal*);

jReal CameraSetupGetField(HCAMERASETUP, HCAMERAFIELD);

jNothing CameraSetupSetDestPosition(HCAMERASETUP, jReal*, jReal*, jReal*);

HLOCATION  CameraSetupGetDestPositionLoc(HCAMERASETUP);

jReal CameraSetupGetDestPositionX(HCAMERASETUP);

jReal CameraSetupGetDestPositionY(HCAMERASETUP);

jNothing CameraSetupApply(HCAMERASETUP, jBoolean, jBoolean);

jNothing CameraSetupApplyWithZ(HCAMERASETUP, jReal*);

jNothing CameraSetupApplyForceDuration(HCAMERASETUP, jBoolean, jReal*);

jNothing CameraSetupApplyForceDurationWithZ(HCAMERASETUP, jReal*, jReal*);

jNothing CameraSetTargetNoise(jReal*, jReal*);

jNothing CameraSetSourceNoise(jReal*, jReal*);

jNothing CameraSetTargetNoiseEx(jReal*, jReal*, jBoolean);

jNothing CameraSetSourceNoiseEx(jReal*, jReal*, jBoolean);

jNothing CameraSetSmoothingFactor(jReal*);

jReal GetCameraMargin(jInteger);

jReal GetCameraBoundMinX();

jReal GetCameraBoundMinY();

jReal GetCameraBoundMaxX();

jReal GetCameraBoundMaxY();

jReal GetCameraField(HCAMERAFIELD);

jReal GetCameraTargetPositionX();

jReal GetCameraTargetPositionY();

jReal GetCameraTargetPositionZ();

HLOCATION  GetCameraTargetPositionLoc();

jReal GetCameraEyePositionX();

jReal GetCameraEyePositionY();

jReal GetCameraEyePositionZ();

HLOCATION  GetCameraEyePositionLoc();

jNothing SetCineFilterTexture(jString);

jNothing SetCineFilterBlendMode(HBLENDMODE);

jNothing SetCineFilterTexMapFlags(HTEXMAPFLAGS);

jNothing SetCineFilterStartUV(jReal*, jReal*, jReal*, jReal*);

jNothing SetCineFilterEndUV(jReal*, jReal*, jReal*, jReal*);

jNothing SetCineFilterStartColor(jInteger, jInteger, jInteger, jInteger);

jNothing SetCineFilterEndColor(jInteger, jInteger, jInteger, jInteger);

jNothing SetCineFilterDuration(jReal*);

jNothing DisplayCineFilter(jBoolean);

jBoolean IsCineFilterDisplayed();

jNothing SetCinematicScene(jInteger, HPLAYERCOLOR, jString, jString, jReal*, jReal*);

jNothing EndCinematicScene();

jNothing ForceCinematicSubtitles(jBoolean);

jNothing NewSoundEnvironment(jString);

HSOUND  CreateSound(jString, jBoolean, jBoolean, jBoolean, jInteger, jInteger, jString);

HSOUND  CreateSoundFilenameWithLabel(jString, jBoolean, jBoolean, jBoolean, jInteger, jInteger, jString);

HSOUND  CreateSoundFromLabel(jString, jBoolean, jBoolean, jBoolean, jInteger, jInteger);

HSOUND  CreateMIDISound(jString, jInteger, jInteger);

jNothing SetStackedSound(jString, jReal*, jReal*);

jNothing ClearStackedSound(jString, jReal*, jReal*);

jNothing SetStackedSoundRect(jString, HRECT);

jNothing ClearStackedSoundRect(jString, HRECT);

jNothing SetSoundParamsFromLabel(HSOUND, jString);

jNothing SetSoundChannel(HSOUND, jInteger);

jNothing SetSoundVolume(HSOUND, jInteger);

jNothing SetSoundPitch(HSOUND, jReal*);

jNothing SetSoundPlayPosition(HSOUND, jInteger);

jNothing SetSoundDistances(HSOUND, jReal*, jReal*);

jNothing SetSoundDistanceCutoff(HSOUND, jReal*);

jNothing SetSoundConeAngles(HSOUND, jReal*, jReal*, jInteger);

jNothing SetSoundConeOrientation(HSOUND, jReal*, jReal*, jReal*);

jNothing SetSoundPosition(HSOUND, jReal*, jReal*, jReal*);

jNothing SetSoundVelocity(HSOUND, jReal*, jReal*, jReal*);

jNothing AttachSoundToUnit(HSOUND, HUNIT);

jNothing StartSound(HSOUND);

jNothing StopSound(HSOUND, jBoolean, jBoolean);

jNothing KillSoundWhenDone(HSOUND);

jNothing SetMapMusic(jString, jBoolean, jInteger);

jNothing ClearMapMusic();

jNothing PlayMusic(jString);

jNothing PlayMusicEx(jString, jInteger, jInteger);

jNothing StopMusic(jBoolean);

jNothing ResumeMusic();

jNothing PlayThematicMusic(jString);

jNothing PlayThematicMusicEx(jString, jInteger);

jNothing EndThematicMusic();

jNothing SetMusicVolume(jInteger);

jNothing SetMusicPlayPosition(jInteger);

jNothing SetThematicMusicPlayPosition(jInteger);

jNothing SetSoundDuration(HSOUND, jInteger);

jInteger GetSoundDuration(HSOUND);

jInteger GetSoundFileDuration(jString);

jNothing VolumeGroupSetVolume(HVOLUMEGROUP, jReal*);

jNothing VolumeGroupReset();

jBoolean GetSoundIsPlaying(HSOUND);

jBoolean GetSoundIsLoading(HSOUND);

jNothing RegisterStackedSound(HSOUND, jBoolean, jReal*, jReal*);

jNothing UnregisterStackedSound(HSOUND, jBoolean, jReal*, jReal*);

HWEATHEREFFECT  AddWeatherEffect(HRECT, jInteger);

jNothing RemoveWeatherEffect(HWEATHEREFFECT);

jNothing EnableWeatherEffect(HWEATHEREFFECT, jBoolean);

HTERRAINDEFORMATION  TerrainDeformCrater(jReal*, jReal*, jReal*, jReal*, jInteger, jBoolean);

HTERRAINDEFORMATION  TerrainDeformRipple(jReal*, jReal*, jReal*, jReal*, jInteger, jInteger, jReal*, jReal*, jReal*, jBoolean);

HTERRAINDEFORMATION  TerrainDeformWave(jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger, jInteger);

HTERRAINDEFORMATION  TerrainDeformRandom(jReal*, jReal*, jReal*, jReal*, jReal*, jInteger, jInteger);

jNothing TerrainDeformStop(HTERRAINDEFORMATION, jInteger);

jNothing TerrainDeformStopAll();

jNothing DestroyEffect(HEFFECT);

HEFFECT  AddSpecialEffect(jString, jReal*, jReal*);

HEFFECT  AddSpecialEffectLoc(jString, HLOCATION);

HEFFECT  AddSpecialEffectTarget(jString, HWIDGET, jString);

HEFFECT  AddSpellEffect(jString, HEFFECTTYPE, jReal*, jReal*);

HEFFECT  AddSpellEffectLoc(jString, HEFFECTTYPE, HLOCATION);

HEFFECT  AddSpellEffectById(jInteger, HEFFECTTYPE, jReal*, jReal*);

HEFFECT  AddSpellEffectByIdLoc(jInteger, HEFFECTTYPE, HLOCATION);

HEFFECT  AddSpellEffectTarget(jString, HEFFECTTYPE, HWIDGET, jString);

HEFFECT  AddSpellEffectTargetById(jInteger, HEFFECTTYPE, HWIDGET, jString);

HLIGHTNING  AddLightning(jString, jBoolean, jReal*, jReal*, jReal*, jReal*);

HLIGHTNING  AddLightningEx(jString, jBoolean, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*);

jBoolean DestroyLightning(HLIGHTNING);

jReal GetLightningColorA(HLIGHTNING);

jReal GetLightningColorR(HLIGHTNING);

jReal GetLightningColorG(HLIGHTNING);

jReal GetLightningColorB(HLIGHTNING);

jBoolean MoveLightning(HLIGHTNING, jBoolean, jReal*, jReal*, jReal*, jReal*);

jBoolean MoveLightningEx(HLIGHTNING, jBoolean, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*);

jBoolean SetLightningColor(HLIGHTNING, jReal*, jReal*, jReal*, jReal*);

jString GetAbilityEffect(jString, HEFFECTTYPE, jInteger);

jString GetAbilityEffectById(jInteger, HEFFECTTYPE, jInteger);

jString GetAbilitySound(jString, HSOUNDTYPE);

jString GetAbilitySoundById(jInteger, HSOUNDTYPE);

jInteger GetTerrainCliffLevel(jReal*, jReal*);

jNothing SetWaterBaseColor(jInteger, jInteger, jInteger, jInteger);

jNothing SetWaterDeforms(jBoolean);

jInteger GetTerrainType(jReal*, jReal*);

jInteger GetTerrainVariance(jReal*, jReal*);

jNothing SetTerrainType(jReal*, jReal*, jInteger, jInteger, jInteger, jInteger);

jBoolean IsTerrainPathable(jReal*, jReal*, HPATHINGTYPE);

jNothing SetTerrainPathable(jReal*, jReal*, HPATHINGTYPE, jBoolean);

HIMAGE  CreateImage(jString, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jReal*, jInteger);

jNothing DestroyImage(HIMAGE);

jNothing ShowImage(HIMAGE, jBoolean);

jNothing SetImageConstantHeight(HIMAGE, jBoolean, jReal*);

jNothing SetImagePosition(HIMAGE, jReal*, jReal*, jReal*);

jNothing SetImageColor(HIMAGE, jInteger, jInteger, jInteger, jInteger);

jNothing SetImageRender(HIMAGE, jBoolean);

jNothing SetImageRenderAlways(HIMAGE, jBoolean);

jNothing SetImageAboveWater(HIMAGE, jBoolean, jBoolean);

jNothing SetImageType(HIMAGE, jInteger);

HUBERSPLAT  CreateUbersplat(jReal*, jReal*, jString, jInteger, jInteger, jInteger, jInteger, jBoolean, jBoolean);

jNothing DestroyUbersplat(HUBERSPLAT);

jNothing ResetUbersplat(HUBERSPLAT);

jNothing FinishUbersplat(HUBERSPLAT);

jNothing ShowUbersplat(HUBERSPLAT, jBoolean);

jNothing SetUbersplatRender(HUBERSPLAT, jBoolean);

jNothing SetUbersplatRenderAlways(HUBERSPLAT, jBoolean);

jNothing SetBlight(HPLAYER, jReal*, jReal*, jReal*, jBoolean);

jNothing SetBlightLoc(HPLAYER, HLOCATION, jReal*, jBoolean);

jNothing SetBlightRect(HPLAYER, HRECT, jBoolean);

jNothing SetBlightPoint(HPLAYER, jReal*, jReal*, jBoolean);

HUNIT  CreateBlightedGoldmine(HPLAYER, jReal*, jReal*, jReal*);

jBoolean IsPointBlighted(jReal*, jReal*);

jNothing SetDoodadAnimation(jReal*, jReal*, jReal*, jInteger, jBoolean, jString, jBoolean);

jNothing SetDoodadAnimationRect(HRECT, jInteger, jString, jBoolean);

jNothing StartMeleeAI(HPLAYER, jString);

jNothing StartCampaignAI(HPLAYER, jString);

jNothing CommandAI(HPLAYER, jInteger, jInteger);

jNothing PauseCompAI(HPLAYER, jBoolean);

HAIDIFFICULTY  GetAIDifficulty(HPLAYER);

jNothing RemoveGuardPosition(HUNIT);

jNothing RecycleGuardPosition(HUNIT);

jNothing RemoveAllGuardPositions(HPLAYER);

jNothing ExecuteFunc(jString);

jNothing Cheat(jString);

jBoolean IsNoVictoryCheat();

jBoolean IsNoDefeatCheat();

jNothing Preload(jString);

jNothing PreloadEnd(jReal*);

jNothing PreloadStart();

jNothing PreloadRefresh();

jNothing PreloadEndEx();

jNothing PreloadGenStart();

jNothing PreloadGenClear();

jNothing PreloadGenEnd(jString);

jNothing Preloader(jString);

