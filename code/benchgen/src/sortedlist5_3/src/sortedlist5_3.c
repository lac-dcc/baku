#include "sortedlist5_3.h"

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
          cell_t* cell1 = sortedlist0->root;
          if(cell1->val == 93)
          {
              cell1 = cell1->next;
              sortedlist0->n--;
          }else{
              while(cell1->next != NULL && cell1->next->val != 93) cell1 = cell1->next;
              if(cell1->next != NULL)
              {
                  cell1 = cell1->next->next;
                  sortedlist0->n--;
              }
           }
      }
      sortedlist0->refC--;
      if(sortedlist0->refC == 0){
           cell_t* cell2 = sortedlist0->root;
           cell_t* tmp2  = NULL;
           while(cell2 != NULL) {
               tmp2 = cell2->next;
               free(cell2);
               cell2 = tmp2;
           }
           free(sortedlist0);
           DEBUG_FREE(sortedlist0->id);
      }
   }
   return 0;
}

