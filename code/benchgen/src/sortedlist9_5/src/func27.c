#include "sortedlist9_5.h" 
sortedlist_t* func27(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist38 = func28(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist38->id);
      free(params0.data);
      sortedlist38->refC--;
      if(sortedlist38->refC == 0){
           cell_t* cell21 = sortedlist38->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist38);
           DEBUG_FREE(sortedlist38->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist40 = func29(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist40->id);
      free(params0.data);
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell22 = sortedlist40->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
   }
   sortedlist_t* sortedlist42;
   if (pCounter > 0) {
      sortedlist42 = vars->data[--pCounter];
      sortedlist42->refC++;
      DEBUG_COPY(sortedlist42->id);
   } else {
      sortedlist42 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist42->refC = 1;
      sortedlist42->id = 42;
      sortedlist42->n = 0;
      sortedlist42->root = NULL;
      DEBUG_NEW(sortedlist42->id);
   }
   return sortedlist42;
}

