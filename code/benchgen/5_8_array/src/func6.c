#include "outs/5_8_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array64 = func7(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array64->id);
      free(params0.data);
      array64->refC--;
      if(array64->refC == 0) {
         free(array64->data);
         free(array64);
         DEBUG_FREE(array64->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array73 = func8(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array73->id);
      free(params0.data);
      array73->refC--;
      if(array73->refC == 0) {
         free(array73->data);
         free(array73);
         DEBUG_FREE(array73->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array78 = func9(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array78->id);
   free(params0.data);
   return array78;
}

