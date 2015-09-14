/* See LICENSE file for copyright and license details. */
/* MBP MB-mappings */
#define XF86MonBrightnessDown   0x1008ff03
#define XF86MonBrightnessUp     0x1008ff02
#define XF86LauncherKB1         0x1008ff4a
#define XF86LauncherKB2         0x1008ff4b
#define XF86KbdBrightnessDown   0x1008ff06
#define XF86KbdBrightnessUp     0x1008ff05
#define XF86AudioPrev           0x1008ff16
#define XF86AudioPlay           0x1008ff14
#define XF86AudioNext           0x1008ff17
#define XF86AudioMute           0x1008ff12
#define XF86AudioLowerVolume    0x1008ff11
#define XF86AudioRaiseVolume    0x1008ff13

/* appearance */
static const char *fonts[] = {
    "AnonMix:size=11",
    "Andale Mono-9:style=bold",
};
#define NUMCOLORS 9

static const char colors[NUMCOLORS][MAXCOLORS][8] = {
   // border   foreground  background
   { "#282828", "#887e75", "#181818" },  // 0 = base
   { "#dc9656", "#d6b89c", "#0f0f0f" },  // 1 = active
   { "#dc9656", "#dc9656", "#0f0f0f" },  // 2 = selected
   { "#ff0000", "#d6d47a", "#181818" },  // 3 = urgent
   { "#ff0000", "#cc5157", "#181818" },  // 4 = error
   { "#ff0000", "#887e75", "#181818" },  // 5 = layout
   { "#ff0000", "#444444", "#181818" },  // 6 = inactive
   { "#ff9900", "#887e75", "#282828" },  // 7 = dmenu - normal
   { "#ff9900", "#dc9656", "#231c01" },  // 8 = dmenu - selected
   // add more here
};

static const unsigned int barpadding      = 12;       /* adds top padding to bar */
static const unsigned int tagpadding      = 0;        /* adds padding to tags */
static const unsigned int ltmargin        = 12;       /* adds right margin to lticon */
static const unsigned int borderpx        = 3;        /* border pixel of windows */
static const unsigned int snap            = 32;       /* snap pixel */
static const Bool showbar                 = True;     /* False means no bar */
static const Bool topbar                  = False;    /* False means bottom bar */
static const unsigned int gappx           = 1;        /* gap pixel between windows */
static const Bool monoclecount            = False;    /* show no. of clients in monocle layout */
static const Bool warpmouse               = True;     /* warp mouse pointer to focused client */

/* tagging */
static const char *tags[] = {
    "1 \uE60D  ", /* 01 - misc */
    "2 \uE68B  ", /* 02 - web */
    "3 \uE685  ", /* 03 - dev */
    "4 \uE67D  ", /* 04 - text */
    "5 \uE61C  ", /* 05 - music */
    "6 \uE6CD  ", /* 06 - media */ 
    "7 \uE6CB  ", /* 07 - files & transfers */
    "8 \uE71D  ", /* 08 - chats */
    "9 \uE6CC  ", /* 09 - news & mail */
};

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class               instance    title              tags mask     iscentered  isfloating   monitor */
  { "CherryTree",        NULL,       NULL,              1 << 3,       False,      False,        1 },
  { "Deadbeef",          NULL,       NULL,              1 << 4,       False,      False,        1 },
  { "Deluge",            NULL,       NULL,              1 << 7,       False,      False,        1 },
  { "Firefox",           NULL,       NULL,              1 << 1,       False,      False,        1 },
  { "Chromium",          NULL,       NULL,              1 << 1,       False,      False,        1 },
  { "Termite",           NULL,       "weechat",         1 << 7,       False,      False,        2 },
  {  NULL,               NULL,       "cmus",            1 << 4,       False,      False,        2 },
  {  NULL,               NULL,       "canto",           1 << 8,       False,      False,        2 },
  {  NULL,               NULL,       "glances",         1 << 4,       False,      False,        1 },
  { "Subl3",             NULL,       NULL,              1 << 2,       False,      False,        1 },
  { "GIMP",              NULL,       NULL,              1 << 4,       False,      False,        0 },
};

