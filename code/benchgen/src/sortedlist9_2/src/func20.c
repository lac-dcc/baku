#include "sortedlist9_2.h" 
sortedlist_t* func20(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist48 = func21(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist48->id);
      free(params0.data);
      sortedlist48->refC--;
      if(sortedlist48->refC == 0){
           cell_t* cell25 = sortedlist48->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist48);
           DEBUG_FREE(sortedlist48->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist50 = func22(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist50->id);
      free(params0.data);
      sortedlist50->refC--;
      if(sortedlist50->refC == 0){
           cell_t* cell31 = sortedlist50->root;
           cell_t* tmp31  = NULL;
           while(cell31 != NULL) {
               tmp31 = cell31->next;
               free(cell31);
               cell31 = tmp31;
           }
           free(sortedlist50);
           DEBUG_FREE(sortedlist50->id);
      }
   }
   sortedlist_t* sortedlist59;
   if (pCounter > 0) {
      sortedlist59 = vars->data[--pCounter];
      sortedlist59->refC++;
      DEBUG_COPY(sortedlist59->id);
   } else {
      sortedlist59 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist59->refC = 1;
      sortedlist59->id = 59;
      sortedlist59->n = 0;
      sortedlist59->root = NULL;
      DEBUG_NEW(sortedlist59->id);
   }
   return sortedlist59;
}

