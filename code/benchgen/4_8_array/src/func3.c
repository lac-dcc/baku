#include "outs/4_8_array.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array68;
   if (pCounter > 0) {
      array68 = vars->data[--pCounter];
      array68->refC++;
      DEBUG_COPY(array68->id);
   } else {
      array68 = (array_t*)malloc(sizeof(array_t));
      array68->size = 669;
      array68->refC = 1;
      array68->id = 68;
      array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
      memset(array68->data, 0, array68->size*sizeof(unsigned int));
      DEBUG_NEW(array68->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array68;
   array_t* array69 = func6(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array69->id);
   free(params0.data);
   unsigned int loop20 = 0;
   unsigned int loopLimit20 = (rand()%loopsFactor)/2 + 1;
   for(; loop20 < loopLimit20; loop20++) {
      for (int i = 0; i < array68->size; i++) {
         array68->data[i]++;
      }
   }
   for (int i = 0; i < array69->size; i++) {
      if (array69->data[i] == 7) { 
         return array69;
      }
   }
   array68->refC--;
   if(array68->refC == 0) {
      free(array68->data);
      free(array68);
      DEBUG_FREE(array68->id);
   }
   return array69;
}

