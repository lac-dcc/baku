#include "sortedlist8_8.h" 
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
           cell_t* cell8 = sortedlist3->root;
           cell_t* tmp8  = NULL;
           while(cell8 != NULL) {
               tmp8 = cell8->next;
               free(cell8);
               cell8 = tmp8;
           }
           free(sortedlist3);
           DEBUG_FREE(sortedlist3->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist21 = func7(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist21->id);
      free(params0.data);
      sortedlist21->refC--;
      if(sortedlist21->refC == 0){
           cell_t* cell9 = sortedlist21->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist21);
           DEBUG_FREE(sortedlist21->id);
      }
   }
   sortedlist_t* sortedlist23;
   if (pCounter > 0) {
      sortedlist23 = vars->data[--pCounter];
      sortedlist23->refC++;
      DEBUG_COPY(sortedlist23->id);
   } else {
      sortedlist23 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist23->refC = 1;
      sortedlist23->id = 23;
      sortedlist23->n = 0;
      sortedlist23->root = NULL;
      DEBUG_NEW(sortedlist23->id);
   }
   return sortedlist23;
}

