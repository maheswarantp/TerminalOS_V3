#ifndef __KERNEL__
#define __KERNEL__

// MULTIBOOT
#include <multiboot.h>

// VGA buffer
#include <drivers/screen.h>
#include <lib/string.h>

// GDT
#include <cpu/gdt.h>

// IDT
#include <cpu/idt.h>
#include <cpu/isr.h>

// TIMER
#include <drivers/timer.h>

// HDD
// #include <drivers/hdd.h>

// FS
// #include <fs/fat.h>

#endif