#include "outs/4_8_array.h" 
array_t* func18(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array27 = func19(&params0, loopsFactor);
      DEBUG_RETURN(array27->id);
      free(params0.data);
      array27->refC--;
      if(array27->refC == 0) {
         free(array27->data);
         free(array27);
         DEBUG_FREE(array27->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array29 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array29->id);
      free(params0.data);
      array29->refC--;
      if(array29->refC == 0) {
         free(array29->data);
         free(array29);
         DEBUG_FREE(array29->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array31 = func21(&params0, loopsFactor);
   DEBUG_RETURN(array31->id);
   free(params0.data);
   return array31;
}

