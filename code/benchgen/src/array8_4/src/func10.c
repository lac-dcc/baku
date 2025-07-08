#include "array8_4.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      array_t* array39;
      if (pCounter > 0) {
         array39 = vars->data[--pCounter];
         array39->refC++;
         DEBUG_COPY(array39->id);
      } else {
         array39 = (array_t*)malloc(sizeof(array_t));
         array39->size = 729;
         array39->refC = 1;
         array39->id = 39;
         array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
         memset(array39->data, 0, array39->size*sizeof(unsigned int));
         DEBUG_NEW(array39->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array39;
      array_t* array40 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array40->id);
      free(params0.data);
      array40->refC--;
      if(array40->refC == 0) {
         free(array40->data);
         free(array40);
         DEBUG_FREE(array40->id);
      }
      array39->refC--;
      if(array39->refC == 0) {
         free(array39->data);
         free(array39);
         DEBUG_FREE(array39->id);
      }
   }
   array_t* array59;
   if (pCounter > 0) {
      array59 = vars->data[--pCounter];
      array59->refC++;
      DEBUG_COPY(array59->id);
   } else {
      array59 = (array_t*)malloc(sizeof(array_t));
      array59->size = 551;
      array59->refC = 1;
      array59->id = 59;
      array59->data = (unsigned int*)malloc(array59->size*sizeof(unsigned int));
      memset(array59->data, 0, array59->size*sizeof(unsigned int));
      DEBUG_NEW(array59->id);
   }
   return array59;
}

