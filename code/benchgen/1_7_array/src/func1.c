#include "outs/1_7_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array7;
   if (pCounter > 0) {
      array7 = vars->data[--pCounter];
      array7->refC++;
      DEBUG_COPY(array7->id);
   } else {
      array7 = (array_t*)malloc(sizeof(array_t));
      array7->size = 211;
      array7->refC = 1;
      array7->id = 7;
      array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
      memset(array7->data, 0, array7->size*sizeof(unsigned int));
      DEBUG_NEW(array7->id);
   }
   array_t* array8;
   if (pCounter > 0) {
      array8 = vars->data[--pCounter];
      array8->refC++;
      DEBUG_COPY(array8->id);
   } else {
      array8 = (array_t*)malloc(sizeof(array_t));
      array8->size = 368;
      array8->refC = 1;
      array8->id = 8;
      array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
      memset(array8->data, 0, array8->size*sizeof(unsigned int));
      DEBUG_NEW(array8->id);
   }
   for (int i = 0; i < array8->size; i++) {
      array8->data[i]++;
   }
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/1 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      for (int i = 0; i < array8->size; i++) {
         array8->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array7;
   params0.data[1] = array8;
   array_t* array9 = func3(&params0, loopsFactor);
   DEBUG_RETURN(array9->id);
   free(params0.data);
   array8->refC--;
   if(array8->refC == 0) {
      free(array8->data);
      free(array8);
      DEBUG_FREE(array8->id);
   }
   array7->refC--;
   if(array7->refC == 0) {
      free(array7->data);
      free(array7);
      DEBUG_FREE(array7->id);
   }
   return array9;
}

