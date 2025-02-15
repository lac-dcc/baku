#include "outs/3_8_array.h" 
array_t* func14(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array18;
   if (pCounter > 0) {
      array18 = vars->data[--pCounter];
      array18->refC++;
      DEBUG_COPY(array18->id);
   } else {
      array18 = (array_t*)malloc(sizeof(array_t));
      array18->size = 505;
      array18->refC = 1;
      array18->id = 18;
      array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
      memset(array18->data, 0, array18->size*sizeof(unsigned int));
      DEBUG_NEW(array18->id);
   }
   for (int i = 0; i < array18->size; i++) {
      array18->data[i]--;
   }
   for (int i = 0; i < array18->size; i++) {
      if (array18->data[i] == 13) { 
         return array18;
      }
   }
   return array18;
}

