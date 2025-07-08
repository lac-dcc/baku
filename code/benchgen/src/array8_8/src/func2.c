#include "array8_8.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array27 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array27->id);
      free(params0.data);
      array27->refC--;
      if(array27->refC == 0) {
         free(array27->data);
         free(array27);
         DEBUG_FREE(array27->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array46 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array46->id);
      free(params0.data);
      array46->refC--;
      if(array46->refC == 0) {
         free(array46->data);
         free(array46);
         DEBUG_FREE(array46->id);
      }
   }
   array_t* array48;
   if (pCounter > 0) {
      array48 = vars->data[--pCounter];
      array48->refC++;
      DEBUG_COPY(array48->id);
   } else {
      array48 = (array_t*)malloc(sizeof(array_t));
      array48->size = 708;
      array48->refC = 1;
      array48->id = 48;
      array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
      memset(array48->data, 0, array48->size*sizeof(unsigned int));
      DEBUG_NEW(array48->id);
   }
   return array48;
}

