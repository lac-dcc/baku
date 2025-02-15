#include "outs/5_9_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array92;
   if (pCounter > 0) {
      array92 = vars->data[--pCounter];
      array92->refC++;
      DEBUG_COPY(array92->id);
   } else {
      array92 = (array_t*)malloc(sizeof(array_t));
      array92->size = 348;
      array92->refC = 1;
      array92->id = 92;
      array92->data = (unsigned int*)malloc(array92->size*sizeof(unsigned int));
      memset(array92->data, 0, array92->size*sizeof(unsigned int));
      DEBUG_NEW(array92->id);
   }
   for (int i = 0; i < array92->size; i++) {
      if (array92->data[i] == 59) { 
         return array92;
      }
   }
   return array92;
}

