#include "array9_8.h" 
array_t* func24(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/3 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      array_t* array38;
      if (pCounter > 0) {
         array38 = vars->data[--pCounter];
         array38->refC++;
         DEBUG_COPY(array38->id);
      } else {
         array38 = (array_t*)malloc(sizeof(array_t));
         array38->size = 31;
         array38->refC = 1;
         array38->id = 38;
         array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
         memset(array38->data, 0, array38->size*sizeof(unsigned int));
         DEBUG_NEW(array38->id);
      }
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
   }
   array_t* array39;
   if (pCounter > 0) {
      array39 = vars->data[--pCounter];
      array39->refC++;
      DEBUG_COPY(array39->id);
   } else {
      array39 = (array_t*)malloc(sizeof(array_t));
      array39->size = 117;
      array39->refC = 1;
      array39->id = 39;
      array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
      memset(array39->data, 0, array39->size*sizeof(unsigned int));
      DEBUG_NEW(array39->id);
   }
   return array39;
}

