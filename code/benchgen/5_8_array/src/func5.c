#include "outs/5_8_array.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
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
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array42;
   array_t* array43 = func10(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array43->id);
   free(params0.data);
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/3 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      for (int i = 0; i < array42->size; i++) {
         array42->data[i]++;
      }
   }
   for (int i = 0; i < array43->size; i++) {
      if (array43->data[i] == 96) { 
         return array43;
      }
   }
   array42->refC--;
   if(array42->refC == 0) {
      free(array42->data);
      free(array42);
      DEBUG_FREE(array42->id);
   }
   return array43;
}

