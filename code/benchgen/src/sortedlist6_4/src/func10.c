#include "sortedlist6_4.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
   for(; loop7 < loopLimit7; loop7++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist31;
      sortedlist_t* sortedlist32 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist32->id);
      free(params0.data);
      sortedlist32->refC--;
      if(sortedlist32->refC == 0){
           cell_t* cell17 = sortedlist32->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist32);
           DEBUG_FREE(sortedlist32->id);
      }
      sortedlist31->refC--;
      if(sortedlist31->refC == 0){
           cell_t* cell18 = sortedlist31->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist31);
           DEBUG_FREE(sortedlist31->id);
      }
   }
   sortedlist_t* sortedlist42;
   if (pCounter > 0) {
      sortedlist42 = vars->data[--pCounter];
      sortedlist42->refC++;
      DEBUG_COPY(sortedlist42->id);
   } else {
      sortedlist42 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist42->refC = 1;
      sortedlist42->id = 42;
      sortedlist42->n = 0;
      sortedlist42->root = NULL;
      DEBUG_NEW(sortedlist42->id);
   }
   return sortedlist42;
}

