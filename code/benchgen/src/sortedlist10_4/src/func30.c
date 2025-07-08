#include "sortedlist10_4.h" 
sortedlist_t* func30(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop14 = 0;
   unsigned int loopLimit14 = (rand()%loopsFactor)/7 + 1;
   for(; loop14 < loopLimit14; loop14++) {
      sortedlist_t* sortedlist60;
      if (pCounter > 0) {
         sortedlist60 = vars->data[--pCounter];
         sortedlist60->refC++;
         DEBUG_COPY(sortedlist60->id);
      } else {
         sortedlist60 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist60->refC = 1;
         sortedlist60->id = 60;
         sortedlist60->n = 0;
         sortedlist60->root = NULL;
         DEBUG_NEW(sortedlist60->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist60;
      sortedlist_t* sortedlist61 = func32(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist61->id);
      free(params0.data);
      sortedlist61->refC--;
      if(sortedlist61->refC == 0){
           cell_t* cell25 = sortedlist61->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist61);
           DEBUG_FREE(sortedlist61->id);
      }
      sortedlist60->refC--;
      if(sortedlist60->refC == 0){
           cell_t* cell26 = sortedlist60->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist60);
           DEBUG_FREE(sortedlist60->id);
      }
   }
   sortedlist_t* sortedlist68;
   if (pCounter > 0) {
      sortedlist68 = vars->data[--pCounter];
      sortedlist68->refC++;
      DEBUG_COPY(sortedlist68->id);
   } else {
      sortedlist68 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist68->refC = 1;
      sortedlist68->id = 68;
      sortedlist68->n = 0;
      sortedlist68->root = NULL;
      DEBUG_NEW(sortedlist68->id);
   }
   return sortedlist68;
}

