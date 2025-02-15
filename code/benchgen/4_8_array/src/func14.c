#include "outs/4_8_array.h" 
array_t* func14(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array34;
   if (pCounter > 0) {
      array34 = vars->data[--pCounter];
      array34->refC++;
      DEBUG_COPY(array34->id);
   } else {
      array34 = (array_t*)malloc(sizeof(array_t));
      array34->size = 619;
      array34->refC = 1;
      array34->id = 34;
      array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
      memset(array34->data, 0, array34->size*sizeof(unsigned int));
      DEBUG_NEW(array34->id);
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/3 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      for (int i = 0; i < array34->size; i++) {
         if (array34->data[i] == 29) { 
            return array34;
         }
      }
   }
   for (int i = 0; i < array34->size; i++) {
      array34->data[i]--;
   }
   for (int i = 0; i < array34->size; i++) {
      if (array34->data[i] == 97) { 
         return array34;
      }
   }
   return array34;
}

