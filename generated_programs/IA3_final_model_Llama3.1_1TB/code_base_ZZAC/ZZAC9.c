
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Function to generate random numbers within a given range
uint32_t generate_random_number(uint32_t min, uint32_t max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate a cache miss
void cache_miss_simulation() {
    // Simulate a cache miss by accessing a random memory location
    uint32_t* ptr = (uint32_t*)malloc(sizeof(uint32_t));
    *ptr = generate_random_number(0, 1000000);
    free(ptr);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Simulate a large number of cache misses
    for (int i = 0; i < 100000; i++) {
        cache_miss_simulation();
    }

    // Simulate a large number of branch instructions
    for (int i = 0; i < 200000; i++) {
        if (generate_random_number(0, 1) == 0) {
            // Simulate a branch instruction
            continue;
        } else {
            // Simulate a non-branch instruction
            generate_random_number(0, 1000000);
        }
    }

    return 0;
}
