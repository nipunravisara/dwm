/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const int user_bh = 40; 			/* bar height */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int gappx     = 20;       /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "scientifica:size=12", "Material Icons:size=12" };
static const char dmenufont[]       = "monospace:size=12";

/* Pywal colors */
#include "/home/rbt/.cache/wal/colors-wal-dwm.h"

/* tagging */
/* static const char *tags[] = { "dev", "web", "file", "mus", "mon" }; */
static const char *tags[] = { "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "   ",      tile },    /* first entry is default */
	{ "   ",      NULL },    /* no layout function means floating behavior */
	{ "   [M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Rofi controls */
static const char *applicationmenu[]  = { "rofi", "-show", "drun", NULL };

/* Terminal control*/
static const char *termcmd[]  = { "alacritty", NULL };

/* Audio controls */
static const char *mutecmd[] = { "pamixer", "-t", NULL };
static const char *volupcmd[] = { "pamixer", "-i", "10", "0", NULL };
static const char *voldowncmd[] = { "pamixer", "-d", "10", "0", NULL };

/* Backlight conrol */
static const char *brightnessup[] = { "brightness", "up", NULL };
static const char *brightnessdown[] = { "brightness", "down", NULL };

/* Flameshot control */
static const char *flameshotgui[] = { "flameshot", "gui", NULL };

/* Lock screen control */
static const char *slock[] = { "slock" };

/* Wifi menu */
static const char *wifimenu[] = { "wifimenu" , NULL};

/* Theme switcher */
static const char *themeswitcher[] = { "themeswitcher" , NULL};

/* Eww contols */
static const char *openeww[] = {"eww", "open-many", "background", "profile", "time", "logout", "poweroff", "restart", "lock", "files", "code", "system", "twitter", "gmail", "firefox", "music", "memory", NULL};
static const char *closeeww[] = {"eww", "close-all", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Up,     setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Down,   setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = openeww} },
	{ MODKEY,                       XK_r,      spawn,          {.v = closeeww} },
	{ MODKEY,                       XK_a,      spawn,          {.v = themeswitcher} },
	{ MODKEY,                       XK_w,      spawn,          {.v = wifimenu } },
	{ MODKEY,                       XK_l,      spawn,          {.v = slock } },
	{ MODKEY,                       XK_d,      spawn,          {.v = applicationmenu } },
	{ MODKEY,                       XK_s,      spawn,          {.v = flameshotgui} },
	{ 0,                            XF86XK_AudioMute, spawn,   {.v = mutecmd } },
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = voldowncmd } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = volupcmd } },
	{ 0,                            XF86XK_MonBrightnessUp, spawn, {.v = brightnessup} },
	{ 0,                            XF86XK_MonBrightnessDown, spawn, {.v = brightnessdown} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

