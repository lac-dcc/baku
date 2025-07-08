#include "array8_2.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array43;
   if (pCounter > 0) {
      array43 = vars->data[--pCounter];
      array43->refC++;
      DEBUG_COPY(array43->id);
   } else {
      array43 = (array_t*)malloc(sizeof(array_t));
      array43->size = 567;
      array43->refC = 1;
      array43->id = 43;
      array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
      memset(array43->data, 0, array43->size*sizeof(unsigned int));
      DEBUG_NEW(array43->id);
   }
   return array43;
}

