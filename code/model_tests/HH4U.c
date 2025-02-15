
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
   