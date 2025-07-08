#include "array5_8.h" 
array_t* func10(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array23 = func11(&params0, loopsFactor);
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
      array_t* array26 = func12(&params0, loopsFactor);
      DEBUG_RETURN(array26->id);
      free(params0.data);
      array26->refC--;
      if(array26->refC == 0) {
         free(array26->data);
         free(array26);
         DEBUG_FREE(array26->id);
      }
   }
   array_t* array28;
   if (pCounter > 0) {
      array28 = vars->data[--pCounter];
      array28->refC++;
      DEBUG_COPY(array28->id);
   } else {
      array28 = (array_t*)malloc(sizeof(array_t));
      array28->size = 399;
      array28->refC = 1;
      array28->id = 28;
      array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
      memset(array28->data, 0, array28->size*sizeof(unsigned int));
      DEBUG_NEW(array28->id);
   }
   return array28;
}

