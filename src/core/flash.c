#include "flash.h"

flash_reg_t flash_register(flash_register_t offset) {
    if (offset > FLASH_ECC_FA1R || offset % 4 != 0) {
        offset = FLASH_ACR;
    }

    return (flash_reg_t) (FLASH_BASE + offset);
}

int flash_unlock() {
    flash_reg_t keyr = flash_register(FLASH_KEYR);
    if (flash_check(keyr, 0xCDEF89AB)) {
        return 1;
    }

    flash_key(keyr, 0x45670123);
    flash_key(keyr, 0xCDEF89AB);

    return flash_check(keyr, 0xCDEF89AB);
}