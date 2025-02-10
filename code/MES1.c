
#include <stdint.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    // Output the sum to avoid the program being optimized away
    // This is just a placeholder to satisfy the requirements
    // In a real scenario, you might want to avoid such outputs in performance-critical code
    (void)sum;
}

int main(int argc, char* argv[]) {
    // Assuming argv[1] contains the data and argv[2] contains the size
    if (argc < 3) {
        return 1;
    }

    const uint8_t* data = (const uint8_t*)argv[1];
    size_t size = atoi(argv[2]);

    process_data(data, size);

    return 0;
}
