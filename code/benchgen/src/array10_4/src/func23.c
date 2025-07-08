#include "array10_4.h" 
array_t* func23(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array54;
   if (pCounter > 0) {
      array54 = vars->data[--pCounter];
      array54->refC++;
      DEBUG_COPY(array54->id);
   } else {
      array54 = (array_t*)malloc(sizeof(array_t));
      array54->size = 228;
      array54->refC = 1;
      array54->id = 54;
      array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
      memset(array54->data, 0, array54->size*sizeof(unsigned int));
      DEBUG_NEW(array54->id);
   }
   return array54;
}

