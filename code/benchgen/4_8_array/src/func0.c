#include "outs/4_8_array.h" 
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
         array_t* array15 = func4(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array15->id);
         free(params0.data);
         array15->refC--;
         if(array15->refC == 0) {
            free(array15->data);
            free(array15);
            DEBUG_FREE(array15->id);
         }
      }
      array_t* array21;
      if (pCounter > 0) {
         array21 = vars->data[--pCounter];
         array21->refC++;
         DEBUG_COPY(array21->id);
      } else {
         array21 = (array_t*)malloc(sizeof(array_t));
         array21->size = 434;
         array21->refC = 1;
         array21->id = 21;
         array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
         memset(array21->data, 0, array21->size*sizeof(unsigned int));
         DEBUG_NEW(array21->id);
      }
      array_t_param params0;
      params0.size = 2;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array1;
      params0.data[1] = array21;
      array_t* array22 = func5(&params0, loopsFactor);
      DEBUG_RETURN(array22->id);
      free(params0.data);
      if(PATH0 & 2) {
         array_t* array25;
         if (pCounter > 0) {
            array25 = vars->data[--pCounter];
            array25->refC++;
            DEBUG_COPY(array25->id);
         } else {
            array25 = (array_t*)malloc(sizeof(array_t));
            array25->size = 754;
            array25->refC = 1;
            array25->id = 25;
            array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
            memset(array25->data, 0, array25->size*sizeof(unsigned int));
            DEBUG_NEW(array25->id);
         }
         unsigned int loop9 = 0;
         unsigned int loopLimit9 = (rand()%loopsFactor)/3 + 1;
         for(; loop9 < loopLimit9; loop9++) {
            for (int i = 0; i < array25->size; i++) {
               array25->data[i]--;
            }
            for (int i = 0; i < array1->size; i++) {
               if (array1->data[i] == 60) { 
                  return array1;
               }
            }
         }
         array_t_param params1;
         params1.size = 4;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array21;
         params1.data[2] = array22;
         params1.data[3] = array25;
         array_t* array26 = func18(&params1, rng(), loopsFactor);
         DEBUG_RETURN(array26->id);
         free(params1.data);
         array26->refC--;
         if(array26->refC == 0) {
            free(array26->data);
            free(array26);
            DEBUG_FREE(array26->id);
         }
         array25->refC--;
         if(array25->refC == 0) {
            free(array25->data);
            free(array25);
            DEBUG_FREE(array25->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array1;
         params1.data[1] = array21;
         params1.data[2] = array22;
         array_t* array33 = func14(&params1, loopsFactor);
         DEBUG_RETURN(array33->id);
         free(params1.data);
         array33->refC--;
         if(array33->refC == 0) {
            free(array33->data);
            free(array33);
            DEBUG_FREE(array33->id);
         }
      }
      for (int i = 0; i < array1->size; i++) {
         if (array1->data[i] == 75) { 
            return array1;
         }
      }
      array22->refC--;
      if(array22->refC == 0) {
         free(array22->data);
         free(array22);
         DEBUG_FREE(array22->id);
      }
      array21->refC--;
      if(array21->refC == 0) {
         free(array21->data);
         free(array21);
         DEBUG_FREE(array21->id);
      }
   }
   return array1;
}

