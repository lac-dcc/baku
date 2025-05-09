#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

signed char var_6 = (signed char)109;
signed char var_7 = (signed char)-104;
unsigned char var_8 = (unsigned char)11;
unsigned long long int var_12 = 17874291156833102743ULL;
unsigned short var_13 = (unsigned short)2226;
int var_14 = 970749134;
signed char var_15 = (signed char)-83;
int zero = 0;
long long int var_16 = -8129999808695766015LL;
unsigned long long int var_17 = 5351584244995389570ULL;
unsigned char arr_1 [21] ;
long long int arr_3 [21] ;
unsigned char arr_4 [21] ;
int arr_5 [21] [21] [21] ;
unsigned int arr_6 [21] ;
_Bool arr_7 [21] [21] [21] ;
void init() {
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        arr_1 [i_0] = (unsigned char)250;
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        arr_3 [i_0] = -4887691712195440815LL;
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        arr_4 [i_0] = (unsigned char)162;
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        for (size_t i_1 = 0; i_1 < 21; ++i_1) 
            for (size_t i_2 = 0; i_2 < 21; ++i_2) 
                arr_5 [i_0] [i_1] [i_2] = -135908715;
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        arr_6 [i_0] = 3842518276U;
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        for (size_t i_1 = 0; i_1 < 21; ++i_1) 
            for (size_t i_2 = 0; i_2 < 21; ++i_2) 
                arr_7 [i_0] [i_1] [i_2] = (_Bool)0;
}

void checksum() {
    hash(&seed, var_16);
    hash(&seed, var_17);
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        hash(&seed, arr_4 [i_0] );
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        for (size_t i_1 = 0; i_1 < 21; ++i_1) 
            for (size_t i_2 = 0; i_2 < 21; ++i_2) 
                hash(&seed, arr_5 [i_0] [i_1] [i_2] );
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        hash(&seed, arr_6 [i_0] );
    for (size_t i_0 = 0; i_0 < 21; ++i_0) 
        for (size_t i_1 = 0; i_1 < 21; ++i_1) 
            for (size_t i_2 = 0; i_2 < 21; ++i_2) 
                hash(&seed, arr_7 [i_0] [i_1] [i_2] );
}
void test(signed char var_6, signed char var_7, unsigned char var_8, unsigned long long int var_12, unsigned short var_13, int var_14, signed char var_15, int zero, unsigned char arr_1 [21] , long long int arr_3 [21] );

int main() {
    init();
    test(var_6, var_7, var_8, var_12, var_13, var_14, var_15, zero, arr_1 , arr_3 );
    checksum();
    printf("%llu\n", seed);
}
