#include "array9_1.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array4 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array4->id);
      free(params0.data);
      array4->refC--;
      if(array4->refC == 0) {
         free(array4->data);
         free(array4);
         DEBUG_FREE(array4->id);
      }
   }
   array_t* array18;
   if (pCounter > 0) {
      array18 = vars->data[--pCounter];
      array18->refC++;
      DEBUG_COPY(array18->id);
   } else {
      array18 = (array_t*)malloc(sizeof(array_t));
      array18->size = 170;
      array18->refC = 1;
      array18->id = 18;
      array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
      memset(array18->data, 0, array18->size*sizeof(unsigned int));
      DEBUG_NEW(array18->id);
   }
   return array18;
}

