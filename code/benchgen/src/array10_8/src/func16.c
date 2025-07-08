#include "array10_8.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      array_t* array35;
      if (pCounter > 0) {
         array35 = vars->data[--pCounter];
         array35->refC++;
         DEBUG_COPY(array35->id);
      } else {
         array35 = (array_t*)malloc(sizeof(array_t));
         array35->size = 652;
         array35->refC = 1;
         array35->id = 35;
         array35->data = (unsigned int*)malloc(array35->size*sizeof(unsigned int));
         memset(array35->data, 0, array35->size*sizeof(unsigned int));
         DEBUG_NEW(array35->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array35;
      array_t* array36 = func18(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array36->id);
      free(params0.data);
      array36->refC--;
      if(array36->refC == 0) {
         free(array36->data);
         free(array36);
         DEBUG_FREE(array36->id);
      }
      array35->refC--;
      if(array35->refC == 0) {
         free(array35->data);
         free(array35);
         DEBUG_FREE(array35->id);
      }
   }
   array_t* array50;
   if (pCounter > 0) {
      array50 = vars->data[--pCounter];
      array50->refC++;
      DEBUG_COPY(array50->id);
   } else {
      array50 = (array_t*)malloc(sizeof(array_t));
      array50->size = 723;
      array50->refC = 1;
      array50->id = 50;
      array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
      memset(array50->data, 0, array50->size*sizeof(unsigned int));
      DEBUG_NEW(array50->id);
   }
   return array50;
}

