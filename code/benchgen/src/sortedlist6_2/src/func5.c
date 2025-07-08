#include "sortedlist6_2.h" 
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
           cell_t* cell0 = sortedlist3->root;
           cell_t* tmp0  = NULL;
           while(cell0 != NULL) {
               tmp0 = cell0->next;
               free(cell0);
               cell0 = tmp0;
           }
           free(sortedlist3);
           DEBUG_FREE(sortedlist3->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist5 = func7(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist5->id);
      free(params0.data);
      sortedlist5->refC--;
      if(sortedlist5->refC == 0){
           cell_t* cell11 = sortedlist5->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist5);
           DEBUG_FREE(sortedlist5->id);
      }
   }
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
   return sortedlist21;
}

