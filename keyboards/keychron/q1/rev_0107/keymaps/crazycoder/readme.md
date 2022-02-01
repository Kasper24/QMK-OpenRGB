## CrazyCoder's Keychron Q1 keymap (ANSI rev_0107) v1.0.0

Merge of lalalademaxiya1 Q1 knob (STM32L432) and mkillewald (Q1 non-knob, atmega32u4) keymaps

This keymap builds on the keymap by mkillewald which builds on Grayson Carr (gtg465x), but adds a couple options.

## Features:
- On macOS, F3 opens Mission Control and F4 opens Launchpad without needing to configure shortcuts in System Preferences
- RGB lighting turns off when the computer sleeps
- Caps Lock RGB indicator
    - the Caps Lock key will light when Caps Lock is enabled with the following options:
        - #define CAPS_LOCK_INDICATOR_COLOR [color] in config.h to set the backlight color used for the indicator when Caps Lock is enabled (default: red)
        - Fn+Z will toggle lighting the TAB key when Caps Lock is enabled. This is useful with non backlit keycaps/legends. (default: off)
        - Fn+X will toggle lighting all the alpha keys when Caps Lock is enabled. (default: off)

- Dynamic Fn layer RGB indicator
    - When the Fn key is held down, any keys defined on the Fn layer in this firmware or in VIA will be highlighted with the following options:
        - #define FN_LAYER_COLOR [color] in config.h to set a static color for defined keys (default: orange)
        - Fn+C will toggle turning off RGB for keys with no definition (default: RGB off)
        - Fn+V will toggle lighting the defined Fn layer keys with the static color set with FN_LAYER_COLOR (default: static color off)

- All custom keycodes can be moved to different keys in VIA by using the ANY key with the following keycodes:
    - USER00 (default: F3) macOS Mission Control
    - USER01 (default: F4) macOS Launchpad
    - USER02 macOS Left Option
    - USER03 macOS Right Option
    - USER04 macOS Left Command
    - USER05 macOS Right Command
    - USER06 Windows Task View
    - USER07 Windows File Explorer
    - USER08 (default: Fn+Z) Caps Lock light Tab toggle
    - USER09 (default: Fn+X) Caps Lock light alphas toggle
    - USER10 (default: Fn+C) Fn layer non-defined keys RGB toggle
    - USER11 (default: Fn+V) Fn layer defined keys static color toggle

RGB must be toggled on for all indicators to function. If you do not want an RGB mode active but still want the indicators, toggle RGB on and turn the brightness all the way off. The indicators will remain at full brightness.

Please make sure to save any customizations you have made in VIA to a .json file before flashing the firmware. Sometimes it has been necessary to re-apply those changes in VIA after flashing the firmware. If that is the case, you will most likely need to manually add the USER08 through USER11 custom keycodes after loading your customizations from the saved .json file. Then re-save a new .json file which will have your previous customizations and the custom keycodes for future use as needed.
    
#### USE AT YOUR OWN RISK

## Changelog:

v1.0.1  January 11, 2022
- 1000Hz polling rate

v1.0.0  January 10, 2022
- Initial merge of lalalademaxiya1 Q1 knob (STM32L432) and mkillewald (Q1 non-knob, atmega32u4) keymaps
