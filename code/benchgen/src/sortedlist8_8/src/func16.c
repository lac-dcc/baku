#include "sortedlist8_8.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist33;
      if (pCounter > 0) {
         sortedlist33 = vars->data[--pCounter];
         sortedlist33->refC++;
         DEBUG_COPY(sortedlist33->id);
      } else {
         sortedlist33 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist33->refC = 1;
         sortedlist33->id = 33;
         sortedlist33->n = 0;
         sortedlist33->root = NULL;
         DEBUG_NEW(sortedlist33->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist33;
      sortedlist_t* sortedlist34 = func18(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist34->id);
      free(params0.data);
      sortedlist34->refC--;
      if(sortedlist34->refC == 0){
           cell_t* cell15 = sortedlist34->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist34);
           DEBUG_FREE(sortedlist34->id);
      }
      sortedlist33->refC--;
      if(sortedlist33->refC == 0){
           cell_t* cell16 = sortedlist33->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist33);
           DEBUG_FREE(sortedlist33->id);
      }
   }
   sortedlist_t* sortedlist41;
   if (pCounter > 0) {
      sortedlist41 = vars->data[--pCounter];
      sortedlist41->refC++;
      DEBUG_COPY(sortedlist41->id);
   } else {
      sortedlist41 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist41->refC = 1;
      sortedlist41->id = 41;
      sortedlist41->n = 0;
      sortedlist41->root = NULL;
      DEBUG_NEW(sortedlist41->id);
   }
   return sortedlist41;
}

