#include "outs/1_5_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array6;
   if (pCounter > 0) {
      array6 = vars->data[--pCounter];
      array6->refC++;
      DEBUG_COPY(array6->id);
   } else {
      array6 = (array_t*)malloc(sizeof(array_t));
      array6->size = 782;
      array6->refC = 1;
      array6->id = 6;
      array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
      memset(array6->data, 0, array6->size*sizeof(unsigned int));
      DEBUG_NEW(array6->id);
   }
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/2 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      for (int i = 0; i < array6->size; i++) {
         array6->data[i]--;
      }
   }
   return array6;
}

