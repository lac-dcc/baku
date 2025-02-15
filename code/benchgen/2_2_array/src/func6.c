#include "outs/2_2_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array75;
   if (pCounter > 0) {
      array75 = vars->data[--pCounter];
      array75->refC++;
      DEBUG_COPY(array75->id);
   } else {
      array75 = (array_t*)malloc(sizeof(array_t));
      array75->size = 227;
      array75->refC = 1;
      array75->id = 75;
      array75->data = (unsigned int*)malloc(array75->size*sizeof(unsigned int));
      memset(array75->data, 0, array75->size*sizeof(unsigned int));
      DEBUG_NEW(array75->id);
   }
   unsigned int loop15 = 0;
   unsigned int loopLimit15 = (rand()%loopsFactor)/2 + 1;
   for(; loop15 < loopLimit15; loop15++) {
      for (int i = 0; i < array75->size; i++) {
         array75->data[i]--;
      }
      unsigned int loop16 = 0;
      unsigned int loopLimit16 = (rand()%loopsFactor)/3 + 1;
      for(; loop16 < loopLimit16; loop16++) {
         array_t* array76;
         if (pCounter > 0) {
            array76 = vars->data[--pCounter];
            array76->refC++;
            DEBUG_COPY(array76->id);
         } else {
            array76 = (array_t*)malloc(sizeof(array_t));
            array76->size = 859;
            array76->refC = 1;
            array76->id = 76;
            array76->data = (unsigned int*)malloc(array76->size*sizeof(unsigned int));
            memset(array76->data, 0, array76->size*sizeof(unsigned int));
            DEBUG_NEW(array76->id);
         }
         if(PATH0 & 1) {
         }
         else {
         }
         for (int i = 0; i < array75->size; i++) {
            if (array75->data[i] == 32) { 
               return array75;
            }
         }
         array_t* array77;
         if (pCounter > 0) {
            array77 = vars->data[--pCounter];
            array77->refC++;
            DEBUG_COPY(array77->id);
         } else {
            array77 = (array_t*)malloc(sizeof(array_t));
            array77->size = 551;
            array77->refC = 1;
            array77->id = 77;
            array77->data = (unsigned int*)malloc(array77->size*sizeof(unsigned int));
            memset(array77->data, 0, array77->size*sizeof(unsigned int));
            DEBUG_NEW(array77->id);
         }
         array77->refC--;
         if(array77->refC == 0) {
            free(array77->data);
            free(array77);
            DEBUG_FREE(array77->id);
         }
         array76->refC--;
         if(array76->refC == 0) {
            free(array76->data);
            free(array76);
            DEBUG_FREE(array76->id);
         }
      }
   }
   return array75;
}

