#include "array8_2.h" 
array_t* func19(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/4 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array16;
      if (pCounter > 0) {
         array16 = vars->data[--pCounter];
         array16->refC++;
         DEBUG_COPY(array16->id);
      } else {
         array16 = (array_t*)malloc(sizeof(array_t));
         array16->size = 526;
         array16->refC = 1;
         array16->id = 16;
         array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
         memset(array16->data, 0, array16->size*sizeof(unsigned int));
         DEBUG_NEW(array16->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array16;
      array_t* array17 = func23(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array17->id);
      free(params0.data);
      for (int i = 0; i < array16->size; i++) {
         array16->data[i]++;
      }
      array17->refC--;
      if(array17->refC == 0) {
         free(array17->data);
         free(array17);
         DEBUG_FREE(array17->id);
      }
      array16->refC--;
      if(array16->refC == 0) {
         free(array16->data);
         free(array16);
         DEBUG_FREE(array16->id);
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

