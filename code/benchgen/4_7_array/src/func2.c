#include "outs/4_7_array.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array39;
   if (pCounter > 0) {
      array39 = vars->data[--pCounter];
      array39->refC++;
      DEBUG_COPY(array39->id);
   } else {
      array39 = (array_t*)malloc(sizeof(array_t));
      array39->size = 378;
      array39->refC = 1;
      array39->id = 39;
      array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
      memset(array39->data, 0, array39->size*sizeof(unsigned int));
      DEBUG_NEW(array39->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array39;
   array_t* array40 = func11(&params0, loopsFactor);
   DEBUG_RETURN(array40->id);
   free(params0.data);
   array_t* array41;
   if (pCounter > 0) {
      array41 = vars->data[--pCounter];
      array41->refC++;
      DEBUG_COPY(array41->id);
   } else {
      array41 = (array_t*)malloc(sizeof(array_t));
      array41->size = 97;
      array41->refC = 1;
      array41->id = 41;
      array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
      memset(array41->data, 0, array41->size*sizeof(unsigned int));
      DEBUG_NEW(array41->id);
   }
   if(PATH0 & 1) {
      unsigned int loop9 = 0;
      unsigned int loopLimit9 = (rand()%loopsFactor)/1 + 1;
      for(; loop9 < loopLimit9; loop9++) {
      }
   }
   else {
      array_t* array42;
      if (pCounter > 0) {
         array42 = vars->data[--pCounter];
         array42->refC++;
         DEBUG_COPY(array42->id);
      } else {
         array42 = (array_t*)malloc(sizeof(array_t));
         array42->size = 902;
         array42->refC = 1;
         array42->id = 42;
         array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
         memset(array42->data, 0, array42->size*sizeof(unsigned int));
         DEBUG_NEW(array42->id);
      }
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array39;
      params1.data[1] = array40;
      params1.data[2] = array41;
      params1.data[3] = array42;
      array_t* array43 = func9(&params1, loopsFactor);
      DEBUG_RETURN(array43->id);
      free(params1.data);
      array43->refC--;
      if(array43->refC == 0) {
         free(array43->data);
         free(array43);
         DEBUG_FREE(array43->id);
      }
      array42->refC--;
      if(array42->refC == 0) {
         free(array42->data);
         free(array42);
         DEBUG_FREE(array42->id);
      }
   }
   for (int i = 0; i < array40->size; i++) {
      if (array40->data[i] == 56) { 
         return array40;
      }
   }
   array_t* array44;
   if (pCounter > 0) {
      array44 = vars->data[--pCounter];
      array44->refC++;
      DEBUG_COPY(array44->id);
   } else {
      array44 = (array_t*)malloc(sizeof(array_t));
      array44->size = 301;
      array44->refC = 1;
      array44->id = 44;
      array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
      memset(array44->data, 0, array44->size*sizeof(unsigned int));
      DEBUG_NEW(array44->id);
   }
   array_t* array45;
   if (pCounter > 0) {
      array45 = vars->data[--pCounter];
      array45->refC++;
      DEBUG_COPY(array45->id);
   } else {
      array45 = (array_t*)malloc(sizeof(array_t));
      array45->size = 280;
      array45->refC = 1;
      array45->id = 45;
      array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
      memset(array45->data, 0, array45->size*sizeof(unsigned int));
      DEBUG_NEW(array45->id);
   }
   for (int i = 0; i < array40->size; i++) {
      array40->data[i]++;
   }
   unsigned int loop10 = 0;
   unsigned int loopLimit10 = (rand()%loopsFactor)/1 + 1;
   for(; loop10 < loopLimit10; loop10++) {
      for (int i = 0; i < array40->size; i++) {
         array40->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 5;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array39;
   params1.data[1] = array40;
   params1.data[2] = array41;
   params1.data[3] = array44;
   params1.data[4] = array45;
   array_t* array46 = func10(&params1, loopsFactor);
   DEBUG_RETURN(array46->id);
   free(params1.data);
   array_t* array47;
   if (pCounter > 0) {
      array47 = vars->data[--pCounter];
      array47->refC++;
      DEBUG_COPY(array47->id);
   } else {
      array47 = (array_t*)malloc(sizeof(array_t));
      array47->size = 444;
      array47->refC = 1;
      array47->id = 47;
      array47->data = (unsigned int*)malloc(array47->size*sizeof(unsigned int));
      memset(array47->data, 0, array47->size*sizeof(unsigned int));
      DEBUG_NEW(array47->id);
   }
   array_t_param params2;
   params2.size = 7;
   params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
   params2.data[0] = array39;
   params2.data[1] = array40;
   params2.data[2] = array41;
   params2.data[3] = array44;
   params2.data[4] = array45;
   params2.data[5] = array46;
   params2.data[6] = array47;
   array_t* array48 = func5(&params2, rng(), loopsFactor);
   DEBUG_RETURN(array48->id);
   free(params2.data);
   array48->refC--;
   if(array48->refC == 0) {
      free(array48->data);
      free(array48);
      DEBUG_FREE(array48->id);
   }
   array47->refC--;
   if(array47->refC == 0) {
      free(array47->data);
      free(array47);
      DEBUG_FREE(array47->id);
   }
   array46->refC--;
   if(array46->refC == 0) {
      free(array46->data);
      free(array46);
      DEBUG_FREE(array46->id);
   }
   array44->refC--;
   if(array44->refC == 0) {
      free(array44->data);
      free(array44);
      DEBUG_FREE(array44->id);
   }
   array41->refC--;
   if(array41->refC == 0) {
      free(array41->data);
      free(array41);
      DEBUG_FREE(array41->id);
   }
   array40->refC--;
   if(array40->refC == 0) {
      free(array40->data);
      free(array40);
      DEBUG_FREE(array40->id);
   }
   array39->refC--;
   if(array39->refC == 0) {
      free(array39->data);
      free(array39);
      DEBUG_FREE(array39->id);
   }
   return array45;
}

