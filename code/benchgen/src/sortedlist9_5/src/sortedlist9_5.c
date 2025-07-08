#include "sortedlist9_5.h"

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
   sortedlist_t* sortedlist44 = func1(&params1, loopsFactor);
   DEBUG_RETURN(sortedlist44->id);
   free(params1.data);
   sortedlist_t_param params2;
   params2.size = 2;
   params2.data = (sortedlist_t**)malloc(params2.size*sizeof(sortedlist_t*));
   params2.data[0] = sortedlist0;
   params2.data[1] = sortedlist44;
   sortedlist_t* sortedlist51 = func2(&params2, loopsFactor);
   DEBUG_RETURN(sortedlist51->id);
   free(params2.data);
   sortedlist51->refC--;
   if(sortedlist51->refC == 0){
        cell_t* cell29 = sortedlist51->root;
        cell_t* tmp29  = NULL;
        while(cell29 != NULL) {
            tmp29 = cell29->next;
            free(cell29);
            cell29 = tmp29;
        }
        free(sortedlist51);
        DEBUG_FREE(sortedlist51->id);
   }
   sortedlist44->refC--;
   if(sortedlist44->refC == 0){
        cell_t* cell30 = sortedlist44->root;
        cell_t* tmp30  = NULL;
        while(cell30 != NULL) {
            tmp30 = cell30->next;
            free(cell30);
            cell30 = tmp30;
        }
        free(sortedlist44);
        DEBUG_FREE(sortedlist44->id);
   }
   sortedlist0->refC--;
   if(sortedlist0->refC == 0){
        cell_t* cell31 = sortedlist0->root;
        cell_t* tmp31  = NULL;
        while(cell31 != NULL) {
            tmp31 = cell31->next;
            free(cell31);
            cell31 = tmp31;
        }
        free(sortedlist0);
        DEBUG_FREE(sortedlist0->id);
   }
   return 0;
}

