#include "array8_4.h" 
array_t* func22(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array50 = func23(&params0, loopsFactor);
      DEBUG_RETURN(array50->id);
      free(params0.data);
      array50->refC--;
      if(array50->refC == 0) {
         free(array50->data);
         free(array50);
         DEBUG_FREE(array50->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array52 = func24(&params0, loopsFactor);
      DEBUG_RETURN(array52->id);
      free(params0.data);
      array52->refC--;
      if(array52->refC == 0) {
         free(array52->data);
         free(array52);
         DEBUG_FREE(array52->id);
      }
   }
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array54 = func25(&params0, loopsFactor);
   DEBUG_RETURN(array54->id);
   free(params0.data);
   return array54;
}

