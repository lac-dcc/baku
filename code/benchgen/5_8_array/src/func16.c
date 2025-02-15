#include "outs/5_8_array.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array22;
   if (pCounter > 0) {
      array22 = vars->data[--pCounter];
      array22->refC++;
      DEBUG_COPY(array22->id);
   } else {
      array22 = (array_t*)malloc(sizeof(array_t));
      array22->size = 808;
      array22->refC = 1;
      array22->id = 22;
      array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
      memset(array22->data, 0, array22->size*sizeof(unsigned int));
      DEBUG_NEW(array22->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      for (int i = 0; i < array22->size; i++) {
         if (array22->data[i] == 78) { 
            return array22;
         }
      }
   }
   for (int i = 0; i < array22->size; i++) {
      array22->data[i]--;
   }
   for (int i = 0; i < array22->size; i++) {
      if (array22->data[i] == 3) { 
         return array22;
      }
   }
   return array22;
}

