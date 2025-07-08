#include "array7_4.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array25 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array25->id);
      free(params0.data);
      array25->refC--;
      if(array25->refC == 0) {
         free(array25->data);
         free(array25);
         DEBUG_FREE(array25->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array27 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array27->id);
      free(params0.data);
      array27->refC--;
      if(array27->refC == 0) {
         free(array27->data);
         free(array27);
         DEBUG_FREE(array27->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array29 = func5(&params0, loopsFactor);
   DEBUG_RETURN(array29->id);
   free(params0.data);
   return array29;
}

