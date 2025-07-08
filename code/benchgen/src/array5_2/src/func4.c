#include "array5_2.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array22;
      if (pCounter > 0) {
         array22 = vars->data[--pCounter];
         array22->refC++;
         DEBUG_COPY(array22->id);
      } else {
         array22 = (array_t*)malloc(sizeof(array_t));
         array22->size = 729;
         array22->refC = 1;
         array22->id = 22;
         array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
         memset(array22->data, 0, array22->size*sizeof(unsigned int));
         DEBUG_NEW(array22->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array22;
      array_t* array23 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array23->id);
      free(params0.data);
      for (int i = 0; i < array23->size; i++) {
         array23->data[i]++;
      }
      array23->refC--;
      if(array23->refC == 0) {
         free(array23->data);
         free(array23);
         DEBUG_FREE(array23->id);
      }
      array22->refC--;
      if(array22->refC == 0) {
         free(array22->data);
         free(array22);
         DEBUG_FREE(array22->id);
      }
   }
   array_t* array36;
   if (pCounter > 0) {
      array36 = vars->data[--pCounter];
      array36->refC++;
      DEBUG_COPY(array36->id);
   } else {
      array36 = (array_t*)malloc(sizeof(array_t));
      array36->size = 902;
      array36->refC = 1;
      array36->id = 36;
      array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
      memset(array36->data, 0, array36->size*sizeof(unsigned int));
      DEBUG_NEW(array36->id);
   }
   return array36;
}

