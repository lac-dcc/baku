#include "array8_4.h" 
array_t* func5(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array37;
   if (pCounter > 0) {
      array37 = vars->data[--pCounter];
      array37->refC++;
      DEBUG_COPY(array37->id);
   } else {
      array37 = (array_t*)malloc(sizeof(array_t));
      array37->size = 865;
      array37->refC = 1;
      array37->id = 37;
      array37->data = (unsigned int*)malloc(array37->size*sizeof(unsigned int));
      memset(array37->data, 0, array37->size*sizeof(unsigned int));
      DEBUG_NEW(array37->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/2 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array37;
      array_t* array38 = func10(&params0, loopsFactor);
      DEBUG_RETURN(array38->id);
      free(params0.data);
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
   }
   return array37;
}

