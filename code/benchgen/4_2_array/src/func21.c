#include "outs/4_2_array.h" 
array_t* func21(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array27;
   if (pCounter > 0) {
      array27 = vars->data[--pCounter];
      array27->refC++;
      DEBUG_COPY(array27->id);
   } else {
      array27 = (array_t*)malloc(sizeof(array_t));
      array27->size = 895;
      array27->refC = 1;
      array27->id = 27;
      array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
      memset(array27->data, 0, array27->size*sizeof(unsigned int));
      DEBUG_NEW(array27->id);
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/3 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      for (int i = 0; i < array27->size; i++) {
         array27->data[i]--;
      }
   }
   return array27;
}

