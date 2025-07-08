#include "array6_8.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array20 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array20->id);
      free(params0.data);
      array20->refC--;
      if(array20->refC == 0) {
         free(array20->data);
         free(array20);
         DEBUG_FREE(array20->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array32 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array32->id);
      free(params0.data);
      array32->refC--;
      if(array32->refC == 0) {
         free(array32->data);
         free(array32);
         DEBUG_FREE(array32->id);
      }
   }
   array_t* array34;
   if (pCounter > 0) {
      array34 = vars->data[--pCounter];
      array34->refC++;
      DEBUG_COPY(array34->id);
   } else {
      array34 = (array_t*)malloc(sizeof(array_t));
      array34->size = 97;
      array34->refC = 1;
      array34->id = 34;
      array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
      memset(array34->data, 0, array34->size*sizeof(unsigned int));
      DEBUG_NEW(array34->id);
   }
   return array34;
}

