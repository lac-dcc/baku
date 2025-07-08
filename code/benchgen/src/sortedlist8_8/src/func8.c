#include "sortedlist8_8.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
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
      sortedlist_t* sortedlist30 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist30->id);
      free(params0.data);
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell19 = sortedlist30->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
      }
      sortedlist29->refC--;
      if(sortedlist29->refC == 0){
           cell_t* cell20 = sortedlist29->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist29);
           DEBUG_FREE(sortedlist29->id);
      }
   }
   sortedlist_t* sortedlist45;
   if (pCounter > 0) {
      sortedlist45 = vars->data[--pCounter];
      sortedlist45->refC++;
      DEBUG_COPY(sortedlist45->id);
   } else {
      sortedlist45 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist45->refC = 1;
      sortedlist45->id = 45;
      sortedlist45->n = 0;
      sortedlist45->root = NULL;
      DEBUG_NEW(sortedlist45->id);
   }
   return sortedlist45;
}

