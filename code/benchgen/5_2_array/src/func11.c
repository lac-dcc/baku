#include "outs/5_2_array.h" 
array_t* func11(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array478;
   if (pCounter > 0) {
      array478 = vars->data[--pCounter];
      array478->refC++;
      DEBUG_COPY(array478->id);
   } else {
      array478 = (array_t*)malloc(sizeof(array_t));
      array478->size = 269;
      array478->refC = 1;
      array478->id = 478;
      array478->data = (unsigned int*)malloc(array478->size*sizeof(unsigned int));
      memset(array478->data, 0, array478->size*sizeof(unsigned int));
      DEBUG_NEW(array478->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array478;
   array_t* array479 = func15(&params0, rng(), loopsFactor);
   DEBUG_RETURN(array479->id);
   free(params0.data);
   for (int i = 0; i < array479->size; i++) {
      if (array479->data[i] == 10) { 
         return array479;
      }
   }
   unsigned int loop86 = 0;
   unsigned int loopLimit86 = (rand()%loopsFactor)/2 + 1;
   for(; loop86 < loopLimit86; loop86++) {
      for (int i = 0; i < array478->size; i++) {
         array478->data[i]--;
      }
      for (int i = 0; i < array479->size; i++) {
         if (array479->data[i] == 98) { 
            return array479;
         }
      }
      if(PATH0 & 1) {
         array_t* array480;
         if (pCounter > 0) {
            array480 = vars->data[--pCounter];
            array480->refC++;
            DEBUG_COPY(array480->id);
         } else {
            array480 = (array_t*)malloc(sizeof(array_t));
            array480->size = 888;
            array480->refC = 1;
            array480->id = 480;
            array480->data = (unsigned int*)malloc(array480->size*sizeof(unsigned int));
            memset(array480->data, 0, array480->size*sizeof(unsigned int));
            DEBUG_NEW(array480->id);
         }
         unsigned int loop87 = 0;
         unsigned int loopLimit87 = (rand()%loopsFactor)/3 + 1;
         for(; loop87 < loopLimit87; loop87++) {
            array_t* array481;
            if (pCounter > 0) {
               array481 = vars->data[--pCounter];
               array481->refC++;
               DEBUG_COPY(array481->id);
            } else {
               array481 = (array_t*)malloc(sizeof(array_t));
               array481->size = 610;
               array481->refC = 1;
               array481->id = 481;
               array481->data = (unsigned int*)malloc(array481->size*sizeof(unsigned int));
               memset(array481->data, 0, array481->size*sizeof(unsigned int));
               DEBUG_NEW(array481->id);
            }
            if(PATH0 & 2) {
            }
            else {
            }
            for (int i = 0; i < array479->size; i++) {
               if (array479->data[i] == 77) { 
                  return array479;
               }
            }
            array_t* array482;
            if (pCounter > 0) {
               array482 = vars->data[--pCounter];
               array482->refC++;
               DEBUG_COPY(array482->id);
            } else {
               array482 = (array_t*)malloc(sizeof(array_t));
               array482->size = 890;
               array482->refC = 1;
               array482->id = 482;
               array482->data = (unsigned int*)malloc(array482->size*sizeof(unsigned int));
               memset(array482->data, 0, array482->size*sizeof(unsigned int));
               DEBUG_NEW(array482->id);
            }
            array482->refC--;
            if(array482->refC == 0) {
               free(array482->data);
               free(array482);
               DEBUG_FREE(array482->id);
            }
            array481->refC--;
            if(array481->refC == 0) {
               free(array481->data);
               free(array481);
               DEBUG_FREE(array481->id);
            }
         }
         array_t_param params1;
         params1.size = 3;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array478;
         params1.data[1] = array479;
         params1.data[2] = array480;
         array_t* array483 = func20(&params1, loopsFactor);
         DEBUG_RETURN(array483->id);
         free(params1.data);
         array_t* array484;
         if (pCounter > 0) {
            array484 = vars->data[--pCounter];
            array484->refC++;
            DEBUG_COPY(array484->id);
         } else {
            array484 = (array_t*)malloc(sizeof(array_t));
            array484->size = 552;
            array484->refC = 1;
            array484->id = 484;
            array484->data = (unsigned int*)malloc(array484->size*sizeof(unsigned int));
            memset(array484->data, 0, array484->size*sizeof(unsigned int));
            DEBUG_NEW(array484->id);
         }
         array_t* array485;
         if (pCounter > 0) {
            array485 = vars->data[--pCounter];
            array485->refC++;
            DEBUG_COPY(array485->id);
         } else {
            array485 = (array_t*)malloc(sizeof(array_t));
            array485->size = 931;
            array485->refC = 1;
            array485->id = 485;
            array485->data = (unsigned int*)malloc(array485->size*sizeof(unsigned int));
            memset(array485->data, 0, array485->size*sizeof(unsigned int));
            DEBUG_NEW(array485->id);
         }
         unsigned int loop88 = 0;
         unsigned int loopLimit88 = (rand()%loopsFactor)/3 + 1;
         for(; loop88 < loopLimit88; loop88++) {
            for (int i = 0; i < array485->size; i++) {
               array485->data[i]++;
            }
            for (int i = 0; i < array483->size; i++) {
               if (array483->data[i] == 99) { 
                  return array483;
               }
            }
            if(PATH0 & 4) {
               array_t_param params2;
               params2.size = 6;
               params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
               params2.data[0] = array478;
               params2.data[1] = array479;
               params2.data[2] = array480;
               params2.data[3] = array483;
               params2.data[4] = array484;
               params2.data[5] = array485;
               array_t* array486 = func24(&params2, loopsFactor);
               DEBUG_RETURN(array486->id);
               free(params2.data);
               array_t* array487;
               if (pCounter > 0) {
                  array487 = vars->data[--pCounter];
                  array487->refC++;
                  DEBUG_COPY(array487->id);
               } else {
                  array487 = (array_t*)malloc(sizeof(array_t));
                  array487->size = 952;
                  array487->refC = 1;
                  array487->id = 487;
                  array487->data = (unsigned int*)malloc(array487->size*sizeof(unsigned int));
                  memset(array487->data, 0, array487->size*sizeof(unsigned int));
                  DEBUG_NEW(array487->id);
               }
               array487->refC--;
               if(array487->refC == 0) {
                  free(array487->data);
                  free(array487);
                  DEBUG_FREE(array487->id);
               }
               array486->refC--;
               if(array486->refC == 0) {
                  free(array486->data);
                  free(array486);
                  DEBUG_FREE(array486->id);
               }
            }
            else {
            }
         }
         array_t* array488;
         if (pCounter > 0) {
            array488 = vars->data[--pCounter];
            array488->refC++;
            DEBUG_COPY(array488->id);
         } else {
            array488 = (array_t*)malloc(sizeof(array_t));
            array488->size = 17;
            array488->refC = 1;
            array488->id = 488;
            array488->data = (unsigned int*)malloc(array488->size*sizeof(unsigned int));
            memset(array488->data, 0, array488->size*sizeof(unsigned int));
            DEBUG_NEW(array488->id);
         }
         array_t* array489;
         if (pCounter > 0) {
            array489 = vars->data[--pCounter];
            array489->refC++;
            DEBUG_COPY(array489->id);
         } else {
            array489 = (array_t*)malloc(sizeof(array_t));
            array489->size = 641;
            array489->refC = 1;
            array489->id = 489;
            array489->data = (unsigned int*)malloc(array489->size*sizeof(unsigned int));
            memset(array489->data, 0, array489->size*sizeof(unsigned int));
            DEBUG_NEW(array489->id);
         }
         array489->refC--;
         if(array489->refC == 0) {
            free(array489->data);
            free(array489);
            DEBUG_FREE(array489->id);
         }
         array488->refC--;
         if(array488->refC == 0) {
            free(array488->data);
            free(array488);
            DEBUG_FREE(array488->id);
         }
         array485->refC--;
         if(array485->refC == 0) {
            free(array485->data);
            free(array485);
            DEBUG_FREE(array485->id);
         }
         array484->refC--;
         if(array484->refC == 0) {
            free(array484->data);
            free(array484);
            DEBUG_FREE(array484->id);
         }
         array483->refC--;
         if(array483->refC == 0) {
            free(array483->data);
            free(array483);
            DEBUG_FREE(array483->id);
         }
         array480->refC--;
         if(array480->refC == 0) {
            free(array480->data);
            free(array480);
            DEBUG_FREE(array480->id);
         }
      }
      else {
         if(PATH0 & 8) {
            array_t* array490;
            if (pCounter > 0) {
               array490 = vars->data[--pCounter];
               array490->refC++;
               DEBUG_COPY(array490->id);
            } else {
               array490 = (array_t*)malloc(sizeof(array_t));
               array490->size = 735;
               array490->refC = 1;
               array490->id = 490;
               array490->data = (unsigned int*)malloc(array490->size*sizeof(unsigned int));
               memset(array490->data, 0, array490->size*sizeof(unsigned int));
               DEBUG_NEW(array490->id);
            }
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array478;
            params1.data[1] = array479;
            params1.data[2] = array490;
            array_t* array491 = func22(&params1, loopsFactor);
            DEBUG_RETURN(array491->id);
            free(params1.data);
            array_t* array492;
            if (pCounter > 0) {
               array492 = vars->data[--pCounter];
               array492->refC++;
               DEBUG_COPY(array492->id);
            } else {
               array492 = (array_t*)malloc(sizeof(array_t));
               array492->size = 184;
               array492->refC = 1;
               array492->id = 492;
               array492->data = (unsigned int*)malloc(array492->size*sizeof(unsigned int));
               memset(array492->data, 0, array492->size*sizeof(unsigned int));
               DEBUG_NEW(array492->id);
            }
            array_t* array493;
            if (pCounter > 0) {
               array493 = vars->data[--pCounter];
               array493->refC++;
               DEBUG_COPY(array493->id);
            } else {
               array493 = (array_t*)malloc(sizeof(array_t));
               array493->size = 195;
               array493->refC = 1;
               array493->id = 493;
               array493->data = (unsigned int*)malloc(array493->size*sizeof(unsigned int));
               memset(array493->data, 0, array493->size*sizeof(unsigned int));
               DEBUG_NEW(array493->id);
            }
            array493->refC--;
            if(array493->refC == 0) {
               free(array493->data);
               free(array493);
               DEBUG_FREE(array493->id);
            }
            array492->refC--;
            if(array492->refC == 0) {
               free(array492->data);
               free(array492);
               DEBUG_FREE(array492->id);
            }
            array491->refC--;
            if(array491->refC == 0) {
               free(array491->data);
               free(array491);
               DEBUG_FREE(array491->id);
            }
            array490->refC--;
            if(array490->refC == 0) {
               free(array490->data);
               free(array490);
               DEBUG_FREE(array490->id);
            }
         }
         else {
            array_t_param params1;
            params1.size = 2;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array478;
            params1.data[1] = array479;
            array_t* array494 = func23(&params1, loopsFactor);
            DEBUG_RETURN(array494->id);
            free(params1.data);
            array_t* array495;
            if (pCounter > 0) {
               array495 = vars->data[--pCounter];
               array495->refC++;
               DEBUG_COPY(array495->id);
            } else {
               array495 = (array_t*)malloc(sizeof(array_t));
               array495->size = 266;
               array495->refC = 1;
               array495->id = 495;
               array495->data = (unsigned int*)malloc(array495->size*sizeof(unsigned int));
               memset(array495->data, 0, array495->size*sizeof(unsigned int));
               DEBUG_NEW(array495->id);
            }
            array495->refC--;
            if(array495->refC == 0) {
               free(array495->data);
               free(array495);
               DEBUG_FREE(array495->id);
            }
            array494->refC--;
            if(array494->refC == 0) {
               free(array494->data);
               free(array494);
               DEBUG_FREE(array494->id);
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array478;
         params1.data[1] = array479;
         array_t* array496 = func21(&params1, rng(), loopsFactor);
         DEBUG_RETURN(array496->id);
         free(params1.data);
         array_t* array497;
         if (pCounter > 0) {
            array497 = vars->data[--pCounter];
            array497->refC++;
            DEBUG_COPY(array497->id);
         } else {
            array497 = (array_t*)malloc(sizeof(array_t));
            array497->size = 528;
            array497->refC = 1;
            array497->id = 497;
            array497->data = (unsigned int*)malloc(array497->size*sizeof(unsigned int));
            memset(array497->data, 0, array497->size*sizeof(unsigned int));
            DEBUG_NEW(array497->id);
         }
         array497->refC--;
         if(array497->refC == 0) {
            free(array497->data);
            free(array497);
            DEBUG_FREE(array497->id);
         }
         array496->refC--;
         if(array496->refC == 0) {
            free(array496->data);
            free(array496);
            DEBUG_FREE(array496->id);
         }
      }
   }
   array_t_param params1;
   params1.size = 2;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array478;
   params1.data[1] = array479;
   array_t* array498 = func16(&params1, rng(), loopsFactor);
   DEBUG_RETURN(array498->id);
   free(params1.data);
   array_t* array499;
   if (pCounter > 0) {
      array499 = vars->data[--pCounter];
      array499->refC++;
      DEBUG_COPY(array499->id);
   } else {
      array499 = (array_t*)malloc(sizeof(array_t));
      array499->size = 278;
      array499->refC = 1;
      array499->id = 499;
      array499->data = (unsigned int*)malloc(array499->size*sizeof(unsigned int));
      memset(array499->data, 0, array499->size*sizeof(unsigned int));
      DEBUG_NEW(array499->id);
   }
   array_t* array500;
   if (pCounter > 0) {
      array500 = vars->data[--pCounter];
      array500->refC++;
      DEBUG_COPY(array500->id);
   } else {
      array500 = (array_t*)malloc(sizeof(array_t));
      array500->size = 197;
      array500->refC = 1;
      array500->id = 500;
      array500->data = (unsigned int*)malloc(array500->size*sizeof(unsigned int));
      memset(array500->data, 0, array500->size*sizeof(unsigned int));
      DEBUG_NEW(array500->id);
   }
   array500->refC--;
   if(array500->refC == 0) {
      free(array500->data);
      free(array500);
      DEBUG_FREE(array500->id);
   }
   array499->refC--;
   if(array499->refC == 0) {
      free(array499->data);
      free(array499);
      DEBUG_FREE(array499->id);
   }
   array498->refC--;
   if(array498->refC == 0) {
      free(array498->data);
      free(array498);
      DEBUG_FREE(array498->id);
   }
   array479->refC--;
   if(array479->refC == 0) {
      free(array479->data);
      free(array479);
      DEBUG_FREE(array479->id);
   }
   return array478;
}

