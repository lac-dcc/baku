#include <stdio.h>

unsigned long long int seed = 0;
void hash(unsigned long long int *seed, unsigned long long int const v) {
    *seed ^= v + 0x9e3779b9 + ((*seed)<<6) + ((*seed)>>2);
}

signed char var_1 = (signed char)-70;
short var_2 = (short)26386;
long long int var_3 = -9060797751487678283LL;
short var_4 = (short)-21296;
long long int var_5 = 5010317896689103978LL;
_Bool var_6 = (_Bool)1;
signed char var_7 = (signed char)101;
_Bool var_8 = (_Bool)0;
short var_9 = (short)19163;
short var_10 = (short)24209;
int var_11 = 478330086;
long long int var_12 = -5677616431815443023LL;
_Bool var_13 = (_Bool)0;
unsigned int var_14 = 1613535752U;
unsigned short var_15 = (unsigned short)28323;
short var_16 = (short)19112;
long long int var_17 = 806395470557655917LL;
signed char var_18 = (signed char)-80;
int zero = 0;
unsigned short var_19 = (unsigned short)63282;
long long int var_20 = 7213177386268676328LL;
long long int var_21 = 712005442936160641LL;
short var_22 = (short)-6662;
signed char var_23 = (signed char)-8;
int var_24 = 938697341;
long long int var_25 = 4560928910114997229LL;
unsigned char var_26 = (unsigned char)1;
_Bool var_27 = (_Bool)1;
_Bool var_28 = (_Bool)0;
short var_29 = (short)-11978;
_Bool var_30 = (_Bool)0;
_Bool var_31 = (_Bool)1;
signed char var_32 = (signed char)98;
_Bool var_33 = (_Bool)0;
unsigned char var_34 = (unsigned char)18;
short var_35 = (short)-26108;
unsigned char var_36 = (unsigned char)69;
signed char var_37 = (signed char)-44;
short var_38 = (short)-27734;
int var_39 = 2043292883;
unsigned int var_40 = 2242676873U;
unsigned int var_41 = 1112236597U;
long long int var_42 = 8817834732979772538LL;
unsigned long long int var_43 = 10506626835661054425ULL;
signed char var_44 = (signed char)125;
_Bool var_45 = (_Bool)0;
signed char var_46 = (signed char)72;
long long int var_47 = 2414852086178941874LL;
signed char var_48 = (signed char)76;
unsigned long long int var_49 = 12746290105484713185ULL;
unsigned int var_50 = 936227340U;
unsigned short var_51 = (unsigned short)8812;
int var_52 = -1112285028;
short var_53 = (short)1203;
unsigned short var_54 = (unsigned short)12234;
short var_55 = (short)30915;
short var_56 = (short)20584;
unsigned long long int arr_2 [16] ;
unsigned short arr_3 [16] [16] ;
_Bool arr_6 [11] ;
signed char arr_7 [11] ;
unsigned char arr_8 [11] ;
unsigned long long int arr_15 [12] [12] ;
_Bool arr_16 [23] [23] ;
short arr_17 [23] ;
signed char arr_18 [23] [23] ;
unsigned long long int arr_21 [23] [23] [23] ;
signed char arr_22 [23] [23] [23] ;
unsigned long long int arr_23 [23] [23] [23] [23] ;
long long int arr_25 [23] [23] ;
unsigned long long int arr_26 [23] [23] ;
_Bool arr_27 [23] [23] [23] [23] ;
int arr_29 [23] ;
unsigned long long int arr_30 [23] [23] [23] ;
unsigned long long int arr_31 [23] [23] [23] [23] ;
_Bool arr_34 [23] ;
short arr_36 [23] [23] [23] ;
signed char arr_42 [23] [23] ;
unsigned int arr_43 [23] [23] [23] [23] [23] ;
_Bool arr_44 [23] [23] [23] [23] [23] [23] ;
int arr_47 [23] [23] [23] [23] [23] ;
signed char arr_5 [16] ;
short arr_12 [11] [11] ;
signed char arr_13 [11] [11] ;
unsigned char arr_19 [23] [23] ;
unsigned int arr_28 [23] [23] ;
unsigned char arr_35 [23] ;
unsigned short arr_41 [23] [23] [23] [23] ;
unsigned long long int arr_45 [23] [23] [23] [23] [23] ;
unsigned char arr_48 [23] [23] [23] [23] [23] ;
long long int arr_51 [23] [23] [23] [23] [23] ;
short arr_52 [23] [23] [23] [23] [23] ;
void init() {
    for (size_t i_0 = 0; i_0 < 16; ++i_0) 
        arr_2 [i_0] = 2073772575094420201ULL;
    for (size_t i_0 = 0; i_0 < 16; ++i_0) 
        for (size_t i_1 = 0; i_1 < 16; ++i_1) 
            arr_3 [i_0] [i_1] = (unsigned short)36045;
    for (size_t i_0 = 0; i_0 < 11; ++i_0) 
        arr_6 [i_0] = (_Bool)1;
    for (size_t i_0 = 0; i_0 < 11; ++i_0) 
        arr_7 [i_0] = (signed char)4;
    for (size_t i_0 = 0; i_0 < 11; ++i_0) 
        arr_8 [i_0] = (unsigned char)238;
    for (size_t i_0 = 0; i_0 < 12; ++i_0) 
        for (size_t i_1 = 0; i_1 < 12; ++i_1) 
            arr_15 [i_0] [i_1] = 7694701965755903424ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_16 [i_0] [i_1] = (_Bool)1;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_17 [i_0] = (short)6560;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_18 [i_0] [i_1] = (signed char)-23;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                arr_21 [i_0] [i_1] [i_2] = 3711539018506541895ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                arr_22 [i_0] [i_1] [i_2] = (signed char)-77;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    arr_23 [i_0] [i_1] [i_2] [i_3] = 12033809053105868930ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_25 [i_0] [i_1] = 1255338507355172005LL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_26 [i_0] [i_1] = 15946978133442550679ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    arr_27 [i_0] [i_1] [i_2] [i_3] = (_Bool)0;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_29 [i_0] = 840077771;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                arr_30 [i_0] [i_1] [i_2] = 10892325355936858843ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    arr_31 [i_0] [i_1] [i_2] [i_3] = 4202623093127780149ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_34 [i_0] = (_Bool)0;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                arr_36 [i_0] [i_1] [i_2] = (short)-27228;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_42 [i_0] [i_1] = (signed char)94;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        arr_43 [i_0] [i_1] [i_2] [i_3] [i_4] = (i_3 % 2 == 0) ? 2549548523U : 1264814724U;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        for (size_t i_5 = 0; i_5 < 23; ++i_5) 
                            arr_44 [i_0] [i_1] [i_2] [i_3] [i_4] [i_5] = (_Bool)1;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        arr_47 [i_0] [i_1] [i_2] [i_3] [i_4] = 1216759516;
    for (size_t i_0 = 0; i_0 < 16; ++i_0) 
        arr_5 [i_0] = (signed char)-110;
    for (size_t i_0 = 0; i_0 < 11; ++i_0) 
        for (size_t i_1 = 0; i_1 < 11; ++i_1) 
            arr_12 [i_0] [i_1] = (short)-14511;
    for (size_t i_0 = 0; i_0 < 11; ++i_0) 
        for (size_t i_1 = 0; i_1 < 11; ++i_1) 
            arr_13 [i_0] [i_1] = (signed char)101;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_19 [i_0] [i_1] = (unsigned char)188;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            arr_28 [i_0] [i_1] = 2936598894U;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        arr_35 [i_0] = (unsigned char)252;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    arr_41 [i_0] [i_1] [i_2] [i_3] = (i_2 % 2 == 0) ? (unsigned short)51230 : (unsigned short)36413;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        arr_45 [i_0] [i_1] [i_2] [i_3] [i_4] = (i_4 % 2 == 0) ? 15478819012479091410ULL : 10210371581583903886ULL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        arr_48 [i_0] [i_1] [i_2] [i_3] [i_4] = (i_1 % 2 == 0) ? (unsigned char)242 : (unsigned char)196;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        arr_51 [i_0] [i_1] [i_2] [i_3] [i_4] = (i_4 % 2 == 0) ? -8761210861395245054LL : 142900736379866386LL;
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        arr_52 [i_0] [i_1] [i_2] [i_3] [i_4] = (i_1 % 2 == 0) ? (short)-6049 : (short)13259;
}

