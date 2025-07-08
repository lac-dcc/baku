#include "array6_4.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array24 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array24->id);
      free(params0.data);
      array24->refC--;
      if(array24->refC == 0) {
         free(array24->data);
         free(array24);
         DEBUG_FREE(array24->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array26 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array26->id);
      free(params0.data);
      array26->refC--;
      if(array26->refC == 0) {
         free(array26->data);
         free(array26);
         DEBUG_FREE(array26->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array28 = func5(&params0, loopsFactor);
   DEBUG_RETURN(array28->id);
   free(params0.data);
   return array28;
}

