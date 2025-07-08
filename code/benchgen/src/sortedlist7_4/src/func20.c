#include "sortedlist7_4.h" 
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/5 + 1;
   for(; loop10 < loopLimit10; loop10++) {
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
      sortedlist_t* sortedlist42 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist42->id);
      free(params0.data);
      sortedlist42->refC--;
      if(sortedlist42->refC == 0){
           cell_t* cell18 = sortedlist42->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist42);
           DEBUG_FREE(sortedlist42->id);
      }
      sortedlist41->refC--;
      if(sortedlist41->refC == 0){
           cell_t* cell19 = sortedlist41->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist41);
           DEBUG_FREE(sortedlist41->id);
      }
   }
   sortedlist_t* sortedlist49;
   if (pCounter > 0) {
      sortedlist49 = vars->data[--pCounter];
      sortedlist49->refC++;
      DEBUG_COPY(sortedlist49->id);
   } else {
      sortedlist49 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist49->refC = 1;
      sortedlist49->id = 49;
      sortedlist49->n = 0;
      sortedlist49->root = NULL;
      DEBUG_NEW(sortedlist49->id);
   }
   return sortedlist49;
}

