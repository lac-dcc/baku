#include "array6_5.h"

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
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array0 = func0(&params0, loopsFactor);
   DEBUG_RETURN(array0->id);
   free(params0.data);
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array0;
   array_t* array29 = func1(&params1, loopsFactor);
   DEBUG_RETURN(array29->id);
   free(params1.data);
   array_t_param params2;
   params2.size = 2;
   params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
   params2.data[0] = array0;
   params2.data[1] = array29;
   array_t* array36 = func2(&params2, loopsFactor);
   DEBUG_RETURN(array36->id);
   free(params2.data);
   array36->refC--;
   if(array36->refC == 0) {
      free(array36->data);
      free(array36);
      DEBUG_FREE(array36->id);
   }
   array29->refC--;
   if(array29->refC == 0) {
      free(array29->data);
      free(array29);
      DEBUG_FREE(array29->id);
   }
   array0->refC--;
   if(array0->refC == 0) {
      free(array0->data);
      free(array0);
      DEBUG_FREE(array0->id);
   }
   return 0;
}

