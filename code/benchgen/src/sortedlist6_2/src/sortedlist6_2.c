#include "sortedlist6_2.h"

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
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist23 = func1(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist23->id);
      free(params0.data);
      sortedlist23->refC--;
      if(sortedlist23->refC == 0){
           cell_t* cell29 = sortedlist23->root;
           cell_t* tmp29  = NULL;
           while(cell29 != NULL) {
               tmp29 = cell29->next;
               free(cell29);
               cell29 = tmp29;
           }
           free(sortedlist23);
           DEBUG_FREE(sortedlist23->id);
      }
   }
   return 0;
}

