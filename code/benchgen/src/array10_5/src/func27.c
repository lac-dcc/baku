#include "array10_5.h" 
array_t* func27(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array38 = func28(&params0, loopsFactor);
      DEBUG_RETURN(array38->id);
      free(params0.data);
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array40 = func29(&params0, loopsFactor);
      DEBUG_RETURN(array40->id);
      free(params0.data);
      array40->refC--;
      if(array40->refC == 0) {
         free(array40->data);
         free(array40);
         DEBUG_FREE(array40->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array42 = func30(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(array42->id);
   free(params0.data);
   return array42;
}

