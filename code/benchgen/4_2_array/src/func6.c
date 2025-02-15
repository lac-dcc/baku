#include "outs/4_2_array.h" 
array_t* func6(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array441;
   if (pCounter > 0) {
      array441 = vars->data[--pCounter];
      array441->refC++;
      DEBUG_COPY(array441->id);
   } else {
      array441 = (array_t*)malloc(sizeof(array_t));
      array441->size = 181;
      array441->refC = 1;
      array441->id = 441;
      array441->data = (unsigned int*)malloc(array441->size*sizeof(unsigned int));
      memset(array441->data, 0, array441->size*sizeof(unsigned int));
      DEBUG_NEW(array441->id);
   }
   unsigned int loop77 = 0;
   unsigned int loopLimit77 = (rand()%loopsFactor)/2 + 1;
   for(; loop77 < loopLimit77; loop77++) {
      for (int i = 0; i < array441->size; i++) {
         array441->data[i]--;
      }
      unsigned int loop78 = 0;
      unsigned int loopLimit78 = (rand()%loopsFactor)/3 + 1;
      for(; loop78 < loopLimit78; loop78++) {
         array_t* array442;
         if (pCounter > 0) {
            array442 = vars->data[--pCounter];
            array442->refC++;
            DEBUG_COPY(array442->id);
         } else {
            array442 = (array_t*)malloc(sizeof(array_t));
            array442->size = 603;
            array442->refC = 1;
            array442->id = 442;
            array442->data = (unsigned int*)malloc(array442->size*sizeof(unsigned int));
            memset(array442->data, 0, array442->size*sizeof(unsigned int));
            DEBUG_NEW(array442->id);
         }
         if(PATH0 & 1) {
            array_t* array443;
            if (pCounter > 0) {
               array443 = vars->data[--pCounter];
               array443->refC++;
               DEBUG_COPY(array443->id);
            } else {
               array443 = (array_t*)malloc(sizeof(array_t));
               array443->size = 720;
               array443->refC = 1;
               array443->id = 443;
               array443->data = (unsigned int*)malloc(array443->size*sizeof(unsigned int));
               memset(array443->data, 0, array443->size*sizeof(unsigned int));
               DEBUG_NEW(array443->id);
            }
            unsigned int loop79 = 0;
            unsigned int loopLimit79 = (rand()%loopsFactor)/4 + 1;
            for(; loop79 < loopLimit79; loop79++) {
               array_t* array444;
               if (pCounter > 0) {
                  array444 = vars->data[--pCounter];
                  array444->refC++;
                  DEBUG_COPY(array444->id);
               } else {
                  array444 = (array_t*)malloc(sizeof(array_t));
                  array444->size = 433;
                  array444->refC = 1;
                  array444->id = 444;
                  array444->data = (unsigned int*)malloc(array444->size*sizeof(unsigned int));
                  memset(array444->data, 0, array444->size*sizeof(unsigned int));
                  DEBUG_NEW(array444->id);
               }
               if(PATH0 & 2) {
               }
               else {
               }
               for (int i = 0; i < array443->size; i++) {
                  if (array443->data[i] == 81) { 
                     return array443;
                  }
               }
               array_t* array445;
               if (pCounter > 0) {
                  array445 = vars->data[--pCounter];
                  array445->refC++;
                  DEBUG_COPY(array445->id);
               } else {
                  array445 = (array_t*)malloc(sizeof(array_t));
                  array445->size = 487;
                  array445->refC = 1;
                  array445->id = 445;
                  array445->data = (unsigned int*)malloc(array445->size*sizeof(unsigned int));
                  memset(array445->data, 0, array445->size*sizeof(unsigned int));
                  DEBUG_NEW(array445->id);
               }
               array445->refC--;
               if(array445->refC == 0) {
                  free(array445->data);
                  free(array445);
                  DEBUG_FREE(array445->id);
               }
               array444->refC--;
               if(array444->refC == 0) {
                  free(array444->data);
                  free(array444);
                  DEBUG_FREE(array444->id);
               }
            }
            array_t_param params0;
            params0.size = 3;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array441;
            params0.data[1] = array442;
            params0.data[2] = array443;
            array_t* array446 = func12(&params0, loopsFactor);
            DEBUG_RETURN(array446->id);
            free(params0.data);
            array_t* array447;
            if (pCounter > 0) {
               array447 = vars->data[--pCounter];
               array447->refC++;
               DEBUG_COPY(array447->id);
            } else {
               array447 = (array_t*)malloc(sizeof(array_t));
               array447->size = 825;
               array447->refC = 1;
               array447->id = 447;
               array447->data = (unsigned int*)malloc(array447->size*sizeof(unsigned int));
               memset(array447->data, 0, array447->size*sizeof(unsigned int));
               DEBUG_NEW(array447->id);
            }
            array_t* array448;
            if (pCounter > 0) {
               array448 = vars->data[--pCounter];
               array448->refC++;
               DEBUG_COPY(array448->id);
            } else {
               array448 = (array_t*)malloc(sizeof(array_t));
               array448->size = 404;
               array448->refC = 1;
               array448->id = 448;
               array448->data = (unsigned int*)malloc(array448->size*sizeof(unsigned int));
               memset(array448->data, 0, array448->size*sizeof(unsigned int));
               DEBUG_NEW(array448->id);
            }
            unsigned int loop80 = 0;
            unsigned int loopLimit80 = (rand()%loopsFactor)/4 + 1;
            for(; loop80 < loopLimit80; loop80++) {
               for (int i = 0; i < array447->size; i++) {
                  array447->data[i]++;
               }
               for (int i = 0; i < array447->size; i++) {
                  if (array447->data[i] == 51) { 
                     return array447;
                  }
               }
               if(PATH0 & 4) {
                  array_t_param params1;
                  params1.size = 6;
                  params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
                  params1.data[0] = array441;
                  params1.data[1] = array442;
                  params1.data[2] = array443;
                  params1.data[3] = array446;
                  params1.data[4] = array447;
                  params1.data[5] = array448;
                  array_t* array449 = func19(&params1, loopsFactor);
                  DEBUG_RETURN(array449->id);
                  free(params1.data);
                  array_t* array450;
                  if (pCounter > 0) {
                     array450 = vars->data[--pCounter];
                     array450->refC++;
                     DEBUG_COPY(array450->id);
                  } else {
                     array450 = (array_t*)malloc(sizeof(array_t));
                     array450->size = 134;
                     array450->refC = 1;
                     array450->id = 450;
                     array450->data = (unsigned int*)malloc(array450->size*sizeof(unsigned int));
                     memset(array450->data, 0, array450->size*sizeof(unsigned int));
                     DEBUG_NEW(array450->id);
                  }
                  array450->refC--;
                  if(array450->refC == 0) {
                     free(array450->data);
                     free(array450);
                     DEBUG_FREE(array450->id);
                  }
                  array449->refC--;
                  if(array449->refC == 0) {
                     free(array449->data);
                     free(array449);
                     DEBUG_FREE(array449->id);
                  }
               }
               else {
               }
            }
            array_t* array451;
            if (pCounter > 0) {
               array451 = vars->data[--pCounter];
               array451->refC++;
               DEBUG_COPY(array451->id);
            } else {
               array451 = (array_t*)malloc(sizeof(array_t));
               array451->size = 181;
               array451->refC = 1;
               array451->id = 451;
               array451->data = (unsigned int*)malloc(array451->size*sizeof(unsigned int));
               memset(array451->data, 0, array451->size*sizeof(unsigned int));
               DEBUG_NEW(array451->id);
            }
            array_t* array452;
            if (pCounter > 0) {
               array452 = vars->data[--pCounter];
               array452->refC++;
               DEBUG_COPY(array452->id);
            } else {
               array452 = (array_t*)malloc(sizeof(array_t));
               array452->size = 506;
               array452->refC = 1;
               array452->id = 452;
               array452->data = (unsigned int*)malloc(array452->size*sizeof(unsigned int));
               memset(array452->data, 0, array452->size*sizeof(unsigned int));
               DEBUG_NEW(array452->id);
            }
            array452->refC--;
            if(array452->refC == 0) {
               free(array452->data);
               free(array452);
               DEBUG_FREE(array452->id);
            }
            array451->refC--;
            if(array451->refC == 0) {
               free(array451->data);
               free(array451);
               DEBUG_FREE(array451->id);
            }
            array448->refC--;
            if(array448->refC == 0) {
               free(array448->data);
               free(array448);
               DEBUG_FREE(array448->id);
            }
            array447->refC--;
            if(array447->refC == 0) {
               free(array447->data);
               free(array447);
               DEBUG_FREE(array447->id);
            }
            array446->refC--;
            if(array446->refC == 0) {
               free(array446->data);
               free(array446);
               DEBUG_FREE(array446->id);
            }
            array443->refC--;
            if(array443->refC == 0) {
               free(array443->data);
               free(array443);
               DEBUG_FREE(array443->id);
            }
         }
         else {
            if(PATH0 & 8) {
               array_t* array453;
               if (pCounter > 0) {
                  array453 = vars->data[--pCounter];
                  array453->refC++;
                  DEBUG_COPY(array453->id);
               } else {
                  array453 = (array_t*)malloc(sizeof(array_t));
                  array453->size = 415;
                  array453->refC = 1;
                  array453->id = 453;
                  array453->data = (unsigned int*)malloc(array453->size*sizeof(unsigned int));
                  memset(array453->data, 0, array453->size*sizeof(unsigned int));
                  DEBUG_NEW(array453->id);
               }
               array_t_param params0;
               params0.size = 3;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array441;
               params0.data[1] = array442;
               params0.data[2] = array453;
               array_t* array454 = func20(&params0, loopsFactor);
               DEBUG_RETURN(array454->id);
               free(params0.data);
               array_t* array455;
               if (pCounter > 0) {
                  array455 = vars->data[--pCounter];
                  array455->refC++;
                  DEBUG_COPY(array455->id);
               } else {
                  array455 = (array_t*)malloc(sizeof(array_t));
                  array455->size = 595;
                  array455->refC = 1;
                  array455->id = 455;
                  array455->data = (unsigned int*)malloc(array455->size*sizeof(unsigned int));
                  memset(array455->data, 0, array455->size*sizeof(unsigned int));
                  DEBUG_NEW(array455->id);
               }
               array_t* array456;
               if (pCounter > 0) {
                  array456 = vars->data[--pCounter];
                  array456->refC++;
                  DEBUG_COPY(array456->id);
               } else {
                  array456 = (array_t*)malloc(sizeof(array_t));
                  array456->size = 999;
                  array456->refC = 1;
                  array456->id = 456;
                  array456->data = (unsigned int*)malloc(array456->size*sizeof(unsigned int));
                  memset(array456->data, 0, array456->size*sizeof(unsigned int));
                  DEBUG_NEW(array456->id);
               }
               array456->refC--;
               if(array456->refC == 0) {
                  free(array456->data);
                  free(array456);
                  DEBUG_FREE(array456->id);
               }
               array455->refC--;
               if(array455->refC == 0) {
                  free(array455->data);
                  free(array455);
                  DEBUG_FREE(array455->id);
               }
               array454->refC--;
               if(array454->refC == 0) {
                  free(array454->data);
                  free(array454);
                  DEBUG_FREE(array454->id);
               }
               array453->refC--;
               if(array453->refC == 0) {
                  free(array453->data);
                  free(array453);
                  DEBUG_FREE(array453->id);
               }
            }
            else {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array441;
               params0.data[1] = array442;
               array_t* array457 = func21(&params0, loopsFactor);
               DEBUG_RETURN(array457->id);
               free(params0.data);
               array_t* array458;
               if (pCounter > 0) {
                  array458 = vars->data[--pCounter];
                  array458->refC++;
                  DEBUG_COPY(array458->id);
               } else {
                  array458 = (array_t*)malloc(sizeof(array_t));
                  array458->size = 483;
                  array458->refC = 1;
                  array458->id = 458;
                  array458->data = (unsigned int*)malloc(array458->size*sizeof(unsigned int));
                  memset(array458->data, 0, array458->size*sizeof(unsigned int));
                  DEBUG_NEW(array458->id);
               }
               array458->refC--;
               if(array458->refC == 0) {
                  free(array458->data);
                  free(array458);
                  DEBUG_FREE(array458->id);
               }
               array457->refC--;
               if(array457->refC == 0) {
                  free(array457->data);
                  free(array457);
                  DEBUG_FREE(array457->id);
               }
            }
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array441;
            params0.data[1] = array442;
            array_t* array459 = func13(&params0, rng(), loopsFactor);
            DEBUG_RETURN(array459->id);
            free(params0.data);
            array_t* array460;
            if (pCounter > 0) {
               array460 = vars->data[--pCounter];
               array460->refC++;
               DEBUG_COPY(array460->id);
            } else {
               array460 = (array_t*)malloc(sizeof(array_t));
               array460->size = 977;
               array460->refC = 1;
               array460->id = 460;
               array460->data = (unsigned int*)malloc(array460->size*sizeof(unsigned int));
               memset(array460->data, 0, array460->size*sizeof(unsigned int));
               DEBUG_NEW(array460->id);
            }
            array460->refC--;
            if(array460->refC == 0) {
               free(array460->data);
               free(array460);
               DEBUG_FREE(array460->id);
            }
            array459->refC--;
            if(array459->refC == 0) {
               free(array459->data);
               free(array459);
               DEBUG_FREE(array459->id);
            }
         }
         if(PATH0 & 16) {
            array_t* array461;
            if (pCounter > 0) {
               array461 = vars->data[--pCounter];
               array461->refC++;
               DEBUG_COPY(array461->id);
            } else {
               array461 = (array_t*)malloc(sizeof(array_t));
               array461->size = 309;
               array461->refC = 1;
               array461->id = 461;
               array461->data = (unsigned int*)malloc(array461->size*sizeof(unsigned int));
               memset(array461->data, 0, array461->size*sizeof(unsigned int));
               DEBUG_NEW(array461->id);
            }
            unsigned int loop81 = 0;
            unsigned int loopLimit81 = (rand()%loopsFactor)/4 + 1;
            for(; loop81 < loopLimit81; loop81++) {
               for (int i = 0; i < array441->size; i++) {
                  array441->data[i]++;
               }
               for (int i = 0; i < array441->size; i++) {
                  if (array441->data[i] == 82) { 
                     return array441;
                  }
               }
               if(PATH0 & 32) {
                  array_t_param params0;
                  params0.size = 3;
                  params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                  params0.data[0] = array441;
                  params0.data[1] = array442;
                  params0.data[2] = array461;
                  array_t* array462 = func14(&params0, rng(), loopsFactor);
                  DEBUG_RETURN(array462->id);
                  free(params0.data);
                  array_t* array463;
                  if (pCounter > 0) {
                     array463 = vars->data[--pCounter];
                     array463->refC++;
                     DEBUG_COPY(array463->id);
                  } else {
                     array463 = (array_t*)malloc(sizeof(array_t));
                     array463->size = 563;
                     array463->refC = 1;
                     array463->id = 463;
                     array463->data = (unsigned int*)malloc(array463->size*sizeof(unsigned int));
                     memset(array463->data, 0, array463->size*sizeof(unsigned int));
                     DEBUG_NEW(array463->id);
                  }
                  array463->refC--;
                  if(array463->refC == 0) {
                     free(array463->data);
                     free(array463);
                     DEBUG_FREE(array463->id);
                  }
                  array462->refC--;
                  if(array462->refC == 0) {
                     free(array462->data);
                     free(array462);
                     DEBUG_FREE(array462->id);
                  }
               }
               else {
                  array_t* array464;
                  if (pCounter > 0) {
                     array464 = vars->data[--pCounter];
                     array464->refC++;
                     DEBUG_COPY(array464->id);
                  } else {
                     array464 = (array_t*)malloc(sizeof(array_t));
                     array464->size = 860;
                     array464->refC = 1;
                     array464->id = 464;
                     array464->data = (unsigned int*)malloc(array464->size*sizeof(unsigned int));
                     memset(array464->data, 0, array464->size*sizeof(unsigned int));
                     DEBUG_NEW(array464->id);
                  }
                  unsigned int loop82 = 0;
                  unsigned int loopLimit82 = (rand()%loopsFactor)/5 + 1;
                  for(; loop82 < loopLimit82; loop82++) {
                     for (int i = 0; i < array461->size; i++) {
                        array461->data[i]++;
                     }
                     for (int i = 0; i < array464->size; i++) {
                        if (array464->data[i] == 85) { 
                           return array464;
                        }
                     }
                     if(PATH0 & 64) {
                        array_t_param params0;
                        params0.size = 4;
                        params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                        params0.data[0] = array441;
                        params0.data[1] = array442;
                        params0.data[2] = array461;
                        params0.data[3] = array464;
                        array_t* array465 = func19(&params0, loopsFactor);
                        DEBUG_RETURN(array465->id);
                        free(params0.data);
                        array_t* array466;
                        if (pCounter > 0) {
                           array466 = vars->data[--pCounter];
                           array466->refC++;
                           DEBUG_COPY(array466->id);
                        } else {
                           array466 = (array_t*)malloc(sizeof(array_t));
                           array466->size = 930;
                           array466->refC = 1;
                           array466->id = 466;
                           array466->data = (unsigned int*)malloc(array466->size*sizeof(unsigned int));
                           memset(array466->data, 0, array466->size*sizeof(unsigned int));
                           DEBUG_NEW(array466->id);
                        }
                        array466->refC--;
                        if(array466->refC == 0) {
                           free(array466->data);
                           free(array466);
                           DEBUG_FREE(array466->id);
                        }
                        array465->refC--;
                        if(array465->refC == 0) {
                           free(array465->data);
                           free(array465);
                           DEBUG_FREE(array465->id);
                        }
                     }
                     else {
                     }
                  }
                  array_t* array467;
                  if (pCounter > 0) {
                     array467 = vars->data[--pCounter];
                     array467->refC++;
                     DEBUG_COPY(array467->id);
                  } else {
                     array467 = (array_t*)malloc(sizeof(array_t));
                     array467->size = 990;
                     array467->refC = 1;
                     array467->id = 467;
                     array467->data = (unsigned int*)malloc(array467->size*sizeof(unsigned int));
                     memset(array467->data, 0, array467->size*sizeof(unsigned int));
                     DEBUG_NEW(array467->id);
                  }
                  array467->refC--;
                  if(array467->refC == 0) {
                     free(array467->data);
                     free(array467);
                     DEBUG_FREE(array467->id);
                  }
                  array464->refC--;
                  if(array464->refC == 0) {
                     free(array464->data);
                     free(array464);
                     DEBUG_FREE(array464->id);
                  }
               }
            }
            array_t* array468;
            if (pCounter > 0) {
               array468 = vars->data[--pCounter];
               array468->refC++;
               DEBUG_COPY(array468->id);
            } else {
               array468 = (array_t*)malloc(sizeof(array_t));
               array468->size = 583;
               array468->refC = 1;
               array468->id = 468;
               array468->data = (unsigned int*)malloc(array468->size*sizeof(unsigned int));
               memset(array468->data, 0, array468->size*sizeof(unsigned int));
               DEBUG_NEW(array468->id);
            }
            array468->refC--;
            if(array468->refC == 0) {
               free(array468->data);
               free(array468);
               DEBUG_FREE(array468->id);
            }
            array461->refC--;
            if(array461->refC == 0) {
               free(array461->data);
               free(array461);
               DEBUG_FREE(array461->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array441;
            params0.data[1] = array442;
            array_t* array469 = func15(&params0, rng(), loopsFactor);
            DEBUG_RETURN(array469->id);
            free(params0.data);
            for (int i = 0; i < array442->size; i++) {
               if (array442->data[i] == 20) { 
                  return array442;
               }
            }
            unsigned int loop83 = 0;
            unsigned int loopLimit83 = (rand()%loopsFactor)/4 + 1;
            for(; loop83 < loopLimit83; loop83++) {
               for (int i = 0; i < array441->size; i++) {
                  array441->data[i]--;
               }
               for (int i = 0; i < array441->size; i++) {
                  if (array441->data[i] == 28) { 
                     return array441;
                  }
               }
               if(PATH0 & 128) {
                  array_t* array470;
                  if (pCounter > 0) {
                     array470 = vars->data[--pCounter];
                     array470->refC++;
                     DEBUG_COPY(array470->id);
                  } else {
                     array470 = (array_t*)malloc(sizeof(array_t));
                     array470->size = 839;
                     array470->refC = 1;
                     array470->id = 470;
                     array470->data = (unsigned int*)malloc(array470->size*sizeof(unsigned int));
                     memset(array470->data, 0, array470->size*sizeof(unsigned int));
                     DEBUG_NEW(array470->id);
                  }
                  array_t_param params1;
                  params1.size = 4;
                  params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
                  params1.data[0] = array441;
                  params1.data[1] = array442;
                  params1.data[2] = array469;
                  params1.data[3] = array470;
                  array_t* array471 = func20(&params1, loopsFactor);
                  DEBUG_RETURN(array471->id);
                  free(params1.data);
                  array_t* array472;
                  if (pCounter > 0) {
                     array472 = vars->data[--pCounter];
                     array472->refC++;
                     DEBUG_COPY(array472->id);
                  } else {
                     array472 = (array_t*)malloc(sizeof(array_t));
                     array472->size = 136;
                     array472->refC = 1;
                     array472->id = 472;
                     array472->data = (unsigned int*)malloc(array472->size*sizeof(unsigned int));
                     memset(array472->data, 0, array472->size*sizeof(unsigned int));
                     DEBUG_NEW(array472->id);
                  }
                  array_t* array473;
                  if (pCounter > 0) {
                     array473 = vars->data[--pCounter];
                     array473->refC++;
                     DEBUG_COPY(array473->id);
                  } else {
                     array473 = (array_t*)malloc(sizeof(array_t));
                     array473->size = 360;
                     array473->refC = 1;
                     array473->id = 473;
                     array473->data = (unsigned int*)malloc(array473->size*sizeof(unsigned int));
                     memset(array473->data, 0, array473->size*sizeof(unsigned int));
                     DEBUG_NEW(array473->id);
                  }
                  array473->refC--;
                  if(array473->refC == 0) {
                     free(array473->data);
                     free(array473);
                     DEBUG_FREE(array473->id);
                  }
                  array472->refC--;
                  if(array472->refC == 0) {
                     free(array472->data);
                     free(array472);
                     DEBUG_FREE(array472->id);
                  }
                  array471->refC--;
                  if(array471->refC == 0) {
                     free(array471->data);
                     free(array471);
                     DEBUG_FREE(array471->id);
                  }
                  array470->refC--;
                  if(array470->refC == 0) {
                     free(array470->data);
                     free(array470);
                     DEBUG_FREE(array470->id);
                  }
               }
               else {
                  array_t_param params1;
                  params1.size = 3;
                  params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
                  params1.data[0] = array441;
                  params1.data[1] = array442;
                  params1.data[2] = array469;
                  array_t* array474 = func21(&params1, loopsFactor);
                  DEBUG_RETURN(array474->id);
                  free(params1.data);
                  array_t* array475;
                  if (pCounter > 0) {
                     array475 = vars->data[--pCounter];
                     array475->refC++;
                     DEBUG_COPY(array475->id);
                  } else {
                     array475 = (array_t*)malloc(sizeof(array_t));
                     array475->size = 337;
                     array475->refC = 1;
                     array475->id = 475;
                     array475->data = (unsigned int*)malloc(array475->size*sizeof(unsigned int));
                     memset(array475->data, 0, array475->size*sizeof(unsigned int));
                     DEBUG_NEW(array475->id);
                  }
                  array475->refC--;
                  if(array475->refC == 0) {
                     free(array475->data);
                     free(array475);
                     DEBUG_FREE(array475->id);
                  }
                  array474->refC--;
                  if(array474->refC == 0) {
                     free(array474->data);
                     free(array474);
                     DEBUG_FREE(array474->id);
                  }
               }
            }
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array441;
            params1.data[1] = array442;
            params1.data[2] = array469;
            array_t* array476 = func16(&params1, loopsFactor);
            DEBUG_RETURN(array476->id);
            free(params1.data);
            array_t* array477;
            if (pCounter > 0) {
               array477 = vars->data[--pCounter];
               array477->refC++;
               DEBUG_COPY(array477->id);
            } else {
               array477 = (array_t*)malloc(sizeof(array_t));
               array477->size = 621;
               array477->refC = 1;
               array477->id = 477;
               array477->data = (unsigned int*)malloc(array477->size*sizeof(unsigned int));
               memset(array477->data, 0, array477->size*sizeof(unsigned int));
               DEBUG_NEW(array477->id);
            }
            array_t* array478;
            if (pCounter > 0) {
               array478 = vars->data[--pCounter];
               array478->refC++;
               DEBUG_COPY(array478->id);
            } else {
               array478 = (array_t*)malloc(sizeof(array_t));
               array478->size = 310;
               array478->refC = 1;
               array478->id = 478;
               array478->data = (unsigned int*)malloc(array478->size*sizeof(unsigned int));
               memset(array478->data, 0, array478->size*sizeof(unsigned int));
               DEBUG_NEW(array478->id);
            }
            array478->refC--;
            if(array478->refC == 0) {
               free(array478->data);
               free(array478);
               DEBUG_FREE(array478->id);
            }
            array477->refC--;
            if(array477->refC == 0) {
               free(array477->data);
               free(array477);
               DEBUG_FREE(array477->id);
            }
            array476->refC--;
            if(array476->refC == 0) {
               free(array476->data);
               free(array476);
               DEBUG_FREE(array476->id);
            }
            array469->refC--;
            if(array469->refC == 0) {
               free(array469->data);
               free(array469);
               DEBUG_FREE(array469->id);
            }
         }
         for (int i = 0; i < array442->size; i++) {
            if (array442->data[i] == 88) { 
               return array442;
            }
         }
         array_t* array479;
         if (pCounter > 0) {
            array479 = vars->data[--pCounter];
            array479->refC++;
            DEBUG_COPY(array479->id);
         } else {
            array479 = (array_t*)malloc(sizeof(array_t));
            array479->size = 225;
            array479->refC = 1;
            array479->id = 479;
            array479->data = (unsigned int*)malloc(array479->size*sizeof(unsigned int));
            memset(array479->data, 0, array479->size*sizeof(unsigned int));
            DEBUG_NEW(array479->id);
         }
         array479->refC--;
         if(array479->refC == 0) {
            free(array479->data);
            free(array479);
            DEBUG_FREE(array479->id);
         }
         array442->refC--;
         if(array442->refC == 0) {
            free(array442->data);
            free(array442);
            DEBUG_FREE(array442->id);
         }
      }
   }
   return array441;
}

