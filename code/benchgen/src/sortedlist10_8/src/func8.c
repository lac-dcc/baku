#include "sortedlist10_8.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      sortedlist_t* sortedlist31;
      if (pCounter > 0) {
         sortedlist31 = vars->data[--pCounter];
         sortedlist31->refC++;
         DEBUG_COPY(sortedlist31->id);
      } else {
         sortedlist31 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist31->refC = 1;
         sortedlist31->id = 31;
         sortedlist31->n = 0;
         sortedlist31->root = NULL;
         DEBUG_NEW(sortedlist31->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist31;
      sortedlist_t* sortedlist32 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist32->id);
      free(params0.data);
      sortedlist32->refC--;
      if(sortedlist32->refC == 0){
           cell_t* cell24 = sortedlist32->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist32);
           DEBUG_FREE(sortedlist32->id);
      }
      sortedlist31->refC--;
      if(sortedlist31->refC == 0){
           cell_t* cell25 = sortedlist31->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist31);
           DEBUG_FREE(sortedlist31->id);
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

