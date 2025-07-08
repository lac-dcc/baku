#include "array6_4.h" 
array_t* func11(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array10;
      if (pCounter > 0) {
         array10 = vars->data[--pCounter];
         array10->refC++;
         DEBUG_COPY(array10->id);
      } else {
         array10 = (array_t*)malloc(sizeof(array_t));
         array10->size = 22;
         array10->refC = 1;
         array10->id = 10;
         array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
         memset(array10->data, 0, array10->size*sizeof(unsigned int));
         DEBUG_NEW(array10->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array10;
      array_t* array11 = func16(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array11->id);
      free(params0.data);
      array11->refC--;
      if(array11->refC == 0) {
         free(array11->data);
         free(array11);
         DEBUG_FREE(array11->id);
      }
      array10->refC--;
      if(array10->refC == 0) {
         free(array10->data);
         free(array10);
         DEBUG_FREE(array10->id);
      }
   }
   array_t* array20;
   if (pCounter > 0) {
      array20 = vars->data[--pCounter];
      array20->refC++;
      DEBUG_COPY(array20->id);
   } else {
      array20 = (array_t*)malloc(sizeof(array_t));
      array20->size = 84;
      array20->refC = 1;
      array20->id = 20;
      array20->data = (unsigned int*)malloc(array20->size*sizeof(unsigned int));
      memset(array20->data, 0, array20->size*sizeof(unsigned int));
      DEBUG_NEW(array20->id);
   }
   return array20;
}

