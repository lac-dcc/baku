
#include <stdint.h>
#include <stddef.h>

#define UNROLL_FACTOR 4

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    // Output the sum (for demonstration purposes)
    // printf("Sum: %lu\n", sum);
}

int main() {
    const uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example data
    size_t size = sizeof(data) / sizeof(data[0]);

    process_data(data, size);

    return 0;
}
