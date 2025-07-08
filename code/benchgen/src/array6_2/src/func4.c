#include "array6_2.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
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
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array28;
      array_t* array29 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array29->id);
      free(params0.data);
      for (int i = 0; i < array29->size; i++) {
         array29->data[i]++;
      }
      array29->refC--;
      if(array29->refC == 0) {
         free(array29->data);
         free(array29);
         DEBUG_FREE(array29->id);
      }
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
   }
   array_t* array43;
   if (pCounter > 0) {
      array43 = vars->data[--pCounter];
      array43->refC++;
      DEBUG_COPY(array43->id);
   } else {
      array43 = (array_t*)malloc(sizeof(array_t));
      array43->size = 675;
      array43->refC = 1;
      array43->id = 43;
      array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
      memset(array43->data, 0, array43->size*sizeof(unsigned int));
      DEBUG_NEW(array43->id);
   }
   return array43;
}

