
MCU = RP2040
BOARD = GENERIC_RP_RP2040
# Bootloader selection
BOOTLOADER = rp2040

# SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
EXTRAKEY_ENABLE = yes    # Audio control and System control
MOUSEKEY_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

SRC += oled/oled_handler.c process_record.c

DEBUG_MATRIX_SCAN_RATE_ENABLE = yes
WPM_ENABLE = yes
CONSOLE_ENABLE = yes
SRC +=  oled/rp2040/master/oled_master_handler.c \
				oled/rp2040/master/indicators_down.c \
				oled/rp2040/master/indicators_up.c \
				oled/rp2040/slave/oled_slave_handler.c \
				oled/rp2040/slave/ocean_dream.c
