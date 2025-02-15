#include "outs/3_2_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array39;
   if (pCounter > 0) {
      array39 = vars->data[--pCounter];
      array39->refC++;
      DEBUG_COPY(array39->id);
   } else {
      array39 = (array_t*)malloc(sizeof(array_t));
      array39->size = 94;
      array39->refC = 1;
      array39->id = 39;
      array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
      memset(array39->data, 0, array39->size*sizeof(unsigned int));
      DEBUG_NEW(array39->id);
   }
   unsigned int loop9 = 0;
   unsigned int loopLimit9 = (rand()%loopsFactor)/2 + 1;
   for(; loop9 < loopLimit9; loop9++) {
      for (int i = 0; i < array39->size; i++) {
         array39->data[i]++;
      }
      for (int i = 0; i < array39->size; i++) {
         if (array39->data[i] == 70) { 
            return array39;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array39;
         array_t* array40 = func7(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array40->id);
         free(params0.data);
         array_t* array41;
         if (pCounter > 0) {
            array41 = vars->data[--pCounter];
            array41->refC++;
            DEBUG_COPY(array41->id);
         } else {
            array41 = (array_t*)malloc(sizeof(array_t));
            array41->size = 467;
            array41->refC = 1;
            array41->id = 41;
            array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
            memset(array41->data, 0, array41->size*sizeof(unsigned int));
            DEBUG_NEW(array41->id);
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
      }
      else {
         array_t* array42;
         if (pCounter > 0) {
            array42 = vars->data[--pCounter];
            array42->refC++;
            DEBUG_COPY(array42->id);
         } else {
            array42 = (array_t*)malloc(sizeof(array_t));
            array42->size = 601;
            array42->refC = 1;
            array42->id = 42;
            array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
            memset(array42->data, 0, array42->size*sizeof(unsigned int));
            DEBUG_NEW(array42->id);
         }
         unsigned int loop10 = 0;
         unsigned int loopLimit10 = (rand()%loopsFactor)/3 + 1;
         for(; loop10 < loopLimit10; loop10++) {
            for (int i = 0; i < array42->size; i++) {
               array42->data[i]++;
            }
            for (int i = 0; i < array39->size; i++) {
               if (array39->data[i] == 17) { 
                  return array39;
               }
            }
            if(PATH0 & 2) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array39;
               params0.data[1] = array42;
               array_t* array43 = func14(&params0, loopsFactor);
               DEBUG_RETURN(array43->id);
               free(params0.data);
               array_t* array44;
               if (pCounter > 0) {
                  array44 = vars->data[--pCounter];
                  array44->refC++;
                  DEBUG_COPY(array44->id);
               } else {
                  array44 = (array_t*)malloc(sizeof(array_t));
                  array44->size = 756;
                  array44->refC = 1;
                  array44->id = 44;
                  array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
                  memset(array44->data, 0, array44->size*sizeof(unsigned int));
                  DEBUG_NEW(array44->id);
               }
               array44->refC--;
               if(array44->refC == 0) {
                  free(array44->data);
                  free(array44);
                  DEBUG_FREE(array44->id);
               }
               array43->refC--;
               if(array43->refC == 0) {
                  free(array43->data);
                  free(array43);
                  DEBUG_FREE(array43->id);
               }
            }
            else {
            }
         }
         array_t* array45;
         if (pCounter > 0) {
            array45 = vars->data[--pCounter];
            array45->refC++;
            DEBUG_COPY(array45->id);
         } else {
            array45 = (array_t*)malloc(sizeof(array_t));
            array45->size = 301;
            array45->refC = 1;
            array45->id = 45;
            array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
            memset(array45->data, 0, array45->size*sizeof(unsigned int));
            DEBUG_NEW(array45->id);
         }
         array45->refC--;
         if(array45->refC == 0) {
            free(array45->data);
            free(array45);
            DEBUG_FREE(array45->id);
         }
         array42->refC--;
         if(array42->refC == 0) {
            free(array42->data);
            free(array42);
            DEBUG_FREE(array42->id);
         }
      }
   }
   array_t* array46;
   if (pCounter > 0) {
      array46 = vars->data[--pCounter];
      array46->refC++;
      DEBUG_COPY(array46->id);
   } else {
      array46 = (array_t*)malloc(sizeof(array_t));
      array46->size = 280;
      array46->refC = 1;
      array46->id = 46;
      array46->data = (unsigned int*)malloc(array46->size*sizeof(unsigned int));
      memset(array46->data, 0, array46->size*sizeof(unsigned int));
      DEBUG_NEW(array46->id);
   }
   array46->refC--;
   if(array46->refC == 0) {
      free(array46->data);
      free(array46);
      DEBUG_FREE(array46->id);
   }
   return array39;
}

