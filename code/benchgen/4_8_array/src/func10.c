#include "outs/4_8_array.h" 
array_t* func10(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array4 = func11(&params0, loopsFactor);
      DEBUG_RETURN(array4->id);
      free(params0.data);
      array4->refC--;
      if(array4->refC == 0) {
         free(array4->data);
         free(array4);
         DEBUG_FREE(array4->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array6 = func12(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array6->id);
      free(params0.data);
      array6->refC--;
      if(array6->refC == 0) {
         free(array6->data);
         free(array6);
         DEBUG_FREE(array6->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array11 = func13(&params0, loopsFactor);
   DEBUG_RETURN(array11->id);
   free(params0.data);
   return array11;
}

