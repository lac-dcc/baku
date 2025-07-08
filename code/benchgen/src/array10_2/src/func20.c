#include "array10_2.h" 
array_t* func20(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array54 = func21(&params0, loopsFactor);
      DEBUG_RETURN(array54->id);
      free(params0.data);
      array54->refC--;
      if(array54->refC == 0) {
         free(array54->data);
         free(array54);
         DEBUG_FREE(array54->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array56 = func22(&params0, loopsFactor);
      DEBUG_RETURN(array56->id);
      free(params0.data);
      array56->refC--;
      if(array56->refC == 0) {
         free(array56->data);
         free(array56);
         DEBUG_FREE(array56->id);
      }
   }
   array_t* array66;
   if (pCounter > 0) {
      array66 = vars->data[--pCounter];
      array66->refC++;
      DEBUG_COPY(array66->id);
   } else {
      array66 = (array_t*)malloc(sizeof(array_t));
      array66->size = 818;
      array66->refC = 1;
      array66->id = 66;
      array66->data = (unsigned int*)malloc(array66->size*sizeof(unsigned int));
      memset(array66->data, 0, array66->size*sizeof(unsigned int));
      DEBUG_NEW(array66->id);
   }
   return array66;
}

