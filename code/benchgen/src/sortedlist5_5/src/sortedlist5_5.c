#include "sortedlist5_5.h"

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
   sortedlist_t* sortedlist24 = func1(&params1, loopsFactor);
   DEBUG_RETURN(sortedlist24->id);
   free(params1.data);
   sortedlist_t_param params2;
   params2.size = 2;
   params2.data = (sortedlist_t**)malloc(params2.size*sizeof(sortedlist_t*));
   params2.data[0] = sortedlist0;
   params2.data[1] = sortedlist24;
   sortedlist_t* sortedlist31 = func2(&params2, loopsFactor);
   DEBUG_RETURN(sortedlist31->id);
   free(params2.data);
   sortedlist31->refC--;
   if(sortedlist31->refC == 0){
        cell_t* cell17 = sortedlist31->root;
        cell_t* tmp17  = NULL;
        while(cell17 != NULL) {
            tmp17 = cell17->next;
            free(cell17);
            cell17 = tmp17;
        }
        free(sortedlist31);
        DEBUG_FREE(sortedlist31->id);
   }
   sortedlist24->refC--;
   if(sortedlist24->refC == 0){
        cell_t* cell18 = sortedlist24->root;
        cell_t* tmp18  = NULL;
        while(cell18 != NULL) {
            tmp18 = cell18->next;
            free(cell18);
            cell18 = tmp18;
        }
        free(sortedlist24);
        DEBUG_FREE(sortedlist24->id);
   }
   sortedlist0->refC--;
   if(sortedlist0->refC == 0){
        cell_t* cell19 = sortedlist0->root;
        cell_t* tmp19  = NULL;
        while(cell19 != NULL) {
            tmp19 = cell19->next;
            free(cell19);
            cell19 = tmp19;
        }
        free(sortedlist0);
        DEBUG_FREE(sortedlist0->id);
   }
   return 0;
}

