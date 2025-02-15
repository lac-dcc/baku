#include "outs/4_2_array.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array57;
   if (pCounter > 0) {
      array57 = vars->data[--pCounter];
      array57->refC++;
      DEBUG_COPY(array57->id);
   } else {
      array57 = (array_t*)malloc(sizeof(array_t));
      array57->size = 871;
      array57->refC = 1;
      array57->id = 57;
      array57->data = (unsigned int*)malloc(array57->size*sizeof(unsigned int));
      memset(array57->data, 0, array57->size*sizeof(unsigned int));
      DEBUG_NEW(array57->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array57;
   array_t* array58 = func17(&params0, loopsFactor);
   DEBUG_RETURN(array58->id);
   free(params0.data);
   for (int i = 0; i < array58->size; i++) {
      if (array58->data[i] == 19) { 
         return array58;
      }
   }
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/3 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      for (int i = 0; i < array57->size; i++) {
         array57->data[i]--;
      }
      for (int i = 0; i < array57->size; i++) {
         if (array57->data[i] == 8) { 
            return array57;
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array57;
   params1.data[1] = array58;
   array_t* array59 = func18(&params1, loopsFactor);
   DEBUG_RETURN(array59->id);
   free(params1.data);
   array_t* array60;
   if (pCounter > 0) {
      array60 = vars->data[--pCounter];
      array60->refC++;
      DEBUG_COPY(array60->id);
   } else {
      array60 = (array_t*)malloc(sizeof(array_t));
      array60->size = 149;
      array60->refC = 1;
      array60->id = 60;
      array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
      memset(array60->data, 0, array60->size*sizeof(unsigned int));
      DEBUG_NEW(array60->id);
   }
   array_t* array61;
   if (pCounter > 0) {
      array61 = vars->data[--pCounter];
      array61->refC++;
      DEBUG_COPY(array61->id);
   } else {
      array61 = (array_t*)malloc(sizeof(array_t));
      array61->size = 796;
      array61->refC = 1;
      array61->id = 61;
      array61->data = (unsigned int*)malloc(array61->size*sizeof(unsigned int));
      memset(array61->data, 0, array61->size*sizeof(unsigned int));
      DEBUG_NEW(array61->id);
   }
   array61->refC--;
   if(array61->refC == 0) {
      free(array61->data);
      free(array61);
      DEBUG_FREE(array61->id);
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
   return array60;
}

