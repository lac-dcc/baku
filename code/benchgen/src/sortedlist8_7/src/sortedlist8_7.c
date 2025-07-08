#include "sortedlist8_7.h"

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
      sortedlist_t_param params0;
      params0.size = 0;
      params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
      sortedlist_t* sortedlist0 = func0(&params0, loopsFactor);
      DEBUG_RETURN(sortedlist0->id);
      free(params0.data);
      if(sortedlist0 != NULL && sortedlist0->n > 0)
      {
          cell_t* cell16 = sortedlist0->root;
          if(cell16->val == 62)
          {
              cell16 = cell16->next;
              sortedlist0->n--;
          }else{
              while(cell16->next != NULL && cell16->next->val != 62) cell16 = cell16->next;
              if(cell16->next != NULL)
              {
                  cell16 = cell16->next->next;
                  sortedlist0->n--;
              }
           }
      }
      sortedlist0->refC--;
      if(sortedlist0->refC == 0){
           cell_t* cell17 = sortedlist0->root;
           cell_t* tmp17  = NULL;
           while(cell17 != NULL) {
               tmp17 = cell17->next;
               free(cell17);
               cell17 = tmp17;
           }
           free(sortedlist0);
           DEBUG_FREE(sortedlist0->id);
      }
   }
   return 0;
}

