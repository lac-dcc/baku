#include "outs/2_7_array.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array14;
   if (pCounter > 0) {
      array14 = vars->data[--pCounter];
      array14->refC++;
      DEBUG_COPY(array14->id);
   } else {
      array14 = (array_t*)malloc(sizeof(array_t));
      array14->size = 42;
      array14->refC = 1;
      array14->id = 14;
      array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
      memset(array14->data, 0, array14->size*sizeof(unsigned int));
      DEBUG_NEW(array14->id);
   }
   array_t* array15;
   if (pCounter > 0) {
      array15 = vars->data[--pCounter];
      array15->refC++;
      DEBUG_COPY(array15->id);
   } else {
      array15 = (array_t*)malloc(sizeof(array_t));
      array15->size = 229;
      array15->refC = 1;
      array15->id = 15;
      array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
      memset(array15->data, 0, array15->size*sizeof(unsigned int));
      DEBUG_NEW(array15->id);
   }
   for (int i = 0; i < array15->size; i++) {
      array15->data[i]++;
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/1 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      for (int i = 0; i < array15->size; i++) {
         array15->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array14;
   params0.data[1] = array15;
   array_t* array16 = func3(&params0, loopsFactor);
   DEBUG_RETURN(array16->id);
   free(params0.data);
   array15->refC--;
   if(array15->refC == 0) {
      free(array15->data);
      free(array15);
      DEBUG_FREE(array15->id);
   }
   array14->refC--;
   if(array14->refC == 0) {
      free(array14->data);
      free(array14);
      DEBUG_FREE(array14->id);
   }
   return array16;
}

