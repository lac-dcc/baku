
#include <stdint.h>
#include <stddef.h>

#define MIN_SIZE 1024  // Minimum size to process

void process_data(const uint8_t* data, size_t size) {
    if (size < MIN_SIZE) {
        return;
    }

    // Example of loop unrolling and SIMD (using SSE for demonstration)
    size_t i;
    __m128i sum = _mm_setzero_si128();
    for (i = 0; i + 15 < size; i += 16) {
        sum = _mm_add_epi32(sum, _mm_loadu_si128((const __m128i*)(data + i)));
    }

    // Process remaining elements
    for (; i < size; ++i) {
        sum = _mm_add_epi32(sum, _mm_set1_epi32(data[i]));
    }

    // Extract results (for demonstration purposes, not needed for perf stats)
    int32_t result[4];
    _mm_storeu_si128((__m128i*)result, sum);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return 1;
    }

    const uint8_t* data = (const uint8_t*)argv[1];
    size_t size = atoi(argv[2]);

    process_data(data, size);

    return 0;
}
