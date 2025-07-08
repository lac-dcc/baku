#include "array7_4.h" 
array_t* func13(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array35;
   if (pCounter > 0) {
      array35 = vars->data[--pCounter];
      array35->refC++;
      DEBUG_COPY(array35->id);
   } else {
      array35 = (array_t*)malloc(sizeof(array_t));
      array35->size = 902;
      array35->refC = 1;
      array35->id = 35;
      array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
      memset(array35->data, 0, array35->size*sizeof(unsigned int));
      DEBUG_NEW(array35->id);
   }
   return array35;
}

