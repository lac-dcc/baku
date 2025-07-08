#include "array6_4.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array38;
   if (pCounter > 0) {
      array38 = vars->data[--pCounter];
      array38->refC++;
      DEBUG_COPY(array38->id);
   } else {
      array38 = (array_t*)malloc(sizeof(array_t));
      array38->size = 444;
      array38->refC = 1;
      array38->id = 38;
      array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
      memset(array38->data, 0, array38->size*sizeof(unsigned int));
      DEBUG_NEW(array38->id);
   }
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/4 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array38;
      array_t* array39 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array39->id);
      free(params0.data);
      array39->refC--;
      if(array39->refC == 0) {
         free(array39->data);
         free(array39);
         DEBUG_FREE(array39->id);
      }
   }
   return array38;
}

