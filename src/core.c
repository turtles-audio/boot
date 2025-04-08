#include "driver/led.h"
#include "driver/flash.h"

void init() {
    led_init();
    led_on(LED_BLUE);

    char str[] = "Hello, world!";

    for (unsigned int i = 0; i < sizeof(str); i++) {
        led_on(LED_GREEN);
        for (int j = 0; j < 99999; j++);
        led_off(LED_GREEN);

        if (str[i] == 'l') {
            led_on(LED_ORANGE);
            break;
        }
    }

    flash_unlock();
}

void panic() {}