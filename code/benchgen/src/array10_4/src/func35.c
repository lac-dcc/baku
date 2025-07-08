#include "array10_4.h" 
array_t* func35(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array67;
   if (pCounter > 0) {
      array67 = vars->data[--pCounter];
      array67->refC++;
      DEBUG_COPY(array67->id);
   } else {
      array67 = (array_t*)malloc(sizeof(array_t));
      array67->size = 404;
      array67->refC = 1;
      array67->id = 67;
      array67->data = (unsigned int*)malloc(array67->size*sizeof(unsigned int));
      memset(array67->data, 0, array67->size*sizeof(unsigned int));
      DEBUG_NEW(array67->id);
   }
   return array67;
}

