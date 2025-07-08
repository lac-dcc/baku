#include "array10_2.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t* array52;
      if (pCounter > 0) {
         array52 = vars->data[--pCounter];
         array52->refC++;
         DEBUG_COPY(array52->id);
      } else {
         array52 = (array_t*)malloc(sizeof(array_t));
         array52->size = 846;
         array52->refC = 1;
         array52->id = 52;
         array52->data = (unsigned int*)malloc(array52->size*sizeof(unsigned int));
         memset(array52->data, 0, array52->size*sizeof(unsigned int));
         DEBUG_NEW(array52->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array52;
      array_t* array53 = func20(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array53->id);
      free(params0.data);
      for (int i = 0; i < array53->size; i++) {
         array53->data[i]++;
      }
      array53->refC--;
      if(array53->refC == 0) {
         free(array53->data);
         free(array53);
         DEBUG_FREE(array53->id);
      }
      array52->refC--;
      if(array52->refC == 0) {
         free(array52->data);
         free(array52);
         DEBUG_FREE(array52->id);
      }
   }
   array_t* array67;
   if (pCounter > 0) {
      array67 = vars->data[--pCounter];
      array67->refC++;
      DEBUG_COPY(array67->id);
   } else {
      array67 = (array_t*)malloc(sizeof(array_t));
      array67->size = 11;
      array67->refC = 1;
      array67->id = 67;
      array67->data = (unsigned int*)malloc(array67->size*sizeof(unsigned int));
      memset(array67->data, 0, array67->size*sizeof(unsigned int));
      DEBUG_NEW(array67->id);
   }
   return array67;
}

