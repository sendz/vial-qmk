VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes

# Disable features to save massive amounts of flash memory
BOOTMAGIC_ENABLE = no       # Saves ~1-2KB (Turns off boot magic shortcuts)
MOUSEKEY_ENABLE = no        # Saves ~2-3KB (Disables controlling cursor with keyboard)
# EXTRAKEY_ENABLE = no        # Saves ~500B (Audio/System keys, keep if you need volume control)
CONSOLE_ENABLE = no         # Saves ~1-2KB (Debugging console output)
COMMAND_ENABLE = no         # Saves ~1-2KB (QMK command menu)
BACKLIGHT_ENABLE = no       # Turn off if your build doesn't have single-color backlight
RGBLIGHT_ENABLE = no        # Saves ~4-5KB (Turn off if you don't have underglow/RGB strips)
NKRO_ENABLE = no            # Saves ~1KB (N-Key Rollover. Standard 6KRO is fine for typing/gaming)
LTO_ENABLE = yes            # CRITICAL: Link-Time Optimization compresses your code significantly
OLED_ENABLE = no
SPACE_CADET_ENABLE = no
ENCODER_MAP_ENABLE = yes
TAP_DANCE_ENABLE = no
