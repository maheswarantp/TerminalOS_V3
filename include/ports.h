#pragma once

#include <drivers/screen.h>
#include <lib/string.h>
#include <types.h>

uint8_t inb(uint16_t port);               // read from a port
uint16_t inw(uint16_t port);
void outb(uint16_t port, uint8_t data);   // send to a port