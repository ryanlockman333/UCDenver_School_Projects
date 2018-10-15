section .data
    EatMsg: db  10, "Hello World from ShellCode", 10, 10
    EatLen: equ $-EatMsg

section .text

global _start
_start:
    nop                         ; nop sled  0_,
    nop                         ; weee -------
    nop                         ; weee ---------
    nop                         ; weee -----------
    nop                         ; weee ------------- 0_, end

    jmp get_addr                ; get address of str

run:    
    ; write(stdout(1), EatMsg, EatLen)
    xor eax, eax                ; zero out register   
    mov eax, 4                  ; sys_write syscall
    mov ebx, 1                  ; specify fd 1 stdout
    ;mov [EatMsg+27], byte ah    ; replace N with null byte after EatMsg
    mov ecx, EatMsg             ; pass offset to msg
    mov edx, EatLen             ; pass len of msg
    int 0x80                     ; make syscall to output to stdout

    ; exit(0)
    mov eax, 1                  ; sepcify exit syscall
    mov ebx, 0                  ; exit with 0 
    int 0x80                     ; syscall to end program

get_addr:
    call run                    ; put addr of str on stack

section .bss

