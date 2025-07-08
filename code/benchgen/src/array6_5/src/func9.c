#include "array6_5.h" 
array_t* func9(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array8 = func10(&params0, loopsFactor);
      DEBUG_RETURN(array8->id);
      free(params0.data);
      array8->refC--;
      if(array8->refC == 0) {
         free(array8->data);
         free(array8);
         DEBUG_FREE(array8->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array10 = func11(&params0, loopsFactor);
      DEBUG_RETURN(array10->id);
      free(params0.data);
      array10->refC--;
      if(array10->refC == 0) {
         free(array10->data);
         free(array10);
         DEBUG_FREE(array10->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array12 = func12(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(array12->id);
   free(params0.data);
   return array12;
}

