#include "sortedlist6_2.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      sortedlist_t* sortedlist28;
      if (pCounter > 0) {
         sortedlist28 = vars->data[--pCounter];
         sortedlist28->refC++;
         DEBUG_COPY(sortedlist28->id);
      } else {
         sortedlist28 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist28->refC = 1;
         sortedlist28->id = 28;
         sortedlist28->n = 0;
         sortedlist28->root = NULL;
         DEBUG_NEW(sortedlist28->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist28;
      sortedlist_t* sortedlist29 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist29->id);
      free(params0.data);
      if(sortedlist28 != NULL && sortedlist28->n > 0) {
           cell_t* cell25 = sortedlist28->root;
           if(sortedlist28->n == 0) {
               sortedlist28->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist28->root->val  = 62;
               sortedlist28->root->next = NULL;
               sortedlist28->n++;
           } else {
               while(cell25 != NULL)
               {
                   if(cell25->next == NULL && cell25->val < 62) {
                       cell25->next = (cell_t*)malloc(sizeof(cell_t));
                       cell25->next->next = NULL;
                       cell25->next->val  = 62;
                       sortedlist28->n++;
                       break;
                   } else if(62 < cell25->val) {
                       cell_t* tmp25 = cell25->next;
                       cell25->next = (cell_t*)malloc(sizeof(cell_t));
                       cell25->next->next = tmp25;
                       int tmp_val25 = cell25->val;
                       cell25->val = 62;
                       cell25->next->val = tmp_val25;
                       sortedlist28->n++;
                       break;
                   }
                   cell25 = cell25->next;
               }
           }
      }
      sortedlist29->refC--;
      if(sortedlist29->refC == 0){
           cell_t* cell26 = sortedlist29->root;
           cell_t* tmp26  = NULL;
           while(cell26 != NULL) {
               tmp26 = cell26->next;
               free(cell26);
               cell26 = tmp26;
           }
           free(sortedlist29);
           DEBUG_FREE(sortedlist29->id);
      }
      sortedlist28->refC--;
      if(sortedlist28->refC == 0){
           cell_t* cell27 = sortedlist28->root;
           cell_t* tmp27  = NULL;
           while(cell27 != NULL) {
               tmp27 = cell27->next;
               free(cell27);
               cell27 = tmp27;
           }
           free(sortedlist28);
           DEBUG_FREE(sortedlist28->id);
      }
   }
   sortedlist_t* sortedlist43;
   if (pCounter > 0) {
      sortedlist43 = vars->data[--pCounter];
      sortedlist43->refC++;
      DEBUG_COPY(sortedlist43->id);
   } else {
      sortedlist43 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist43->refC = 1;
      sortedlist43->id = 43;
      sortedlist43->n = 0;
      sortedlist43->root = NULL;
      DEBUG_NEW(sortedlist43->id);
   }
   return sortedlist43;
}

