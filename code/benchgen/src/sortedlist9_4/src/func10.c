#include "sortedlist9_4.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/3 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      sortedlist_t* sortedlist41;
      if (pCounter > 0) {
         sortedlist41 = vars->data[--pCounter];
         sortedlist41->refC++;
         DEBUG_COPY(sortedlist41->id);
      } else {
         sortedlist41 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist41->refC = 1;
         sortedlist41->id = 41;
         sortedlist41->n = 0;
         sortedlist41->root = NULL;
         DEBUG_NEW(sortedlist41->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist41;
      sortedlist_t* sortedlist42 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist42->id);
      free(params0.data);
      sortedlist42->refC--;
      if(sortedlist42->refC == 0){
           cell_t* cell27 = sortedlist42->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist42);
           DEBUG_FREE(sortedlist42->id);
      }
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell28 = sortedlist41->root;
           cell_t* tmp28  = NULL;
           while(cell28 != NULL) {
               tmp28 = cell28->next;
               free(cell28);
               cell28 = tmp28;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
   }
   sortedlist_t* sortedlist62;
   if (pCounter > 0) {
      sortedlist62 = vars->data[--pCounter];
      sortedlist62->refC++;
      DEBUG_COPY(sortedlist62->id);
   } else {
      sortedlist62 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist62->refC = 1;
      sortedlist62->id = 62;
      sortedlist62->n = 0;
      sortedlist62->root = NULL;
      DEBUG_NEW(sortedlist62->id);
   }
   return sortedlist62;
}

