#include <cpu/idt.h>

idt_gate_t idt[256];
idt_register_t idt_reg;

void set_idt_gate(int n, uint32_t isr) {
    idt[n].low_offset = low_16(isr);
    idt[n].sel = 0x08;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].high_offset = high_16(isr);
}

void set_idt()
{
    idt_reg.base = (uint32_t) &idt;
    idt_reg.limit = 256 * sizeof(idt_gate_t) - 1;

    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));
}