#include <drivers/hdd.h>

#define STATUS_BSY 0x80
#define STATUS_RDY 0x40
#define STATUS_DRQ 0x08
#define STATUS_DF 0x20
#define STATUS_ERR 0x01

static void ATA_wait_BSY();
static void ATA_wait_DRQ();

void read_sectors(uint16_t* target, uint32_t lba, uint32_t sector_count)
{
    ATA_wait_BSY();
    outb(0x1F6, 0xE0 | ((lba >> 24) & 0x0F));
    outb(0x1F2, (uint8_t)sector_count);
    outb(0x1F3, (uint8_t)lba);
    outb(0x1F4, (uint8_t)(lba >> 8));
    outb(0x1F5, (uint8_t)(lba >> 16));
    outb(0x1F7, 0x20);


    for(int i = 0; i < sector_count; i++)
    {
        ATA_wait_BSY();
        ATA_wait_DRQ();

        for(int i = 0; i < 256; i++)
        {
            target[i] = inw(0x1F0);
        }
        target += 256;
    }
}

static void ATA_wait_BSY()
{
    while(inb(0x1F7) & STATUS_BSY);                 // exit when clears
}

static void ATA_wait_DRQ()
{
    uint8_t val = inb(0x1F7);

    while(!val & STATUS_DRQ || !val & STATUS_ERR || !val & STATUS_DF);
    
    if(val & STATUS_ERR) printf("Error Reading Sectors!!!\n");
}