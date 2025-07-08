#include "sortedlist7_5.h"

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
   sortedlist_t_param params0;
   params0.size = 0;
   params0.data = (sortedlist_t**)malloc(params0.size*sizeof(sortedlist_t*));
   sortedlist_t* sortedlist0 = func0(&params0, loopsFactor);
   DEBUG_RETURN(sortedlist0->id);
   free(params0.data);
   sortedlist_t_param params1;
   params1.size = 1;
   params1.data = (sortedlist_t**)malloc(params1.size*sizeof(sortedlist_t*));
   params1.data[0] = sortedlist0;
   sortedlist_t* sortedlist34 = func1(&params1, loopsFactor);
   DEBUG_RETURN(sortedlist34->id);
   free(params1.data);
   sortedlist_t_param params2;
   params2.size = 2;
   params2.data = (sortedlist_t**)malloc(params2.size*sizeof(sortedlist_t*));
   params2.data[0] = sortedlist0;
   params2.data[1] = sortedlist34;
   sortedlist_t* sortedlist41 = func2(&params2, loopsFactor);
   DEBUG_RETURN(sortedlist41->id);
   free(params2.data);
   sortedlist41->refC--;
   if(sortedlist41->refC == 0){
        cell_t* cell23 = sortedlist41->root;
        cell_t* tmp23  = NULL;
        while(cell23 != NULL) {
            tmp23 = cell23->next;
            free(cell23);
            cell23 = tmp23;
        }
        free(sortedlist41);
        DEBUG_FREE(sortedlist41->id);
   }
   sortedlist34->refC--;
   if(sortedlist34->refC == 0){
        cell_t* cell24 = sortedlist34->root;
        cell_t* tmp24  = NULL;
        while(cell24 != NULL) {
            tmp24 = cell24->next;
            free(cell24);
            cell24 = tmp24;
        }
        free(sortedlist34);
        DEBUG_FREE(sortedlist34->id);
   }
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
   return 0;
}

