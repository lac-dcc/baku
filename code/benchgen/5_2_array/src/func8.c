#include "outs/5_2_array.h" 
array_t* func8(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array289 = func15(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array289->id);
   free(params0.data);
   for (int i = 0; i < array289->size; i++) {
      if (array289->data[i] == 99) { 
         return array289;
      }
   }
   unsigned int loop55 = 0;
   unsigned int loopLimit55 = (rand()%loopsFactor)/3 + 1;
   for(; loop55 < loopLimit55; loop55++) {
      for (int i = 0; i < array289->size; i++) {
         array289->data[i]--;
      }
      for (int i = 0; i < array289->size; i++) {
         if (array289->data[i] == 69) { 
            return array289;
         }
      }
      if(PATH0 & 1) {
         array_t* array290;
         if (pCounter > 0) {
            array290 = vars->data[--pCounter];
            array290->refC++;
            DEBUG_COPY(array290->id);
         } else {
            array290 = (array_t*)malloc(sizeof(array_t));
            array290->size = 363;
            array290->refC = 1;
            array290->id = 290;
            array290->data = (unsigned int*)malloc(array290->size*sizeof(unsigned int));
            memset(array290->data, 0, array290->size*sizeof(unsigned int));
            DEBUG_NEW(array290->id);
         }
         unsigned int loop56 = 0;
         unsigned int loopLimit56 = (rand()%loopsFactor)/4 + 1;
         for(; loop56 < loopLimit56; loop56++) {
            array_t* array291;
            if (pCounter > 0) {
               array291 = vars->data[--pCounter];
               array291->refC++;
               DEBUG_COPY(array291->id);
            } else {
               array291 = (array_t*)malloc(sizeof(array_t));
               array291->size = 622;
               array291->refC = 1;
               array291->id = 291;
               array291->data = (unsigned int*)malloc(array291->size*sizeof(unsigned int));
               memset(array291->data, 0, array291->size*sizeof(unsigned int));
               DEBUG_NEW(array291->id);
            }
            if(PATH0 & 2) {
            }
            else {
            }
            for (int i = 0; i < array290->size; i++) {
               if (array290->data[i] == 73) { 
                  return array290;
               }
            }
            array_t* array292;
            if (pCounter > 0) {
               array292 = vars->data[--pCounter];
               array292->refC++;
               DEBUG_COPY(array292->id);
            } else {
               array292 = (array_t*)malloc(sizeof(array_t));
               array292->size = 847;
               array292->refC = 1;
               array292->id = 292;
               array292->data = (unsigned int*)malloc(array292->size*sizeof(unsigned int));
               memset(array292->data, 0, array292->size*sizeof(unsigned int));
               DEBUG_NEW(array292->id);
            }
            array292->refC--;
            if(array292->refC == 0) {
               free(array292->data);
               free(array292);
               DEBUG_FREE(array292->id);
            }
            array291->refC--;
            if(array291->refC == 0) {
               free(array291->data);
               free(array291);
               DEBUG_FREE(array291->id);
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array289;
         params1.data[1] = array290;
         array_t* array293 = func20(&params1, loopsFactor);
         DEBUG_RETURN(array293->id);
         free(params1.data);
         array_t* array294;
         if (pCounter > 0) {
            array294 = vars->data[--pCounter];
            array294->refC++;
            DEBUG_COPY(array294->id);
         } else {
            array294 = (array_t*)malloc(sizeof(array_t));
            array294->size = 682;
            array294->refC = 1;
            array294->id = 294;
            array294->data = (unsigned int*)malloc(array294->size*sizeof(unsigned int));
            memset(array294->data, 0, array294->size*sizeof(unsigned int));
            DEBUG_NEW(array294->id);
         }
         array_t* array295;
         if (pCounter > 0) {
            array295 = vars->data[--pCounter];
            array295->refC++;
            DEBUG_COPY(array295->id);
         } else {
            array295 = (array_t*)malloc(sizeof(array_t));
            array295->size = 390;
            array295->refC = 1;
            array295->id = 295;
            array295->data = (unsigned int*)malloc(array295->size*sizeof(unsigned int));
            memset(array295->data, 0, array295->size*sizeof(unsigned int));
            DEBUG_NEW(array295->id);
         }
         unsigned int loop57 = 0;
         unsigned int loopLimit57 = (rand()%loopsFactor)/4 + 1;
         for(; loop57 < loopLimit57; loop57++) {
            for (int i = 0; i < array293->size; i++) {
               array293->data[i]++;
            }
            for (int i = 0; i < array290->size; i++) {
               if (array290->data[i] == 57) { 
                  return array290;
               }
            }
            if(PATH0 & 4) {
               array_t_param params2;
               params2.size = 5;
               params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
               params2.data[0] = array289;
               params2.data[1] = array290;
               params2.data[2] = array293;
               params2.data[3] = array294;
               params2.data[4] = array295;
               array_t* array296 = func24(&params2, loopsFactor);
               DEBUG_RETURN(array296->id);
               free(params2.data);
               array_t* array297;
               if (pCounter > 0) {
                  array297 = vars->data[--pCounter];
                  array297->refC++;
                  DEBUG_COPY(array297->id);
               } else {
                  array297 = (array_t*)malloc(sizeof(array_t));
                  array297->size = 157;
                  array297->refC = 1;
                  array297->id = 297;
                  array297->data = (unsigned int*)malloc(array297->size*sizeof(unsigned int));
                  memset(array297->data, 0, array297->size*sizeof(unsigned int));
                  DEBUG_NEW(array297->id);
               }
               array297->refC--;
               if(array297->refC == 0) {
                  free(array297->data);
                  free(array297);
                  DEBUG_FREE(array297->id);
               }
               array296->refC--;
               if(array296->refC == 0) {
                  free(array296->data);
                  free(array296);
                  DEBUG_FREE(array296->id);
               }
            }
            else {
            }
         }
         array_t* array298;
         if (pCounter > 0) {
            array298 = vars->data[--pCounter];
            array298->refC++;
            DEBUG_COPY(array298->id);
         } else {
            array298 = (array_t*)malloc(sizeof(array_t));
            array298->size = 574;
            array298->refC = 1;
            array298->id = 298;
            array298->data = (unsigned int*)malloc(array298->size*sizeof(unsigned int));
            memset(array298->data, 0, array298->size*sizeof(unsigned int));
            DEBUG_NEW(array298->id);
         }
         array_t* array299;
         if (pCounter > 0) {
            array299 = vars->data[--pCounter];
            array299->refC++;
            DEBUG_COPY(array299->id);
         } else {
            array299 = (array_t*)malloc(sizeof(array_t));
            array299->size = 491;
            array299->refC = 1;
            array299->id = 299;
            array299->data = (unsigned int*)malloc(array299->size*sizeof(unsigned int));
            memset(array299->data, 0, array299->size*sizeof(unsigned int));
            DEBUG_NEW(array299->id);
         }
         array299->refC--;
         if(array299->refC == 0) {
            free(array299->data);
            free(array299);
            DEBUG_FREE(array299->id);
         }
         array298->refC--;
         if(array298->refC == 0) {
            free(array298->data);
            free(array298);
            DEBUG_FREE(array298->id);
         }
         array295->refC--;
         if(array295->refC == 0) {
            free(array295->data);
            free(array295);
            DEBUG_FREE(array295->id);
         }
         array294->refC--;
         if(array294->refC == 0) {
            free(array294->data);
            free(array294);
            DEBUG_FREE(array294->id);
         }
         array293->refC--;
         if(array293->refC == 0) {
            free(array293->data);
            free(array293);
            DEBUG_FREE(array293->id);
         }
         array290->refC--;
         if(array290->refC == 0) {
            free(array290->data);
            free(array290);
            DEBUG_FREE(array290->id);
         }
      }
      else {
         if(PATH0 & 8) {
            array_t* array300;
            if (pCounter > 0) {
               array300 = vars->data[--pCounter];
               array300->refC++;
               DEBUG_COPY(array300->id);
            } else {
               array300 = (array_t*)malloc(sizeof(array_t));
               array300->size = 947;
               array300->refC = 1;
               array300->id = 300;
               array300->data = (unsigned int*)malloc(array300->size*sizeof(unsigned int));
               memset(array300->data, 0, array300->size*sizeof(unsigned int));
               DEBUG_NEW(array300->id);
            }
            array_t_param params1;
            params1.size = 2;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array289;
            params1.data[1] = array300;
            array_t* array301 = func22(&params1, loopsFactor);
            DEBUG_RETURN(array301->id);
            free(params1.data);
            array_t* array302;
            if (pCounter > 0) {
               array302 = vars->data[--pCounter];
               array302->refC++;
               DEBUG_COPY(array302->id);
            } else {
               array302 = (array_t*)malloc(sizeof(array_t));
               array302->size = 21;
               array302->refC = 1;
               array302->id = 302;
               array302->data = (unsigned int*)malloc(array302->size*sizeof(unsigned int));
               memset(array302->data, 0, array302->size*sizeof(unsigned int));
               DEBUG_NEW(array302->id);
            }
            array_t* array303;
            if (pCounter > 0) {
               array303 = vars->data[--pCounter];
               array303->refC++;
               DEBUG_COPY(array303->id);
            } else {
               array303 = (array_t*)malloc(sizeof(array_t));
               array303->size = 537;
               array303->refC = 1;
               array303->id = 303;
               array303->data = (unsigned int*)malloc(array303->size*sizeof(unsigned int));
               memset(array303->data, 0, array303->size*sizeof(unsigned int));
               DEBUG_NEW(array303->id);
            }
            array303->refC--;
            if(array303->refC == 0) {
               free(array303->data);
               free(array303);
               DEBUG_FREE(array303->id);
            }
            array302->refC--;
            if(array302->refC == 0) {
               free(array302->data);
               free(array302);
               DEBUG_FREE(array302->id);
            }
            array301->refC--;
            if(array301->refC == 0) {
               free(array301->data);
               free(array301);
               DEBUG_FREE(array301->id);
            }
            array300->refC--;
            if(array300->refC == 0) {
               free(array300->data);
               free(array300);
               DEBUG_FREE(array300->id);
            }
         }
         else {
            array_t_param params1;
            params1.size = 1;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array289;
            array_t* array304 = func23(&params1, loopsFactor);
            DEBUG_RETURN(array304->id);
            free(params1.data);
            array_t* array305;
            if (pCounter > 0) {
               array305 = vars->data[--pCounter];
               array305->refC++;
               DEBUG_COPY(array305->id);
            } else {
               array305 = (array_t*)malloc(sizeof(array_t));
               array305->size = 30;
               array305->refC = 1;
               array305->id = 305;
               array305->data = (unsigned int*)malloc(array305->size*sizeof(unsigned int));
               memset(array305->data, 0, array305->size*sizeof(unsigned int));
               DEBUG_NEW(array305->id);
            }
            array305->refC--;
            if(array305->refC == 0) {
               free(array305->data);
               free(array305);
               DEBUG_FREE(array305->id);
            }
            array304->refC--;
            if(array304->refC == 0) {
               free(array304->data);
               free(array304);
               DEBUG_FREE(array304->id);
            }
         }
         array_t_param params1;
         params1.size = 1;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array289;
         array_t* array306 = func21(&params1, rng(), loopsFactor);
         DEBUG_RETURN(array306->id);
         free(params1.data);
         array_t* array307;
         if (pCounter > 0) {
            array307 = vars->data[--pCounter];
            array307->refC++;
            DEBUG_COPY(array307->id);
         } else {
            array307 = (array_t*)malloc(sizeof(array_t));
            array307->size = 81;
            array307->refC = 1;
            array307->id = 307;
            array307->data = (unsigned int*)malloc(array307->size*sizeof(unsigned int));
            memset(array307->data, 0, array307->size*sizeof(unsigned int));
            DEBUG_NEW(array307->id);
         }
         array307->refC--;
         if(array307->refC == 0) {
            free(array307->data);
            free(array307);
            DEBUG_FREE(array307->id);
         }
         array306->refC--;
         if(array306->refC == 0) {
            free(array306->data);
            free(array306);
            DEBUG_FREE(array306->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array289;
   array_t* array308 = func16(&params1, rng(), loopsFactor);
   DEBUG_RETURN(array308->id);
   free(params1.data);
   array_t* array309;
   if (pCounter > 0) {
      array309 = vars->data[--pCounter];
      array309->refC++;
      DEBUG_COPY(array309->id);
   } else {
      array309 = (array_t*)malloc(sizeof(array_t));
      array309->size = 2;
      array309->refC = 1;
      array309->id = 309;
      array309->data = (unsigned int*)malloc(array309->size*sizeof(unsigned int));
      memset(array309->data, 0, array309->size*sizeof(unsigned int));
      DEBUG_NEW(array309->id);
   }
   array_t* array310;
   if (pCounter > 0) {
      array310 = vars->data[--pCounter];
      array310->refC++;
      DEBUG_COPY(array310->id);
   } else {
      array310 = (array_t*)malloc(sizeof(array_t));
      array310->size = 231;
      array310->refC = 1;
      array310->id = 310;
      array310->data = (unsigned int*)malloc(array310->size*sizeof(unsigned int));
      memset(array310->data, 0, array310->size*sizeof(unsigned int));
      DEBUG_NEW(array310->id);
   }
   array309->refC--;
   if(array309->refC == 0) {
      free(array309->data);
      free(array309);
      DEBUG_FREE(array309->id);
   }
   array308->refC--;
   if(array308->refC == 0) {
      free(array308->data);
      free(array308);
      DEBUG_FREE(array308->id);
   }
   array289->refC--;
   if(array289->refC == 0) {
      free(array289->data);
      free(array289);
      DEBUG_FREE(array289->id);
   }
   return array310;
}

