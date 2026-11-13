/*
 * The OLED on this board is powered whether or not ZMK drives it, so with
 * CONFIG_ZMK_DISPLAY=n it keeps the last frame lit. Send it the display-off
 * command once the display driver has initialised.
 */
#include <zephyr/device.h>
#include <zephyr/drivers/display.h>
#include <zephyr/init.h>

static int corne_oled_off(void) {
    const struct device *display = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

    if (device_is_ready(display)) {
        display_blanking_on(display);
    }
    return 0;
}

SYS_INIT(corne_oled_off, APPLICATION, 99);
