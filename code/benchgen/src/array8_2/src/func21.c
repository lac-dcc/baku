#include "array8_2.h" 
array_t* func21(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array48;
   if (pCounter > 0) {
      array48 = vars->data[--pCounter];
      array48->refC++;
      DEBUG_COPY(array48->id);
   } else {
      array48 = (array_t*)malloc(sizeof(array_t));
      array48->size = 19;
      array48->refC = 1;
      array48->id = 48;
      array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
      memset(array48->data, 0, array48->size*sizeof(unsigned int));
      DEBUG_NEW(array48->id);
   }
   return array48;
}

