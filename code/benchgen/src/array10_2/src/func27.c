#include "array10_2.h" 
array_t* func27(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array60;
   if (pCounter > 0) {
      array60 = vars->data[--pCounter];
      array60->refC++;
      DEBUG_COPY(array60->id);
   } else {
      array60 = (array_t*)malloc(sizeof(array_t));
      array60->size = 432;
      array60->refC = 1;
      array60->id = 60;
      array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
      memset(array60->data, 0, array60->size*sizeof(unsigned int));
      DEBUG_NEW(array60->id);
   }
   return array60;
}

