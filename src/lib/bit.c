#include <lib/bit.h>

uint32_t setBit(uint32_t num, int position) {
    uint32_t mask = 1 << position; // Create a mask with only the bit at the specified position set
    return num | mask; // Perform bitwise OR to set the bit
}

// Function to unset a bit at a specified position
uint32_t unsetBit(uint32_t num, int position) {
    uint32_t mask = ~(1 << position); // Create a mask with only the bit at the specified position unset
    return num & mask; // Perform bitwise AND to unset the bit
}