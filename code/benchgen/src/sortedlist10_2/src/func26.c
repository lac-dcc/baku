#include "sortedlist10_2.h" 
sortedlist_t* func26(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist59 = func27(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist59->id);
      free(params0.data);
      sortedlist59->refC--;
      if(sortedlist59->refC == 0){
           cell_t* cell30 = sortedlist59->root;
           cell_t* tmp30  = NULL;
           while(cell30 != NULL) {
               tmp30 = cell30->next;
               free(cell30);
               cell30 = tmp30;
           }
           free(sortedlist59);
           DEBUG_FREE(sortedlist59->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist61 = func28(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist61->id);
      free(params0.data);
      sortedlist61->refC--;
      if(sortedlist61->refC == 0){
           cell_t* cell32 = sortedlist61->root;
           cell_t* tmp32  = NULL;
           while(cell32 != NULL) {
               tmp32 = cell32->next;
               free(cell32);
               cell32 = tmp32;
           }
           free(sortedlist61);
           DEBUG_FREE(sortedlist61->id);
      }
   }
   sortedlist_t* sortedlist64;
   if (pCounter > 0) {
      sortedlist64 = vars->data[--pCounter];
      sortedlist64->refC++;
      DEBUG_COPY(sortedlist64->id);
   } else {
      sortedlist64 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist64->refC = 1;
      sortedlist64->id = 64;
      sortedlist64->n = 0;
      sortedlist64->root = NULL;
      DEBUG_NEW(sortedlist64->id);
   }
   return sortedlist64;
}

