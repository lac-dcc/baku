#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

unsigned long long int var_0 = 5079549603781981168ULL;
signed char var_1 = (signed char)68;
unsigned long long int var_3 = 10251430654876099435ULL;
unsigned long long int var_4 = 12994674174267215158ULL;
signed char var_5 = (signed char)66;
unsigned int var_6 = 624013973U;
signed char var_7 = (signed char)-47;
unsigned int var_9 = 2402877492U;
short var_12 = (short)9104;
short var_13 = (short)16359;
int var_14 = 1182634744;
int zero = 0;
unsigned long long int var_17 = 7921309849915873833ULL;
short var_18 = (short)26260;
signed char var_19 = (signed char)83;
unsigned char var_20 = (unsigned char)164;
_Bool var_21 = (_Bool)1;
unsigned short var_22 = (unsigned short)1696;
signed char var_23 = (signed char)7;
unsigned short var_24 = (unsigned short)8740;
unsigned char var_25 = (unsigned char)174;
void init() {
}

void checksum() {
    hash(&seed, var_17);
    hash(&seed, var_18);
    hash(&seed, var_19);
    hash(&seed, var_20);
    hash(&seed, var_21);
    hash(&seed, var_22);
    hash(&seed, var_23);
    hash(&seed, var_24);
    hash(&seed, var_25);
}
void test(unsigned long long int var_0, signed char var_1, unsigned long long int var_3, unsigned long long int var_4, signed char var_5, unsigned int var_6, signed char var_7, unsigned int var_9, short var_12, short var_13, int var_14, int zero);

int main() {
    init();
    test(var_0, var_1, var_3, var_4, var_5, var_6, var_7, var_9, var_12, var_13, var_14, zero);
    checksum();
    printf("%llu\n", seed);
}
