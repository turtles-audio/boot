.global lock
.global boot

.section .vector, "a"
    .word _stack_start
    .word boot
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .word lock
    .skip 32

.section .text
boot:
    bl lcd_enable
    b .
lock:
    b .
