#include "array8_2.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array33;
   if (pCounter > 0) {
      array33 = vars->data[--pCounter];
      array33->refC++;
      DEBUG_COPY(array33->id);
   } else {
      array33 = (array_t*)malloc(sizeof(array_t));
      array33->size = 795;
      array33->refC = 1;
      array33->id = 33;
      array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
      memset(array33->data, 0, array33->size*sizeof(unsigned int));
      DEBUG_NEW(array33->id);
   }
   return array33;
}

