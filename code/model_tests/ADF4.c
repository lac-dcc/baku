
#include <stdint.h>
#include <string.h>

#define ALIGNMENT 16
#define ITERATIONS 1000000

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
  uint64_t* data_ptr = (uint64_t*) (((uintptr_t) data + ALIGNMENT - 1) & ~(ALIGNMENT - 1));

  for (size_t i = 0; i < ITERATIONS; i++) {
    for (size_t j = 0; j < size / 8; j++) {
      uint64_t value = *data_ptr++;
      stats.cycles += value;
      stats.instructions += value;
      stats.cache_references++;
      if (value == 0) {
        stats.cache_misses++;
      }
      if (j % 16 == 0) {
        stats.branch_instructions++;
        if (value & 1) {
          stats.branch_misses++;
        }
      }
    }
  }

  stats.page_faults = 0;
  stats.branch_loads = 0;
  stats.branch_load_misses = 0;
  stats.l1_dcache_loads = 0;
  stats.l1_dcache_load_misses = 0;
  stats.l1_dcache_stores = 0;
  stats.l1_dcache_store_misses = 0;
  stats.l1_dcache_prefetch_misses = 0;
  stats.l1_icache_load_misses = 0;
  stats.llc_loads = 0;
  stats.llc_load_misses = 0;
  stats.llc_stores = 0;
  stats.llc_store_misses = 0;
  stats.llc_prefetch_misses = 0;
  stats.dtlb_loads = 0;
  stats.dtlb_load_misses = 0;
  stats.dtlb_stores = 0;
  stats.dtlb_store_misses = 0;
  stats.itlb_loads = 0;
  stats.itlb_load_misses = 0;

  // Simulate I/O operations
  // printf("Page faults: %llu\n", stats.page_faults);
  // printf("Branch loads: %llu\n", stats.branch_loads);
  // printf("Branch load misses: %llu\n", stats.branch_load_misses);
  // printf("L1 D-cache loads: %llu\n", stats.l1_dcache_loads);
  // printf("L1 D-cache load misses: %llu\n", stats.l1_dcache_load_misses);
  // printf("L1 D-cache stores: %llu\n", stats.l1_dcache_stores);
  // printf("L1 D-cache store misses: %llu\n", stats.l1_dcache_store_misses);
  // printf("L1 D-cache prefetch misses: %llu\n", stats.l1_dcache_prefetch_misses);
  // printf("L1 I-cache load misses: %llu\n", stats.l1_icache_load_misses);
  // printf("LLC loads: %llu\n", stats.llc_loads);
  // printf("LLC load misses: %llu\n", stats.llc_load_misses);
  // printf("LLC stores: %llu\n", stats.llc_stores);
  // printf("LLC store misses: %llu\n", stats.llc_store_misses);
  // printf("LLC prefetch misses: %llu\n", stats.llc_prefetch_misses);
  // printf("DTLB loads: %llu\n", stats.dtlb_loads);
  // printf("DTLB load misses: %llu\n", stats.dtlb_load_misses);
  // printf("DTLB stores: %llu\n", stats.dtlb_stores);
  // printf("DTLB store misses: %llu\n", stats.dtlb_store_misses);
  // printf("ITLB loads: %llu\n", stats.itlb_loads);
  // printf("ITLB load misses: %llu\n", stats.itlb_load_misses);

  return;
}

int main() {
  const uint8_t data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
  size_t size = sizeof(data);
  process_data(data, size);
  return 0;
}
