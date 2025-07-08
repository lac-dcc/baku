#include "array8_8.h" 
array_t* func18(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array35 = func19(&params0, loopsFactor);
      DEBUG_RETURN(array35->id);
      free(params0.data);
      array35->refC--;
      if(array35->refC == 0) {
         free(array35->data);
         free(array35);
         DEBUG_FREE(array35->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array38 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array38->id);
      free(params0.data);
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
   }
   array_t* array40;
   if (pCounter > 0) {
      array40 = vars->data[--pCounter];
      array40->refC++;
      DEBUG_COPY(array40->id);
   } else {
      array40 = (array_t*)malloc(sizeof(array_t));
      array40->size = 481;
      array40->refC = 1;
      array40->id = 40;
      array40->data = (unsigned int*)malloc(array40->size*sizeof(unsigned int));
      memset(array40->data, 0, array40->size*sizeof(unsigned int));
      DEBUG_NEW(array40->id);
   }
   return array40;
}

