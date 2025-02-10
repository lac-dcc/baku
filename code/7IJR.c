
#include <stdint.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    // Output the sum (for demonstration purposes)
    // printf("Sum: %lu\n", sum);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return -1;
    }

    const uint8_t* data = (const uint8_t*)argv[1];
    size_t size = atoi(argv[2]);

    process_data(data, size);

    return 0;
}
