#include "outs/4_2_array.h" 
array_t* func5(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t_param params0;
   params0.size = 0;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   array_t* array356 = func10(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array356->id);
   free(params0.data);
   for (int i = 0; i < array356->size; i++) {
      if (array356->data[i] == 18) { 
         return array356;
      }
   }
   unsigned int loop64 = 0;
   unsigned int loopLimit64 = (rand()%loopsFactor)/2 + 1;
   for(; loop64 < loopLimit64; loop64++) {
      for (int i = 0; i < array356->size; i++) {
         array356->data[i]--;
      }
      for (int i = 0; i < array356->size; i++) {
         if (array356->data[i] == 63) { 
            return array356;
         }
      }
      if(PATH0 & 1) {
         array_t* array357;
         if (pCounter > 0) {
            array357 = vars->data[--pCounter];
            array357->refC++;
            DEBUG_COPY(array357->id);
         } else {
            array357 = (array_t*)malloc(sizeof(array_t));
            array357->size = 55;
            array357->refC = 1;
            array357->id = 357;
            array357->data = (unsigned int*)malloc(array357->size*sizeof(unsigned int));
            memset(array357->data, 0, array357->size*sizeof(unsigned int));
            DEBUG_NEW(array357->id);
         }
         unsigned int loop65 = 0;
         unsigned int loopLimit65 = (rand()%loopsFactor)/3 + 1;
         for(; loop65 < loopLimit65; loop65++) {
            array_t* array358;
            if (pCounter > 0) {
               array358 = vars->data[--pCounter];
               array358->refC++;
               DEBUG_COPY(array358->id);
            } else {
               array358 = (array_t*)malloc(sizeof(array_t));
               array358->size = 90;
               array358->refC = 1;
               array358->id = 358;
               array358->data = (unsigned int*)malloc(array358->size*sizeof(unsigned int));
               memset(array358->data, 0, array358->size*sizeof(unsigned int));
               DEBUG_NEW(array358->id);
            }
            if(PATH0 & 2) {
            }
            else {
            }
            for (int i = 0; i < array358->size; i++) {
               if (array358->data[i] == 30) { 
                  return array358;
               }
            }
            array_t* array359;
            if (pCounter > 0) {
               array359 = vars->data[--pCounter];
               array359->refC++;
               DEBUG_COPY(array359->id);
            } else {
               array359 = (array_t*)malloc(sizeof(array_t));
               array359->size = 904;
               array359->refC = 1;
               array359->id = 359;
               array359->data = (unsigned int*)malloc(array359->size*sizeof(unsigned int));
               memset(array359->data, 0, array359->size*sizeof(unsigned int));
               DEBUG_NEW(array359->id);
            }
            array359->refC--;
            if(array359->refC == 0) {
               free(array359->data);
               free(array359);
               DEBUG_FREE(array359->id);
            }
            array358->refC--;
            if(array358->refC == 0) {
               free(array358->data);
               free(array358);
               DEBUG_FREE(array358->id);
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array356;
         params1.data[1] = array357;
         array_t* array360 = func12(&params1, loopsFactor);
         DEBUG_RETURN(array360->id);
         free(params1.data);
         array_t* array361;
         if (pCounter > 0) {
            array361 = vars->data[--pCounter];
            array361->refC++;
            DEBUG_COPY(array361->id);
         } else {
            array361 = (array_t*)malloc(sizeof(array_t));
            array361->size = 633;
            array361->refC = 1;
            array361->id = 361;
            array361->data = (unsigned int*)malloc(array361->size*sizeof(unsigned int));
            memset(array361->data, 0, array361->size*sizeof(unsigned int));
            DEBUG_NEW(array361->id);
         }
         array_t* array362;
         if (pCounter > 0) {
            array362 = vars->data[--pCounter];
            array362->refC++;
            DEBUG_COPY(array362->id);
         } else {
            array362 = (array_t*)malloc(sizeof(array_t));
            array362->size = 685;
            array362->refC = 1;
            array362->id = 362;
            array362->data = (unsigned int*)malloc(array362->size*sizeof(unsigned int));
            memset(array362->data, 0, array362->size*sizeof(unsigned int));
            DEBUG_NEW(array362->id);
         }
         unsigned int loop66 = 0;
         unsigned int loopLimit66 = (rand()%loopsFactor)/3 + 1;
         for(; loop66 < loopLimit66; loop66++) {
            for (int i = 0; i < array362->size; i++) {
               array362->data[i]++;
            }
            for (int i = 0; i < array361->size; i++) {
               if (array361->data[i] == 4) { 
                  return array361;
               }
            }
            if(PATH0 & 4) {
               array_t_param params2;
               params2.size = 5;
               params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
               params2.data[0] = array356;
               params2.data[1] = array357;
               params2.data[2] = array360;
               params2.data[3] = array361;
               params2.data[4] = array362;
               array_t* array363 = func19(&params2, loopsFactor);
               DEBUG_RETURN(array363->id);
               free(params2.data);
               array_t* array364;
               if (pCounter > 0) {
                  array364 = vars->data[--pCounter];
                  array364->refC++;
                  DEBUG_COPY(array364->id);
               } else {
                  array364 = (array_t*)malloc(sizeof(array_t));
                  array364->size = 250;
                  array364->refC = 1;
                  array364->id = 364;
                  array364->data = (unsigned int*)malloc(array364->size*sizeof(unsigned int));
                  memset(array364->data, 0, array364->size*sizeof(unsigned int));
                  DEBUG_NEW(array364->id);
               }
               array364->refC--;
               if(array364->refC == 0) {
                  free(array364->data);
                  free(array364);
                  DEBUG_FREE(array364->id);
               }
               array363->refC--;
               if(array363->refC == 0) {
                  free(array363->data);
                  free(array363);
                  DEBUG_FREE(array363->id);
               }
            }
            else {
            }
         }
         array_t* array365;
         if (pCounter > 0) {
            array365 = vars->data[--pCounter];
            array365->refC++;
            DEBUG_COPY(array365->id);
         } else {
            array365 = (array_t*)malloc(sizeof(array_t));
            array365->size = 868;
            array365->refC = 1;
            array365->id = 365;
            array365->data = (unsigned int*)malloc(array365->size*sizeof(unsigned int));
            memset(array365->data, 0, array365->size*sizeof(unsigned int));
            DEBUG_NEW(array365->id);
         }
         array_t* array366;
         if (pCounter > 0) {
            array366 = vars->data[--pCounter];
            array366->refC++;
            DEBUG_COPY(array366->id);
         } else {
            array366 = (array_t*)malloc(sizeof(array_t));
            array366->size = 503;
            array366->refC = 1;
            array366->id = 366;
            array366->data = (unsigned int*)malloc(array366->size*sizeof(unsigned int));
            memset(array366->data, 0, array366->size*sizeof(unsigned int));
            DEBUG_NEW(array366->id);
         }
         array366->refC--;
         if(array366->refC == 0) {
            free(array366->data);
            free(array366);
            DEBUG_FREE(array366->id);
         }
         array365->refC--;
         if(array365->refC == 0) {
            free(array365->data);
            free(array365);
            DEBUG_FREE(array365->id);
         }
         array362->refC--;
         if(array362->refC == 0) {
            free(array362->data);
            free(array362);
            DEBUG_FREE(array362->id);
         }
         array361->refC--;
         if(array361->refC == 0) {
            free(array361->data);
            free(array361);
            DEBUG_FREE(array361->id);
         }
         array360->refC--;
         if(array360->refC == 0) {
            free(array360->data);
            free(array360);
            DEBUG_FREE(array360->id);
         }
         array357->refC--;
         if(array357->refC == 0) {
            free(array357->data);
            free(array357);
            DEBUG_FREE(array357->id);
         }
      }
      else {
         if(PATH0 & 8) {
            array_t* array367;
            if (pCounter > 0) {
               array367 = vars->data[--pCounter];
               array367->refC++;
               DEBUG_COPY(array367->id);
            } else {
               array367 = (array_t*)malloc(sizeof(array_t));
               array367->size = 485;
               array367->refC = 1;
               array367->id = 367;
               array367->data = (unsigned int*)malloc(array367->size*sizeof(unsigned int));
               memset(array367->data, 0, array367->size*sizeof(unsigned int));
               DEBUG_NEW(array367->id);
            }
            array_t_param params1;
            params1.size = 2;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array356;
            params1.data[1] = array367;
            array_t* array368 = func20(&params1, loopsFactor);
            DEBUG_RETURN(array368->id);
            free(params1.data);
            array_t* array369;
            if (pCounter > 0) {
               array369 = vars->data[--pCounter];
               array369->refC++;
               DEBUG_COPY(array369->id);
            } else {
               array369 = (array_t*)malloc(sizeof(array_t));
               array369->size = 639;
               array369->refC = 1;
               array369->id = 369;
               array369->data = (unsigned int*)malloc(array369->size*sizeof(unsigned int));
               memset(array369->data, 0, array369->size*sizeof(unsigned int));
               DEBUG_NEW(array369->id);
            }
            array_t* array370;
            if (pCounter > 0) {
               array370 = vars->data[--pCounter];
               array370->refC++;
               DEBUG_COPY(array370->id);
            } else {
               array370 = (array_t*)malloc(sizeof(array_t));
               array370->size = 949;
               array370->refC = 1;
               array370->id = 370;
               array370->data = (unsigned int*)malloc(array370->size*sizeof(unsigned int));
               memset(array370->data, 0, array370->size*sizeof(unsigned int));
               DEBUG_NEW(array370->id);
            }
            array370->refC--;
            if(array370->refC == 0) {
               free(array370->data);
               free(array370);
               DEBUG_FREE(array370->id);
            }
            array369->refC--;
            if(array369->refC == 0) {
               free(array369->data);
               free(array369);
               DEBUG_FREE(array369->id);
            }
            array368->refC--;
            if(array368->refC == 0) {
               free(array368->data);
               free(array368);
               DEBUG_FREE(array368->id);
            }
            array367->refC--;
            if(array367->refC == 0) {
               free(array367->data);
               free(array367);
               DEBUG_FREE(array367->id);
            }
         }
         else {
            array_t_param params1;
            params1.size = 1;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array356;
            array_t* array371 = func21(&params1, loopsFactor);
            DEBUG_RETURN(array371->id);
            free(params1.data);
            array_t* array372;
            if (pCounter > 0) {
               array372 = vars->data[--pCounter];
               array372->refC++;
               DEBUG_COPY(array372->id);
            } else {
               array372 = (array_t*)malloc(sizeof(array_t));
               array372->size = 226;
               array372->refC = 1;
               array372->id = 372;
               array372->data = (unsigned int*)malloc(array372->size*sizeof(unsigned int));
               memset(array372->data, 0, array372->size*sizeof(unsigned int));
               DEBUG_NEW(array372->id);
            }
            array372->refC--;
            if(array372->refC == 0) {
               free(array372->data);
               free(array372);
               DEBUG_FREE(array372->id);
            }
            array371->refC--;
            if(array371->refC == 0) {
               free(array371->data);
               free(array371);
               DEBUG_FREE(array371->id);
            }
         }
         array_t_param params1;
         params1.size = 1;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array356;
         array_t* array373 = func13(&params1, rng(), loopsFactor);
         DEBUG_RETURN(array373->id);
         free(params1.data);
         array_t* array374;
         if (pCounter > 0) {
            array374 = vars->data[--pCounter];
            array374->refC++;
            DEBUG_COPY(array374->id);
         } else {
            array374 = (array_t*)malloc(sizeof(array_t));
            array374->size = 596;
            array374->refC = 1;
            array374->id = 374;
            array374->data = (unsigned int*)malloc(array374->size*sizeof(unsigned int));
            memset(array374->data, 0, array374->size*sizeof(unsigned int));
            DEBUG_NEW(array374->id);
         }
         array374->refC--;
         if(array374->refC == 0) {
            free(array374->data);
            free(array374);
            DEBUG_FREE(array374->id);
         }
         array373->refC--;
         if(array373->refC == 0) {
            free(array373->data);
            free(array373);
            DEBUG_FREE(array373->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 1;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array356;
   array_t* array375 = func11(&params1, rng(), loopsFactor);
   DEBUG_RETURN(array375->id);
   free(params1.data);
   array_t* array376;
   if (pCounter > 0) {
      array376 = vars->data[--pCounter];
      array376->refC++;
      DEBUG_COPY(array376->id);
   } else {
      array376 = (array_t*)malloc(sizeof(array_t));
      array376->size = 560;
      array376->refC = 1;
      array376->id = 376;
      array376->data = (unsigned int*)malloc(array376->size*sizeof(unsigned int));
      memset(array376->data, 0, array376->size*sizeof(unsigned int));
      DEBUG_NEW(array376->id);
   }
   array_t* array377;
   if (pCounter > 0) {
      array377 = vars->data[--pCounter];
      array377->refC++;
      DEBUG_COPY(array377->id);
   } else {
      array377 = (array_t*)malloc(sizeof(array_t));
      array377->size = 36;
      array377->refC = 1;
      array377->id = 377;
      array377->data = (unsigned int*)malloc(array377->size*sizeof(unsigned int));
      memset(array377->data, 0, array377->size*sizeof(unsigned int));
      DEBUG_NEW(array377->id);
   }
   array376->refC--;
   if(array376->refC == 0) {
      free(array376->data);
      free(array376);
      DEBUG_FREE(array376->id);
   }
   array375->refC--;
   if(array375->refC == 0) {
      free(array375->data);
      free(array375);
      DEBUG_FREE(array375->id);
   }
   array356->refC--;
   if(array356->refC == 0) {
      free(array356->data);
      free(array356);
      DEBUG_FREE(array356->id);
   }
   return array377;
}

