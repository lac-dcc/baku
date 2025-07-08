#include "array6_2.h" 
array_t* func5(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array3 = func6(&params0, loopsFactor);
      DEBUG_RETURN(array3->id);
      free(params0.data);
      array3->refC--;
      if(array3->refC == 0) {
         free(array3->data);
         free(array3);
         DEBUG_FREE(array3->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array5 = func7(&params0, loopsFactor);
      DEBUG_RETURN(array5->id);
      free(params0.data);
      array5->refC--;
      if(array5->refC == 0) {
         free(array5->data);
         free(array5);
         DEBUG_FREE(array5->id);
      }
   }
   array_t* array21;
   if (pCounter > 0) {
      array21 = vars->data[--pCounter];
      array21->refC++;
      DEBUG_COPY(array21->id);
   } else {
      array21 = (array_t*)malloc(sizeof(array_t));
      array21->size = 327;
      array21->refC = 1;
      array21->id = 21;
      array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
      memset(array21->data, 0, array21->size*sizeof(unsigned int));
      DEBUG_NEW(array21->id);
   }
   return array21;
}

