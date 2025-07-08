#include "sortedlist10_4.h" 
sortedlist_t* func26(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist21 = func27(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist21->id);
      free(params0.data);
      sortedlist21->refC--;
      if(sortedlist21->refC == 0){
           cell_t* cell4 = sortedlist21->root;
           cell_t* tmp4  = NULL;
           while(cell4 != NULL) {
               tmp4 = cell4->next;
               free(cell4);
               cell4 = tmp4;
           }
           free(sortedlist21);
           DEBUG_FREE(sortedlist21->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist23 = func28(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist23->id);
      free(params0.data);
      sortedlist23->refC--;
      if(sortedlist23->refC == 0){
           cell_t* cell5 = sortedlist23->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist23);
           DEBUG_FREE(sortedlist23->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist25 = func29(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist25->id);
   free(params0.data);
   return sortedlist25;
}

