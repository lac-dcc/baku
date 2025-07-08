#include "sortedlist10_2.h" 
sortedlist_t* func23(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist18 = func24(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist18->id);
      free(params0.data);
      sortedlist18->refC--;
      if(sortedlist18->refC == 0){
           cell_t* cell3 = sortedlist18->root;
           cell_t* tmp3  = NULL;
           while(cell3 != NULL) {
               tmp3 = cell3->next;
               free(cell3);
               cell3 = tmp3;
           }
           free(sortedlist18);
           DEBUG_FREE(sortedlist18->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist20 = func25(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist20->id);
      free(params0.data);
      sortedlist20->refC--;
      if(sortedlist20->refC == 0){
           cell_t* cell9 = sortedlist20->root;
           cell_t* tmp9  = NULL;
           while(cell9 != NULL) {
               tmp9 = cell9->next;
               free(cell9);
               cell9 = tmp9;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
   }
   sortedlist_t* sortedlist29;
   if (pCounter > 0) {
      sortedlist29 = vars->data[--pCounter];
      sortedlist29->refC++;
      DEBUG_COPY(sortedlist29->id);
   } else {
      sortedlist29 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist29->refC = 1;
      sortedlist29->id = 29;
      sortedlist29->n = 0;
      sortedlist29->root = NULL;
      DEBUG_NEW(sortedlist29->id);
   }
   return sortedlist29;
}

