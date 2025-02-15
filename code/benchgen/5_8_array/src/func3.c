#include "outs/5_8_array.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array99;
   if (pCounter > 0) {
      array99 = vars->data[--pCounter];
      array99->refC++;
      DEBUG_COPY(array99->id);
   } else {
      array99 = (array_t*)malloc(sizeof(array_t));
      array99->size = 255;
      array99->refC = 1;
      array99->id = 99;
      array99->data = (unsigned int*)malloc(array99->size*sizeof(unsigned int));
      memset(array99->data, 0, array99->size*sizeof(unsigned int));
      DEBUG_NEW(array99->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array99;
   array_t* array100 = func6(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array100->id);
   free(params0.data);
   unsigned int loop29 = 0;
   unsigned int loopLimit29 = (rand()%loopsFactor)/2 + 1;
   for(; loop29 < loopLimit29; loop29++) {
      for (int i = 0; i < array100->size; i++) {
         array100->data[i]++;
      }
   }
   for (int i = 0; i < array99->size; i++) {
      if (array99->data[i] == 39) { 
         return array99;
      }
   }
   array99->refC--;
   if(array99->refC == 0) {
      free(array99->data);
      free(array99);
      DEBUG_FREE(array99->id);
   }
   return array100;
}

