
#include <stdint.h>

void process_data(const uint8_t* data, size_t size) {
    size_t sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i];
    }
    // Placeholder for actual processing logic
}
