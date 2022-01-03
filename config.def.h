// See LICENSE file for copyright and license details. 
#include <X11/XF86keysym.h>

// pywal colors 
#include "/home/rbt/.cache/wal/colors-wal-dwm.h"

// appearance 
static const int user_bh 			= 50; 		// bar height 
static const unsigned int borderpx  = 5;        // border pixel of windows 
static const unsigned int gappx     = 5;        // gaps between windows 
static const unsigned int snap      = 32;       // snap pixel 
static const int showbar            = 1;        // 0 means no bar 
static const int topbar             = 1;        // 0 means bottom bar 
static const char *fonts[]          = { "OverpassMono Nerd Font=12" };
static const char dmenufont[]       = "OverpassMono Nerd Font:size=12";

// layout(s) 
static const float mfact     		= 0.55; 	// factor of master area size [0.05..0.95] 
static const int nmaster     		= 1;    	// number of clients in master area 
static const int resizehints 		= 1;    	// 1 means respect size hints in tiled resizals 

// tagging 
static const char *tags[] 			= { "•", "•", "•", "•", "•" };

// rules

static const Rule rules[] = {
	/* class              	 instance    title       tags mask   isfloating    monitor */
	{ "firefox",          	NULL,       NULL,       2,       		0,           	1 },
  	{ "telegram-desktop", NULL,       NULL,       5,          	  0,              1 }
};

// keys
static Key keys[0];

static const Layout layouts[] = {
	// symbol     arrange function 
	{ "[t]",      tile },    					// first entry is default 
	{ "[f]",      NULL },    					// no layout function means floating behavior 
	{ "[m]",      monocle },					// full screen behavior
};

// key definitions 
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

// helper for spawning shell commands in the pre dwm-5.0 fashion 
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// button definitions 
static Button buttons[] = {
	// click                event mask      button          function        argument 
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

// void
// moveWindow(const Arg *arg)
// {
// 	movemouse(&((Arg) {0})
// }

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

// signal definitions 
static Signal signals[] = {
	// signum           function 
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex }
};
