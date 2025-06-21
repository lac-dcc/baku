
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 10000000

int main() {
    uint64_t cycles = 0;
    uint64_t instructions = 0;
    uint64_t cache_references = 0;
    uint64_t cache_misses = 0;
    uint64_t branch_instructions = 0;

    clock_t start_time = clock();

    for (int i = 0; i < ITERATIONS; i++) {
        int x = 0;
        for (int j = 0; j < 1000; j++) {
            x += j;
        }
        instructions++;

        if (x!= 4950) {
            cache_misses++;
            cache_references++;
        } else {
            cache_references++;
        }

        if (j!= 1000) {
            branch_instructions++;
        }

        cycles++;
    }

    clock_t end_time = clock();

    printf("Cycles: %llu\n", cycles);
    printf("Instructions: %llu\n", instructions);
    printf("Cache References: %llu\n", cache_references);
    printf("Cache Misses: %llu\n", cache_misses);
    printf("Branch Instructions: %llu\n", branch_instructions);

    printf("Time elapsed: %.6f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}
