#include "sortedlist7_2.h" 
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
   for(; loop4 < loopLimit4; loop4++) {
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
      sortedlist_t_param params0;
      params0.size = 1;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      params0.data[0] = sortedlist29;
      sortedlist_t* sortedlist30 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(sortedlist30->id);
      free(params0.data);
      if(sortedlist30 != NULL && sortedlist30->n > 0) {
           cell_t* cell30 = sortedlist30->root;
           if(sortedlist30->n == 0) {
               sortedlist30->root = (cell_t*)malloc(sizeof(cell_t));
               sortedlist30->root->val  = 2;
               sortedlist30->root->next = NULL;
               sortedlist30->n++;
           } else {
               while(cell30 != NULL)
               {
                   if(cell30->next == NULL && cell30->val < 2) {
                       cell30->next = (cell_t*)malloc(sizeof(cell_t));
                       cell30->next->next = NULL;
                       cell30->next->val  = 2;
                       sortedlist30->n++;
                       break;
                   } else if(2 < cell30->val) {
                       cell_t* tmp30 = cell30->next;
                       cell30->next = (cell_t*)malloc(sizeof(cell_t));
                       cell30->next->next = tmp30;
                       int tmp_val30 = cell30->val;
                       cell30->val = 2;
                       cell30->next->val = tmp_val30;
                       sortedlist30->n++;
                       break;
                   }
                   cell30 = cell30->next;
               }
           }
      }
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell31 = sortedlist30->root;
           cell_t* tmp31  = NULL;
           while(cell31 != NULL) {
               tmp31 = cell31->next;
               free(cell31);
               cell31 = tmp31;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
      }
      sortedlist29->refC--;
      if(sortedlist29->refC == 0){
           cell_t* cell32 = sortedlist29->root;
           cell_t* tmp32  = NULL;
           while(cell32 != NULL) {
               tmp32 = cell32->next;
               free(cell32);
               cell32 = tmp32;
           }
           free(sortedlist29);
           DEBUG_FREE(sortedlist29->id);
      }
   }
   sortedlist_t* sortedlist50;
   if (pCounter > 0) {
      sortedlist50 = vars->data[--pCounter];
      sortedlist50->refC++;
      DEBUG_COPY(sortedlist50->id);
   } else {
      sortedlist50 = (sortedlist_t*)malloc(sizeof(sortedlist_t));
      sortedlist50->refC = 1;
      sortedlist50->id = 50;
      sortedlist50->n = 0;
      sortedlist50->root = NULL;
      DEBUG_NEW(sortedlist50->id);
   }
   return sortedlist50;
}

