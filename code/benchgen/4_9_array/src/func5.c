#include "outs/4_9_array.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array17;
   if (pCounter > 0) {
      array17 = vars->data[--pCounter];
      array17->refC++;
      DEBUG_COPY(array17->id);
   } else {
      array17 = (array_t*)malloc(sizeof(array_t));
      array17->size = 336;
      array17->refC = 1;
      array17->id = 17;
      array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
      memset(array17->data, 0, array17->size*sizeof(unsigned int));
      DEBUG_NEW(array17->id);
   }
   for (int i = 0; i < array17->size; i++) {
      array17->data[i]++;
   }
   for (int i = 0; i < array17->size; i++) {
      if (array17->data[i] == 29) { 
         return array17;
      }
   }
   for (int i = 0; i < array17->size; i++) {
      array17->data[i]--;
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array17;
   array_t* array18 = func13(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array18->id);
   free(params0.data);
   array18->refC--;
   if(array18->refC == 0) {
      free(array18->data);
      free(array18);
      DEBUG_FREE(array18->id);
   }
   return array17;
}

