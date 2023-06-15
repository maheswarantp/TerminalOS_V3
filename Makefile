GCC 		= i686-elf-gcc
ASM 		= nasm
LD 			= i686-elf-ld 
INCLUDE		= include

# CFLAGS  	= -ffreestanding -O2 -Wall -Wextra -I include/
CFLAGS		= -g -ffreestanding -O0 -Wall -Wextra -fno-exceptions -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector

LDFLAGS 	= -ffreestanding -O0 -nostdlib

C_SOURCES	= ${wildcard *.c */*.c */*/*.c */*/*/*.c}
H_SOURCES	= ${wildcard *.h */*.h */*/*.h */*/*/*.h}
ASM_SOURCES = ${wildcard *.asm */*.asm */*/*.asm */*/*/*.asm}

OBJ 		= ${C_SOURCES:.c=.o} ${ASM_SOURCES:.asm=.o}

TOOLS		= tools
BUILD		= build

.PHONY: all

%.o: %.asm
	nasm -f elf32 $< -o $@

%.o: %.c ${HEADERS}
	${GCC} ${CFLAGS} -I include/ -ffreestanding -c $< -o $@
	# ${GCC} ${CFLAGS} -c -g $< -o $@

kernel.elf: linker.ld ${OBJ}
	${GCC} -T linker.ld -o ${BUILD}/$@ ${LDFLAGS} ${OBJ}

update_disk: kernel.elf
	bash ./updatedisk.sh

run: update_disk
	qemu-system-i386 -hda disk.img -soundhw pcspk -m 10

all: run FORCE

FORCE: ;

makedisk:
	bash ./makedisk.sh

debug: FORCE
	bash ./debug.sh


clean:
	rm -rf *.o */*.o */*/*.o */*/*/*.o build/*