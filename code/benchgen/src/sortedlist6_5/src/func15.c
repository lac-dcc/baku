#include "sortedlist6_5.h" 
sortedlist_t* func15(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist18 = func16(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist18->id);
      free(params0.data);
      sortedlist18->refC--;
      if(sortedlist18->refC == 0){
           cell_t* cell10 = sortedlist18->root;
           cell_t* tmp10  = NULL;
           while(cell10 != NULL) {
               tmp10 = cell10->next;
               free(cell10);
               cell10 = tmp10;
           }
           free(sortedlist18);
           DEBUG_FREE(sortedlist18->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist20 = func17(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist20->id);
      free(params0.data);
      sortedlist20->refC--;
      if(sortedlist20->refC == 0){
           cell_t* cell11 = sortedlist20->root;
           cell_t* tmp11  = NULL;
           while(cell11 != NULL) {
               tmp11 = cell11->next;
               free(cell11);
               cell11 = tmp11;
           }
           free(sortedlist20);
           DEBUG_FREE(sortedlist20->id);
      }
   }
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist22 = func18(&params0, get_path(), loopsFactor);
   DEBUG_RETURN(sortedlist22->id);
   free(params0.data);
   return sortedlist22;
}

