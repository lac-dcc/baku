#include "sortedlist8_2.h" 
sortedlist_t* func16(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      sortedlist_t* sortedlist45;
      if (pCounter > 0) {
         sortedlist45 = vars->data[--pCounter];
         sortedlist45->refC++;
         DEBUG_COPY(sortedlist45->id);
      } else {
         sortedlist45 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist45->refC = 1;
         sortedlist45->id = 45;
         sortedlist45->n = 0;
         sortedlist45->root = NULL;
         DEBUG_NEW(sortedlist45->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist45;
      sortedlist_t* sortedlist46 = func20(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist46->id);
      free(params0.data);
      if(sortedlist46 != NULL && sortedlist46->n > 0) {
           cell_t* cell27 = sortedlist46->root;
           if(sortedlist46->n == 0) {
               sortedlist46->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist46->root->val  = 67;
               sortedlist46->root->next = NULL;
               sortedlist46->n++;
           } else {
               while(cell27 != NULL)
               {
                   if(cell27->next == NULL && cell27->val < 67) {
                       cell27->next = (cell_t*)malloc(sizeof(cell_t));
                       cell27->next->next = NULL;
                       cell27->next->val  = 67;
                       sortedlist46->n++;
                       break;
                   } else if(67 < cell27->val) {
                       cell_t* tmp27 = cell27->next;
                       cell27->next = (cell_t*)malloc(sizeof(cell_t));
                       cell27->next->next = tmp27;
                       int tmp_val27 = cell27->val;
                       cell27->val = 67;
                       cell27->next->val = tmp_val27;
                       sortedlist46->n++;
                       break;
                   }
                   cell27 = cell27->next;
               }
           }
      }
      sortedlist46->refC--;
      if(sortedlist46->refC == 0){
           cell_t* cell28 = sortedlist46->root;
           cell_t* tmp28  = NULL;
           while(cell28 != NULL) {
               tmp28 = cell28->next;
               free(cell28);
               cell28 = tmp28;
           }
           free(sortedlist46);
           DEBUG_FREE(sortedlist46->id);
      }
      sortedlist45->refC--;
      if(sortedlist45->refC == 0){
           cell_t* cell29 = sortedlist45->root;
           cell_t* tmp29  = NULL;
           while(cell29 != NULL) {
               tmp29 = cell29->next;
               free(cell29);
               cell29 = tmp29;
           }
           free(sortedlist45);
           DEBUG_FREE(sortedlist45->id);
      }
   }
   sortedlist_t* sortedlist53;
   if (pCounter > 0) {
      sortedlist53 = vars->data[--pCounter];
      sortedlist53->refC++;
      DEBUG_COPY(sortedlist53->id);
   } else {
      sortedlist53 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist53->refC = 1;
      sortedlist53->id = 53;
      sortedlist53->n = 0;
      sortedlist53->root = NULL;
      DEBUG_NEW(sortedlist53->id);
   }
   return sortedlist53;
}

