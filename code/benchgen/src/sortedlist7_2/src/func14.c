#include "sortedlist7_2.h" 
sortedlist_t* func14(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist36 = func15(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist36->id);
      free(params0.data);
      sortedlist36->refC--;
      if(sortedlist36->refC == 0){
           cell_t* cell19 = sortedlist36->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist36);
           DEBUG_FREE(sortedlist36->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist38 = func16(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist38->id);
      free(params0.data);
      sortedlist38->refC--;
      if(sortedlist38->refC == 0){
           cell_t* cell25 = sortedlist38->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist38);
           DEBUG_FREE(sortedlist38->id);
      }
   }
   sortedlist_t* sortedlist47;
   if (pCounter > 0) {
      sortedlist47 = vars->data[--pCounter];
      sortedlist47->refC++;
      DEBUG_COPY(sortedlist47->id);
   } else {
      sortedlist47 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist47->refC = 1;
      sortedlist47->id = 47;
      sortedlist47->n = 0;
      sortedlist47->root = NULL;
      DEBUG_NEW(sortedlist47->id);
   }
   return sortedlist47;
}

