Dream Machine - DWM
==============================
dwm is an extremely fast, small, and dynamic window manager for X. 

Based of DWM 6.1 head from 2015-03-13 (commit 14343e69cc5), tweaked and configured to personal preference.

This is part of Lindstreams Dream Machine, read more @ link.

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

* **Notitle**  
  Who need titles anyway?

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

* **Viewontag**  
  Follow a window to the tag it's being moved to, can't really decide on this one - option is set in config.h (needs fixing, indifferent to current tag status).

* **Emptyview**  
  There's something annoying about not being able to toggle that last tag out of view.. 

* **Push up/down**  
  Allows you to move clients around the stack.

* **Tagintostack**  
  Allways attach clients to the stack area when toggling tags.


Other tweaks
----------------------------
* **Keeptags**  
  Tags should be kept when moving clients between displays

* **Followfocus**  
  You allways travel with the selected client when sending them between your monitors.

* **Raisetags**  
  * Toggle view if not active when moving clients between display
  * Toggle view if client isn't visible after launch

* **Runorraise**  
  * Checks by window title aswell as names
  * If application is available on the current monitor then it's raised. If not, it will instead raise all matches on all the other monitors.

* **Borders & gaps**  
  * Single screen: borders & gaps hidden on single client and in monocle mode.
  * Multi-screen: borders always shown, gaps hidden in monocle and on single client. 

* **Layoutfirst**  
  Layout icon is shown first in menu and has its own colorsettings

* **Notoccupied**  
  Special color when tags are active but unoccupied (removed rect-indicator)

* **Setting for monoclecounter**


Dirty polish
----------------------------
* **separators between tags**  
  Hardcoded colors in drw > drw_sep()

* **top line**  
  Hardcoded colors in drw > drw_topsep()