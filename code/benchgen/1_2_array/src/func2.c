#include "outs/1_2_array.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array3;
   if (pCounter > 0) {
      array3 = vars->data[--pCounter];
      array3->refC++;
      DEBUG_COPY(array3->id);
   } else {
      array3 = (array_t*)malloc(sizeof(array_t));
      array3->size = 763;
      array3->refC = 1;
      array3->id = 3;
      array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
      memset(array3->data, 0, array3->size*sizeof(unsigned int));
      DEBUG_NEW(array3->id);
   }
   return array3;
}

