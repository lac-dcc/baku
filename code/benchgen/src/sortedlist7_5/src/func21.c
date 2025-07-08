#include "sortedlist7_5.h" 
sortedlist_t* func21(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist28 = func22(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist28->id);
      free(params0.data);
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell15 = sortedlist28->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist30 = func23(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist30->id);
      free(params0.data);
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell16 = sortedlist30->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
      }
   }
   sortedlist_t* sortedlist32;
   if (pCounter > 0) {
      sortedlist32 = vars->data[--pCounter];
      sortedlist32->refC++;
      DEBUG_COPY(sortedlist32->id);
   } else {
      sortedlist32 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist32->refC = 1;
      sortedlist32->id = 32;
      sortedlist32->n = 0;
      sortedlist32->root = NULL;
      DEBUG_NEW(sortedlist32->id);
   }
   return sortedlist32;
}

