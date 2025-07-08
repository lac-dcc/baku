#include "sortedlist10_2.h" 
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
           cell_t* cell13 = sortedlist15->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist15);
           DEBUG_FREE(sortedlist15->id);
      }
   }
   sortedlist_t* sortedlist31;
   if (pCounter > 0) {
      sortedlist31 = vars->data[--pCounter];
      sortedlist31->refC++;
      DEBUG_COPY(sortedlist31->id);
   } else {
      sortedlist31 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist31->refC = 1;
      sortedlist31->id = 31;
      sortedlist31->n = 0;
      sortedlist31->root = NULL;
      DEBUG_NEW(sortedlist31->id);
   }
   return sortedlist31;
}

