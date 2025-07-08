#include "array9_2.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/1 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      array_t* array36;
      if (pCounter > 0) {
         array36 = vars->data[--pCounter];
         array36->refC++;
         DEBUG_COPY(array36->id);
      } else {
         array36 = (array_t*)malloc(sizeof(array_t));
         array36->size = 902;
         array36->refC = 1;
         array36->id = 36;
         array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
         memset(array36->data, 0, array36->size*sizeof(unsigned int));
         DEBUG_NEW(array36->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array36;
      array_t* array37 = func8(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array37->id);
      free(params0.data);
      for (int i = 0; i < array36->size; i++) {
         array36->data[i]++;
      }
      array37->refC--;
      if(array37->refC == 0) {
         free(array37->data);
         free(array37);
         DEBUG_FREE(array37->id);
      }
      array36->refC--;
      if(array36->refC == 0) {
         free(array36->data);
         free(array36);
         DEBUG_FREE(array36->id);
      }
   }
   array_t* array64;
   if (pCounter > 0) {
      array64 = vars->data[--pCounter];
      array64->refC++;
      DEBUG_COPY(array64->id);
   } else {
      array64 = (array_t*)malloc(sizeof(array_t));
      array64->size = 121;
      array64->refC = 1;
      array64->id = 64;
      array64->data = (unsigned int*)malloc(array64->size*sizeof(unsigned int));
      memset(array64->data, 0, array64->size*sizeof(unsigned int));
      DEBUG_NEW(array64->id);
   }
   return array64;
}

