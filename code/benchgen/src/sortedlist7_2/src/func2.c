#include "sortedlist7_2.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist26 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist26->id);
      free(params0.data);
      sortedlist26->refC--;
      if(sortedlist26->refC == 0){
           cell_t* cell17 = sortedlist26->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist26);
           DEBUG_FREE(sortedlist26->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist28 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist28->id);
      free(params0.data);
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell33 = sortedlist28->root;
           cell_t* tmp33  = NULL;
           while(cell33 != NULL) {
               tmp33 = cell33->next;
               free(cell33);
               cell33 = tmp33;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
   }
   sortedlist_t* sortedlist51;
   if (pCounter > 0) {
      sortedlist51 = vars->data[--pCounter];
      sortedlist51->refC++;
      DEBUG_COPY(sortedlist51->id);
   } else {
      sortedlist51 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist51->refC = 1;
      sortedlist51->id = 51;
      sortedlist51->n = 0;
      sortedlist51->root = NULL;
      DEBUG_NEW(sortedlist51->id);
   }
   return sortedlist51;
}

