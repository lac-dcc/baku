#include "sortedlist6_5.h"

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
   sortedlist_t* sortedlist29 = func1(&params1, loopsFactor);
   DEBUG_RETURN(sortedlist29->id);
   free(params1.data);
   sortedlist_t_param params2;
   params2.size = 2;
   params2.data = (sortedlist_t**)malloc(params2.size*sizeof(sortedlist_t*));
   params2.data[0] = sortedlist0;
   params2.data[1] = sortedlist29;
   sortedlist_t* sortedlist36 = func2(&params2, loopsFactor);
   DEBUG_RETURN(sortedlist36->id);
   free(params2.data);
   sortedlist36->refC--;
   if(sortedlist36->refC == 0){
        cell_t* cell20 = sortedlist36->root;
        cell_t* tmp20  = NULL;
        while(cell20 != NULL) {
            tmp20 = cell20->next;
            free(cell20);
            cell20 = tmp20;
        }
        free(sortedlist36);
        DEBUG_FREE(sortedlist36->id);
   }
   sortedlist29->refC--;
   if(sortedlist29->refC == 0){
        cell_t* cell21 = sortedlist29->root;
        cell_t* tmp21  = NULL;
        while(cell21 != NULL) {
            tmp21 = cell21->next;
            free(cell21);
            cell21 = tmp21;
        }
        free(sortedlist29);
        DEBUG_FREE(sortedlist29->id);
   }
   sortedlist0->refC--;
   if(sortedlist0->refC == 0){
        cell_t* cell22 = sortedlist0->root;
        cell_t* tmp22  = NULL;
        while(cell22 != NULL) {
            tmp22 = cell22->next;
            free(cell22);
            cell22 = tmp22;
        }
        free(sortedlist0);
        DEBUG_FREE(sortedlist0->id);
   }
   return 0;
}

