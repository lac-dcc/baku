#include "array7_8.h" 
array_t* func8(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array23;
      if (pCounter > 0) {
         array23 = vars->data[--pCounter];
         array23->refC++;
         DEBUG_COPY(array23->id);
      } else {
         array23 = (array_t*)malloc(sizeof(array_t));
         array23->size = 545;
         array23->refC = 1;
         array23->id = 23;
         array23->data = (unsigned int*)malloc(array23->size*sizeof(unsigned int));
         memset(array23->data, 0, array23->size*sizeof(unsigned int));
         DEBUG_NEW(array23->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array23;
      array_t* array24 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array24->id);
      free(params0.data);
      array24->refC--;
      if(array24->refC == 0) {
         free(array24->data);
         free(array24);
         DEBUG_FREE(array24->id);
      }
      array23->refC--;
      if(array23->refC == 0) {
         free(array23->data);
         free(array23);
         DEBUG_FREE(array23->id);
      }
   }
   array_t* array38;
   if (pCounter > 0) {
      array38 = vars->data[--pCounter];
      array38->refC++;
      DEBUG_COPY(array38->id);
   } else {
      array38 = (array_t*)malloc(sizeof(array_t));
      array38->size = 865;
      array38->refC = 1;
      array38->id = 38;
      array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
      memset(array38->data, 0, array38->size*sizeof(unsigned int));
      DEBUG_NEW(array38->id);
   }
   return array38;
}

