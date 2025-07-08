#include "array6_4.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t* array31;
      if (pCounter > 0) {
         array31 = vars->data[--pCounter];
         array31->refC++;
         DEBUG_COPY(array31->id);
      } else {
         array31 = (array_t*)malloc(sizeof(array_t));
         array31->size = 586;
         array31->refC = 1;
         array31->id = 31;
         array31->data = (unsigned int*)malloc(array31->size*sizeof(unsigned int));
         memset(array31->data, 0, array31->size*sizeof(unsigned int));
         DEBUG_NEW(array31->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array31;
      array_t* array32 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array32->id);
      free(params0.data);
      array32->refC--;
      if(array32->refC == 0) {
         free(array32->data);
         free(array32);
         DEBUG_FREE(array32->id);
      }
      array31->refC--;
      if(array31->refC == 0) {
         free(array31->data);
         free(array31);
         DEBUG_FREE(array31->id);
      }
   }
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
   return array42;
}

