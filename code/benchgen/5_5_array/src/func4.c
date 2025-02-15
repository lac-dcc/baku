#include "outs/5_5_array.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/6 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      for (int i = 0; i < array16->size; i++) {
         array16->data[i]--;
      }
   }
   array17->refC--;
   if(array17->refC == 0) {
      free(array17->data);
      free(array17);
      DEBUG_FREE(array17->id);
   }
   return array16;
}

