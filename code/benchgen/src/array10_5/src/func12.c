#include "array10_5.h" 
array_t* func12(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array13 = func13(&params0, loopsFactor);
      DEBUG_RETURN(array13->id);
      free(params0.data);
      array13->refC--;
      if(array13->refC == 0) {
         free(array13->data);
         free(array13);
         DEBUG_FREE(array13->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array15 = func14(&params0, loopsFactor);
      DEBUG_RETURN(array15->id);
      free(params0.data);
      array15->refC--;
      if(array15->refC == 0) {
         free(array15->data);
         free(array15);
         DEBUG_FREE(array15->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array17 = func15(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(array17->id);
   free(params0.data);
   return array17;
}

