#include "array5_4.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array36;
   if (pCounter > 0) {
      array36 = vars->data[--pCounter];
      array36->refC++;
      DEBUG_COPY(array36->id);
   } else {
      array36 = (array_t*)malloc(sizeof(array_t));
      array36->size = 301;
      array36->refC = 1;
      array36->id = 36;
      array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
      memset(array36->data, 0, array36->size*sizeof(unsigned int));
      DEBUG_NEW(array36->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/4 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array36;
      array_t* array37 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array37->id);
      free(params0.data);
      array37->refC--;
      if(array37->refC == 0) {
         free(array37->data);
         free(array37);
         DEBUG_FREE(array37->id);
      }
   }
   return array36;
}

