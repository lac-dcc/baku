
#include <stdint.h>
#include <stddef.h>

#define UNROLL_FACTOR 8

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    // Align data to cache line size for better cache performance
    const uint8_t* aligned_data = (const uint8_t*)(((size_t)data + 63) & ~63);
    size_t aligned_size = size;

    // Process data
    for (i = 0; i < aligned_size; i += 64) {
        // Unroll the loop for better instruction-level parallelism
        #pragma unroll(UNROLL_FACTOR)
        for (int j = 0; j < 8; ++j) {
            sum += aligned_data[i + j];
        }
    }

    // Handle remaining data
    for (i = aligned_size; i < size; ++i) {
        sum += aligned_data[i];
    }

    // Dummy output to avoid optimization removal
    (void)sum;
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
