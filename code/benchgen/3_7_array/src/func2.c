#include "outs/3_7_array.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array19;
   if (pCounter > 0) {
      array19 = vars->data[--pCounter];
      array19->refC++;
      DEBUG_COPY(array19->id);
   } else {
      array19 = (array_t*)malloc(sizeof(array_t));
      array19->size = 980;
      array19->refC = 1;
      array19->id = 19;
      array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
      memset(array19->data, 0, array19->size*sizeof(unsigned int));
      DEBUG_NEW(array19->id);
   }
   for (int i = 0; i < array19->size; i++) {
      if (array19->data[i] == 73) { 
         return array19;
      }
   }
   array_t* array20;
   if (pCounter > 0) {
      array20 = vars->data[--pCounter];
      array20->refC++;
      DEBUG_COPY(array20->id);
   } else {
      array20 = (array_t*)malloc(sizeof(array_t));
      array20->size = 862;
      array20->refC = 1;
      array20->id = 20;
      array20->data = (unsigned int*)malloc(array20->size*sizeof(unsigned int));
      memset(array20->data, 0, array20->size*sizeof(unsigned int));
      DEBUG_NEW(array20->id);
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array19;
   params0.data[1] = array20;
   array_t* array21 = func5(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array21->id);
   free(params0.data);
   array21->refC--;
   if(array21->refC == 0) {
      free(array21->data);
      free(array21);
      DEBUG_FREE(array21->id);
   }
   array20->refC--;
   if(array20->refC == 0) {
      free(array20->data);
      free(array20);
      DEBUG_FREE(array20->id);
   }
   return array19;
}

