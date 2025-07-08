#include "sortedlist10_2.h" 
sortedlist_t* func8(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist44 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist44->id);
      free(params0.data);
      sortedlist44->refC--;
      if(sortedlist44->refC == 0){
           cell_t* cell27 = sortedlist44->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist44);
           DEBUG_FREE(sortedlist44->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist46 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist46->id);
      free(params0.data);
      sortedlist46->refC--;
      if(sortedlist46->refC == 0){
           cell_t* cell44 = sortedlist46->root;
           cell_t* tmp44  = NULL;
           while(cell44 != NULL) {
               tmp44 = cell44->next;
               free(cell44);
               cell44 = tmp44;
           }
           free(sortedlist46);
           DEBUG_FREE(sortedlist46->id);
      }
   }
   sortedlist_t* sortedlist70;
   if (pCounter > 0) {
      sortedlist70 = vars->data[--pCounter];
      sortedlist70->refC++;
      DEBUG_COPY(sortedlist70->id);
   } else {
      sortedlist70 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist70->refC = 1;
      sortedlist70->id = 70;
      sortedlist70->n = 0;
      sortedlist70->root = NULL;
      DEBUG_NEW(sortedlist70->id);
   }
   return sortedlist70;
}

