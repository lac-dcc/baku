#include "array8_5.h" 
array_t* func21(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array28 = func22(&params0, loopsFactor);
      DEBUG_RETURN(array28->id);
      free(params0.data);
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array30 = func23(&params0, loopsFactor);
      DEBUG_RETURN(array30->id);
      free(params0.data);
      array30->refC--;
      if(array30->refC == 0) {
         free(array30->data);
         free(array30);
         DEBUG_FREE(array30->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array32 = func24(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(array32->id);
   free(params0.data);
   return array32;
}

