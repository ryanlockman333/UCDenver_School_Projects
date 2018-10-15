; convert lowercase char to uppercase char
; 4/30/14

SECTION .data

SECTION .bss
    Buff resb 1            ; buffer for read/writ

SECTION .text
global _start

_start
    nop                     ; no operation for debugger

ReadFile:
    ; read(0, Buff, 1)
    mov eax, 3h             ; call sys_read
    mov ebx, 0h             ; use stdin(0)
    mov ecx, Buff           ; pass adrr of Buff
    mov edx, 1h             ; read one char from stdin
    int 80h                 ; interupt via syscall

    ; check return
    cmp eax, 0h             ; compare sys_read return value, EOF(0 return)
    je Exit                 ; jump if equal to 0

    ; check char 
    cmp byte [Buff], 61h    ; compare byte with lowercase a(61h)
    jb WriteFile            ; jump of below a
    cmp byte [Buff], 7Ah    ; compare same byte with lowercase z(7a)
    ja WriteFile            ; jump if above z

    ; convert to upper
    sub byte [Buff], 20h    ; minus 20h(value between each lower and upper)

WriteFile:
    ; write(1, Buff, 1)
    mov eax, 4h             ; call sys_write
    mov ebx, 1h             ; use stdout(1)
    mov ecx, Buff           ; pass addr of Buff
    mov edx, 1h             ; write 1 char to stdout
    int 80h                 ; interupt via syscall

    ; read next byte
    jmp ReadFile            ; jump to next char

Exit:
    ; exit(0)
    mov eax, 1h             ; call sys_exit
    mov ebx, 0h             ; return succes(0)
    int 80h                 ; interupt via syscall

