#include "outs/4_5_array.h" 
array_t* func4(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array9;
   if (pCounter > 0) {
      array9 = vars->data[--pCounter];
      array9->refC++;
      DEBUG_COPY(array9->id);
   } else {
      array9 = (array_t*)malloc(sizeof(array_t));
      array9->size = 530;
      array9->refC = 1;
      array9->id = 9;
      array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
      memset(array9->data, 0, array9->size*sizeof(unsigned int));
      DEBUG_NEW(array9->id);
   }
   array_t* array10;
   if (pCounter > 0) {
      array10 = vars->data[--pCounter];
      array10->refC++;
      DEBUG_COPY(array10->id);
   } else {
      array10 = (array_t*)malloc(sizeof(array_t));
      array10->size = 862;
      array10->refC = 1;
      array10->id = 10;
      array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
      memset(array10->data, 0, array10->size*sizeof(unsigned int));
      DEBUG_NEW(array10->id);
   }
   unsigned int loop7 = 0;
   unsigned int loopLimit7 = (rand()%loopsFactor)/6 + 1;
   for(; loop7 < loopLimit7; loop7++) {
      for (int i = 0; i < array10->size; i++) {
         array10->data[i]--;
      }
   }
   array9->refC--;
   if(array9->refC == 0) {
      free(array9->data);
      free(array9);
      DEBUG_FREE(array9->id);
   }
   return array10;
}

