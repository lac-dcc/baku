
#include <stdint.h>
#include <stddef.h>

#define UNROLL_FACTOR 4

void process_data(const uint8_t* data, size_t size) {
    size_t i;
    uint64_t sum = 0;

    for (i = 0; i < size; i += UNROLL_FACTOR) {
        sum += data[i];
        sum += data[i + 1];
        sum += data[i + 2];
        sum += data[i + 3];
    }

    for (; i < size; ++i) {
        sum += data[i];
    }

    // Dummy output to avoid compiler optimization
    (void)sum;
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
