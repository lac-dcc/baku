#include "sortedlist8_2.h" 
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
           cell_t* cell8 = sortedlist15->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist15);
           DEBUG_FREE(sortedlist15->id);
      }
   }
   sortedlist_t* sortedlist24;
   if (pCounter > 0) {
      sortedlist24 = vars->data[--pCounter];
      sortedlist24->refC++;
      DEBUG_COPY(sortedlist24->id);
   } else {
      sortedlist24 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist24->refC = 1;
      sortedlist24->id = 24;
      sortedlist24->n = 0;
      sortedlist24->root = NULL;
      DEBUG_NEW(sortedlist24->id);
   }
   return sortedlist24;
}

