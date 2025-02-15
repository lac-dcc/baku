#include "outs/3_5_array.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   array_t* array15;
   if (pCounter > 0) {
      array15 = vars->data[--pCounter];
      array15->refC++;
      DEBUG_COPY(array15->id);
   } else {
      array15 = (array_t*)malloc(sizeof(array_t));
      array15->size = 324;
      array15->refC = 1;
      array15->id = 15;
      array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
      memset(array15->data, 0, array15->size*sizeof(unsigned int));
      DEBUG_NEW(array15->id);
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/4 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      for (int i = 0; i < array15->size; i++) {
         array15->data[i]--;
      }
   }
   array15->refC--;
   if(array15->refC == 0) {
      free(array15->data);
      free(array15);
      DEBUG_FREE(array15->id);
   }
   return array14;
}

