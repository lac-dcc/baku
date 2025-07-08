#include "sortedlist7_2.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist39;
      sortedlist_t* sortedlist40 = func20(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist40->id);
      free(params0.data);
      if(sortedlist40 != NULL && sortedlist40->n > 0) {
           cell_t* cell22 = sortedlist40->root;
           if(sortedlist40->n == 0) {
               sortedlist40->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist40->root->val  = 29;
               sortedlist40->root->next = NULL;
               sortedlist40->n++;
           } else {
               while(cell22 != NULL)
               {
                   if(cell22->next == NULL && cell22->val < 29) {
                       cell22->next = (cell_t*)malloc(sizeof(cell_t));
                       cell22->next->next = NULL;
                       cell22->next->val  = 29;
                       sortedlist40->n++;
                       break;
                   } else if(29 < cell22->val) {
                       cell_t* tmp22 = cell22->next;
                       cell22->next = (cell_t*)malloc(sizeof(cell_t));
                       cell22->next->next = tmp22;
                       int tmp_val22 = cell22->val;
                       cell22->val = 29;
                       cell22->next->val = tmp_val22;
                       sortedlist40->n++;
                       break;
                   }
                   cell22 = cell22->next;
               }
           }
      }
      sortedlist40->refC--;
      if(sortedlist40->refC == 0){
           cell_t* cell23 = sortedlist40->root;
           cell_t* tmp23  = NULL;
           while(cell23 != NULL) {
               tmp23 = cell23->next;
               free(cell23);
               cell23 = tmp23;
           }
           free(sortedlist40);
           DEBUG_FREE(sortedlist40->id);
      }
      sortedlist39->refC--;
      if(sortedlist39->refC == 0){
           cell_t* cell24 = sortedlist39->root;
           cell_t* tmp24  = NULL;
           while(cell24 != NULL) {
               tmp24 = cell24->next;
               free(cell24);
               cell24 = tmp24;
           }
           free(sortedlist39);
           DEBUG_FREE(sortedlist39->id);
      }
   }
   sortedlist_t* sortedlist46;
   if (pCounter > 0) {
      sortedlist46 = vars->data[--pCounter];
      sortedlist46->refC++;
      DEBUG_COPY(sortedlist46->id);
   } else {
      sortedlist46 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist46->refC = 1;
      sortedlist46->id = 46;
      sortedlist46->n = 0;
      sortedlist46->root = NULL;
      DEBUG_NEW(sortedlist46->id);
   }
   return sortedlist46;
}

