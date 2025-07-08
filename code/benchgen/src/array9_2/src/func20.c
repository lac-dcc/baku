#include "array9_2.h" 
array_t* func20(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array48 = func21(&params0, loopsFactor);
      DEBUG_RETURN(array48->id);
      free(params0.data);
      array48->refC--;
      if(array48->refC == 0) {
         free(array48->data);
         free(array48);
         DEBUG_FREE(array48->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array50 = func22(&params0, loopsFactor);
      DEBUG_RETURN(array50->id);
      free(params0.data);
      array50->refC--;
      if(array50->refC == 0) {
         free(array50->data);
         free(array50);
         DEBUG_FREE(array50->id);
      }
   }
   array_t* array59;
   if (pCounter > 0) {
      array59 = vars->data[--pCounter];
      array59->refC++;
      DEBUG_COPY(array59->id);
   } else {
      array59 = (array_t*)malloc(sizeof(array_t));
      array59->size = 743;
      array59->refC = 1;
      array59->id = 59;
      array59->data = (unsigned int*)malloc(array59->size*sizeof(unsigned int));
      memset(array59->data, 0, array59->size*sizeof(unsigned int));
      DEBUG_NEW(array59->id);
   }
   return array59;
}

