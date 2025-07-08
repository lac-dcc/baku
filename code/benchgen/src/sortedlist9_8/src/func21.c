#include "sortedlist9_8.h" 
sortedlist_t* func21(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist11 = func22(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist11->id);
      free(params0.data);
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell0 = sortedlist11->root;
           cell_t* tmp0  = NULL;
           while(cell0 != NULL) {
               tmp0 = cell0->next;
               free(cell0);
               cell0 = tmp0;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist14 = func23(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist14->id);
      free(params0.data);
      sortedlist14->refC--;
      if(sortedlist14->refC == 0){
           cell_t* cell1 = sortedlist14->root;
           cell_t* tmp1  = NULL;
           while(cell1 != NULL) {
               tmp1 = cell1->next;
               free(cell1);
               cell1 = tmp1;
           }
           free(sortedlist14);
           DEBUG_FREE(sortedlist14->id);
      }
   }
   sortedlist_t* sortedlist16;
   if (pCounter > 0) {
      sortedlist16 = vars->data[--pCounter];
      sortedlist16->refC++;
      DEBUG_COPY(sortedlist16->id);
   } else {
      sortedlist16 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist16->refC = 1;
      sortedlist16->id = 16;
      sortedlist16->n = 0;
      sortedlist16->root = NULL;
      DEBUG_NEW(sortedlist16->id);
   }
   return sortedlist16;
}

