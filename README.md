Dream Machine - DWM
==============================
dwm is an extremely fast, small, and dynamic window manager for X. 

Based of DWM 6.1 head from 2015-03-13 (commit 14343e69cc5), tweaked and configured to personal preference.

This is part of Lindstreams Dream Machine, read more @ link.

Patches
----------------------------
* **dwmfifo**    
  Best thing since sliced bread, this patch adds a FIFO command/controller (/tmp/dwm.fifo) to exec keybind actions through CLI.

* **hide vacant tags**  
  Pretty self-explanatory :)

* **statusallmons**  
  Makes the statusbar available on all displays.

* **runorraise**  
  Allows you to map frequently used apps to a key combo that will launch the application if it's not already running - otherwise bring the running session into focus. Great stuff to use with browsers and notes.

* **notitle**  
  Who need titles anyway?

* **save_floats**  
  Makes dwm remember the floating position and window size before things are tiled, and restores them appropriately.

* **bottom stack**  
  Nowamore nicknamed htile

* **center**  
  Adds an iscentered rule to automatically center clients on the current monitor.

* **statuscolors**  
  Adds a few more colors to dwm's palette.

* **focusmaster**  
  Super + ShiftR takes you back to your master client.

* **uselessgaps**  
  Adds the possibility to gap windows, also takes care of border in monocle and fullscreen mode.

* **viewontag**  
  Follow a window to the tag it's being moved to, can't really decide on this one - option is set in config.h (needs fixing, indifferent to current tag status).

* **emptyview**  
  There's something annoying about not being able to toggle that last tag out of view.. 

* **swap focus (WIP)**  
  Allows you to switch focus with a single shortcut


Other modifications
----------------------------
* **keeptags**  
  Tags should be kept when moving clients between displays

* **raisetags**  
  * toggle view if not active when moving clients between display
  * toggle view if client isn't visible after launch

* **runorraise**  
  * checks by window title aswell as names
  * changed to toggleview

* **borderfix**  
  border was applied to all windows when reattaching floating windows. 

* **layoutfirst**  
  layout icon is shown first in menu and has its own colorsettings

* **notoccupied**  
  special color when tags are active but unoccupied (removed rect-indicator)

* **setting for monoclecounter**


Dirty shines
----------------------------
* **separators between tags**  
  Hardcoded colors in drw > drw_sep()

* **top line**  
  Hardcoded colors in drw > drw_topsep()