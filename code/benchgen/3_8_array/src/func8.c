#include "outs/3_8_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t* array25;
      if (pCounter > 0) {
         array25 = vars->data[--pCounter];
         array25->refC++;
         DEBUG_COPY(array25->id);
      } else {
         array25 = (array_t*)malloc(sizeof(array_t));
         array25->size = 676;
         array25->refC = 1;
         array25->id = 25;
         array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
         memset(array25->data, 0, array25->size*sizeof(unsigned int));
         DEBUG_NEW(array25->id);
      }
      unsigned int loop8 = 0;
      unsigned int loopLimit8 = (rand()%loopsFactor)/2 + 1;
      for(; loop8 < loopLimit8; loop8++) {
         for (int i = 0; i < array25->size; i++) {
            array25->data[i]--;
         }
         for (int i = 0; i < array25->size; i++) {
            if (array25->data[i] == 12) { 
               return array25;
            }
         }
      }
      array25->refC--;
      if(array25->refC == 0) {
         free(array25->data);
         free(array25);
         DEBUG_FREE(array25->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array26 = func14(&params0, loopsFactor);
      DEBUG_RETURN(array26->id);
      free(params0.data);
      array26->refC--;
      if(array26->refC == 0) {
         free(array26->data);
         free(array26);
         DEBUG_FREE(array26->id);
      }
   }
   array_t* array27;
   if (pCounter > 0) {
      array27 = vars->data[--pCounter];
      array27->refC++;
      DEBUG_COPY(array27->id);
   } else {
      array27 = (array_t*)malloc(sizeof(array_t));
      array27->size = 94;
      array27->refC = 1;
      array27->id = 27;
      array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
      memset(array27->data, 0, array27->size*sizeof(unsigned int));
      DEBUG_NEW(array27->id);
   }
   return array27;
}

