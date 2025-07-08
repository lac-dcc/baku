#include "sortedlist5_4.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      sortedlist_t* sortedlist29;
      if (pCounter > 0) {
         sortedlist29 = vars->data[--pCounter];
         sortedlist29->refC++;
         DEBUG_COPY(sortedlist29->id);
      } else {
         sortedlist29 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist29->refC = 1;
         sortedlist29->id = 29;
         sortedlist29->n = 0;
         sortedlist29->root = NULL;
         DEBUG_NEW(sortedlist29->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist29;
      sortedlist_t* sortedlist30 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist30->id);
      free(params0.data);
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell15 = sortedlist30->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
      }
      sortedlist29->refC--;
      if(sortedlist29->refC == 0){
           cell_t* cell16 = sortedlist29->root;
           cell_t* tmp16  = NULL;
           while(cell16 != NULL) {
               tmp16 = cell16->next;
               free(cell16);
               cell16 = tmp16;
           }
           free(sortedlist29);
           DEBUG_FREE(sortedlist29->id);
      }
   }
   sortedlist_t* sortedlist39;
   if (pCounter > 0) {
      sortedlist39 = vars->data[--pCounter];
      sortedlist39->refC++;
      DEBUG_COPY(sortedlist39->id);
   } else {
      sortedlist39 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist39->refC = 1;
      sortedlist39->id = 39;
      sortedlist39->n = 0;
      sortedlist39->root = NULL;
      DEBUG_NEW(sortedlist39->id);
   }
   return sortedlist39;
}

