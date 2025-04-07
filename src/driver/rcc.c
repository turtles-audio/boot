#define RCC_BASE 0x58024400
#define RCC_APB1HENR (*(volatile int*) (RCC_BASE + 0xEC))
#define RCC_APB1LENR (*(volatile int*) (RCC_BASE + 0xE8))
#define RCC_APB2ENR (*(volatile int*) (RCC_BASE + 0xF0))
#define RCC_APB3ENR (*(volatile int*) (RCC_BASE + 0xE4))
#define RCC_APB4ENR (*(volatile int*) (RCC_BASE + 0xF4))

#define RCC_AHB1ENR (*(volatile int*) (RCC_BASE + 0xD8))
#define RCC_AHB2ENR (*(volatile int*) (RCC_BASE + 0xDC))
#define RCC_AHB3ENR (*(volatile int*) (RCC_BASE + 0xD4))
#define RCC_AHB4ENR (*(volatile int*) (RCC_BASE + 0xE0))

void rcc_ltdc_enable() {
    RCC_APB3ENR |= (1 << 3);
}

void rcc_gpio_enable() {
    RCC_AHB4ENR |= 0b11111111111;
}