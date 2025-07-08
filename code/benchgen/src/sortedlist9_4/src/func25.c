#include "sortedlist9_4.h" 
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist57;
   if (pCounter > 0) {
      sortedlist57 = vars->data[--pCounter];
      sortedlist57->refC++;
      DEBUG_COPY(sortedlist57->id);
   } else {
      sortedlist57 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist57->refC = 1;
      sortedlist57->id = 57;
      sortedlist57->n = 0;
      sortedlist57->root = NULL;
      DEBUG_NEW(sortedlist57->id);
   }
   unsigned int loop12 = 0;
   unsigned int loopLimit12 = (rand()%loopsFactor)/6 + 1;
   for(; loop12 < loopLimit12; loop12++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist57;
      sortedlist_t* sortedlist58 = func30(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist58->id);
      free(params0.data);
      sortedlist58->refC--;
      if(sortedlist58->refC == 0){
           cell_t* cell23 = sortedlist58->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist58);
           DEBUG_FREE(sortedlist58->id);
      }
   }
   return sortedlist57;
}

