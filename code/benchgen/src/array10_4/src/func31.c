#include "array10_4.h" 
array_t* func31(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t* array28;
      if (pCounter > 0) {
         array28 = vars->data[--pCounter];
         array28->refC++;
         DEBUG_COPY(array28->id);
      } else {
         array28 = (array_t*)malloc(sizeof(array_t));
         array28->size = 788;
         array28->refC = 1;
         array28->id = 28;
         array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
         memset(array28->data, 0, array28->size*sizeof(unsigned int));
         DEBUG_NEW(array28->id);
      }
      array28->refC--;
      if(array28->refC == 0) {
         free(array28->data);
         free(array28);
         DEBUG_FREE(array28->id);
      }
   }
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 584;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   return array29;
}

