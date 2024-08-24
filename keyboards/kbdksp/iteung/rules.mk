
MCU = RP2040
BOARD = GENERIC_RP_RP2040
# Bootloader selection
BOOTLOADER = rp2040

# SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
EXTRAKEY_ENABLE = yes    # Audio control and System control
MOUSEKEY_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = ssd1306

RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
WS2812_DRIVER = vendor

SRC += oled/oled_handler.c process_record.c

DEBUG_MATRIX_SCAN_RATE_ENABLE = yes
WPM_ENABLE = yes
CONSOLE_ENABLE = yes
SRC +=  oled/rp2040/master/oled_master_handler.c \
				oled/rp2040/slave/oled_slave_handler.c
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = analog_joystick
