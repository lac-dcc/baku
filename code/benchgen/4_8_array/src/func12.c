#include "outs/4_8_array.h" 
array_t* func12(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t* array7;
      if (pCounter > 0) {
         array7 = vars->data[--pCounter];
         array7->refC++;
         DEBUG_COPY(array7->id);
      } else {
         array7 = (array_t*)malloc(sizeof(array_t));
         array7->size = 530;
         array7->refC = 1;
         array7->id = 7;
         array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
         memset(array7->data, 0, array7->size*sizeof(unsigned int));
         DEBUG_NEW(array7->id);
      }
      unsigned int loop4 = 0;
      unsigned int loopLimit4 = (rand()%loopsFactor)/3 + 1;
      for(; loop4 < loopLimit4; loop4++) {
         for (int i = 0; i < array7->size; i++) {
            array7->data[i]--;
         }
         for (int i = 0; i < array7->size; i++) {
            if (array7->data[i] == 67) { 
               return array7;
            }
         }
      }
      array7->refC--;
      if(array7->refC == 0) {
         free(array7->data);
         free(array7);
         DEBUG_FREE(array7->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array8 = func16(&params0, loopsFactor);
      DEBUG_RETURN(array8->id);
      free(params0.data);
      array8->refC--;
      if(array8->refC == 0) {
         free(array8->data);
         free(array8);
         DEBUG_FREE(array8->id);
      }
   }
   array_t* array10;
   if (pCounter > 0) {
      array10 = vars->data[--pCounter];
      array10->refC++;
      DEBUG_COPY(array10->id);
   } else {
      array10 = (array_t*)malloc(sizeof(array_t));
      array10->size = 11;
      array10->refC = 1;
      array10->id = 10;
      array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
      memset(array10->data, 0, array10->size*sizeof(unsigned int));
      DEBUG_NEW(array10->id);
   }
   return array10;
}

