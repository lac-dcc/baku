#include "array8_4.h" 
array_t* func18(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array15;
   if (pCounter > 0) {
      array15 = vars->data[--pCounter];
      array15->refC++;
      DEBUG_COPY(array15->id);
   } else {
      array15 = (array_t*)malloc(sizeof(array_t));
      array15->size = 324;
      array15->refC = 1;
      array15->id = 15;
      array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
      memset(array15->data, 0, array15->size*sizeof(unsigned int));
      DEBUG_NEW(array15->id);
   }
   return array15;
}

