#ifndef __KERNEL__
#define __KERNEL__

// VGA BUFFER
#include <drivers/screen.h>

// String.h
#include <lib/string.h>

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

// Tests
#include <tests/test_timer.h>
#include <tests/test_speaker.h>

#endif