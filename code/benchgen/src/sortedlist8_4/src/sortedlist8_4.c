#include "sortedlist8_4.h"

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
              cell_t* cell14 = sortedlist0->root;
              cell_t* tmp14  = NULL;
              while(cell14 != NULL) {
                  tmp14 = cell14->next;
                  free(cell14);
                  cell14 = tmp14;
              }
              free(sortedlist0);
              DEBUG_FREE(sortedlist0->id);
         }
      }
   }
   else {
      unsigned int loop6 = 0;
      unsigned int loopLimit6 = (rand()%loopsFactor)/1 + 1;
      for(; loop6 < loopLimit6; loop6++) {
         sortedlist_t_param params0;
         params0.size = 0;
         params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
         sortedlist_t* sortedlist30 = func1(&params0, loopsFactor);
         DEBUG_RETURN(sortedlist30->id);
         free(params0.data);
         sortedlist30->refC--;
         if(sortedlist30->refC == 0){
              cell_t* cell28 = sortedlist30->root;
              cell_t* tmp28  = NULL;
              while(cell28 != NULL) {
                  tmp28 = cell28->next;
                  free(cell28);
                  cell28 = tmp28;
              }
              free(sortedlist30);
              DEBUG_FREE(sortedlist30->id);
         }
      }
   }
   return 0;
}

