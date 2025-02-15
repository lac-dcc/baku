#include "outs/5_2_array.h" 
array_t* func15(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array133;
   if (pCounter > 0) {
      array133 = vars->data[--pCounter];
      array133->refC++;
      DEBUG_COPY(array133->id);
   } else {
      array133 = (array_t*)malloc(sizeof(array_t));
      array133->size = 466;
      array133->refC = 1;
      array133->id = 133;
      array133->data = (unsigned int*)malloc(array133->size*sizeof(unsigned int));
      memset(array133->data, 0, array133->size*sizeof(unsigned int));
      DEBUG_NEW(array133->id);
   }
   unsigned int loop27 = 0;
   unsigned int loopLimit27 = (rand()%loopsFactor)/3 + 1;
   for(; loop27 < loopLimit27; loop27++) {
      for (int i = 0; i < array133->size; i++) {
         array133->data[i]++;
      }
      for (int i = 0; i < array133->size; i++) {
         if (array133->data[i] == 90) { 
            return array133;
         }
      }
      if(PATH0 & 1) {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array133;
         array_t* array134 = func19(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array134->id);
         free(params0.data);
         array_t* array135;
         if (pCounter > 0) {
            array135 = vars->data[--pCounter];
            array135->refC++;
            DEBUG_COPY(array135->id);
         } else {
            array135 = (array_t*)malloc(sizeof(array_t));
            array135->size = 542;
            array135->refC = 1;
            array135->id = 135;
            array135->data = (unsigned int*)malloc(array135->size*sizeof(unsigned int));
            memset(array135->data, 0, array135->size*sizeof(unsigned int));
            DEBUG_NEW(array135->id);
         }
         array135->refC--;
         if(array135->refC == 0) {
            free(array135->data);
            free(array135);
            DEBUG_FREE(array135->id);
         }
         array134->refC--;
         if(array134->refC == 0) {
            free(array134->data);
            free(array134);
            DEBUG_FREE(array134->id);
         }
      }
      else {
         array_t* array136;
         if (pCounter > 0) {
            array136 = vars->data[--pCounter];
            array136->refC++;
            DEBUG_COPY(array136->id);
         } else {
            array136 = (array_t*)malloc(sizeof(array_t));
            array136->size = 936;
            array136->refC = 1;
            array136->id = 136;
            array136->data = (unsigned int*)malloc(array136->size*sizeof(unsigned int));
            memset(array136->data, 0, array136->size*sizeof(unsigned int));
            DEBUG_NEW(array136->id);
         }
         unsigned int loop28 = 0;
         unsigned int loopLimit28 = (rand()%loopsFactor)/4 + 1;
         for(; loop28 < loopLimit28; loop28++) {
            for (int i = 0; i < array136->size; i++) {
               array136->data[i]++;
            }
            for (int i = 0; i < array136->size; i++) {
               if (array136->data[i] == 56) { 
                  return array136;
               }
            }
            if(PATH0 & 2) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array133;
               params0.data[1] = array136;
               array_t* array137 = func24(&params0, loopsFactor);
               DEBUG_RETURN(array137->id);
               free(params0.data);
               array_t* array138;
               if (pCounter > 0) {
                  array138 = vars->data[--pCounter];
                  array138->refC++;
                  DEBUG_COPY(array138->id);
               } else {
                  array138 = (array_t*)malloc(sizeof(array_t));
                  array138->size = 887;
                  array138->refC = 1;
                  array138->id = 138;
                  array138->data = (unsigned int*)malloc(array138->size*sizeof(unsigned int));
                  memset(array138->data, 0, array138->size*sizeof(unsigned int));
                  DEBUG_NEW(array138->id);
               }
               array138->refC--;
               if(array138->refC == 0) {
                  free(array138->data);
                  free(array138);
                  DEBUG_FREE(array138->id);
               }
               array137->refC--;
               if(array137->refC == 0) {
                  free(array137->data);
                  free(array137);
                  DEBUG_FREE(array137->id);
               }
            }
            else {
            }
         }
         array_t* array139;
         if (pCounter > 0) {
            array139 = vars->data[--pCounter];
            array139->refC++;
            DEBUG_COPY(array139->id);
         } else {
            array139 = (array_t*)malloc(sizeof(array_t));
            array139->size = 412;
            array139->refC = 1;
            array139->id = 139;
            array139->data = (unsigned int*)malloc(array139->size*sizeof(unsigned int));
            memset(array139->data, 0, array139->size*sizeof(unsigned int));
            DEBUG_NEW(array139->id);
         }
         array139->refC--;
         if(array139->refC == 0) {
            free(array139->data);
            free(array139);
            DEBUG_FREE(array139->id);
         }
         array136->refC--;
         if(array136->refC == 0) {
            free(array136->data);
            free(array136);
            DEBUG_FREE(array136->id);
         }
      }
   }
   array_t* array140;
   if (pCounter > 0) {
      array140 = vars->data[--pCounter];
      array140->refC++;
      DEBUG_COPY(array140->id);
   } else {
      array140 = (array_t*)malloc(sizeof(array_t));
      array140->size = 348;
      array140->refC = 1;
      array140->id = 140;
      array140->data = (unsigned int*)malloc(array140->size*sizeof(unsigned int));
      memset(array140->data, 0, array140->size*sizeof(unsigned int));
      DEBUG_NEW(array140->id);
   }
   array140->refC--;
   if(array140->refC == 0) {
      free(array140->data);
      free(array140);
      DEBUG_FREE(array140->id);
   }
   return array133;
}

