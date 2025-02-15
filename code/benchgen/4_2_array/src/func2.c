#include "outs/4_2_array.h" 
array_t* func2(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop1 = 0;
   unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
   for(; loop1 < loopLimit1; loop1++) {
      array_t* array3;
      if (pCounter > 0) {
         array3 = vars->data[--pCounter];
         array3->refC++;
         DEBUG_COPY(array3->id);
      } else {
         array3 = (array_t*)malloc(sizeof(array_t));
         array3->size = 763;
         array3->refC = 1;
         array3->id = 3;
         array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
         memset(array3->data, 0, array3->size*sizeof(unsigned int));
         DEBUG_NEW(array3->id);
      }
      if(PATH0 & 1) {
         array_t* array4;
         if (pCounter > 0) {
            array4 = vars->data[--pCounter];
            array4->refC++;
            DEBUG_COPY(array4->id);
         } else {
            array4 = (array_t*)malloc(sizeof(array_t));
            array4->size = 926;
            array4->refC = 1;
            array4->id = 4;
            array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
            memset(array4->data, 0, array4->size*sizeof(unsigned int));
            DEBUG_NEW(array4->id);
         }
         unsigned int loop2 = 0;
         unsigned int loopLimit2 = (rand()%loopsFactor)/3 + 1;
         for(; loop2 < loopLimit2; loop2++) {
            array_t* array5;
            if (pCounter > 0) {
               array5 = vars->data[--pCounter];
               array5->refC++;
               DEBUG_COPY(array5->id);
            } else {
               array5 = (array_t*)malloc(sizeof(array_t));
               array5->size = 540;
               array5->refC = 1;
               array5->id = 5;
               array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
               memset(array5->data, 0, array5->size*sizeof(unsigned int));
               DEBUG_NEW(array5->id);
            }
            if(PATH0 & 2) {
            }
            else {
            }
            for (int i = 0; i < array3->size; i++) {
               if (array3->data[i] == 72) { 
                  return array3;
               }
            }
            array_t* array6;
            if (pCounter > 0) {
               array6 = vars->data[--pCounter];
               array6->refC++;
               DEBUG_COPY(array6->id);
            } else {
               array6 = (array_t*)malloc(sizeof(array_t));
               array6->size = 736;
               array6->refC = 1;
               array6->id = 6;
               array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
               memset(array6->data, 0, array6->size*sizeof(unsigned int));
               DEBUG_NEW(array6->id);
            }
            array6->refC--;
            if(array6->refC == 0) {
               free(array6->data);
               free(array6);
               DEBUG_FREE(array6->id);
            }
            array5->refC--;
            if(array5->refC == 0) {
               free(array5->data);
               free(array5);
               DEBUG_FREE(array5->id);
            }
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array3;
         params0.data[1] = array4;
         array_t* array7 = func12(&params0, loopsFactor);
         DEBUG_RETURN(array7->id);
         free(params0.data);
         array_t* array14;
         if (pCounter > 0) {
            array14 = vars->data[--pCounter];
            array14->refC++;
            DEBUG_COPY(array14->id);
         } else {
            array14 = (array_t*)malloc(sizeof(array_t));
            array14->size = 784;
            array14->refC = 1;
            array14->id = 14;
            array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
            memset(array14->data, 0, array14->size*sizeof(unsigned int));
            DEBUG_NEW(array14->id);
         }
         array_t* array15;
         if (pCounter > 0) {
            array15 = vars->data[--pCounter];
            array15->refC++;
            DEBUG_COPY(array15->id);
         } else {
            array15 = (array_t*)malloc(sizeof(array_t));
            array15->size = 537;
            array15->refC = 1;
            array15->id = 15;
            array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
            memset(array15->data, 0, array15->size*sizeof(unsigned int));
            DEBUG_NEW(array15->id);
         }
         unsigned int loop4 = 0;
         unsigned int loopLimit4 = (rand()%loopsFactor)/3 + 1;
         for(; loop4 < loopLimit4; loop4++) {
            for (int i = 0; i < array14->size; i++) {
               array14->data[i]++;
            }
            for (int i = 0; i < array15->size; i++) {
               if (array15->data[i] == 15) { 
                  return array15;
               }
            }
            if(PATH0 & 4) {
               array_t_param params1;
               params1.size = 5;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array3;
               params1.data[1] = array4;
               params1.data[2] = array7;
               params1.data[3] = array14;
               params1.data[4] = array15;
               array_t* array16 = func19(&params1, loopsFactor);
               DEBUG_RETURN(array16->id);
               free(params1.data);
               array_t* array18;
               if (pCounter > 0) {
                  array18 = vars->data[--pCounter];
                  array18->refC++;
                  DEBUG_COPY(array18->id);
               } else {
                  array18 = (array_t*)malloc(sizeof(array_t));
                  array18->size = 873;
                  array18->refC = 1;
                  array18->id = 18;
                  array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
                  memset(array18->data, 0, array18->size*sizeof(unsigned int));
                  DEBUG_NEW(array18->id);
               }
               array18->refC--;
               if(array18->refC == 0) {
                  free(array18->data);
                  free(array18);
                  DEBUG_FREE(array18->id);
               }
               array16->refC--;
               if(array16->refC == 0) {
                  free(array16->data);
                  free(array16);
                  DEBUG_FREE(array16->id);
               }
            }
            else {
            }
         }
         array_t* array19;
         if (pCounter > 0) {
            array19 = vars->data[--pCounter];
            array19->refC++;
            DEBUG_COPY(array19->id);
         } else {
            array19 = (array_t*)malloc(sizeof(array_t));
            array19->size = 862;
            array19->refC = 1;
            array19->id = 19;
            array19->data = (unsigned int*)malloc(array19->size*sizeof(unsigned int));
            memset(array19->data, 0, array19->size*sizeof(unsigned int));
            DEBUG_NEW(array19->id);
         }
         array_t* array20;
         if (pCounter > 0) {
            array20 = vars->data[--pCounter];
            array20->refC++;
            DEBUG_COPY(array20->id);
         } else {
            array20 = (array_t*)malloc(sizeof(array_t));
            array20->size = 170;
            array20->refC = 1;
            array20->id = 20;
            array20->data = (unsigned int*)malloc(array20->size*sizeof(unsigned int));
            memset(array20->data, 0, array20->size*sizeof(unsigned int));
            DEBUG_NEW(array20->id);
         }
         array20->refC--;
         if(array20->refC == 0) {
            free(array20->data);
            free(array20);
            DEBUG_FREE(array20->id);
         }
         array19->refC--;
         if(array19->refC == 0) {
            free(array19->data);
            free(array19);
            DEBUG_FREE(array19->id);
         }
         array15->refC--;
         if(array15->refC == 0) {
            free(array15->data);
            free(array15);
            DEBUG_FREE(array15->id);
         }
         array14->refC--;
         if(array14->refC == 0) {
            free(array14->data);
            free(array14);
            DEBUG_FREE(array14->id);
         }
         array7->refC--;
         if(array7->refC == 0) {
            free(array7->data);
            free(array7);
            DEBUG_FREE(array7->id);
         }
         array4->refC--;
         if(array4->refC == 0) {
            free(array4->data);
            free(array4);
            DEBUG_FREE(array4->id);
         }
      }
      else {
         if(PATH0 & 8) {
            array_t* array21;
            if (pCounter > 0) {
               array21 = vars->data[--pCounter];
               array21->refC++;
               DEBUG_COPY(array21->id);
            } else {
               array21 = (array_t*)malloc(sizeof(array_t));
               array21->size = 996;
               array21->refC = 1;
               array21->id = 21;
               array21->data = (unsigned int*)malloc(array21->size*sizeof(unsigned int));
               memset(array21->data, 0, array21->size*sizeof(unsigned int));
               DEBUG_NEW(array21->id);
            }
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array3;
            params0.data[1] = array21;
            array_t* array22 = func20(&params0, loopsFactor);
            DEBUG_RETURN(array22->id);
            free(params0.data);
            array_t* array24;
            if (pCounter > 0) {
               array24 = vars->data[--pCounter];
               array24->refC++;
               DEBUG_COPY(array24->id);
            } else {
               array24 = (array_t*)malloc(sizeof(array_t));
               array24->size = 505;
               array24->refC = 1;
               array24->id = 24;
               array24->data = (unsigned int*)malloc(array24->size*sizeof(unsigned int));
               memset(array24->data, 0, array24->size*sizeof(unsigned int));
               DEBUG_NEW(array24->id);
            }
            array_t* array25;
            if (pCounter > 0) {
               array25 = vars->data[--pCounter];
               array25->refC++;
               DEBUG_COPY(array25->id);
            } else {
               array25 = (array_t*)malloc(sizeof(array_t));
               array25->size = 846;
               array25->refC = 1;
               array25->id = 25;
               array25->data = (unsigned int*)malloc(array25->size*sizeof(unsigned int));
               memset(array25->data, 0, array25->size*sizeof(unsigned int));
               DEBUG_NEW(array25->id);
            }
            array25->refC--;
            if(array25->refC == 0) {
               free(array25->data);
               free(array25);
               DEBUG_FREE(array25->id);
            }
            array24->refC--;
            if(array24->refC == 0) {
               free(array24->data);
               free(array24);
               DEBUG_FREE(array24->id);
            }
            array22->refC--;
            if(array22->refC == 0) {
               free(array22->data);
               free(array22);
               DEBUG_FREE(array22->id);
            }
            array21->refC--;
            if(array21->refC == 0) {
               free(array21->data);
               free(array21);
               DEBUG_FREE(array21->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 1;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array3;
            array_t* array26 = func21(&params0, loopsFactor);
            DEBUG_RETURN(array26->id);
            free(params0.data);
            array_t* array28;
            if (pCounter > 0) {
               array28 = vars->data[--pCounter];
               array28->refC++;
               DEBUG_COPY(array28->id);
            } else {
               array28 = (array_t*)malloc(sizeof(array_t));
               array28->size = 814;
               array28->refC = 1;
               array28->id = 28;
               array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
               memset(array28->data, 0, array28->size*sizeof(unsigned int));
               DEBUG_NEW(array28->id);
            }
            array28->refC--;
            if(array28->refC == 0) {
               free(array28->data);
               free(array28);
               DEBUG_FREE(array28->id);
            }
            array26->refC--;
            if(array26->refC == 0) {
               free(array26->data);
               free(array26);
               DEBUG_FREE(array26->id);
            }
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array3;
         array_t* array29 = func13(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array29->id);
         free(params0.data);
         array_t* array33;
         if (pCounter > 0) {
            array33 = vars->data[--pCounter];
            array33->refC++;
            DEBUG_COPY(array33->id);
         } else {
            array33 = (array_t*)malloc(sizeof(array_t));
            array33->size = 403;
            array33->refC = 1;
            array33->id = 33;
            array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
            memset(array33->data, 0, array33->size*sizeof(unsigned int));
            DEBUG_NEW(array33->id);
         }
         array33->refC--;
         if(array33->refC == 0) {
            free(array33->data);
            free(array33);
            DEBUG_FREE(array33->id);
         }
         array29->refC--;
         if(array29->refC == 0) {
            free(array29->data);
            free(array29);
            DEBUG_FREE(array29->id);
         }
      }
      if(PATH0 & 16) {
         array_t* array34;
         if (pCounter > 0) {
            array34 = vars->data[--pCounter];
            array34->refC++;
            DEBUG_COPY(array34->id);
         } else {
            array34 = (array_t*)malloc(sizeof(array_t));
            array34->size = 651;
            array34->refC = 1;
            array34->id = 34;
            array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
            memset(array34->data, 0, array34->size*sizeof(unsigned int));
            DEBUG_NEW(array34->id);
         }
         unsigned int loop8 = 0;
         unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
         for(; loop8 < loopLimit8; loop8++) {
            for (int i = 0; i < array3->size; i++) {
               array3->data[i]++;
            }
            for (int i = 0; i < array34->size; i++) {
               if (array34->data[i] == 32) { 
                  return array34;
               }
            }
            if(PATH0 & 32) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array3;
               params0.data[1] = array34;
               array_t* array35 = func14(&params0, rng(), loopsFactor);
               DEBUG_RETURN(array35->id);
               free(params0.data);
               array_t* array39;
               if (pCounter > 0) {
                  array39 = vars->data[--pCounter];
                  array39->refC++;
                  DEBUG_COPY(array39->id);
               } else {
                  array39 = (array_t*)malloc(sizeof(array_t));
                  array39->size = 570;
                  array39->refC = 1;
                  array39->id = 39;
                  array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
                  memset(array39->data, 0, array39->size*sizeof(unsigned int));
                  DEBUG_NEW(array39->id);
               }
               array39->refC--;
               if(array39->refC == 0) {
                  free(array39->data);
                  free(array39);
                  DEBUG_FREE(array39->id);
               }
               array35->refC--;
               if(array35->refC == 0) {
                  free(array35->data);
                  free(array35);
                  DEBUG_FREE(array35->id);
               }
            }
            else {
               array_t* array40;
               if (pCounter > 0) {
                  array40 = vars->data[--pCounter];
                  array40->refC++;
                  DEBUG_COPY(array40->id);
               } else {
                  array40 = (array_t*)malloc(sizeof(array_t));
                  array40->size = 434;
                  array40->refC = 1;
                  array40->id = 40;
                  array40->data = (unsigned int*)malloc(array40->size*sizeof(unsigned int));
                  memset(array40->data, 0, array40->size*sizeof(unsigned int));
                  DEBUG_NEW(array40->id);
               }
               unsigned int loop10 = 0;
               unsigned int loopLimit10 = (rand()%loopsFactor)/4 + 1;
               for(; loop10 < loopLimit10; loop10++) {
                  for (int i = 0; i < array34->size; i++) {
                     array34->data[i]++;
                  }
                  for (int i = 0; i < array40->size; i++) {
                     if (array40->data[i] == 1) { 
                        return array40;
                     }
                  }
                  if(PATH0 & 64) {
                     array_t_param params0;
                     params0.size = 3;
                     params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                     params0.data[0] = array3;
                     params0.data[1] = array34;
                     params0.data[2] = array40;
                     array_t* array41 = func19(&params0, loopsFactor);
                     DEBUG_RETURN(array41->id);
                     free(params0.data);
                     array_t* array42;
                     if (pCounter > 0) {
                        array42 = vars->data[--pCounter];
                        array42->refC++;
                        DEBUG_COPY(array42->id);
                     } else {
                        array42 = (array_t*)malloc(sizeof(array_t));
                        array42->size = 317;
                        array42->refC = 1;
                        array42->id = 42;
                        array42->data = (unsigned int*)malloc(array42->size*sizeof(unsigned int));
                        memset(array42->data, 0, array42->size*sizeof(unsigned int));
                        DEBUG_NEW(array42->id);
                     }
                     array42->refC--;
                     if(array42->refC == 0) {
                        free(array42->data);
                        free(array42);
                        DEBUG_FREE(array42->id);
                     }
                     array41->refC--;
                     if(array41->refC == 0) {
                        free(array41->data);
                        free(array41);
                        DEBUG_FREE(array41->id);
                     }
                  }
                  else {
                  }
               }
               array_t* array43;
               if (pCounter > 0) {
                  array43 = vars->data[--pCounter];
                  array43->refC++;
                  DEBUG_COPY(array43->id);
               } else {
                  array43 = (array_t*)malloc(sizeof(array_t));
                  array43->size = 492;
                  array43->refC = 1;
                  array43->id = 43;
                  array43->data = (unsigned int*)malloc(array43->size*sizeof(unsigned int));
                  memset(array43->data, 0, array43->size*sizeof(unsigned int));
                  DEBUG_NEW(array43->id);
               }
               array43->refC--;
               if(array43->refC == 0) {
                  free(array43->data);
                  free(array43);
                  DEBUG_FREE(array43->id);
               }
               array40->refC--;
               if(array40->refC == 0) {
                  free(array40->data);
                  free(array40);
                  DEBUG_FREE(array40->id);
               }
            }
         }
         array_t* array44;
         if (pCounter > 0) {
            array44 = vars->data[--pCounter];
            array44->refC++;
            DEBUG_COPY(array44->id);
         } else {
            array44 = (array_t*)malloc(sizeof(array_t));
            array44->size = 652;
            array44->refC = 1;
            array44->id = 44;
            array44->data = (unsigned int*)malloc(array44->size*sizeof(unsigned int));
            memset(array44->data, 0, array44->size*sizeof(unsigned int));
            DEBUG_NEW(array44->id);
         }
         array44->refC--;
         if(array44->refC == 0) {
            free(array44->data);
            free(array44);
            DEBUG_FREE(array44->id);
         }
         array34->refC--;
         if(array34->refC == 0) {
            free(array34->data);
            free(array34);
            DEBUG_FREE(array34->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array3;
         array_t* array45 = func15(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array45->id);
         free(params0.data);
         for (int i = 0; i < array45->size; i++) {
            if (array45->data[i] == 71) { 
               return array45;
            }
         }
         unsigned int loop12 = 0;
         unsigned int loopLimit12 = (rand()%loopsFactor)/3 + 1;
         for(; loop12 < loopLimit12; loop12++) {
            for (int i = 0; i < array45->size; i++) {
               array45->data[i]--;
            }
            for (int i = 0; i < array45->size; i++) {
               if (array45->data[i] == 9) { 
                  return array45;
               }
            }
            if(PATH0 & 128) {
               array_t* array50;
               if (pCounter > 0) {
                  array50 = vars->data[--pCounter];
                  array50->refC++;
                  DEBUG_COPY(array50->id);
               } else {
                  array50 = (array_t*)malloc(sizeof(array_t));
                  array50->size = 927;
                  array50->refC = 1;
                  array50->id = 50;
                  array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
                  memset(array50->data, 0, array50->size*sizeof(unsigned int));
                  DEBUG_NEW(array50->id);
               }
               array_t_param params1;
               params1.size = 3;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array3;
               params1.data[1] = array45;
               params1.data[2] = array50;
               array_t* array51 = func20(&params1, loopsFactor);
               DEBUG_RETURN(array51->id);
               free(params1.data);
               array_t* array52;
               if (pCounter > 0) {
                  array52 = vars->data[--pCounter];
                  array52->refC++;
                  DEBUG_COPY(array52->id);
               } else {
                  array52 = (array_t*)malloc(sizeof(array_t));
                  array52->size = 497;
                  array52->refC = 1;
                  array52->id = 52;
                  array52->data = (unsigned int*)malloc(array52->size*sizeof(unsigned int));
                  memset(array52->data, 0, array52->size*sizeof(unsigned int));
                  DEBUG_NEW(array52->id);
               }
               array_t* array53;
               if (pCounter > 0) {
                  array53 = vars->data[--pCounter];
                  array53->refC++;
                  DEBUG_COPY(array53->id);
               } else {
                  array53 = (array_t*)malloc(sizeof(array_t));
                  array53->size = 353;
                  array53->refC = 1;
                  array53->id = 53;
                  array53->data = (unsigned int*)malloc(array53->size*sizeof(unsigned int));
                  memset(array53->data, 0, array53->size*sizeof(unsigned int));
                  DEBUG_NEW(array53->id);
               }
               array53->refC--;
               if(array53->refC == 0) {
                  free(array53->data);
                  free(array53);
                  DEBUG_FREE(array53->id);
               }
               array52->refC--;
               if(array52->refC == 0) {
                  free(array52->data);
                  free(array52);
                  DEBUG_FREE(array52->id);
               }
               array51->refC--;
               if(array51->refC == 0) {
                  free(array51->data);
                  free(array51);
                  DEBUG_FREE(array51->id);
               }
               array50->refC--;
               if(array50->refC == 0) {
                  free(array50->data);
                  free(array50);
                  DEBUG_FREE(array50->id);
               }
            }
            else {
               array_t_param params1;
               params1.size = 2;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array3;
               params1.data[1] = array45;
               array_t* array54 = func21(&params1, loopsFactor);
               DEBUG_RETURN(array54->id);
               free(params1.data);
               array_t* array55;
               if (pCounter > 0) {
                  array55 = vars->data[--pCounter];
                  array55->refC++;
                  DEBUG_COPY(array55->id);
               } else {
                  array55 = (array_t*)malloc(sizeof(array_t));
                  array55->size = 306;
                  array55->refC = 1;
                  array55->id = 55;
                  array55->data = (unsigned int*)malloc(array55->size*sizeof(unsigned int));
                  memset(array55->data, 0, array55->size*sizeof(unsigned int));
                  DEBUG_NEW(array55->id);
               }
               array55->refC--;
               if(array55->refC == 0) {
                  free(array55->data);
                  free(array55);
                  DEBUG_FREE(array55->id);
               }
               array54->refC--;
               if(array54->refC == 0) {
                  free(array54->data);
                  free(array54);
                  DEBUG_FREE(array54->id);
               }
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array3;
         params1.data[1] = array45;
         array_t* array56 = func16(&params1, loopsFactor);
         DEBUG_RETURN(array56->id);
         free(params1.data);
         array_t* array62;
         if (pCounter > 0) {
            array62 = vars->data[--pCounter];
            array62->refC++;
            DEBUG_COPY(array62->id);
         } else {
            array62 = (array_t*)malloc(sizeof(array_t));
            array62->size = 618;
            array62->refC = 1;
            array62->id = 62;
            array62->data = (unsigned int*)malloc(array62->size*sizeof(unsigned int));
            memset(array62->data, 0, array62->size*sizeof(unsigned int));
            DEBUG_NEW(array62->id);
         }
         array_t* array63;
         if (pCounter > 0) {
            array63 = vars->data[--pCounter];
            array63->refC++;
            DEBUG_COPY(array63->id);
         } else {
            array63 = (array_t*)malloc(sizeof(array_t));
            array63->size = 245;
            array63->refC = 1;
            array63->id = 63;
            array63->data = (unsigned int*)malloc(array63->size*sizeof(unsigned int));
            memset(array63->data, 0, array63->size*sizeof(unsigned int));
            DEBUG_NEW(array63->id);
         }
         array63->refC--;
         if(array63->refC == 0) {
            free(array63->data);
            free(array63);
            DEBUG_FREE(array63->id);
         }
         array62->refC--;
         if(array62->refC == 0) {
            free(array62->data);
            free(array62);
            DEBUG_FREE(array62->id);
         }
         array56->refC--;
         if(array56->refC == 0) {
            free(array56->data);
            free(array56);
            DEBUG_FREE(array56->id);
         }
         array45->refC--;
         if(array45->refC == 0) {
            free(array45->data);
            free(array45);
            DEBUG_FREE(array45->id);
         }
      }
      for (int i = 0; i < array3->size; i++) {
         if (array3->data[i] == 51) { 
            return array3;
         }
      }
      array_t* array64;
      if (pCounter > 0) {
         array64 = vars->data[--pCounter];
         array64->refC++;
         DEBUG_COPY(array64->id);
      } else {
         array64 = (array_t*)malloc(sizeof(array_t));
         array64->size = 921;
         array64->refC = 1;
         array64->id = 64;
         array64->data = (unsigned int*)malloc(array64->size*sizeof(unsigned int));
         memset(array64->data, 0, array64->size*sizeof(unsigned int));
         DEBUG_NEW(array64->id);
      }
      array64->refC--;
      if(array64->refC == 0) {
         free(array64->data);
         free(array64);
         DEBUG_FREE(array64->id);
      }
      array3->refC--;
      if(array3->refC == 0) {
         free(array3->data);
         free(array3);
         DEBUG_FREE(array3->id);
      }
   }
   array_t* array65;
   if (pCounter > 0) {
      array65 = vars->data[--pCounter];
      array65->refC++;
      DEBUG_COPY(array65->id);
   } else {
      array65 = (array_t*)malloc(sizeof(array_t));
      array65->size = 555;
      array65->refC = 1;
      array65->id = 65;
      array65->data = (unsigned int*)malloc(array65->size*sizeof(unsigned int));
      memset(array65->data, 0, array65->size*sizeof(unsigned int));
      DEBUG_NEW(array65->id);
   }
   return array65;
}

