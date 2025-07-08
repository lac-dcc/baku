#include "array10_2.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array50;
   if (pCounter > 0) {
      array50 = vars->data[--pCounter];
      array50->refC++;
      DEBUG_COPY(array50->id);
   } else {
      array50 = (array_t*)malloc(sizeof(array_t));
      array50->size = 340;
      array50->refC = 1;
      array50->id = 50;
      array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
      memset(array50->data, 0, array50->size*sizeof(unsigned int));
      DEBUG_NEW(array50->id);
   }
   return array50;
}

