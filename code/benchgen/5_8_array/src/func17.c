#include "outs/5_8_array.h" 
array_t* func17(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array27;
   if (pCounter > 0) {
      array27 = vars->data[--pCounter];
      array27->refC++;
      DEBUG_COPY(array27->id);
   } else {
      array27 = (array_t*)malloc(sizeof(array_t));
      array27->size = 539;
      array27->refC = 1;
      array27->id = 27;
      array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
      memset(array27->data, 0, array27->size*sizeof(unsigned int));
      DEBUG_NEW(array27->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array27;
   array_t* array28 = func24(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array28->id);
   free(params0.data);
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      for (int i = 0; i < array27->size; i++) {
         array27->data[i]++;
      }
   }
   for (int i = 0; i < array27->size; i++) {
      if (array27->data[i] == 67) { 
         return array27;
      }
   }
   array27->refC--;
   if(array27->refC == 0) {
      free(array27->data);
      free(array27);
      DEBUG_FREE(array27->id);
   }
   return array28;
}

