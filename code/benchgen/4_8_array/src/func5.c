#include "outs/4_8_array.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array23;
   if (pCounter > 0) {
      array23 = vars->data[--pCounter];
      array23->refC++;
      DEBUG_COPY(array23->id);
   } else {
      array23 = (array_t*)malloc(sizeof(array_t));
      array23->size = 808;
      array23->refC = 1;
      array23->id = 23;
      array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
      memset(array23->data, 0, array23->size*sizeof(unsigned int));
      DEBUG_NEW(array23->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array23;
   array_t* array24 = func10(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array24->id);
   free(params0.data);
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      for (int i = 0; i < array23->size; i++) {
         array23->data[i]++;
      }
   }
   for (int i = 0; i < array23->size; i++) {
      if (array23->data[i] == 3) { 
         return array23;
      }
   }
   array23->refC--;
   if(array23->refC == 0) {
      free(array23->data);
      free(array23);
      DEBUG_FREE(array23->id);
   }
   return array24;
}

