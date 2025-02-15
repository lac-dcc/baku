#include "outs/2_8_array.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array22;
   if (pCounter > 0) {
      array22 = vars->data[--pCounter];
      array22->refC++;
      DEBUG_COPY(array22->id);
   } else {
      array22 = (array_t*)malloc(sizeof(array_t));
      array22->size = 808;
      array22->refC = 1;
      array22->id = 22;
      array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
      memset(array22->data, 0, array22->size*sizeof(unsigned int));
      DEBUG_NEW(array22->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array22;
   array_t* array23 = func6(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array23->id);
   free(params0.data);
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      for (int i = 0; i < array22->size; i++) {
         array22->data[i]++;
      }
   }
   for (int i = 0; i < array22->size; i++) {
      if (array22->data[i] == 3) { 
         return array22;
      }
   }
   array22->refC--;
   if(array22->refC == 0) {
      free(array22->data);
      free(array22);
      DEBUG_FREE(array22->id);
   }
   return array23;
}

