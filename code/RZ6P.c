
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOOP_UNROLL 8

typedef struct {
  uint64_t cycles;
  uint64_t instructions;
  uint64_t cache_references;
  uint64_t cache_misses;
  double branch_misses_percent;
  uint64_t branch_instructions;
  uint64_t branch_misses;
  double branch_misses_percent;
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

void process_perf_data(const uint8_t* data, size_t size, perf_stats_t* stats) {
  // Validate buffer bounds
  if (size < sizeof(perf_stats_t)) {
    return;
  }

  // Process data
  stats->cycles = *(uint64_t*)data;
  stats->instructions = *(uint64_t*)(data + sizeof(uint64_t));
  stats->cache_references = *(uint64_t*)(data + 2 * sizeof(uint64_t));
  stats->cache_misses = *(uint64_t*)(data + 3 * sizeof(uint64_t));
  stats->branch_misses_percent = *(double*)(data + 4 * sizeof(uint64_t));
  stats->branch_instructions = *(uint64_t*)(data + 5 * sizeof(uint64_t));
  stats->branch_misses = *(uint64_t*)(data + 6 * sizeof(uint64_t));
  stats->branch_misses_percent = *(double*)(data + 7 * sizeof(uint64_t));
  stats->page_faults = *(uint64_t*)(data + 8 * sizeof(uint64_t));
  stats->branch_loads = *(uint64_t*)(data + 9 * sizeof(uint64_t));
  stats->branch_load_misses = *(uint64_t*)(data + 10 * sizeof(uint64_t));
  stats->L1_dcache_loads = *(uint64_t*)(data + 11 * sizeof(uint64_t));
  stats->L1_dcache_load_misses = *(uint64_t*)(data + 12 * sizeof(uint64_t));
  stats->L1_dcache_stores = *(uint64_t*)(data + 13 * sizeof(uint64_t));
  stats->L1_dcache_store_misses = *(uint64_t*)(data + 14 * sizeof(uint64_t));
  stats->L1_dcache_prefetch_misses = *(uint64_t*)(data + 15 * sizeof(uint64_t));
  stats->L1_icache_load_misses = *(uint64_t*)(data + 16 * sizeof(uint64_t));
  stats->LLC_loads = *(uint64_t*)(data + 17 * sizeof(uint64_t));
  stats->LLC_load_misses = *(uint64_t*)(data + 18 * sizeof(uint64_t));
  stats->LLC_stores = *(uint64_t*)(data + 19 * sizeof(uint64_t));
  stats->LLC_store_misses = *(uint64_t*)(data + 20 * sizeof(uint64_t));
  stats->LLC_prefetch_misses = *(uint64_t*)(data + 21 * sizeof(uint64_t));
  stats->dTLB_loads = *(uint64_t*)(data + 22 * sizeof(uint64_t));
  stats->dTLB_load_misses = *(uint64_t*)(data + 23 * sizeof(uint64_t));
  stats->dTLB_stores = *(uint64_t*)(data + 24 * sizeof(uint64_t));
  stats->dTLB_store_misses = *(uint64_t*)(data + 25 * sizeof(uint64_t));
  stats->iTLB_loads = *(uint64_t*)(data + 26 * sizeof(uint64_t));
  stats->iTLB_load_misses = *(uint64_t*)(data + 27 * sizeof(uint64_t));
}

int main() {
  const uint8_t data[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
  size_t size = sizeof(data);

  perf_stats_t stats;
  process_perf_data(data, size, &stats);

  return 0;
}
