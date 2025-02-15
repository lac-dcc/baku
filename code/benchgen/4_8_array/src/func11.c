#include "outs/4_8_array.h" 
array_t* func11(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/3 + 1;
   for(; loop3 < loopLimit3; loop3++) {
   }
   array_t* array5;
   if (pCounter > 0) {
      array5 = vars->data[--pCounter];
      array5->refC++;
      DEBUG_COPY(array5->id);
   } else {
      array5 = (array_t*)malloc(sizeof(array_t));
      array5->size = 736;
      array5->refC = 1;
      array5->id = 5;
      array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
      memset(array5->data, 0, array5->size*sizeof(unsigned int));
      DEBUG_NEW(array5->id);
   }
   return array5;
}

