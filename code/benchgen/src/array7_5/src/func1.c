#include "array7_5.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array35 = func3(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(array35->id);
   free(params0.data);
   return array35;
}

