
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000
#define M 1000000
#define K 1000000

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
    uint64_t L1_dcache_loads;
    uint64_t L1_dcache_load_misses;
    uint64_t L1_dcache_stores;
    uint64_t L1_dcache_store_misses;
    uint64_t L1_dcache_prefetch_misses;
    uint64_t L1_icache_load_misses;
    uint64_t LLC_loads;
    uint64_t LLC_load_misses;
    uint64_t LLC_stores;
    uint64_t LLC_store_misses;
    uint64_t LLC_prefetch_misses;
    uint64_t dTLB_loads;
    uint64_t dTLB_load_misses;
    uint64_t dTLB_stores;
    uint64_t dTLB_store_misses;
    uint64_t iTLB_loads;
    uint64_t iTLB_load_misses;
} perf_stats;

void process_data(const uint8_t* data, size_t size) {
    perf_stats stats;
    memset(&stats, 0, sizeof(stats));

    for (size_t i = 0; i < size; i += 16) {
        uint64_t block[16];
        memcpy(block, data + i, 16 * sizeof(uint64_t));
        for (size_t j = 0; j < 16; j++) {
            // Do some calculations
            stats.instructions++;
            stats.cache_references++;
            stats.cache_misses++;
            stats.branch_instructions++;
            stats.branch_misses++;
            stats.page_faults++;
            stats.branch_loads++;
            stats.branch_load_misses++;
            stats.L1_dcache_loads++;
            stats.L1_dcache_load_misses++;
            stats.L1_dcache_stores++;
            stats.L1_dcache_store_misses++;
            stats.L1_dcache_prefetch_misses++;
            stats.L1_icache_load_misses++;
            stats.LLC_loads++;
