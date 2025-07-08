#include "sortedlist6_2.h" 
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist25 = func3(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist25->id);
      free(params0.data);
      sortedlist25->refC--;
      if(sortedlist25->refC == 0){
           cell_t* cell16 = sortedlist25->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist25);
           DEBUG_FREE(sortedlist25->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist27 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist27->id);
      free(params0.data);
      sortedlist27->refC--;
      if(sortedlist27->refC == 0){
           cell_t* cell28 = sortedlist27->root;
           cell_t* tmp28  = NULL;
           while(cell28 != NULL) {
               tmp28 = cell28->next;
               free(cell28);
               cell28 = tmp28;
           }
           free(sortedlist27);
           DEBUG_FREE(sortedlist27->id);
      }
   }
   sortedlist_t* sortedlist44;
   if (pCounter > 0) {
      sortedlist44 = vars->data[--pCounter];
      sortedlist44->refC++;
      DEBUG_COPY(sortedlist44->id);
   } else {
      sortedlist44 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist44->refC = 1;
      sortedlist44->id = 44;
      sortedlist44->n = 0;
      sortedlist44->root = NULL;
      DEBUG_NEW(sortedlist44->id);
   }
   return sortedlist44;
}

