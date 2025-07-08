#include "sortedlist6_8.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/1 + 1;
   for(; loop2 < loopLimit2; loop2++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist22;
      sortedlist_t* sortedlist23 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist23->id);
      free(params0.data);
      sortedlist23->refC--;
      if(sortedlist23->refC == 0){
           cell_t* cell12 = sortedlist23->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist23);
           DEBUG_FREE(sortedlist23->id);
      }
      sortedlist22->refC--;
      if(sortedlist22->refC == 0){
           cell_t* cell13 = sortedlist22->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist22);
           DEBUG_FREE(sortedlist22->id);
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

