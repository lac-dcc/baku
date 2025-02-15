#include "outs/3_7_array.h" 
array_t* func5(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/1 + 1;
      for(; loop4 < loopLimit4; loop4++) {
      }
   }
   else {
      array_t* array22;
      if (pCounter > 0) {
         array22 = vars->data[--pCounter];
         array22->refC++;
         DEBUG_COPY(array22->id);
      } else {
         array22 = (array_t*)malloc(sizeof(array_t));
         array22->size = 925;
         array22->refC = 1;
         array22->id = 22;
         array22->data = (unsigned int*)malloc(array22->size*sizeof(unsigned int));
         memset(array22->data, 0, array22->size*sizeof(unsigned int));
         DEBUG_NEW(array22->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array22;
      array_t* array23 = func7(&params0, loopsFactor);
      DEBUG_RETURN(array23->id);
      free(params0.data);
      array23->refC--;
      if(array23->refC == 0) {
         free(array23->data);
         free(array23);
         DEBUG_FREE(array23->id);
      }
      array22->refC--;
      if(array22->refC == 0) {
         free(array22->data);
         free(array22);
         DEBUG_FREE(array22->id);
      }
   }
   array_t* array24;
   if (pCounter > 0) {
      array24 = vars->data[--pCounter];
      array24->refC++;
      DEBUG_COPY(array24->id);
   } else {
      array24 = (array_t*)malloc(sizeof(array_t));
      array24->size = 336;
      array24->refC = 1;
      array24->id = 24;
      array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
      memset(array24->data, 0, array24->size*sizeof(unsigned int));
      DEBUG_NEW(array24->id);
   }
   array_t* array25;
   if (pCounter > 0) {
      array25 = vars->data[--pCounter];
      array25->refC++;
      DEBUG_COPY(array25->id);
   } else {
      array25 = (array_t*)malloc(sizeof(array_t));
      array25->size = 505;
      array25->refC = 1;
      array25->id = 25;
      array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
      memset(array25->data, 0, array25->size*sizeof(unsigned int));
      DEBUG_NEW(array25->id);
   }
   for (int i = 0; i < array24->size; i++) {
      array24->data[i]++;
   }
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/1 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      for (int i = 0; i < array25->size; i++) {
         array25->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array24;
   params0.data[1] = array25;
   array_t* array26 = func8(&params0, loopsFactor);
   DEBUG_RETURN(array26->id);
   free(params0.data);
   array26->refC--;
   if(array26->refC == 0) {
      free(array26->data);
      free(array26);
      DEBUG_FREE(array26->id);
   }
   array25->refC--;
   if(array25->refC == 0) {
      free(array25->data);
      free(array25);
      DEBUG_FREE(array25->id);
   }
   return array24;
}

