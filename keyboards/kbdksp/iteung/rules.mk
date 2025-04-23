# SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

OLED_DRIVER = ssd1306

SRC += oled/oled_handler.c process_record.c

DEBUG_MATRIX_SCAN_RATE_ENABLE = yes

SRC +=  oled/rp2040/master/oled_master_handler.c \
				oled/rp2040/slave/oled_slave_handler.c
# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = analog_joystick
# ANALOG_DRIVER_REQUIRED = yes
