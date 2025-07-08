#include "array10_2.h" 
array_t* func28(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/5 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      array_t* array62;
      if (pCounter > 0) {
         array62 = vars->data[--pCounter];
         array62->refC++;
         DEBUG_COPY(array62->id);
      } else {
         array62 = (array_t*)malloc(sizeof(array_t));
         array62->size = 474;
         array62->refC = 1;
         array62->id = 62;
         array62->data = (unsigned int*)malloc(array62->size*sizeof(unsigned int));
         memset(array62->data, 0, array62->size*sizeof(unsigned int));
         DEBUG_NEW(array62->id);
      }
      array62->refC--;
      if(array62->refC == 0) {
         free(array62->data);
         free(array62);
         DEBUG_FREE(array62->id);
      }
   }
   array_t* array63;
   if (pCounter > 0) {
      array63 = vars->data[--pCounter];
      array63->refC++;
      DEBUG_COPY(array63->id);
   } else {
      array63 = (array_t*)malloc(sizeof(array_t));
      array63->size = 121;
      array63->refC = 1;
      array63->id = 63;
      array63->data = (unsigned int*)malloc(array63->size*sizeof(unsigned int));
      memset(array63->data, 0, array63->size*sizeof(unsigned int));
      DEBUG_NEW(array63->id);
   }
   return array63;
}

