#ifndef FLASH_H
#define FLASH_H

#define flash_key(x, y) ((*x) = (y)); while ((*x) != (y)) {}
#define flash_check(x, y) (*x) == (y)

#define FLASH_BASE 0

enum FLASH_REGISTER {
    FLASH_ACR = 0x0,
    FLASH_KEYR = 0x4,
    FLASH_OPTKEYR = 0x8,
    FLASH_CR1 = 0x0C,
    FLASH_SR1 = 0x10,
    FLASH_CCR1 = 0x14,
    FLASH_OPTCR = 0x18,
    FLASH_OPTSR_CUR = 0x1C,
    FLASH_OPTSR_PRG = 0x20,
    FLASH_OPTCCR = 0x24,
    FLASH_PRAR_CUR1 = 0x28,
    FLASH_PRAR_PRG1 = 0x2C,
    FLASH_ScAR_CUR1 = 0x30,
    FLASH_SCAR_PRG1 = 0x34,
    FLASH_WPSN_CUR1R = 0x38,
    FLASH_WPSN_PRG1R = 0x3C,
    FLASH_BOOT7_CURR = 0x40,
    FLASH_BOOT7_PRGR = 0x44,
    FLASH_BOOT4_CURR = 0x48,
    FLASH_BOOT4_PRGR = 0x4C,
    FLASH_CRCCR1 = 0x50,
    FLASH_CRCADD1R = 0x54,
    FLASH_CRCEADD1R = 0x58,
    FLASH_CRCDATAR = 0x5C,
    FLASH_ECC_FA1R = 0x60,
};

typedef enum FLASH_REGISTER flash_register_t;

typedef unsigned int* flash_reg_t;

int flash_unlock();

#endif