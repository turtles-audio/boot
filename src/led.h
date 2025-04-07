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

#endif