#ifndef LED_H
#define LED_H

#include "gpio.h"

enum LED {
    LED_GREEN = GPIO_PIN12,
    LED_ORANGE = GPIO_PIN13,
    LED_RED = GPIO_PIN14,
    LED_BLUE = GPIO_PIN15,
};

typedef enum LED led_t;

int led_init();
int led_on(led_t led);
int led_off(led_t led);

#endif