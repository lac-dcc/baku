#include "sortedlist10_4.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/3 + 1;
   for(; loop10 < loopLimit10; loop10++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist42;
      sortedlist_t* sortedlist43 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist43->id);
      free(params0.data);
      sortedlist43->refC--;
      if(sortedlist43->refC == 0){
           cell_t* cell31 = sortedlist43->root;
           cell_t* tmp31  = NULL;
           while(cell31 != NULL) {
               tmp31 = cell31->next;
               free(cell31);
               cell31 = tmp31;
           }
           free(sortedlist43);
           DEBUG_FREE(sortedlist43->id);
      }
      sortedlist42->refC--;
      if(sortedlist42->refC == 0){
           cell_t* cell32 = sortedlist42->root;
           cell_t* tmp32  = NULL;
           while(cell32 != NULL) {
               tmp32 = cell32->next;
               free(cell32);
               cell32 = tmp32;
           }
           free(sortedlist42);
           DEBUG_FREE(sortedlist42->id);
      }
   }
   sortedlist_t* sortedlist70;
   if (pCounter > 0) {
      sortedlist70 = vars->data[--pCounter];
      sortedlist70->refC++;
      DEBUG_COPY(sortedlist70->id);
   } else {
      sortedlist70 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist70->refC = 1;
      sortedlist70->id = 70;
      sortedlist70->n = 0;
      sortedlist70->root = NULL;
      DEBUG_NEW(sortedlist70->id);
   }
   return sortedlist70;
}

