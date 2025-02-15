#include "outs/2_8_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array11 = func7(&params0, loopsFactor);
      DEBUG_RETURN(array11->id);
      free(params0.data);
      array11->refC--;
      if(array11->refC == 0) {
         free(array11->data);
         free(array11);
         DEBUG_FREE(array11->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array13 = func8(&params0, loopsFactor);
      DEBUG_RETURN(array13->id);
      free(params0.data);
      array13->refC--;
      if(array13->refC == 0) {
         free(array13->data);
         free(array13);
         DEBUG_FREE(array13->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array15 = func9(&params0, loopsFactor);
   DEBUG_RETURN(array15->id);
   free(params0.data);
   return array15;
}