/* layout(s) */
static const float mfact      = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\uE701",      tile },    /* first entry is default */
  { "\uE6FE",      monocle }, /* monocle */
	{ "\uE6FF",      NULL },    /* float */
  { "\uE700",      htile },   /* bottom stack */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* dmenu */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char dmenu_width[]    = "500"; 
static const char dmenu_lheight[]  = "32";  
static const char dmenu_lines[]    = "8";

/* commands */
static const char *cmd_browser[] = { "firefox", NULL, NULL, NULL, "Firefox" };
static const char *cmd_canto[] = { "termite", "--title", "canto", "-e", "canto-curses", NULL, NULL, NULL,  "canto" };
static const char *cmd_cherrytree[] = { "cherrytree", NULL, NULL, NULL, "CherryTree" };
static const char *cmd_clipmenu[] = { "clipmenu", "-m", dmenumon, "-w", dmenu_width, "-lh", dmenu_lheight, "-l", dmenu_lines, "-nb", colors[7][2], "-nf", colors[7][1], "-sb", colors[8][2], "-sf", colors[8][1], "-centerx", "-centery", NULL };
static const char *cmd_cmus[] = { "termite", "--title", "cmus", "-e", "cmus", NULL, NULL, NULL,  "cmus" };
static const char *cmd_chrome[] = { "chromium", NULL, NULL, NULL, "Chromium" };
static const char *cmd_deluge[] = { "deluge-gtk", NULL, NULL, NULL, "Deluge" };
static const char *cmd_dmenu[] = { "launcher", dmenumon, "dmenu", "-m", dmenumon, "-w", dmenu_width, "-lh", dmenu_lheight, "-l", dmenu_lines, "-nb", colors[7][2], "-nf", colors[7][1], "-sb", colors[8][2], "-sf", colors[8][1], "-centerx", "-centery", NULL };
static const char *cmd_passmenu[] = { "passmenu", "-m", dmenumon, "-w", dmenu_width, "-lh", dmenu_lheight, "-l", dmenu_lines, "-nb", colors[7][2], "-nf", colors[7][1], "-sb", colors[8][2], "-sf", colors[8][1], "-centerx", "-centery", NULL };
static const char *cmd_sublime[] = { "subl3", NULL, NULL, NULL, "Subl3" };
static const char *cmd_term[]  = { "termite", NULL };
static const char *cmd_weechat[]  = { "termite", "--title", "weechat", "-e", "weechat", NULL, NULL, NULL,  "weechat" };

/* KB functions */
static const char *kb_audio_prev[] = { "deadbeef", "--prev", NULL };
static const char *kb_audio_play[] = { "deadbeef", "--play-pause", NULL };
static const char *kb_audio_next[] = { "deadbeef", "--next", NULL };
static const char *kb_audio_mute[] = { "pulseaudio-ctl", "mute", NULL };
static const char *kb_audio_vold[] = { "pulseaudio-ctl", "down", NULL };
static const char *kb_audio_volu[] = { "pulseaudio-ctl", "up", NULL };
static const char *kb_backlightdec[] = { "xbacklight", "-dec", "2", NULL };
static const char *kb_backlightinc[] = { "xbacklight", "-inc", "10", NULL };
static const char *kb_launcher1[] = { "xbacklight", "-dec", "10", NULL };
static const char *kb_launcher2[] = { "togglepad", NULL, NULL };
static const char *kb_lightoff[] = { "keyboard_actions/fn_kbd_backlight_off", NULL };
static const char *kb_lighton[] = { "keyboard_actions/fn_kbd_backlight_on", NULL };


