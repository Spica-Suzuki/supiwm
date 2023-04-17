#ifndef CONFIG_H
#define CONFIG_H

static const char *termcmd[] = { "urxvt-tabbed",    NULL };
static const char *menucmd[] = { "dmenu_run",       NULL };
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}


#define MASTER_SIZE     0.52
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False means panel is on bottom */
#define PANEL_HEIGHT    0       /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    TILE      /* initial layout/mode: TILE MONOCLE BSTACK GRID FLOAT */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_WINDOW   False     /* follow the window when moved to a different desktop */
#define FOLLOW_MOUSE    False     /* focus the window the mouse just entered */
#define CLICK_TO_FOCUS  True      /* focus an unfocused window when clicked  */
#define FOCUS_BUTTON    Button3   /* mouse button to be used along with CLICK_TO_FOCUS */
#define BORDER_WIDTH    0         /* window border width */
#define MINWSZ          50        /* minimum window size in pixels  */
#define DEFAULT_DESKTOP 0         /* the desktop to focus initially */

#define DESKTOPS        6
#define DESKTOPCHANGE(K,N) \
    {  Mod4Mask,             K,              change_desktop, {.i = N}}, \
    {  Mod4Mask|ShiftMask,   K,              client_to_desktop, {.i = N}},

static Key keys[] = {
    /* modifier                  key            function           argument */
    {  Mod4Mask,                 XK_BackSpace,  focusurgent,       {NULL}},
    {  Mod4Mask|ShiftMask,       XK_q,          killclient,        {NULL}},

    {  Mod4Mask|ShiftMask,       XK_t,          switch_mode,       {.i = TILE}},
    {  Mod4Mask|ShiftMask,       XK_m,          switch_mode,       {.i = MONOCLE}},
    {  Mod4Mask|ShiftMask,       XK_f,          switch_mode,       {.i = FLOAT}},
    {  Mod4Mask|ShiftMask,       XK_e,          quit,              {.i = 0}},
    {  Mod4Mask,       XK_Return,     spawn,             {.com = termcmd}},
    {  Mod4Mask,                 XK_v,          spawn,             {.com = menucmd}},
       DESKTOPCHANGE(    XK_1,                             0)
       DESKTOPCHANGE(    XK_2,                             1)
       DESKTOPCHANGE(    XK_3,                             2)
       DESKTOPCHANGE(    XK_4,                             3)
       DESKTOPCHANGE(    XK_5,                             4)
       DESKTOPCHANGE(    XK_6,                             5)
       DESKTOPCHANGE(    XK_7,                             6)
       DESKTOPCHANGE(    XK_8,                             7)
       DESKTOPCHANGE(    XK_9,                             8)
       DESKTOPCHANGE(    XK_0,                             9)
};

static Button buttons[] = {
    {  Mod4Mask,    Button1,     mousemotion,   {.i = MOVE}},
    {  Mod4Mask,    Button3,     mousemotion,   {.i = RESIZE}},
    {  Mod1Mask,    Button3,     spawn,         {.com = menucmd}},
};



#endif
