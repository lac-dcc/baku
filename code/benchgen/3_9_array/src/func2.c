#include "outs/3_9_array.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array5;
   if (pCounter > 0) {
      array5 = vars->data[--pCounter];
      array5->refC++;
      DEBUG_COPY(array5->id);
   } else {
      array5 = (array_t*)malloc(sizeof(array_t));
      array5->size = 736;
      array5->refC = 1;
      array5->id = 5;
      array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
      memset(array5->data, 0, array5->size*sizeof(unsigned int));
      DEBUG_NEW(array5->id);
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      for (int i = 0; i < array5->size; i++) {
         array5->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array5;
   array_t* array6 = func8(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array6->id);
   free(params0.data);
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      for (int i = 0; i < array6->size; i++) {
         array6->data[i]++;
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array5;
   params1.data[1] = array6;
   array_t* array8 = func5(&params1, loopsFactor);
   DEBUG_RETURN(array8->id);
   free(params1.data);
   for (int i = 0; i < array6->size; i++) {
      if (array6->data[i] == 29) { 
         return array6;
      }
   }
   array8->refC--;
   if(array8->refC == 0) {
      free(array8->data);
      free(array8);
      DEBUG_FREE(array8->id);
   }
   array6->refC--;
   if(array6->refC == 0) {
      free(array6->data);
      free(array6);
      DEBUG_FREE(array6->id);
   }
   return array5;
}

