#include "outs/5_2_array.h" 
array_t* func7(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop34 = 0;
   unsigned int loopLimit34 = (rand()%loopsFactor)/3 + 1;
   for(; loop34 < loopLimit34; loop34++) {
      array_t* array178;
      if (pCounter > 0) {
         array178 = vars->data[--pCounter];
         array178->refC++;
         DEBUG_COPY(array178->id);
      } else {
         array178 = (array_t*)malloc(sizeof(array_t));
         array178->size = 961;
         array178->refC = 1;
         array178->id = 178;
         array178->data = (unsigned int*)malloc(array178->size*sizeof(unsigned int));
         memset(array178->data, 0, array178->size*sizeof(unsigned int));
         DEBUG_NEW(array178->id);
      }
      if(PATH0 & 1) {
         array_t* array179;
         if (pCounter > 0) {
            array179 = vars->data[--pCounter];
            array179->refC++;
            DEBUG_COPY(array179->id);
         } else {
            array179 = (array_t*)malloc(sizeof(array_t));
            array179->size = 754;
            array179->refC = 1;
            array179->id = 179;
            array179->data = (unsigned int*)malloc(array179->size*sizeof(unsigned int));
            memset(array179->data, 0, array179->size*sizeof(unsigned int));
            DEBUG_NEW(array179->id);
         }
         unsigned int loop35 = 0;
         unsigned int loopLimit35 = (rand()%loopsFactor)/4 + 1;
         for(; loop35 < loopLimit35; loop35++) {
            array_t* array180;
            if (pCounter > 0) {
               array180 = vars->data[--pCounter];
               array180->refC++;
               DEBUG_COPY(array180->id);
            } else {
               array180 = (array_t*)malloc(sizeof(array_t));
               array180->size = 326;
               array180->refC = 1;
               array180->id = 180;
               array180->data = (unsigned int*)malloc(array180->size*sizeof(unsigned int));
               memset(array180->data, 0, array180->size*sizeof(unsigned int));
               DEBUG_NEW(array180->id);
            }
            if(PATH0 & 2) {
            }
            else {
            }
            for (int i = 0; i < array178->size; i++) {
               if (array178->data[i] == 44) { 
                  return array178;
               }
            }
            array_t* array181;
            if (pCounter > 0) {
               array181 = vars->data[--pCounter];
               array181->refC++;
               DEBUG_COPY(array181->id);
            } else {
               array181 = (array_t*)malloc(sizeof(array_t));
               array181->size = 202;
               array181->refC = 1;
               array181->id = 181;
               array181->data = (unsigned int*)malloc(array181->size*sizeof(unsigned int));
               memset(array181->data, 0, array181->size*sizeof(unsigned int));
               DEBUG_NEW(array181->id);
            }
            array181->refC--;
            if(array181->refC == 0) {
               free(array181->data);
               free(array181);
               DEBUG_FREE(array181->id);
            }
            array180->refC--;
            if(array180->refC == 0) {
               free(array180->data);
               free(array180);
               DEBUG_FREE(array180->id);
            }
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array178;
         params0.data[1] = array179;
         array_t* array182 = func20(&params0, loopsFactor);
         DEBUG_RETURN(array182->id);
         free(params0.data);
         array_t* array183;
         if (pCounter > 0) {
            array183 = vars->data[--pCounter];
            array183->refC++;
            DEBUG_COPY(array183->id);
         } else {
            array183 = (array_t*)malloc(sizeof(array_t));
            array183->size = 784;
            array183->refC = 1;
            array183->id = 183;
            array183->data = (unsigned int*)malloc(array183->size*sizeof(unsigned int));
            memset(array183->data, 0, array183->size*sizeof(unsigned int));
            DEBUG_NEW(array183->id);
         }
         array_t* array184;
         if (pCounter > 0) {
            array184 = vars->data[--pCounter];
            array184->refC++;
            DEBUG_COPY(array184->id);
         } else {
            array184 = (array_t*)malloc(sizeof(array_t));
            array184->size = 21;
            array184->refC = 1;
            array184->id = 184;
            array184->data = (unsigned int*)malloc(array184->size*sizeof(unsigned int));
            memset(array184->data, 0, array184->size*sizeof(unsigned int));
            DEBUG_NEW(array184->id);
         }
         unsigned int loop36 = 0;
         unsigned int loopLimit36 = (rand()%loopsFactor)/4 + 1;
         for(; loop36 < loopLimit36; loop36++) {
            for (int i = 0; i < array182->size; i++) {
               array182->data[i]++;
            }
            for (int i = 0; i < array183->size; i++) {
               if (array183->data[i] == 28) { 
                  return array183;
               }
            }
            if(PATH0 & 4) {
               array_t_param params1;
               params1.size = 5;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array178;
               params1.data[1] = array179;
               params1.data[2] = array182;
               params1.data[3] = array183;
               params1.data[4] = array184;
               array_t* array185 = func24(&params1, loopsFactor);
               DEBUG_RETURN(array185->id);
               free(params1.data);
               array_t* array186;
               if (pCounter > 0) {
                  array186 = vars->data[--pCounter];
                  array186->refC++;
                  DEBUG_COPY(array186->id);
               } else {
                  array186 = (array_t*)malloc(sizeof(array_t));
                  array186->size = 908;
                  array186->refC = 1;
                  array186->id = 186;
                  array186->data = (unsigned int*)malloc(array186->size*sizeof(unsigned int));
                  memset(array186->data, 0, array186->size*sizeof(unsigned int));
                  DEBUG_NEW(array186->id);
               }
               array186->refC--;
               if(array186->refC == 0) {
                  free(array186->data);
                  free(array186);
                  DEBUG_FREE(array186->id);
               }
               array185->refC--;
               if(array185->refC == 0) {
                  free(array185->data);
                  free(array185);
                  DEBUG_FREE(array185->id);
               }
            }
            else {
            }
         }
         array_t* array187;
         if (pCounter > 0) {
            array187 = vars->data[--pCounter];
            array187->refC++;
            DEBUG_COPY(array187->id);
         } else {
            array187 = (array_t*)malloc(sizeof(array_t));
            array187->size = 958;
            array187->refC = 1;
            array187->id = 187;
            array187->data = (unsigned int*)malloc(array187->size*sizeof(unsigned int));
            memset(array187->data, 0, array187->size*sizeof(unsigned int));
            DEBUG_NEW(array187->id);
         }
         array_t* array188;
         if (pCounter > 0) {
            array188 = vars->data[--pCounter];
            array188->refC++;
            DEBUG_COPY(array188->id);
         } else {
            array188 = (array_t*)malloc(sizeof(array_t));
            array188->size = 498;
            array188->refC = 1;
            array188->id = 188;
            array188->data = (unsigned int*)malloc(array188->size*sizeof(unsigned int));
            memset(array188->data, 0, array188->size*sizeof(unsigned int));
            DEBUG_NEW(array188->id);
         }
         array188->refC--;
         if(array188->refC == 0) {
            free(array188->data);
            free(array188);
            DEBUG_FREE(array188->id);
         }
         array187->refC--;
         if(array187->refC == 0) {
            free(array187->data);
            free(array187);
            DEBUG_FREE(array187->id);
         }
         array184->refC--;
         if(array184->refC == 0) {
            free(array184->data);
            free(array184);
            DEBUG_FREE(array184->id);
         }
         array183->refC--;
         if(array183->refC == 0) {
            free(array183->data);
            free(array183);
            DEBUG_FREE(array183->id);
         }
         array182->refC--;
         if(array182->refC == 0) {
            free(array182->data);
            free(array182);
            DEBUG_FREE(array182->id);
         }
         array179->refC--;
         if(array179->refC == 0) {
            free(array179->data);
            free(array179);
            DEBUG_FREE(array179->id);
         }
      }
      else {
         if(PATH0 & 8) {
            array_t* array189;
            if (pCounter > 0) {
               array189 = vars->data[--pCounter];
               array189->refC++;
               DEBUG_COPY(array189->id);
            } else {
               array189 = (array_t*)malloc(sizeof(array_t));
               array189->size = 36;
               array189->refC = 1;
               array189->id = 189;
               array189->data = (unsigned int*)malloc(array189->size*sizeof(unsigned int));
               memset(array189->data, 0, array189->size*sizeof(unsigned int));
               DEBUG_NEW(array189->id);
            }
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array178;
            params0.data[1] = array189;
            array_t* array190 = func22(&params0, loopsFactor);
            DEBUG_RETURN(array190->id);
            free(params0.data);
            array_t* array191;
            if (pCounter > 0) {
               array191 = vars->data[--pCounter];
               array191->refC++;
               DEBUG_COPY(array191->id);
            } else {
               array191 = (array_t*)malloc(sizeof(array_t));
               array191->size = 248;
               array191->refC = 1;
               array191->id = 191;
               array191->data = (unsigned int*)malloc(array191->size*sizeof(unsigned int));
               memset(array191->data, 0, array191->size*sizeof(unsigned int));
               DEBUG_NEW(array191->id);
            }
            array_t* array192;
            if (pCounter > 0) {
               array192 = vars->data[--pCounter];
               array192->refC++;
               DEBUG_COPY(array192->id);
            } else {
               array192 = (array_t*)malloc(sizeof(array_t));
               array192->size = 303;
               array192->refC = 1;
               array192->id = 192;
               array192->data = (unsigned int*)malloc(array192->size*sizeof(unsigned int));
               memset(array192->data, 0, array192->size*sizeof(unsigned int));
               DEBUG_NEW(array192->id);
            }
            array192->refC--;
            if(array192->refC == 0) {
               free(array192->data);
               free(array192);
               DEBUG_FREE(array192->id);
            }
            array191->refC--;
            if(array191->refC == 0) {
               free(array191->data);
               free(array191);
               DEBUG_FREE(array191->id);
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
            array_t_param params0;
            params0.size = 1;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array178;
            array_t* array193 = func23(&params0, loopsFactor);
            DEBUG_RETURN(array193->id);
            free(params0.data);
            array_t* array194;
            if (pCounter > 0) {
               array194 = vars->data[--pCounter];
               array194->refC++;
               DEBUG_COPY(array194->id);
            } else {
               array194 = (array_t*)malloc(sizeof(array_t));
               array194->size = 648;
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
            array193->refC--;
            if(array193->refC == 0) {
               free(array193->data);
               free(array193);
               DEBUG_FREE(array193->id);
            }
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array178;
         array_t* array195 = func21(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array195->id);
         free(params0.data);
         array_t* array196;
         if (pCounter > 0) {
            array196 = vars->data[--pCounter];
            array196->refC++;
            DEBUG_COPY(array196->id);
         } else {
            array196 = (array_t*)malloc(sizeof(array_t));
            array196->size = 567;
            array196->refC = 1;
            array196->id = 196;
            array196->data = (unsigned int*)malloc(array196->size*sizeof(unsigned int));
            memset(array196->data, 0, array196->size*sizeof(unsigned int));
            DEBUG_NEW(array196->id);
         }
         array196->refC--;
         if(array196->refC == 0) {
            free(array196->data);
            free(array196);
            DEBUG_FREE(array196->id);
         }
         array195->refC--;
         if(array195->refC == 0) {
            free(array195->data);
            free(array195);
            DEBUG_FREE(array195->id);
         }
      }
      if(PATH0 & 16) {
         array_t* array197;
         if (pCounter > 0) {
            array197 = vars->data[--pCounter];
            array197->refC++;
            DEBUG_COPY(array197->id);
         } else {
            array197 = (array_t*)malloc(sizeof(array_t));
            array197->size = 746;
            array197->refC = 1;
            array197->id = 197;
            array197->data = (unsigned int*)malloc(array197->size*sizeof(unsigned int));
            memset(array197->data, 0, array197->size*sizeof(unsigned int));
            DEBUG_NEW(array197->id);
         }
         unsigned int loop37 = 0;
         unsigned int loopLimit37 = (rand()%loopsFactor)/4 + 1;
         for(; loop37 < loopLimit37; loop37++) {
            for (int i = 0; i < array178->size; i++) {
               array178->data[i]++;
            }
            for (int i = 0; i < array197->size; i++) {
               if (array197->data[i] == 0) { 
                  return array197;
               }
            }
            if(PATH0 & 32) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array178;
               params0.data[1] = array197;
               array_t* array198 = func19(&params0, rng(), loopsFactor);
               DEBUG_RETURN(array198->id);
               free(params0.data);
               array_t* array199;
               if (pCounter > 0) {
                  array199 = vars->data[--pCounter];
                  array199->refC++;
                  DEBUG_COPY(array199->id);
               } else {
                  array199 = (array_t*)malloc(sizeof(array_t));
                  array199->size = 797;
                  array199->refC = 1;
                  array199->id = 199;
                  array199->data = (unsigned int*)malloc(array199->size*sizeof(unsigned int));
                  memset(array199->data, 0, array199->size*sizeof(unsigned int));
                  DEBUG_NEW(array199->id);
               }
               array199->refC--;
               if(array199->refC == 0) {
                  free(array199->data);
                  free(array199);
                  DEBUG_FREE(array199->id);
               }
               array198->refC--;
               if(array198->refC == 0) {
                  free(array198->data);
                  free(array198);
                  DEBUG_FREE(array198->id);
               }
            }
            else {
               array_t* array200;
               if (pCounter > 0) {
                  array200 = vars->data[--pCounter];
                  array200->refC++;
                  DEBUG_COPY(array200->id);
               } else {
                  array200 = (array_t*)malloc(sizeof(array_t));
                  array200->size = 249;
                  array200->refC = 1;
                  array200->id = 200;
                  array200->data = (unsigned int*)malloc(array200->size*sizeof(unsigned int));
                  memset(array200->data, 0, array200->size*sizeof(unsigned int));
                  DEBUG_NEW(array200->id);
               }
               unsigned int loop38 = 0;
               unsigned int loopLimit38 = (rand()%loopsFactor)/5 + 1;
               for(; loop38 < loopLimit38; loop38++) {
                  for (int i = 0; i < array197->size; i++) {
                     array197->data[i]++;
                  }
                  for (int i = 0; i < array197->size; i++) {
                     if (array197->data[i] == 33) { 
                        return array197;
                     }
                  }
                  if(PATH0 & 64) {
                     array_t_param params0;
                     params0.size = 3;
                     params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                     params0.data[0] = array178;
                     params0.data[1] = array197;
                     params0.data[2] = array200;
                     array_t* array201 = func24(&params0, loopsFactor);
                     DEBUG_RETURN(array201->id);
                     free(params0.data);
                     array_t* array202;
                     if (pCounter > 0) {
                        array202 = vars->data[--pCounter];
                        array202->refC++;
                        DEBUG_COPY(array202->id);
                     } else {
                        array202 = (array_t*)malloc(sizeof(array_t));
                        array202->size = 253;
                        array202->refC = 1;
                        array202->id = 202;
                        array202->data = (unsigned int*)malloc(array202->size*sizeof(unsigned int));
                        memset(array202->data, 0, array202->size*sizeof(unsigned int));
                        DEBUG_NEW(array202->id);
                     }
                     array202->refC--;
                     if(array202->refC == 0) {
                        free(array202->data);
                        free(array202);
                        DEBUG_FREE(array202->id);
                     }
                     array201->refC--;
                     if(array201->refC == 0) {
                        free(array201->data);
                        free(array201);
                        DEBUG_FREE(array201->id);
                     }
                  }
                  else {
                  }
               }
               array_t* array203;
               if (pCounter > 0) {
                  array203 = vars->data[--pCounter];
                  array203->refC++;
                  DEBUG_COPY(array203->id);
               } else {
                  array203 = (array_t*)malloc(sizeof(array_t));
                  array203->size = 892;
                  array203->refC = 1;
                  array203->id = 203;
                  array203->data = (unsigned int*)malloc(array203->size*sizeof(unsigned int));
                  memset(array203->data, 0, array203->size*sizeof(unsigned int));
                  DEBUG_NEW(array203->id);
               }
               array203->refC--;
               if(array203->refC == 0) {
                  free(array203->data);
                  free(array203);
                  DEBUG_FREE(array203->id);
               }
               array200->refC--;
               if(array200->refC == 0) {
                  free(array200->data);
                  free(array200);
                  DEBUG_FREE(array200->id);
               }
            }
         }
         array_t* array204;
         if (pCounter > 0) {
            array204 = vars->data[--pCounter];
            array204->refC++;
            DEBUG_COPY(array204->id);
         } else {
            array204 = (array_t*)malloc(sizeof(array_t));
            array204->size = 686;
            array204->refC = 1;
            array204->id = 204;
            array204->data = (unsigned int*)malloc(array204->size*sizeof(unsigned int));
            memset(array204->data, 0, array204->size*sizeof(unsigned int));
            DEBUG_NEW(array204->id);
         }
         array204->refC--;
         if(array204->refC == 0) {
            free(array204->data);
            free(array204);
            DEBUG_FREE(array204->id);
         }
         array197->refC--;
         if(array197->refC == 0) {
            free(array197->data);
            free(array197);
            DEBUG_FREE(array197->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array178;
         array_t* array205 = func17(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array205->id);
         free(params0.data);
         for (int i = 0; i < array178->size; i++) {
            if (array178->data[i] == 75) { 
               return array178;
            }
         }
         unsigned int loop39 = 0;
         unsigned int loopLimit39 = (rand()%loopsFactor)/4 + 1;
         for(; loop39 < loopLimit39; loop39++) {
            for (int i = 0; i < array178->size; i++) {
               array178->data[i]--;
            }
            for (int i = 0; i < array205->size; i++) {
               if (array205->data[i] == 29) { 
                  return array205;
               }
            }
            if(PATH0 & 128) {
               array_t* array206;
               if (pCounter > 0) {
                  array206 = vars->data[--pCounter];
                  array206->refC++;
                  DEBUG_COPY(array206->id);
               } else {
                  array206 = (array_t*)malloc(sizeof(array_t));
                  array206->size = 436;
                  array206->refC = 1;
                  array206->id = 206;
                  array206->data = (unsigned int*)malloc(array206->size*sizeof(unsigned int));
                  memset(array206->data, 0, array206->size*sizeof(unsigned int));
                  DEBUG_NEW(array206->id);
               }
               array_t_param params1;
               params1.size = 3;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array178;
               params1.data[1] = array205;
               params1.data[2] = array206;
               array_t* array207 = func22(&params1, loopsFactor);
               DEBUG_RETURN(array207->id);
               free(params1.data);
               array_t* array208;
               if (pCounter > 0) {
                  array208 = vars->data[--pCounter];
                  array208->refC++;
                  DEBUG_COPY(array208->id);
               } else {
                  array208 = (array_t*)malloc(sizeof(array_t));
                  array208->size = 921;
                  array208->refC = 1;
                  array208->id = 208;
                  array208->data = (unsigned int*)malloc(array208->size*sizeof(unsigned int));
                  memset(array208->data, 0, array208->size*sizeof(unsigned int));
                  DEBUG_NEW(array208->id);
               }
               array_t* array209;
               if (pCounter > 0) {
                  array209 = vars->data[--pCounter];
                  array209->refC++;
                  DEBUG_COPY(array209->id);
               } else {
                  array209 = (array_t*)malloc(sizeof(array_t));
                  array209->size = 460;
                  array209->refC = 1;
                  array209->id = 209;
                  array209->data = (unsigned int*)malloc(array209->size*sizeof(unsigned int));
                  memset(array209->data, 0, array209->size*sizeof(unsigned int));
                  DEBUG_NEW(array209->id);
               }
               array209->refC--;
               if(array209->refC == 0) {
                  free(array209->data);
                  free(array209);
                  DEBUG_FREE(array209->id);
               }
               array208->refC--;
               if(array208->refC == 0) {
                  free(array208->data);
                  free(array208);
                  DEBUG_FREE(array208->id);
               }
               array207->refC--;
               if(array207->refC == 0) {
                  free(array207->data);
                  free(array207);
                  DEBUG_FREE(array207->id);
               }
               array206->refC--;
               if(array206->refC == 0) {
                  free(array206->data);
                  free(array206);
                  DEBUG_FREE(array206->id);
               }
            }
            else {
               array_t_param params1;
               params1.size = 2;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array178;
               params1.data[1] = array205;
               array_t* array210 = func23(&params1, loopsFactor);
               DEBUG_RETURN(array210->id);
               free(params1.data);
               array_t* array211;
               if (pCounter > 0) {
                  array211 = vars->data[--pCounter];
                  array211->refC++;
                  DEBUG_COPY(array211->id);
               } else {
                  array211 = (array_t*)malloc(sizeof(array_t));
                  array211->size = 27;
                  array211->refC = 1;
                  array211->id = 211;
                  array211->data = (unsigned int*)malloc(array211->size*sizeof(unsigned int));
                  memset(array211->data, 0, array211->size*sizeof(unsigned int));
                  DEBUG_NEW(array211->id);
               }
               array211->refC--;
               if(array211->refC == 0) {
                  free(array211->data);
                  free(array211);
                  DEBUG_FREE(array211->id);
               }
               array210->refC--;
               if(array210->refC == 0) {
                  free(array210->data);
                  free(array210);
                  DEBUG_FREE(array210->id);
               }
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array178;
         params1.data[1] = array205;
         array_t* array212 = func18(&params1, loopsFactor);
         DEBUG_RETURN(array212->id);
         free(params1.data);
         array_t* array213;
         if (pCounter > 0) {
            array213 = vars->data[--pCounter];
            array213->refC++;
            DEBUG_COPY(array213->id);
         } else {
            array213 = (array_t*)malloc(sizeof(array_t));
            array213->size = 556;
            array213->refC = 1;
            array213->id = 213;
            array213->data = (unsigned int*)malloc(array213->size*sizeof(unsigned int));
            memset(array213->data, 0, array213->size*sizeof(unsigned int));
            DEBUG_NEW(array213->id);
         }
         array_t* array214;
         if (pCounter > 0) {
            array214 = vars->data[--pCounter];
            array214->refC++;
            DEBUG_COPY(array214->id);
         } else {
            array214 = (array_t*)malloc(sizeof(array_t));
            array214->size = 902;
            array214->refC = 1;
            array214->id = 214;
            array214->data = (unsigned int*)malloc(array214->size*sizeof(unsigned int));
            memset(array214->data, 0, array214->size*sizeof(unsigned int));
            DEBUG_NEW(array214->id);
         }
         array214->refC--;
         if(array214->refC == 0) {
            free(array214->data);
            free(array214);
            DEBUG_FREE(array214->id);
         }
         array213->refC--;
         if(array213->refC == 0) {
            free(array213->data);
            free(array213);
            DEBUG_FREE(array213->id);
         }
         array212->refC--;
         if(array212->refC == 0) {
            free(array212->data);
            free(array212);
            DEBUG_FREE(array212->id);
         }
         array205->refC--;
         if(array205->refC == 0) {
            free(array205->data);
            free(array205);
            DEBUG_FREE(array205->id);
         }
      }
      for (int i = 0; i < array178->size; i++) {
         if (array178->data[i] == 97) { 
            return array178;
         }
      }
      array_t* array215;
      if (pCounter > 0) {
         array215 = vars->data[--pCounter];
         array215->refC++;
         DEBUG_COPY(array215->id);
      } else {
         array215 = (array_t*)malloc(sizeof(array_t));
         array215->size = 699;
         array215->refC = 1;
         array215->id = 215;
         array215->data = (unsigned int*)malloc(array215->size*sizeof(unsigned int));
         memset(array215->data, 0, array215->size*sizeof(unsigned int));
         DEBUG_NEW(array215->id);
      }
      array215->refC--;
      if(array215->refC == 0) {
         free(array215->data);
         free(array215);
         DEBUG_FREE(array215->id);
      }
      array178->refC--;
      if(array178->refC == 0) {
         free(array178->data);
         free(array178);
         DEBUG_FREE(array178->id);
      }
   }
   array_t* array216;
   if (pCounter > 0) {
      array216 = vars->data[--pCounter];
      array216->refC++;
      DEBUG_COPY(array216->id);
   } else {
      array216 = (array_t*)malloc(sizeof(array_t));
      array216->size = 43;
      array216->refC = 1;
      array216->id = 216;
      array216->data = (unsigned int*)malloc(array216->size*sizeof(unsigned int));
      memset(array216->data, 0, array216->size*sizeof(unsigned int));
      DEBUG_NEW(array216->id);
   }
   return array216;
}

