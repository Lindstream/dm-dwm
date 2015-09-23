Dream Machine - DWM
==============================
dwm is an extremely fast, small, and dynamic window manager for X. 

Based of DWM 6.1 head from 2015-03-13 (commit 14343e69cc5), tweaked and configured to personal preference.

This is part of Lindstreams Dream Machine, read more @ link.

Everything listed is implemented and working. 
BUGS are listed in BUGS ;)

Screenshots
----
**Clean**
![dream-machine-theme](https://raw.githubusercontent.com/Lindstream/dm-dwm/master/screenshot1.jpg)


**Dirty**
![dream-machine-theme](https://raw.githubusercontent.com/Lindstream/dm-dwm/master/screenshot2.jpg)

Patches
----------------------------
* **Dwmfifo**    
  Best thing since sliced bread, this patch adds a FIFO command/controller (/tmp/dwm.fifo) to exec keybind actions through CLI.

* **Hide vacant tags**  
  Pretty self-explanatory :)

* **Statusallmons**  
  Makes the statusbar available on all displays.

* **Runorraise**  
  Allows you to map frequently used apps to a key combo that will launch the application if it's not already running - otherwise bring the running session into focus. Great stuff to use with browsers and notes.  
  * Now checks for window title aswell as names
  * If application is running on the current monitor then bring it up. If not: scan and toggle all matches on all monitors. If no matches are found: exec! 

* **Save_floats**  
  Makes dwm remember the floating position and window size before things are tiled, and restores them appropriately.

* **Bottom stack**  
  Nowamore nicknamed htile

* **Center**  
  Adds an "iscentered" rule to automatically center clients on the current monitor.

* **Statuscolors**  
  Adds a few more colors to dwm's palette. 

* **Focusmaster**  
  Super + ShiftR takes you back to your master client.

* **Uselessgaps**  
  Adds the possibility to gap windows, also takes care of border in monocle and fullscreen mode.

* **Emptyview**  
  There's something annoying about not being able to toggle that last tag out of view.. 

* **Push up/down**  
  Allows you to move clients around the stack.

* **Tagintostack**  
  Allways attach clients to the stack area when toggling tags.

* **Urgent border color**  
  Kinda neat on a multi-monitor setup.

* **Warp**  
  Makes the mouse cursor follow your focus.  
  * Added setting mousemove to config.h.  
  * Changed warp position to bottom right corner (-25px).  
  * Not triggered by motion anymore, only keys.

* **Attach aside**  
  New clients are attached and focused in stack area. 

Other tweaks
----------------------------
* **No title**  
  Who need titles anyway?

* **Keep tags**  
  Tags should be kept when moving clients between displays.

* **Followfocus**  
  You allways travel with the selected client when sending them between your monitors.

* **Raise tags**  
  * Activate view if not active when moving clients between displays
  * Activate view if client isn't visible after launch

* **Borders & gaps**  
  * Single screen: borders & gaps hidden on single client and in monocle mode.
  * Multi-screen: borders always shown, gaps hidden in monocle and on single client. 

* **Layout first**  
  Layout icon is shown first in menu and has its own colorsettings

* **Not occupied**  
  Special color when tags are active but unoccupied (removed rect-indicator)

* **Bucket**  
  Bucket (tag 1) new clients when no other rules apply (configurable). 

* **Ordered rules**  
  Matching Class appends tag to clients, Matching Titles assigns that single tag.  

* **Bar opacity**

* **Setting for monoclecounter**

Dirty polish
----------------------------
* **Separators between tags**  
  Hardcoded colors in drw > drw_sep()

* **Top line**  
  Hardcoded colors in drw > drw_topsep()