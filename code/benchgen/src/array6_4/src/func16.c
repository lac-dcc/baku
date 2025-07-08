#include "array6_4.h" 
array_t* func16(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array12 = func17(&params0, loopsFactor);
      DEBUG_RETURN(array12->id);
      free(params0.data);
      array12->refC--;
      if(array12->refC == 0) {
         free(array12->data);
         free(array12);
         DEBUG_FREE(array12->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array14 = func18(&params0, loopsFactor);
      DEBUG_RETURN(array14->id);
      free(params0.data);
      array14->refC--;
      if(array14->refC == 0) {
         free(array14->data);
         free(array14);
         DEBUG_FREE(array14->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array16 = func19(&params0, loopsFactor);
   DEBUG_RETURN(array16->id);
   free(params0.data);
   return array16;
}

