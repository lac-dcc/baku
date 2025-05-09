#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

unsigned int var_0 = 3462249879U;
short var_6 = (short)8591;
int zero = 0;
unsigned int var_12 = 2323568796U;
short var_13 = (short)-22541;
void init() {
}

void checksum() {
    hash(&seed, var_12);
    hash(&seed, var_13);
}
void test(unsigned int var_0, short var_6, int zero);

int main() {
    init();
    test(var_0, var_6, zero);
    checksum();
    printf("%llu\n", seed);
}
