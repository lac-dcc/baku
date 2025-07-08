#include "array9_4.h" 
array_t* func26(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array21 = func27(&params0, loopsFactor);
      DEBUG_RETURN(array21->id);
      free(params0.data);
      array21->refC--;
      if(array21->refC == 0) {
         free(array21->data);
         free(array21);
         DEBUG_FREE(array21->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array23 = func28(&params0, loopsFactor);
      DEBUG_RETURN(array23->id);
      free(params0.data);
      array23->refC--;
      if(array23->refC == 0) {
         free(array23->data);
         free(array23);
         DEBUG_FREE(array23->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array25 = func29(&params0, loopsFactor);
   DEBUG_RETURN(array25->id);
   free(params0.data);
   return array25;
}

