#ifndef GPIO_H
#define GPIO_H

#include "rcc.h"

#define GPIO_BASE 0x58020000

#define GPIOA_BASE (GPIO_BASE + 0x000)
#define GPIOB_BASE (GPIO_BASE + 0x400)
#define GPIOC_BASE (GPIO_BASE + 0x800)
#define GPIOD_BASE (GPIO_BASE + 0xC00)
#define GPIOE_BASE (GPIO_BASE + 0x1000)
#define GPIOF_BASE (GPIO_BASE + 0x1400)
#define GPIOG_BASE (GPIO_BASE + 0x1800)
#define GPIOH_BASE (GPIO_BASE + 0x1C00)
#define GPIOI_BASE (GPIO_BASE + 0x2000)
#define GPIOJ_BASE (GPIO_BASE + 0x2400)
#define GPIOK_BASE (GPIO_BASE + 0x2800)

enum GPIO_PINS {
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15,
};

enum GPIO_SLOTS {
    GPIOA,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF,
    GPIOG,
    GPIOH,
    GPIOI,
    GPIOJ,
    GPIOK,
};

enum GPIO_MODER {
    GPIO_MODER_INPUT = 0b00,
    GPIO_MODER_OUTPUT = 0b01,
    GPIO_MODER_ALTERNATE = 0b10,
    GPIO_MODER_ANALOG = 0b11,
};

enum GPIO_OTYPER {
    GPIO_OTYPER_PP = 0b0,
    GPIO_OTYPER_OD = 0b1,
};

enum GPIO_OSPEEDR {
    GPIO_OSPEEDR_LOW = 0b00,
    GPIO_OSPEEDR_MEDIUM = 0b01,
    GPIO_OSPEEDR_HIGH = 0b10,
    GPIO_OSPEEDR_VERY_HIGH = 0b11,
};

enum GPIO_PUPDR {
    GPIO_PUPDR_NONE = 0b00,
    GPIO_PUPDR_PULL_UP = 0b01,
    GPIO_PUPDR_PULL_DOWN = 0b10,
    GPIO_PUPDR_RESERVED = 0b11,
};

enum GPIO_VALUE {
    GPIO_LOW = 0b0,
    GPIO_HIGH = 0b1,
};

enum GPIO_REGISTER {
    GPIO_MODER = 0x00,
    GPIO_OTYPER = 0x04,
    GPIO_OSPEEDR = 0x08,
    GPIO_PUPDR = 0x0C,
    GPIO_IDR = 0x10,
    GPIO_ODR = 0x14,
    GPIO_BSRR = 0x18,
    GPIO_LCKR = 0x1C,
    GPIO_AFRL = 0x20,
    GPIO_AFRH = 0x24,
};

typedef enum GPIO_PINS gpio_pin_t;
typedef enum GPIO_SLOTS gpio_slot_t;
typedef enum GPIO_MODER gpio_moder_t;
typedef enum GPIO_OTYPER gpio_otyper_t;
typedef enum GPIO_OSPEEDR gpio_ospeedr_t;
typedef enum GPIO_PUPDR gpio_pupdr_t;
typedef enum GPIO_VALUE gpio_value_t;

typedef unsigned int* gpio_reg_t;
typedef unsigned int gpio_register_t;

void gpio_init();

int gpio_write(gpio_slot_t slot, gpio_pin_t pin, gpio_value_t value);
gpio_value_t gpio_read(gpio_slot_t slot, gpio_pin_t pin);

int gpio_mode(gpio_slot_t slot, gpio_pin_t pin, gpio_moder_t mode);
int gpio_speed(gpio_slot_t slot, gpio_pin_t pin, gpio_ospeedr_t speed);

#endif