#include "sortedlist9_8.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist28 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist28->id);
      free(params0.data);
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell22 = sortedlist28->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist48 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist48->id);
      free(params0.data);
      sortedlist48->refC--;
      if(sortedlist48->refC == 0){
           cell_t* cell23 = sortedlist48->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist48);
           DEBUG_FREE(sortedlist48->id);
      }
   }
   sortedlist_t* sortedlist50;
   if (pCounter > 0) {
      sortedlist50 = vars->data[--pCounter];
      sortedlist50->refC++;
      DEBUG_COPY(sortedlist50->id);
   } else {
      sortedlist50 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist50->refC = 1;
      sortedlist50->id = 50;
      sortedlist50->n = 0;
      sortedlist50->root = NULL;
      DEBUG_NEW(sortedlist50->id);
   }
   return sortedlist50;
}

