#include "outs/3_9_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array7;
   if (pCounter > 0) {
      array7 = vars->data[--pCounter];
      array7->refC++;
      DEBUG_COPY(array7->id);
   } else {
      array7 = (array_t*)malloc(sizeof(array_t));
      array7->size = 530;
      array7->refC = 1;
      array7->id = 7;
      array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
      memset(array7->data, 0, array7->size*sizeof(unsigned int));
      DEBUG_NEW(array7->id);
   }
   if(PATH0 & 1) {
   }
   else {
   }
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/2 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      for (int i = 0; i < array7->size; i++) {
         array7->data[i]++;
      }
   }
   return array7;
}

