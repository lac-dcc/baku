#include "outs/5_7_array.h" 
array_t* func12(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array4;
   if (pCounter > 0) {
      array4 = vars->data[--pCounter];
      array4->refC++;
      DEBUG_COPY(array4->id);
   } else {
      array4 = (array_t*)malloc(sizeof(array_t));
      array4->size = 690;
      array4->refC = 1;
      array4->id = 4;
      array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
      memset(array4->data, 0, array4->size*sizeof(unsigned int));
      DEBUG_NEW(array4->id);
   }
   return array4;
}

