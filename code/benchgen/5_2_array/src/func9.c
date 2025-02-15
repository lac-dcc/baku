#include "outs/5_2_array.h" 
array_t* func9(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array374;
   if (pCounter > 0) {
      array374 = vars->data[--pCounter];
      array374->refC++;
      DEBUG_COPY(array374->id);
   } else {
      array374 = (array_t*)malloc(sizeof(array_t));
      array374->size = 560;
      array374->refC = 1;
      array374->id = 374;
      array374->data = (unsigned int*)malloc(array374->size*sizeof(unsigned int));
      memset(array374->data, 0, array374->size*sizeof(unsigned int));
      DEBUG_NEW(array374->id);
   }
   unsigned int loop68 = 0;
   unsigned int loopLimit68 = (rand()%loopsFactor)/3 + 1;
   for(; loop68 < loopLimit68; loop68++) {
      for (int i = 0; i < array374->size; i++) {
         array374->data[i]--;
      }
      unsigned int loop69 = 0;
      unsigned int loopLimit69 = (rand()%loopsFactor)/4 + 1;
      for(; loop69 < loopLimit69; loop69++) {
         array_t* array375;
         if (pCounter > 0) {
            array375 = vars->data[--pCounter];
            array375->refC++;
            DEBUG_COPY(array375->id);
         } else {
            array375 = (array_t*)malloc(sizeof(array_t));
            array375->size = 955;
            array375->refC = 1;
            array375->id = 375;
            array375->data = (unsigned int*)malloc(array375->size*sizeof(unsigned int));
            memset(array375->data, 0, array375->size*sizeof(unsigned int));
            DEBUG_NEW(array375->id);
         }
         if(PATH0 & 1) {
            array_t* array376;
            if (pCounter > 0) {
               array376 = vars->data[--pCounter];
               array376->refC++;
               DEBUG_COPY(array376->id);
            } else {
               array376 = (array_t*)malloc(sizeof(array_t));
               array376->size = 770;
               array376->refC = 1;
               array376->id = 376;
               array376->data = (unsigned int*)malloc(array376->size*sizeof(unsigned int));
               memset(array376->data, 0, array376->size*sizeof(unsigned int));
               DEBUG_NEW(array376->id);
            }
            unsigned int loop70 = 0;
            unsigned int loopLimit70 = (rand()%loopsFactor)/5 + 1;
            for(; loop70 < loopLimit70; loop70++) {
               array_t* array377;
               if (pCounter > 0) {
                  array377 = vars->data[--pCounter];
                  array377->refC++;
                  DEBUG_COPY(array377->id);
               } else {
                  array377 = (array_t*)malloc(sizeof(array_t));
                  array377->size = 518;
                  array377->refC = 1;
                  array377->id = 377;
                  array377->data = (unsigned int*)malloc(array377->size*sizeof(unsigned int));
                  memset(array377->data, 0, array377->size*sizeof(unsigned int));
                  DEBUG_NEW(array377->id);
               }
               if(PATH0 & 2) {
               }
               else {
               }
               for (int i = 0; i < array377->size; i++) {
                  if (array377->data[i] == 42) { 
                     return array377;
                  }
               }
               array_t* array378;
               if (pCounter > 0) {
                  array378 = vars->data[--pCounter];
                  array378->refC++;
                  DEBUG_COPY(array378->id);
               } else {
                  array378 = (array_t*)malloc(sizeof(array_t));
                  array378->size = 532;
                  array378->refC = 1;
                  array378->id = 378;
                  array378->data = (unsigned int*)malloc(array378->size*sizeof(unsigned int));
                  memset(array378->data, 0, array378->size*sizeof(unsigned int));
                  DEBUG_NEW(array378->id);
               }
               array378->refC--;
               if(array378->refC == 0) {
                  free(array378->data);
                  free(array378);
                  DEBUG_FREE(array378->id);
               }
               array377->refC--;
               if(array377->refC == 0) {
                  free(array377->data);
                  free(array377);
                  DEBUG_FREE(array377->id);
               }
            }
            array_t_param params0;
            params0.size = 3;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array374;
            params0.data[1] = array375;
            params0.data[2] = array376;
            array_t* array379 = func20(&params0, loopsFactor);
            DEBUG_RETURN(array379->id);
            free(params0.data);
            array_t* array380;
            if (pCounter > 0) {
               array380 = vars->data[--pCounter];
               array380->refC++;
               DEBUG_COPY(array380->id);
            } else {
               array380 = (array_t*)malloc(sizeof(array_t));
               array380->size = 321;
               array380->refC = 1;
               array380->id = 380;
               array380->data = (unsigned int*)malloc(array380->size*sizeof(unsigned int));
               memset(array380->data, 0, array380->size*sizeof(unsigned int));
               DEBUG_NEW(array380->id);
            }
            array_t* array381;
            if (pCounter > 0) {
               array381 = vars->data[--pCounter];
               array381->refC++;
               DEBUG_COPY(array381->id);
            } else {
               array381 = (array_t*)malloc(sizeof(array_t));
               array381->size = 270;
               array381->refC = 1;
               array381->id = 381;
               array381->data = (unsigned int*)malloc(array381->size*sizeof(unsigned int));
               memset(array381->data, 0, array381->size*sizeof(unsigned int));
               DEBUG_NEW(array381->id);
            }
            unsigned int loop71 = 0;
            unsigned int loopLimit71 = (rand()%loopsFactor)/5 + 1;
            for(; loop71 < loopLimit71; loop71++) {
               for (int i = 0; i < array376->size; i++) {
                  array376->data[i]++;
               }
               for (int i = 0; i < array380->size; i++) {
                  if (array380->data[i] == 27) { 
                     return array380;
                  }
               }
               if(PATH0 & 4) {
                  array_t_param params1;
                  params1.size = 6;
                  params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
                  params1.data[0] = array374;
                  params1.data[1] = array375;
                  params1.data[2] = array376;
                  params1.data[3] = array379;
                  params1.data[4] = array380;
                  params1.data[5] = array381;
                  array_t* array382 = func24(&params1, loopsFactor);
                  DEBUG_RETURN(array382->id);
                  free(params1.data);
                  array_t* array383;
                  if (pCounter > 0) {
                     array383 = vars->data[--pCounter];
                     array383->refC++;
                     DEBUG_COPY(array383->id);
                  } else {
                     array383 = (array_t*)malloc(sizeof(array_t));
                     array383->size = 283;
                     array383->refC = 1;
                     array383->id = 383;
                     array383->data = (unsigned int*)malloc(array383->size*sizeof(unsigned int));
                     memset(array383->data, 0, array383->size*sizeof(unsigned int));
                     DEBUG_NEW(array383->id);
                  }
                  array383->refC--;
                  if(array383->refC == 0) {
                     free(array383->data);
                     free(array383);
                     DEBUG_FREE(array383->id);
                  }
                  array382->refC--;
                  if(array382->refC == 0) {
                     free(array382->data);
                     free(array382);
                     DEBUG_FREE(array382->id);
                  }
               }
               else {
               }
            }
            array_t* array384;
            if (pCounter > 0) {
               array384 = vars->data[--pCounter];
               array384->refC++;
               DEBUG_COPY(array384->id);
            } else {
               array384 = (array_t*)malloc(sizeof(array_t));
               array384->size = 72;
               array384->refC = 1;
               array384->id = 384;
               array384->data = (unsigned int*)malloc(array384->size*sizeof(unsigned int));
               memset(array384->data, 0, array384->size*sizeof(unsigned int));
               DEBUG_NEW(array384->id);
            }
            array_t* array385;
            if (pCounter > 0) {
               array385 = vars->data[--pCounter];
               array385->refC++;
               DEBUG_COPY(array385->id);
            } else {
               array385 = (array_t*)malloc(sizeof(array_t));
               array385->size = 398;
               array385->refC = 1;
               array385->id = 385;
               array385->data = (unsigned int*)malloc(array385->size*sizeof(unsigned int));
               memset(array385->data, 0, array385->size*sizeof(unsigned int));
               DEBUG_NEW(array385->id);
            }
            array385->refC--;
            if(array385->refC == 0) {
               free(array385->data);
               free(array385);
               DEBUG_FREE(array385->id);
            }
            array384->refC--;
            if(array384->refC == 0) {
               free(array384->data);
               free(array384);
               DEBUG_FREE(array384->id);
            }
            array381->refC--;
            if(array381->refC == 0) {
               free(array381->data);
               free(array381);
               DEBUG_FREE(array381->id);
            }
            array380->refC--;
            if(array380->refC == 0) {
               free(array380->data);
               free(array380);
               DEBUG_FREE(array380->id);
            }
            array379->refC--;
            if(array379->refC == 0) {
               free(array379->data);
               free(array379);
               DEBUG_FREE(array379->id);
            }
            array376->refC--;
            if(array376->refC == 0) {
               free(array376->data);
               free(array376);
               DEBUG_FREE(array376->id);
            }
         }
         else {
            if(PATH0 & 8) {
               array_t* array386;
               if (pCounter > 0) {
                  array386 = vars->data[--pCounter];
                  array386->refC++;
                  DEBUG_COPY(array386->id);
               } else {
                  array386 = (array_t*)malloc(sizeof(array_t));
                  array386->size = 830;
                  array386->refC = 1;
                  array386->id = 386;
                  array386->data = (unsigned int*)malloc(array386->size*sizeof(unsigned int));
                  memset(array386->data, 0, array386->size*sizeof(unsigned int));
                  DEBUG_NEW(array386->id);
               }
               array_t_param params0;
               params0.size = 3;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array374;
               params0.data[1] = array375;
               params0.data[2] = array386;
               array_t* array387 = func22(&params0, loopsFactor);
               DEBUG_RETURN(array387->id);
               free(params0.data);
               array_t* array388;
               if (pCounter > 0) {
                  array388 = vars->data[--pCounter];
                  array388->refC++;
                  DEBUG_COPY(array388->id);
               } else {
                  array388 = (array_t*)malloc(sizeof(array_t));
                  array388->size = 950;
                  array388->refC = 1;
                  array388->id = 388;
                  array388->data = (unsigned int*)malloc(array388->size*sizeof(unsigned int));
                  memset(array388->data, 0, array388->size*sizeof(unsigned int));
                  DEBUG_NEW(array388->id);
               }
               array_t* array389;
               if (pCounter > 0) {
                  array389 = vars->data[--pCounter];
                  array389->refC++;
                  DEBUG_COPY(array389->id);
               } else {
                  array389 = (array_t*)malloc(sizeof(array_t));
                  array389->size = 30;
                  array389->refC = 1;
                  array389->id = 389;
                  array389->data = (unsigned int*)malloc(array389->size*sizeof(unsigned int));
                  memset(array389->data, 0, array389->size*sizeof(unsigned int));
                  DEBUG_NEW(array389->id);
               }
               array389->refC--;
               if(array389->refC == 0) {
                  free(array389->data);
                  free(array389);
                  DEBUG_FREE(array389->id);
               }
               array388->refC--;
               if(array388->refC == 0) {
                  free(array388->data);
                  free(array388);
                  DEBUG_FREE(array388->id);
               }
               array387->refC--;
               if(array387->refC == 0) {
                  free(array387->data);
                  free(array387);
                  DEBUG_FREE(array387->id);
               }
               array386->refC--;
               if(array386->refC == 0) {
                  free(array386->data);
                  free(array386);
                  DEBUG_FREE(array386->id);
               }
            }
            else {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array374;
               params0.data[1] = array375;
               array_t* array390 = func23(&params0, loopsFactor);
               DEBUG_RETURN(array390->id);
               free(params0.data);
               array_t* array391;
               if (pCounter > 0) {
                  array391 = vars->data[--pCounter];
                  array391->refC++;
                  DEBUG_COPY(array391->id);
               } else {
                  array391 = (array_t*)malloc(sizeof(array_t));
                  array391->size = 59;
                  array391->refC = 1;
                  array391->id = 391;
                  array391->data = (unsigned int*)malloc(array391->size*sizeof(unsigned int));
                  memset(array391->data, 0, array391->size*sizeof(unsigned int));
                  DEBUG_NEW(array391->id);
               }
               array391->refC--;
               if(array391->refC == 0) {
                  free(array391->data);
                  free(array391);
                  DEBUG_FREE(array391->id);
               }
               array390->refC--;
               if(array390->refC == 0) {
                  free(array390->data);
                  free(array390);
                  DEBUG_FREE(array390->id);
               }
            }
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array374;
            params0.data[1] = array375;
            array_t* array392 = func21(&params0, rng(), loopsFactor);
            DEBUG_RETURN(array392->id);
            free(params0.data);
            array_t* array393;
            if (pCounter > 0) {
               array393 = vars->data[--pCounter];
               array393->refC++;
               DEBUG_COPY(array393->id);
            } else {
               array393 = (array_t*)malloc(sizeof(array_t));
               array393->size = 924;
               array393->refC = 1;
               array393->id = 393;
               array393->data = (unsigned int*)malloc(array393->size*sizeof(unsigned int));
               memset(array393->data, 0, array393->size*sizeof(unsigned int));
               DEBUG_NEW(array393->id);
            }
            array393->refC--;
            if(array393->refC == 0) {
               free(array393->data);
               free(array393);
               DEBUG_FREE(array393->id);
            }
            array392->refC--;
            if(array392->refC == 0) {
               free(array392->data);
               free(array392);
               DEBUG_FREE(array392->id);
            }
         }
         if(PATH0 & 16) {
            array_t* array394;
            if (pCounter > 0) {
               array394 = vars->data[--pCounter];
               array394->refC++;
               DEBUG_COPY(array394->id);
            } else {
               array394 = (array_t*)malloc(sizeof(array_t));
               array394->size = 82;
               array394->refC = 1;
               array394->id = 394;
               array394->data = (unsigned int*)malloc(array394->size*sizeof(unsigned int));
               memset(array394->data, 0, array394->size*sizeof(unsigned int));
               DEBUG_NEW(array394->id);
            }
            unsigned int loop72 = 0;
            unsigned int loopLimit72 = (rand()%loopsFactor)/5 + 1;
            for(; loop72 < loopLimit72; loop72++) {
               for (int i = 0; i < array374->size; i++) {
                  array374->data[i]++;
               }
               for (int i = 0; i < array374->size; i++) {
                  if (array374->data[i] == 4) { 
                     return array374;
                  }
               }
               if(PATH0 & 32) {
                  array_t_param params0;
                  params0.size = 3;
                  params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                  params0.data[0] = array374;
                  params0.data[1] = array375;
                  params0.data[2] = array394;
                  array_t* array395 = func19(&params0, rng(), loopsFactor);
                  DEBUG_RETURN(array395->id);
                  free(params0.data);
                  array_t* array396;
                  if (pCounter > 0) {
                     array396 = vars->data[--pCounter];
                     array396->refC++;
                     DEBUG_COPY(array396->id);
                  } else {
                     array396 = (array_t*)malloc(sizeof(array_t));
                     array396->size = 898;
                     array396->refC = 1;
                     array396->id = 396;
                     array396->data = (unsigned int*)malloc(array396->size*sizeof(unsigned int));
                     memset(array396->data, 0, array396->size*sizeof(unsigned int));
                     DEBUG_NEW(array396->id);
                  }
                  array396->refC--;
                  if(array396->refC == 0) {
                     free(array396->data);
                     free(array396);
                     DEBUG_FREE(array396->id);
                  }
                  array395->refC--;
                  if(array395->refC == 0) {
                     free(array395->data);
                     free(array395);
                     DEBUG_FREE(array395->id);
                  }
               }
               else {
                  array_t* array397;
                  if (pCounter > 0) {
                     array397 = vars->data[--pCounter];
                     array397->refC++;
                     DEBUG_COPY(array397->id);
                  } else {
                     array397 = (array_t*)malloc(sizeof(array_t));
                     array397->size = 486;
                     array397->refC = 1;
                     array397->id = 397;
                     array397->data = (unsigned int*)malloc(array397->size*sizeof(unsigned int));
                     memset(array397->data, 0, array397->size*sizeof(unsigned int));
                     DEBUG_NEW(array397->id);
                  }
                  unsigned int loop73 = 0;
                  unsigned int loopLimit73 = (rand()%loopsFactor)/6 + 1;
                  for(; loop73 < loopLimit73; loop73++) {
                     for (int i = 0; i < array374->size; i++) {
                        array374->data[i]++;
                     }
                     for (int i = 0; i < array394->size; i++) {
                        if (array394->data[i] == 59) { 
                           return array394;
                        }
                     }
                     if(PATH0 & 64) {
                        array_t_param params0;
                        params0.size = 4;
                        params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                        params0.data[0] = array374;
                        params0.data[1] = array375;
                        params0.data[2] = array394;
                        params0.data[3] = array397;
                        array_t* array398 = func24(&params0, loopsFactor);
                        DEBUG_RETURN(array398->id);
                        free(params0.data);
                        array_t* array399;
                        if (pCounter > 0) {
                           array399 = vars->data[--pCounter];
                           array399->refC++;
                           DEBUG_COPY(array399->id);
                        } else {
                           array399 = (array_t*)malloc(sizeof(array_t));
                           array399->size = 683;
                           array399->refC = 1;
                           array399->id = 399;
                           array399->data = (unsigned int*)malloc(array399->size*sizeof(unsigned int));
                           memset(array399->data, 0, array399->size*sizeof(unsigned int));
                           DEBUG_NEW(array399->id);
                        }
                        array399->refC--;
                        if(array399->refC == 0) {
                           free(array399->data);
                           free(array399);
                           DEBUG_FREE(array399->id);
                        }
                        array398->refC--;
                        if(array398->refC == 0) {
                           free(array398->data);
                           free(array398);
                           DEBUG_FREE(array398->id);
                        }
                     }
                     else {
                     }
                  }
                  array_t* array400;
                  if (pCounter > 0) {
                     array400 = vars->data[--pCounter];
                     array400->refC++;
                     DEBUG_COPY(array400->id);
                  } else {
                     array400 = (array_t*)malloc(sizeof(array_t));
                     array400->size = 41;
                     array400->refC = 1;
                     array400->id = 400;
                     array400->data = (unsigned int*)malloc(array400->size*sizeof(unsigned int));
                     memset(array400->data, 0, array400->size*sizeof(unsigned int));
                     DEBUG_NEW(array400->id);
                  }
                  array400->refC--;
                  if(array400->refC == 0) {
                     free(array400->data);
                     free(array400);
                     DEBUG_FREE(array400->id);
                  }
                  array397->refC--;
                  if(array397->refC == 0) {
                     free(array397->data);
                     free(array397);
                     DEBUG_FREE(array397->id);
                  }
               }
            }
            array_t* array401;
            if (pCounter > 0) {
               array401 = vars->data[--pCounter];
               array401->refC++;
               DEBUG_COPY(array401->id);
            } else {
               array401 = (array_t*)malloc(sizeof(array_t));
               array401->size = 848;
               array401->refC = 1;
               array401->id = 401;
               array401->data = (unsigned int*)malloc(array401->size*sizeof(unsigned int));
               memset(array401->data, 0, array401->size*sizeof(unsigned int));
               DEBUG_NEW(array401->id);
            }
            array401->refC--;
            if(array401->refC == 0) {
               free(array401->data);
               free(array401);
               DEBUG_FREE(array401->id);
            }
            array394->refC--;
            if(array394->refC == 0) {
               free(array394->data);
               free(array394);
               DEBUG_FREE(array394->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array374;
            params0.data[1] = array375;
            array_t* array402 = func17(&params0, rng(), loopsFactor);
            DEBUG_RETURN(array402->id);
            free(params0.data);
            for (int i = 0; i < array375->size; i++) {
               if (array375->data[i] == 22) { 
                  return array375;
               }
            }
            unsigned int loop74 = 0;
            unsigned int loopLimit74 = (rand()%loopsFactor)/5 + 1;
            for(; loop74 < loopLimit74; loop74++) {
               for (int i = 0; i < array374->size; i++) {
                  array374->data[i]--;
               }
               for (int i = 0; i < array374->size; i++) {
                  if (array374->data[i] == 21) { 
                     return array374;
                  }
               }
               if(PATH0 & 128) {
                  array_t* array403;
                  if (pCounter > 0) {
                     array403 = vars->data[--pCounter];
                     array403->refC++;
                     DEBUG_COPY(array403->id);
                  } else {
                     array403 = (array_t*)malloc(sizeof(array_t));
                     array403->size = 457;
                     array403->refC = 1;
                     array403->id = 403;
                     array403->data = (unsigned int*)malloc(array403->size*sizeof(unsigned int));
                     memset(array403->data, 0, array403->size*sizeof(unsigned int));
                     DEBUG_NEW(array403->id);
                  }
                  array_t_param params1;
                  params1.size = 4;
                  params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
                  params1.data[0] = array374;
                  params1.data[1] = array375;
                  params1.data[2] = array402;
                  params1.data[3] = array403;
                  array_t* array404 = func22(&params1, loopsFactor);
                  DEBUG_RETURN(array404->id);
                  free(params1.data);
                  array_t* array405;
                  if (pCounter > 0) {
                     array405 = vars->data[--pCounter];
                     array405->refC++;
                     DEBUG_COPY(array405->id);
                  } else {
                     array405 = (array_t*)malloc(sizeof(array_t));
                     array405->size = 171;
                     array405->refC = 1;
                     array405->id = 405;
                     array405->data = (unsigned int*)malloc(array405->size*sizeof(unsigned int));
                     memset(array405->data, 0, array405->size*sizeof(unsigned int));
                     DEBUG_NEW(array405->id);
                  }
                  array_t* array406;
                  if (pCounter > 0) {
                     array406 = vars->data[--pCounter];
                     array406->refC++;
                     DEBUG_COPY(array406->id);
                  } else {
                     array406 = (array_t*)malloc(sizeof(array_t));
                     array406->size = 776;
                     array406->refC = 1;
                     array406->id = 406;
                     array406->data = (unsigned int*)malloc(array406->size*sizeof(unsigned int));
                     memset(array406->data, 0, array406->size*sizeof(unsigned int));
                     DEBUG_NEW(array406->id);
                  }
                  array406->refC--;
                  if(array406->refC == 0) {
                     free(array406->data);
                     free(array406);
                     DEBUG_FREE(array406->id);
                  }
                  array405->refC--;
                  if(array405->refC == 0) {
                     free(array405->data);
                     free(array405);
                     DEBUG_FREE(array405->id);
                  }
                  array404->refC--;
                  if(array404->refC == 0) {
                     free(array404->data);
                     free(array404);
                     DEBUG_FREE(array404->id);
                  }
                  array403->refC--;
                  if(array403->refC == 0) {
                     free(array403->data);
                     free(array403);
                     DEBUG_FREE(array403->id);
                  }
               }
               else {
                  array_t_param params1;
                  params1.size = 3;
                  params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
                  params1.data[0] = array374;
                  params1.data[1] = array375;
                  params1.data[2] = array402;
                  array_t* array407 = func23(&params1, loopsFactor);
                  DEBUG_RETURN(array407->id);
                  free(params1.data);
                  array_t* array408;
                  if (pCounter > 0) {
                     array408 = vars->data[--pCounter];
                     array408->refC++;
                     DEBUG_COPY(array408->id);
                  } else {
                     array408 = (array_t*)malloc(sizeof(array_t));
                     array408->size = 701;
                     array408->refC = 1;
                     array408->id = 408;
                     array408->data = (unsigned int*)malloc(array408->size*sizeof(unsigned int));
                     memset(array408->data, 0, array408->size*sizeof(unsigned int));
                     DEBUG_NEW(array408->id);
                  }
                  array408->refC--;
                  if(array408->refC == 0) {
                     free(array408->data);
                     free(array408);
                     DEBUG_FREE(array408->id);
                  }
                  array407->refC--;
                  if(array407->refC == 0) {
                     free(array407->data);
                     free(array407);
                     DEBUG_FREE(array407->id);
                  }
               }
            }
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array374;
            params1.data[1] = array375;
            params1.data[2] = array402;
            array_t* array409 = func18(&params1, loopsFactor);
            DEBUG_RETURN(array409->id);
            free(params1.data);
            array_t* array410;
            if (pCounter > 0) {
               array410 = vars->data[--pCounter];
               array410->refC++;
               DEBUG_COPY(array410->id);
            } else {
               array410 = (array_t*)malloc(sizeof(array_t));
               array410->size = 933;
               array410->refC = 1;
               array410->id = 410;
               array410->data = (unsigned int*)malloc(array410->size*sizeof(unsigned int));
               memset(array410->data, 0, array410->size*sizeof(unsigned int));
               DEBUG_NEW(array410->id);
            }
            array_t* array411;
            if (pCounter > 0) {
               array411 = vars->data[--pCounter];
               array411->refC++;
               DEBUG_COPY(array411->id);
            } else {
               array411 = (array_t*)malloc(sizeof(array_t));
               array411->size = 907;
               array411->refC = 1;
               array411->id = 411;
               array411->data = (unsigned int*)malloc(array411->size*sizeof(unsigned int));
               memset(array411->data, 0, array411->size*sizeof(unsigned int));
               DEBUG_NEW(array411->id);
            }
            array411->refC--;
            if(array411->refC == 0) {
               free(array411->data);
               free(array411);
               DEBUG_FREE(array411->id);
            }
            array410->refC--;
            if(array410->refC == 0) {
               free(array410->data);
               free(array410);
               DEBUG_FREE(array410->id);
            }
            array409->refC--;
            if(array409->refC == 0) {
               free(array409->data);
               free(array409);
               DEBUG_FREE(array409->id);
            }
            array402->refC--;
            if(array402->refC == 0) {
               free(array402->data);
               free(array402);
               DEBUG_FREE(array402->id);
            }
         }
         for (int i = 0; i < array375->size; i++) {
            if (array375->data[i] == 28) { 
               return array375;
            }
         }
         array_t* array412;
         if (pCounter > 0) {
            array412 = vars->data[--pCounter];
            array412->refC++;
            DEBUG_COPY(array412->id);
         } else {
            array412 = (array_t*)malloc(sizeof(array_t));
            array412->size = 806;
            array412->refC = 1;
            array412->id = 412;
            array412->data = (unsigned int*)malloc(array412->size*sizeof(unsigned int));
            memset(array412->data, 0, array412->size*sizeof(unsigned int));
            DEBUG_NEW(array412->id);
         }
         array412->refC--;
         if(array412->refC == 0) {
            free(array412->data);
            free(array412);
            DEBUG_FREE(array412->id);
         }
         array375->refC--;
         if(array375->refC == 0) {
            free(array375->data);
            free(array375);
            DEBUG_FREE(array375->id);
         }
      }
   }
   return array374;
}

