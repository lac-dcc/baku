#include "outs/1_2_array.h" 
array_t* func6(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array22;
   if (pCounter > 0) {
      array22 = vars->data[--pCounter];
      array22->refC++;
      DEBUG_COPY(array22->id);
   } else {
      array22 = (array_t*)malloc(sizeof(array_t));
      array22->size = 305;
      array22->refC = 1;
      array22->id = 22;
      array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
      memset(array22->data, 0, array22->size*sizeof(unsigned int));
      DEBUG_NEW(array22->id);
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      for (int i = 0; i < array22->size; i++) {
         array22->data[i]--;
      }
   }
   return array22;
}

