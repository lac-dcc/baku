#include "outs/5_5_array.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array27;
   if (pCounter > 0) {
      array27 = vars->data[--pCounter];
      array27->refC++;
      DEBUG_COPY(array27->id);
   } else {
      array27 = (array_t*)malloc(sizeof(array_t));
      array27->size = 584;
      array27->refC = 1;
      array27->id = 27;
      array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
      memset(array27->data, 0, array27->size*sizeof(unsigned int));
      DEBUG_NEW(array27->id);
   }
   array_t* array28;
   if (pCounter > 0) {
      array28 = vars->data[--pCounter];
      array28->refC++;
      DEBUG_COPY(array28->id);
   } else {
      array28 = (array_t*)malloc(sizeof(array_t));
      array28->size = 403;
      array28->refC = 1;
      array28->id = 28;
      array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
      memset(array28->data, 0, array28->size*sizeof(unsigned int));
      DEBUG_NEW(array28->id);
   }
   unsigned int loop15 = 0;
   unsigned int loopLimit15 = (rand()%loopsFactor)/4 + 1;
   for(; loop15 < loopLimit15; loop15++) {
      for (int i = 0; i < array28->size; i++) {
         array28->data[i]--;
      }
   }
   array28->refC--;
   if(array28->refC == 0) {
      free(array28->data);
      free(array28);
      DEBUG_FREE(array28->id);
   }
   return array27;
}

