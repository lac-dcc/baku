#include "array8_8.h" 
array_t* func19(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array36 = func24(&params0, loopsFactor);
   DEBUG_RETURN(array36->id);
   free(params0.data);
   return array36;
}

