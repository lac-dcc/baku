#include "array7_2.h" 
array_t* func10(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop5 = 0;
   unsigned int loopLimit5 = (rand()%loopsFactor)/2 + 1;
   for(; loop5 < loopLimit5; loop5++) {
      array_t* array34;
      if (pCounter > 0) {
         array34 = vars->data[--pCounter];
         array34->refC++;
         DEBUG_COPY(array34->id);
      } else {
         array34 = (array_t*)malloc(sizeof(array_t));
         array34->size = 434;
         array34->refC = 1;
         array34->id = 34;
         array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
         memset(array34->data, 0, array34->size*sizeof(unsigned int));
         DEBUG_NEW(array34->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array34;
      array_t* array35 = func14(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array35->id);
      free(params0.data);
      for (int i = 0; i < array35->size; i++) {
         array35->data[i]++;
      }
      array35->refC--;
      if(array35->refC == 0) {
         free(array35->data);
         free(array35);
         DEBUG_FREE(array35->id);
      }
      array34->refC--;
      if(array34->refC == 0) {
         free(array34->data);
         free(array34);
         DEBUG_FREE(array34->id);
      }
   }
   array_t* array48;
   if (pCounter > 0) {
      array48 = vars->data[--pCounter];
      array48->refC++;
      DEBUG_COPY(array48->id);
   } else {
      array48 = (array_t*)malloc(sizeof(array_t));
      array48->size = 732;
      array48->refC = 1;
      array48->id = 48;
      array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
      memset(array48->data, 0, array48->size*sizeof(unsigned int));
      DEBUG_NEW(array48->id);
   }
   return array48;
}

