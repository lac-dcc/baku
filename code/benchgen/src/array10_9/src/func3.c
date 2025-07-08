#include "array10_9.h" 
array_t* func3(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array9;
   if (pCounter > 0) {
      array9 = vars->data[--pCounter];
      array9->refC++;
      DEBUG_COPY(array9->id);
   } else {
      array9 = (array_t*)malloc(sizeof(array_t));
      array9->size = 862;
      array9->refC = 1;
      array9->id = 9;
      array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
      memset(array9->data, 0, array9->size*sizeof(unsigned int));
      DEBUG_NEW(array9->id);
   }
   unsigned int loop6 = 0;
   unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
   for(; loop6 < loopLimit6; loop6++) {
      array_t* array10;
      if (pCounter > 0) {
         array10 = vars->data[--pCounter];
         array10->refC++;
         DEBUG_COPY(array10->id);
      } else {
         array10 = (array_t*)malloc(sizeof(array_t));
         array10->size = 123;
         array10->refC = 1;
         array10->id = 10;
         array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
         memset(array10->data, 0, array10->size*sizeof(unsigned int));
         DEBUG_NEW(array10->id);
      }
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/8 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         for (int i = 0; i < array10->size; i++) {
            array10->data[i]--;
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array9;
         params0.data[1] = array10;
         array_t* array11 = func4(&params0, loopsFactor);
         DEBUG_RETURN(array11->id);
         free(params0.data);
         array11->refC--;
         if(array11->refC == 0) {
            free(array11->data);
            free(array11);
            DEBUG_FREE(array11->id);
         }
      }
      array10->refC--;
      if(array10->refC == 0) {
         free(array10->data);
         free(array10);
         DEBUG_FREE(array10->id);
      }
   }
   return array9;
}

