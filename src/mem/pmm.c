#include <mem/pmm.h>

static uint32_t         _mmngr_memory_size = 0;
static uint32_t         _mmngr_used_blocks = 0;
static uint32_t         _mmngr_max_blocks = 0;
static uint32_t*        _mmngr_memory_map = 0;

void mmap_set(uint32_t bit)
{
    _mmngr_memory_map[bit / 32] |= (1 << (bit % 32));
}

void mmap_unset(uint32_t bit)
{
    _mmngr_memory_map[bit / 32] &= ~ (1 << (bit % 32));
}

boolean mmap_test(uint32_t bit)
{
    return _mmngr_memory_map[bit / 32] & (1 << (bit % 32));
}

uint32_t returnMemoryMap()
{
    return *_mmngr_memory_map;
}

uint32_t mmap_first_free()
{
    for(uint32_t i = 0; i < pmmngr_get_block_count() / 32; i++)
    {
        if(_mmngr_memory_map[i] != 0xFFFFFFFF)
        {
            for(uint32_t j = 0; j < 32; j++)
            {
                int bit = 1 << j;
                if(!(_mmngr_memory_map[i] & bit))
                    return i * 4 * 8 + j;
            }
        }
    }
    return -1;
}

void pmmngr_init(uint32_t memSize, uint32_t bitmap)
{
    _mmngr_memory_size = memSize;
    _mmngr_memory_map = (uint32_t*)bitmap;
    _mmngr_max_blocks = (pmmngr_get_memory_size() * 1024) / PMMNGR_BLOCK_SIZE;
    _mmngr_used_blocks = pmmngr_get_block_count();

    // All memory in use by default
    memset(_mmngr_memory_map, 0xF, pmmngr_get_block_count() / PMMNGR_BLOCKS_PER_BYTE);
}

void pmmngr_init_region(uint32_t base, uint32_t size)
{
    int align = base / PMMNGR_BLOCK_SIZE;
    int blocks = size / PMMNGR_BLOCK_SIZE;

    for(; blocks > 0; blocks--)
    {
        mmap_unset(align++);
        _mmngr_used_blocks--;
    }

    mmap_set(0);        // first block always set
}

void pmmngr_deinit_region(uint32_t base, uint32_t size)
{
    int align = base / PMMNGR_BLOCK_SIZE;
    int blocks = size / PMMNGR_BLOCK_SIZE;

    for(; blocks > 0; blocks--)
    {
        mmap_set(align++);
        _mmngr_used_blocks++;
    }
}

// Allocate single block of memory
void* pmmngr_alloc_block()
{
    if(pmmngr_get_free_block_count() <= 0)
        return 0;           // out of memory
    uint32_t frame = mmap_first_free();

    if (frame == -1)
        return 0;           // out of memory
    
    mmap_set(frame);

    uint32_t addr = frame * PMMNGR_BLOCK_SIZE;
    _mmngr_used_blocks++;
    return (void*)addr;
}

// Free single block
void pmmngr_free_block(void* p)
{
    uint32_t addr = (uint32_t)p;
    uint32_t frame = addr / PMMNGR_BLOCK_SIZE;

    mmap_unset(frame);
    _mmngr_used_blocks--;
}

uint32_t pmmngr_get_memory_size () {

	return _mmngr_memory_size;
}

uint32_t pmmngr_get_block_count () {

	return _mmngr_max_blocks;
}

uint32_t pmmngr_get_use_block_count () {

	return _mmngr_used_blocks;
}

uint32_t pmmngr_get_free_block_count () {

	return _mmngr_max_blocks - _mmngr_used_blocks;
}

uint32_t pmmngr_get_block_size () {

	return PMMNGR_BLOCK_SIZE;
}