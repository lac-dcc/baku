#include "outs/4_9_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array65;
   if (pCounter > 0) {
      array65 = vars->data[--pCounter];
      array65->refC++;
      DEBUG_COPY(array65->id);
   } else {
      array65 = (array_t*)malloc(sizeof(array_t));
      array65->size = 669;
      array65->refC = 1;
      array65->id = 65;
      array65->data = (unsigned int*)malloc(array65->size*sizeof(unsigned int));
      memset(array65->data, 0, array65->size*sizeof(unsigned int));
      DEBUG_NEW(array65->id);
   }
   for (int i = 0; i < array65->size; i++) {
      if (array65->data[i] == 42) { 
         return array65;
      }
   }
   return array65;
}

