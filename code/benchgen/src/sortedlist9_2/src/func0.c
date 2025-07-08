#include "sortedlist9_2.h" 
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
           cell_t* cell18 = sortedlist1->root;
           if(sortedlist1->n == 0) {
               sortedlist1->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist1->root->val  = 36;
               sortedlist1->root->next = NULL;
               sortedlist1->n++;
           } else {
               while(cell18 != NULL)
               {
                   if(cell18->next == NULL && cell18->val < 36) {
                       cell18->next = (cell_t*)malloc(sizeof(cell_t));
                       cell18->next->next = NULL;
                       cell18->next->val  = 36;
                       sortedlist1->n++;
                       break;
                   } else if(36 < cell18->val) {
                       cell_t* tmp18 = cell18->next;
                       cell18->next = (cell_t*)malloc(sizeof(cell_t));
                       cell18->next->next = tmp18;
                       int tmp_val18 = cell18->val;
                       cell18->val = 36;
                       cell18->next->val = tmp_val18;
                       sortedlist1->n++;
                       break;
                   }
                   cell18 = cell18->next;
               }
           }
      }
      sortedlist2->refC--;
      if(sortedlist2->refC == 0){
           cell_t* cell19 = sortedlist2->root;
           cell_t* tmp19  = NULL;
           while(cell19 != NULL) {
               tmp19 = cell19->next;
               free(cell19);
               cell19 = tmp19;
           }
           free(sortedlist2);
           DEBUG_FREE(sortedlist2->id);
      }
      sortedlist1->refC--;
      if(sortedlist1->refC == 0){
           cell_t* cell20 = sortedlist1->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist1);
           DEBUG_FREE(sortedlist1->id);
      }
   }
   sortedlist_t* sortedlist30;
   if (pCounter > 0) {
      sortedlist30 = vars->data[--pCounter];
      sortedlist30->refC++;
      DEBUG_COPY(sortedlist30->id);
   } else {
      sortedlist30 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist30->refC = 1;
      sortedlist30->id = 30;
      sortedlist30->n = 0;
      sortedlist30->root = NULL;
      DEBUG_NEW(sortedlist30->id);
   }
   return sortedlist30;
}

