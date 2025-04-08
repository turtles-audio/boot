.section .vector, "a"
    .word _stack_start
    .word boot
    .skip 247

.section .vector.root, "a"
    .word _stack_start
    .word boot
    .skip 247

.section .text
boot:
    bl init
    b .
.global boot