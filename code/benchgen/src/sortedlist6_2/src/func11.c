#include "sortedlist6_2.h" 
sortedlist_t* func11(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist8 = func12(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist8->id);
      free(params0.data);
      sortedlist8->refC--;
      if(sortedlist8->refC == 0){
           cell_t* cell1 = sortedlist8->root;
           cell_t* tmp1  = NULL;
           while(cell1 != NULL) {
               tmp1 = cell1->next;
               free(cell1);
               cell1 = tmp1;
           }
           free(sortedlist8);
           DEBUG_FREE(sortedlist8->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist10 = func13(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist10->id);
      free(params0.data);
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell7 = sortedlist10->root;
           cell_t* tmp7  = NULL;
           while(cell7 != NULL) {
               tmp7 = cell7->next;
               free(cell7);
               cell7 = tmp7;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   sortedlist_t* sortedlist19;
   if (pCounter > 0) {
      sortedlist19 = vars->data[--pCounter];
      sortedlist19->refC++;
      DEBUG_COPY(sortedlist19->id);
   } else {
      sortedlist19 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist19->refC = 1;
      sortedlist19->id = 19;
      sortedlist19->n = 0;
      sortedlist19->root = NULL;
      DEBUG_NEW(sortedlist19->id);
   }
   return sortedlist19;
}

