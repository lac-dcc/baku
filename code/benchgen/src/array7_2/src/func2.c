#include "array7_2.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array26 = func3(&params0, loopsFactor);
      DEBUG_RETURN(array26->id);
      free(params0.data);
      array26->refC--;
      if(array26->refC == 0) {
         free(array26->data);
         free(array26);
         DEBUG_FREE(array26->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array28 = func4(&params0, loopsFactor);
      DEBUG_RETURN(array28->id);
      free(params0.data);
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
   }
   array_t* array51;
   if (pCounter > 0) {
      array51 = vars->data[--pCounter];
      array51->refC++;
      DEBUG_COPY(array51->id);
   } else {
      array51 = (array_t*)malloc(sizeof(array_t));
      array51->size = 715;
      array51->refC = 1;
      array51->id = 51;
      array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
      memset(array51->data, 0, array51->size*sizeof(unsigned int));
      DEBUG_NEW(array51->id);
   }
   return array51;
}

