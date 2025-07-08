#include "sortedlist8_8.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist27 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist27->id);
      free(params0.data);
      sortedlist27->refC--;
      if(sortedlist27->refC == 0){
           cell_t* cell21 = sortedlist27->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist27);
           DEBUG_FREE(sortedlist27->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist46 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist46->id);
      free(params0.data);
      sortedlist46->refC--;
      if(sortedlist46->refC == 0){
           cell_t* cell22 = sortedlist46->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist46);
           DEBUG_FREE(sortedlist46->id);
      }
   }
   sortedlist_t* sortedlist48;
   if (pCounter > 0) {
      sortedlist48 = vars->data[--pCounter];
      sortedlist48->refC++;
      DEBUG_COPY(sortedlist48->id);
   } else {
      sortedlist48 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist48->refC = 1;
      sortedlist48->id = 48;
      sortedlist48->n = 0;
      sortedlist48->root = NULL;
      DEBUG_NEW(sortedlist48->id);
   }
   return sortedlist48;
}

