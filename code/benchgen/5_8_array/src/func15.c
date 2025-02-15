#include "outs/5_8_array.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array81;
   if (pCounter > 0) {
      array81 = vars->data[--pCounter];
      array81->refC++;
      DEBUG_COPY(array81->id);
   } else {
      array81 = (array_t*)malloc(sizeof(array_t));
      array81->size = 624;
      array81->refC = 1;
      array81->id = 81;
      array81->data = (unsigned int*)malloc(array81->size*sizeof(unsigned int));
      memset(array81->data, 0, array81->size*sizeof(unsigned int));
      DEBUG_NEW(array81->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array81;
   array_t* array82 = func18(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array82->id);
   free(params0.data);
   unsigned int loop24 = 0;
   unsigned int loopLimit24 = (rand()%loopsFactor)/2 + 1;
   for(; loop24 < loopLimit24; loop24++) {
      for (int i = 0; i < array81->size; i++) {
         array81->data[i]++;
      }
   }
   for (int i = 0; i < array82->size; i++) {
      if (array82->data[i] == 79) { 
         return array82;
      }
   }
   array82->refC--;
   if(array82->refC == 0) {
      free(array82->data);
      free(array82);
      DEBUG_FREE(array82->id);
   }
   return array81;
}

