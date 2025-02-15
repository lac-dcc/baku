#include "outs/3_2_array.h" 
array_t* func9(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array68;
   if (pCounter > 0) {
      array68 = vars->data[--pCounter];
      array68->refC++;
      DEBUG_COPY(array68->id);
   } else {
      array68 = (array_t*)malloc(sizeof(array_t));
      array68->size = 228;
      array68->refC = 1;
      array68->id = 68;
      array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
      memset(array68->data, 0, array68->size*sizeof(unsigned int));
      DEBUG_NEW(array68->id);
   }
   unsigned int loop15 = 0;
   unsigned int loopLimit15 = (rand()%loopsFactor)/3 + 1;
   for(; loop15 < loopLimit15; loop15++) {
      for (int i = 0; i < array68->size; i++) {
         array68->data[i]--;
      }
      unsigned int loop16 = 0;
      unsigned int loopLimit16 = (rand()%loopsFactor)/4 + 1;
      for(; loop16 < loopLimit16; loop16++) {
         array_t* array69;
         if (pCounter > 0) {
            array69 = vars->data[--pCounter];
            array69->refC++;
            DEBUG_COPY(array69->id);
         } else {
            array69 = (array_t*)malloc(sizeof(array_t));
            array69->size = 350;
            array69->refC = 1;
            array69->id = 69;
            array69->data = (unsigned int*)malloc(array69->size*sizeof(unsigned int));
            memset(array69->data, 0, array69->size*sizeof(unsigned int));
            DEBUG_NEW(array69->id);
         }
         if(PATH0 & 1) {
         }
         else {
         }
         for (int i = 0; i < array69->size; i++) {
            if (array69->data[i] == 0) { 
               return array69;
            }
         }
         array_t* array70;
         if (pCounter > 0) {
            array70 = vars->data[--pCounter];
            array70->refC++;
            DEBUG_COPY(array70->id);
         } else {
            array70 = (array_t*)malloc(sizeof(array_t));
            array70->size = 34;
            array70->refC = 1;
            array70->id = 70;
            array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
            memset(array70->data, 0, array70->size*sizeof(unsigned int));
            DEBUG_NEW(array70->id);
         }
         array70->refC--;
         if(array70->refC == 0) {
            free(array70->data);
            free(array70);
            DEBUG_FREE(array70->id);
         }
         array69->refC--;
         if(array69->refC == 0) {
            free(array69->data);
            free(array69);
            DEBUG_FREE(array69->id);
         }
      }
   }
   return array68;
}

