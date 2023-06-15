dd if=/dev/zero of=disk.img bs=512 count=20480
printf "Creating disk image         $(tput setaf 2)[OK]$(tput sgr0)\n"

(
    echo n                  # create new partition
    echo p                  # make it primary
    echo                    
    echo 
    echo 
    echo t
    echo 1                  # fat 12 label
    echo a
    echo p
    echo w
) | sudo fdisk disk.img

sudo losetup /dev/loop30 disk.img
sudo losetup /dev/loop31 disk.img -o 1048576            # make an offset to loop31 device for the kernel part to be formatted in fat 12 specification

sudo mkfs.fat -F 12 -f 2 /dev/loop31   
# -F 12 -h 0 -s 2 -S 512 -n "TOS"                 # format kernel partition to fat12 
sudo mount /dev/loop31 /mnt/                            # mount to /mnt

printf "Format to FAT-12            $(tput setaf 2)[OK]$(tput sgr0)\n"

sudo grub-install --root-directory=/mnt/ --no-floppy --modules="normal multiboot part_msdos" /dev/loop30

if fdisk -l disk.img | grep "FAT12"
then
    printf "Grub Install check          $(tput setaf 2)[OK]$(tput sgr0)\n"
else
    printf "Grub Install check          $(tput setaf 1)[NOT OK]$(tput sgr0)\n"
fi 

# Copy grub.cfg file to the /mnt
sudo umount /mnt/
sudo losetup -d /dev/loop30
sudo losetup -d /dev/loop31
