#include "array8_4.h" 
array_t* func30(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array57;
   if (pCounter > 0) {
      array57 = vars->data[--pCounter];
      array57->refC++;
      DEBUG_COPY(array57->id);
   } else {
      array57 = (array_t*)malloc(sizeof(array_t));
      array57->size = 856;
      array57->refC = 1;
      array57->id = 57;
      array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
      memset(array57->data, 0, array57->size*sizeof(unsigned int));
      DEBUG_NEW(array57->id);
   }
   return array57;
}

