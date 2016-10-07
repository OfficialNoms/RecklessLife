#define ST_CENTER         0x02    //Defines center alignment for text
#define ST_LEFT           0x00    //Defines left alignment for text
#define ST_RIGHT          0x01    //Defines right alignment for text
#define WATERMARK_Y       0.55     //The y value (vertical position) of the watermark
#define HEALTH_Y          0.280   //The y value (vertical position) of player health bar
#define FOOD_Y            0.235   //The y value (vertical position) of food bar
#define WATER_Y           0.190   //The y value (vertical position) of water bar
#define XP_Y              0.145    //The y value (vertical position) of the XP/level bar (optional - if you use my XP system)
#define VERSION_Y         1.9
#define FPS_Y             1.855
#define UPTIME_Y          1.81
#define GRIDREF_Y         1.765
#define CASH_Y            1.72
#define BANK_Y            1.675
#define CIVILIANS_Y       1.63
#define COPS_Y            1.585
#define MEDICS_Y          1.54
#define WANTED_Y          1.495
#define BAR_W             0.35    //The width of bars
#define BAR_H             0.035   //The height of bars
/*
    Original Author: Daniel Stuart
    Modified by: noms (or noah👬  depending on who you ask...)
    File: hud_stats.hpp
*/

class playerHUD {
    idd = -1;
    duration = 10e10;
    movingEnable = 0;
    fadein = 0;
    fadeout = 0;
    name = "playerHUD";
    onLoad = "uiNamespace setVariable ['playerHUD',_this select 0]";
    objects[] = {};
    controls[] = {
        Life_RscProgress_HUDFood,
        Life_RscProgress_HUDHealth,
        Life_RscProgress_HUDWater,
        Life_RscProgress_HUDXP,
        Life_RscProgress_HUDFoodBack,
        Life_RscProgress_HUDHealthBack,
        Life_RscProgress_HUDWaterBack,
        Life_RscProgress_HUDXPBack,
        Life_RscText_HUDFood,
        Life_RscText_HUDHealth,
        Life_RscText_HUDWater,
        Life_RscText_HUDFoodVal,
        Life_RscText_HUDHealthVal,
        Life_RscText_HUDWaterVal,
        Life_RscText_HUDXPCenter,
        Life_RscText_HUDXPLeft,
        Life_RscText_HUDXPRight,
        Life_RscText_HUDXPLabel,
        Life_RscPicture_Watermark,
        Life_RscText_FPS,
        Life_RscText_Uptime,
        Life_RscText_GRIDREF,
        Life_RscText_CASH,
        Life_RscText_BANK,
        Life_RscText_OnlineCivilians,
        Life_RscText_OnlineCops,
        Life_RscText_OnlineMedics,
        Life_RscText_Wanted,
        Life_RscText_Version,
        Life_RscText_FPSVal,
        Life_RscText_UptimeVal,
        Life_RscText_GRIDREFVal,
        Life_RscText_CASHVal,
        Life_RscText_BANKVal,
        Life_RscText_OnlineCiviliansVal,
        Life_RscText_OnlineCopsVal,
        Life_RscText_OnlineMedicsVal,
        Life_RscText_WantedVal
    };
    /* Progress Bars */
    //Define a common Progress Bar to use
    class LIFE_RscProgress_HUDCommon: Life_RscProgress {
        colorFrame[] = {0,0,0,0};
        x = safeZoneX + safeZoneW - (BAR_W + 0.01);
        y = safeZoneY + safeZoneH - 0.325;
        w = BAR_W;
        h = BAR_H;
    };

    class Life_RscProgress_HUDFood: LIFE_RscProgress_HUDCommon {
        idc = 2200;
        colorBar[] = {0.2,0.8,0.2,0.6};
        y = safeZoneY + safeZoneH - FOOD_Y;
    };
    class Life_RscProgress_HUDHealth: LIFE_RscProgress_HUDCommon {
        idc = 2201;
        colorBar[] = {0.8,0.2,0.2,0.6};
        y = safeZoneY + safeZoneH - HEALTH_Y;
    };
    class Life_RscProgress_HUDWater: LIFE_RscProgress_HUDCommon {
        idc = 2202;
        colorBar[] = {0.2,0.2,0.8,0.6};
        y = safeZoneY + safeZoneH - WATER_Y;
    };

