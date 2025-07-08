#include "array10_2.h" 
array_t* func9(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array45;
   if (pCounter > 0) {
      array45 = vars->data[--pCounter];
      array45->refC++;
      DEBUG_COPY(array45->id);
   } else {
      array45 = (array_t*)malloc(sizeof(array_t));
      array45->size = 965;
      array45->refC = 1;
      array45->id = 45;
      array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
      memset(array45->data, 0, array45->size*sizeof(unsigned int));
      DEBUG_NEW(array45->id);
   }
   return array45;
}

