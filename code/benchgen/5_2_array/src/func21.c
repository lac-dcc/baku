#include "outs/5_2_array.h" 
array_t* func21(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array80;
   if (pCounter > 0) {
      array80 = vars->data[--pCounter];
      array80->refC++;
      DEBUG_COPY(array80->id);
   } else {
      array80 = (array_t*)malloc(sizeof(array_t));
      array80->size = 121;
      array80->refC = 1;
      array80->id = 80;
      array80->data = (unsigned int*)malloc(array80->size*sizeof(unsigned int));
      memset(array80->data, 0, array80->size*sizeof(unsigned int));
      DEBUG_NEW(array80->id);
   }
   unsigned int loop15 = 0;
   unsigned int loopLimit15 = (rand()%loopsFactor)/3 + 1;
   for(; loop15 < loopLimit15; loop15++) {
      for (int i = 0; i < array80->size; i++) {
         array80->data[i]--;
      }
      unsigned int loop16 = 0;
      unsigned int loopLimit16 = (rand()%loopsFactor)/4 + 1;
      for(; loop16 < loopLimit16; loop16++) {
         array_t* array81;
         if (pCounter > 0) {
            array81 = vars->data[--pCounter];
            array81->refC++;
            DEBUG_COPY(array81->id);
         } else {
            array81 = (array_t*)malloc(sizeof(array_t));
            array81->size = 395;
            array81->refC = 1;
            array81->id = 81;
            array81->data = (unsigned int*)malloc(array81->size*sizeof(unsigned int));
            memset(array81->data, 0, array81->size*sizeof(unsigned int));
            DEBUG_NEW(array81->id);
         }
         if(PATH0 & 1) {
         }
         else {
         }
         for (int i = 0; i < array81->size; i++) {
            if (array81->data[i] == 37) { 
               return array81;
            }
         }
         array_t* array82;
         if (pCounter > 0) {
            array82 = vars->data[--pCounter];
            array82->refC++;
            DEBUG_COPY(array82->id);
         } else {
            array82 = (array_t*)malloc(sizeof(array_t));
            array82->size = 235;
            array82->refC = 1;
            array82->id = 82;
            array82->data = (unsigned int*)malloc(array82->size*sizeof(unsigned int));
            memset(array82->data, 0, array82->size*sizeof(unsigned int));
            DEBUG_NEW(array82->id);
         }
         array82->refC--;
         if(array82->refC == 0) {
            free(array82->data);
            free(array82);
            DEBUG_FREE(array82->id);
         }
         array81->refC--;
         if(array81->refC == 0) {
            free(array81->data);
            free(array81);
            DEBUG_FREE(array81->id);
         }
      }
   }
   return array80;
}

