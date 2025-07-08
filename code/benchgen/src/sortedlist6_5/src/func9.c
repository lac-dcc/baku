#include "sortedlist6_5.h" 
sortedlist_t* func9(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist8 = func10(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist8->id);
      free(params0.data);
      sortedlist8->refC--;
      if(sortedlist8->refC == 0){
           cell_t* cell4 = sortedlist8->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist8);
           DEBUG_FREE(sortedlist8->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist10 = func11(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist10->id);
      free(params0.data);
      sortedlist10->refC--;
      if(sortedlist10->refC == 0){
           cell_t* cell5 = sortedlist10->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist10);
           DEBUG_FREE(sortedlist10->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist12 = func12(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(sortedlist12->id);
   free(params0.data);
   return sortedlist12;
}

