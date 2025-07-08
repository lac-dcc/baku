#include "array10_2.h" 
array_t* func25(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      array_t* array21;
      if (pCounter > 0) {
         array21 = vars->data[--pCounter];
         array21->refC++;
         DEBUG_COPY(array21->id);
      } else {
         array21 = (array_t*)malloc(sizeof(array_t));
         array21->size = 846;
         array21->refC = 1;
         array21->id = 21;
         array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
         memset(array21->data, 0, array21->size*sizeof(unsigned int));
         DEBUG_NEW(array21->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array21;
      array_t* array22 = func29(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array22->id);
      free(params0.data);
      for (int i = 0; i < array21->size; i++) {
         array21->data[i]++;
      }
      array22->refC--;
      if(array22->refC == 0) {
         free(array22->data);
         free(array22);
         DEBUG_FREE(array22->id);
      }
      array21->refC--;
      if(array21->refC == 0) {
         free(array21->data);
         free(array21);
         DEBUG_FREE(array21->id);
      }
   }
   array_t* array28;
   if (pCounter > 0) {
      array28 = vars->data[--pCounter];
      array28->refC++;
      DEBUG_COPY(array28->id);
   } else {
      array28 = (array_t*)malloc(sizeof(array_t));
      array28->size = 403;
      array28->refC = 1;
      array28->id = 28;
      array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
      memset(array28->data, 0, array28->size*sizeof(unsigned int));
      DEBUG_NEW(array28->id);
   }
   return array28;
}

