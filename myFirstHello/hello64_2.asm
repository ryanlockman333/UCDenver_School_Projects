SECTION .data                   ; Section containing initialized data
    EatMsg: db  'Hello, world', 0x0A
    EatLen: equ $-EatMsg

SECTION .bss                    ; Section containing uninitialized data

SECTION .text                   ; Section containing code

global main                     ; Linker needs this to find the entry point!
main:
    nopi                        ; This no-op keeps gdb happy (see text)
    mov ebx, 4                  ; Specify sys_write syscall
    mov ebx, 1                  ; Specify File Descriptor 1: stdout
    mov ecx, EatMsg             ; Pass offset of the msg
    mov edx, EatLen             ; Pass the length of msg
    int 80H                     ; Make syscall to output msg to stdout

    mov eax, 1                  ; Specify Exit syscall
    mov ebx, 0                  ; return 0 {success)
    int 80H                     ; Make syscall tot erminate program

