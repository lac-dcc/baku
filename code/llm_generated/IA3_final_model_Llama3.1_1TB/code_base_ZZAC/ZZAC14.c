

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function to calculate CPU cycles
uint64_t cpu_cycles(uint64_t instructions, uint64_t cache_references, uint64_t cache_misses, uint64_t branch_instructions) {
    // Assume 1 instruction takes 1 cycle
    uint64_t cycles = instructions;
    // Cache references add cycles
    cycles += cache_references;
    // Cache misses add cycles
    cycles += cache_misses * 10; // Assuming 10 cycles per cache miss
    // Branch instructions add cycles
    cycles += branch_instructions * 2; // Assuming 2 cycles per branch instruction
    return cycles;
}

int main() {
    uint64_t instructions = 2309001;
    uint64_t cache_references = 103065;
    uint64_t cache_misses = 37901;
    uint64_t branch_instructions = 437419;

    uint64_t cycles = cpu_cycles(instructions, cache_references, cache_misses, branch_instructions);

    printf("CPU Cycles: %llu\n", cycles);
    printf("Instructions: %llu\n", instructions);
    printf("Cache References: %llu\n", cache_references);
    printf("Cache Misses: %llu\n", cache_misses);
    printf("Branch Instructions: %llu\n", branch_instructions);

    return 0;
}

