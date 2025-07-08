#include "sortedlist10_4.h" 
sortedlist_t* func32(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist62 = func33(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist62->id);
      free(params0.data);
      sortedlist62->refC--;
      if(sortedlist62->refC == 0){
           cell_t* cell23 = sortedlist62->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist62);
           DEBUG_FREE(sortedlist62->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist64 = func34(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist64->id);
      free(params0.data);
      sortedlist64->refC--;
      if(sortedlist64->refC == 0){
           cell_t* cell24 = sortedlist64->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist64);
           DEBUG_FREE(sortedlist64->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist66 = func35(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist66->id);
   free(params0.data);
   return sortedlist66;
}

