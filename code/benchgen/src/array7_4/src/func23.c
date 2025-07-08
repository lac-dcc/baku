#include "array7_4.h" 
array_t* func23(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array44;
   if (pCounter > 0) {
      array44 = vars->data[--pCounter];
      array44->refC++;
      DEBUG_COPY(array44->id);
   } else {
      array44 = (array_t*)malloc(sizeof(array_t));
      array44->size = 353;
      array44->refC = 1;
      array44->id = 44;
      array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
      memset(array44->data, 0, array44->size*sizeof(unsigned int));
      DEBUG_NEW(array44->id);
   }
   return array44;
}

