#include "outs/5_8_array.h" 
array_t* func21(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array53;
   if (pCounter > 0) {
      array53 = vars->data[--pCounter];
      array53->refC++;
      DEBUG_COPY(array53->id);
   } else {
      array53 = (array_t*)malloc(sizeof(array_t));
      array53->size = 275;
      array53->refC = 1;
      array53->id = 53;
      array53->data = (unsigned int*)malloc(array53->size*sizeof(unsigned int));
      memset(array53->data, 0, array53->size*sizeof(unsigned int));
      DEBUG_NEW(array53->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array53;
   array_t* array54 = func23(&params0, loopsFactor);
   DEBUG_RETURN(array54->id);
   free(params0.data);
   array53->refC--;
   if(array53->refC == 0) {
      free(array53->data);
      free(array53);
      DEBUG_FREE(array53->id);
   }
   return array54;
}

