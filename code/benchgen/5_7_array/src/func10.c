#include "outs/5_7_array.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array26;
   if (pCounter > 0) {
      array26 = vars->data[--pCounter];
      array26->refC++;
      DEBUG_COPY(array26->id);
   } else {
      array26 = (array_t*)malloc(sizeof(array_t));
      array26->size = 505;
      array26->refC = 1;
      array26->id = 26;
      array26->data = (unsigned int*)malloc(array26->size*sizeof(unsigned int));
      memset(array26->data, 0, array26->size*sizeof(unsigned int));
      DEBUG_NEW(array26->id);
   }
   for (int i = 0; i < array26->size; i++) {
      if (array26->data[i] == 29) { 
         return array26;
      }
   }
   for (int i = 0; i < array26->size; i++) {
      if (array26->data[i] == 57) { 
         return array26;
      }
   }
   return array26;
}

