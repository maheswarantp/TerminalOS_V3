#include <drivers/timer.h>
#include <cpu/isr.h>
#include <lib/string.h>
#include <ports.h>

uint32_t tick = 0;

void timer_interrupt_handler(registers_t *regs) {
    tick++;
    // printf("Time is :%d\n", tick);
}

uint32_t getTime()
{
    return tick;
}

void sleep(uint32_t time)
{
    uint32_t up1 = getTime();
    while(getTime() - up1 <= time);
}


void init_timer(uint32_t freq) {
    set_interrupt_handler(TIMER_INTERRUPT, &timer_interrupt_handler);

    uint32_t d = 1193180 / freq;

    outb(0x43, 0x36);
    outb(0x40, (uint8_t)(d & 0xFF));
    outb(0x40, (uint8_t)((d >> 8) & 0xFF));
}