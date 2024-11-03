# QMK Notes for my mechanical keyboards

## Guide
### Using QMK Configurator
The configurator gives you an easy way to configure and compile a new layout.
However you cannot customise it with functions in your build.

Steps:

1. visually configure your desired layout in the online QMK configurator
2. download the json
3. print and save your layout but don't compile in the configurator
4. use QMK to convert the json into `keymap.c` (not tested)
5. run QMK setup and copy changes.

### files changed
#### DZ60 9/9/2022 build:
- keyboards/dz60/rules.mk --> to shift custom rules into keymap folder next time
- keyboards/dz60/keymaps/mrshiister/keymap.c
#### kbd67 2/10/2022 build:
- keyboards/kbdfans/kbd67/mkiirgb/keymaps/mrshiister/*

### Using VIA
Via is a similar tool to the QMK Configurator
#### Advantages
- Change the keymaps live, if via rule is enabled. Tested on kbd67.
- Accepts all QMK keycodes, but might need to use long forms, e.g. `MT()`
- Has key tester and matrix tester
#### Disadvantages
- Lacks function level customisations
- Outdate firmware (chording was 8ms per key, 2/10/2022)
#### Notes
- My keyboards are Via-disabled because the disadvantages are deal-breakers.

## QMK program
### Archlinux
Install `qmk` from package manager.

## Changing Keyboard Firmware
### DZ60 - Flash Firmware through QMK CLI
#### 1.1.1
- Date: 9/9/2022
- QMK program itself is no longer packaged with the code
- Check `user.qmk_home` with `qmk config`
    - Cannot set it to the older firmware folder (0.7.106), won't recognise as qmk clone
- Check `git config` to allow global safe directory
    - Might be a NTFS problem
- `qmk flash my_specified.hex` is bugged - please copy the hex file to the root folder of qmk before flashing or you will have an empty firmware
- `qmk flash` through building and flashing directly, however, works.
### kbd67 - Copy firmware to mass storage
- does not need flashing
- **Change Firmware in WINDOWS.** Ejecting in Linux does not have the same effect as ejecting in Windows.
- Boot into bootloader, delete `FLASH.BIN` and copy the compiled `kbdfans_kbd67_mkiirgb_v3_mrshiister.bin`
- Eject the keyboard. Keyboard RGB should light up.
- Plug out and plug in keyboard again.

### QMK firmware Version
#### 0.18.5
- Date: 9/9/2022
- `TT(x)` keycode acts like `#define TAPPING_TOGGLE 1` so I replaced it with `MO(x)`
- Single tap Right-Shift for DEL
- Chords are ok
- Enabling Dynamic Macros rule breaks the kbd67

#### 0.7.106
- Date: 2019
- Double-tap Right-Shift for DEL
- Chords are ok

### Layout
- Programmable buttons are recognised by the Linux kernel but KDE doesn't recognise them. See [custom keymap](https://wiki.archlinux.org/title/Linux_console/Keyboard_configuration#Creating_a_custom_keymap) for potential solution
- Added Macros!
- `sudo libinput debug-events --show-keycodes` to capture keycodes
- Neither Xorg nor Wayland seem to support the Macro keycodes

### Physically Reset DZ60
1. Remove keycaps and unscrew main board
2. With keyboard plugged in, use flathead screwdriver to touch both RESET pins
3. To test: `BOOTMAGIC_ENABLE = yes` -- Hold Esc and plug in keyboard to go to bootloader

### Physically Reset kbd67
1. Unscrew case
2. Remove bottom foam
3. Press "S1" button while plugged in
4. Otherwise, hold Esc and plug in keyboard
5. The original Via-enabled firmware is `kbdfans_kbd67_mkiirgb_v3_via.bin`