#include "array10_4.h" 
array_t* func22(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array53 = func23(&params0, loopsFactor);
      DEBUG_RETURN(array53->id);
      free(params0.data);
      array53->refC--;
      if(array53->refC == 0) {
         free(array53->data);
         free(array53);
         DEBUG_FREE(array53->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array55 = func24(&params0, loopsFactor);
      DEBUG_RETURN(array55->id);
      free(params0.data);
      array55->refC--;
      if(array55->refC == 0) {
         free(array55->data);
         free(array55);
         DEBUG_FREE(array55->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array57 = func25(&params0, loopsFactor);
   DEBUG_RETURN(array57->id);
   free(params0.data);
   return array57;
}

