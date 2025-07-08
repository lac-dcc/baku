#include "sortedlist6_8.h" 
sortedlist_t* func5(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist3 = func6(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist3->id);
      free(params0.data);
      sortedlist3->refC--;
      if(sortedlist3->refC == 0){
           cell_t* cell4 = sortedlist3->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist3);
           DEBUG_FREE(sortedlist3->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist14 = func7(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist14->id);
      free(params0.data);
      sortedlist14->refC--;
      if(sortedlist14->refC == 0){
           cell_t* cell5 = sortedlist14->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist14);
           DEBUG_FREE(sortedlist14->id);
      }
   }
   sortedlist_t* sortedlist16;
   if (pCounter > 0) {
      sortedlist16 = vars->data[--pCounter];
      sortedlist16->refC++;
      DEBUG_COPY(sortedlist16->id);
   } else {
      sortedlist16 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist16->refC = 1;
      sortedlist16->id = 16;
      sortedlist16->n = 0;
      sortedlist16->root = NULL;
      DEBUG_NEW(sortedlist16->id);
   }
   return sortedlist16;
}

