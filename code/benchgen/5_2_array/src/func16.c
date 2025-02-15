#include "outs/5_2_array.h" 
array_t* func16(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array160;
   if (pCounter > 0) {
      array160 = vars->data[--pCounter];
      array160->refC++;
      DEBUG_COPY(array160->id);
   } else {
      array160 = (array_t*)malloc(sizeof(array_t));
      array160->size = 850;
      array160->refC = 1;
      array160->id = 160;
      array160->data = (unsigned int*)malloc(array160->size*sizeof(unsigned int));
      memset(array160->data, 0, array160->size*sizeof(unsigned int));
      DEBUG_NEW(array160->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array160;
   array_t* array161 = func17(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array161->id);
   free(params0.data);
   for (int i = 0; i < array160->size; i++) {
      if (array160->data[i] == 99) { 
         return array160;
      }
   }
   unsigned int loop32 = 0;
   unsigned int loopLimit32 = (rand()%loopsFactor)/3 + 1;
   for(; loop32 < loopLimit32; loop32++) {
      for (int i = 0; i < array160->size; i++) {
         array160->data[i]--;
      }
      for (int i = 0; i < array160->size; i++) {
         if (array160->data[i] == 98) { 
            return array160;
         }
      }
      if(PATH0 & 1) {
         array_t* array162;
         if (pCounter > 0) {
            array162 = vars->data[--pCounter];
            array162->refC++;
            DEBUG_COPY(array162->id);
         } else {
            array162 = (array_t*)malloc(sizeof(array_t));
            array162->size = 713;
            array162->refC = 1;
            array162->id = 162;
            array162->data = (unsigned int*)malloc(array162->size*sizeof(unsigned int));
            memset(array162->data, 0, array162->size*sizeof(unsigned int));
            DEBUG_NEW(array162->id);
         }
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array160;
         params1.data[1] = array161;
         params1.data[2] = array162;
         array_t* array163 = func22(&params1, loopsFactor);
         DEBUG_RETURN(array163->id);
         free(params1.data);
         array_t* array164;
         if (pCounter > 0) {
            array164 = vars->data[--pCounter];
            array164->refC++;
            DEBUG_COPY(array164->id);
         } else {
            array164 = (array_t*)malloc(sizeof(array_t));
            array164->size = 524;
            array164->refC = 1;
            array164->id = 164;
            array164->data = (unsigned int*)malloc(array164->size*sizeof(unsigned int));
            memset(array164->data, 0, array164->size*sizeof(unsigned int));
            DEBUG_NEW(array164->id);
         }
         array_t* array165;
         if (pCounter > 0) {
            array165 = vars->data[--pCounter];
            array165->refC++;
            DEBUG_COPY(array165->id);
         } else {
            array165 = (array_t*)malloc(sizeof(array_t));
            array165->size = 590;
            array165->refC = 1;
            array165->id = 165;
            array165->data = (unsigned int*)malloc(array165->size*sizeof(unsigned int));
            memset(array165->data, 0, array165->size*sizeof(unsigned int));
            DEBUG_NEW(array165->id);
         }
         array165->refC--;
         if(array165->refC == 0) {
            free(array165->data);
            free(array165);
            DEBUG_FREE(array165->id);
         }
         array164->refC--;
         if(array164->refC == 0) {
            free(array164->data);
            free(array164);
            DEBUG_FREE(array164->id);
         }
         array163->refC--;
         if(array163->refC == 0) {
            free(array163->data);
            free(array163);
            DEBUG_FREE(array163->id);
         }
         array162->refC--;
         if(array162->refC == 0) {
            free(array162->data);
            free(array162);
            DEBUG_FREE(array162->id);
         }
      }
      else {
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array160;
         params1.data[1] = array161;
         array_t* array166 = func23(&params1, loopsFactor);
         DEBUG_RETURN(array166->id);
         free(params1.data);
         array_t* array167;
         if (pCounter > 0) {
            array167 = vars->data[--pCounter];
            array167->refC++;
            DEBUG_COPY(array167->id);
         } else {
            array167 = (array_t*)malloc(sizeof(array_t));
            array167->size = 819;
            array167->refC = 1;
            array167->id = 167;
            array167->data = (unsigned int*)malloc(array167->size*sizeof(unsigned int));
            memset(array167->data, 0, array167->size*sizeof(unsigned int));
            DEBUG_NEW(array167->id);
         }
         array167->refC--;
         if(array167->refC == 0) {
            free(array167->data);
            free(array167);
            DEBUG_FREE(array167->id);
         }
         array166->refC--;
         if(array166->refC == 0) {
            free(array166->data);
            free(array166);
            DEBUG_FREE(array166->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array160;
   params1.data[1] = array161;
   array_t* array168 = func18(&params1, loopsFactor);
   DEBUG_RETURN(array168->id);
   free(params1.data);
   array_t* array169;
   if (pCounter > 0) {
      array169 = vars->data[--pCounter];
      array169->refC++;
      DEBUG_COPY(array169->id);
   } else {
      array169 = (array_t*)malloc(sizeof(array_t));
      array169->size = 155;
      array169->refC = 1;
      array169->id = 169;
      array169->data = (unsigned int*)malloc(array169->size*sizeof(unsigned int));
      memset(array169->data, 0, array169->size*sizeof(unsigned int));
      DEBUG_NEW(array169->id);
   }
   array_t* array170;
   if (pCounter > 0) {
      array170 = vars->data[--pCounter];
      array170->refC++;
      DEBUG_COPY(array170->id);
   } else {
      array170 = (array_t*)malloc(sizeof(array_t));
      array170->size = 994;
      array170->refC = 1;
      array170->id = 170;
      array170->data = (unsigned int*)malloc(array170->size*sizeof(unsigned int));
      memset(array170->data, 0, array170->size*sizeof(unsigned int));
      DEBUG_NEW(array170->id);
   }
   array169->refC--;
   if(array169->refC == 0) {
      free(array169->data);
      free(array169);
      DEBUG_FREE(array169->id);
   }
   array168->refC--;
   if(array168->refC == 0) {
      free(array168->data);
      free(array168);
      DEBUG_FREE(array168->id);
   }
   array161->refC--;
   if(array161->refC == 0) {
      free(array161->data);
      free(array161);
      DEBUG_FREE(array161->id);
   }
   array160->refC--;
   if(array160->refC == 0) {
      free(array160->data);
      free(array160);
      DEBUG_FREE(array160->id);
   }
   return array170;
}

