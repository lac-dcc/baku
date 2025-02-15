#include "outs/5_7_array.h" 
array_t* func7(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array41;
   if (pCounter > 0) {
      array41 = vars->data[--pCounter];
      array41->refC++;
      DEBUG_COPY(array41->id);
   } else {
      array41 = (array_t*)malloc(sizeof(array_t));
      array41->size = 570;
      array41->refC = 1;
      array41->id = 41;
      array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
      memset(array41->data, 0, array41->size*sizeof(unsigned int));
      DEBUG_NEW(array41->id);
   }
   for (int i = 0; i < array41->size; i++) {
      if (array41->data[i] == 78) { 
         return array41;
      }
   }
   array_t* array42;
   if (pCounter > 0) {
      array42 = vars->data[--pCounter];
      array42->refC++;
      DEBUG_COPY(array42->id);
   } else {
      array42 = (array_t*)malloc(sizeof(array_t));
      array42->size = 467;
      array42->refC = 1;
      array42->id = 42;
      array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
      memset(array42->data, 0, array42->size*sizeof(unsigned int));
      DEBUG_NEW(array42->id);
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array41;
   params0.data[1] = array42;
   array_t* array43 = func11(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array43->id);
   free(params0.data);
   array42->refC--;
   if(array42->refC == 0) {
      free(array42->data);
      free(array42);
      DEBUG_FREE(array42->id);
   }
   array41->refC--;
   if(array41->refC == 0) {
      free(array41->data);
      free(array41);
      DEBUG_FREE(array41->id);
   }
   return array43;
}

