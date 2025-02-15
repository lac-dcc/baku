#include "outs/5_8_array.h" 
array_t* func0(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array1;
   if (pCounter > 0) {
      array1 = vars->data[--pCounter];
      array1->refC++;
      DEBUG_COPY(array1->id);
   } else {
      array1 = (array_t*)malloc(sizeof(array_t));
      array1->size = 386;
      array1->refC = 1;
      array1->id = 1;
      array1->data = (unsigned int*)malloc(array1->size*sizeof(unsigned int));
      memset(array1->data, 0, array1->size*sizeof(unsigned int));
      DEBUG_NEW(array1->id);
   }
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      if(PATH0 & 1) {
         array_t* array2;
         if (pCounter > 0) {
            array2 = vars->data[--pCounter];
            array2->refC++;
            DEBUG_COPY(array2->id);
         } else {
            array2 = (array_t*)malloc(sizeof(array_t));
            array2->size = 492;
            array2->refC = 1;
            array2->id = 2;
            array2->data = (unsigned int*)malloc(array2->size*sizeof(unsigned int));
            memset(array2->data, 0, array2->size*sizeof(unsigned int));
            DEBUG_NEW(array2->id);
         }
         unsigned int loop2 = 0;
         unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
         for(; loop2 < loopLimit2; loop2++) {
            for (int i = 0; i < array2->size; i++) {
               array2->data[i]--;
            }
            for (int i = 0; i < array2->size; i++) {
               if (array2->data[i] == 62) { 
                  return array2;
               }
            }
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array1;
         params0.data[1] = array2;
         array_t* array3 = func10(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array3->id);
         free(params0.data);
         array3->refC--;
         if(array3->refC == 0) {
            free(array3->data);
            free(array3);
            DEBUG_FREE(array3->id);
         }
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array1;
         array_t* array31 = func4(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array31->id);
         free(params0.data);
         array31->refC--;
         if(array31->refC == 0) {
            free(array31->data);
            free(array31);
            DEBUG_FREE(array31->id);
         }
      }
      array_t* array40;
      if (pCounter > 0) {
         array40 = vars->data[--pCounter];
         array40->refC++;
         DEBUG_COPY(array40->id);
      } else {
         array40 = (array_t*)malloc(sizeof(array_t));
         array40->size = 732;
         array40->refC = 1;
         array40->id = 40;
         array40->data = (unsigned int*)malloc(array40->size*sizeof(unsigned int));
         memset(array40->data, 0, array40->size*sizeof(unsigned int));
         DEBUG_NEW(array40->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array1;
      params0.data[1] = array40;
      array_t* array41 = func5(&params0, loopsFactor);
      DEBUG_RETURN(array41->id);
      free(params0.data);
      if(PATH0 & 2) {
         array_t* array44;
         if (pCounter > 0) {
            array44 = vars->data[--pCounter];
            array44->refC++;
            DEBUG_COPY(array44->id);
         } else {
            array44 = (array_t*)malloc(sizeof(array_t));
            array44->size = 618;
            array44->refC = 1;
            array44->id = 44;
            array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
            memset(array44->data, 0, array44->size*sizeof(unsigned int));
            DEBUG_NEW(array44->id);
         }
         unsigned int loop14 = 0;
         unsigned int loopLimit14 = (rand()%loopsFactor)/3 + 1;
         for(; loop14 < loopLimit14; loop14++) {
            for (int i = 0; i < array40->size; i++) {
               array40->data[i]--;
            }
            for (int i = 0; i < array41->size; i++) {
               if (array41->data[i] == 51) { 
                  return array41;
               }
            }
         }
         array_t_param params1;
         params1.size = 4;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array40;
         params1.data[2] = array41;
         params1.data[3] = array44;
         array_t* array45 = func18(&params1, rng(), loopsFactor);
         DEBUG_RETURN(array45->id);
         free(params1.data);
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
      else {
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array40;
         params1.data[2] = array41;
         array_t* array55 = func14(&params1, rng(), loopsFactor);
         DEBUG_RETURN(array55->id);
         free(params1.data);
         array55->refC--;
         if(array55->refC == 0) {
            free(array55->data);
            free(array55);
            DEBUG_FREE(array55->id);
         }
      }
      for (int i = 0; i < array40->size; i++) {
         if (array40->data[i] == 28) { 
            return array40;
         }
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
   return array1;
}

