#include "sortedlist10_5.h"

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
   sortedlist_t* sortedlist49 = func1(&params1, loopsFactor);
   DEBUG_RETURN(sortedlist49->id);
   free(params1.data);
   sortedlist_t_param params2;
   params2.size = 2;
   params2.data = (sortedlist_t**)malloc(params2.size*sizeof(sortedlist_t*));
   params2.data[0] = sortedlist0;
   params2.data[1] = sortedlist49;
   sortedlist_t* sortedlist56 = func2(&params2, loopsFactor);
   DEBUG_RETURN(sortedlist56->id);
   free(params2.data);
   sortedlist56->refC--;
   if(sortedlist56->refC == 0){
        cell_t* cell32 = sortedlist56->root;
        cell_t* tmp32  = NULL;
        while(cell32 != NULL) {
            tmp32 = cell32->next;
            free(cell32);
            cell32 = tmp32;
        }
        free(sortedlist56);
        DEBUG_FREE(sortedlist56->id);
   }
   sortedlist49->refC--;
   if(sortedlist49->refC == 0){
        cell_t* cell33 = sortedlist49->root;
        cell_t* tmp33  = NULL;
        while(cell33 != NULL) {
            tmp33 = cell33->next;
            free(cell33);
            cell33 = tmp33;
        }
        free(sortedlist49);
        DEBUG_FREE(sortedlist49->id);
   }
   sortedlist0->refC--;
   if(sortedlist0->refC == 0){
        cell_t* cell34 = sortedlist0->root;
        cell_t* tmp34  = NULL;
        while(cell34 != NULL) {
            tmp34 = cell34->next;
            free(cell34);
            cell34 = tmp34;
        }
        free(sortedlist0);
        DEBUG_FREE(sortedlist0->id);
   }
   return 0;
}

