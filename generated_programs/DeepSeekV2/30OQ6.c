
#include <stdio.h>

int main() {
    unsigned long long int cycles, instructions, cache_references, cache_misses, branch_instructions;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Failed to open /proc/stat\n");
        return 1;
    }

    if (fscanf(fp, "cpu %llu %llu %llu %llu %llu", &cycles, &instructions, &cache_references, &cache_misses, &branch_instructions) != 5) {
        printf("Failed to read /proc/stat\n");
        return 1;
    }

    fclose(fp);

    printf("Cycles: %llu\n", cycles);
    printf("Instructions: %llu\n", instructions);
    printf("Cache References: %llu\n", cache_references);
    printf("Cache Misses: %llu\n", cache_misses);
    printf("Branch Instructions: %llu\n", branch_instructions);

    return 0;
}
