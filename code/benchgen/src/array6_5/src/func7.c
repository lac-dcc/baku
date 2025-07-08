#include "array6_5.h" 
array_t* func7(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array4;
   if (pCounter > 0) {
      array4 = vars->data[--pCounter];
      array4->refC++;
      DEBUG_COPY(array4->id);
   } else {
      array4 = (array_t*)malloc(sizeof(array_t));
      array4->size = 926;
      array4->refC = 1;
      array4->id = 4;
      array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
      memset(array4->data, 0, array4->size*sizeof(unsigned int));
      DEBUG_NEW(array4->id);
   }
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      for (int i = 0; i < array4->size; i++) {
         array4->data[i]--;
      }
   }
   return array4;
}

