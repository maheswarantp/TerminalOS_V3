# Compile with debug symbols here

# gnome-terminal -- gdb -e"

sudo gnome-terminal -- gdb -ex "target remote localhost:1234" -ex "symbol-file build/kernel.elf" -ex "layout asm"
if test -f "build/kernel.elf"
then
	sudo qemu-system-i386 -s -S -hda disk.img
else
    cp $(BUILD)/kernel.elf debug/kernel.elf
    objcopy --only-keep-debug debug/kernel.elf debug/terminalos.sym 
    objcopy --strip-debug debug/kernel.elf
    qemu-system-i386 -s -S -hda disk.img -d int -no-reboot -no-shutdown -M smm=off -D interrupts_debug.log
fi	
