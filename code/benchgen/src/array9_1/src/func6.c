#include "array9_1.h" 
array_t* func6(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array10 = func7(&params0, loopsFactor);
      DEBUG_RETURN(array10->id);
      free(params0.data);
      array10->refC--;
      if(array10->refC == 0) {
         free(array10->data);
         free(array10);
         DEBUG_FREE(array10->id);
      }
   }
   array_t* array16;
   if (pCounter > 0) {
      array16 = vars->data[--pCounter];
      array16->refC++;
      DEBUG_COPY(array16->id);
   } else {
      array16 = (array_t*)malloc(sizeof(array_t));
      array16->size = 526;
      array16->refC = 1;
      array16->id = 16;
      array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
      memset(array16->data, 0, array16->size*sizeof(unsigned int));
      DEBUG_NEW(array16->id);
   }
   return array16;
}

