#include "sortedlist9_4.h" 
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/5 + 1;
   for(; loop11 < loopLimit11; loop11++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist50;
      sortedlist_t* sortedlist51 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist51->id);
      free(params0.data);
      sortedlist51->refC--;
      if(sortedlist51->refC == 0){
           cell_t* cell24 = sortedlist51->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist51);
           DEBUG_FREE(sortedlist51->id);
      }
      sortedlist50->refC--;
      if(sortedlist50->refC == 0){
           cell_t* cell25 = sortedlist50->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist50);
           DEBUG_FREE(sortedlist50->id);
      }
   }
   sortedlist_t* sortedlist61;
   if (pCounter > 0) {
      sortedlist61 = vars->data[--pCounter];
      sortedlist61->refC++;
      DEBUG_COPY(sortedlist61->id);
   } else {
      sortedlist61 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist61->refC = 1;
      sortedlist61->id = 61;
      sortedlist61->n = 0;
      sortedlist61->root = NULL;
      DEBUG_NEW(sortedlist61->id);
   }
   return sortedlist61;
}

