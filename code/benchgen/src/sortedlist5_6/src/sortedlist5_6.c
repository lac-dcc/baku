#include "sortedlist5_6.h"

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
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      if(get_path() & 1) {
         sortedlist_t_param params0;
         params0.size = 0;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         sortedlist_t* sortedlist0 = func0(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist0->id);
         free(params0.data);
         sortedlist0->refC--;
         if(sortedlist0->refC == 0){
              cell_t* cell4 = sortedlist0->root;
              cell_t* tmp4  = NULL;
              while(cell4 != NULL) {
                  tmp4 = cell4->next;
                  free(cell4);
                  cell4 = tmp4;
              }
              free(sortedlist0);
              DEBUG_FREE(sortedlist0->id);
         }
      }
      else {
         unsigned int loop2 = 0;
         unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
         for(; loop2 < loopLimit2; loop2++) {
            sortedlist_t_param params0;
            params0.size = 0;
            params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
            sortedlist_t* sortedlist9 = func1(&params0, loopsFactor);
            DEBUG_RETURN(sortedlist9->id);
            free(params0.data);
            sortedlist9->refC--;
            if(sortedlist9->refC == 0){
                 cell_t* cell7 = sortedlist9->root;
                 cell_t* tmp7  = NULL;
                 while(cell7 != NULL) {
                     tmp7 = cell7->next;
                     free(cell7);
                     cell7 = tmp7;
                 }
                 free(sortedlist9);
                 DEBUG_FREE(sortedlist9->id);
            }
         }
      }
   }
   return 0;
}

