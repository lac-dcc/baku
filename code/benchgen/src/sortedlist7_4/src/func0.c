#include "sortedlist7_4.h" 
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
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
           cell_t* cell9 = sortedlist2->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell10 = sortedlist1->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist22;
   if (pCounter > 0) {
      sortedlist22 = vars->data[--pCounter];
      sortedlist22->refC++;
      DEBUG_COPY(sortedlist22->id);
   } else {
      sortedlist22 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist22->refC = 1;
      sortedlist22->id = 22;
      sortedlist22->n = 0;
      sortedlist22->root = NULL;
      DEBUG_NEW(sortedlist22->id);
   }
   return sortedlist22;
}

