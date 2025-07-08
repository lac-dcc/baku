#include "array10_4.h" 
array_t* func27(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array22;
   if (pCounter > 0) {
      array22 = vars->data[--pCounter];
      array22->refC++;
      DEBUG_COPY(array22->id);
   } else {
      array22 = (array_t*)malloc(sizeof(array_t));
      array22->size = 729;
      array22->refC = 1;
      array22->id = 22;
      array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
      memset(array22->data, 0, array22->size*sizeof(unsigned int));
      DEBUG_NEW(array22->id);
   }
   return array22;
}

