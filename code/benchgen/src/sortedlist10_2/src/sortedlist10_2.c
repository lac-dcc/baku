#include "sortedlist10_2.h"

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
           cell_t* cell25 = sortedlist0->root;
           cell_t* tmp25  = NULL;
           while(cell25 != NULL) {
               tmp25 = cell25->next;
               free(cell25);
               cell25 = tmp25;
           }
           free(sortedlist0);
           DEBUG_FREE(sortedlist0->id);
      }
   }
   else {
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist37 = func1(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist37->id);
      free(params0.data);
      sortedlist37->refC--;
      if(sortedlist37->refC == 0){
           cell_t* cell49 = sortedlist37->root;
           cell_t* tmp49  = NULL;
           while(cell49 != NULL) {
               tmp49 = cell49->next;
               free(cell49);
               cell49 = tmp49;
           }
           free(sortedlist37);
           DEBUG_FREE(sortedlist37->id);
      }
   }
   return 0;
}

