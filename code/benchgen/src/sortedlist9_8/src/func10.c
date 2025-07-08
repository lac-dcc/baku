#include "sortedlist9_8.h" 
sortedlist_t* func10(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist32 = func11(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist32->id);
      free(params0.data);
      sortedlist32->refC--;
      if(sortedlist32->refC == 0){
           cell_t* cell18 = sortedlist32->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist32);
           DEBUG_FREE(sortedlist32->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist44 = func12(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist44->id);
      free(params0.data);
      sortedlist44->refC--;
      if(sortedlist44->refC == 0){
           cell_t* cell19 = sortedlist44->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist44);
           DEBUG_FREE(sortedlist44->id);
      }
   }
   sortedlist_t* sortedlist46;
   if (pCounter > 0) {
      sortedlist46 = vars->data[--pCounter];
      sortedlist46->refC++;
      DEBUG_COPY(sortedlist46->id);
   } else {
      sortedlist46 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist46->refC = 1;
      sortedlist46->id = 46;
      sortedlist46->n = 0;
      sortedlist46->root = NULL;
      DEBUG_NEW(sortedlist46->id);
   }
   return sortedlist46;
}

