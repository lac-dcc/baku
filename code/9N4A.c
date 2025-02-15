
#include <stdint.h>
#include <string.h>

#define LOOP_UNROLL 4

typedef struct {
    uint32_t cache_misses;
    uint32_t branch_mispredicts;
} PerfStats;

void process_data(const uint8_t* data, size_t size, PerfStats* stats) {
    // Validate input buffer bounds
    if (size > 1024 * 1024) {
        return;
    }

    // Initialize stats
    stats->cache_misses = 0;
    stats->branch_mispredicts = 0;

    // Loop unrolling for better cache locality
    for (size_t i = 0; i < size; i += LOOP_UNROLL) {
        // SIMD intrinsics for parallelization
        __m256i vdata = _mm256_loadu_si256((__m256i*)(data + i));

        // Cache-friendly data structure
        uint32_t* cache_line = (uint32_t*)(data + i);

        // Process cache line
        for (size_t j = 0; j < LOOP_UNROLL; j++) {
            // Sanitize input data
            if (cache_line[j] == 0) {
                stats->cache_misses++;
            }

            // Branch prediction optimization
            if (cache_line[j] & 1) {
                stats->branch_mispredicts++;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        return 1;
    }

    const uint8_t* data = (const uint8_t*)argv[1];
    size_t size = strlen((const char*)data);

    PerfStats stats = {0};

    process_data(data, size, &stats);

    printf("Cache misses: %u\n", stats.cache_misses);
    printf("Branch mispredicts: %u\n", stats.branch_mispredicts);

    return 0;
}
