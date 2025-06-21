
#include <stdio.h>

int main() {
    unsigned long long int cycles, instructions, cache_references, cache_misses, branch_instructions;
    FILE *fp;
    char line[256];

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    if (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "cpu %llu %llu %llu %llu %llu", &cycles, &instructions, &cache_references, &cache_misses, &branch_instructions);
    }

    fclose(fp);

    printf("CPU Cycles: %llu\n", cycles);
    printf("Instructions: %llu\n", instructions);
    printf("Cache References: %llu\n", cache_references);
    printf("Cache Misses: %llu\n", cache_misses);
    printf("Branch Instructions: %llu\n", branch_instructions);

    return 0;
}
