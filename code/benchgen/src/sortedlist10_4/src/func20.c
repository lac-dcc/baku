#include "sortedlist10_4.h" 
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop12 = 0;
   unsigned int loopLimit12 = (rand()%loopsFactor)/5 + 1;
   for(; loop12 < loopLimit12; loop12++) {
      sortedlist_t* sortedlist51;
      if (pCounter > 0) {
         sortedlist51 = vars->data[--pCounter];
         sortedlist51->refC++;
         DEBUG_COPY(sortedlist51->id);
      } else {
         sortedlist51 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist51->refC = 1;
         sortedlist51->id = 51;
         sortedlist51->n = 0;
         sortedlist51->root = NULL;
         DEBUG_NEW(sortedlist51->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist51;
      sortedlist_t* sortedlist52 = func22(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist52->id);
      free(params0.data);
      sortedlist52->refC--;
      if(sortedlist52->refC == 0){
           cell_t* cell28 = sortedlist52->root;
           cell_t* tmp28  = NULL;
           while(cell28 != NULL) {
               tmp28 = cell28->next;
               free(cell28);
               cell28 = tmp28;
           }
           free(sortedlist52);
           DEBUG_FREE(sortedlist52->id);
      }
      sortedlist51->refC--;
      if(sortedlist51->refC == 0){
           cell_t* cell29 = sortedlist51->root;
           cell_t* tmp29  = NULL;
           while(cell29 != NULL) {
               tmp29 = cell29->next;
               free(cell29);
               cell29 = tmp29;
           }
           free(sortedlist51);
           DEBUG_FREE(sortedlist51->id);
      }
   }
   sortedlist_t* sortedlist69;
   if (pCounter > 0) {
      sortedlist69 = vars->data[--pCounter];
      sortedlist69->refC++;
      DEBUG_COPY(sortedlist69->id);
   } else {
      sortedlist69 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist69->refC = 1;
      sortedlist69->id = 69;
      sortedlist69->n = 0;
      sortedlist69->root = NULL;
      DEBUG_NEW(sortedlist69->id);
   }
   return sortedlist69;
}

