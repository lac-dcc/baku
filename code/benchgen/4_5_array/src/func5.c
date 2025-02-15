#include "outs/4_5_array.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array13 = func6(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array13->id);
   free(params0.data);
   return array13;
}

