#ifndef __IDT__
#define __IDT__

#include <types.h>

typedef struct {
    uint16_t low_offset;
    uint16_t sel;
    uint8_t always0;
    uint8_t flags;
    uint16_t high_offset;
}__attribute__((packed)) idt_gate_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
}__attribute__((packed)) idt_register_t;

void set_idt_gate(int n, uint32_t isr);
void set_idt();

#endif