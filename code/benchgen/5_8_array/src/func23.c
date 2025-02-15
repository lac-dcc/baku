#include "outs/5_8_array.h" 
array_t* func23(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array10;
   if (pCounter > 0) {
      array10 = vars->data[--pCounter];
      array10->refC++;
      DEBUG_COPY(array10->id);
   } else {
      array10 = (array_t*)malloc(sizeof(array_t));
      array10->size = 456;
      array10->refC = 1;
      array10->id = 10;
      array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
      memset(array10->data, 0, array10->size*sizeof(unsigned int));
      DEBUG_NEW(array10->id);
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/4 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      for (int i = 0; i < array10->size; i++) {
         array10->data[i]++;
      }
   }
   for (int i = 0; i < array10->size; i++) {
      if (array10->data[i] == 29) { 
         return array10;
      }
   }
   return array10;
}

