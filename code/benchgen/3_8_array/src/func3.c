#include "outs/3_8_array.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array41;
   if (pCounter > 0) {
      array41 = vars->data[--pCounter];
      array41->refC++;
      DEBUG_COPY(array41->id);
   } else {
      array41 = (array_t*)malloc(sizeof(array_t));
      array41->size = 19;
      array41->refC = 1;
      array41->id = 41;
      array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
      memset(array41->data, 0, array41->size*sizeof(unsigned int));
      DEBUG_NEW(array41->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array41;
   array_t* array42 = func6(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array42->id);
   free(params0.data);
   unsigned int loop12 = 0;
   unsigned int loopLimit12 = (rand()%loopsFactor)/2 + 1;
   for(; loop12 < loopLimit12; loop12++) {
      for (int i = 0; i < array41->size; i++) {
         array41->data[i]++;
      }
   }
   for (int i = 0; i < array42->size; i++) {
      if (array42->data[i] == 40) { 
         return array42;
      }
   }
   array41->refC--;
   if(array41->refC == 0) {
      free(array41->data);
      free(array41);
      DEBUG_FREE(array41->id);
   }
   return array42;
}

