#include "sortedlist10_8.h" 
sortedlist_t* func18(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist37 = func19(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist37->id);
      free(params0.data);
      sortedlist37->refC--;
      if(sortedlist37->refC == 0){
           cell_t* cell18 = sortedlist37->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist37);
           DEBUG_FREE(sortedlist37->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist47 = func20(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist47->id);
      free(params0.data);
      sortedlist47->refC--;
      if(sortedlist47->refC == 0){
           cell_t* cell19 = sortedlist47->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist47);
           DEBUG_FREE(sortedlist47->id);
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

