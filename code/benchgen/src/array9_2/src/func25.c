#include "array9_2.h" 
array_t* func25(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/5 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      array_t* array21;
      if (pCounter > 0) {
         array21 = vars->data[--pCounter];
         array21->refC++;
         DEBUG_COPY(array21->id);
      } else {
         array21 = (array_t*)malloc(sizeof(array_t));
         array21->size = 846;
         array21->refC = 1;
         array21->id = 21;
         array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
         memset(array21->data, 0, array21->size*sizeof(unsigned int));
         DEBUG_NEW(array21->id);
      }
      array21->refC--;
      if(array21->refC == 0) {
         free(array21->data);
         free(array21);
         DEBUG_FREE(array21->id);
      }
   }
   array_t* array22;
   if (pCounter > 0) {
      array22 = vars->data[--pCounter];
      array22->refC++;
      DEBUG_COPY(array22->id);
   } else {
      array22 = (array_t*)malloc(sizeof(array_t));
      array22->size = 729;
      array22->refC = 1;
      array22->id = 22;
      array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
      memset(array22->data, 0, array22->size*sizeof(unsigned int));
      DEBUG_NEW(array22->id);
   }
   return array22;
}

