#include "sortedlist8_8.h" 
sortedlist_t* func10(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist31 = func11(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist31->id);
      free(params0.data);
      sortedlist31->refC--;
      if(sortedlist31->refC == 0){
           cell_t* cell17 = sortedlist31->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist31);
           DEBUG_FREE(sortedlist31->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist42 = func12(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist42->id);
      free(params0.data);
      sortedlist42->refC--;
      if(sortedlist42->refC == 0){
           cell_t* cell18 = sortedlist42->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist42);
           DEBUG_FREE(sortedlist42->id);
      }
   }
   sortedlist_t* sortedlist44;
   if (pCounter > 0) {
      sortedlist44 = vars->data[--pCounter];
      sortedlist44->refC++;
      DEBUG_COPY(sortedlist44->id);
   } else {
      sortedlist44 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist44->refC = 1;
      sortedlist44->id = 44;
      sortedlist44->n = 0;
      sortedlist44->root = NULL;
      DEBUG_NEW(sortedlist44->id);
   }
   return sortedlist44;
}

