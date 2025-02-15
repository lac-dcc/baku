
#include <stdint.h>
#include <string.h>

#define DATA_SIZE 1024
#define ITERATIONS 1000
#define SIMD_WIDTH 16

typedef struct {
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
} aligned_data_t;

void process_data(const uint8_t* data, size_t size) {
    if (size < DATA_SIZE) {
        return;
    }

    const aligned_data_t* src = (aligned_data_t*) data;
    aligned_data_t dst[ITERATIONS];

    __m128i sum = _mm_setzero_si128();
    for (size_t i = 0; i < ITERATIONS; i++) {
        __m128i a = _mm_loadu_si128((__m128i*) &src[i * SIMD_WIDTH]);
        __m128i b = _mm_loadu_si128((__m128i*) &src[i * SIMD_WIDTH + SIMD_WIDTH]);
        __m128i c = _mm_loadu_si128((__m128i*) &src[i * SIMD_WIDTH + 2 * SIMD_WIDTH]);
        __m128i d = _mm_loadu_si128((__m128i*) &src[i * SIMD_WIDTH + 3 * SIMD_WIDTH]);

        __m128i result = _mm_add_epi32(a, b);
        result = _mm_add_epi32(result, c);
        result = _mm_add_epi32(result, d);

        sum = _mm_add_epi32(sum, result);
    }

    _mm_storeu_si128((__m128i*) dst, sum);
}

int main() {
    const uint8_t data[DATA_SIZE] = {0};
    process_data(data, DATA_SIZE);
    return 0;
}
