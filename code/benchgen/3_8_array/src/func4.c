#include "outs/3_8_array.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array11;
   if (pCounter > 0) {
      array11 = vars->data[--pCounter];
      array11->refC++;
      DEBUG_COPY(array11->id);
   } else {
      array11 = (array_t*)malloc(sizeof(array_t));
      array11->size = 11;
      array11->refC = 1;
      array11->id = 11;
      array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
      memset(array11->data, 0, array11->size*sizeof(unsigned int));
      DEBUG_NEW(array11->id);
   }
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/3 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      for (int i = 0; i < array11->size; i++) {
         if (array11->data[i] == 29) { 
            return array11;
         }
      }
   }
   for (int i = 0; i < array11->size; i++) {
      array11->data[i]--;
   }
   for (int i = 0; i < array11->size; i++) {
      if (array11->data[i] == 19) { 
         return array11;
      }
   }
   return array11;
}

