#include "outs/4_8_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t* array45;
      if (pCounter > 0) {
         array45 = vars->data[--pCounter];
         array45->refC++;
         DEBUG_COPY(array45->id);
      } else {
         array45 = (array_t*)malloc(sizeof(array_t));
         array45->size = 555;
         array45->refC = 1;
         array45->id = 45;
         array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
         memset(array45->data, 0, array45->size*sizeof(unsigned int));
         DEBUG_NEW(array45->id);
      }
      unsigned int loop14 = 0;
      unsigned int loopLimit14 = (rand()%loopsFactor)/2 + 1;
      for(; loop14 < loopLimit14; loop14++) {
         for (int i = 0; i < array45->size; i++) {
            array45->data[i]--;
         }
         for (int i = 0; i < array45->size; i++) {
            if (array45->data[i] == 64) { 
               return array45;
            }
         }
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array45;
      array_t* array46 = func18(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array46->id);
      free(params0.data);
      array46->refC--;
      if(array46->refC == 0) {
         free(array46->data);
         free(array46);
         DEBUG_FREE(array46->id);
      }
      array45->refC--;
      if(array45->refC == 0) {
         free(array45->data);
         free(array45);
         DEBUG_FREE(array45->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array47 = func14(&params0, loopsFactor);
      DEBUG_RETURN(array47->id);
      free(params0.data);
      array47->refC--;
      if(array47->refC == 0) {
         free(array47->data);
         free(array47);
         DEBUG_FREE(array47->id);
      }
   }
   array_t* array48;
   if (pCounter > 0) {
      array48 = vars->data[--pCounter];
      array48->refC++;
      DEBUG_COPY(array48->id);
   } else {
      array48 = (array_t*)malloc(sizeof(array_t));
      array48->size = 500;
      array48->refC = 1;
      array48->id = 48;
      array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
      memset(array48->data, 0, array48->size*sizeof(unsigned int));
      DEBUG_NEW(array48->id);
   }
   return array48;
}

