#include "sortedlist10_2.h" 
sortedlist_t* func20(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist54 = func21(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist54->id);
      free(params0.data);
      sortedlist54->refC--;
      if(sortedlist54->refC == 0){
           cell_t* cell29 = sortedlist54->root;
           cell_t* tmp29  = NULL;
           while(cell29 != NULL) {
               tmp29 = cell29->next;
               free(cell29);
               cell29 = tmp29;
           }
           free(sortedlist54);
           DEBUG_FREE(sortedlist54->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist56 = func22(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist56->id);
      free(params0.data);
      sortedlist56->refC--;
      if(sortedlist56->refC == 0){
           cell_t* cell36 = sortedlist56->root;
           cell_t* tmp36  = NULL;
           while(cell36 != NULL) {
               tmp36 = cell36->next;
               free(cell36);
               cell36 = tmp36;
           }
           free(sortedlist56);
           DEBUG_FREE(sortedlist56->id);
      }
   }
   sortedlist_t* sortedlist66;
   if (pCounter > 0) {
      sortedlist66 = vars->data[--pCounter];
      sortedlist66->refC++;
      DEBUG_COPY(sortedlist66->id);
   } else {
      sortedlist66 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist66->refC = 1;
      sortedlist66->id = 66;
      sortedlist66->n = 0;
      sortedlist66->root = NULL;
      DEBUG_NEW(sortedlist66->id);
   }
   return sortedlist66;
}

