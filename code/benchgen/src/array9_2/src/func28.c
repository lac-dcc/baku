#include "array9_2.h" 
array_t* func28(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array56;
   if (pCounter > 0) {
      array56 = vars->data[--pCounter];
      array56->refC++;
      DEBUG_COPY(array56->id);
   } else {
      array56 = (array_t*)malloc(sizeof(array_t));
      array56->size = 500;
      array56->refC = 1;
      array56->id = 56;
      array56->data = (unsigned int*)malloc(array56->size*sizeof(unsigned int));
      memset(array56->data, 0, array56->size*sizeof(unsigned int));
      DEBUG_NEW(array56->id);
   }
   return array56;
}

