#include "array7_2.h" 
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
      array16->refC--;
      if(array16->refC == 0) {
         free(array16->data);
         free(array16);
         DEBUG_FREE(array16->id);
      }
   }
   array_t* array17;
   if (pCounter > 0) {
      array17 = vars->data[--pCounter];
      array17->refC++;
      DEBUG_COPY(array17->id);
   } else {
      array17 = (array_t*)malloc(sizeof(array_t));
      array17->size = 91;
      array17->refC = 1;
      array17->id = 17;
      array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
      memset(array17->data, 0, array17->size*sizeof(unsigned int));
      DEBUG_NEW(array17->id);
   }
   return array17;
}