static Key keys[] = {
	/* modifier                     key        function        argument */
	
	/* Commands */
  { MODKEY,                       XK_space,   spawn,          {.v = cmd_dmenu } },
	{ MODKEY,                       XK_v,       spawn,          {.v = cmd_clipmenu } },
	{ MODKEY|ShiftMask,             XK_Return, 	spawn,          {.v = cmd_term } },
	{ MODKEY,			                  XK_x, 	   	runorraise,     {.v = cmd_browser } },
	
	/* General */
	{ MODKEY|ShiftMask,             XK_b,      	togglebar,      {0} },
	{ MODKEY,                       XK_Return, 	zoom,           {0} },
	{ MODKEY,                       XK_Tab,    	view,           {0} },
	{ MODKEY,			                  XK_q,      	killclient,     {0} },
	{ MODKEY,                       XK_0,      	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      	tag,            {.ui = ~0 } },
	{ MODKEY,             			    XK_minus,   incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_minus,   incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      	setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,       setmfact,       {.f = +0.05} }, 
  { MODKEY,                       XK_j,       pushdown,       {.f = +0.05} }, 
	{ MODKEY,                       XK_k,      	pushup,         {.f = +0.05} },	
	{ MODKEY,                       XK_comma,  	focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period,  focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_Shift_R, focusmaster,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,          	  XK_period, 	tagmon,         {.i = +1 } },
	
	/* Layouts */
	{ MODKEY,                       XK_t,      	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      	setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_m,       setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_b,      	setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_z,  		  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_f,  		  togglefloating, {0} },

	/* Sloppy bindings to switch focus */ 
	{ MODKEY,           			XK_Right,         focusstack,     {.i = +1 } },
  { MODKEY,           			XK_Left,          focusstack,     {.i = -1 } },
  { MODKEY,           			XK_Down,          focusstack,     {.i = +1 } },
  { MODKEY,           			XK_Up,            focusstack,     {.i = -1 } },
  { MODKEY,           			XK_d,             focusstack,     {.i = +1 } },
  { MODKEY,          				XK_a,             focusstack,     {.i = -1 } },
  { MODKEY,           			XK_s,             focusstack,     {.i = +1 } },
  { MODKEY,           			XK_w,             focusstack,     {.i = -1 } },
	
	/* MBP Mappings */ 
	{ 0, XF86MonBrightnessUp,  				   	spawn,          {.v = kb_backlightinc } },
  { 0, XF86MonBrightnessDown,				   	spawn,         	{.v = kb_backlightdec } },
  { 0, XF86KbdBrightnessUp,  				   	spawn,          {.v = kb_lighton } },
  { 0, XF86KbdBrightnessDown,				   	spawn,          {.v = kb_lightoff } },
  { 0, XF86AudioPrev,        				   	spawn,          {.v = kb_audio_prev } },
  { 0, XF86AudioPlay,        				   	spawn,          {.v = kb_audio_play } },
  { 0, XF86AudioNext,        				   	spawn,          {.v = kb_audio_next } },
  { 0, XF86AudioMute,        				   	spawn,          {.v = kb_audio_mute } },
  { 0, XF86AudioLowerVolume, 				   	spawn,          {.v = kb_audio_vold } },
  { 0, XF86AudioRaiseVolume, 				   	spawn,          {.v = kb_audio_volu } },
  { 0, XF86LauncherKB1,                 spawn,          {.v = kb_launcher1 } },
  { 0, XF86LauncherKB2,          			  spawn,          {.v = kb_launcher2 } },

  /* Forever alone, quits. */
  { MODKEY|ShiftMask,             XK_q,		    quit,         {0} },

    /* Tags */ 
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};


