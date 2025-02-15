#include "outs/3_2_array.h" 
array_t* func8(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array51 = func15(&params0, loopsFactor);
   DEBUG_RETURN(array51->id);
   free(params0.data);
   for (int i = 0; i < array51->size; i++) {
      if (array51->data[i] == 97) { 
         return array51;
      }
   }
   unsigned int loop13 = 0;
   unsigned int loopLimit13 = (rand()%loopsFactor)/3 + 1;
   for(; loop13 < loopLimit13; loop13++) {
      for (int i = 0; i < array51->size; i++) {
         array51->data[i]--;
      }
      for (int i = 0; i < array51->size; i++) {
         if (array51->data[i] == 65) { 
            return array51;
         }
      }
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array51;
   array_t* array52 = func16(&params1, loopsFactor);
   DEBUG_RETURN(array52->id);
   free(params1.data);
   array_t* array53;
   if (pCounter > 0) {
      array53 = vars->data[--pCounter];
      array53->refC++;
      DEBUG_COPY(array53->id);
   } else {
      array53 = (array_t*)malloc(sizeof(array_t));
      array53->size = 219;
      array53->refC = 1;
      array53->id = 53;
      array53->data = (unsigned int*)malloc(array53->size*sizeof(unsigned int));
      memset(array53->data, 0, array53->size*sizeof(unsigned int));
      DEBUG_NEW(array53->id);
   }
   array_t* array54;
   if (pCounter > 0) {
      array54 = vars->data[--pCounter];
      array54->refC++;
      DEBUG_COPY(array54->id);
   } else {
      array54 = (array_t*)malloc(sizeof(array_t));
      array54->size = 624;
      array54->refC = 1;
      array54->id = 54;
      array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
      memset(array54->data, 0, array54->size*sizeof(unsigned int));
      DEBUG_NEW(array54->id);
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
   array52->refC--;
   if(array52->refC == 0) {
      free(array52->data);
      free(array52);
      DEBUG_FREE(array52->id);
   }
   return array51;
}

