#include "array10_4.h" 
array_t* func30(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop14 = 0;
   unsigned int loopLimit14 = (rand()%loopsFactor)/7 + 1;
   for(; loop14 < loopLimit14; loop14++) {
      array_t* array60;
      if (pCounter > 0) {
         array60 = vars->data[--pCounter];
         array60->refC++;
         DEBUG_COPY(array60->id);
      } else {
         array60 = (array_t*)malloc(sizeof(array_t));
         array60->size = 432;
         array60->refC = 1;
         array60->id = 60;
         array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
         memset(array60->data, 0, array60->size*sizeof(unsigned int));
         DEBUG_NEW(array60->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array60;
      array_t* array61 = func32(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array61->id);
      free(params0.data);
      array61->refC--;
      if(array61->refC == 0) {
         free(array61->data);
         free(array61);
         DEBUG_FREE(array61->id);
      }
      array60->refC--;
      if(array60->refC == 0) {
         free(array60->data);
         free(array60);
         DEBUG_FREE(array60->id);
      }
   }
   array_t* array68;
   if (pCounter > 0) {
      array68 = vars->data[--pCounter];
      array68->refC++;
      DEBUG_COPY(array68->id);
   } else {
      array68 = (array_t*)malloc(sizeof(array_t));
      array68->size = 613;
      array68->refC = 1;
      array68->id = 68;
      array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
      memset(array68->data, 0, array68->size*sizeof(unsigned int));
      DEBUG_NEW(array68->id);
   }
   return array68;
}

