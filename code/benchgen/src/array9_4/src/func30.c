#include "array9_4.h" 
array_t* func30(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/7 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      array_t* array59;
      if (pCounter > 0) {
         array59 = vars->data[--pCounter];
         array59->refC++;
         DEBUG_COPY(array59->id);
      } else {
         array59 = (array_t*)malloc(sizeof(array_t));
         array59->size = 936;
         array59->refC = 1;
         array59->id = 59;
         array59->data = (unsigned int*)malloc(array59->size*sizeof(unsigned int));
         memset(array59->data, 0, array59->size*sizeof(unsigned int));
         DEBUG_NEW(array59->id);
      }
      array59->refC--;
      if(array59->refC == 0) {
         free(array59->data);
         free(array59);
         DEBUG_FREE(array59->id);
      }
   }
   array_t* array60;
   if (pCounter > 0) {
      array60 = vars->data[--pCounter];
      array60->refC++;
      DEBUG_COPY(array60->id);
   } else {
      array60 = (array_t*)malloc(sizeof(array_t));
      array60->size = 432;
      array60->refC = 1;
      array60->id = 60;
      array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
      memset(array60->data, 0, array60->size*sizeof(unsigned int));
      DEBUG_NEW(array60->id);
   }
   return array60;
}

