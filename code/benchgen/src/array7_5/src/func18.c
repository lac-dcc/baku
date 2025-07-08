#include "array7_5.h" 
array_t* func18(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array23 = func19(&params0, loopsFactor);
      DEBUG_RETURN(array23->id);
      free(params0.data);
      array23->refC--;
      if(array23->refC == 0) {
         free(array23->data);
         free(array23);
         DEBUG_FREE(array23->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array25 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array25->id);
      free(params0.data);
      array25->refC--;
      if(array25->refC == 0) {
         free(array25->data);
         free(array25);
         DEBUG_FREE(array25->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array27 = func21(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(array27->id);
   free(params0.data);
   return array27;
}

