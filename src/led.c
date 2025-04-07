#include "led.h"

int led_init() {
    int success = 1;
    gpio_init();

    success &= gpio_mode(GPIOI, (gpio_pin_t) LED_GREEN, GPIO_MODER_OUTPUT);
    success &= gpio_mode(GPIOI, (gpio_pin_t) LED_ORANGE, GPIO_MODER_OUTPUT);
    success &= gpio_mode(GPIOI, (gpio_pin_t) LED_RED, GPIO_MODER_OUTPUT);
    success &= gpio_mode(GPIOI, (gpio_pin_t) LED_BLUE, GPIO_MODER_OUTPUT);

    success &= led_off(LED_GREEN);
    success &= led_off(LED_ORANGE);
    success &= led_off(LED_RED);
    success &= led_off(LED_BLUE);

    return success;
}

int led_on(led_t led) {
    return gpio_write(GPIOI, (gpio_pin_t) led, GPIO_LOW);
}

int led_off(led_t led) {
    return gpio_write(GPIOI, (gpio_pin_t) led, GPIO_HIGH);
}