#include "array9_6.h" 
array_t* func1(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array10 = func2(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(array10->id);
   free(params0.data);
   return array10;
}

