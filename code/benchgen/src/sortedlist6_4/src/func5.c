#include "sortedlist6_4.h" 
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist29;
      sortedlist_t* sortedlist30 = func10(&params0, loopsFactor);
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
   }
   return sortedlist29;
}

