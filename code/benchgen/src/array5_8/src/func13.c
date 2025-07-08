#include "array5_8.h" 
array_t* func13(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array7 = func14(&params0, loopsFactor);
      DEBUG_RETURN(array7->id);
      free(params0.data);
      array7->refC--;
      if(array7->refC == 0) {
         free(array7->data);
         free(array7);
         DEBUG_FREE(array7->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array9 = func15(&params0, loopsFactor);
      DEBUG_RETURN(array9->id);
      free(params0.data);
      array9->refC--;
      if(array9->refC == 0) {
         free(array9->data);
         free(array9);
         DEBUG_FREE(array9->id);
      }
   }
   array_t* array11;
   if (pCounter > 0) {
      array11 = vars->data[--pCounter];
      array11->refC++;
      DEBUG_COPY(array11->id);
   } else {
      array11 = (array_t*)malloc(sizeof(array_t));
      array11->size = 393;
      array11->refC = 1;
      array11->id = 11;
      array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
      memset(array11->data, 0, array11->size*sizeof(unsigned int));
      DEBUG_NEW(array11->id);
   }
   return array11;
}

