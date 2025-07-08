#include "sortedlist10_8.h"

int main(int argc, char** argv) {
   int loopsFactor = 100;
   srand(0);
   for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-path-seed") == 0) {
         i++;
         if (i < argc) {
            srand(atoi(argv[i]));
         }
      }
      else if (strcmp(argv[i], "-loops-factor") == 0) {
         i++;
         if (i < argc) {
            loopsFactor = atoi(argv[i]);
         }
      }
   }
   if(get_path() & 1) {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist0 = func0(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist0->id);
      free(params0.data);
      sortedlist0->refC--;
      if(sortedlist0->refC == 0){
           cell_t* cell13 = sortedlist0->root;
           cell_t* tmp13  = NULL;
           while(cell13 != NULL) {
               tmp13 = cell13->next;
               free(cell13);
               cell13 = tmp13;
           }
           free(sortedlist0);
           DEBUG_FREE(sortedlist0->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist27 = func1(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist27->id);
      free(params0.data);
      sortedlist27->refC--;
      if(sortedlist27->refC == 0){
           cell_t* cell28 = sortedlist27->root;
           cell_t* tmp28  = NULL;
           while(cell28 != NULL) {
               tmp28 = cell28->next;
               free(cell28);
               cell28 = tmp28;
           }
           free(sortedlist27);
           DEBUG_FREE(sortedlist27->id);
      }
   }
   return 0;
}