    /* Bar Backgrounds */
    // These are for setting a background color to the bars
    class Life_RscProgress_HUDFoodBack: LIFE_RscProgress_HUDCommon {
        idc = 9400;
        colorBar[] = {0.2,0.2,0.2,0.2};
        y = safeZoneY + safeZoneH - FOOD_Y;
    };
    class Life_RscProgress_HUDHealthBack: LIFE_RscProgress_HUDCommon {
        idc = 9401;
        colorBar[] = {0.2,0.2,0.2,0.2};
        y = safeZoneY + safeZoneH - HEALTH_Y;
    };
    class Life_RscProgress_HUDWaterBack: LIFE_RscProgress_HUDCommon {
        idc = 9402;
        colorBar[] = {0.2,0.2,0.2,0.2};
        y = safeZoneY + safeZoneH - WATER_Y;
    };

    /* Texts */
    class Life_RscText_HUDCommon: Life_RscText {
        SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
        x = safeZoneX + safeZoneW - (BAR_W + 0.01);
        w = BAR_W;
        h = BAR_H;
    };
    class Life_RscText_HUDFood: Life_RscText_HUDCommon {
        idc = 1200;
        style = ST_LEFT;
        text = "$STR_HUD_Food";
        y = safeZoneY + safeZoneH - FOOD_Y;
    };
    class Life_RscText_HUDHealth: Life_RscText_HUDCommon {
        idc = 1201;
        style = ST_LEFT;
        text = "$STR_HUD_Health";
        y = safeZoneY + safeZoneH - HEALTH_Y;
    };
    class Life_RscText_HUDWater: Life_RscText_HUDCommon {
        idc = 1202;
        style = ST_LEFT;
        text = "$STR_HUD_Water";
        y = safeZoneY + safeZoneH - WATER_Y;
    };
    class Life_RscText_Version: Life_RscText_HUDCommon {
        idc = 1203;
        style = ST_CENTER;
        text = "Reckless Life v1.3";
        y = safeZoneY + safeZoneH - VERSION_Y;
    };
    class Life_RscText_FPS: Life_RscText_HUDCommon {
        idc = 1204;
        style = ST_LEFT;
        text = "FPS:";
        y = safeZoneY + safeZoneH - FPS_Y;
    };
    class Life_RscText_Uptime: Life_RscText_HUDCommon {
        idc = 1205;
        style = ST_LEFT;
        text = "Uptime:";
        y = safeZoneY + safeZoneH - UPTIME_Y;
    };
    class Life_RscText_GRIDREF: Life_RscText_HUDCommon {
        idc = 1206;
        style = ST_LEFT;
        text = "GRIDREF:";
        y = safeZoneY + safeZoneH - GRIDREF_Y;
    };
    class Life_RscText_CASH: Life_RscText_HUDCommon {
        idc = 1207;
        style = ST_LEFT;
        text = "CASH:";
        y = safeZoneY + safeZoneH - CASH_Y;
    };
    class Life_RscText_BANK: Life_RscText_HUDCommon {
        idc = 1208;
        style = ST_LEFT;
        text = "BANK:";
        y = safeZoneY + safeZoneH - BANK_Y;
    };
    class Life_RscText_OnlineCops: Life_RscText_HUDCommon {
        idc = 1209;
        style = ST_LEFT;
        text = "Cops:";
        y = safeZoneY + safeZoneH - COPS_Y;
    };
    class Life_RscText_OnlineCivilians: Life_RscText_HUDCommon {
        idc = 1210;
        style = ST_LEFT;
        text = "Civilians:";
        y = safeZoneY + safeZoneH - CIVILIANS_Y;
    };
    class Life_RscText_OnlineMedics: Life_RscText_HUDCommon {
        idc = 1211;
        style = ST_LEFT;
        text = "Medics:";
        y = safeZoneY + safeZoneH - MEDICS_Y;
    };
    class Life_RscText_Wanted: Life_RscText_HUDCommon {
        idc = 1212;
        style = ST_LEFT;
        text = "WANTED STATUS:";
        y = safeZoneY + safeZoneH - WANTED_Y;
    };
    class Life_RscText_HUDFoodVal: Life_RscText_HUDCommon {
        idc = 9600;
        text = "";
        style = ST_RIGHT;
        y = safeZoneY + safeZoneH - FOOD_Y;
    };
    class Life_RscText_HUDHealthVal: Life_RscText_HUDCommon {
        idc = 9601;
        text = "";
        style = ST_RIGHT;
        y = safeZoneY + safeZoneH - HEALTH_Y;
    };
    class Life_RscText_HUDWaterVal: Life_RscText_HUDCommon {
        idc = 9602;
        text = "";
        style = ST_RIGHT;
        y = safeZoneY + safeZoneH - WATER_Y;
    };
    class Life_RscText_FPSVal: Life_RscText_HUDCommon {
        idc = 9613;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - FPS_Y;
    };
    class Life_RscText_UptimeVal: Life_RscText_HUDCommon {
        idc = 9614;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - UPTIME_Y;
    };
    class Life_RscText_GRIDREFVal: Life_RscText_HUDCommon {
        idc = 9606;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - GRIDREF_Y;
    };
    class Life_RscText_CASHVal: Life_RscText_HUDCommon {
        idc = 9607;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - CASH_Y;
    };
    class Life_RscText_BANKVal: Life_RscText_HUDCommon {
        idc = 9608;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - BANK_Y;
    };
    class Life_RscText_OnlineCopsVal: Life_RscText_HUDCommon {
        idc = 9609;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - COPS_Y;
    };
    class Life_RscText_OnlineCiviliansVal: Life_RscText_HUDCommon {
        idc = 9610;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - CIVILIANS_Y;
    };
    class Life_RscText_OnlineMedicsVal: Life_RscText_HUDCommon {
        idc = 9611;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - MEDICS_Y;
    };
    class Life_RscText_WantedVal: Life_RscText_HUDCommon {
        idc = 9612;
        style = ST_RIGHT;
        text = "";
        y = safeZoneY + safeZoneH - WANTED_Y;
    };

