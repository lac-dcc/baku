#include "array10_4.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/3 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      array_t* array42;
      if (pCounter > 0) {
         array42 = vars->data[--pCounter];
         array42->refC++;
         DEBUG_COPY(array42->id);
      } else {
         array42 = (array_t*)malloc(sizeof(array_t));
         array42->size = 709;
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
      array_t* array43 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array43->id);
      free(params0.data);
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
   array_t* array70;
   if (pCounter > 0) {
      array70 = vars->data[--pCounter];
      array70->refC++;
      DEBUG_COPY(array70->id);
   } else {
      array70 = (array_t*)malloc(sizeof(array_t));
      array70->size = 369;
      array70->refC = 1;
      array70->id = 70;
      array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
      memset(array70->data, 0, array70->size*sizeof(unsigned int));
      DEBUG_NEW(array70->id);
   }
   return array70;
}

