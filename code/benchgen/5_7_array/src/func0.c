#include "outs/5_7_array.h" 
array_t* func0(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      unsigned int loop0 = 0;
      unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
      for(; loop0 < loopLimit0; loop0++) {
         array_t* array2;
         if (pCounter > 0) {
            array2 = vars->data[--pCounter];
            array2->refC++;
            DEBUG_COPY(array2->id);
         } else {
            array2 = (array_t*)malloc(sizeof(array_t));
            array2->size = 492;
            array2->refC = 1;
            array2->id = 2;
            array2->data = (unsigned int*)malloc(array2->size*sizeof(unsigned int));
            memset(array2->data, 0, array2->size*sizeof(unsigned int));
            DEBUG_NEW(array2->id);
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array2;
         array_t* array3 = func12(&params0, loopsFactor);
         DEBUG_RETURN(array3->id);
         free(params0.data);
         array_t* array5;
         if (pCounter > 0) {
            array5 = vars->data[--pCounter];
            array5->refC++;
            DEBUG_COPY(array5->id);
         } else {
            array5 = (array_t*)malloc(sizeof(array_t));
            array5->size = 763;
            array5->refC = 1;
            array5->id = 5;
            array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
            memset(array5->data, 0, array5->size*sizeof(unsigned int));
            DEBUG_NEW(array5->id);
         }
         if(PATH0 & 2) {
            unsigned int loop1 = 0;
            unsigned int loopLimit1 = (rand()%loopsFactor)/2 + 1;
            for(; loop1 < loopLimit1; loop1++) {
            }
         }
         else {
            array_t* array6;
            if (pCounter > 0) {
               array6 = vars->data[--pCounter];
               array6->refC++;
               DEBUG_COPY(array6->id);
            } else {
               array6 = (array_t*)malloc(sizeof(array_t));
               array6->size = 926;
               array6->refC = 1;
               array6->id = 6;
               array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
               memset(array6->data, 0, array6->size*sizeof(unsigned int));
               DEBUG_NEW(array6->id);
            }
            array_t_param params1;
            params1.size = 4;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array2;
            params1.data[1] = array3;
            params1.data[2] = array5;
            params1.data[3] = array6;
            array_t* array7 = func13(&params1, loopsFactor);
            DEBUG_RETURN(array7->id);
            free(params1.data);
            array7->refC--;
            if(array7->refC == 0) {
               free(array7->data);
               free(array7);
               DEBUG_FREE(array7->id);
            }
            array6->refC--;
            if(array6->refC == 0) {
               free(array6->data);
               free(array6);
               DEBUG_FREE(array6->id);
            }
         }
         for (int i = 0; i < array2->size; i++) {
            if (array2->data[i] == 29) { 
               return array2;
            }
         }
         array_t* array9;
         if (pCounter > 0) {
            array9 = vars->data[--pCounter];
            array9->refC++;
            DEBUG_COPY(array9->id);
         } else {
            array9 = (array_t*)malloc(sizeof(array_t));
            array9->size = 782;
            array9->refC = 1;
            array9->id = 9;
            array9->data = (unsigned int*)malloc(array9->size*sizeof(unsigned int));
            memset(array9->data, 0, array9->size*sizeof(unsigned int));
            DEBUG_NEW(array9->id);
         }
         array_t* array10;
         if (pCounter > 0) {
            array10 = vars->data[--pCounter];
            array10->refC++;
            DEBUG_COPY(array10->id);
         } else {
            array10 = (array_t*)malloc(sizeof(array_t));
            array10->size = 530;
            array10->refC = 1;
            array10->id = 10;
            array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
            memset(array10->data, 0, array10->size*sizeof(unsigned int));
            DEBUG_NEW(array10->id);
         }
         for (int i = 0; i < array5->size; i++) {
            array5->data[i]++;
         }
         unsigned int loop2 = 0;
         unsigned int loopLimit2 = (rand()%loopsFactor)/2 + 1;
         for(; loop2 < loopLimit2; loop2++) {
            for (int i = 0; i < array9->size; i++) {
               array9->data[i]--;
            }
         }
         array_t_param params1;
         params1.size = 5;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array2;
         params1.data[1] = array3;
         params1.data[2] = array5;
         params1.data[3] = array9;
         params1.data[4] = array10;
         array_t* array11 = func14(&params1, loopsFactor);
         DEBUG_RETURN(array11->id);
         free(params1.data);
         array_t* array13;
         if (pCounter > 0) {
            array13 = vars->data[--pCounter];
            array13->refC++;
            DEBUG_COPY(array13->id);
         } else {
            array13 = (array_t*)malloc(sizeof(array_t));
            array13->size = 69;
            array13->refC = 1;
            array13->id = 13;
            array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
            memset(array13->data, 0, array13->size*sizeof(unsigned int));
            DEBUG_NEW(array13->id);
         }
         array_t_param params2;
         params2.size = 7;
         params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
         params2.data[0] = array2;
         params2.data[1] = array3;
         params2.data[2] = array5;
         params2.data[3] = array9;
         params2.data[4] = array10;
         params2.data[5] = array11;
         params2.data[6] = array13;
         array_t* array14 = func6(&params2, rng(), loopsFactor);
         DEBUG_RETURN(array14->id);
         free(params2.data);
         array_t* array27;
         if (pCounter > 0) {
            array27 = vars->data[--pCounter];
            array27->refC++;
            DEBUG_COPY(array27->id);
         } else {
            array27 = (array_t*)malloc(sizeof(array_t));
            array27->size = 582;
            array27->refC = 1;
            array27->id = 27;
            array27->data = (unsigned int*)malloc(array27->size*sizeof(unsigned int));
            memset(array27->data, 0, array27->size*sizeof(unsigned int));
            DEBUG_NEW(array27->id);
         }
         if(PATH0 & 4) {
            unsigned int loop6 = 0;
            unsigned int loopLimit6 = (rand()%loopsFactor)/2 + 1;
            for(; loop6 < loopLimit6; loop6++) {
               for (int i = 0; i < array2->size; i++) {
                  if (array2->data[i] == 14) { 
                     return array2;
                  }
               }
               array_t* array28;
               if (pCounter > 0) {
                  array28 = vars->data[--pCounter];
                  array28->refC++;
                  DEBUG_COPY(array28->id);
               } else {
                  array28 = (array_t*)malloc(sizeof(array_t));
                  array28->size = 367;
                  array28->refC = 1;
                  array28->id = 28;
                  array28->data = (unsigned int*)malloc(array28->size*sizeof(unsigned int));
                  memset(array28->data, 0, array28->size*sizeof(unsigned int));
                  DEBUG_NEW(array28->id);
               }
               array_t_param params3;
               params3.size = 10;
               params3.data = (array_t**)malloc(params3.size*sizeof(array_t*));
               params3.data[0] = array2;
               params3.data[1] = array3;
               params3.data[2] = array5;
               params3.data[3] = array9;
               params3.data[4] = array10;
               params3.data[5] = array11;
               params3.data[6] = array13;
               params3.data[7] = array14;
               params3.data[8] = array27;
               params3.data[9] = array28;
               array_t* array29 = func12(&params3, loopsFactor);
               DEBUG_RETURN(array29->id);
               free(params3.data);
               array_t* array30;
               if (pCounter > 0) {
                  array30 = vars->data[--pCounter];
                  array30->refC++;
                  DEBUG_COPY(array30->id);
               } else {
                  array30 = (array_t*)malloc(sizeof(array_t));
                  array30->size = 43;
                  array30->refC = 1;
                  array30->id = 30;
                  array30->data = (unsigned int*)malloc(array30->size*sizeof(unsigned int));
                  memset(array30->data, 0, array30->size*sizeof(unsigned int));
                  DEBUG_NEW(array30->id);
               }
               if(PATH0 & 8) {
                  unsigned int loop7 = 0;
                  unsigned int loopLimit7 = (rand()%loopsFactor)/3 + 1;
                  for(; loop7 < loopLimit7; loop7++) {
                  }
               }
               else {
                  array_t* array31;
                  if (pCounter > 0) {
                     array31 = vars->data[--pCounter];
                     array31->refC++;
                     DEBUG_COPY(array31->id);
                  } else {
                     array31 = (array_t*)malloc(sizeof(array_t));
                     array31->size = 750;
                     array31->refC = 1;
                     array31->id = 31;
                     array31->data = (unsigned int*)malloc(array31->size*sizeof(unsigned int));
                     memset(array31->data, 0, array31->size*sizeof(unsigned int));
                     DEBUG_NEW(array31->id);
                  }
                  array_t_param params4;
                  params4.size = 13;
                  params4.data = (array_t**)malloc(params4.size*sizeof(array_t*));
                  params4.data[0] = array2;
                  params4.data[1] = array3;
                  params4.data[2] = array5;
                  params4.data[3] = array9;
                  params4.data[4] = array10;
                  params4.data[5] = array11;
                  params4.data[6] = array13;
                  params4.data[7] = array14;
                  params4.data[8] = array27;
                  params4.data[9] = array28;
                  params4.data[10] = array29;
                  params4.data[11] = array30;
                  params4.data[12] = array31;
                  array_t* array32 = func13(&params4, loopsFactor);
                  DEBUG_RETURN(array32->id);
                  free(params4.data);
                  array32->refC--;
                  if(array32->refC == 0) {
                     free(array32->data);
                     free(array32);
                     DEBUG_FREE(array32->id);
                  }
                  array31->refC--;
                  if(array31->refC == 0) {
                     free(array31->data);
                     free(array31);
                     DEBUG_FREE(array31->id);
                  }
               }
               for (int i = 0; i < array2->size; i++) {
                  if (array2->data[i] == 78) { 
                     return array2;
                  }
               }
               array_t* array33;
               if (pCounter > 0) {
                  array33 = vars->data[--pCounter];
                  array33->refC++;
                  DEBUG_COPY(array33->id);
               } else {
                  array33 = (array_t*)malloc(sizeof(array_t));
                  array33->size = 788;
                  array33->refC = 1;
                  array33->id = 33;
                  array33->data = (unsigned int*)malloc(array33->size*sizeof(unsigned int));
                  memset(array33->data, 0, array33->size*sizeof(unsigned int));
                  DEBUG_NEW(array33->id);
               }
               array_t* array34;
               if (pCounter > 0) {
                  array34 = vars->data[--pCounter];
                  array34->refC++;
                  DEBUG_COPY(array34->id);
               } else {
                  array34 = (array_t*)malloc(sizeof(array_t));
                  array34->size = 584;
                  array34->refC = 1;
                  array34->id = 34;
                  array34->data = (unsigned int*)malloc(array34->size*sizeof(unsigned int));
                  memset(array34->data, 0, array34->size*sizeof(unsigned int));
                  DEBUG_NEW(array34->id);
               }
               for (int i = 0; i < array14->size; i++) {
                  array14->data[i]++;
               }
               unsigned int loop8 = 0;
               unsigned int loopLimit8 = (rand()%loopsFactor)/3 + 1;
               for(; loop8 < loopLimit8; loop8++) {
                  for (int i = 0; i < array28->size; i++) {
                     array28->data[i]--;
                  }
               }
               array_t_param params4;
               params4.size = 14;
               params4.data = (array_t**)malloc(params4.size*sizeof(array_t*));
               params4.data[0] = array2;
               params4.data[1] = array3;
               params4.data[2] = array5;
               params4.data[3] = array9;
               params4.data[4] = array10;
               params4.data[5] = array11;
               params4.data[6] = array13;
               params4.data[7] = array14;
               params4.data[8] = array27;
               params4.data[9] = array28;
               params4.data[10] = array29;
               params4.data[11] = array30;
               params4.data[12] = array33;
               params4.data[13] = array34;
               array_t* array35 = func14(&params4, loopsFactor);
               DEBUG_RETURN(array35->id);
               free(params4.data);
               array35->refC--;
               if(array35->refC == 0) {
                  free(array35->data);
                  free(array35);
                  DEBUG_FREE(array35->id);
               }
               array34->refC--;
               if(array34->refC == 0) {
                  free(array34->data);
                  free(array34);
                  DEBUG_FREE(array34->id);
               }
               array33->refC--;
               if(array33->refC == 0) {
                  free(array33->data);
                  free(array33);
                  DEBUG_FREE(array33->id);
               }
               array30->refC--;
               if(array30->refC == 0) {
                  free(array30->data);
                  free(array30);
                  DEBUG_FREE(array30->id);
               }
               array29->refC--;
               if(array29->refC == 0) {
                  free(array29->data);
                  free(array29);
                  DEBUG_FREE(array29->id);
               }
               array28->refC--;
               if(array28->refC == 0) {
                  free(array28->data);
                  free(array28);
                  DEBUG_FREE(array28->id);
               }
            }
         }
         else {
            array_t* array36;
            if (pCounter > 0) {
               array36 = vars->data[--pCounter];
               array36->refC++;
               DEBUG_COPY(array36->id);
            } else {
               array36 = (array_t*)malloc(sizeof(array_t));
               array36->size = 932;
               array36->refC = 1;
               array36->id = 36;
               array36->data = (unsigned int*)malloc(array36->size*sizeof(unsigned int));
               memset(array36->data, 0, array36->size*sizeof(unsigned int));
               DEBUG_NEW(array36->id);
            }
            array_t* array37;
            if (pCounter > 0) {
               array37 = vars->data[--pCounter];
               array37->refC++;
               DEBUG_COPY(array37->id);
            } else {
               array37 = (array_t*)malloc(sizeof(array_t));
               array37->size = 60;
               array37->refC = 1;
               array37->id = 37;
               array37->data = (unsigned int*)malloc(array37->size*sizeof(unsigned int));
               memset(array37->data, 0, array37->size*sizeof(unsigned int));
               DEBUG_NEW(array37->id);
            }
            array_t* array38;
            if (pCounter > 0) {
               array38 = vars->data[--pCounter];
               array38->refC++;
               DEBUG_COPY(array38->id);
            } else {
               array38 = (array_t*)malloc(sizeof(array_t));
               array38->size = 676;
               array38->refC = 1;
               array38->id = 38;
               array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
               memset(array38->data, 0, array38->size*sizeof(unsigned int));
               DEBUG_NEW(array38->id);
            }
            for (int i = 0; i < array2->size; i++) {
               array2->data[i]++;
            }
            unsigned int loop9 = 0;
            unsigned int loopLimit9 = (rand()%loopsFactor)/2 + 1;
            for(; loop9 < loopLimit9; loop9++) {
               for (int i = 0; i < array14->size; i++) {
                  array14->data[i]--;
               }
            }
            array_t_param params3;
            params3.size = 12;
            params3.data = (array_t**)malloc(params3.size*sizeof(array_t*));
            params3.data[0] = array2;
            params3.data[1] = array3;
            params3.data[2] = array5;
            params3.data[3] = array9;
            params3.data[4] = array10;
            params3.data[5] = array11;
            params3.data[6] = array13;
            params3.data[7] = array14;
            params3.data[8] = array27;
            params3.data[9] = array36;
            params3.data[10] = array37;
            params3.data[11] = array38;
            array_t* array39 = func10(&params3, loopsFactor);
            DEBUG_RETURN(array39->id);
            free(params3.data);
            array_t_param params4;
            params4.size = 13;
            params4.data = (array_t**)malloc(params4.size*sizeof(array_t*));
            params4.data[0] = array2;
            params4.data[1] = array3;
            params4.data[2] = array5;
            params4.data[3] = array9;
            params4.data[4] = array10;
            params4.data[5] = array11;
            params4.data[6] = array13;
            params4.data[7] = array14;
            params4.data[8] = array27;
            params4.data[9] = array36;
            params4.data[10] = array37;
            params4.data[11] = array38;
            params4.data[12] = array39;
            array_t* array40 = func7(&params4, loopsFactor);
            DEBUG_RETURN(array40->id);
            free(params4.data);
            array40->refC--;
            if(array40->refC == 0) {
               free(array40->data);
               free(array40);
               DEBUG_FREE(array40->id);
            }
            array39->refC--;
            if(array39->refC == 0) {
               free(array39->data);
               free(array39);
               DEBUG_FREE(array39->id);
            }
            array38->refC--;
            if(array38->refC == 0) {
               free(array38->data);
               free(array38);
               DEBUG_FREE(array38->id);
            }
            array37->refC--;
            if(array37->refC == 0) {
               free(array37->data);
               free(array37);
               DEBUG_FREE(array37->id);
            }
            array36->refC--;
            if(array36->refC == 0) {
               free(array36->data);
               free(array36);
               DEBUG_FREE(array36->id);
            }
         }
         for (int i = 0; i < array10->size; i++) {
            if (array10->data[i] == 29) { 
               return array10;
            }
         }
         array_t* array49;
         if (pCounter > 0) {
            array49 = vars->data[--pCounter];
            array49->refC++;
            DEBUG_COPY(array49->id);
         } else {
            array49 = (array_t*)malloc(sizeof(array_t));
            array49->size = 31;
            array49->refC = 1;
            array49->id = 49;
            array49->data = (unsigned int*)malloc(array49->size*sizeof(unsigned int));
            memset(array49->data, 0, array49->size*sizeof(unsigned int));
            DEBUG_NEW(array49->id);
         }
         array_t* array50;
         if (pCounter > 0) {
            array50 = vars->data[--pCounter];
            array50->refC++;
            DEBUG_COPY(array50->id);
         } else {
            array50 = (array_t*)malloc(sizeof(array_t));
            array50->size = 117;
            array50->refC = 1;
            array50->id = 50;
            array50->data = (unsigned int*)malloc(array50->size*sizeof(unsigned int));
            memset(array50->data, 0, array50->size*sizeof(unsigned int));
            DEBUG_NEW(array50->id);
         }
         for (int i = 0; i < array50->size; i++) {
            array50->data[i]++;
         }
         unsigned int loop12 = 0;
         unsigned int loopLimit12 = (rand()%loopsFactor)/2 + 1;
         for(; loop12 < loopLimit12; loop12++) {
            for (int i = 0; i < array9->size; i++) {
               array9->data[i]--;
            }
         }
         array_t_param params3;
         params3.size = 11;
         params3.data = (array_t**)malloc(params3.size*sizeof(array_t*));
         params3.data[0] = array2;
         params3.data[1] = array3;
         params3.data[2] = array5;
         params3.data[3] = array9;
         params3.data[4] = array10;
         params3.data[5] = array11;
         params3.data[6] = array13;
         params3.data[7] = array14;
         params3.data[8] = array27;
         params3.data[9] = array49;
         params3.data[10] = array50;
         array_t* array51 = func8(&params3, rng(), loopsFactor);
         DEBUG_RETURN(array51->id);
         free(params3.data);
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
         array49->refC--;
         if(array49->refC == 0) {
            free(array49->data);
            free(array49);
            DEBUG_FREE(array49->id);
         }
         array27->refC--;
         if(array27->refC == 0) {
            free(array27->data);
            free(array27);
            DEBUG_FREE(array27->id);
         }
         array14->refC--;
         if(array14->refC == 0) {
            free(array14->data);
            free(array14);
            DEBUG_FREE(array14->id);
         }
         array13->refC--;
         if(array13->refC == 0) {
            free(array13->data);
            free(array13);
            DEBUG_FREE(array13->id);
         }
         array11->refC--;
         if(array11->refC == 0) {
            free(array11->data);
            free(array11);
            DEBUG_FREE(array11->id);
         }
         array10->refC--;
         if(array10->refC == 0) {
            free(array10->data);
            free(array10);
            DEBUG_FREE(array10->id);
         }
         array9->refC--;
         if(array9->refC == 0) {
            free(array9->data);
            free(array9);
            DEBUG_FREE(array9->id);
         }
         array5->refC--;
         if(array5->refC == 0) {
            free(array5->data);
            free(array5);
            DEBUG_FREE(array5->id);
         }
         array3->refC--;
         if(array3->refC == 0) {
            free(array3->data);
            free(array3);
            DEBUG_FREE(array3->id);
         }
         array2->refC--;
         if(array2->refC == 0) {
            free(array2->data);
            free(array2);
            DEBUG_FREE(array2->id);
         }
      }
   }
   else {
      array_t* array60;
      if (pCounter > 0) {
         array60 = vars->data[--pCounter];
         array60->refC++;
         DEBUG_COPY(array60->id);
      } else {
         array60 = (array_t*)malloc(sizeof(array_t));
         array60->size = 708;
         array60->refC = 1;
         array60->id = 60;
         array60->data = (unsigned int*)malloc(array60->size*sizeof(unsigned int));
         memset(array60->data, 0, array60->size*sizeof(unsigned int));
         DEBUG_NEW(array60->id);
      }
      array_t* array61;
      if (pCounter > 0) {
         array61 = vars->data[--pCounter];
         array61->refC++;
         DEBUG_COPY(array61->id);
      } else {
         array61 = (array_t*)malloc(sizeof(array_t));
         array61->size = 715;
         array61->refC = 1;
         array61->id = 61;
         array61->data = (unsigned int*)malloc(array61->size*sizeof(unsigned int));
         memset(array61->data, 0, array61->size*sizeof(unsigned int));
         DEBUG_NEW(array61->id);
      }
      array_t* array62;
      if (pCounter > 0) {
         array62 = vars->data[--pCounter];
         array62->refC++;
         DEBUG_COPY(array62->id);
      } else {
         array62 = (array_t*)malloc(sizeof(array_t));
         array62->size = 340;
         array62->refC = 1;
         array62->id = 62;
         array62->data = (unsigned int*)malloc(array62->size*sizeof(unsigned int));
         memset(array62->data, 0, array62->size*sizeof(unsigned int));
         DEBUG_NEW(array62->id);
      }
      for (int i = 0; i < array60->size; i++) {
         array60->data[i]++;
      }
      unsigned int loop15 = 0;
      unsigned int loopLimit15 = (rand()%loopsFactor)/1 + 1;
      for(; loop15 < loopLimit15; loop15++) {
         for (int i = 0; i < array60->size; i++) {
            array60->data[i]--;
         }
      }
      array_t_param params0;
      params0.size = 3;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      params0.data[0] = array60;
      params0.data[1] = array61;
      params0.data[2] = array62;
      array_t* array63 = func4(&params0, rng(), loopsFactor);
      DEBUG_RETURN(array63->id);
      free(params0.data);
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array60;
      params1.data[1] = array61;
      params1.data[2] = array62;
      params1.data[3] = array63;
      array_t* array77 = func2(&params1, rng(), loopsFactor);
      DEBUG_RETURN(array77->id);
      free(params1.data);
      array77->refC--;
      if(array77->refC == 0) {
         free(array77->data);
         free(array77);
         DEBUG_FREE(array77->id);
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
      array61->refC--;
      if(array61->refC == 0) {
         free(array61->data);
         free(array61);
         DEBUG_FREE(array61->id);
      }
      array60->refC--;
      if(array60->refC == 0) {
         free(array60->data);
         free(array60);
         DEBUG_FREE(array60->id);
      }
   }
   array_t* array109;
   if (pCounter > 0) {
      array109 = vars->data[--pCounter];
      array109->refC++;
      DEBUG_COPY(array109->id);
   } else {
      array109 = (array_t*)malloc(sizeof(array_t));
      array109->size = 305;
      array109->refC = 1;
      array109->id = 109;
      array109->data = (unsigned int*)malloc(array109->size*sizeof(unsigned int));
      memset(array109->data, 0, array109->size*sizeof(unsigned int));
      DEBUG_NEW(array109->id);
   }
   return array109;
}

