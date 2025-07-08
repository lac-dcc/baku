#include "sortedlist10_2.h" 
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      sortedlist_t* sortedlist47;
      if (pCounter > 0) {
         sortedlist47 = vars->data[--pCounter];
         sortedlist47->refC++;
         DEBUG_COPY(sortedlist47->id);
      } else {
         sortedlist47 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
         sortedlist47->refC = 1;
         sortedlist47->id = 47;
         sortedlist47->n = 0;
         sortedlist47->root = NULL;
         DEBUG_NEW(sortedlist47->id);
      }
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist47;
      sortedlist_t* sortedlist48 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist48->id);
      free(params0.data);
      if(sortedlist48 != NULL && sortedlist48->n > 0) {
           cell_t* cell41 = sortedlist48->root;
           if(sortedlist48->n == 0) {
               sortedlist48->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist48->root->val  = 21;
               sortedlist48->root->next = NULL;
               sortedlist48->n++;
           } else {
               while(cell41 != NULL)
               {
                   if(cell41->next == NULL && cell41->val < 21) {
                       cell41->next = (cell_t*)malloc(sizeof(cell_t));
                       cell41->next->next = NULL;
                       cell41->next->val  = 21;
                       sortedlist48->n++;
                       break;
                   } else if(21 < cell41->val) {
                       cell_t* tmp41 = cell41->next;
                       cell41->next = (cell_t*)malloc(sizeof(cell_t));
                       cell41->next->next = tmp41;
                       int tmp_val41 = cell41->val;
                       cell41->val = 21;
                       cell41->next->val = tmp_val41;
                       sortedlist48->n++;
                       break;
                   }
                   cell41 = cell41->next;
               }
           }
      }
      sortedlist48->refC--;
      if(sortedlist48->refC == 0){
           cell_t* cell42 = sortedlist48->root;
           cell_t* tmp42  = NULL;
           while(cell42 != NULL) {
               tmp42 = cell42->next;
               free(cell42);
               cell42 = tmp42;
           }
           free(sortedlist48);
           DEBUG_FREE(sortedlist48->id);
      }
      sortedlist47->refC--;
      if(sortedlist47->refC == 0){
           cell_t* cell43 = sortedlist47->root;
           cell_t* tmp43  = NULL;
           while(cell43 != NULL) {
               tmp43 = cell43->next;
               free(cell43);
               cell43 = tmp43;
           }
           free(sortedlist47);
           DEBUG_FREE(sortedlist47->id);
      }
   }
   sortedlist_t* sortedlist69;
   if (pCounter > 0) {
      sortedlist69 = vars->data[--pCounter];
      sortedlist69->refC++;
      DEBUG_COPY(sortedlist69->id);
   } else {
      sortedlist69 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist69->refC = 1;
      sortedlist69->id = 69;
      sortedlist69->n = 0;
      sortedlist69->root = NULL;
      DEBUG_NEW(sortedlist69->id);
   }
   return sortedlist69;
}

