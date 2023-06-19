#include <drivers/speaker.h>

void play_sound(uint32_t freq)
{
    uint32_t div;
    uint8_t tmp;

    div = 1193180 / freq;
    outb(0x43, 0xb6);
    outb(0x42, (uint8_t)(div));
    outb(0x42, (uint8_t)(div >> 8));

    tmp = inb(0x61);
    if(tmp != (tmp | 3))
        outb(0x61, tmp | 3);
}

void stop_sound()
{
    uint8_t tmp  = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

void beep(uint32_t timeMilliSeconds)
{
    play_sound(1000);
    sleep(timeMilliSeconds);
    stop_sound();

    play_sound(2000);
    sleep(timeMilliSeconds);
    stop_sound();
}