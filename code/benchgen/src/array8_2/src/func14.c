#include "array8_2.h" 
array_t* func14(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array42 = func15(&params0, loopsFactor);
      DEBUG_RETURN(array42->id);
      free(params0.data);
      array42->refC--;
      if(array42->refC == 0) {
         free(array42->data);
         free(array42);
         DEBUG_FREE(array42->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array44 = func16(&params0, loopsFactor);
      DEBUG_RETURN(array44->id);
      free(params0.data);
      array44->refC--;
      if(array44->refC == 0) {
         free(array44->data);
         free(array44);
         DEBUG_FREE(array44->id);
      }
   }
   array_t* array54;
   if (pCounter > 0) {
      array54 = vars->data[--pCounter];
      array54->refC++;
      DEBUG_COPY(array54->id);
   } else {
      array54 = (array_t*)malloc(sizeof(array_t));
      array54->size = 555;
      array54->refC = 1;
      array54->id = 54;
      array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
      memset(array54->data, 0, array54->size*sizeof(unsigned int));
      DEBUG_NEW(array54->id);
   }
   return array54;
}

