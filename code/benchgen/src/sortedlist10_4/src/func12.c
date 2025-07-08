#include "sortedlist10_4.h" 
sortedlist_t* func12(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist44 = func13(&params0, loopsFactor);
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
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist46 = func14(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist46->id);
      free(params0.data);
      sortedlist46->refC--;
      if(sortedlist46->refC == 0){
           cell_t* cell20 = sortedlist46->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist46);
           DEBUG_FREE(sortedlist46->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist48 = func15(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist48->id);
   free(params0.data);
   return sortedlist48;
}

