#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

unsigned char var_0 = (unsigned char)97;
long long int var_1 = -789066429915644342LL;
unsigned long long int var_2 = 8521773750601585031ULL;
unsigned short var_3 = (unsigned short)4457;
unsigned short var_5 = (unsigned short)48945;
short var_6 = (short)-16197;
unsigned char var_7 = (unsigned char)160;
unsigned short var_8 = (unsigned short)40810;
short var_9 = (short)30880;
int var_11 = 355302574;
short var_12 = (short)-3459;
short var_13 = (short)27170;
short var_14 = (short)-22020;
int zero = 0;
unsigned int var_17 = 1599236172U;
short var_18 = (short)13411;
int var_19 = -1474049425;
short var_20 = (short)-126;
long long int var_21 = 389453530226737085LL;
int var_22 = 136398342;
int var_23 = -2000313515;
unsigned short var_24 = (unsigned short)50418;
unsigned int var_25 = 1329386066U;
unsigned short var_26 = (unsigned short)38513;
unsigned long long int arr_0 [23] [23] ;
unsigned char arr_1 [23] [23] ;
unsigned char arr_3 [23] [23] ;
unsigned long long int arr_7 [23] ;
long long int arr_11 [10] ;
unsigned char arr_4 [23] [23] ;
unsigned long long int arr_5 [23] [23] ;
_Bool arr_6 [23] ;
long long int arr_9 [23] ;
int arr_10 [23] ;
unsigned int arr_14 [10] ;
void init() {
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_0 [i_0] [i_1] = (i_1 % 2 == 0) ? 18416509962071802727ULL : 15346616257753034676ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_1 [i_0] [i_1] = (i_0 % 2 == 0) ? (unsigned char)154 : (unsigned char)96;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_3 [i_0] [i_1] = (i_0 % 2 == 0) ? (unsigned char)237 : (unsigned char)118;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_7 [i_0] = 7470450577164132619ULL;
    for (size_t i_0 = 0; i_0 < 10; ++i_0) 
        arr_11 [i_0] = -6008490230941624631LL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_4 [i_0] [i_1] = (i_1 % 2 == 0) ? (unsigned char)66 : (unsigned char)185;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_5 [i_0] [i_1] = (i_0 % 2 == 0) ? 378766195943370071ULL : 2834194296737461328ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_6 [i_0] = (i_0 % 2 == 0) ? (_Bool)1 : (_Bool)1;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_9 [i_0] = (i_0 % 2 == 0) ? 4813923403429725239LL : -534922501998414033LL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_10 [i_0] = (i_0 % 2 == 0) ? -81049283 : -611572376;
    for (size_t i_0 = 0; i_0 < 10; ++i_0) 
        arr_14 [i_0] = 68884863U;
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
    hash(&seed, var_26);
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            hash(&seed, arr_4 [i_0] [i_1] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            hash(&seed, arr_5 [i_0] [i_1] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        hash(&seed, arr_6 [i_0] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        hash(&seed, arr_9 [i_0] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        hash(&seed, arr_10 [i_0] );
    for (size_t i_0 = 0; i_0 < 10; ++i_0) 
        hash(&seed, arr_14 [i_0] );
}
void test(unsigned char var_0, long long int var_1, unsigned long long int var_2, unsigned short var_3, unsigned short var_5, short var_6, unsigned char var_7, unsigned short var_8, short var_9, int var_11, short var_12, short var_13, short var_14, int zero, unsigned long long int arr_0 [23] [23] , unsigned char arr_1 [23] [23] , unsigned char arr_3 [23] [23] , unsigned long long int arr_7 [23] , long long int arr_11 [10] );

int main() {
    init();
    test(var_0, var_1, var_2, var_3, var_5, var_6, var_7, var_8, var_9, var_11, var_12, var_13, var_14, zero, arr_0 , arr_1 , arr_3 , arr_7 , arr_11 );
    checksum();
    printf("%llu\n", seed);
}
