
#include <stdint.h>
#include <stddef.h>

#define UNROLL_FACTOR 4

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    // Process data
    for (i = 0; i < size; i += UNROLL_FACTOR) {
        sum += data[i];
        sum += data[i + 1];
        sum += data[i + 2];
        sum += data[i + 3];
    }

    // Handle remaining elements
    for (; i < size; ++i) {
        sum += data[i];
    }

    // Dummy output to avoid optimization
    volatile uint64_t dummy = sum;
}

int main(int argc, char* argv[]) {
    const uint8_t data[] = { /* Your data here */ };
    size_t size = sizeof(data);

    process_data(data, size);

    return 0;
}
