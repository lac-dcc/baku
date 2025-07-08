#include "sortedlist8_5.h"

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
   sortedlist_t* sortedlist39 = func1(&params1, loopsFactor);
   DEBUG_RETURN(sortedlist39->id);
   free(params1.data);
   sortedlist_t_param params2;
   params2.size = 2;
   params2.data = (sortedlist_t**)malloc(params2.size*sizeof(sortedlist_t*));
   params2.data[0] = sortedlist0;
   params2.data[1] = sortedlist39;
   sortedlist_t* sortedlist46 = func2(&params2, loopsFactor);
   DEBUG_RETURN(sortedlist46->id);
   free(params2.data);
   sortedlist46->refC--;
   if(sortedlist46->refC == 0){
        cell_t* cell26 = sortedlist46->root;
        cell_t* tmp26  = NULL;
        while(cell26 != NULL) {
            tmp26 = cell26->next;
            free(cell26);
            cell26 = tmp26;
        }
        free(sortedlist46);
        DEBUG_FREE(sortedlist46->id);
   }
   sortedlist39->refC--;
   if(sortedlist39->refC == 0){
        cell_t* cell27 = sortedlist39->root;
        cell_t* tmp27  = NULL;
        while(cell27 != NULL) {
            tmp27 = cell27->next;
            free(cell27);
            cell27 = tmp27;
        }
        free(sortedlist39);
        DEBUG_FREE(sortedlist39->id);
   }
   sortedlist0->refC--;
   if(sortedlist0->refC == 0){
        cell_t* cell28 = sortedlist0->root;
        cell_t* tmp28  = NULL;
        while(cell28 != NULL) {
            tmp28 = cell28->next;
            free(cell28);
            cell28 = tmp28;
        }
        free(sortedlist0);
        DEBUG_FREE(sortedlist0->id);
   }
   return 0;
}

