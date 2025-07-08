#include "array10_4.h" 
array_t* func32(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array62 = func33(&params0, loopsFactor);
      DEBUG_RETURN(array62->id);
      free(params0.data);
      array62->refC--;
      if(array62->refC == 0) {
         free(array62->data);
         free(array62);
         DEBUG_FREE(array62->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array64 = func34(&params0, loopsFactor);
      DEBUG_RETURN(array64->id);
      free(params0.data);
      array64->refC--;
      if(array64->refC == 0) {
         free(array64->data);
         free(array64);
         DEBUG_FREE(array64->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array66 = func35(&params0, loopsFactor);
   DEBUG_RETURN(array66->id);
   free(params0.data);
   return array66;
}

