; 
; Multiboot header constants
; 

MBALIGN equ 1<<0
MEMINFO equ 1<<1
FLAGS equ MBALIGN | MEMINFO
MAGIC equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)
RANDOM_VAL equ 0xABCD

; C code entry defined here
extern main


; 
; Multiboot section
; 

section .multiboot
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

; 
; Intialise stack for C code to run here
; 


section .bss
stack_bottom:
    resb 16 * 1024
stack_top:

; 
; Enter C Code from the _start section 
; 

section .text
global _start
_start:
    push eax
    mov eax, 0x100000
    mov [eax], dword RANDOM_VAL
    mov esp, stack_top
    
    cli
    call main                                 ; never return from kernel_main, in case returns, hang the cpu
; 
; Hang the CPU
; 

.hang:
    hlt
    jmp .hang 

.end: