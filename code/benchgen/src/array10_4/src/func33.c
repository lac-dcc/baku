#include "array10_4.h" 
array_t* func33(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array63;
   if (pCounter > 0) {
      array63 = vars->data[--pCounter];
      array63->refC++;
      DEBUG_COPY(array63->id);
   } else {
      array63 = (array_t*)malloc(sizeof(array_t));
      array63->size = 395;
      array63->refC = 1;
      array63->id = 63;
      array63->data = (unsigned int*)malloc(array63->size*sizeof(unsigned int));
      memset(array63->data, 0, array63->size*sizeof(unsigned int));
      DEBUG_NEW(array63->id);
   }
   return array63;
}

