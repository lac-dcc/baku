#include "array10_10.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array13;
   if (pCounter > 0) {
      array13 = vars->data[--pCounter];
      array13->refC++;
      DEBUG_COPY(array13->id);
   } else {
      array13 = (array_t*)malloc(sizeof(array_t));
      array13->size = 69;
      array13->refC = 1;
      array13->id = 13;
      array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
      memset(array13->data, 0, array13->size*sizeof(unsigned int));
      DEBUG_NEW(array13->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/10 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      for (int i = 0; i < array13->size; i++) {
         array13->data[i]++;
      }
      unsigned int loop10 = 0;
      unsigned int loopLimit10 = (rand()%loopsFactor)/11 + 1;
      for(; loop10 < loopLimit10; loop10++) {
         array_t* array14;
         if (pCounter > 0) {
            array14 = vars->data[--pCounter];
            array14->refC++;
            DEBUG_COPY(array14->id);
         } else {
            array14 = (array_t*)malloc(sizeof(array_t));
            array14->size = 393;
            array14->refC = 1;
            array14->id = 14;
            array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
            memset(array14->data, 0, array14->size*sizeof(unsigned int));
            DEBUG_NEW(array14->id);
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array13;
         params0.data[1] = array14;
         array_t* array15 = func5(&params0, loopsFactor);
         DEBUG_RETURN(array15->id);
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
      }
   }
   return array13;
}

