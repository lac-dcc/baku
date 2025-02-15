#include "outs/4_2_array.h" 
array_t* func10(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array188;
   if (pCounter > 0) {
      array188 = vars->data[--pCounter];
      array188->refC++;
      DEBUG_COPY(array188->id);
   } else {
      array188 = (array_t*)malloc(sizeof(array_t));
      array188->size = 36;
      array188->refC = 1;
      array188->id = 188;
      array188->data = (unsigned int*)malloc(array188->size*sizeof(unsigned int));
      memset(array188->data, 0, array188->size*sizeof(unsigned int));
      DEBUG_NEW(array188->id);
   }
   unsigned int loop37 = 0;
   unsigned int loopLimit37 = (rand()%loopsFactor)/2 + 1;
   for(; loop37 < loopLimit37; loop37++) {
      for (int i = 0; i < array188->size; i++) {
         array188->data[i]++;
      }
      for (int i = 0; i < array188->size; i++) {
         if (array188->data[i] == 48) { 
            return array188;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array188;
         array_t* array189 = func14(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array189->id);
         free(params0.data);
         array_t* array190;
         if (pCounter > 0) {
            array190 = vars->data[--pCounter];
            array190->refC++;
            DEBUG_COPY(array190->id);
         } else {
            array190 = (array_t*)malloc(sizeof(array_t));
            array190->size = 133;
            array190->refC = 1;
            array190->id = 190;
            array190->data = (unsigned int*)malloc(array190->size*sizeof(unsigned int));
            memset(array190->data, 0, array190->size*sizeof(unsigned int));
            DEBUG_NEW(array190->id);
         }
         array190->refC--;
         if(array190->refC == 0) {
            free(array190->data);
            free(array190);
            DEBUG_FREE(array190->id);
         }
         array189->refC--;
         if(array189->refC == 0) {
            free(array189->data);
            free(array189);
            DEBUG_FREE(array189->id);
         }
      }
      else {
         array_t* array191;
         if (pCounter > 0) {
            array191 = vars->data[--pCounter];
            array191->refC++;
            DEBUG_COPY(array191->id);
         } else {
            array191 = (array_t*)malloc(sizeof(array_t));
            array191->size = 648;
            array191->refC = 1;
            array191->id = 191;
            array191->data = (unsigned int*)malloc(array191->size*sizeof(unsigned int));
            memset(array191->data, 0, array191->size*sizeof(unsigned int));
            DEBUG_NEW(array191->id);
         }
         unsigned int loop38 = 0;
         unsigned int loopLimit38 = (rand()%loopsFactor)/3 + 1;
         for(; loop38 < loopLimit38; loop38++) {
            for (int i = 0; i < array188->size; i++) {
               array188->data[i]++;
            }
            for (int i = 0; i < array188->size; i++) {
               if (array188->data[i] == 67) { 
                  return array188;
               }
            }
            if(PATH0 & 2) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array188;
               params0.data[1] = array191;
               array_t* array192 = func19(&params0, loopsFactor);
               DEBUG_RETURN(array192->id);
               free(params0.data);
               array_t* array193;
               if (pCounter > 0) {
                  array193 = vars->data[--pCounter];
                  array193->refC++;
                  DEBUG_COPY(array193->id);
               } else {
                  array193 = (array_t*)malloc(sizeof(array_t));
                  array193->size = 529;
                  array193->refC = 1;
                  array193->id = 193;
                  array193->data = (unsigned int*)malloc(array193->size*sizeof(unsigned int));
                  memset(array193->data, 0, array193->size*sizeof(unsigned int));
                  DEBUG_NEW(array193->id);
               }
               array193->refC--;
               if(array193->refC == 0) {
                  free(array193->data);
                  free(array193);
                  DEBUG_FREE(array193->id);
               }
               array192->refC--;
               if(array192->refC == 0) {
                  free(array192->data);
                  free(array192);
                  DEBUG_FREE(array192->id);
               }
            }
            else {
            }
         }
         array_t* array194;
         if (pCounter > 0) {
            array194 = vars->data[--pCounter];
            array194->refC++;
            DEBUG_COPY(array194->id);
         } else {
            array194 = (array_t*)malloc(sizeof(array_t));
            array194->size = 500;
            array194->refC = 1;
            array194->id = 194;
            array194->data = (unsigned int*)malloc(array194->size*sizeof(unsigned int));
            memset(array194->data, 0, array194->size*sizeof(unsigned int));
            DEBUG_NEW(array194->id);
         }
         array194->refC--;
         if(array194->refC == 0) {
            free(array194->data);
            free(array194);
            DEBUG_FREE(array194->id);
         }
         array191->refC--;
         if(array191->refC == 0) {
            free(array191->data);
            free(array191);
            DEBUG_FREE(array191->id);
         }
      }
   }
   array_t* array195;
   if (pCounter > 0) {
      array195 = vars->data[--pCounter];
      array195->refC++;
      DEBUG_COPY(array195->id);
   } else {
      array195 = (array_t*)malloc(sizeof(array_t));
      array195->size = 46;
      array195->refC = 1;
      array195->id = 195;
      array195->data = (unsigned int*)malloc(array195->size*sizeof(unsigned int));
      memset(array195->data, 0, array195->size*sizeof(unsigned int));
      DEBUG_NEW(array195->id);
   }
   array195->refC--;
   if(array195->refC == 0) {
      free(array195->data);
      free(array195);
      DEBUG_FREE(array195->id);
   }
   return array188;
}

