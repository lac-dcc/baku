#include "array10_2.h" 
array_t* func26(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array59 = func27(&params0, loopsFactor);
      DEBUG_RETURN(array59->id);
      free(params0.data);
      array59->refC--;
      if(array59->refC == 0) {
         free(array59->data);
         free(array59);
         DEBUG_FREE(array59->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array61 = func28(&params0, loopsFactor);
      DEBUG_RETURN(array61->id);
      free(params0.data);
      array61->refC--;
      if(array61->refC == 0) {
         free(array61->data);
         free(array61);
         DEBUG_FREE(array61->id);
      }
   }
   array_t* array64;
   if (pCounter > 0) {
      array64 = vars->data[--pCounter];
      array64->refC++;
      DEBUG_COPY(array64->id);
   } else {
      array64 = (array_t*)malloc(sizeof(array_t));
      array64->size = 395;
      array64->refC = 1;
      array64->id = 64;
      array64->data = (unsigned int*)malloc(array64->size*sizeof(unsigned int));
      memset(array64->data, 0, array64->size*sizeof(unsigned int));
      DEBUG_NEW(array64->id);
   }
   return array64;
}

