#include "array5_4.h"

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
      unsigned int loop0 = 0;
      unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
      for(; loop0 < loopLimit0; loop0++) {
         array_t_param params0;
         params0.size = 0;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         array_t* array0 = func0(&params0, loopsFactor);
         DEBUG_RETURN(array0->id);
         free(params0.data);
         array0->refC--;
         if(array0->refC == 0) {
            free(array0->data);
            free(array0);
            DEBUG_FREE(array0->id);
         }
      }
   }
   else {
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
      for(; loop4 < loopLimit4; loop4++) {
         array_t_param params0;
         params0.size = 0;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         array_t* array20 = func1(&params0, loopsFactor);
         DEBUG_RETURN(array20->id);
         free(params0.data);
         array20->refC--;
         if(array20->refC == 0) {
            free(array20->data);
            free(array20);
            DEBUG_FREE(array20->id);
         }
      }
   }
   return 0;
}

