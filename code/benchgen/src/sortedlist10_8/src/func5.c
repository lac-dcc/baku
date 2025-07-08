#include "sortedlist10_8.h" 
sortedlist_t* func5(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist3 = func6(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist3->id);
      free(params0.data);
      sortedlist3->refC--;
      if(sortedlist3->refC == 0){
           cell_t* cell9 = sortedlist3->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist3);
           DEBUG_FREE(sortedlist3->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist23 = func7(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist23->id);
      free(params0.data);
      sortedlist23->refC--;
      if(sortedlist23->refC == 0){
           cell_t* cell10 = sortedlist23->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist23);
           DEBUG_FREE(sortedlist23->id);
      }
   }
   sortedlist_t* sortedlist25;
   if (pCounter > 0) {
      sortedlist25 = vars->data[--pCounter];
      sortedlist25->refC++;
      DEBUG_COPY(sortedlist25->id);
   } else {
      sortedlist25 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist25->refC = 1;
      sortedlist25->id = 25;
      sortedlist25->n = 0;
      sortedlist25->root = NULL;
      DEBUG_NEW(sortedlist25->id);
   }
   return sortedlist25;
}

