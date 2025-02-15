
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
  uint64_t* ptr = (uint64_t*)data;
  for (int i = 0; i < sizeof(perf_stats_t) / sizeof(uint64_t); i += LOOP_UNROLL) {
    uint64_t value = *ptr++;
    switch (i) {
      case 0:
        stats->cycles = value;
        break;
      case 1:
        stats->instructions = value;
        break;
      case 2:
        stats->cache_references = value;
        break;
      case 3:
        stats->cache_misses = value;
        break;
      case 4:
        stats->branch_misses_percent = (double)value;
        break;
      case 5:
        stats->branch_instructions = value;
        break;
      case 6:
        stats->branch_misses = value;
        break;
      case 7:
        stats->branch_misses_percent = (double)value;
        break;
      case 8:
        stats->page_faults = value;
        break;
      case 9:
        stats->branch_loads = value;
        break;
      case 10:
        stats->branch_load_misses = value;
        break;
      case 11:
        stats->L1_dcache_loads = value;
        break;
      case 12:
        stats->L1_dcache_load_misses = value;
        break;
      case 13:
        stats->L1_dcache_stores = value;
        break;
      case 14:
        stats->L1_dcache_store_misses = value;
        break;
      case 15:
        stats->L1_dcache_prefetch_misses = value;
        break;
      case 16:
        stats->L1_icache_load_misses = value;
        break;
      case 17:
        stats->LLC_loads = value;
        break;
      case 18:
        stats->LLC_load_misses = value;
        break;
      case 19:
        stats->LLC_stores = value;
        break;
      case 20:
        stats->LLC_store_misses = value;
        break;
      case 21:
        stats->LLC_prefetch_misses = value;
        break;
      case 22:
        stats->dTLB_loads = value;
        break;
      case 23:
        stats->dTLB_load_misses = value;
        break;
      case 24:
        stats->dTLB_stores = value;
        break;
      case 25:
        stats->dTLB_store_misses = value;
        break;
      case 26:
        stats->iTLB_loads = value;
        break;
      case 27:
        stats->iTLB_load_misses = value;
        break;
    }
  }
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
