#include "array8_4.h" 
array_t* func25(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array55;
   if (pCounter > 0) {
      array55 = vars->data[--pCounter];
      array55->refC++;
      DEBUG_COPY(array55->id);
   } else {
      array55 = (array_t*)malloc(sizeof(array_t));
      array55->size = 34;
      array55->refC = 1;
      array55->id = 55;
      array55->data = (unsigned int*)malloc(array55->size*sizeof(unsigned int));
      memset(array55->data, 0, array55->size*sizeof(unsigned int));
      DEBUG_NEW(array55->id);
   }
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/6 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array55;
      array_t* array56 = func30(&params0, loopsFactor);
      DEBUG_RETURN(array56->id);
      free(params0.data);
      array56->refC--;
      if(array56->refC == 0) {
         free(array56->data);
         free(array56);
         DEBUG_FREE(array56->id);
      }
   }
   return array55;
}

