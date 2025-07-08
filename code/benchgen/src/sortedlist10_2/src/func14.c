#include "sortedlist10_2.h" 
sortedlist_t* func14(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist49 = func15(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist49->id);
      free(params0.data);
      sortedlist49->refC--;
      if(sortedlist49->refC == 0){
           cell_t* cell28 = sortedlist49->root;
           cell_t* tmp28  = NULL;
           while(cell28 != NULL) {
               tmp28 = cell28->next;
               free(cell28);
               cell28 = tmp28;
           }
           free(sortedlist49);
           DEBUG_FREE(sortedlist49->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist51 = func16(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist51->id);
      free(params0.data);
      sortedlist51->refC--;
      if(sortedlist51->refC == 0){
           cell_t* cell40 = sortedlist51->root;
           cell_t* tmp40  = NULL;
           while(cell40 != NULL) {
               tmp40 = cell40->next;
               free(cell40);
               cell40 = tmp40;
           }
           free(sortedlist51);
           DEBUG_FREE(sortedlist51->id);
      }
   }
   sortedlist_t* sortedlist68;
   if (pCounter > 0) {
      sortedlist68 = vars->data[--pCounter];
      sortedlist68->refC++;
      DEBUG_COPY(sortedlist68->id);
   } else {
      sortedlist68 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist68->refC = 1;
      sortedlist68->id = 68;
      sortedlist68->n = 0;
      sortedlist68->root = NULL;
      DEBUG_NEW(sortedlist68->id);
   }
   return sortedlist68;
}

