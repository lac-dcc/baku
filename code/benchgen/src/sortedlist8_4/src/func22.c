#include "sortedlist8_4.h" 
sortedlist_t* func22(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist50 = func23(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist50->id);
      free(params0.data);
      sortedlist50->refC--;
      if(sortedlist50->refC == 0){
           cell_t* cell19 = sortedlist50->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist50);
           DEBUG_FREE(sortedlist50->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist52 = func24(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist52->id);
      free(params0.data);
      sortedlist52->refC--;
      if(sortedlist52->refC == 0){
           cell_t* cell20 = sortedlist52->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist52);
           DEBUG_FREE(sortedlist52->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist54 = func25(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist54->id);
   free(params0.data);
   return sortedlist54;
}

