#include "led.h"

void init() {
    led_init();

    while (1) {
        led_on(LED_GREEN);
        for (int i = 0; i < 1000000; i++); // Delay
        led_off(LED_GREEN);
        for (int i = 0; i < 1000000; i++); // Delay
    }
}