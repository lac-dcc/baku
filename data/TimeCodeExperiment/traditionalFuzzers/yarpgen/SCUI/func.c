/*
yarpgen version 2.0 (build 700f5a2 on 2025:05:08)
Seed: 1844496665
Invocation: ../../bin/yarpgen.out --std=c --out-dir=../../data/TimeCodeExperiment/traditionalFuzzers/yarpgen/SCUI
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
void test(signed char var_0, unsigned char var_1, signed char var_2, long long int var_3, long long int var_4, unsigned long long int var_5, unsigned short var_6, unsigned int var_7, unsigned long long int var_8, _Bool var_9, unsigned char var_10, int zero, unsigned int arr_0 [15] , _Bool arr_2 [15] [15] , signed char arr_3 [15] [15] , _Bool arr_6 [15] [15] [15] , short arr_7 [15] [15] [15] [15] , short arr_11 [15] [15] [15] [15] [15] [15] , signed char arr_16 [24] , signed char arr_18 [24] , long long int arr_19 [24] [24] [24] , signed char arr_29 [13] [13] [13] [13] ) {
    var_11 = ((/* implicit */unsigned char) ((signed char) ((((/* implicit */long long int) (~(((/* implicit */int) var_2))))) | (var_4))));
    if (((/* implicit */_Bool) ((var_7) + (((/* implicit */unsigned int) ((/* implicit */int) var_2))))))
    {
        var_12 = ((/* implicit */int) (+(((((/* implicit */_Bool) ((((/* implicit */_Bool) var_10)) ? (var_3) : (((/* implicit */long long int) ((/* implicit */int) (signed char)-65)))))) ? ((~(var_7))) : (((/* implicit */unsigned int) (((-2147483647 - 1)) | (((/* implicit */int) (signed char)57)))))))));
        /* LoopNest 3 */
        for (_Bool i_0 = ((/* implicit */int) ((/* implicit */_Bool) var_5))/*1*/; i_0 < (_Bool)1/*1*/; i_0 += ((/* implicit */int) ((/* implicit */_Bool) var_3))/*1*/) 
        {
            for (signed char i_1 = ((((/* implicit */int) ((/* implicit */signed char) var_5))) + (59))/*0*/; i_1 < ((((/* implicit */int) ((/* implicit */signed char) (-(var_5))))) - (44))/*15*/; i_1 += (signed char)4/*4*/) 
            {
                for (unsigned int i_2 = ((((/* implicit */unsigned int) (~(((/* implicit */int) ((_Bool) (~(((/* implicit */int) (signed char)65))))))))) - (4294967293U))/*1*/; i_2 < ((((/* implicit */unsigned int) var_0)) - (102U))/*14*/; i_2 += ((((/* implicit */unsigned int) var_8)) - (1705099214U))/*3*/) 
                {
                    {
                        var_13 = ((/* implicit */unsigned long long int) (+(((/* implicit */int) (!(((/* implicit */_Bool) var_10)))))));
                        /* LoopSeq 1 */
                        /* vectorizable */
                        for (unsigned long long int i_3 = ((((/* implicit */unsigned long long int) var_7)) - (140210751ULL))/*0*/; i_3 < 15ULL/*15*/; i_3 += 2ULL/*2*/) 
                        {
                            var_14 = ((/* implicit */unsigned long long int) ((int) arr_2 [i_0] [i_1]));
                            var_15 = ((/* implicit */unsigned char) min((var_15), (((/* implicit */unsigned char) ((((/* implicit */_Bool) arr_3 [i_0 - 1] [i_2 + 1])) ? (((/* implicit */unsigned int) ((/* implicit */int) (short)127))) : (0U))))));
                            var_16 = ((/* implicit */int) min((var_16), (((/* implicit */int) (~(140737488355327ULL))))));
                            var_17 = ((/* implicit */unsigned long long int) (-(((((/* implicit */_Bool) 4294967275U)) ? (((/* implicit */int) arr_6 [i_2] [i_2 + 1] [i_2])) : (((/* implicit */int) var_0))))));
                        }
                        /* LoopNest 2 */
                        for (int i_4 = ((((/* implicit */int) (+(((min((((/* implicit */unsigned int) arr_2 [i_2] [i_2])), (20U))) & (((/* implicit */unsigned int) ((((/* implicit */int) (_Bool)1)) % (3))))))))) + (4))/*4*/; i_4 < (((((!(((/* implicit */_Bool) arr_3 [i_0 - 1] [i_0 - 1])))) ? (((/* implicit */int) min((((/* implicit */short) arr_3 [i_0 - 1] [i_0 - 1])), (arr_7 [i_0 - 1] [i_0 - 1] [i_0 - 1] [i_0 - 1])))) : (((/* implicit */int) min((arr_7 [i_0 - 1] [i_0 - 1] [i_0 - 1] [i_0 - 1]), (((/* implicit */short) (signed char)64))))))) - (50))/*14*/; i_4 += ((((/* implicit */int) var_0)) - (115))/*1*/) 
                        {
                            for (short i_5 = ((((/* implicit */int) ((/* implicit */short) (signed char)16))) - (16))/*0*/; i_5 < (short)15/*15*/; i_5 += ((((/* implicit */int) ((/* implicit */short) var_2))) + (90))/*4*/) 
                            {
                                {
                                    var_18 -= ((/* implicit */signed char) arr_11 [i_0 - 1] [i_2] [i_2 + 1] [i_2 + 1] [i_4 - 4] [i_4]);
                                    var_19 = ((/* implicit */short) max((var_19), (((/* implicit */short) (+(((/* implicit */int) ((((4294967269U) * (4294967292U))) < (((/* implicit */unsigned int) ((/* implicit */int) max((((/* implicit */unsigned char) (_Bool)0)), (var_1)))))))))))));
                                }
                            } 
                        } 
                    }
                } 
            } 
        } 
        if (((/* implicit */_Bool) var_5))
        {
            /* LoopNest 2 */
            for (long long int i_6 = 3LL/*3*/; i_6 < ((((/* implicit */long long int) var_6)) - (37799LL))/*23*/; i_6 += 4LL/*4*/) 
            {
                for (short i_7 = (short)0/*0*/; i_7 < ((((/* implicit */int) ((/* implicit */short) (!(((/* implicit */_Bool) 29U)))))) + (24))/*24*/; i_7 += (short)1/*1*/) 
                {
                    {
                        arr_21 [i_6] [i_7] [i_7] = ((/* implicit */short) ((((/* implicit */_Bool) (~((~(4294967270U)))))) ? (((/* implicit */int) arr_16 [i_6])) : ((~(((((/* implicit */_Bool) (short)32767)) ? (((/* implicit */int) (_Bool)1)) : (((/* implicit */int) (unsigned char)137))))))));
                        arr_22 [i_7] = ((/* implicit */long long int) (+((+(((((/* implicit */int) arr_18 [i_6])) / (((/* implicit */int) var_6))))))));
                    }
                } 
            } 
            var_20 -= ((/* implicit */signed char) var_6);
            var_21 = ((/* implicit */unsigned short) min((var_21), (((/* implicit */unsigned short) ((((/* implicit */int) (signed char)-78)) | (((/* implicit */int) (signed char)-8)))))));
            /* LoopNest 3 */
            for (short i_8 = (short)0/*0*/; i_8 < ((((/* implicit */int) ((/* implicit */short) (-((+(((((/* implicit */_Bool) var_8)) ? (4294967270U) : (((/* implicit */unsigned int) ((/* implicit */int) var_9))))))))))) - (13))/*13*/; i_8 += (short)4/*4*/) 
            {
                for (_Bool i_9 = (_Bool)0/*0*/; i_9 < ((/* implicit */int) ((/* implicit */_Bool) var_5))/*1*/; i_9 += (_Bool)1/*1*/) 
                {
                    for (_Bool i_10 = ((/* implicit */int) ((/* implicit */_Bool) var_6))/*1*/; i_10 < (_Bool)1/*1*/; i_10 += ((/* implicit */int) ((/* implicit */_Bool) var_6))/*1*/) 
                    {
                        {
                            var_22 = ((/* implicit */unsigned long long int) (~(((/* implicit */int) arr_6 [i_8] [i_10] [i_8]))));
                            /* LoopNest 2 */
                            for (_Bool i_11 = (_Bool)0/*0*/; i_11 < (_Bool)1/*1*/; i_11 += ((/* implicit */int) ((/* implicit */_Bool) (-(var_7))))/*1*/) 
                            {
                                for (short i_12 = ((((/* implicit */int) ((/* implicit */short) var_0))) - (114))/*2*/; i_12 < ((((/* implicit */int) ((/* implicit */short) var_2))) + (96))/*10*/; i_12 += ((((/* implicit */int) ((/* implicit */short) (signed char)7))) - (3))/*4*/) 
                                {
                                    {
                                        if (((/* implicit */_Bool) (~((~(((arr_2 [i_10] [i_12 - 2]) ? (((/* implicit */long long int) ((/* implicit */int) var_1))) : (var_3))))))))
                                        {
                                            var_23 = ((/* implicit */unsigned char) ((short) min((((/* implicit */unsigned long long int) var_6)), (var_8))));
                                            var_24 = ((/* implicit */unsigned short) ((((/* implicit */unsigned long long int) ((/* implicit */int) (signed char)-9))) / (((((/* implicit */_Bool) ((var_3) - (((/* implicit */long long int) ((/* implicit */int) (short)-21605)))))) ? (11219036107845303952ULL) : (((/* implicit */unsigned long long int) ((/* implicit */int) (unsigned short)9466)))))));
                                            if (((/* implicit */_Bool) ((((/* implicit */_Bool) arr_19 [i_12] [i_11] [i_9])) ? (((((/* implicit */_Bool) max((var_2), (var_2)))) ? (((/* implicit */int) arr_2 [i_12 - 1] [i_10 - 1])) : ((+(((/* implicit */int) var_0)))))) : ((-((~(((/* implicit */int) (unsigned char)146)))))))))
                                            {
                                                var_25 += var_1;
                                                var_26 = ((/* implicit */unsigned char) var_4);
                                            }

                                            var_27 = ((/* implicit */signed char) (+(((/* implicit */int) arr_2 [i_8] [i_8]))));
                                            if (((/* implicit */_Bool) (~(((/* implicit */int) (unsigned short)38572)))))
                                            {
                                                var_28 = ((/* implicit */signed char) (-(((/* implicit */int) arr_29 [i_12] [i_11] [i_10] [i_9]))));
                                                var_29 ^= ((/* implicit */short) ((((/* implicit */_Bool) (signed char)-22)) ? (((/* implicit */unsigned int) ((/* implicit */int) ((_Bool) ((((/* implicit */_Bool) var_6)) ? (((/* implicit */int) (signed char)-90)) : (((/* implicit */int) var_1))))))) : ((+(max((var_7), (((/* implicit */unsigned int) (signed char)85))))))));
                                                var_30 = ((/* implicit */unsigned short) var_5);
                                                arr_38 [i_10] = arr_11 [i_10] [i_8] [i_10] [i_11] [i_12] [i_10 - 1];
                                            }

                                        }

                                        var_31 *= ((/* implicit */short) var_6);
                                        var_32 = ((/* implicit */long long int) ((((/* implicit */_Bool) 5573987244473734598ULL)) || (((/* implicit */_Bool) var_1))));
                                        arr_39 [i_9] [i_11] [i_9] [i_8] [i_9] [i_8] = ((/* implicit */unsigned long long int) (+((+(arr_0 [i_8])))));
                                    }
                                } 
                            } 
                        }
                    } 
                } 
            } 
        }

    }

    var_33 = ((/* implicit */long long int) ((((/* implicit */_Bool) (-(var_7)))) ? (max((((/* implicit */unsigned long long int) (!(((/* implicit */_Bool) var_1))))), (var_5))) : (((/* implicit */unsigned long long int) ((/* implicit */int) var_10)))));
}
