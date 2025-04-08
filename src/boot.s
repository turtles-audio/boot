.section .vector, "a"
    .word _stack_start
    .word boot
    .skip 248

.section .text
boot:
    bl init
    b .
.global boot