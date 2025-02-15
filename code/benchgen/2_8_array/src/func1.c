#include "outs/2_8_array.h" 
array_t* func1(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array20;
   if (pCounter > 0) {
      array20 = vars->data[--pCounter];
      array20->refC++;
      DEBUG_COPY(array20->id);
   } else {
      array20 = (array_t*)malloc(sizeof(array_t));
      array20->size = 434;
      array20->refC = 1;
      array20->id = 20;
      array20->data = (unsigned int*)malloc(array20->size*sizeof(unsigned int));
      memset(array20->data, 0, array20->size*sizeof(unsigned int));
      DEBUG_NEW(array20->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array20;
   array_t* array21 = func3(&params0, loopsFactor);
   DEBUG_RETURN(array21->id);
   free(params0.data);
   if(PATH0 & 1) {
      array_t* array24;
      if (pCounter > 0) {
         array24 = vars->data[--pCounter];
         array24->refC++;
         DEBUG_COPY(array24->id);
      } else {
         array24 = (array_t*)malloc(sizeof(array_t));
         array24->size = 754;
         array24->refC = 1;
         array24->id = 24;
         array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
         memset(array24->data, 0, array24->size*sizeof(unsigned int));
         DEBUG_NEW(array24->id);
      }
      unsigned int loop7 = 0;
      unsigned int loopLimit7 = (rand()%loopsFactor)/2 + 1;
      for(; loop7 < loopLimit7; loop7++) {
         for (int i = 0; i < array21->size; i++) {
            array21->data[i]--;
         }
         for (int i = 0; i < array20->size; i++) {
            if (array20->data[i] == 60) { 
               return array20;
            }
         }
      }
      array24->refC--;
      if(array24->refC == 0) {
         free(array24->data);
         free(array24);
         DEBUG_FREE(array24->id);
      }
   }
   else {
      array_t_param params1;
      params1.size = 2;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array20;
      params1.data[1] = array21;
      array_t* array25 = func4(&params1, loopsFactor);
      DEBUG_RETURN(array25->id);
      free(params1.data);
      array25->refC--;
      if(array25->refC == 0) {
         free(array25->data);
         free(array25);
         DEBUG_FREE(array25->id);
      }
   }
   array20->refC--;
   if(array20->refC == 0) {
      free(array20->data);
      free(array20);
      DEBUG_FREE(array20->id);
   }
   return array21;
}

