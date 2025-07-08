#include "array8_5.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array42;
   if (pCounter > 0) {
      array42 = vars->data[--pCounter];
      array42->refC++;
      DEBUG_COPY(array42->id);
   } else {
      array42 = (array_t*)malloc(sizeof(array_t));
      array42->size = 368;
      array42->refC = 1;
      array42->id = 42;
      array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
      memset(array42->data, 0, array42->size*sizeof(unsigned int));
      DEBUG_NEW(array42->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/1 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      for (int i = 0; i < array42->size; i++) {
         array42->data[i]--;
      }
   }
   return array42;
}

