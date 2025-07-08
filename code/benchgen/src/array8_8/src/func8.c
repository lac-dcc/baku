#include "array8_8.h" 
array_t* func8(array_t_param* vars, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop3 = 0;
   unsigned int loopLimit3 = (rand()%loopsFactor)/1 + 1;
   for(; loop3 < loopLimit3; loop3++) {
      array_t* array29;
      if (pCounter > 0) {
         array29 = vars->data[--pCounter];
         array29->refC++;
         DEBUG_COPY(array29->id);
      } else {
         array29 = (array_t*)malloc(sizeof(array_t));
         array29->size = 60;
         array29->refC = 1;
         array29->id = 29;
         array29->data = (unsigned int*)malloc(array29->size*sizeof(unsigned int));
         memset(array29->data, 0, array29->size*sizeof(unsigned int));
         DEBUG_NEW(array29->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array29;
      array_t* array30 = func10(&params0, get_path(), loopsFactor);
      DEBUG_RETURN(array30->id);
      free(params0.data);
      array30->refC--;
      if(array30->refC == 0) {
         free(array30->data);
         free(array30);
         DEBUG_FREE(array30->id);
      }
      array29->refC--;
      if(array29->refC == 0) {
         free(array29->data);
         free(array29);
         DEBUG_FREE(array29->id);
      }
   }
   array_t* array45;
   if (pCounter > 0) {
      array45 = vars->data[--pCounter];
      array45->refC++;
      DEBUG_COPY(array45->id);
   } else {
      array45 = (array_t*)malloc(sizeof(array_t));
      array45->size = 624;
      array45->refC = 1;
      array45->id = 45;
      array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
      memset(array45->data, 0, array45->size*sizeof(unsigned int));
      DEBUG_NEW(array45->id);
   }
   return array45;
}

