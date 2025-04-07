#include <stdint.h>
#include "rcc.h"

#define LTDC_BASE 0x50001000
#define LTDC_SSCR (*(volatile uint32_t*) (LTDC_BASE + 0x8))
#define LTDC_BPCR (*(volatile uint32_t*) (LTDC_BASE + 0xC))
#define LTDC_AWCR (*(volatile uint32_t*) (LTDC_BASE + 0x10))
#define LTDC_TWCR (*(volatile uint32_t*) (LTDC_BASE + 0x14))
#define LTDC_GCR (*(volatile uint32_t*) (LTDC_BASE + 0x18))
#define LTDC_SRCR (*(volatile uint32_t*) (LTDC_BASE + 0x24))
#define LTDC_BCCR (*(volatile uint32_t*) (LTDC_BASE + 0x2C))
#define LTDC_IER (*(volatile uint32_t*) (LTDC_BASE + 0x34))

void lcd_timing() {
    //LTDC_SSCR = 0x90001;
    //LTDC_BPCR = 0x1D0003;
    //LTDC_AWCR = 0x15D00F3;
    //LTDC_TWCR = (0x167 << 16) | 0xF7;
    return;
}

void lcd_enable() {
    rcc_ltdc_enable();
    rcc_gpio_enable();

    (*(volatile uint32_t*)(0x58022000)) &= ~(0x3 << (15 * 2));
    (*(volatile uint32_t*)(0x58022000)) |= (0x1 << (15 * 2));
    //(*(volatile uint32_t*)(0x58021C18)) = (0);

    while (1) {}

    //LTDC_GCR = 0b1;
    //LTDC_BCCR = 0xFFFFFF00;
    return;
}