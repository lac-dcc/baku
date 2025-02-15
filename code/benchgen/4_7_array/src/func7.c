#include "outs/4_7_array.h" 
array_t* func7(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array19;
   if (pCounter > 0) {
      array19 = vars->data[--pCounter];
      array19->refC++;
      DEBUG_COPY(array19->id);
   } else {
      array19 = (array_t*)malloc(sizeof(array_t));
      array19->size = 315;
      array19->refC = 1;
      array19->id = 19;
      array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
      memset(array19->data, 0, array19->size*sizeof(unsigned int));
      DEBUG_NEW(array19->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array19;
   array_t* array20 = func11(&params0, loopsFactor);
   DEBUG_RETURN(array20->id);
   free(params0.data);
   array19->refC--;
   if(array19->refC == 0) {
      free(array19->data);
      free(array19);
      DEBUG_FREE(array19->id);
   }
   return array20;
}

