GCC 		= i686-elf-gcc
ASM 		= nasm
LD 			= i686-elf-ld 
INCLUDE		= include

CFLAGS 		= -g -ffreestanding -Wall -Wextra -fno-exceptions -m32 -fno-builtin -fno-stack-protector -I include/
# CFLAGS  	= -ffreestanding -O2 -Wall -Wextra -I include/
LDFLAGS 	= -ffreestanding -O2 -nostdlib

C_SOURCES	= ${wildcard *.c */*.c */*/*.c */*/*/*.c}
H_SOURCES	= ${wildcard *.h */*.h */*/*.h */*/*/*.h}
ASM_SOURCES = ${wildcard *.asm */*.asm */*/*.asm */*/*/*.asm}

OBJ 		= ${C_SOURCES:.c=.o} ${ASM_SOURCES:.asm=.o}

TOOLS		= tools
BUILD		= build

.PHONY: all

%.o: %.asm
	nasm -f elf32 $< -o $@

%.o: %.c
	${GCC} ${CFLAGS} -c -g $< -o $@

kernel.elf: linker.ld ${OBJ}
	${GCC} -T linker.ld -o ${BUILD}/$@ ${LDFLAGS} ${OBJ}

update_disk: kernel.elf
	bash ./update_disk.sh

run: update_disk
	qemu-system-i386 -hda disk.img

all: run FORCE

FORCE: ;

makedisk:
	bash ./makedisk.sh

debug: FORCE
	bash ./debug.sh


clean:
	rm -rf *.o */*.o */*/*.o */*/*/*.o build/*