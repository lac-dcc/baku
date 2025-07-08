#include "sortedlist6_4.h"

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
              cell_t* cell10 = sortedlist0->root;
              cell_t* tmp10  = NULL;
              while(cell10 != NULL) {
                  tmp10 = cell10->next;
                  free(cell10);
                  cell10 = tmp10;
              }
              free(sortedlist0);
              DEBUG_FREE(sortedlist0->id);
         }
      }
   }
   else {
      unsigned int loop5 = 0;
      unsigned int loopLimit5 = (rand()%loopsFactor)/1 + 1;
      for(; loop5 < loopLimit5; loop5++) {
         sortedlist_t_param params0;
         params0.size = 0;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         sortedlist_t* sortedlist22 = func1(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist22->id);
         free(params0.data);
         sortedlist22->refC--;
         if(sortedlist22->refC == 0){
              cell_t* cell20 = sortedlist22->root;
              cell_t* tmp20  = NULL;
              while(cell20 != NULL) {
                  tmp20 = cell20->next;
                  free(cell20);
                  cell20 = tmp20;
              }
              free(sortedlist22);
              DEBUG_FREE(sortedlist22->id);
         }
      }
   }
   return 0;
}

