#include "sortedlist6_4.h" 
sortedlist_t* func16(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist12 = func17(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist12->id);
      free(params0.data);
      sortedlist12->refC--;
      if(sortedlist12->refC == 0){
           cell_t* cell2 = sortedlist12->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist12);
           DEBUG_FREE(sortedlist12->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist14 = func18(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist14->id);
      free(params0.data);
      sortedlist14->refC--;
      if(sortedlist14->refC == 0){
           cell_t* cell3 = sortedlist14->root;
           cell_t* tmp3  = NULL;
           while(cell3 != NULL) {
               tmp3 = cell3->next;
               free(cell3);
               cell3 = tmp3;
           }
           free(sortedlist14);
           DEBUG_FREE(sortedlist14->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist16 = func19(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist16->id);
   free(params0.data);
   return sortedlist16;
}

