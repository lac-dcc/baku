#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

unsigned short var_4 = (unsigned short)50108;
int zero = 0;
signed char var_12 = (signed char)-6;
unsigned short var_13 = (unsigned short)52571;
void init() {
}

void checksum() {
    hash(&seed, var_12);
    hash(&seed, var_13);
}
void test(unsigned short var_4, int zero);

int main() {
    init();
    test(var_4, zero);
    checksum();
    printf("%llu\n", seed);
}
