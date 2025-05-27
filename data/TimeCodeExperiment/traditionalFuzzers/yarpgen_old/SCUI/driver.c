#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

signed char var_0 = (signed char)116;
unsigned char var_1 = (unsigned char)129;
signed char var_2 = (signed char)-86;
long long int var_3 = 743788891729652223LL;
long long int var_4 = -1355013751983315916LL;
unsigned long long int var_5 = 6804229085253666501ULL;
unsigned short var_6 = (unsigned short)37822;
unsigned int var_7 = 140210751U;
unsigned long long int var_8 = 3846111200586874833ULL;
_Bool var_9 = (_Bool)1;
unsigned char var_10 = (unsigned char)208;
int zero = 0;
unsigned char var_11 = (unsigned char)167;
int var_12 = -1133941906;
unsigned long long int var_13 = 6666966225978042282ULL;
unsigned long long int var_14 = 17972902787069538724ULL;
unsigned char var_15 = (unsigned char)35;
int var_16 = -800450225;
unsigned long long int var_17 = 6224583471113593137ULL;
signed char var_18 = (signed char)125;
short var_19 = (short)-12104;
signed char var_20 = (signed char)-83;
unsigned short var_21 = (unsigned short)6674;
unsigned long long int var_22 = 3036407782845566469ULL;
unsigned char var_23 = (unsigned char)219;
unsigned short var_24 = (unsigned short)5400;
unsigned char var_25 = (unsigned char)244;
unsigned char var_26 = (unsigned char)79;
signed char var_27 = (signed char)42;
signed char var_28 = (signed char)119;
short var_29 = (short)-24717;
unsigned short var_30 = (unsigned short)46266;
short var_31 = (short)10490;
long long int var_32 = 3128519147422815602LL;
long long int var_33 = -1184462266336909036LL;
unsigned int arr_0 [15] ;
_Bool arr_2 [15] [15] ;
signed char arr_3 [15] [15] ;
_Bool arr_6 [15] [15] [15] ;
short arr_7 [15] [15] [15] [15] ;
short arr_11 [15] [15] [15] [15] [15] [15] ;
signed char arr_16 [24] ;
signed char arr_18 [24] ;
long long int arr_19 [24] [24] [24] ;
signed char arr_29 [13] [13] [13] [13] ;
short arr_21 [24] [24] [24] ;
long long int arr_22 [24] ;
short arr_38 [13] ;
unsigned long long int arr_39 [13] [13] [13] [13] [13] [13] ;
void init() {
    for (size_t i_0 = 0; i_0 < 15; ++i_0) 
        arr_0 [i_0] = 2558203659U;
    for (size_t i_0 = 0; i_0 < 15; ++i_0) 
        for (size_t i_1 = 0; i_1 < 15; ++i_1) 
            arr_2 [i_0] [i_1] = (_Bool)0;
    for (size_t i_0 = 0; i_0 < 15; ++i_0) 
        for (size_t i_1 = 0; i_1 < 15; ++i_1) 
            arr_3 [i_0] [i_1] = (signed char)32;
    for (size_t i_0 = 0; i_0 < 15; ++i_0) 
        for (size_t i_1 = 0; i_1 < 15; ++i_1) 
            for (size_t i_2 = 0; i_2 < 15; ++i_2) 
                arr_6 [i_0] [i_1] [i_2] = (_Bool)1;
    for (size_t i_0 = 0; i_0 < 15; ++i_0) 
        for (size_t i_1 = 0; i_1 < 15; ++i_1) 
            for (size_t i_2 = 0; i_2 < 15; ++i_2) 
                for (size_t i_3 = 0; i_3 < 15; ++i_3) 
                    arr_7 [i_0] [i_1] [i_2] [i_3] = (short)23147;
    for (size_t i_0 = 0; i_0 < 15; ++i_0) 
        for (size_t i_1 = 0; i_1 < 15; ++i_1) 
            for (size_t i_2 = 0; i_2 < 15; ++i_2) 
                for (size_t i_3 = 0; i_3 < 15; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 15; ++i_4) 
                        for (size_t i_5 = 0; i_5 < 15; ++i_5) 
                            arr_11 [i_0] [i_1] [i_2] [i_3] [i_4] [i_5] = (short)11626;
    for (size_t i_0 = 0; i_0 < 24; ++i_0) 
        arr_16 [i_0] = (signed char)-65;
    for (size_t i_0 = 0; i_0 < 24; ++i_0) 
        arr_18 [i_0] = (signed char)-69;
    for (size_t i_0 = 0; i_0 < 24; ++i_0) 
        for (size_t i_1 = 0; i_1 < 24; ++i_1) 
            for (size_t i_2 = 0; i_2 < 24; ++i_2) 
                arr_19 [i_0] [i_1] [i_2] = -7266662081347301225LL;
    for (size_t i_0 = 0; i_0 < 13; ++i_0) 
        for (size_t i_1 = 0; i_1 < 13; ++i_1) 
            for (size_t i_2 = 0; i_2 < 13; ++i_2) 
                for (size_t i_3 = 0; i_3 < 13; ++i_3) 
                    arr_29 [i_0] [i_1] [i_2] [i_3] = (signed char)-62;
    for (size_t i_0 = 0; i_0 < 24; ++i_0) 
        for (size_t i_1 = 0; i_1 < 24; ++i_1) 
            for (size_t i_2 = 0; i_2 < 24; ++i_2) 
                arr_21 [i_0] [i_1] [i_2] = (short)-15303;
    for (size_t i_0 = 0; i_0 < 24; ++i_0) 
        arr_22 [i_0] = 883525399840311664LL;
    for (size_t i_0 = 0; i_0 < 13; ++i_0) 
        arr_38 [i_0] = (short)-22048;
    for (size_t i_0 = 0; i_0 < 13; ++i_0) 
        for (size_t i_1 = 0; i_1 < 13; ++i_1) 
            for (size_t i_2 = 0; i_2 < 13; ++i_2) 
                for (size_t i_3 = 0; i_3 < 13; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 13; ++i_4) 
                        for (size_t i_5 = 0; i_5 < 13; ++i_5) 
                            arr_39 [i_0] [i_1] [i_2] [i_3] [i_4] [i_5] = 17838243664845745925ULL;
}

