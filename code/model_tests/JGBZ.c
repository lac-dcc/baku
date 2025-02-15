
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    uint64_t cpu_cycles;
    uint64_t instructions;
    uint64_t cache_references;
    uint64_t cache_misses;
    uint64_t branch_instructions;
    uint64_t branch_misses;
    uint64_t page_faults;
    uint64_t branch_loads;
    uint64_t branch_load_misses;
    uint64_t l1_dcache_loads;
    uint64_t l1_dcache_load_misses;
    uint64_t l1_dcache_stores;
    uint64_t l1_dcache_store_misses;
    uint64_t l1_dcache_prefetch_misses;
    uint64_t l1_icache_load_misses;
    uint64_t llc_loads;
    uint64_t llc_load_misses;
    uint64_t llc_stores;
    uint64_t llc_store_misses;
    uint64_t llc_prefetch_misses;
    uint64_t dtlb_loads;
    uint64_t dtlb_load_misses;
    uint64_t dtlb_stores;
    uint64_t dtlb_store_misses;
    uint64_t itlb_loads;
    uint64_t itlb_load_misses;
} perf_stats_t;

void process_data(const uint8_t* data, size_t size) {
    perf_stats_t stats = {0};
    for (size_t i = 0; i < size; i++) {
        if (i % 16 == 0) {
            // Unaligned load
            uint64_t temp = *(uint64_t*)(data + i);
            stats.cpu_cycles += 100;
            stats.instructions += 16;
            stats.cache_references += 1;
            stats.cache_misses += 1;
            stats.branch_instructions += 16;
            stats.branch_misses += 1;
        } else {
            // Aligned load
            uint64_t temp = *(uint64_t*)(data + i);
            stats.cpu_cycles += 50;
            stats.instructions += 8;
            stats.cache_references += 1;
            stats.cache_misses += 0;
            stats.branch_instructions += 8;
            stats.branch_misses += 0;
        }
    }
    // Store aligned
    *(uint64_t*)(data + size)