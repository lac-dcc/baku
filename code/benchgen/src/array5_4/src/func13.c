#include "array5_4.h" 
array_t* func13(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array32;
   if (pCounter > 0) {
      array32 = vars->data[--pCounter];
      array32->refC++;
      DEBUG_COPY(array32->id);
   } else {
      array32 = (array_t*)malloc(sizeof(array_t));
      array32->size = 795;
      array32->refC = 1;
      array32->id = 32;
      array32->data = (unsigned int*)malloc(array32->size*sizeof(unsigned int));
      memset(array32->data, 0, array32->size*sizeof(unsigned int));
      DEBUG_NEW(array32->id);
   }
   return array32;
}

