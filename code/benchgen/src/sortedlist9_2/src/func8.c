#include "sortedlist9_2.h" 
sortedlist_t* func8(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist38 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist38->id);
      free(params0.data);
      sortedlist38->refC--;
      if(sortedlist38->refC == 0){
           cell_t* cell23 = sortedlist38->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist38);
           DEBUG_FREE(sortedlist38->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist40 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist40->id);
      free(params0.data);
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell39 = sortedlist40->root;
           cell_t* tmp39  = NULL;
           while(cell39 != NULL) {
               tmp39 = cell39->next;
               free(cell39);
               cell39 = tmp39;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
   }
   sortedlist_t* sortedlist63;
   if (pCounter > 0) {
      sortedlist63 = vars->data[--pCounter];
      sortedlist63->refC++;
      DEBUG_COPY(sortedlist63->id);
   } else {
      sortedlist63 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist63->refC = 1;
      sortedlist63->id = 63;
      sortedlist63->n = 0;
      sortedlist63->root = NULL;
      DEBUG_NEW(sortedlist63->id);
   }
   return sortedlist63;
}

