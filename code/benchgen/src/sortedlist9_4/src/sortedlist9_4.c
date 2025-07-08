#include "sortedlist9_4.h"

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
              cell_t* cell15 = sortedlist0->root;
              cell_t* tmp15  = NULL;
              while(cell15 != NULL) {
                  tmp15 = cell15->next;
                  free(cell15);
                  cell15 = tmp15;
              }
              free(sortedlist0);
              DEBUG_FREE(sortedlist0->id);
         }
      }
   }
   else {
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/1 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         sortedlist_t_param params0;
         params0.size = 0;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         sortedlist_t* sortedlist32 = func1(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist32->id);
         free(params0.data);
         sortedlist32->refC--;
         if(sortedlist32->refC == 0){
              cell_t* cell30 = sortedlist32->root;
              cell_t* tmp30  = NULL;
              while(cell30 != NULL) {
                  tmp30 = cell30->next;
                  free(cell30);
                  cell30 = tmp30;
              }
              free(sortedlist32);
              DEBUG_FREE(sortedlist32->id);
         }
      }
   }
   return 0;
}

