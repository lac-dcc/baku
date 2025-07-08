#include "array6_8.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/2 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array26;
      if (pCounter > 0) {
         array26 = vars->data[--pCounter];
         array26->refC++;
         DEBUG_COPY(array26->id);
      } else {
         array26 = (array_t*)malloc(sizeof(array_t));
         array26->size = 584;
         array26->refC = 1;
         array26->id = 26;
         array26->data = (unsigned int*)malloc(array26->size*sizeof(unsigned int));
         memset(array26->data, 0, array26->size*sizeof(unsigned int));
         DEBUG_NEW(array26->id);
      }
      array26->refC--;
      if(array26->refC == 0) {
         free(array26->data);
         free(array26);
         DEBUG_FREE(array26->id);
      }
   }
   array_t* array27;
   if (pCounter > 0) {
      array27 = vars->data[--pCounter];
      array27->refC++;
      DEBUG_COPY(array27->id);
   } else {
      array27 = (array_t*)malloc(sizeof(array_t));
      array27->size = 403;
      array27->refC = 1;
      array27->id = 27;
      array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
      memset(array27->data, 0, array27->size*sizeof(unsigned int));
      DEBUG_NEW(array27->id);
   }
   return array27;
}

