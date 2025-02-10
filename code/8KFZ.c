
#include <stdint.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    // Dummy output to avoid compiler optimizations
    volatile uint64_t dummy = sum;
}

int main(int argc, char* argv[]) {
    // Example usage
    const uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size = sizeof(data) / sizeof(data[0]);

    process_data(data, size);

    return 0;
}
