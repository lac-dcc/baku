#include "outs/4_8_array.h" 
array_t* func19(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array28;
   if (pCounter > 0) {
      array28 = vars->data[--pCounter];
      array28->refC++;
      DEBUG_COPY(array28->id);
   } else {
      array28 = (array_t*)malloc(sizeof(array_t));
      array28->size = 795;
      array28->refC = 1;
      array28->id = 28;
      array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
      memset(array28->data, 0, array28->size*sizeof(unsigned int));
      DEBUG_NEW(array28->id);
   }
   return array28;
}

