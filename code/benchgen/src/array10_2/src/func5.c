#include "array10_2.h" 
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
   array_t* array35;
   if (pCounter > 0) {
      array35 = vars->data[--pCounter];
      array35->refC++;
      DEBUG_COPY(array35->id);
   } else {
      array35 = (array_t*)malloc(sizeof(array_t));
      array35->size = 378;
      array35->refC = 1;
      array35->id = 35;
      array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
      memset(array35->data, 0, array35->size*sizeof(unsigned int));
      DEBUG_NEW(array35->id);
   }
   return array35;
}

