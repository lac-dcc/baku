#include "sortedlist7_2.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist34;
      sortedlist_t* sortedlist35 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist35->id);
      free(params0.data);
      if(sortedlist34 != NULL && sortedlist34->n > 0) {
           cell_t* cell26 = sortedlist34->root;
           if(sortedlist34->n == 0) {
               sortedlist34->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist34->root->val  = 23;
               sortedlist34->root->next = NULL;
               sortedlist34->n++;
           } else {
               while(cell26 != NULL)
               {
                   if(cell26->next == NULL && cell26->val < 23) {
                       cell26->next = (cell_t*)malloc(sizeof(cell_t));
                       cell26->next->next = NULL;
                       cell26->next->val  = 23;
                       sortedlist34->n++;
                       break;
                   } else if(23 < cell26->val) {
                       cell_t* tmp26 = cell26->next;
                       cell26->next = (cell_t*)malloc(sizeof(cell_t));
                       cell26->next->next = tmp26;
                       int tmp_val26 = cell26->val;
                       cell26->val = 23;
                       cell26->next->val = tmp_val26;
                       sortedlist34->n++;
                       break;
                   }
                   cell26 = cell26->next;
               }
           }
      }
      sortedlist35->refC--;
      if(sortedlist35->refC == 0){
           cell_t* cell27 = sortedlist35->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist35);
           DEBUG_FREE(sortedlist35->id);
      }
      sortedlist34->refC--;
      if(sortedlist34->refC == 0){
           cell_t* cell28 = sortedlist34->root;
           cell_t* tmp28  = NULL;
           while(cell28 != NULL) {
               tmp28 = cell28->next;
               free(cell28);
               cell28 = tmp28;
           }
           free(sortedlist34);
           DEBUG_FREE(sortedlist34->id);
      }
   }
   sortedlist_t* sortedlist48;
   if (pCounter > 0) {
      sortedlist48 = vars->data[--pCounter];
      sortedlist48->refC++;
      DEBUG_COPY(sortedlist48->id);
   } else {
      sortedlist48 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist48->refC = 1;
      sortedlist48->id = 48;
      sortedlist48->n = 0;
      sortedlist48->root = NULL;
      DEBUG_NEW(sortedlist48->id);
   }
   return sortedlist48;
}

