#include "sortedlist10_2.h" 
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
      if(sortedlist6 != NULL && sortedlist6->n > 0) {
           cell_t* cell18 = sortedlist6->root;
           if(sortedlist6->n == 0) {
               sortedlist6->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist6->root->val  = 11;
               sortedlist6->root->next = NULL;
               sortedlist6->n++;
           } else {
               while(cell18 != NULL)
               {
                   if(cell18->next == NULL && cell18->val < 11) {
                       cell18->next = (cell_t*)malloc(sizeof(cell_t));
                       cell18->next->next = NULL;
                       cell18->next->val  = 11;
                       sortedlist6->n++;
                       break;
                   } else if(11 < cell18->val) {
                       cell_t* tmp18 = cell18->next;
                       cell18->next = (cell_t*)malloc(sizeof(cell_t));
                       cell18->next->next = tmp18;
                       int tmp_val18 = cell18->val;
                       cell18->val = 11;
                       cell18->next->val = tmp_val18;
                       sortedlist6->n++;
                       break;
                   }
                   cell18 = cell18->next;
               }
           }
      }
      sortedlist7->refC--;
      if(sortedlist7->refC == 0){
           cell_t* cell19 = sortedlist7->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist7);
           DEBUG_FREE(sortedlist7->id);
      }
      sortedlist6->refC--;
      if(sortedlist6->refC == 0){
           cell_t* cell20 = sortedlist6->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist6);
           DEBUG_FREE(sortedlist6->id);
      }
   }
   sortedlist_t* sortedlist34;
   if (pCounter > 0) {
      sortedlist34 = vars->data[--pCounter];
      sortedlist34->refC++;
      DEBUG_COPY(sortedlist34->id);
   } else {
      sortedlist34 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist34->refC = 1;
      sortedlist34->id = 34;
      sortedlist34->n = 0;
      sortedlist34->root = NULL;
      DEBUG_NEW(sortedlist34->id);
   }
   return sortedlist34;
}

