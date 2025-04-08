#include "rcc.h"
#include "gpio.h"
#include "lcd.h"

#define LTDC_BASE 0x50001000
#define LTDC_SSCR (*(volatile int*) (LTDC_BASE + 0x8))
#define LTDC_BPCR (*(volatile int*) (LTDC_BASE + 0xC))
#define LTDC_AWCR (*(volatile int*) (LTDC_BASE + 0x10))
#define LTDC_TWCR (*(volatile int*) (LTDC_BASE + 0x14))
#define LTDC_GCR (*(volatile int*) (LTDC_BASE + 0x18))
#define LTDC_SRCR (*(volatile int*) (LTDC_BASE + 0x24))
#define LTDC_BCCR (*(volatile int*) (LTDC_BASE + 0x2C))
#define LTDC_IER (*(volatile int*) (LTDC_BASE + 0x34))

int lcd_init() {
    return 0;
}