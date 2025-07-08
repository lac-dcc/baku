#include "sortedlist9_2.h" 
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
           cell_t* cell5 = sortedlist20->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
   }
   sortedlist_t* sortedlist23;
   if (pCounter > 0) {
      sortedlist23 = vars->data[--pCounter];
      sortedlist23->refC++;
      DEBUG_COPY(sortedlist23->id);
   } else {
      sortedlist23 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist23->refC = 1;
      sortedlist23->id = 23;
      sortedlist23->n = 0;
      sortedlist23->root = NULL;
      DEBUG_NEW(sortedlist23->id);
   }
   return sortedlist23;
}

