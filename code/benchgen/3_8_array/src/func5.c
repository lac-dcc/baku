#include "outs/3_8_array.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array14;
   if (pCounter > 0) {
      array14 = vars->data[--pCounter];
      array14->refC++;
      DEBUG_COPY(array14->id);
   } else {
      array14 = (array_t*)malloc(sizeof(array_t));
      array14->size = 413;
      array14->refC = 1;
      array14->id = 14;
      array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
      memset(array14->data, 0, array14->size*sizeof(unsigned int));
      DEBUG_NEW(array14->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array14;
   array_t* array15 = func10(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array15->id);
   free(params0.data);
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/3 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      for (int i = 0; i < array14->size; i++) {
         array14->data[i]++;
      }
   }
   for (int i = 0; i < array14->size; i++) {
      if (array14->data[i] == 73) { 
         return array14;
      }
   }
   array15->refC--;
   if(array15->refC == 0) {
      free(array15->data);
      free(array15);
      DEBUG_FREE(array15->id);
   }
   return array14;
}

