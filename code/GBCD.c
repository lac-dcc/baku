
#include <stdint.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    // Unrolling the loop by 4 for better cache utilization
    const uint8_t* end = data + size - (size % 4);
    for (i = 0; i < end; i += 4) {
        sum += data[i] + data[i + 1] + data[i + 2] + data[i + 3];
    }

    // Handle remaining elements
    for (; i < size; i++) {
        sum += data[i];
    }

    // Ensure the sum is used to avoid compiler optimization
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
