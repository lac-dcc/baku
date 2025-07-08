#include "array6_9.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array6;
   if (pCounter > 0) {
      array6 = vars->data[--pCounter];
      array6->refC++;
      DEBUG_COPY(array6->id);
   } else {
      array6 = (array_t*)malloc(sizeof(array_t));
      array6->size = 736;
      array6->refC = 1;
      array6->id = 6;
      array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
      memset(array6->data, 0, array6->size*sizeof(unsigned int));
      DEBUG_NEW(array6->id);
   }
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
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
      unsigned int loop5 = 0;
      unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
      for(; loop5 < loopLimit5; loop5++) {
         for (int i = 0; i < array6->size; i++) {
            array6->data[i]--;
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array6;
         params0.data[1] = array7;
         array_t* array8 = func3(&params0, loopsFactor);
         DEBUG_RETURN(array8->id);
         free(params0.data);
         array8->refC--;
         if(array8->refC == 0) {
            free(array8->data);
            free(array8);
            DEBUG_FREE(array8->id);
         }
      }
      array7->refC--;
      if(array7->refC == 0) {
         free(array7->data);
         free(array7);
         DEBUG_FREE(array7->id);
      }
   }
   return array6;
}

