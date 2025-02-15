#include "outs/4_5_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array24;
   if (pCounter > 0) {
      array24 = vars->data[--pCounter];
      array24->refC++;
      DEBUG_COPY(array24->id);
   } else {
      array24 = (array_t*)malloc(sizeof(array_t));
      array24->size = 545;
      array24->refC = 1;
      array24->id = 24;
      array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
      memset(array24->data, 0, array24->size*sizeof(unsigned int));
      DEBUG_NEW(array24->id);
   }
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/2 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      for (int i = 0; i < array24->size; i++) {
         array24->data[i]--;
      }
   }
   return array24;
}

