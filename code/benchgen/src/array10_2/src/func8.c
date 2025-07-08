#include "array10_2.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array44 = func9(&params0, loopsFactor);
      DEBUG_RETURN(array44->id);
      free(params0.data);
      array44->refC--;
      if(array44->refC == 0) {
         free(array44->data);
         free(array44);
         DEBUG_FREE(array44->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array46 = func10(&params0, loopsFactor);
      DEBUG_RETURN(array46->id);
      free(params0.data);
      array46->refC--;
      if(array46->refC == 0) {
         free(array46->data);
         free(array46);
         DEBUG_FREE(array46->id);
      }
   }
   array_t* array70;
   if (pCounter > 0) {
      array70 = vars->data[--pCounter];
      array70->refC++;
      DEBUG_COPY(array70->id);
   } else {
      array70 = (array_t*)malloc(sizeof(array_t));
      array70->size = 613;
      array70->refC = 1;
      array70->id = 70;
      array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
      memset(array70->data, 0, array70->size*sizeof(unsigned int));
      DEBUG_NEW(array70->id);
   }
   return array70;
}

