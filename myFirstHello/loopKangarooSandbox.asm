section .data
    Str: db "KANGAROO"

section .text

global main

main:
    nop
    ; Sandbox your instructions...

    mov ebx, Str                        ; move str to base
    mov eax, 8                          ; counter
    ToLower: add Byte [ebx], 32         ; loop each char to lowercase
    inc ebx
    dec eax
    jnz ToLower                         ; jump if not zero

    ; Sandbox your instructions...
    nop

section .bss

