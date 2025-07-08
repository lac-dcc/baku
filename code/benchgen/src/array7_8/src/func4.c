#include "array7_8.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array40;
   if (pCounter > 0) {
      array40 = vars->data[--pCounter];
      array40->refC++;
      DEBUG_COPY(array40->id);
   } else {
      array40 = (array_t*)malloc(sizeof(array_t));
      array40->size = 117;
      array40->refC = 1;
      array40->id = 40;
      array40->data = (unsigned int*)malloc(array40->size*sizeof(unsigned int));
      memset(array40->data, 0, array40->size*sizeof(unsigned int));
      DEBUG_NEW(array40->id);
   }
   return array40;
}

