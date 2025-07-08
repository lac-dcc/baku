#include "sortedlist8_2.h" 
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      sortedlist_t* sortedlist6;
      if (pCounter > 0) {
         sortedlist6 = vars->data[--pCounter];
         sortedlist6->refC++;
         DEBUG_COPY(sortedlist6->id);
      } else {
         sortedlist6 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist6->refC = 1;
         sortedlist6->id = 6;
         sortedlist6->n = 0;
         sortedlist6->root = NULL;
         DEBUG_NEW(sortedlist6->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist6;
      sortedlist_t* sortedlist7 = func11(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist7->id);
      free(params0.data);
      if(sortedlist7 != NULL && sortedlist7->n > 0) {
           cell_t* cell13 = sortedlist7->root;
           if(sortedlist7->n == 0) {
               sortedlist7->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist7->root->val  = 26;
               sortedlist7->root->next = NULL;
               sortedlist7->n++;
           } else {
               while(cell13 != NULL)
               {
                   if(cell13->next == NULL && cell13->val < 26) {
                       cell13->next = (cell_t*)malloc(sizeof(cell_t));
                       cell13->next->next = NULL;
                       cell13->next->val  = 26;
                       sortedlist7->n++;
                       break;
                   } else if(26 < cell13->val) {
                       cell_t* tmp13 = cell13->next;
                       cell13->next = (cell_t*)malloc(sizeof(cell_t));
                       cell13->next->next = tmp13;
                       int tmp_val13 = cell13->val;
                       cell13->val = 26;
                       cell13->next->val = tmp_val13;
                       sortedlist7->n++;
                       break;
                   }
                   cell13 = cell13->next;
               }
           }
      }
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell14 = sortedlist7->root;
           cell_t* tmp14  = NULL;
           while(cell14 != NULL) {
               tmp14 = cell14->next;
               free(cell14);
               cell14 = tmp14;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
      sortedlist6->refC--;
      if(sortedlist6->refC == 0){
           cell_t* cell15 = sortedlist6->root;
           cell_t* tmp15  = NULL;
           while(cell15 != NULL) {
               tmp15 = cell15->next;
               free(cell15);
               cell15 = tmp15;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
   }
   sortedlist_t* sortedlist27;
   if (pCounter > 0) {
      sortedlist27 = vars->data[--pCounter];
      sortedlist27->refC++;
      DEBUG_COPY(sortedlist27->id);
   } else {
      sortedlist27 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist27->refC = 1;
      sortedlist27->id = 27;
      sortedlist27->n = 0;
      sortedlist27->root = NULL;
      DEBUG_NEW(sortedlist27->id);
   }
   return sortedlist27;
}

