#include "array6_8.h" 
array_t* func8(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/1 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      array_t* array22;
      if (pCounter > 0) {
         array22 = vars->data[--pCounter];
         array22->refC++;
         DEBUG_COPY(array22->id);
      } else {
         array22 = (array_t*)malloc(sizeof(array_t));
         array22->size = 582;
         array22->refC = 1;
         array22->id = 22;
         array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
         memset(array22->data, 0, array22->size*sizeof(unsigned int));
         DEBUG_NEW(array22->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array22;
      array_t* array23 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array23->id);
      free(params0.data);
      array23->refC--;
      if(array23->refC == 0) {
         free(array23->data);
         free(array23);
         DEBUG_FREE(array23->id);
      }
      array22->refC--;
      if(array22->refC == 0) {
         free(array22->data);
         free(array22);
         DEBUG_FREE(array22->id);
      }
   }
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
   return array31;
}

