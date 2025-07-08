#include "array10_5.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array57;
   if (pCounter > 0) {
      array57 = vars->data[--pCounter];
      array57->refC++;
      DEBUG_COPY(array57->id);
   } else {
      array57 = (array_t*)malloc(sizeof(array_t));
      array57->size = 776;
      array57->refC = 1;
      array57->id = 57;
      array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
      memset(array57->data, 0, array57->size*sizeof(unsigned int));
      DEBUG_NEW(array57->id);
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/1 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      for (int i = 0; i < array57->size; i++) {
         array57->data[i]--;
      }
   }
   return array57;
}

