#include "sortedlist5_2.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist27;
      sortedlist_t* sortedlist28 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist28->id);
      free(params0.data);
      if(sortedlist27 != NULL && sortedlist27->n > 0) {
           cell_t* cell16 = sortedlist27->root;
           if(sortedlist27->n == 0) {
               sortedlist27->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist27->root->val  = 26;
               sortedlist27->root->next = NULL;
               sortedlist27->n++;
           } else {
               while(cell16 != NULL)
               {
                   if(cell16->next == NULL && cell16->val < 26) {
                       cell16->next = (cell_t*)malloc(sizeof(cell_t));
                       cell16->next->next = NULL;
                       cell16->next->val  = 26;
                       sortedlist27->n++;
                       break;
                   } else if(26 < cell16->val) {
                       cell_t* tmp16 = cell16->next;
                       cell16->next = (cell_t*)malloc(sizeof(cell_t));
                       cell16->next->next = tmp16;
                       int tmp_val16 = cell16->val;
                       cell16->val = 26;
                       cell16->next->val = tmp_val16;
                       sortedlist27->n++;
                       break;
                   }
                   cell16 = cell16->next;
               }
           }
      }
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell17 = sortedlist28->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
      sortedlist27->refC--;
      if(sortedlist27->refC == 0){
           cell_t* cell18 = sortedlist27->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist27);
           DEBUG_FREE(sortedlist27->id);
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

