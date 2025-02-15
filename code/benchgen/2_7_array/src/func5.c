#include "outs/2_7_array.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array11;
   if (pCounter > 0) {
      array11 = vars->data[--pCounter];
      array11->refC++;
      DEBUG_COPY(array11->id);
   } else {
      array11 = (array_t*)malloc(sizeof(array_t));
      array11->size = 929;
      array11->refC = 1;
      array11->id = 11;
      array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
      memset(array11->data, 0, array11->size*sizeof(unsigned int));
      DEBUG_NEW(array11->id);
   }
   return array11;
}

