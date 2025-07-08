#include "array9_8.h" 
array_t* func16(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop4 = 0;
   unsigned int loopLimit4 = (rand()%loopsFactor)/2 + 1;
   for(; loop4 < loopLimit4; loop4++) {
      array_t* array34;
      if (pCounter > 0) {
         array34 = vars->data[--pCounter];
         array34->refC++;
         DEBUG_COPY(array34->id);
      } else {
         array34 = (array_t*)malloc(sizeof(array_t));
         array34->size = 492;
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
      array_t* array35 = func18(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array35->id);
      free(params0.data);
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
   array_t* array43;
   if (pCounter > 0) {
      array43 = vars->data[--pCounter];
      array43->refC++;
      DEBUG_COPY(array43->id);
   } else {
      array43 = (array_t*)malloc(sizeof(array_t));
      array43->size = 586;
      array43->refC = 1;
      array43->id = 43;
      array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
      memset(array43->data, 0, array43->size*sizeof(unsigned int));
      DEBUG_NEW(array43->id);
   }
   return array43;
}