void checksum() {
    hash(&seed, var_11);
    hash(&seed, var_12);
    hash(&seed, var_13);
    hash(&seed, var_14);
    hash(&seed, var_15);
    hash(&seed, var_16);
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
    hash(&seed, var_27);
    hash(&seed, var_28);
    hash(&seed, var_29);
    hash(&seed, var_30);
    hash(&seed, var_31);
    hash(&seed, var_32);
    hash(&seed, var_33);
    for (size_t i_0 = 0; i_0 < 24; ++i_0) 
        for (size_t i_1 = 0; i_1 < 24; ++i_1) 
            for (size_t i_2 = 0; i_2 < 24; ++i_2) 
                hash(&seed, arr_21 [i_0] [i_1] [i_2] );
    for (size_t i_0 = 0; i_0 < 24; ++i_0) 
        hash(&seed, arr_22 [i_0] );
    for (size_t i_0 = 0; i_0 < 13; ++i_0) 
        hash(&seed, arr_38 [i_0] );
    for (size_t i_0 = 0; i_0 < 13; ++i_0) 
        for (size_t i_1 = 0; i_1 < 13; ++i_1) 
            for (size_t i_2 = 0; i_2 < 13; ++i_2) 
                for (size_t i_3 = 0; i_3 < 13; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 13; ++i_4) 
                        for (size_t i_5 = 0; i_5 < 13; ++i_5) 
                            hash(&seed, arr_39 [i_0] [i_1] [i_2] [i_3] [i_4] [i_5] );
}
void test(signed char var_0, unsigned char var_1, signed char var_2, long long int var_3, long long int var_4, unsigned long long int var_5, unsigned short var_6, unsigned int var_7, unsigned long long int var_8, _Bool var_9, unsigned char var_10, int zero, unsigned int arr_0 [15] , _Bool arr_2 [15] [15] , signed char arr_3 [15] [15] , _Bool arr_6 [15] [15] [15] , short arr_7 [15] [15] [15] [15] , short arr_11 [15] [15] [15] [15] [15] [15] , signed char arr_16 [24] , signed char arr_18 [24] , long long int arr_19 [24] [24] [24] , signed char arr_29 [13] [13] [13] [13] );

int main() {
    init();
    test(var_0, var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8, var_9, var_10, zero, arr_0 , arr_2 , arr_3 , arr_6 , arr_7 , arr_11 , arr_16 , arr_18 , arr_19 , arr_29 );
    checksum();
    printf("%llu\n", seed);
}
