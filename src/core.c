#include "driver/led.h"

void init() {
    led_init();
    led_on(LED_BLUE);
}