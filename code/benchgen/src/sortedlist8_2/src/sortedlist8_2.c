#include "sortedlist8_2.h"

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
           cell_t* cell20 = sortedlist0->root;
           cell_t* tmp20  = NULL;
           while(cell20 != NULL) {
               tmp20 = cell20->next;
               free(cell20);
               cell20 = tmp20;
           }
           free(sortedlist0);
           DEBUG_FREE(sortedlist0->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist30 = func1(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist30->id);
      free(params0.data);
      sortedlist30->refC--;
      if(sortedlist30->refC == 0){
           cell_t* cell39 = sortedlist30->root;
           cell_t* tmp39  = NULL;
           while(cell39 != NULL) {
               tmp39 = cell39->next;
               free(cell39);
               cell39 = tmp39;
           }
           free(sortedlist30);
           DEBUG_FREE(sortedlist30->id);
      }
   }
   return 0;
}

