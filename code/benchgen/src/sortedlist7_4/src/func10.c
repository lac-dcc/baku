#include "sortedlist7_4.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      sortedlist_t* sortedlist32;
      if (pCounter > 0) {
         sortedlist32 = vars->data[--pCounter];
         sortedlist32->refC++;
         DEBUG_COPY(sortedlist32->id);
      } else {
         sortedlist32 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist32->refC = 1;
         sortedlist32->id = 32;
         sortedlist32->n = 0;
         sortedlist32->root = NULL;
         DEBUG_NEW(sortedlist32->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist32;
      sortedlist_t* sortedlist33 = func12(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist33->id);
      free(params0.data);
      sortedlist33->refC--;
      if(sortedlist33->refC == 0){
           cell_t* cell21 = sortedlist33->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist33);
           DEBUG_FREE(sortedlist33->id);
      }
      sortedlist32->refC--;
      if(sortedlist32->refC == 0){
           cell_t* cell22 = sortedlist32->root;
           cell_t* tmp22  = NULL;
           while(cell22 != NULL) {
               tmp22 = cell22->next;
               free(cell22);
               cell22 = tmp22;
           }
           free(sortedlist32);
           DEBUG_FREE(sortedlist32->id);
      }
   }
   sortedlist_t* sortedlist50;
   if (pCounter > 0) {
      sortedlist50 = vars->data[--pCounter];
      sortedlist50->refC++;
      DEBUG_COPY(sortedlist50->id);
   } else {
      sortedlist50 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist50->refC = 1;
      sortedlist50->id = 50;
      sortedlist50->n = 0;
      sortedlist50->root = NULL;
      DEBUG_NEW(sortedlist50->id);
   }
   return sortedlist50;
}

