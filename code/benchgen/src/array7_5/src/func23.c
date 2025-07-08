#include "array7_5.h" 
array_t* func23(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array31;
   if (pCounter > 0) {
      array31 = vars->data[--pCounter];
      array31->refC++;
      DEBUG_COPY(array31->id);
   } else {
      array31 = (array_t*)malloc(sizeof(array_t));
      array31->size = 97;
      array31->refC = 1;
      array31->id = 31;
      array31->data = (unsigned int*)malloc(array31->size*sizeof(unsigned int));
      memset(array31->data, 0, array31->size*sizeof(unsigned int));
      DEBUG_NEW(array31->id);
   }
   return array31;
}

