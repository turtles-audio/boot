.global lock
.global boot

.section .vector, "a"
    .word _stack_start
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .word boot
    .skip 32

.section .text
boot:
    bl lcd_enable
    b .
lock:
    b .
