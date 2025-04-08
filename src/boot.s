.section .vector, "a"
stack:
    .word _stack_start
start:
    .word boot
exceptions:
    .skip 239
checksum:
    .word 0
kernel:
    .word 0

.section .vector.root, "a"
    .word _stack_start
    .word boot
    .skip 247

.section .text
boot:
    bl init

    ldr r0, =checksum
    ldr r0, [r0]
    cmp r0, #0
    beq lock

    ldr r0, =kernel
    ldr r0, [r0]
    cmp r0, #0
    beq lock
elevate:
    ldr r0, =stack
    ldr r0, [r0]
    mov sp, r0

    ldr r0, =kernel
    ldr r0, [r0]
    bx r0
lock:
    bl panic
    b .
.global boot