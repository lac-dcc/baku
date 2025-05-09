#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

unsigned long long int var_1 = 9504800984687462948ULL;
short var_3 = (short)-19903;
int zero = 0;
signed char var_10 = (signed char)-62;
signed char var_11 = (signed char)102;
void init() {
}

void checksum() {
    hash(&seed, var_10);
    hash(&seed, var_11);
}
void test(unsigned long long int var_1, short var_3, int zero);

int main() {
    init();
    test(var_1, var_3, zero);
    checksum();
    printf("%llu\n", seed);
}
