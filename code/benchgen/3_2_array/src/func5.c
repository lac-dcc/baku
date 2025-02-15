#include "outs/3_2_array.h" 
array_t* func5(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array153 = func10(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array153->id);
   free(params0.data);
   for (int i = 0; i < array153->size; i++) {
      if (array153->data[i] == 27) { 
         return array153;
      }
   }
   unsigned int loop30 = 0;
   unsigned int loopLimit30 = (rand()%loopsFactor)/2 + 1;
   for(; loop30 < loopLimit30; loop30++) {
      for (int i = 0; i < array153->size; i++) {
         array153->data[i]--;
      }
      for (int i = 0; i < array153->size; i++) {
         if (array153->data[i] == 58) { 
            return array153;
         }
      }
      if(PATH0 & 1) {
         array_t* array154;
         if (pCounter > 0) {
            array154 = vars->data[--pCounter];
            array154->refC++;
            DEBUG_COPY(array154->id);
         } else {
            array154 = (array_t*)malloc(sizeof(array_t));
            array154->size = 920;
            array154->refC = 1;
            array154->id = 154;
            array154->data = (unsigned int*)malloc(array154->size*sizeof(unsigned int));
            memset(array154->data, 0, array154->size*sizeof(unsigned int));
            DEBUG_NEW(array154->id);
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array153;
         params1.data[1] = array154;
         array_t* array155 = func12(&params1, loopsFactor);
         DEBUG_RETURN(array155->id);
         free(params1.data);
         array_t* array156;
         if (pCounter > 0) {
            array156 = vars->data[--pCounter];
            array156->refC++;
            DEBUG_COPY(array156->id);
         } else {
            array156 = (array_t*)malloc(sizeof(array_t));
            array156->size = 269;
            array156->refC = 1;
            array156->id = 156;
            array156->data = (unsigned int*)malloc(array156->size*sizeof(unsigned int));
            memset(array156->data, 0, array156->size*sizeof(unsigned int));
            DEBUG_NEW(array156->id);
         }
         array_t* array157;
         if (pCounter > 0) {
            array157 = vars->data[--pCounter];
            array157->refC++;
            DEBUG_COPY(array157->id);
         } else {
            array157 = (array_t*)malloc(sizeof(array_t));
            array157->size = 396;
            array157->refC = 1;
            array157->id = 157;
            array157->data = (unsigned int*)malloc(array157->size*sizeof(unsigned int));
            memset(array157->data, 0, array157->size*sizeof(unsigned int));
            DEBUG_NEW(array157->id);
         }
         array157->refC--;
         if(array157->refC == 0) {
            free(array157->data);
            free(array157);
            DEBUG_FREE(array157->id);
         }
         array156->refC--;
         if(array156->refC == 0) {
            free(array156->data);
            free(array156);
            DEBUG_FREE(array156->id);
         }
         array155->refC--;
         if(array155->refC == 0) {
            free(array155->data);
            free(array155);
            DEBUG_FREE(array155->id);
         }
         array154->refC--;
         if(array154->refC == 0) {
            free(array154->data);
            free(array154);
            DEBUG_FREE(array154->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 1;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array153;
         array_t* array158 = func13(&params1, loopsFactor);
         DEBUG_RETURN(array158->id);
         free(params1.data);
         array_t* array159;
         if (pCounter > 0) {
            array159 = vars->data[--pCounter];
            array159->refC++;
            DEBUG_COPY(array159->id);
         } else {
            array159 = (array_t*)malloc(sizeof(array_t));
            array159->size = 84;
            array159->refC = 1;
            array159->id = 159;
            array159->data = (unsigned int*)malloc(array159->size*sizeof(unsigned int));
            memset(array159->data, 0, array159->size*sizeof(unsigned int));
            DEBUG_NEW(array159->id);
         }
         array159->refC--;
         if(array159->refC == 0) {
            free(array159->data);
            free(array159);
            DEBUG_FREE(array159->id);
         }
         array158->refC--;
         if(array158->refC == 0) {
            free(array158->data);
            free(array158);
            DEBUG_FREE(array158->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array153;
   array_t* array160 = func11(&params1, loopsFactor);
   DEBUG_RETURN(array160->id);
   free(params1.data);
   array_t* array161;
   if (pCounter > 0) {
      array161 = vars->data[--pCounter];
      array161->refC++;
      DEBUG_COPY(array161->id);
   } else {
      array161 = (array_t*)malloc(sizeof(array_t));
      array161->size = 672;
      array161->refC = 1;
      array161->id = 161;
      array161->data = (unsigned int*)malloc(array161->size*sizeof(unsigned int));
      memset(array161->data, 0, array161->size*sizeof(unsigned int));
      DEBUG_NEW(array161->id);
   }
   array_t* array162;
   if (pCounter > 0) {
      array162 = vars->data[--pCounter];
      array162->refC++;
      DEBUG_COPY(array162->id);
   } else {
      array162 = (array_t*)malloc(sizeof(array_t));
      array162->size = 850;
      array162->refC = 1;
      array162->id = 162;
      array162->data = (unsigned int*)malloc(array162->size*sizeof(unsigned int));
      memset(array162->data, 0, array162->size*sizeof(unsigned int));
      DEBUG_NEW(array162->id);
   }
   array162->refC--;
   if(array162->refC == 0) {
      free(array162->data);
      free(array162);
      DEBUG_FREE(array162->id);
   }
   array161->refC--;
   if(array161->refC == 0) {
      free(array161->data);
      free(array161);
      DEBUG_FREE(array161->id);
   }
   array153->refC--;
   if(array153->refC == 0) {
      free(array153->data);
      free(array153);
      DEBUG_FREE(array153->id);
   }
   return array160;
}

