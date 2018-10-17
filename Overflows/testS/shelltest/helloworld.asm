section .data    ; section declaration

msg db "Hello, world!"    ; the string

section .text     ; section declaration

global _start     ; Default entry point for ELF linking

_start:

; write() call

 mov eax, 4       ; put 4 into eax, since write is syscall #4
 mov ebx, 1       ; put stdout into ebx, since the proper fd is 1
 mov ecx, msg     ; put the address of the string into ecx
 mov edx, 13      ; put 13 into edx, since our string is 13 bytes
 int 0x80         ; Call the kernel to make the system call happen

; exit() call

 mov eax,1       ; put 1 into eax, since exit is syscall #1
 mov ebx,0       ; put 0 into ebx
 int 0x80        ; Call the kernel to make the system call happen
