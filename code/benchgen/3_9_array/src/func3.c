#include "outs/3_9_array.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array21;
   if (pCounter > 0) {
      array21 = vars->data[--pCounter];
      array21->refC++;
      DEBUG_COPY(array21->id);
   } else {
      array21 = (array_t*)malloc(sizeof(array_t));
      array21->size = 651;
      array21->refC = 1;
      array21->id = 21;
      array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
      memset(array21->data, 0, array21->size*sizeof(unsigned int));
      DEBUG_NEW(array21->id);
   }
   for (int i = 0; i < array21->size; i++) {
      array21->data[i]++;
   }
   for (int i = 0; i < array21->size; i++) {
      if (array21->data[i] == 32) { 
         return array21;
      }
   }
   for (int i = 0; i < array21->size; i++) {
      array21->data[i]--;
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array21;
   array_t* array22 = func8(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array22->id);
   free(params0.data);
   array21->refC--;
   if(array21->refC == 0) {
      free(array21->data);
      free(array21);
      DEBUG_FREE(array21->id);
   }
   return array22;
}

