#include <drivers/timer.h>

uint32_t tick = 0;
uint32_t milli_seconds_tick = 0;

void timer_interrupt_handler(registers_t *regs) {
    tick++;             // gives in milliseconds
    // if(tick % 1 == 0) // gives in second
        // milli_seconds_tick++;
        // printf("Tick is %d\n", tick);
}

uint32_t getTime()
{
    return tick;
}

void sleep(uint32_t time)
{
    uint32_t up1 = getTime();
    while((getTime() - up1) < (time/10));
    // printf("%d\n", getTime() - up1);
}

void init_timer(uint32_t freq) {
    register_interrupt_handler(IRQ0, &timer_interrupt_handler);

    // uint32_t d = 1193180 / freq;
    // 1193182
    uint32_t d = 1193182 / freq;

    outb(0x43, 0x36);
    outb(0x40, (uint8_t)(d & 0xFF));
    outb(0x40, (uint8_t)((d >> 8) & 0xFF));
}