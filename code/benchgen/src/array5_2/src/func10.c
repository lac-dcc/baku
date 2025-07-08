#include "array5_2.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      array_t* array27;
      if (pCounter > 0) {
         array27 = vars->data[--pCounter];
         array27->refC++;
         DEBUG_COPY(array27->id);
      } else {
         array27 = (array_t*)malloc(sizeof(array_t));
         array27->size = 276;
         array27->refC = 1;
         array27->id = 27;
         array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
         memset(array27->data, 0, array27->size*sizeof(unsigned int));
         DEBUG_NEW(array27->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array27;
      array_t* array28 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array28->id);
      free(params0.data);
      for (int i = 0; i < array27->size; i++) {
         array27->data[i]++;
      }
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
      array27->refC--;
      if(array27->refC == 0) {
         free(array27->data);
         free(array27);
         DEBUG_FREE(array27->id);
      }
   }
   array_t* array34;
   if (pCounter > 0) {
      array34 = vars->data[--pCounter];
      array34->refC++;
      DEBUG_COPY(array34->id);
   } else {
      array34 = (array_t*)malloc(sizeof(array_t));
      array34->size = 434;
      array34->refC = 1;
      array34->id = 34;
      array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
      memset(array34->data, 0, array34->size*sizeof(unsigned int));
      DEBUG_NEW(array34->id);
   }
   return array34;
}

