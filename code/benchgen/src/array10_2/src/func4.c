#include "array10_2.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/1 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      array_t* array42;
      if (pCounter > 0) {
         array42 = vars->data[--pCounter];
         array42->refC++;
         DEBUG_COPY(array42->id);
      } else {
         array42 = (array_t*)malloc(sizeof(array_t));
         array42->size = 481;
         array42->refC = 1;
         array42->id = 42;
         array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
         memset(array42->data, 0, array42->size*sizeof(unsigned int));
         DEBUG_NEW(array42->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array42;
      array_t* array43 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array43->id);
      free(params0.data);
      for (int i = 0; i < array42->size; i++) {
         array42->data[i]++;
      }
      array43->refC--;
      if(array43->refC == 0) {
         free(array43->data);
         free(array43);
         DEBUG_FREE(array43->id);
      }
      array42->refC--;
      if(array42->refC == 0) {
         free(array42->data);
         free(array42);
         DEBUG_FREE(array42->id);
      }
   }
   array_t* array71;
   if (pCounter > 0) {
      array71 = vars->data[--pCounter];
      array71->refC++;
      DEBUG_COPY(array71->id);
   } else {
      array71 = (array_t*)malloc(sizeof(array_t));
      array71->size = 840;
      array71->refC = 1;
      array71->id = 71;
      array71->data = (unsigned int*)malloc(array71->size*sizeof(unsigned int));
      memset(array71->data, 0, array71->size*sizeof(unsigned int));
      DEBUG_NEW(array71->id);
   }
   return array71;
}

