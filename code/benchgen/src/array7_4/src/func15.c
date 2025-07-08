#include "array7_4.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array39;
   if (pCounter > 0) {
      array39 = vars->data[--pCounter];
      array39->refC++;
      DEBUG_COPY(array39->id);
   } else {
      array39 = (array_t*)malloc(sizeof(array_t));
      array39->size = 619;
      array39->refC = 1;
      array39->id = 39;
      array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
      memset(array39->data, 0, array39->size*sizeof(unsigned int));
      DEBUG_NEW(array39->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/4 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array39;
      array_t* array40 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array40->id);
      free(params0.data);
      array40->refC--;
      if(array40->refC == 0) {
         free(array40->data);
         free(array40);
         DEBUG_FREE(array40->id);
      }
   }
   return array39;
}

