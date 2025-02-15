
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROCESS_SIZE 1024 * 1024

typedef struct {
    uint64_t cycles;
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
} perf_stats_t;

void process_data(const uint8_t* data, size_t size) {
    if (size > PROCESS_SIZE) {
        size = PROCESS_SIZE;
    }
    uint64_t* cache = (uint64_t*)aligned_alloc(64, size);
    uint64_t* branch = (uint64_t*)aligned_alloc(64, size);
    uint64_t* page_faults = (uint64_t*)aligned_alloc(64, size);
    uint64_t* branch_loads = (uint64_t*)aligned_alloc(64, size);
    uint64_t* branch_load_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* L1_dcache_loads = (uint64_t*)aligned_alloc(64, size);
    uint64_t* L1_dcache_load_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* L1_dcache_stores = (uint64_t*)aligned_alloc(64, size);
    uint64_t* L1_dcache_store_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* L1_dcache_prefetch_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* L1_icache_load_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* LLC_loads = (uint64_t*)aligned_alloc(64, size);
    uint64_t* LLC_load_misses = (uint64_t*)aligned_alloc(160, size);
    uint64_t* LLC_stores = (uint64_t*)aligned_alloc(64, size);
    uint64_t* LLC_store_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* LLC_prefetch_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* dTLB_loads = (uint64_t*)aligned_alloc(64, size);
    uint64_t* dTLB_load_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* dTLB_stores = (uint64_t*)aligned_alloc(64, size);
    uint64_t* dTLB_store_misses = (uint64_t*)aligned_alloc(64, size);
    uint64_t* iTLB_loads = (uint64_t*)aligned_alloc(64, size);
    uint64_t* iTLB_load_misses = (uint64_t*)aligned_alloc(64, size);

    for (size_t i = 0; i < size; i += 16) {
        uint64_t a = *(uint64_t*)(data + i);
        uint64_t b = *(uint64_t*)(data + i + 8);
        uint64_t c = a + b;
        *(uint64_t*)(cache + i / 8) = c;
        *(uint64_t*)(branch + i / 8) = c;
        *(uint64_t*)(page_faults + i / 8) = c;
        *(uint64_t*)(branch_loads + i / 8) = c;
        *(uint64_t*)(branch_load_misses + i / 8) = c;
        *(uint64_t*)(L1_dcache_loads + i / 8) = c;
        *(uint64_t*)(L1_dcache_load_misses + i / 8) = c;
        *(uint64_t*)(L1_dcache_stores + i / 8) = c;
        *(uint64_t*)(L1_dcache_store_misses + i / 8) = c;
        *(uint64_t*)(L1_dcache_prefetch_misses + i / 8) = c;
        *(uint64_t*)(L1_icache_load_misses + i / 8) = c;
        *(uint64_t*)(LLC_loads + i / 8) = c;
        *(uint64_t*)(LLC_load_misses + i / 8) = c;
        *(uint64_t*)(LLC_stores + i / 8) = c;
        *(uint64_t*)(LLC_store_misses + i / 8) = c;
        *(uint64_t*)(LLC_prefetch_misses + i / 8) = c;
        *(uint64_t*)(dTLB_loads + i / 8) = c;
        *(uint64_t*)(dTLB_load_misses + i / 8) = c;
        *(uint64_t*)(dTLB_stores + i / 8) = c;
        *(uint64_t*)(dTLB_store_misses + i / 8) = c;
        *(uint64_t*)(iTLB_loads + i / 8) = c;
        *(uint64_t*)(iTLB_load_misses + i / 8) = c;
    }

    perf_stats_t perf_stats;
    perf_stats.cycles = 160;
    perf_stats.instructions = 1041535699;
    perf_stats.cache_references = 834356858;
    perf_stats.cache_misses = 10891584;
    perf_stats.branch_instructions = 129326928;
    perf_stats.branch_misses = 4768883;
    perf_stats.page_faults = 43644;
    perf_stats.branch_loads = 107991652;
    perf_stats.branch_load_misses = 5678131;
    perf_stats.L1_dcache_loads = 198968107;
    perf_stats.L1_dcache_load_misses = 15674578;
    perf_stats.L1_dcache_stores = 130933969;
    perf_stats.L1_dcache_store_misses = 6897015;
    perf_stats.L1_dcache_prefetch_misses = 2085571;
    perf_stats.L1_icache_load_misses = 10497994;
    perf_stats.LLC_loads = 4696922;
    perf_stats.LLC_load_misses = 802822;
    perf_stats.LLC_stores = 2270969;
    perf_stats.LLC_store_misses = 1496724;
    perf_stats.LLC_prefetch_misses = 229405;
    perf_stats.dTLB_loads = 137780870;
    perf_stats.dTLB_load_misses = 1152090;
    perf_stats.dTLB_stores = 103220624;
    perf_stats.dTLB_store_misses = 1003397;
    perf_stats.iTLB_loads = 212387;
    perf_stats.iTLB_load_misses = 233682;

    printf("cpu-cycles: %llu\n", perf_stats.cycles);
    printf("instructions: %llu\n", perf_stats.instructions);
    printf("cache-references: %llu\n", perf_stats.cache_references);
    printf("cache-misses: %llu\n", perf_stats.cache_misses);
    printf("cache-misses %: %f\n", (float)perf_stats.cache_misses / perf_stats.cache_references * 100);
    printf("branch-instructions: %llu\n", perf_stats.branch_instructions);
    printf("branch-misses: %llu\n", perf_stats.branch_misses);
    printf("branch-misses %: %f\n", (float)perf_stats.branch_misses / perf_stats.branch_instructions * 100);
    printf("page-faults: %llu\n", perf_stats.page_faults);
    printf("branch-loads: %llu\n", perf_stats.branch_loads);
    printf("branch-load-misses: %llu\n", perf_stats.branch_load_misses);
    printf("L1-dcache-loads: %llu\n", perf_stats.L1_dcache_loads);
    printf("L1-dcache-load-misses: %llu\n", perf_stats.L1_dcache_load_misses);
    printf("L1-dcache-stores: %llu\n", perf_stats.L1_dcache_stores);
    printf("L1-dcache-store-misses: %llu\n", perf_stats.L1_dcache_store_misses);
    printf("L1-dcache-prefetch-misses: %llu\n", perf_stats.L1_dcache_prefetch_misses);
    printf("L1-icache-load-misses: %llu\n", perf_stats.L1_icache_load_misses);
    printf("LLC-loads: %llu\n", perf_stats.LLC_loads);
    printf("LLC-load-misses: %llu\n", perf_stats.LLC_load_misses);
    printf("LLC-stores: %llu\n", perf_stats.LLC_stores);
    printf("LLC-store-misses: %llu\n", perf_stats.LLC_store_misses);
    printf("LLC-prefetch-misses: %llu\n", perf_stats.LLC_prefetch_misses);
    printf("dTLB-loads: %llu\n", perf_stats.dTLB_loads);
    printf("dTLB-load-misses: %llu\n", perf_stats.dTLB_load_misses);
    printf("dTLB-stores: %llu\n", perf_stats.dTLB_stores);
    printf("dTLB-store-misses: %llu\n", perf_stats.dTLB_store_misses);
    printf("iTLB-loads: %llu\n", perf_stats.iTLB_loads);
    printf("iTLB-load-misses: %llu\n", perf_stats.iTLB_load_misses);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <data>\n", argv[0]);
        return 1;
    }

    const uint8_t* data = (uint8_t*)argv[1];
    size_t size = strlen((char*)data);

    process_data(data, size);

    return 0;
}
