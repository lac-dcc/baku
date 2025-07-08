#include "array8_2.h" 
array_t* func22(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/4 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      array_t* array50;
      if (pCounter > 0) {
         array50 = vars->data[--pCounter];
         array50->refC++;
         DEBUG_COPY(array50->id);
      } else {
         array50 = (array_t*)malloc(sizeof(array_t));
         array50->size = 149;
         array50->refC = 1;
         array50->id = 50;
         array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
         memset(array50->data, 0, array50->size*sizeof(unsigned int));
         DEBUG_NEW(array50->id);
      }
      array50->refC--;
      if(array50->refC == 0) {
         free(array50->data);
         free(array50);
         DEBUG_FREE(array50->id);
      }
   }
   array_t* array51;
   if (pCounter > 0) {
      array51 = vars->data[--pCounter];
      array51->refC++;
      DEBUG_COPY(array51->id);
   } else {
      array51 = (array_t*)malloc(sizeof(array_t));
      array51->size = 796;
      array51->refC = 1;
      array51->id = 51;
      array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
      memset(array51->data, 0, array51->size*sizeof(unsigned int));
      DEBUG_NEW(array51->id);
   }
   return array51;
}

