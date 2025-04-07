_phys_fram_start = 0x30000000;
_phys_binary_start = 0x8000000;

_special = _phys_binary_start + 0x50;

ENTRY(boot)

MEMORY {
    VECTOR(rx) : ORIGIN = 0, LENGTH = 0xFFFF
    FLASH (rx) : ORIGIN = 0x8000000, LENGTH = 512K
    SRAM (rw) : ORIGIN = 0x30000000, LENGTH = 8M
}

SECTIONS {
    .boot_stack (NOLOAD) : ALIGN(8) {
        _stack_end = .;
        . += 8K;
        _stack_start = .;
    } >SRAM

    .data : { *(.data*) } >SRAM

    .bss (NOLOAD) : ALIGN(16) {
        _bss_end = .;
        *(.bss*);
        . = ALIGN(16);
        _bss_start = .;
    } >SRAM

    .vector : ALIGN(4) {
        KEEP(*(.vector))
    } >FLASH

    .text : {
        KEEP(*(.text))
        *(.text*)
        . = ALIGN(8);
    } >FLASH

    .rodata : {
        *(.rodata)
    } >FLASH

    .rodata : ALIGN(8) { *(.rodata*) } >FLASH
}
