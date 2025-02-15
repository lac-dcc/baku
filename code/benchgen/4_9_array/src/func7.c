#include "outs/4_9_array.h" 
array_t* func7(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array43;
   if (pCounter > 0) {
      array43 = vars->data[--pCounter];
      array43->refC++;
      DEBUG_COPY(array43->id);
   } else {
      array43 = (array_t*)malloc(sizeof(array_t));
      array43->size = 228;
      array43->refC = 1;
      array43->id = 43;
      array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
      memset(array43->data, 0, array43->size*sizeof(unsigned int));
      DEBUG_NEW(array43->id);
   }
   unsigned int loop19 = 0;
   unsigned int loopLimit19 = (rand()%loopsFactor)/2 + 1;
   for(; loop19 < loopLimit19; loop19++) {
      for (int i = 0; i < array43->size; i++) {
         array43->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array43;
   array_t* array44 = func13(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array44->id);
   free(params0.data);
   unsigned int loop20 = 0;
   unsigned int loopLimit20 = (rand()%loopsFactor)/2 + 1;
   for(; loop20 < loopLimit20; loop20++) {
      for (int i = 0; i < array43->size; i++) {
         array43->data[i]++;
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array43;
   params1.data[1] = array44;
   array_t* array45 = func10(&params1, loopsFactor);
   DEBUG_RETURN(array45->id);
   free(params1.data);
   for (int i = 0; i < array43->size; i++) {
      if (array43->data[i] == 14) { 
         return array43;
      }
   }
   array44->refC--;
   if(array44->refC == 0) {
      free(array44->data);
      free(array44);
      DEBUG_FREE(array44->id);
   }
   array43->refC--;
   if(array43->refC == 0) {
      free(array43->data);
      free(array43);
      DEBUG_FREE(array43->id);
   }
   return array45;
}

