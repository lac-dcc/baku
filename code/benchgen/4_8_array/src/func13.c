#include "outs/4_8_array.h" 
array_t* func13(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array12;
   if (pCounter > 0) {
      array12 = vars->data[--pCounter];
      array12->refC++;
      DEBUG_COPY(array12->id);
   } else {
      array12 = (array_t*)malloc(sizeof(array_t));
      array12->size = 784;
      array12->refC = 1;
      array12->id = 12;
      array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
      memset(array12->data, 0, array12->size*sizeof(unsigned int));
      DEBUG_NEW(array12->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array12;
   array_t* array13 = func17(&params0, loopsFactor);
   DEBUG_RETURN(array13->id);
   free(params0.data);
   array13->refC--;
   if(array13->refC == 0) {
      free(array13->data);
      free(array13);
      DEBUG_FREE(array13->id);
   }
   return array12;
}

