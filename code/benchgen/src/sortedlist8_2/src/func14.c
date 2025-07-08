#include "sortedlist8_2.h" 
sortedlist_t* func14(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist42 = func15(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist42->id);
      free(params0.data);
      sortedlist42->refC--;
      if(sortedlist42->refC == 0){
           cell_t* cell23 = sortedlist42->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist42);
           DEBUG_FREE(sortedlist42->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist44 = func16(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist44->id);
      free(params0.data);
      sortedlist44->refC--;
      if(sortedlist44->refC == 0){
           cell_t* cell30 = sortedlist44->root;
           cell_t* tmp30  = NULL;
           while(cell30 != NULL) {
               tmp30 = cell30->next;
               free(cell30);
               cell30 = tmp30;
           }
           free(sortedlist44);
           DEBUG_FREE(sortedlist44->id);
      }
   }
   sortedlist_t* sortedlist54;
   if (pCounter > 0) {
      sortedlist54 = vars->data[--pCounter];
      sortedlist54->refC++;
      DEBUG_COPY(sortedlist54->id);
   } else {
      sortedlist54 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist54->refC = 1;
      sortedlist54->id = 54;
      sortedlist54->n = 0;
      sortedlist54->root = NULL;
      DEBUG_NEW(sortedlist54->id);
   }
   return sortedlist54;
}