/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = cmd_term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *dwmfifo = "/tmp/dwm.fifo";
static Command commands[] = {
   { "cmd_browser",     runorraise,     {.v = cmd_browser} },
   { "cmd_canto",       runorraise,     {.v = cmd_canto} },
   { "cmd_cherrytree",  runorraise,     {.v = cmd_cherrytree} },
   { "cmd_clipmenu",    spawn,          {.v = cmd_clipmenu} },
   { "cmd_cmus",        runorraise,     {.v = cmd_cmus} },
   { "cmd_chrome",      runorraise,     {.v = cmd_chrome} },
   { "cmd_deluge",      runorraise,     {.v = cmd_deluge} },
   { "cmd_dmenu",       spawn,          {.v = cmd_dmenu} },
   { "cmd_passmenu",    spawn,          {.v = cmd_passmenu} },
   { "cmd_sublime",     runorraise,     {.v = cmd_sublime} },
   { "cmd_term",        spawn,          {.v = cmd_term} },
   { "cmd_weechat",     runorraise,     {.v = cmd_weechat} },
   { "togglebar",       togglebar,      {0} },
   { "killclient",      killclient,     {0} },
   { "setlayout-tiled", setlayout,      {.v = &layouts[0]} },
   { "setlayout-float", setlayout,      {.v = &layouts[2]} },
   { "setlayout-mono",  setlayout,      {.v = &layouts[1]} },
   { "setlayout-htile", setlayout,      {.v = &layouts[3]} },
   { "togglefloating",  togglefloating, {0} },
   { "viewall",         view,           {.ui = ~0} },
   { "viewnone",        view,           {.ui = 0} },
   { "focusmon+",       focusmon,       {.i = +1} },
   { "focusmon-",       focusmon,       {.i = -1} },
   { "tagmon+",         tagmon,         {.i = +1} },
   { "tagmon-",         tagmon,         {.i = -1} },
   { "view1",           view,           {.ui = 1 << 0} },
   { "view2",           view,           {.ui = 1 << 1} },
   { "view3",           view,           {.ui = 1 << 2} },
   { "view4",           view,           {.ui = 1 << 3} },
   { "view5",           view,           {.ui = 1 << 4} },
   { "view6",           view,           {.ui = 1 << 5} },
   { "view7",           view,           {.ui = 1 << 6} },
   { "view8",           view,           {.ui = 1 << 7} },
   { "view9",           view,           {.ui = 1 << 8} },
   { "toggleview1",     toggleview,     {.ui = 1 << 0} },
   { "toggleview2",     toggleview,     {.ui = 1 << 1} },
   { "toggleview3",     toggleview,     {.ui = 1 << 2} },
   { "toggleview4",     toggleview,     {.ui = 1 << 3} },
   { "toggleview5",     toggleview,     {.ui = 1 << 4} },
   { "toggleview6",     toggleview,     {.ui = 1 << 5} },
   { "toggleview7",     toggleview,     {.ui = 1 << 6} },
   { "toggleview8",     toggleview,     {.ui = 1 << 7} },
   { "toggleview9",     toggleview,     {.ui = 1 << 8} },
   { "tag1",            tag,            {.ui = 1 << 0} },
   { "tag2",            tag,            {.ui = 1 << 1} },
   { "tag3",            tag,            {.ui = 1 << 2} },
   { "tag4",            tag,            {.ui = 1 << 3} },
   { "tag5",            tag,            {.ui = 1 << 4} },
   { "tag6",            tag,            {.ui = 1 << 5} },
   { "tag7",            tag,            {.ui = 1 << 6} },
   { "tag8",            tag,            {.ui = 1 << 7} },
   { "tag9",            tag,            {.ui = 1 << 8} },
   { "toggletag1",      toggletag,      {.ui = 1 << 0} },
   { "toggletag2",      toggletag,      {.ui = 1 << 1} },
   { "toggletag3",      toggletag,      {.ui = 1 << 2} },
   { "toggletag4",      toggletag,      {.ui = 1 << 3} },
   { "toggletag5",      toggletag,      {.ui = 1 << 4} },
   { "toggletag6",      toggletag,      {.ui = 1 << 5} },
   { "toggletag7",      toggletag,      {.ui = 1 << 6} },
   { "toggletag8",      toggletag,      {.ui = 1 << 7} },
   { "toggletag9",      toggletag,      {.ui = 1 << 8} },
};