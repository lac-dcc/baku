#include "array8_4.h" 
array_t* func15(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array46;
   if (pCounter > 0) {
      array46 = vars->data[--pCounter];
      array46->refC++;
      DEBUG_COPY(array46->id);
   } else {
      array46 = (array_t*)malloc(sizeof(array_t));
      array46->size = 732;
      array46->refC = 1;
      array46->id = 46;
      array46->data = (unsigned int*)malloc(array46->size*sizeof(unsigned int));
      memset(array46->data, 0, array46->size*sizeof(unsigned int));
      DEBUG_NEW(array46->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/4 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array46;
      array_t* array47 = func20(&params0, loopsFactor);
      DEBUG_RETURN(array47->id);
      free(params0.data);
      array47->refC--;
      if(array47->refC == 0) {
         free(array47->data);
         free(array47);
         DEBUG_FREE(array47->id);
      }
   }
   return array46;
}

