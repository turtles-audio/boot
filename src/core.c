#include "driver/led.h"

#include "core/flash.h"

void init() {
    led_init();
    led_on(LED_BLUE);

    flash_unlock();
}