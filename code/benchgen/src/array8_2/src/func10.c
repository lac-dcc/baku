#include "array8_2.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      array_t* array40;
      if (pCounter > 0) {
         array40 = vars->data[--pCounter];
         array40->refC++;
         DEBUG_COPY(array40->id);
      } else {
         array40 = (array_t*)malloc(sizeof(array_t));
         array40->size = 729;
         array40->refC = 1;
         array40->id = 40;
         array40->data = (unsigned int*)malloc(array40->size*sizeof(unsigned int));
         memset(array40->data, 0, array40->size*sizeof(unsigned int));
         DEBUG_NEW(array40->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array40;
      array_t* array41 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array41->id);
      free(params0.data);
      for (int i = 0; i < array40->size; i++) {
         array40->data[i]++;
      }
      array41->refC--;
      if(array41->refC == 0) {
         free(array41->data);
         free(array41);
         DEBUG_FREE(array41->id);
      }
      array40->refC--;
      if(array40->refC == 0) {
         free(array40->data);
         free(array40);
         DEBUG_FREE(array40->id);
      }
   }
   array_t* array55;
   if (pCounter > 0) {
      array55 = vars->data[--pCounter];
      array55->refC++;
      DEBUG_COPY(array55->id);
   } else {
      array55 = (array_t*)malloc(sizeof(array_t));
      array55->size = 764;
      array55->refC = 1;
      array55->id = 55;
      array55->data = (unsigned int*)malloc(array55->size*sizeof(unsigned int));
      memset(array55->data, 0, array55->size*sizeof(unsigned int));
      DEBUG_NEW(array55->id);
   }
   return array55;
}

