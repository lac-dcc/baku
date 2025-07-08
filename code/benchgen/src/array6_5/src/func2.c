#include "array6_5.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array37;
   if (pCounter > 0) {
      array37 = vars->data[--pCounter];
      array37->refC++;
      DEBUG_COPY(array37->id);
   } else {
      array37 = (array_t*)malloc(sizeof(array_t));
      array37->size = 709;
      array37->refC = 1;
      array37->id = 37;
      array37->data = (unsigned int*)malloc(array37->size*sizeof(unsigned int));
      memset(array37->data, 0, array37->size*sizeof(unsigned int));
      DEBUG_NEW(array37->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/1 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      for (int i = 0; i < array37->size; i++) {
         array37->data[i]--;
      }
   }
   return array37;
}

