#include "array10_8.h" 
array_t* func10(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array33 = func11(&params0, loopsFactor);
      DEBUG_RETURN(array33->id);
      free(params0.data);
      array33->refC--;
      if(array33->refC == 0) {
         free(array33->data);
         free(array33);
         DEBUG_FREE(array33->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array51 = func12(&params0, loopsFactor);
      DEBUG_RETURN(array51->id);
      free(params0.data);
      array51->refC--;
      if(array51->refC == 0) {
         free(array51->data);
         free(array51);
         DEBUG_FREE(array51->id);
      }
   }
   array_t* array53;
   if (pCounter > 0) {
      array53 = vars->data[--pCounter];
      array53->refC++;
      DEBUG_COPY(array53->id);
   } else {
      array53 = (array_t*)malloc(sizeof(array_t));
      array53->size = 764;
      array53->refC = 1;
      array53->id = 53;
      array53->data = (unsigned int*)malloc(array53->size*sizeof(unsigned int));
      memset(array53->data, 0, array53->size*sizeof(unsigned int));
      DEBUG_NEW(array53->id);
   }
   return array53;
}

