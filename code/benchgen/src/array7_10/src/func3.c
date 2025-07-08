#include "array7_10.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array10;
   if (pCounter > 0) {
      array10 = vars->data[--pCounter];
      array10->refC++;
      DEBUG_COPY(array10->id);
   } else {
      array10 = (array_t*)malloc(sizeof(array_t));
      array10->size = 123;
      array10->refC = 1;
      array10->id = 10;
      array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
      memset(array10->data, 0, array10->size*sizeof(unsigned int));
      DEBUG_NEW(array10->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      for (int i = 0; i < array10->size; i++) {
         array10->data[i]++;
      }
      unsigned int loop8 = 0;
      unsigned int loopLimit8 = (rand()%loopsFactor)/9 + 1;
      for(; loop8 < loopLimit8; loop8++) {
      }
   }
   return array10;
}

