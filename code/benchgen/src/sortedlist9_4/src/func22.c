#include "sortedlist9_4.h" 
sortedlist_t* func22(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist52 = func23(&params0, loopsFactor);
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
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist54 = func24(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist54->id);
      free(params0.data);
      sortedlist54->refC--;
      if(sortedlist54->refC == 0){
           cell_t* cell21 = sortedlist54->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist54);
           DEBUG_FREE(sortedlist54->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist56 = func25(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist56->id);
   free(params0.data);
   return sortedlist56;
}

