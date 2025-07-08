#include "sortedlist7_2.h" 
sortedlist_t* func8(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist31 = func9(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist31->id);
      free(params0.data);
      sortedlist31->refC--;
      if(sortedlist31->refC == 0){
           cell_t* cell18 = sortedlist31->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist31);
           DEBUG_FREE(sortedlist31->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist33 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist33->id);
      free(params0.data);
      sortedlist33->refC--;
      if(sortedlist33->refC == 0){
           cell_t* cell29 = sortedlist33->root;
           cell_t* tmp29  = NULL;
           while(cell29 != NULL) {
               tmp29 = cell29->next;
               free(cell29);
               cell29 = tmp29;
           }
           free(sortedlist33);
           DEBUG_FREE(sortedlist33->id);
      }
   }
   sortedlist_t* sortedlist49;
   if (pCounter > 0) {
      sortedlist49 = vars->data[--pCounter];
      sortedlist49->refC++;
      DEBUG_COPY(sortedlist49->id);
   } else {
      sortedlist49 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist49->refC = 1;
      sortedlist49->id = 49;
      sortedlist49->n = 0;
      sortedlist49->root = NULL;
      DEBUG_NEW(sortedlist49->id);
   }
   return sortedlist49;
}

