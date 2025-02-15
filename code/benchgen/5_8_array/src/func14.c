#include "outs/5_8_array.h" 
array_t* func14(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array56;
   if (pCounter > 0) {
      array56 = vars->data[--pCounter];
      array56->refC++;
      DEBUG_COPY(array56->id);
   } else {
      array56 = (array_t*)malloc(sizeof(array_t));
      array56->size = 793;
      array56->refC = 1;
      array56->id = 56;
      array56->data = (unsigned int*)malloc(array56->size*sizeof(unsigned int));
      memset(array56->data, 0, array56->size*sizeof(unsigned int));
      DEBUG_NEW(array56->id);
   }
   unsigned int loop17 = 0;
   unsigned int loopLimit17 = (rand()%loopsFactor)/3 + 1;
   for(; loop17 < loopLimit17; loop17++) {
      if(PATH0 & 1) {
         array_t* array57;
         if (pCounter > 0) {
            array57 = vars->data[--pCounter];
            array57->refC++;
            DEBUG_COPY(array57->id);
         } else {
            array57 = (array_t*)malloc(sizeof(array_t));
            array57->size = 818;
            array57->refC = 1;
            array57->id = 57;
            array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
            memset(array57->data, 0, array57->size*sizeof(unsigned int));
            DEBUG_NEW(array57->id);
         }
         unsigned int loop18 = 0;
         unsigned int loopLimit18 = (rand()%loopsFactor)/4 + 1;
         for(; loop18 < loopLimit18; loop18++) {
            for (int i = 0; i < array56->size; i++) {
               array56->data[i]--;
            }
            for (int i = 0; i < array57->size; i++) {
               if (array57->data[i] == 11) { 
                  return array57;
               }
            }
         }
         array57->refC--;
         if(array57->refC == 0) {
            free(array57->data);
            free(array57);
            DEBUG_FREE(array57->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array56;
         array_t* array58 = func22(&params0, loopsFactor);
         DEBUG_RETURN(array58->id);
         free(params0.data);
         array58->refC--;
         if(array58->refC == 0) {
            free(array58->data);
            free(array58);
            DEBUG_FREE(array58->id);
         }
      }
      array_t* array59;
      if (pCounter > 0) {
         array59 = vars->data[--pCounter];
         array59->refC++;
         DEBUG_COPY(array59->id);
      } else {
         array59 = (array_t*)malloc(sizeof(array_t));
         array59->size = 776;
         array59->refC = 1;
         array59->id = 59;
         array59->data = (unsigned int*)malloc(array59->size*sizeof(unsigned int));
         memset(array59->data, 0, array59->size*sizeof(unsigned int));
         DEBUG_NEW(array59->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array56;
      params0.data[1] = array59;
      array_t* array60 = func23(&params0, loopsFactor);
      DEBUG_RETURN(array60->id);
      free(params0.data);
      for (int i = 0; i < array59->size; i++) {
         if (array59->data[i] == 13) { 
            return array59;
         }
      }
      array60->refC--;
      if(array60->refC == 0) {
         free(array60->data);
         free(array60);
         DEBUG_FREE(array60->id);
      }
      array59->refC--;
      if(array59->refC == 0) {
         free(array59->data);
         free(array59);
         DEBUG_FREE(array59->id);
      }
   }
   for (int i = 0; i < array56->size; i++) {
      array56->data[i]--;
   }
   for (int i = 0; i < array56->size; i++) {
      if (array56->data[i] == 40) { 
         return array56;
      }
   }
   return array56;
}

