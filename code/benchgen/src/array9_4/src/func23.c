#include "array9_4.h" 
array_t* func23(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array53;
   if (pCounter > 0) {
      array53 = vars->data[--pCounter];
      array53->refC++;
      DEBUG_COPY(array53->id);
   } else {
      array53 = (array_t*)malloc(sizeof(array_t));
      array53->size = 764;
      array53->refC = 1;
      array53->id = 53;
      array53->data = (unsigned int*)malloc(array53->size*sizeof(unsigned int));
      memset(array53->data, 0, array53->size*sizeof(unsigned int));
      DEBUG_NEW(array53->id);
   }
   return array53;
}

