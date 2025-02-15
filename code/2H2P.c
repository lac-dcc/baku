
#include <stdint.h>
#include <string.h>
#include <immintrin.h>

void process_data(const uint8_t* data, size_t size) {
    // Validate input buffer bounds
    if (size == 0 || data == NULL) {
        return;
    }

    // Process data in chunks to reduce cache misses
    for (size_t i = 0; i < size; i += 64) { // Unroll loop for better cache locality
        const uint8_t* chunk = data + i;
        size_t chunk_size = (size - i <= 64)? size - i : 64;

        // Use SIMD intrinsics for vectorized operations
        __m256i vec = _mm256_loadu