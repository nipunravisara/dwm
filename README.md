# My build of DWM

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger) [![GitHub last commit](https://img.shields.io/github/last-commit/google/skia.svg?style=flat)](https://github.com/nipunravisara/dwm)

This is [suckless](https://dwm.suckless.org), dwm window manager, Did some changes on keybindings and using rofi as my launcher. Check out config.h

### Patches and features

- [Fullgaps](https://dwm.suckless.org/patches/fullgaps/) - This patch adds gaps between client windows.
- [Bar height](https://dwm.suckless.org/patches/bar_height/) - This patch allows user to change dwm's default bar height.

## Installation

```sh
git clone https://github.com/nipunravisara/dwm.git
cd dwm
sudo make install
```

## Installation libxft-bgra

You must install `libxft-bgra` from the `AUR` for color emoji in the status/info bar. [Learn more.](https://www.youtube.com/watch?v=0QkByBugq_4)
