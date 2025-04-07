#include "gpio.h"

void gpio_init() {
    rcc_gpio_enable();
}

gpio_reg_t gpio_register(gpio_slot_t slot, gpio_register_t offset) {
    if (offset > GPIO_AFRH || offset % 4 != 0) {
        offset = GPIO_MODER;
    }

    switch (slot) {
        case GPIOB: return (gpio_reg_t) GPIOB_BASE + offset;
        case GPIOC: return (gpio_reg_t) GPIOC_BASE + offset;
        case GPIOD: return (gpio_reg_t) GPIOD_BASE + offset;
        case GPIOE: return (gpio_reg_t) GPIOE_BASE + offset;
        case GPIOF: return (gpio_reg_t) GPIOF_BASE + offset;
        case GPIOG: return (gpio_reg_t) GPIOG_BASE + offset;
        case GPIOH: return (gpio_reg_t) GPIOH_BASE + offset;
        case GPIOI: return (gpio_reg_t) GPIOI_BASE + offset;
        case GPIOJ: return (gpio_reg_t) GPIOJ_BASE + offset;
        case GPIOK: return (gpio_reg_t) GPIOK_BASE + offset;
        case GPIOA: default: return (gpio_reg_t) GPIOA_BASE + offset;
    }
}

gpio_value_t gpio_read(gpio_slot_t slot, gpio_pin_t pin) {
    gpio_reg_t idr = gpio_register(slot, GPIO_IDR);
    gpio_value_t value = (*idr >> pin) & 0x1;

    return value;
}

gpio_value_t gpio_bssr(gpio_slot_t slot, gpio_pin_t pin, gpio_value_t value) {
    gpio_reg_t bssr = gpio_register(slot, GPIO_BSRR);

    switch (value) {
        case GPIO_LOW:
            *bssr &= ~(1 << pin);
            break;
        case GPIO_HIGH:
        default:
            *bssr |= (1 << pin);
            break;
    }

    return gpio_read(slot, pin);
}

int gpio_write(gpio_slot_t slot, gpio_pin_t pin, gpio_value_t value) {
    gpio_bssr(slot, pin, value);

    if (gpio_read(slot, pin) == value) {
        return 1;
    }

    return 0;
}

int gpio_mode(gpio_slot_t slot, gpio_pin_t pin, gpio_moder_t mode) {
    gpio_reg_t moder = gpio_register(slot, GPIO_MODER);
    *moder &= ~(0b11 << (pin * 2));
    *moder |= (mode << (pin * 2));

    return *moder & ((0b11 << (pin * 2)) == (mode << (pin * 2)));
}

int gpio_speed(gpio_slot_t slot, gpio_pin_t pin, gpio_ospeedr_t speed) {
    gpio_reg_t ospeedr = gpio_register(slot, GPIO_OSPEEDR);
    *ospeedr &= ~(0b11 << (pin * 2));
    *ospeedr |= (speed << (pin * 2));

    return *ospeedr & ((0b11 << (pin * 2)) == (speed << (pin * 2)));
}