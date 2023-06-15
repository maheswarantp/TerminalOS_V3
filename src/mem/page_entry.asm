section .text
global loadPageDirectory
loadPageDirectory:
    push ebp
    mov esp, ebp
    mov eax, dword [esp + 8]
    mov cr3, eax
    mov esp, ebp
    pop ebp
    ret



global enablePaging
enablePaging:
    push ebp
    mov ebp, esp
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
    mov esp, ebp
    pop ebp
    ret

