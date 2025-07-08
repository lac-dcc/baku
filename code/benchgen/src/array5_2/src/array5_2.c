#include "array5_2.h"

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
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array17 = func1(&params0, loopsFactor);
      DEBUG_RETURN(array17->id);
      free(params0.data);
      array17->refC--;
      if(array17->refC == 0) {
         free(array17->data);
         free(array17);
         DEBUG_FREE(array17->id);
      }
   }
   return 0;
}

