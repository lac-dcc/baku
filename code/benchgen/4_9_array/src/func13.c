#include "outs/4_9_array.h" 
array_t* func13(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array19;
   if (pCounter > 0) {
      array19 = vars->data[--pCounter];
      array19->refC++;
      DEBUG_COPY(array19->id);
   } else {
      array19 = (array_t*)malloc(sizeof(array_t));
      array19->size = 545;
      array19->refC = 1;
      array19->id = 19;
      array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
      memset(array19->data, 0, array19->size*sizeof(unsigned int));
      DEBUG_NEW(array19->id);
   }
   if(PATH0 & 1) {
   }
   else {
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/2 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      for (int i = 0; i < array19->size; i++) {
         array19->data[i]++;
      }
   }
   return array19;
}

