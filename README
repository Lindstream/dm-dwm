Dream Machine - DWM
==============================
dwm is an extremely fast, small, and dynamic window manager for X. 

Based of DWM head from 2015-03-13 (commit 14343e69cc5), tweaked and configured to personal preference.

This is part of Lindstreams Dream Machine, read more @ link.

Patches
----------------------------
* dwmfifo - done
  Best thing since sliced bread, this patch adds a FIFO command/controller (/tmp/dwm.fifo) to exec keybind actions through CLI.

* hide vacant tags - done
  Pretty self-explainatory :)

* statusallmons - done
  Makes the statusbar available on all displays.

* runorraise - done
  Allows you to map frequently used apps to a key combo that will launch the application if it's not already running - otherwise bring the running session into focus. Great stuff to use with browsers and notes.

* notitle - done
  Who need titles anyway?

* save_floats - done
  Makes dwm remember the floating position and window size before things are tiled, and restores them appropriately.

* bottom stack - done
  Nowamore nicknamed htile

* center - done
  Adds an “iscentered” rule to automatically center clients on the current monitor.

* statuscolors - done
  Adds a few more colors to dwm's palette.

* focusmaster - done
  Super + ShiftR takes you back to your master client.

* uselessgaps - done
  Adds the possibillity to gap windows, also takes care of border in monocle and fullscreen mode.

* viewontag - done
  Follow a window to the tag it's being moved to, can't really decide on this one - option is set in config.h
  - Needs fixing, indifferent to current tag status.

* emptyview - done
  There's something annoying about not being able to toggle that last tag out of view.. 

* swap focus - wip
  Allows you to switch focus with a single shortcut


Other modifications
----------------------------
* keeptags - done
  Tags should be kept when moving clients between displays

* raisetags - done 
  - toggle view if not active when moving clients between display
  - toggle view if client isn't visible after launch

* runorraise -done
  - checks by window title aswell as names
  - changed to toggleview

* borderfix - done
  border was applied to all windows when reattaching floating windows. 

* layoutfirst - done
  layout icon is shown first in menu and has it's own colorsettings

* notoccupied - done
  special color when tags are active but unoccupied (removed rect-indicator)

* setting for monoclecounter - done


Dirty shines
----------------------------
* separators between tags
  Hardcoded colors in drw > drw_sep()

* top line
  Hardcoded colors in drw > drw_topsep()