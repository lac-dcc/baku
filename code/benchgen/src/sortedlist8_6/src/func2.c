#include "sortedlist8_6.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist11 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist11->id);
      free(params0.data);
      sortedlist11->refC--;
      if(sortedlist11->refC == 0){
           cell_t* cell5 = sortedlist11->root;
           cell_t* tmp5  = NULL;
           while(cell5 != NULL) {
               tmp5 = cell5->next;
               free(cell5);
               cell5 = tmp5;
           }
           free(sortedlist11);
           DEBUG_FREE(sortedlist11->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist13 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist13->id);
      free(params0.data);
      sortedlist13->refC--;
      if(sortedlist13->refC == 0){
           cell_t* cell6 = sortedlist13->root;
           cell_t* tmp6  = NULL;
           while(cell6 != NULL) {
               tmp6 = cell6->next;
               free(cell6);
               cell6 = tmp6;
           }
           free(sortedlist13);
           DEBUG_FREE(sortedlist13->id);
      }
   }
   sortedlist_t* sortedlist15;
   if (pCounter > 0) {
      sortedlist15 = vars->data[--pCounter];
      sortedlist15->refC++;
      DEBUG_COPY(sortedlist15->id);
   } else {
      sortedlist15 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist15->refC = 1;
      sortedlist15->id = 15;
      sortedlist15->n = 0;
      sortedlist15->root = NULL;
      DEBUG_NEW(sortedlist15->id);
   }
   return sortedlist15;
}

