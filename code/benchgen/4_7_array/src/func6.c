#include "outs/4_7_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop1 = 0;
      unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
      for(; loop1 < loopLimit1; loop1++) {
      }
   }
   else {
      array_t* array5;
      if (pCounter > 0) {
         array5 = vars->data[--pCounter];
         array5->refC++;
         DEBUG_COPY(array5->id);
      } else {
         array5 = (array_t*)malloc(sizeof(array_t));
         array5->size = 926;
         array5->refC = 1;
         array5->id = 5;
         array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
         memset(array5->data, 0, array5->size*sizeof(unsigned int));
         DEBUG_NEW(array5->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array5;
      array_t* array6 = func9(&params0, loopsFactor);
      DEBUG_RETURN(array6->id);
      free(params0.data);
      array6->refC--;
      if(array6->refC == 0) {
         free(array6->data);
         free(array6);
         DEBUG_FREE(array6->id);
      }
      array5->refC--;
      if(array5->refC == 0) {
         free(array5->data);
         free(array5);
         DEBUG_FREE(array5->id);
      }
   }
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
   array_t* array9;
   if (pCounter > 0) {
      array9 = vars->data[--pCounter];
      array9->refC++;
      DEBUG_COPY(array9->id);
   } else {
      array9 = (array_t*)malloc(sizeof(array_t));
      array9->size = 429;
      array9->refC = 1;
      array9->id = 9;
      array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
      memset(array9->data, 0, array9->size*sizeof(unsigned int));
      DEBUG_NEW(array9->id);
   }
   for (int i = 0; i < array8->size; i++) {
      array8->data[i]++;
   }
   unsigned int loop2 = 0;
   unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
   for(; loop2 < loopLimit2; loop2++) {
      for (int i = 0; i < array8->size; i++) {
         array8->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array8;
   params0.data[1] = array9;
   array_t* array10 = func10(&params0, loopsFactor);
   DEBUG_RETURN(array10->id);
   free(params0.data);
   array10->refC--;
   if(array10->refC == 0) {
      free(array10->data);
      free(array10);
      DEBUG_FREE(array10->id);
   }
   array9->refC--;
   if(array9->refC == 0) {
      free(array9->data);
      free(array9);
      DEBUG_FREE(array9->id);
   }
   return array8;
}

