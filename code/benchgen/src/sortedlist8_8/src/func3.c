#include "sortedlist8_8.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist28 = func8(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist28->id);
   free(params0.data);
   return sortedlist28;
}

