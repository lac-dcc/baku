#include "sortedlist8_2.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist32 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist32->id);
      free(params0.data);
      sortedlist32->refC--;
      if(sortedlist32->refC == 0){
           cell_t* cell21 = sortedlist32->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist32);
           DEBUG_FREE(sortedlist32->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist34 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist34->id);
      free(params0.data);
      sortedlist34->refC--;
      if(sortedlist34->refC == 0){
           cell_t* cell38 = sortedlist34->root;
           cell_t* tmp38  = NULL;
           while(cell38 != NULL) {
               tmp38 = cell38->next;
               free(cell38);
               cell38 = tmp38;
           }
           free(sortedlist34);
           DEBUG_FREE(sortedlist34->id);
      }
   }
   sortedlist_t* sortedlist58;
   if (pCounter > 0) {
      sortedlist58 = vars->data[--pCounter];
      sortedlist58->refC++;
      DEBUG_COPY(sortedlist58->id);
   } else {
      sortedlist58 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist58->refC = 1;
      sortedlist58->id = 58;
      sortedlist58->n = 0;
      sortedlist58->root = NULL;
      DEBUG_NEW(sortedlist58->id);
   }
   return sortedlist58;
}

