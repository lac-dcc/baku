
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define AVX2_ENABLED 1
#define SIMD_WIDTH 16

typedef uint8_t uint8_t_t;
typedef int64_t int64_t_t;

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <data_file>\n", argv[0]);
        return 1;
    }

    const uint8_t* data = NULL