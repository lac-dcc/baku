#include "outs/4_9_array.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 301;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   for (int i = 0; i < array29->size; i++) {
      array29->data[i]++;
   }
   for (int i = 0; i < array29->size; i++) {
      if (array29->data[i] == 41) { 
         return array29;
      }
   }
   for (int i = 0; i < array29->size; i++) {
      array29->data[i]--;
   }
   return array29;
}

