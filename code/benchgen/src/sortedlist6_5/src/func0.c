#include "sortedlist6_5.h" 
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      sortedlist_t* sortedlist1;
      if (pCounter > 0) {
         sortedlist1 = vars->data[--pCounter];
         sortedlist1->refC++;
         DEBUG_COPY(sortedlist1->id);
      } else {
         sortedlist1 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist1->refC = 1;
         sortedlist1->id = 1;
         sortedlist1->n = 0;
         sortedlist1->root = NULL;
         DEBUG_NEW(sortedlist1->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist1;
      sortedlist_t* sortedlist2 = func6(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist2->id);
      free(params0.data);
      sortedlist2->refC--;
      if(sortedlist2->refC == 0){
           cell_t* cell14 = sortedlist2->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell15 = sortedlist1->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist28;
   if (pCounter > 0) {
      sortedlist28 = vars->data[--pCounter];
      sortedlist28->refC++;
      DEBUG_COPY(sortedlist28->id);
   } else {
      sortedlist28 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist28->refC = 1;
      sortedlist28->id = 28;
      sortedlist28->n = 0;
      sortedlist28->root = NULL;
      DEBUG_NEW(sortedlist28->id);
   }
   return sortedlist28;
}

