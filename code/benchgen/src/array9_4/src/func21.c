#include "array9_4.h" 
array_t* func21(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/6 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      array_t* array19;
      if (pCounter > 0) {
         array19 = vars->data[--pCounter];
         array19->refC++;
         DEBUG_COPY(array19->id);
      } else {
         array19 = (array_t*)malloc(sizeof(array_t));
         array19->size = 996;
         array19->refC = 1;
         array19->id = 19;
         array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
         memset(array19->data, 0, array19->size*sizeof(unsigned int));
         DEBUG_NEW(array19->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array19;
      array_t* array20 = func26(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array20->id);
      free(params0.data);
      array20->refC--;
      if(array20->refC == 0) {
         free(array20->data);
         free(array20);
         DEBUG_FREE(array20->id);
      }
      array19->refC--;
      if(array19->refC == 0) {
         free(array19->data);
         free(array19);
         DEBUG_FREE(array19->id);
      }
   }
   array_t* array29;
   if (pCounter > 0) {
      array29 = vars->data[--pCounter];
      array29->refC++;
      DEBUG_COPY(array29->id);
   } else {
      array29 = (array_t*)malloc(sizeof(array_t));
      array29->size = 754;
      array29->refC = 1;
      array29->id = 29;
      array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
      memset(array29->data, 0, array29->size*sizeof(unsigned int));
      DEBUG_NEW(array29->id);
   }
   return array29;
}

