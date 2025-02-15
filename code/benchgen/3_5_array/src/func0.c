#include "outs/3_5_array.h" 
array_t* func0(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array1 = func3(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array1->id);
      free(params0.data);
      array_t* array12;
      if (pCounter > 0) {
         array12 = vars->data[--pCounter];
         array12->refC++;
         DEBUG_COPY(array12->id);
      } else {
         array12 = (array_t*)malloc(sizeof(array_t));
         array12->size = 229;
         array12->refC = 1;
         array12->id = 12;
         array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
         memset(array12->data, 0, array12->size*sizeof(unsigned int));
         DEBUG_NEW(array12->id);
      }
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         for (int i = 0; i < array12->size; i++) {
            array12->data[i]++;
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array12;
         array_t* array13 = func2(&params1, loopsFactor);
         DEBUG_RETURN(array13->id);
         free(params1.data);
         for (int i = 0; i < array13->size; i++) {
            if (array13->data[i] == 26) { 
               return array13;
            }
         }
         for (int i = 0; i < array12->size; i++) {
            if (array12->data[i] == 80) { 
               return array12;
            }
         }
         array13->refC--;
         if(array13->refC == 0) {
            free(array13->data);
            free(array13);
            DEBUG_FREE(array13->id);
         }
      }
      array12->refC--;
      if(array12->refC == 0) {
         free(array12->data);
         free(array12);
         DEBUG_FREE(array12->id);
      }
      array1->refC--;
      if(array1->refC == 0) {
         free(array1->data);
         free(array1);
         DEBUG_FREE(array1->id);
      }
   }
   array_t* array16;
   if (pCounter > 0) {
      array16 = vars->data[--pCounter];
      array16->refC++;
      DEBUG_COPY(array16->id);
   } else {
      array16 = (array_t*)malloc(sizeof(array_t));
      array16->size = 956;
      array16->refC = 1;
      array16->id = 16;
      array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
      memset(array16->data, 0, array16->size*sizeof(unsigned int));
      DEBUG_NEW(array16->id);
   }
   return array16;
}

