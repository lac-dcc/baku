#include "outs/2_9_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array23;
   if (pCounter > 0) {
      array23 = vars->data[--pCounter];
      array23->refC++;
      DEBUG_COPY(array23->id);
   } else {
      array23 = (array_t*)malloc(sizeof(array_t));
      array23->size = 739;
      array23->refC = 1;
      array23->id = 23;
      array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
      memset(array23->data, 0, array23->size*sizeof(unsigned int));
      DEBUG_NEW(array23->id);
   }
   for (int i = 0; i < array23->size; i++) {
      if (array23->data[i] == 26) { 
         return array23;
      }
   }
   return array23;
}

