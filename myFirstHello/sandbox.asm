section .data

section .text

global main

main:
    nop
    ; Sandbox your instructions...

    mov eax, 100
    mov ebx, 10
    div ebx

    ; Sandbox your instructions...
    nop

section .bss

