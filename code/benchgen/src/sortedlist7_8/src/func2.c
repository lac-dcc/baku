#include "sortedlist7_8.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist21 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist21->id);
      free(params0.data);
      sortedlist21->refC--;
      if(sortedlist21->refC == 0){
           cell_t* cell18 = sortedlist21->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist21);
           DEBUG_FREE(sortedlist21->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist39 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist39->id);
      free(params0.data);
      sortedlist39->refC--;
      if(sortedlist39->refC == 0){
           cell_t* cell19 = sortedlist39->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist39);
           DEBUG_FREE(sortedlist39->id);
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

