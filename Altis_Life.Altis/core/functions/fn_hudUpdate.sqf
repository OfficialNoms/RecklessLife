#include "..\..\script_macros.hpp"
/*
    File: fn_hudUpdate.sqf
    Original Author: Daniel Stuart
    Modified by: noms (or noah👬  depending on who you ask...)
    Description:
    Updates the HUD when it needs to.
*/
disableSerialization;

if (isNull LIFEdisplay) then {[] call life_fnc_hudSetup;};
 

//Set Progress Bar for LIFE variables
LIFEctrl(2200) progressSetPosition (life_hunger / 100);
LIFEctrl(2201) progressSetPosition (1 - (damage player));
LIFEctrl(2202) progressSetPosition (life_thirst / 100);
//Background for LIFE variables
LIFEctrl(9400) progressSetPosition (1);
LIFEctrl(9401) progressSetPosition (1);
LIFEctrl(9402) progressSetPosition (1);
//Text values for LIFE variables
LIFEctrl(9600) ctrlSetText format["%1%2",life_hunger,"%"];
LIFEctrl(9601) ctrlSetText format["%1%2",round(100-((damage player) * 100)),"%"];
LIFEctrl(9602) ctrlSetText format["%1%2",life_thirst,"%"];
//Change colour of bars if they are low
if(life_hunger < 0.3) then
{ LIFEctrl(2200) ctrlSetBackgroundColor [255,0,0,0.4];};
if((damage player) < 0.3) then
{ LIFEctrl(2201) ctrlSetBackgroundColor [255,0,0,0.4];};
if((life_thirst) < 0.3) then
{ LIFEctrl(2202) ctrlSetBackgroundColor [255,0,0,0.4];};

if(life_settings_enableHUDStats) then
{
  LIFEctrl(1203) ctrlSetText format["Reckless Life v1.3"];
  LIFEctrl(1204) ctrlSetText "FPS:";
  LIFEctrl(1205) ctrlSetText "UPTIME:";
  LIFEctrl(1206) ctrlSetText "GRIDREF:";
  LIFEctrl(1207) ctrlSetText "CASH:";
  LIFEctrl(1208) ctrlSetText "BANK:";
  LIFEctrl(1209) ctrlSetText "COPS:";
  LIFEctrl(1210) ctrlSetText "CIVILIANS:";
  LIFEctrl(1211) ctrlSetText "MEDICS:";
  LIFEctrl(1212) ctrlSetText "WANTED STATUS:";
  LIFEctrl(9613) ctrlSetText format["%1",round diag_fps];
  LIFEctrl(9614) ctrlSetText format["%1",[time,"HH:MM:SS"] call BIS_fnc_secondsToString];
  LIFEctrl(9606) ctrlSetText format["%1",mapGridPosition player];
  LIFEctrl(9607) ctrlSetText format["%1",[life_cash] call life_fnc_numberText];
  LIFEctrl(9608) ctrlSetText format["%1",[life_atmbank] call life_fnc_numberText];
  LIFEctrl(9609) ctrlSetText format["%1",west countSide playableUnits];
  LIFEctrl(9610) ctrlSetText format["%1",civilian countSide playableUnits];
  LIFEctrl(9611) ctrlSetText format["%1",independent countSide playableUnits];
  LIFEctrl(9612) ctrlSetText format["COMING SOON"];
}
else
{
  LIFEctrl(1203) ctrlSetText format["Press Shift + B Enable Extended HUD Stats"];
  LIFEctrl(9604) ctrlSetText "";
  LIFEctrl(9605) ctrlSetText "";
  LIFEctrl(9606) ctrlSetText "";
  LIFEctrl(9607) ctrlSetText "";
  LIFEctrl(9608) ctrlSetText "";
  LIFEctrl(9609) ctrlSetText "";
  LIFEctrl(9610) ctrlSetText "";
  LIFEctrl(9611) ctrlSetText "";
  LIFEctrl(9612) ctrlSetText "";
  LIFEctrl(1204) ctrlSetText "";
  LIFEctrl(1205) ctrlSetText "";
  LIFEctrl(1206) ctrlSetText "";
  LIFEctrl(1207) ctrlSetText "";
  LIFEctrl(1208) ctrlSetText "";
  LIFEctrl(1209) ctrlSetText "";
  LIFEctrl(1210) ctrlSetText "";
  LIFEctrl(1211) ctrlSetText "";
  LIFEctrl(1212) ctrlSetText "";
};


/* USE IF USING MY XP SYSTEM
============================================================================*/

if(life_settings_enableHUDStats) then
{
  LIFEctrl(2203) progressSetPosition (life_level_percentToNextLevel / 100);
  LIFEctrl(9403) progressSetPosition (1);
  LIFEctrl(9603) ctrlSetText format["%1 / %2", life_xp_currentXPToNextLevel,life_xp_XPToNextLevel]; // XP needed to next level
  LIFEctrl(9604) ctrlSetText format["LEVEL %1", life_level];  //Current Level
  LIFEctrl(9605) ctrlSetText format["LEVEL %1",(life_level+1)]; //Next Level
  LIFEctrl(9700) ctrlSetText format["LEVEL"];
}
else
{
  LIFEctrl(2203) progressSetPosition (0);
  LIFEctrl(9403) progressSetPosition (0);
  LIFEctrl(9603) ctrlSetText "";
  LIFEctrl(9604) ctrlSetText "";
  LIFEctrl(9605) ctrlSetText "";
  LIFEctrl(9700) ctrlSetText "";
};
/*=========================================================================*/
