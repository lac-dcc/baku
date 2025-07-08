#include "array10_8.h" 
array_t* func25(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array13;
      if (pCounter > 0) {
         array13 = vars->data[--pCounter];
         array13->refC++;
         DEBUG_COPY(array13->id);
      } else {
         array13 = (array_t*)malloc(sizeof(array_t));
         array13->size = 537;
         array13->refC = 1;
         array13->id = 13;
         array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
         memset(array13->data, 0, array13->size*sizeof(unsigned int));
         DEBUG_NEW(array13->id);
      }
      array13->refC--;
      if(array13->refC == 0) {
         free(array13->data);
         free(array13);
         DEBUG_FREE(array13->id);
      }
   }
   array_t* array14;
   if (pCounter > 0) {
      array14 = vars->data[--pCounter];
      array14->refC++;
      DEBUG_COPY(array14->id);
   } else {
      array14 = (array_t*)malloc(sizeof(array_t));
      array14->size = 198;
      array14->refC = 1;
      array14->id = 14;
      array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
      memset(array14->data, 0, array14->size*sizeof(unsigned int));
      DEBUG_NEW(array14->id);
   }
   return array14;
}

