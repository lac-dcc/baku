#include "array8_8.h" 
array_t* func17(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      array_t* array9;
      if (pCounter > 0) {
         array9 = vars->data[--pCounter];
         array9->refC++;
         DEBUG_COPY(array9->id);
      } else {
         array9 = (array_t*)malloc(sizeof(array_t));
         array9->size = 22;
         array9->refC = 1;
         array9->id = 9;
         array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
         memset(array9->data, 0, array9->size*sizeof(unsigned int));
         DEBUG_NEW(array9->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array9;
      array_t* array10 = func21(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array10->id);
      free(params0.data);
      array10->refC--;
      if(array10->refC == 0) {
         free(array10->data);
         free(array10);
         DEBUG_FREE(array10->id);
      }
      array9->refC--;
      if(array9->refC == 0) {
         free(array9->data);
         free(array9);
         DEBUG_FREE(array9->id);
      }
   }
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
   return array16;
}

