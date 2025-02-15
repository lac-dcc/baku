
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LOOP_UNROLL 16
#define SIMD_WIDTH 4

typedef struct {
  uint32_t cache_misses;
  uint32_t branch_misses;
  uint32_t cache_references;
  uint32_t instructions;
  uint32_t cpu_cycles;
  uint32_t page_faults;
} perf_stats_t;

void process_data(const uint8_t* data, size_t size) {
  perf_stats_t stats = {0};

  // Validate buffer bounds
  if (size < sizeof(perf_stats_t)) {
    return;
  }

  // Unaligned memory access is okay here
  const uint32_t* data32 = (const uint32_t*)data;

  for (size_t i = 0; i < size / sizeof(uint32_t); i++) {
    // Unroll the loop to reduce branch mispredictions
    for (size_t j = 0; j < LOOP_UNROLL; j++) {
      uint32_t value = data32[i * LOOP_UNROLL + j];

      // SIMD intrinsics for cache-friendly memory access
      __m128i vec = _mm_loadu_si128((const __m128i*)(&value));

      // Perform some operation on the vector (e.g., add, multiply)
      __m128i result = _mm_add_epi32(vec, vec);

      // Sanitize the result (e.g., to prevent overflows)
      __m128i sanitized = _mm_min_epi32(result, _mm_set1_epi32(0x7FFFFFFF));

      // Store the result back to memory (aligned access is okay here)
      _mm_store_si128((__m128i*)(&value), sanitized);
    }
  }

  // Update performance statistics
  stats.cache_misses += 0x12345678; // Example value
  stats.branch_misses += 0x87654321; // Example value
  stats.cache_references += size;
  stats.instructions += size * LOOP_UNROLL;
  stats.cpu_cycles += 0x12345678; // Example value
  stats.page_faults += 0x98765432; // Example value

  // Print performance statistics (fuzzer-specific constraint: exclude I/O)
  printf("cache_misses: %u\n", stats.cache_misses);
  printf("branch_misses: %u\n", stats.branch_misses);
  printf("cache_references: %u\n", stats.cache_references);
  printf("instructions: %u\n", stats.instructions);
  printf("cpu_cycles: %u\n", stats.cpu_cycles);
  printf("page_faults: %u\n", stats.page_faults);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    return 1; // Invalid input
  }

  const uint8_t* data = (const uint8_t*)argv[1];
  size_t size = strlen((const char*)data);

  process_data(data, size);

  return 0;
}
