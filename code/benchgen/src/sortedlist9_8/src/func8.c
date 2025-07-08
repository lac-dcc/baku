#include "sortedlist9_8.h" 
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t* sortedlist30;
      if (pCounter > 0) {
         sortedlist30 = vars->data[--pCounter];
         sortedlist30->refC++;
         DEBUG_COPY(sortedlist30->id);
      } else {
         sortedlist30 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist30->refC = 1;
         sortedlist30->id = 30;
         sortedlist30->n = 0;
         sortedlist30->root = NULL;
         DEBUG_NEW(sortedlist30->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist30;
      sortedlist_t* sortedlist31 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist31->id);
      free(params0.data);
      sortedlist31->refC--;
      if(sortedlist31->refC == 0){
           cell_t* cell20 = sortedlist31->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist31);
           DEBUG_FREE(sortedlist31->id);
      }
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell21 = sortedlist30->root;
           cell_t* tmp21  = NULL;
           while(cell21 != NULL) {
               tmp21 = cell21->next;
               free(cell21);
               cell21 = tmp21;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
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

