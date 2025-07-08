#include "array9_2.h" 
array_t* func14(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array43 = func15(&params0, loopsFactor);
      DEBUG_RETURN(array43->id);
      free(params0.data);
      array43->refC--;
      if(array43->refC == 0) {
         free(array43->data);
         free(array43);
         DEBUG_FREE(array43->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array45 = func16(&params0, loopsFactor);
      DEBUG_RETURN(array45->id);
      free(params0.data);
      array45->refC--;
      if(array45->refC == 0) {
         free(array45->data);
         free(array45);
         DEBUG_FREE(array45->id);
      }
   }
   array_t* array61;
   if (pCounter > 0) {
      array61 = vars->data[--pCounter];
      array61->refC++;
      DEBUG_COPY(array61->id);
   } else {
      array61 = (array_t*)malloc(sizeof(array_t));
      array61->size = 936;
      array61->refC = 1;
      array61->id = 61;
      array61->data = (unsigned int*)malloc(array61->size*sizeof(unsigned int));
      memset(array61->data, 0, array61->size*sizeof(unsigned int));
      DEBUG_NEW(array61->id);
   }
   return array61;
}

