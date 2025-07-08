#include "array7_4.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array3 = func7(&params0, loopsFactor);
      DEBUG_RETURN(array3->id);
      free(params0.data);
      array3->refC--;
      if(array3->refC == 0) {
         free(array3->data);
         free(array3);
         DEBUG_FREE(array3->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array5 = func8(&params0, loopsFactor);
      DEBUG_RETURN(array5->id);
      free(params0.data);
      array5->refC--;
      if(array5->refC == 0) {
         free(array5->data);
         free(array5);
         DEBUG_FREE(array5->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array7 = func9(&params0, loopsFactor);
   DEBUG_RETURN(array7->id);
   free(params0.data);
   return array7;
}

