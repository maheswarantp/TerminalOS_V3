#ifndef __KERNEL__
#define __KERNEL__

// Multiboot
#include <multiboot.h>

// COM1 
#include <drivers/serial.h>

// VGA BUFFER
#include <drivers/screen.h>

// String.h
#include <lib/string.h>
#include <lib/bit.h>

// GDT
#include <cpu/gdt.h>

// IDT
#include <cpu/idt.h>

// ISR
#include <cpu/isr.h>

// Timer
#include <drivers/timer.h>

// Speaker
#include <drivers/speaker.h>

// Keyboard
#include <drivers/keyboard.h>

// HDD
#include <drivers/hdd.h>


// Paging
#include <mem/pmm.h>
#include <mem/paging.h>

// Tests
#include <tests/test_timer.h>
#include <tests/test_speaker.h>

// Visuals
#include <utils/visuals.h>

#endif