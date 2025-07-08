#include "array10_8.h" 
array_t* func24(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/3 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      array_t* array39;
      if (pCounter > 0) {
         array39 = vars->data[--pCounter];
         array39->refC++;
         DEBUG_COPY(array39->id);
      } else {
         array39 = (array_t*)malloc(sizeof(array_t));
         array39->size = 117;
         array39->refC = 1;
         array39->id = 39;
         array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
         memset(array39->data, 0, array39->size*sizeof(unsigned int));
         DEBUG_NEW(array39->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array39;
      array_t* array40 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array40->id);
      free(params0.data);
      array40->refC--;
      if(array40->refC == 0) {
         free(array40->data);
         free(array40);
         DEBUG_FREE(array40->id);
      }
      array39->refC--;
      if(array39->refC == 0) {
         free(array39->data);
         free(array39);
         DEBUG_FREE(array39->id);
      }
   }
   array_t* array46;
   if (pCounter > 0) {
      array46 = vars->data[--pCounter];
      array46->refC++;
      DEBUG_COPY(array46->id);
   } else {
      array46 = (array_t*)malloc(sizeof(array_t));
      array46->size = 732;
      array46->refC = 1;
      array46->id = 46;
      array46->data = (unsigned int*)malloc(array46->size*sizeof(unsigned int));
      memset(array46->data, 0, array46->size*sizeof(unsigned int));
      DEBUG_NEW(array46->id);
   }
   return array46;
}

