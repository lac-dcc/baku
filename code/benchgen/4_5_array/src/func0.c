#include "outs/4_5_array.h" 
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
      array_t* array18;
      if (pCounter > 0) {
         array18 = vars->data[--pCounter];
         array18->refC++;
         DEBUG_COPY(array18->id);
      } else {
         array18 = (array_t*)malloc(sizeof(array_t));
         array18->size = 980;
         array18->refC = 1;
         array18->id = 18;
         array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
         memset(array18->data, 0, array18->size*sizeof(unsigned int));
         DEBUG_NEW(array18->id);
      }
      unsigned int loop11 = 0;
      unsigned int loopLimit11 = (rand()%loopsFactor)/3 + 1;
      for(; loop11 < loopLimit11; loop11++) {
         for (int i = 0; i < array1->size; i++) {
            array1->data[i]++;
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array18;
         array_t* array19 = func2(&params1, loopsFactor);
         DEBUG_RETURN(array19->id);
         free(params1.data);
         for (int i = 0; i < array1->size; i++) {
            if (array1->data[i] == 36) { 
               return array1;
            }
         }
         for (int i = 0; i < array19->size; i++) {
            if (array19->data[i] == 46) { 
               return array19;
            }
         }
         array19->refC--;
         if(array19->refC == 0) {
            free(array19->data);
            free(array19);
            DEBUG_FREE(array19->id);
         }
      }
      array18->refC--;
      if(array18->refC == 0) {
         free(array18->data);
         free(array18);
         DEBUG_FREE(array18->id);
      }
      array1->refC--;
      if(array1->refC == 0) {
         free(array1->data);
         free(array1);
         DEBUG_FREE(array1->id);
      }
   }
   array_t* array22;
   if (pCounter > 0) {
      array22 = vars->data[--pCounter];
      array22->refC++;
      DEBUG_COPY(array22->id);
   } else {
      array22 = (array_t*)malloc(sizeof(array_t));
      array22->size = 729;
      array22->refC = 1;
      array22->id = 22;
      array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
      memset(array22->data, 0, array22->size*sizeof(unsigned int));
      DEBUG_NEW(array22->id);
   }
   return array22;
}

