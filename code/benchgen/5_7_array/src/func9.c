#include "outs/5_7_array.h" 
array_t* func9(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array21;
   if (pCounter > 0) {
      array21 = vars->data[--pCounter];
      array21->refC++;
      DEBUG_COPY(array21->id);
   } else {
      array21 = (array_t*)malloc(sizeof(array_t));
      array21->size = 980;
      array21->refC = 1;
      array21->id = 21;
      array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
      memset(array21->data, 0, array21->size*sizeof(unsigned int));
      DEBUG_NEW(array21->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array21;
   array_t* array22 = func12(&params0, loopsFactor);
   DEBUG_RETURN(array22->id);
   free(params0.data);
   array22->refC--;
   if(array22->refC == 0) {
      free(array22->data);
      free(array22);
      DEBUG_FREE(array22->id);
   }
   return array21;
}

