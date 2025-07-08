#include "sortedlist5_8.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/1 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      sortedlist_t* sortedlist21;
      if (pCounter > 0) {
         sortedlist21 = vars->data[--pCounter];
         sortedlist21->refC++;
         DEBUG_COPY(sortedlist21->id);
      } else {
         sortedlist21 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist21->refC = 1;
         sortedlist21->id = 21;
         sortedlist21->n = 0;
         sortedlist21->root = NULL;
         DEBUG_NEW(sortedlist21->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist21;
      sortedlist_t* sortedlist22 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist22->id);
      free(params0.data);
      sortedlist22->refC--;
      if(sortedlist22->refC == 0){
           cell_t* cell11 = sortedlist22->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist22);
           DEBUG_FREE(sortedlist22->id);
      }
      sortedlist21->refC--;
      if(sortedlist21->refC == 0){
           cell_t* cell12 = sortedlist21->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist21);
           DEBUG_FREE(sortedlist21->id);
      }
   }
   sortedlist_t* sortedlist29;
   if (pCounter > 0) {
      sortedlist29 = vars->data[--pCounter];
      sortedlist29->refC++;
      DEBUG_COPY(sortedlist29->id);
   } else {
      sortedlist29 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist29->refC = 1;
      sortedlist29->id = 29;
      sortedlist29->n = 0;
      sortedlist29->root = NULL;
      DEBUG_NEW(sortedlist29->id);
   }
   return sortedlist29;
}

