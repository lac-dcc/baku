#include "array8_8.h" 
array_t* func9(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      array_t* array5;
      if (pCounter > 0) {
         array5 = vars->data[--pCounter];
         array5->refC++;
         DEBUG_COPY(array5->id);
      } else {
         array5 = (array_t*)malloc(sizeof(array_t));
         array5->size = 736;
         array5->refC = 1;
         array5->id = 5;
         array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
         memset(array5->data, 0, array5->size*sizeof(unsigned int));
         DEBUG_NEW(array5->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array5;
      array_t* array6 = func13(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array6->id);
      free(params0.data);
      array6->refC--;
      if(array6->refC == 0) {
         free(array6->data);
         free(array6);
         DEBUG_FREE(array6->id);
      }
      array5->refC--;
      if(array5->refC == 0) {
         free(array5->data);
         free(array5);
         DEBUG_FREE(array5->id);
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

