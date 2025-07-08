#include "array7_2.h" 
array_t* func7(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      array_t* array6;
      if (pCounter > 0) {
         array6 = vars->data[--pCounter];
         array6->refC++;
         DEBUG_COPY(array6->id);
      } else {
         array6 = (array_t*)malloc(sizeof(array_t));
         array6->size = 368;
         array6->refC = 1;
         array6->id = 6;
         array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
         memset(array6->data, 0, array6->size*sizeof(unsigned int));
         DEBUG_NEW(array6->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array6;
      array_t* array7 = func11(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array7->id);
      free(params0.data);
      for (int i = 0; i < array7->size; i++) {
         array7->data[i]++;
      }
      array7->refC--;
      if(array7->refC == 0) {
         free(array7->data);
         free(array7);
         DEBUG_FREE(array7->id);
      }
      array6->refC--;
      if(array6->refC == 0) {
         free(array6->data);
         free(array6);
         DEBUG_FREE(array6->id);
      }
   }
   array_t* array21;
   if (pCounter > 0) {
      array21 = vars->data[--pCounter];
      array21->refC++;
      DEBUG_COPY(array21->id);
   } else {
      array21 = (array_t*)malloc(sizeof(array_t));
      array21->size = 84;
      array21->refC = 1;
      array21->id = 21;
      array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
      memset(array21->data, 0, array21->size*sizeof(unsigned int));
      DEBUG_NEW(array21->id);
   }
   return array21;
}

