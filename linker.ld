/* Entry Section for the final bin file */
ENTRY(_start)
OUTPUT_FORMAT(elf32-i386)                       /* ELF32 binary, 32 bit */
OUTPUT_ARCH(i386:i386)                          /* 32 bit architecture machine code neeeded*/

SECTIONS
{
    . = 1M;                                     /* Align the kernel code at 1M location */

    .text :                                     /* Text section has multiboot and actual code sections */
    {
        *(.multiboot)
        *(.text)
    }

    .rodata :                                   /* Any Read only data declared here, constants etc */
    {
        *(.rodata)
    }

    .data :                                     /* Read and write data declared here */
    {
        *(.data)
    }

    .bss :                                      /* Reserved but uninitialised data here, stack is declared here too */
    {
        *(.bss)
    }
}
