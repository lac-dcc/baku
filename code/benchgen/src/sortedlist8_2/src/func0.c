#include "sortedlist8_2.h" 
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      sortedlist_t* sortedlist1;
      if (pCounter > 0) {
         sortedlist1 = vars->data[--pCounter];
         sortedlist1->refC++;
         DEBUG_COPY(sortedlist1->id);
      } else {
         sortedlist1 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist1->refC = 1;
         sortedlist1->id = 1;
         sortedlist1->n = 0;
         sortedlist1->root = NULL;
         DEBUG_NEW(sortedlist1->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist1;
      sortedlist_t* sortedlist2 = func5(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist2->id);
      free(params0.data);
      if(sortedlist1 != NULL && sortedlist1->n > 0) {
           cell_t* cell17 = sortedlist1->root;
           if(sortedlist1->n == 0) {
               sortedlist1->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist1->root->val  = 36;
               sortedlist1->root->next = NULL;
               sortedlist1->n++;
           } else {
               while(cell17 != NULL)
               {
                   if(cell17->next == NULL && cell17->val < 36) {
                       cell17->next = (cell_t*)malloc(sizeof(cell_t));
                       cell17->next->next = NULL;
                       cell17->next->val  = 36;
                       sortedlist1->n++;
                       break;
                   } else if(36 < cell17->val) {
                       cell_t* tmp17 = cell17->next;
                       cell17->next = (cell_t*)malloc(sizeof(cell_t));
                       cell17->next->next = tmp17;
                       int tmp_val17 = cell17->val;
                       cell17->val = 36;
                       cell17->next->val = tmp_val17;
                       sortedlist1->n++;
                       break;
                   }
                   cell17 = cell17->next;
               }
           }
      }
      sortedlist2->refC--;
      if(sortedlist2->refC == 0){
           cell_t* cell18 = sortedlist2->root;
           cell_t* tmp18  = NULL;
           while(cell18 != NULL) {
               tmp18 = cell18->next;
               free(cell18);
               cell18 = tmp18;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell19 = sortedlist1->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
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
   return sortedlist29;
}