    /*USE IF YOU USE MY XP SYSTEM AND WOULD LIKE PROGRESS DISPLAYED ON SCREEN
    ==========================================================================*/
    class Life_RscProgress_HUDXP: LIFE_RscProgress_HUDCommon {
        idc = 2203;
        colorBar[] = {0.2,0.2,0.2,0.6};
        y = safeZoneY + safeZoneH - XP_Y;
    };
    class Life_RscProgress_HUDXPBack: LIFE_RscProgress_HUDCommon {
        idc = 9403;
        colorBar[] = {0.2,0.2,0.2,0.2};
        y = safeZoneY + safeZoneH - XP_Y;
    };
    class Life_RscText_HUDXPCenter: Life_RscText_HUDCommon {
        idc = 9603;
        text = "";
        style = ST_CENTER;
        y = safeZoneY + safeZoneH - XP_Y;
    };
    class Life_RscText_HUDXPLeft: Life_RscText_HUDCommon {
        idc = 9604;
        text = "";
        style = ST_LEFT;
        y = safeZoneY + safeZoneH - XP_Y;
    };
    class Life_RscText_HUDXPRight: Life_RscText_HUDCommon {
        idc = 9605;
        text = "";
        style = ST_RIGHT;
        y = safeZoneY + safeZoneH - XP_Y;
    };

    //Label for XP system
    class Life_RscText_HUDXPLabel: Life_RscText_HUDCommon {
        idc = 9700;
        x = safeZoneX + safeZoneW - (BAR_W - -0.16);
        y = safeZoneY + safeZoneH - XP_Y;
        w = 0.15;
        h = BAR_H;
        text = "";
        style = ST_RIGHT;
    };
    /*==========================================================================*/


    // Watermark
    class Life_RscPicture_Watermark: Life_RscPicture
    {
      idc = 9900;
      text = "watermark.paa";
      x = safeZoneX + safeZoneW -  (BAR_W + 0.01);
      y = safeZoneY + safeZoneH - WATERMARK_Y;
      w = BAR_W;
      h = 0.23; //height of the image (will take some trial and error as Arma does images on GUI in a weird way)
    };
};
