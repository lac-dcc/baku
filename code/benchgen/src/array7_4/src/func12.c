#include "array7_4.h" 
array_t* func12(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array34 = func13(&params0, loopsFactor);
      DEBUG_RETURN(array34->id);
      free(params0.data);
      array34->refC--;
      if(array34->refC == 0) {
         free(array34->data);
         free(array34);
         DEBUG_FREE(array34->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array36 = func14(&params0, loopsFactor);
      DEBUG_RETURN(array36->id);
      free(params0.data);
      array36->refC--;
      if(array36->refC == 0) {
         free(array36->data);
         free(array36);
         DEBUG_FREE(array36->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array38 = func15(&params0, loopsFactor);
   DEBUG_RETURN(array38->id);
   free(params0.data);
   return array38;
}

