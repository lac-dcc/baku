#include "array9_2.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array38 = func9(&params0, loopsFactor);
      DEBUG_RETURN(array38->id);
      free(params0.data);
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array40 = func10(&params0, loopsFactor);
      DEBUG_RETURN(array40->id);
      free(params0.data);
      array40->refC--;
      if(array40->refC == 0) {
         free(array40->data);
         free(array40);
         DEBUG_FREE(array40->id);
      }
   }
   array_t* array63;
   if (pCounter > 0) {
      array63 = vars->data[--pCounter];
      array63->refC++;
      DEBUG_COPY(array63->id);
   } else {
      array63 = (array_t*)malloc(sizeof(array_t));
      array63->size = 275;
      array63->refC = 1;
      array63->id = 63;
      array63->data = (unsigned int*)malloc(array63->size*sizeof(unsigned int));
      memset(array63->data, 0, array63->size*sizeof(unsigned int));
      DEBUG_NEW(array63->id);
   }
   return array63;
}

