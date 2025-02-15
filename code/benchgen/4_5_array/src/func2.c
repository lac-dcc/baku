#include "outs/4_5_array.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array20;
   if (pCounter > 0) {
      array20 = vars->data[--pCounter];
      array20->refC++;
      DEBUG_COPY(array20->id);
   } else {
      array20 = (array_t*)malloc(sizeof(array_t));
      array20->size = 281;
      array20->refC = 1;
      array20->id = 20;
      array20->data = (unsigned int*)malloc(array20->size*sizeof(unsigned int));
      memset(array20->data, 0, array20->size*sizeof(unsigned int));
      DEBUG_NEW(array20->id);
   }
   array_t* array21;
   if (pCounter > 0) {
      array21 = vars->data[--pCounter];
      array21->refC++;
      DEBUG_COPY(array21->id);
   } else {
      array21 = (array_t*)malloc(sizeof(array_t));
      array21->size = 305;
      array21->refC = 1;
      array21->id = 21;
      array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
      memset(array21->data, 0, array21->size*sizeof(unsigned int));
      DEBUG_NEW(array21->id);
   }
   unsigned int loop12 = 0;
   unsigned int loopLimit12 = (rand()%loopsFactor)/4 + 1;
   for(; loop12 < loopLimit12; loop12++) {
      for (int i = 0; i < array21->size; i++) {
         array21->data[i]--;
      }
   }
   array21->refC--;
   if(array21->refC == 0) {
      free(array21->data);
      free(array21);
      DEBUG_FREE(array21->id);
   }
   return array20;
}

