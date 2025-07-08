#include "array9_4.h" 
array_t* func25(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array57;
   if (pCounter > 0) {
      array57 = vars->data[--pCounter];
      array57->refC++;
      DEBUG_COPY(array57->id);
   } else {
      array57 = (array_t*)malloc(sizeof(array_t));
      array57->size = 743;
      array57->refC = 1;
      array57->id = 57;
      array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
      memset(array57->data, 0, array57->size*sizeof(unsigned int));
      DEBUG_NEW(array57->id);
   }
   unsigned int loop12 = 0;
   unsigned int loopLimit12 = (rand()%loopsFactor)/6 + 1;
   for(; loop12 < loopLimit12; loop12++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array57;
      array_t* array58 = func30(&params0, loopsFactor);
      DEBUG_RETURN(array58->id);
      free(params0.data);
      array58->refC--;
      if(array58->refC == 0) {
         free(array58->data);
         free(array58);
         DEBUG_FREE(array58->id);
      }
   }
   return array57;
}

