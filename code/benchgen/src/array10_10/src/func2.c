#include "array10_10.h" 
array_t* func2(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array7;
   if (pCounter > 0) {
      array7 = vars->data[--pCounter];
      array7->refC++;
      DEBUG_COPY(array7->id);
   } else {
      array7 = (array_t*)malloc(sizeof(array_t));
      array7->size = 211;
      array7->refC = 1;
      array7->id = 7;
      array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
      memset(array7->data, 0, array7->size*sizeof(unsigned int));
      DEBUG_NEW(array7->id);
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      for (int i = 0; i < array7->size; i++) {
         array7->data[i]++;
      }
      unsigned int loop6 = 0;
      unsigned int loopLimit6 = (rand()%loopsFactor)/7 + 1;
      for(; loop6 < loopLimit6; loop6++) {
         array_t* array8;
         if (pCounter > 0) {
            array8 = vars->data[--pCounter];
            array8->refC++;
            DEBUG_COPY(array8->id);
         } else {
            array8 = (array_t*)malloc(sizeof(array_t));
            array8->size = 567;
            array8->refC = 1;
            array8->id = 8;
            array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
            memset(array8->data, 0, array8->size*sizeof(unsigned int));
            DEBUG_NEW(array8->id);
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array7;
         params0.data[1] = array8;
         array_t* array9 = func3(&params0, loopsFactor);
         DEBUG_RETURN(array9->id);
         free(params0.data);
         array9->refC--;
         if(array9->refC == 0) {
            free(array9->data);
            free(array9);
            DEBUG_FREE(array9->id);
         }
         array8->refC--;
         if(array8->refC == 0) {
            free(array8->data);
            free(array8);
            DEBUG_FREE(array8->id);
         }
      }
   }
   return array7;
}

