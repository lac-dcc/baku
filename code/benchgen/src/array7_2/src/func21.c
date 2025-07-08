#include "array7_2.h" 
array_t* func21(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array42;
   if (pCounter > 0) {
      array42 = vars->data[--pCounter];
      array42->refC++;
      DEBUG_COPY(array42->id);
   } else {
      array42 = (array_t*)malloc(sizeof(array_t));
      array42->size = 481;
      array42->refC = 1;
      array42->id = 42;
      array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
      memset(array42->data, 0, array42->size*sizeof(unsigned int));
      DEBUG_NEW(array42->id);
   }
   return array42;
}

