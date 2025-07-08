#include "array10_9.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array12;
   if (pCounter > 0) {
      array12 = vars->data[--pCounter];
      array12->refC++;
      DEBUG_COPY(array12->id);
   } else {
      array12 = (array_t*)malloc(sizeof(array_t));
      array12->size = 58;
      array12->refC = 1;
      array12->id = 12;
      array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
      memset(array12->data, 0, array12->size*sizeof(unsigned int));
      DEBUG_NEW(array12->id);
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/9 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      array_t* array13;
      if (pCounter > 0) {
         array13 = vars->data[--pCounter];
         array13->refC++;
         DEBUG_COPY(array13->id);
      } else {
         array13 = (array_t*)malloc(sizeof(array_t));
         array13->size = 69;
         array13->refC = 1;
         array13->id = 13;
         array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
         memset(array13->data, 0, array13->size*sizeof(unsigned int));
         DEBUG_NEW(array13->id);
      }
      unsigned int loop9 = 0;
      unsigned int loopLimit9 = (rand()%loopsFactor)/10 + 1;
      for(; loop9 < loopLimit9; loop9++) {
         for (int i = 0; i < array13->size; i++) {
            array13->data[i]--;
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array12;
         params0.data[1] = array13;
         array_t* array14 = func5(&params0, loopsFactor);
         DEBUG_RETURN(array14->id);
         free(params0.data);
         array14->refC--;
         if(array14->refC == 0) {
            free(array14->data);
            free(array14);
            DEBUG_FREE(array14->id);
         }
      }
      array13->refC--;
      if(array13->refC == 0) {
         free(array13->data);
         free(array13);
         DEBUG_FREE(array13->id);
      }
   }
   return array12;
}

