#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

unsigned short var_5 = (unsigned short)46063;
unsigned short var_9 = (unsigned short)63817;
int zero = 0;
unsigned char var_10 = (unsigned char)169;
_Bool var_11 = (_Bool)1;
void init() {
}

void checksum() {
    hash(&seed, var_10);
    hash(&seed, var_11);
}
void test(unsigned short var_5, unsigned short var_9, int zero);

int main() {
    init();
    test(var_5, var_9, zero);
    checksum();
    printf("%llu\n", seed);
}