void checksum() {
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
    hash(&seed, var_34);
    hash(&seed, var_35);
    hash(&seed, var_36);
    hash(&seed, var_37);
    hash(&seed, var_38);
    hash(&seed, var_39);
    hash(&seed, var_40);
    hash(&seed, var_41);
    hash(&seed, var_42);
    hash(&seed, var_43);
    hash(&seed, var_44);
    hash(&seed, var_45);
    hash(&seed, var_46);
    hash(&seed, var_47);
    hash(&seed, var_48);
    hash(&seed, var_49);
    hash(&seed, var_50);
    hash(&seed, var_51);
    hash(&seed, var_52);
    hash(&seed, var_53);
    hash(&seed, var_54);
    hash(&seed, var_55);
    hash(&seed, var_56);
    for (size_t i_0 = 0; i_0 < 16; ++i_0) 
        hash(&seed, arr_5 [i_0] );
    for (size_t i_0 = 0; i_0 < 11; ++i_0) 
        for (size_t i_1 = 0; i_1 < 11; ++i_1) 
            hash(&seed, arr_12 [i_0] [i_1] );
    for (size_t i_0 = 0; i_0 < 11; ++i_0) 
        for (size_t i_1 = 0; i_1 < 11; ++i_1) 
            hash(&seed, arr_13 [i_0] [i_1] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            hash(&seed, arr_19 [i_0] [i_1] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            hash(&seed, arr_28 [i_0] [i_1] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        hash(&seed, arr_35 [i_0] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    hash(&seed, arr_41 [i_0] [i_1] [i_2] [i_3] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        hash(&seed, arr_45 [i_0] [i_1] [i_2] [i_3] [i_4] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        hash(&seed, arr_48 [i_0] [i_1] [i_2] [i_3] [i_4] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        hash(&seed, arr_51 [i_0] [i_1] [i_2] [i_3] [i_4] );
    for (size_t i_0 = 0; i_0 < 23; ++i_0) 
        for (size_t i_1 = 0; i_1 < 23; ++i_1) 
            for (size_t i_2 = 0; i_2 < 23; ++i_2) 
                for (size_t i_3 = 0; i_3 < 23; ++i_3) 
                    for (size_t i_4 = 0; i_4 < 23; ++i_4) 
                        hash(&seed, arr_52 [i_0] [i_1] [i_2] [i_3] [i_4] );
}
void test(signed char var_1, short var_2, long long int var_3, short var_4, long long int var_5, _Bool var_6, signed char var_7, _Bool var_8, short var_9, short var_10, int var_11, long long int var_12, _Bool var_13, unsigned int var_14, unsigned short var_15, short var_16, long long int var_17, signed char var_18, int zero, unsigned long long int arr_2 [16] , unsigned short arr_3 [16] [16] , _Bool arr_6 [11] , signed char arr_7 [11] , unsigned char arr_8 [11] , unsigned long long int arr_15 [12] [12] , _Bool arr_16 [23] [23] , short arr_17 [23] , signed char arr_18 [23] [23] , unsigned long long int arr_21 [23] [23] [23] , signed char arr_22 [23] [23] [23] , unsigned long long int arr_23 [23] [23] [23] [23] , long long int arr_25 [23] [23] , unsigned long long int arr_26 [23] [23] , _Bool arr_27 [23] [23] [23] [23] , int arr_29 [23] , unsigned long long int arr_30 [23] [23] [23] , unsigned long long int arr_31 [23] [23] [23] [23] , _Bool arr_34 [23] , short arr_36 [23] [23] [23] , signed char arr_42 [23] [23] , unsigned int arr_43 [23] [23] [23] [23] [23] , _Bool arr_44 [23] [23] [23] [23] [23] [23] , int arr_47 [23] [23] [23] [23] [23] );

int main() {
    init();
    test(var_1, var_2, var_3, var_4, var_5, var_6, var_7, var_8, var_9, var_10, var_11, var_12, var_13, var_14, var_15, var_16, var_17, var_18, zero, arr_2 , arr_3 , arr_6 , arr_7 , arr_8 , arr_15 , arr_16 , arr_17 , arr_18 , arr_21 , arr_22 , arr_23 , arr_25 , arr_26 , arr_27 , arr_29 , arr_30 , arr_31 , arr_34 , arr_36 , arr_42 , arr_43 , arr_44 , arr_47 );
    checksum();
    printf("%llu\n", seed);
}
