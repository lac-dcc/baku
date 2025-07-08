#include "array6_4.h" 
array_t* func20(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/5 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      array_t* array40;
      if (pCounter > 0) {
         array40 = vars->data[--pCounter];
         array40->refC++;
         DEBUG_COPY(array40->id);
      } else {
         array40 = (array_t*)malloc(sizeof(array_t));
         array40->size = 117;
         array40->refC = 1;
         array40->id = 40;
         array40->data = (unsigned int*)malloc(array40->size*sizeof(unsigned int));
         memset(array40->data, 0, array40->size*sizeof(unsigned int));
         DEBUG_NEW(array40->id);
      }
      array40->refC--;
      if(array40->refC == 0) {
         free(array40->data);
         free(array40);
         DEBUG_FREE(array40->id);
      }
   }
   array_t* array41;
   if (pCounter > 0) {
      array41 = vars->data[--pCounter];
      array41->refC++;
      DEBUG_COPY(array41->id);
   } else {
      array41 = (array_t*)malloc(sizeof(array_t));
      array41->size = 97;
      array41->refC = 1;
      array41->id = 41;
      array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
      memset(array41->data, 0, array41->size*sizeof(unsigned int));
      DEBUG_NEW(array41->id);
   }
   return array41;
}

