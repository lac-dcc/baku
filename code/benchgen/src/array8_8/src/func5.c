#include "array8_8.h" 
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
      array_t* array21 = func7(&params0, loopsFactor);
      DEBUG_RETURN(array21->id);
      free(params0.data);
      array21->refC--;
      if(array21->refC == 0) {
         free(array21->data);
         free(array21);
         DEBUG_FREE(array21->id);
      }
   }
   array_t* array23;
   if (pCounter > 0) {
      array23 = vars->data[--pCounter];
      array23->refC++;
      DEBUG_COPY(array23->id);
   } else {
      array23 = (array_t*)malloc(sizeof(array_t));
      array23->size = 895;
      array23->refC = 1;
      array23->id = 23;
      array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
      memset(array23->data, 0, array23->size*sizeof(unsigned int));
      DEBUG_NEW(array23->id);
   }
   return array23;
}

