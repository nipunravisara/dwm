# My build of DWM

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger) [![GitHub last commit](https://img.shields.io/github/last-commit/google/skia.svg?style=flat)](https://github.com/nipunravisara/dwm)

This is [suckless](https://dwm.suckless.org), dwm window manager, Edit `config.def.h` for configureations. For more check my [dotfiles](https://github.com/nipunravisara/dots-x2).

![screenshot](https://raw.githubusercontent.com/nipunravisara/dots-x2/master/screenshots/screenshot-0.png)

### Patches

- [Fullgaps](https://dwm.suckless.org/patches/fullgaps/) - This patch adds gaps between client windows.
- [Bar height](https://dwm.suckless.org/patches/bar_height/) - This patch allows user to change dwm's default bar height.
- [No title](https://dwm.suckless.org/patches/notitle/) - This patch hide window title on top bar.

### Dependencies

I'm using scientifica bitmap font and material-icon font for icons. make sure you install those or change fonts as your preferences in `config.def.h` file. To generate color palettes I'm using pywal so install paywal before compile this dwm build.

- [scientifica bitmap font](https://github.com/NerdyPepper/scientifica)
- [material-icons](https://aur.archlinux.org/packages/ttf-material-icons-git/)
- [pywal](https://github.com/dylanaraps/pywal)

## Installation

```sh
git clone https://github.com/nipunravisara/dwm.git
cd dwm
sudo make install
```

## Installation libxft-bgra

You must install `libxft-bgra` from the `AUR` for color emoji in the status/info bar. [Learn more.](https://www.youtube.com/watch?v=0QkByBugq_4)
