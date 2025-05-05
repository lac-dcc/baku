
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define N 10000000
#define M 1000000

uint32_t arr1[N];
uint32_t arr2[N];
uint32_t arr3[N];

void init() {
    for (int i = 0; i < N; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
        arr3[i] = rand() % 100;
    }
}

void loop() {
    for (int i = 0; i < N; i++) {
        uint32_t a = arr1[i] + arr2[i];
        uint32_t b = arr1[i] * arr2[i];
        uint32_t c = a + b;
        uint32_t d = a - b;
        uint32_t e = b * arr3[i];
        uint32_t f = a * arr3[i];
        uint32_t g = c + d;
        uint32_t h = c - d;
        uint32_t i = e + f;
        uint32_t j = e - f;
        uint32_t k = i + h;
        uint32_t l = i - h;
        uint32_t m = j + l;
        uint32_t n = j - l;
    }
}

int main() {
    init();
    loop();
    return 0;
}
