#include "outs/4_2_array.h" 
array_t* func13(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array30;
   if (pCounter > 0) {
      array30 = vars->data[--pCounter];
      array30->refC++;
      DEBUG_COPY(array30->id);
   } else {
      array30 = (array_t*)malloc(sizeof(array_t));
      array30->size = 750;
      array30->refC = 1;
      array30->id = 30;
      array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
      memset(array30->data, 0, array30->size*sizeof(unsigned int));
      DEBUG_NEW(array30->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      for (int i = 0; i < array30->size; i++) {
         array30->data[i]--;
      }
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/4 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         array_t* array31;
         if (pCounter > 0) {
            array31 = vars->data[--pCounter];
            array31->refC++;
            DEBUG_COPY(array31->id);
         } else {
            array31 = (array_t*)malloc(sizeof(array_t));
            array31->size = 808;
            array31->refC = 1;
            array31->id = 31;
            array31->data = (unsigned int*)malloc(array31->size*sizeof(unsigned int));
            memset(array31->data, 0, array31->size*sizeof(unsigned int));
            DEBUG_NEW(array31->id);
         }
         if(PATH0 & 1) {
         }
         else {
         }
         for (int i = 0; i < array30->size; i++) {
            if (array30->data[i] == 78) { 
               return array30;
            }
         }
         array_t* array32;
         if (pCounter > 0) {
            array32 = vars->data[--pCounter];
            array32->refC++;
            DEBUG_COPY(array32->id);
         } else {
            array32 = (array_t*)malloc(sizeof(array_t));
            array32->size = 788;
            array32->refC = 1;
            array32->id = 32;
            array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
            memset(array32->data, 0, array32->size*sizeof(unsigned int));
            DEBUG_NEW(array32->id);
         }
         array32->refC--;
         if(array32->refC == 0) {
            free(array32->data);
            free(array32);
            DEBUG_FREE(array32->id);
         }
         array31->refC--;
         if(array31->refC == 0) {
            free(array31->data);
            free(array31);
            DEBUG_FREE(array31->id);
         }
      }
   }
   return array30;
}

