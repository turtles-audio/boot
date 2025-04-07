#include <stdint.h>
#include "rcc.h"
#include "gpio.h"

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

}