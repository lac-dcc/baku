#include "sortedlist6_4.h" 
sortedlist_t* func1(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist23 = func2(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(sortedlist23->id);
   free(params0.data);
   return sortedlist23;
}

