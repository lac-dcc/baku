#include "outs/4_7_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array60;
   if (pCounter > 0) {
      array60 = vars->data[--pCounter];
      array60->refC++;
      DEBUG_COPY(array60->id);
   } else {
      array60 = (array_t*)malloc(sizeof(array_t));
      array60->size = 715;
      array60->refC = 1;
      array60->id = 60;
      array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
      memset(array60->data, 0, array60->size*sizeof(unsigned int));
      DEBUG_NEW(array60->id);
   }
   array_t* array61;
   if (pCounter > 0) {
      array61 = vars->data[--pCounter];
      array61->refC++;
      DEBUG_COPY(array61->id);
   } else {
      array61 = (array_t*)malloc(sizeof(array_t));
      array61->size = 340;
      array61->refC = 1;
      array61->id = 61;
      array61->data = (unsigned int*)malloc(array61->size*sizeof(unsigned int));
      memset(array61->data, 0, array61->size*sizeof(unsigned int));
      DEBUG_NEW(array61->id);
   }
   for (int i = 0; i < array61->size; i++) {
      array61->data[i]++;
   }
   unsigned int loop14 = 0;
   unsigned int loopLimit14 = (rand()%loopsFactor)/1 + 1;
   for(; loop14 < loopLimit14; loop14++) {
      for (int i = 0; i < array60->size; i++) {
         array60->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array60;
   params0.data[1] = array61;
   array_t* array62 = func3(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array62->id);
   free(params0.data);
   array62->refC--;
   if(array62->refC == 0) {
      free(array62->data);
      free(array62);
      DEBUG_FREE(array62->id);
   }
   array60->refC--;
   if(array60->refC == 0) {
      free(array60->data);
      free(array60);
      DEBUG_FREE(array60->id);
   }
   return array61;
}

