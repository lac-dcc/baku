#include "sortedlist9_2.h" 
sortedlist_t* func17(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist13 = func18(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist13->id);
      free(params0.data);
      sortedlist13->refC--;
      if(sortedlist13->refC == 0){
           cell_t* cell2 = sortedlist13->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist13);
           DEBUG_FREE(sortedlist13->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist15 = func19(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist15->id);
      free(params0.data);
      sortedlist15->refC--;
      if(sortedlist15->refC == 0){
           cell_t* cell9 = sortedlist15->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist15);
           DEBUG_FREE(sortedlist15->id);
      }
   }
   sortedlist_t* sortedlist25;
   if (pCounter > 0) {
      sortedlist25 = vars->data[--pCounter];
      sortedlist25->refC++;
      DEBUG_COPY(sortedlist25->id);
   } else {
      sortedlist25 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist25->refC = 1;
      sortedlist25->id = 25;
      sortedlist25->n = 0;
      sortedlist25->root = NULL;
      DEBUG_NEW(sortedlist25->id);
   }
   return sortedlist25;
}

