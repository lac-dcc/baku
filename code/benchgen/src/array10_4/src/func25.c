#include "array10_4.h" 
array_t* func25(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array58;
   if (pCounter > 0) {
      array58 = vars->data[--pCounter];
      array58->refC++;
      DEBUG_COPY(array58->id);
   } else {
      array58 = (array_t*)malloc(sizeof(array_t));
      array58->size = 491;
      array58->refC = 1;
      array58->id = 58;
      array58->data = (unsigned int*)malloc(array58->size*sizeof(unsigned int));
      memset(array58->data, 0, array58->size*sizeof(unsigned int));
      DEBUG_NEW(array58->id);
   }
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/6 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array58;
      array_t* array59 = func30(&params0, loopsFactor);
      DEBUG_RETURN(array59->id);
      free(params0.data);
      array59->refC--;
      if(array59->refC == 0) {
         free(array59->data);
         free(array59);
         DEBUG_FREE(array59->id);
      }
   }
   return array58;
}

