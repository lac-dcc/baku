#include "outs/2_9_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array9;
   if (pCounter > 0) {
      array9 = vars->data[--pCounter];
      array9->refC++;
      DEBUG_COPY(array9->id);
   } else {
      array9 = (array_t*)malloc(sizeof(array_t));
      array9->size = 456;
      array9->refC = 1;
      array9->id = 9;
      array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
      memset(array9->data, 0, array9->size*sizeof(unsigned int));
      DEBUG_NEW(array9->id);
   }
   if(PATH0 & 1) {
   }
   else {
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      for (int i = 0; i < array9->size; i++) {
         array9->data[i]++;
      }
   }
   return array9;
}

