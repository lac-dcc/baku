#include "outs/5_7_array.h" 
array_t* func11(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop10 = 0;
      unsigned int loopLimit10 = (rand()%loopsFactor)/2 + 1;
      for(; loop10 < loopLimit10; loop10++) {
      }
   }
   else {
      array_t* array44;
      if (pCounter > 0) {
         array44 = vars->data[--pCounter];
         array44->refC++;
         DEBUG_COPY(array44->id);
      } else {
         array44 = (array_t*)malloc(sizeof(array_t));
         array44->size = 492;
         array44->refC = 1;
         array44->id = 44;
         array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
         memset(array44->data, 0, array44->size*sizeof(unsigned int));
         DEBUG_NEW(array44->id);
      }
      array_t_param params0;
      params0.size = 1;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array44;
      array_t* array45 = func13(&params0, loopsFactor);
      DEBUG_RETURN(array45->id);
      free(params0.data);
      array45->refC--;
      if(array45->refC == 0) {
         free(array45->data);
         free(array45);
         DEBUG_FREE(array45->id);
      }
      array44->refC--;
      if(array44->refC == 0) {
         free(array44->data);
         free(array44);
         DEBUG_FREE(array44->id);
      }
   }
   array_t* array46;
   if (pCounter > 0) {
      array46 = vars->data[--pCounter];
      array46->refC++;
      DEBUG_COPY(array46->id);
   } else {
      array46 = (array_t*)malloc(sizeof(array_t));
      array46->size = 301;
      array46->refC = 1;
      array46->id = 46;
      array46->data = (unsigned int*)malloc(array46->size*sizeof(unsigned int));
      memset(array46->data, 0, array46->size*sizeof(unsigned int));
      DEBUG_NEW(array46->id);
   }
   array_t* array47;
   if (pCounter > 0) {
      array47 = vars->data[--pCounter];
      array47->refC++;
      DEBUG_COPY(array47->id);
   } else {
      array47 = (array_t*)malloc(sizeof(array_t));
      array47->size = 280;
      array47->refC = 1;
      array47->id = 47;
      array47->data = (unsigned int*)malloc(array47->size*sizeof(unsigned int));
      memset(array47->data, 0, array47->size*sizeof(unsigned int));
      DEBUG_NEW(array47->id);
   }
   for (int i = 0; i < array46->size; i++) {
      array46->data[i]++;
   }
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/2 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      for (int i = 0; i < array47->size; i++) {
         array47->data[i]--;
      }
   }
   array_t_param params0;
   params0.size = 2;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array46;
   params0.data[1] = array47;
   array_t* array48 = func14(&params0, loopsFactor);
   DEBUG_RETURN(array48->id);
   free(params0.data);
   array48->refC--;
   if(array48->refC == 0) {
      free(array48->data);
      free(array48);
      DEBUG_FREE(array48->id);
   }
   array46->refC--;
   if(array46->refC == 0) {
      free(array46->data);
      free(array46);
      DEBUG_FREE(array46->id);
   }
   return array47;
}

