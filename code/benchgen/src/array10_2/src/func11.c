#include "array10_2.h" 
array_t* func11(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array8 = func12(&params0, loopsFactor);
      DEBUG_RETURN(array8->id);
      free(params0.data);
      array8->refC--;
      if(array8->refC == 0) {
         free(array8->data);
         free(array8);
         DEBUG_FREE(array8->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array10 = func13(&params0, loopsFactor);
      DEBUG_RETURN(array10->id);
      free(params0.data);
      array10->refC--;
      if(array10->refC == 0) {
         free(array10->data);
         free(array10);
         DEBUG_FREE(array10->id);
      }
   }
   array_t* array33;
   if (pCounter > 0) {
      array33 = vars->data[--pCounter];
      array33->refC++;
      DEBUG_COPY(array33->id);
   } else {
      array33 = (array_t*)malloc(sizeof(array_t));
      array33->size = 94;
      array33->refC = 1;
      array33->id = 33;
      array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
      memset(array33->data, 0, array33->size*sizeof(unsigned int));
      DEBUG_NEW(array33->id);
   }
   return array33;
}

