#include "outs/5_7_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array52;
   if (pCounter > 0) {
      array52 = vars->data[--pCounter];
      array52->refC++;
      DEBUG_COPY(array52->id);
   } else {
      array52 = (array_t*)malloc(sizeof(array_t));
      array52->size = 567;
      array52->refC = 1;
      array52->id = 52;
      array52->data = (unsigned int*)malloc(array52->size*sizeof(unsigned int));
      memset(array52->data, 0, array52->size*sizeof(unsigned int));
      DEBUG_NEW(array52->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array52;
   array_t* array53 = func12(&params0, loopsFactor);
   DEBUG_RETURN(array53->id);
   free(params0.data);
   array_t* array54;
   if (pCounter > 0) {
      array54 = vars->data[--pCounter];
      array54->refC++;
      DEBUG_COPY(array54->id);
   } else {
      array54 = (array_t*)malloc(sizeof(array_t));
      array54->size = 353;
      array54->refC = 1;
      array54->id = 54;
      array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
      memset(array54->data, 0, array54->size*sizeof(unsigned int));
      DEBUG_NEW(array54->id);
   }
   if(PATH0 & 1) {
      unsigned int loop13 = 0;
      unsigned int loopLimit13 = (rand()%loopsFactor)/2 + 1;
      for(; loop13 < loopLimit13; loop13++) {
      }
   }
   else {
      array_t* array55;
      if (pCounter > 0) {
         array55 = vars->data[--pCounter];
         array55->refC++;
         DEBUG_COPY(array55->id);
      } else {
         array55 = (array_t*)malloc(sizeof(array_t));
         array55->size = 586;
         array55->refC = 1;
         array55->id = 55;
         array55->data = (unsigned int*)malloc(array55->size*sizeof(unsigned int));
         memset(array55->data, 0, array55->size*sizeof(unsigned int));
         DEBUG_NEW(array55->id);
      }
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array52;
      params1.data[1] = array53;
      params1.data[2] = array54;
      params1.data[3] = array55;
      array_t* array56 = func13(&params1, loopsFactor);
      DEBUG_RETURN(array56->id);
      free(params1.data);
      array56->refC--;
      if(array56->refC == 0) {
         free(array56->data);
         free(array56);
         DEBUG_FREE(array56->id);
      }
      array55->refC--;
      if(array55->refC == 0) {
         free(array55->data);
         free(array55);
         DEBUG_FREE(array55->id);
      }
   }
   for (int i = 0; i < array54->size; i++) {
      if (array54->data[i] == 19) { 
         return array54;
      }
   }
   array_t* array57;
   if (pCounter > 0) {
      array57 = vars->data[--pCounter];
      array57->refC++;
      DEBUG_COPY(array57->id);
   } else {
      array57 = (array_t*)malloc(sizeof(array_t));
      array57->size = 624;
      array57->refC = 1;
      array57->id = 57;
      array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
      memset(array57->data, 0, array57->size*sizeof(unsigned int));
      DEBUG_NEW(array57->id);
   }
   array_t* array58;
   if (pCounter > 0) {
      array58 = vars->data[--pCounter];
      array58->refC++;
      DEBUG_COPY(array58->id);
   } else {
      array58 = (array_t*)malloc(sizeof(array_t));
      array58->size = 528;
      array58->refC = 1;
      array58->id = 58;
      array58->data = (unsigned int*)malloc(array58->size*sizeof(unsigned int));
      memset(array58->data, 0, array58->size*sizeof(unsigned int));
      DEBUG_NEW(array58->id);
   }
   for (int i = 0; i < array53->size; i++) {
      array53->data[i]++;
   }
   unsigned int loop14 = 0;
   unsigned int loopLimit14 = (rand()%loopsFactor)/2 + 1;
   for(; loop14 < loopLimit14; loop14++) {
      for (int i = 0; i < array54->size; i++) {
         array54->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 5;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array52;
   params1.data[1] = array53;
   params1.data[2] = array54;
   params1.data[3] = array57;
   params1.data[4] = array58;
   array_t* array59 = func14(&params1, loopsFactor);
   DEBUG_RETURN(array59->id);
   free(params1.data);
   for (int i = 0; i < array59->size; i++) {
      if (array59->data[i] == 70) { 
         return array59;
      }
   }
   array59->refC--;
   if(array59->refC == 0) {
      free(array59->data);
      free(array59);
      DEBUG_FREE(array59->id);
   }
   array58->refC--;
   if(array58->refC == 0) {
      free(array58->data);
      free(array58);
      DEBUG_FREE(array58->id);
   }
   array57->refC--;
   if(array57->refC == 0) {
      free(array57->data);
      free(array57);
      DEBUG_FREE(array57->id);
   }
   array54->refC--;
   if(array54->refC == 0) {
      free(array54->data);
      free(array54);
      DEBUG_FREE(array54->id);
   }
   array53->refC--;
   if(array53->refC == 0) {
      free(array53->data);
      free(array53);
      DEBUG_FREE(array53->id);
   }
   return array52;
}

