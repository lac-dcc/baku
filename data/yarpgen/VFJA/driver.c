#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

long long int var_1 = 4244380162215177844LL;
signed char var_2 = (signed char)-81;
short var_4 = (short)13077;
signed char var_6 = (signed char)-61;
unsigned long long int var_9 = 5948341898829495150ULL;
signed char var_10 = (signed char)-1;
unsigned int var_11 = 1111164104U;
unsigned char var_14 = (unsigned char)155;
signed char var_15 = (signed char)113;
short var_17 = (short)-4470;
unsigned int var_18 = 140760519U;
int zero = 0;
unsigned int var_19 = 609355332U;
unsigned int var_20 = 2480471226U;
int var_21 = -1200167355;
unsigned char var_22 = (unsigned char)206;
signed char var_23 = (signed char)94;
unsigned char var_24 = (unsigned char)62;
signed char arr_11 [17] [17] [17] [17] [17] [17] ;
unsigned int arr_12 [17] ;
unsigned int arr_13 [17] [17] [17] ;
void init() {
    for (size_t i_0 = 0; i_0 < 17; ++i_0) 
        for (size_t i_1 = 0; i_1 < 17; ++i_1) 
            for (size_t i_2 = 0; i_2 < 17; ++i_2) 
                for (size_t i_3 = 0; i_3 < 17; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 17; ++i_4) 
                        for (size_t i_5 = 0; i_5 < 17; ++i_5) 
                            arr_11 [i_0] [i_1] [i_2] [i_3] [i_4] [i_5] = (i_2 % 2 == 0) ? (signed char)-81 : (signed char)125;
    for (size_t i_0 = 0; i_0 < 17; ++i_0) 
        arr_12 [i_0] = (i_0 % 2 == 0) ? 3539516864U : 1250852591U;
    for (size_t i_0 = 0; i_0 < 17; ++i_0) 
        for (size_t i_1 = 0; i_1 < 17; ++i_1) 
            for (size_t i_2 = 0; i_2 < 17; ++i_2) 
                arr_13 [i_0] [i_1] [i_2] = (i_1 % 2 == 0) ? 4145375593U : 721476920U;
}

void checksum() {
    hash(&seed, var_19);
    hash(&seed, var_20);
    hash(&seed, var_21);
    hash(&seed, var_22);
    hash(&seed, var_23);
    hash(&seed, var_24);
    for (size_t i_0 = 0; i_0 < 17; ++i_0) 
        for (size_t i_1 = 0; i_1 < 17; ++i_1) 
            for (size_t i_2 = 0; i_2 < 17; ++i_2) 
                for (size_t i_3 = 0; i_3 < 17; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 17; ++i_4) 
                        for (size_t i_5 = 0; i_5 < 17; ++i_5) 
                            hash(&seed, arr_11 [i_0] [i_1] [i_2] [i_3] [i_4] [i_5] );
    for (size_t i_0 = 0; i_0 < 17; ++i_0) 
        hash(&seed, arr_12 [i_0] );
    for (size_t i_0 = 0; i_0 < 17; ++i_0) 
        for (size_t i_1 = 0; i_1 < 17; ++i_1) 
            for (size_t i_2 = 0; i_2 < 17; ++i_2) 
                hash(&seed, arr_13 [i_0] [i_1] [i_2] );
}
void test(long long int var_1, signed char var_2, short var_4, signed char var_6, unsigned long long int var_9, signed char var_10, unsigned int var_11, unsigned char var_14, signed char var_15, short var_17, unsigned int var_18, int zero);

int main() {
    init();
    test(var_1, var_2, var_4, var_6, var_9, var_10, var_11, var_14, var_15, var_17, var_18, zero);
    checksum();
    printf("%llu\n", seed);
}
