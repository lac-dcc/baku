#include "sortedlist5_4.h"

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
      unsigned int loop0 = 0;
      unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
      for(; loop0 < loopLimit0; loop0++) {
         sortedlist_t_param params0;
         params0.size = 0;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         sortedlist_t* sortedlist0 = func0(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist0->id);
         free(params0.data);
         sortedlist0->refC--;
         if(sortedlist0->refC == 0){
              cell_t* cell9 = sortedlist0->root;
              cell_t* tmp9  = NULL;
              while(cell9 != NULL) {
                  tmp9 = cell9->next;
                  free(cell9);
                  cell9 = tmp9;
              }
              free(sortedlist0);
              DEBUG_FREE(sortedlist0->id);
         }
      }
   }
   else {
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
      for(; loop4 < loopLimit4; loop4++) {
         sortedlist_t_param params0;
         params0.size = 0;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         sortedlist_t* sortedlist20 = func1(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist20->id);
         free(params0.data);
         sortedlist20->refC--;
         if(sortedlist20->refC == 0){
              cell_t* cell18 = sortedlist20->root;
              cell_t* tmp18  = NULL;
              while(cell18 != NULL) {
                  tmp18 = cell18->next;
                  free(cell18);
                  cell18 = tmp18;
              }
              free(sortedlist20);
              DEBUG_FREE(sortedlist20->id);
         }
      }
   }
   return 0;
}

