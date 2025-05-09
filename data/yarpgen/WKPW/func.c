/*
yarpgen version 2.0 (build 700f5a2 on 2025:05:08)
Seed: 1420984286
Invocation: ../../bin/yarpgen.out --std=c --out-dir=../../data/yarpgen/WKPW
*/
#include "init.h"
#define max(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a > _b ? _a : _b; })
#define min(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a < _b ? _a : _b; })
void test(signed char var_6, signed char var_7, unsigned char var_8, unsigned long long int var_12, unsigned short var_13, int var_14, signed char var_15, int zero, unsigned char arr_1 [21] , long long int arr_3 [21] ) {
    var_16 = ((/* implicit */long long int) ((((/* implicit */int) ((short) (_Bool)0))) + (((/* implicit */int) var_8))));
    /* LoopNest 2 */
    for (short i_0 = ((((/* implicit */int) ((/* implicit */short) var_13))) - (2226))/*0*/; i_0 < (short)21/*21*/; i_0 += (short)4/*4*/) 
    {
        for (unsigned short i_1 = (unsigned short)0/*0*/; i_1 < ((((/* implicit */int) ((/* implicit */unsigned short) var_15))) - (65432))/*21*/; i_1 += ((((/* implicit */int) ((/* implicit */unsigned short) var_12))) - (27541))/*2*/) 
        {
            {
                arr_4 [i_0] = ((/* implicit */unsigned char) ((signed char) max(((unsigned short)33636), (((/* implicit */unsigned short) (short)18971)))));
                arr_5 [i_0] [i_1] [(short)20] = ((/* implicit */int) (+((-(arr_3 [i_1])))));
                arr_6 [i_0] = ((/* implicit */unsigned int) var_15);
                arr_7 [i_0] [i_1] [i_1] = ((/* implicit */_Bool) ((((((/* implicit */int) (short)18971)) <= (((/* implicit */int) (signed char)-101)))) ? (((/* implicit */int) ((((/* implicit */_Bool) var_15)) || (((/* implicit */_Bool) arr_1 [i_1]))))) : (((int) 7816374212001121352LL))));
            }
        } 
    } 
    var_17 = ((/* implicit */unsigned long long int) ((((/* implicit */_Bool) var_7)) ? (((((((/* implicit */_Bool) var_14)) || (((/* implicit */_Bool) var_6)))) ? (((/* implicit */int) var_13)) : (((((/* implicit */_Bool) var_13)) ? (((/* implicit */int) (unsigned short)56088)) : (((/* implicit */int) var_8)))))) : (((((/* implicit */_Bool) ((((/* implicit */_Bool) var_13)) ? (((/* implicit */int) var_8)) : (((/* implicit */int) (_Bool)1))))) ? (((/* implicit */int) (!(((/* implicit */_Bool) 24ULL))))) : (((/* implicit */int) (!(((/* implicit */_Bool) var_14)))))))));
}
