#include "sortedlist8_7.h" 
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   sortedlist_t* sortedlist7;
   if (pCounter > 0) {
      sortedlist7 = vars->data[--pCounter];
      sortedlist7->refC++;
      DEBUG_COPY(sortedlist7->id);
   } else {
      sortedlist7 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist7->refC = 1;
      sortedlist7->id = 7;
      sortedlist7->n = 0;
      sortedlist7->root = NULL;
      DEBUG_NEW(sortedlist7->id);
   }
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      if(sortedlist7 != NULL && sortedlist7->n > 0) {
           cell_t* cell3 = sortedlist7->root;
           if(sortedlist7->n == 0) {
               sortedlist7->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist7->root->val  = 92;
               sortedlist7->root->next = NULL;
               sortedlist7->n++;
           } else {
               while(cell3 != NULL)
               {
                   if(cell3->next == NULL && cell3->val < 92) {
                       cell3->next = (cell_t*)malloc(sizeof(cell_t));
                       cell3->next->next = NULL;
                       cell3->next->val  = 92;
                       sortedlist7->n++;
                       break;
                   } else if(92 < cell3->val) {
                       cell_t* tmp3 = cell3->next;
                       cell3->next = (cell_t*)malloc(sizeof(cell_t));
                       cell3->next->next = tmp3;
                       int tmp_val3 = cell3->val;
                       cell3->val = 92;
                       cell3->next->val = tmp_val3;
                       sortedlist7->n++;
                       break;
                   }
                   cell3 = cell3->next;
               }
           }
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist7;
      sortedlist_t* sortedlist8 = func4(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist8->id);
      free(params0.data);
      sortedlist8->refC--;
      if(sortedlist8->refC == 0){
           cell_t* cell12 = sortedlist8->root;
           cell_t* tmp12  = NULL;
           while(cell12 != NULL) {
               tmp12 = cell12->next;
               free(cell12);
               cell12 = tmp12;
           }
           free(sortedlist8);
           DEBUG_FREE(sortedlist8->id);
      }
   }
   return sortedlist7;
}

