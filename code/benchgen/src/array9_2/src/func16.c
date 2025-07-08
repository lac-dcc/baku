#include "array9_2.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t* array46;
      if (pCounter > 0) {
         array46 = vars->data[--pCounter];
         array46->refC++;
         DEBUG_COPY(array46->id);
      } else {
         array46 = (array_t*)malloc(sizeof(array_t));
         array46->size = 683;
         array46->refC = 1;
         array46->id = 46;
         array46->data = (unsigned int*)malloc(array46->size*sizeof(unsigned int));
         memset(array46->data, 0, array46->size*sizeof(unsigned int));
         DEBUG_NEW(array46->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array46;
      array_t* array47 = func20(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array47->id);
      free(params0.data);
      for (int i = 0; i < array47->size; i++) {
         array47->data[i]++;
      }
      array47->refC--;
      if(array47->refC == 0) {
         free(array47->data);
         free(array47);
         DEBUG_FREE(array47->id);
      }
      array46->refC--;
      if(array46->refC == 0) {
         free(array46->data);
         free(array46);
         DEBUG_FREE(array46->id);
      }
   }
   array_t* array60;
   if (pCounter > 0) {
      array60 = vars->data[--pCounter];
      array60->refC++;
      DEBUG_COPY(array60->id);
   } else {
      array60 = (array_t*)malloc(sizeof(array_t));
      array60->size = 365;
      array60->refC = 1;
      array60->id = 60;
      array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
      memset(array60->data, 0, array60->size*sizeof(unsigned int));
      DEBUG_NEW(array60->id);
   }
   return array60;
}

