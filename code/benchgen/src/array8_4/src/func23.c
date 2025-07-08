#include "array8_4.h" 
array_t* func23(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array51;
   if (pCounter > 0) {
      array51 = vars->data[--pCounter];
      array51->refC++;
      DEBUG_COPY(array51->id);
   } else {
      array51 = (array_t*)malloc(sizeof(array_t));
      array51->size = 846;
      array51->refC = 1;
      array51->id = 51;
      array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
      memset(array51->data, 0, array51->size*sizeof(unsigned int));
      DEBUG_NEW(array51->id);
   }
   return array51;
}

