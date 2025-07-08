#include "array10_2.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array39 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array39->id);
      free(params0.data);
      array39->refC--;
      if(array39->refC == 0) {
         free(array39->data);
         free(array39);
         DEBUG_FREE(array39->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array41 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array41->id);
      free(params0.data);
      array41->refC--;
      if(array41->refC == 0) {
         free(array41->data);
         free(array41);
         DEBUG_FREE(array41->id);
      }
   }
   array_t* array72;
   if (pCounter > 0) {
      array72 = vars->data[--pCounter];
      array72->refC++;
      DEBUG_COPY(array72->id);
   } else {
      array72 = (array_t*)malloc(sizeof(array_t));
      array72->size = 818;
      array72->refC = 1;
      array72->id = 72;
      array72->data = (unsigned int*)malloc(array72->size*sizeof(unsigned int));
      memset(array72->data, 0, array72->size*sizeof(unsigned int));
      DEBUG_NEW(array72->id);
   }
   return array72;
}

