#include "array10_8.h" 
array_t* func8(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
   for(; loop4 < loopLimit4; loop4++) {
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
      array_t* array32 = func10(&params0, get_path(), loopsFactor);
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
   array_t* array54;
   if (pCounter > 0) {
      array54 = vars->data[--pCounter];
      array54->refC++;
      DEBUG_COPY(array54->id);
   } else {
      array54 = (array_t*)malloc(sizeof(array_t));
      array54->size = 841;
      array54->refC = 1;
      array54->id = 54;
      array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
      memset(array54->data, 0, array54->size*sizeof(unsigned int));
      DEBUG_NEW(array54->id);
   }
   return array54;
}

