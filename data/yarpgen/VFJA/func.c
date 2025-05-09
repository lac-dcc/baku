/*
yarpgen version 2.0 (build 700f5a2 on 2025:05:08)
Seed: 3146145301
Invocation: ../../bin/yarpgen.out --std=c --out-dir=../../data/yarpgen/VFJA
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
void test(long long int var_1, signed char var_2, short var_4, signed char var_6, unsigned long long int var_9, signed char var_10, unsigned int var_11, unsigned char var_14, signed char var_15, short var_17, unsigned int var_18, int zero) {
    var_19 = ((/* implicit */unsigned int) (~(((((/* implicit */long long int) ((/* implicit */int) ((((/* implicit */_Bool) var_1)) && (((/* implicit */_Bool) var_17)))))) | (max((2268882404100896608LL), (-3851554719125482492LL)))))));
    /* LoopNest 3 */
    for (unsigned int i_0 = ((((/* implicit */unsigned int) var_14)) - (155U))/*0*/; i_0 < 17U/*17*/; i_0 += 2U/*2*/) 
    {
        for (unsigned int i_1 = ((((/* implicit */unsigned int) var_17)) - (4294962826U))/*0*/; i_1 < 17U/*17*/; i_1 += 4U/*4*/) 
        {
            for (long long int i_2 = ((((/* implicit */long long int) (!(((((/* implicit */unsigned int) ((/* implicit */int) var_2))) != (var_11)))))) + (1LL))/*1*/; i_2 < ((((/* implicit */long long int) var_15)) - (98LL))/*15*/; i_2 += ((((/* implicit */long long int) var_9)) - (5948341898829495147LL))/*3*/) 
            {
                {
                    /* LoopSeq 1 */
                    for (unsigned char i_3 = (unsigned char)2/*2*/; i_3 < ((((/* implicit */int) ((/* implicit */unsigned char) var_10))) - (242))/*13*/; i_3 += (unsigned char)2/*2*/) 
                    {
                        var_20 = (~((~(var_18))));
                        var_21 ^= ((/* implicit */int) min((((((unsigned int) var_15)) * (((/* implicit */unsigned int) ((/* implicit */int) (!(((/* implicit */_Bool) 2241387122U)))))))), (((/* implicit */unsigned int) ((((/* implicit */_Bool) (-(1644644144U)))) || (((/* implicit */_Bool) ((unsigned short) var_17))))))));
                        var_22 ^= ((/* implicit */unsigned char) ((unsigned int) ((long long int) var_1)));
                        arr_11 [i_3] [i_2 + 2] [i_2] [i_2] [i_1] [i_0] = ((/* implicit */signed char) ((short) ((((/* implicit */int) ((268435455U) > (268435455U)))) << ((((~(((/* implicit */int) (short)2115)))) + (2138))))));
                        arr_12 [i_2] = ((/* implicit */unsigned int) (((+(((/* implicit */int) ((short) 2268882404100896608LL))))) << (((268435458U) - (268435454U)))));
                    }
                    arr_13 [i_1] [i_1] [i_0] |= ((/* implicit */unsigned int) (-(((/* implicit */int) ((short) ((long long int) var_1))))));
                    var_23 = ((/* implicit */signed char) var_4);
                }
            } 
        } 
    } 
    var_24 = ((/* implicit */unsigned char) var_6);
}
