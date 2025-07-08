#include "array8_8.h" 
array_t* func10(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array31 = func11(&params0, loopsFactor);
      DEBUG_RETURN(array31->id);
      free(params0.data);
      array31->refC--;
      if(array31->refC == 0) {
         free(array31->data);
         free(array31);
         DEBUG_FREE(array31->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array42 = func12(&params0, loopsFactor);
      DEBUG_RETURN(array42->id);
      free(params0.data);
      array42->refC--;
      if(array42->refC == 0) {
         free(array42->data);
         free(array42);
         DEBUG_FREE(array42->id);
      }
   }
   array_t* array44;
   if (pCounter > 0) {
      array44 = vars->data[--pCounter];
      array44->refC++;
      DEBUG_COPY(array44->id);
   } else {
      array44 = (array_t*)malloc(sizeof(array_t));
      array44->size = 683;
      array44->refC = 1;
      array44->id = 44;
      array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
      memset(array44->data, 0, array44->size*sizeof(unsigned int));
      DEBUG_NEW(array44->id);
   }
   return array44;
}

