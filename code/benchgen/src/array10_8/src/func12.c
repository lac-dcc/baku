#include "array10_8.h" 
array_t* func12(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array52;
   if (pCounter > 0) {
      array52 = vars->data[--pCounter];
      array52->refC++;
      DEBUG_COPY(array52->id);
   } else {
      array52 = (array_t*)malloc(sizeof(array_t));
      array52->size = 379;
      array52->refC = 1;
      array52->id = 52;
      array52->data = (unsigned int*)malloc(array52->size*sizeof(unsigned int));
      memset(array52->data, 0, array52->size*sizeof(unsigned int));
      DEBUG_NEW(array52->id);
   }
   return array52;
}

