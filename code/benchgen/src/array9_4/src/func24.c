#include "array9_4.h" 
array_t* func24(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array55;
   if (pCounter > 0) {
      array55 = vars->data[--pCounter];
      array55->refC++;
      DEBUG_COPY(array55->id);
   } else {
      array55 = (array_t*)malloc(sizeof(array_t));
      array55->size = 34;
      array55->refC = 1;
      array55->id = 55;
      array55->data = (unsigned int*)malloc(array55->size*sizeof(unsigned int));
      memset(array55->data, 0, array55->size*sizeof(unsigned int));
      DEBUG_NEW(array55->id);
   }
   return array55;
}

