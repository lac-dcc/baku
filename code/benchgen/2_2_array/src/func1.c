#include "outs/2_2_array.h" 
array_t* func1(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop8 = 0;
   unsigned int loopLimit8 = (rand()%loopsFactor)/1 + 1;
   for(; loop8 < loopLimit8; loop8++) {
      array_t* array38;
      if (pCounter > 0) {
         array38 = vars->data[--pCounter];
         array38->refC++;
         DEBUG_COPY(array38->id);
      } else {
         array38 = (array_t*)malloc(sizeof(array_t));
         array38->size = 434;
         array38->refC = 1;
         array38->id = 38;
         array38->data = (unsigned int*)malloc(array38->size*sizeof(unsigned int));
         memset(array38->data, 0, array38->size*sizeof(unsigned int));
         DEBUG_NEW(array38->id);
      }
      if(PATH0 & 1) {
         array_t* array39;
         if (pCounter > 0) {
            array39 = vars->data[--pCounter];
            array39->refC++;
            DEBUG_COPY(array39->id);
         } else {
            array39 = (array_t*)malloc(sizeof(array_t));
            array39->size = 378;
            array39->refC = 1;
            array39->id = 39;
            array39->data = (unsigned int*)malloc(array39->size*sizeof(unsigned int));
            memset(array39->data, 0, array39->size*sizeof(unsigned int));
            DEBUG_NEW(array39->id);
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array38;
         params0.data[1] = array39;
         array_t* array40 = func8(&params0, loopsFactor);
         DEBUG_RETURN(array40->id);
         free(params0.data);
         array_t* array41;
         if (pCounter > 0) {
            array41 = vars->data[--pCounter];
            array41->refC++;
            DEBUG_COPY(array41->id);
         } else {
            array41 = (array_t*)malloc(sizeof(array_t));
            array41->size = 97;
            array41->refC = 1;
            array41->id = 41;
            array41->data = (unsigned int*)malloc(array41->size*sizeof(unsigned int));
            memset(array41->data, 0, array41->size*sizeof(unsigned int));
            DEBUG_NEW(array41->id);
         }
         array_t* array42;
         if (pCounter > 0) {
            array42 = vars->data[--pCounter];
            array42->refC++;
            DEBUG_COPY(array42->id);
         } else {
            array42 = (array_t*)malloc(sizeof(array_t));
            array42->size = 902;
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
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array38;
         array_t* array43 = func9(&params0, loopsFactor);
         DEBUG_RETURN(array43->id);
         free(params0.data);
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
         array43->refC--;
         if(array43->refC == 0) {
            free(array43->data);
            free(array43);
            DEBUG_FREE(array43->id);
         }
      }
      if(PATH0 & 2) {
         array_t* array45;
         if (pCounter > 0) {
            array45 = vars->data[--pCounter];
            array45->refC++;
            DEBUG_COPY(array45->id);
         } else {
            array45 = (array_t*)malloc(sizeof(array_t));
            array45->size = 756;
            array45->refC = 1;
            array45->id = 45;
            array45->data = (unsigned int*)malloc(array45->size*sizeof(unsigned int));
            memset(array45->data, 0, array45->size*sizeof(unsigned int));
            DEBUG_NEW(array45->id);
         }
         unsigned int loop9 = 0;
         unsigned int loopLimit9 = (rand()%loopsFactor)/2 + 1;
         for(; loop9 < loopLimit9; loop9++) {
            for (int i = 0; i < array45->size; i++) {
               array45->data[i]++;
            }
            for (int i = 0; i < array38->size; i++) {
               if (array38->data[i] == 86) { 
                  return array38;
               }
            }
            if(PATH0 & 4) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array38;
               params0.data[1] = array45;
               array_t* array46 = func7(&params0, loopsFactor);
               DEBUG_RETURN(array46->id);
               free(params0.data);
               array_t* array47;
               if (pCounter > 0) {
                  array47 = vars->data[--pCounter];
                  array47->refC++;
                  DEBUG_COPY(array47->id);
               } else {
                  array47 = (array_t*)malloc(sizeof(array_t));
                  array47->size = 689;
                  array47->refC = 1;
                  array47->id = 47;
                  array47->data = (unsigned int*)malloc(array47->size*sizeof(unsigned int));
                  memset(array47->data, 0, array47->size*sizeof(unsigned int));
                  DEBUG_NEW(array47->id);
               }
               array47->refC--;
               if(array47->refC == 0) {
                  free(array47->data);
                  free(array47);
                  DEBUG_FREE(array47->id);
               }
               array46->refC--;
               if(array46->refC == 0) {
                  free(array46->data);
                  free(array46);
                  DEBUG_FREE(array46->id);
               }
            }
            else {
            }
         }
         array_t* array48;
         if (pCounter > 0) {
            array48 = vars->data[--pCounter];
            array48->refC++;
            DEBUG_COPY(array48->id);
         } else {
            array48 = (array_t*)malloc(sizeof(array_t));
            array48->size = 444;
            array48->refC = 1;
            array48->id = 48;
            array48->data = (unsigned int*)malloc(array48->size*sizeof(unsigned int));
            memset(array48->data, 0, array48->size*sizeof(unsigned int));
            DEBUG_NEW(array48->id);
         }
         array48->refC--;
         if(array48->refC == 0) {
            free(array48->data);
            free(array48);
            DEBUG_FREE(array48->id);
         }
         array45->refC--;
         if(array45->refC == 0) {
            free(array45->data);
            free(array45);
            DEBUG_FREE(array45->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array38;
         array_t* array49 = func10(&params0, loopsFactor);
         DEBUG_RETURN(array49->id);
         free(params0.data);
         for (int i = 0; i < array49->size; i++) {
            if (array49->data[i] == 31) { 
               return array49;
            }
         }
         unsigned int loop10 = 0;
         unsigned int loopLimit10 = (rand()%loopsFactor)/2 + 1;
         for(; loop10 < loopLimit10; loop10++) {
            for (int i = 0; i < array49->size; i++) {
               array49->data[i]--;
            }
            for (int i = 0; i < array49->size; i++) {
               if (array49->data[i] == 71) { 
                  return array49;
               }
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array38;
         params1.data[1] = array49;
         array_t* array50 = func11(&params1, loopsFactor);
         DEBUG_RETURN(array50->id);
         free(params1.data);
         array_t* array51;
         if (pCounter > 0) {
            array51 = vars->data[--pCounter];
            array51->refC++;
            DEBUG_COPY(array51->id);
         } else {
            array51 = (array_t*)malloc(sizeof(array_t));
            array51->size = 709;
            array51->refC = 1;
            array51->id = 51;
            array51->data = (unsigned int*)malloc(array51->size*sizeof(unsigned int));
            memset(array51->data, 0, array51->size*sizeof(unsigned int));
            DEBUG_NEW(array51->id);
         }
         array_t* array52;
         if (pCounter > 0) {
            array52 = vars->data[--pCounter];
            array52->refC++;
            DEBUG_COPY(array52->id);
         } else {
            array52 = (array_t*)malloc(sizeof(array_t));
            array52->size = 927;
            array52->refC = 1;
            array52->id = 52;
            array52->data = (unsigned int*)malloc(array52->size*sizeof(unsigned int));
            memset(array52->data, 0, array52->size*sizeof(unsigned int));
            DEBUG_NEW(array52->id);
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
         array49->refC--;
         if(array49->refC == 0) {
            free(array49->data);
            free(array49);
            DEBUG_FREE(array49->id);
         }
      }
      for (int i = 0; i < array38->size; i++) {
         if (array38->data[i] == 56) { 
            return array38;
         }
      }
      array_t* array53;
      if (pCounter > 0) {
         array53 = vars->data[--pCounter];
         array53->refC++;
         DEBUG_COPY(array53->id);
      } else {
         array53 = (array_t*)malloc(sizeof(array_t));
         array53->size = 497;
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
      array38->refC--;
      if(array38->refC == 0) {
         free(array38->data);
         free(array38);
         DEBUG_FREE(array38->id);
      }
   }
   unsigned int loop11 = 0;
   unsigned int loopLimit11 = (rand()%loopsFactor)/1 + 1;
   for(; loop11 < loopLimit11; loop11++) {
      if(PATH0 & 8) {
         array_t* array54;
         if (pCounter > 0) {
            array54 = vars->data[--pCounter];
            array54->refC++;
            DEBUG_COPY(array54->id);
         } else {
            array54 = (array_t*)malloc(sizeof(array_t));
            array54->size = 353;
            array54->refC = 1;
            array54->id = 54;
            array54->data = (unsigned int*)malloc(array54->size*sizeof(unsigned int));
            memset(array54->data, 0, array54->size*sizeof(unsigned int));
            DEBUG_NEW(array54->id);
         }
         unsigned int loop12 = 0;
         unsigned int loopLimit12 = (rand()%loopsFactor)/2 + 1;
         for(; loop12 < loopLimit12; loop12++) {
            array_t* array55;
            if (pCounter > 0) {
               array55 = vars->data[--pCounter];
               array55->refC++;
               DEBUG_COPY(array55->id);
            } else {
               array55 = (array_t*)malloc(sizeof(array_t));
               array55->size = 586;
               array55->refC = 1;
               array55->id = 55;
               array55->data = (unsigned int*)malloc(array55->size*sizeof(unsigned int));
               memset(array55->data, 0, array55->size*sizeof(unsigned int));
               DEBUG_NEW(array55->id);
            }
            if(PATH0 & 16) {
            }
            else {
            }
            for (int i = 0; i < array55->size; i++) {
               if (array55->data[i] == 6) { 
                  return array55;
               }
            }
            array_t* array56;
            if (pCounter > 0) {
               array56 = vars->data[--pCounter];
               array56->refC++;
               DEBUG_COPY(array56->id);
            } else {
               array56 = (array_t*)malloc(sizeof(array_t));
               array56->size = 683;
               array56->refC = 1;
               array56->id = 56;
               array56->data = (unsigned int*)malloc(array56->size*sizeof(unsigned int));
               memset(array56->data, 0, array56->size*sizeof(unsigned int));
               DEBUG_NEW(array56->id);
            }
            array56->refC--;
            if(array56->refC == 0) {
               free(array56->data);
               free(array56);
               DEBUG_FREE(array56->id);
            }
            array55->refC--;
            if(array55->refC == 0) {
               free(array55->data);
               free(array55);
               DEBUG_FREE(array55->id);
            }
         }
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array54;
         array_t* array57 = func5(&params0, loopsFactor);
         DEBUG_RETURN(array57->id);
         free(params0.data);
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
         unsigned int loop14 = 0;
         unsigned int loopLimit14 = (rand()%loopsFactor)/2 + 1;
         for(; loop14 < loopLimit14; loop14++) {
            for (int i = 0; i < array62->size; i++) {
               array62->data[i]++;
            }
            for (int i = 0; i < array63->size; i++) {
               if (array63->data[i] == 21) { 
                  return array63;
               }
            }
            if(PATH0 & 32) {
               array_t_param params1;
               params1.size = 4;
               params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
               params1.data[0] = array54;
               params1.data[1] = array57;
               params1.data[2] = array62;
               params1.data[3] = array63;
               array_t* array64 = func7(&params1, loopsFactor);
               DEBUG_RETURN(array64->id);
               free(params1.data);
               array_t* array65;
               if (pCounter > 0) {
                  array65 = vars->data[--pCounter];
                  array65->refC++;
                  DEBUG_COPY(array65->id);
               } else {
                  array65 = (array_t*)malloc(sizeof(array_t));
                  array65->size = 488;
                  array65->refC = 1;
                  array65->id = 65;
                  array65->data = (unsigned int*)malloc(array65->size*sizeof(unsigned int));
                  memset(array65->data, 0, array65->size*sizeof(unsigned int));
                  DEBUG_NEW(array65->id);
               }
               array65->refC--;
               if(array65->refC == 0) {
                  free(array65->data);
                  free(array65);
                  DEBUG_FREE(array65->id);
               }
               array64->refC--;
               if(array64->refC == 0) {
                  free(array64->data);
                  free(array64);
                  DEBUG_FREE(array64->id);
               }
            }
            else {
            }
         }
         array_t* array66;
         if (pCounter > 0) {
            array66 = vars->data[--pCounter];
            array66->refC++;
            DEBUG_COPY(array66->id);
         } else {
            array66 = (array_t*)malloc(sizeof(array_t));
            array66->size = 764;
            array66->refC = 1;
            array66->id = 66;
            array66->data = (unsigned int*)malloc(array66->size*sizeof(unsigned int));
            memset(array66->data, 0, array66->size*sizeof(unsigned int));
            DEBUG_NEW(array66->id);
         }
         array_t* array67;
         if (pCounter > 0) {
            array67 = vars->data[--pCounter];
            array67->refC++;
            DEBUG_COPY(array67->id);
         } else {
            array67 = (array_t*)malloc(sizeof(array_t));
            array67->size = 228;
            array67->refC = 1;
            array67->id = 67;
            array67->data = (unsigned int*)malloc(array67->size*sizeof(unsigned int));
            memset(array67->data, 0, array67->size*sizeof(unsigned int));
            DEBUG_NEW(array67->id);
         }
         array67->refC--;
         if(array67->refC == 0) {
            free(array67->data);
            free(array67);
            DEBUG_FREE(array67->id);
         }
         array66->refC--;
         if(array66->refC == 0) {
            free(array66->data);
            free(array66);
            DEBUG_FREE(array66->id);
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
         array57->refC--;
         if(array57->refC == 0) {
            free(array57->data);
            free(array57);
            DEBUG_FREE(array57->id);
         }
         array54->refC--;
         if(array54->refC == 0) {
            free(array54->data);
            free(array54);
            DEBUG_FREE(array54->id);
         }
      }
      else {
         if(PATH0 & 64) {
            array_t* array68;
            if (pCounter > 0) {
               array68 = vars->data[--pCounter];
               array68->refC++;
               DEBUG_COPY(array68->id);
            } else {
               array68 = (array_t*)malloc(sizeof(array_t));
               array68->size = 841;
               array68->refC = 1;
               array68->id = 68;
               array68->data = (unsigned int*)malloc(array68->size*sizeof(unsigned int));
               memset(array68->data, 0, array68->size*sizeof(unsigned int));
               DEBUG_NEW(array68->id);
            }
            array_t_param params0;
            params0.size = 1;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array68;
            array_t* array69 = func8(&params0, loopsFactor);
            DEBUG_RETURN(array69->id);
            free(params0.data);
            array_t* array70;
            if (pCounter > 0) {
               array70 = vars->data[--pCounter];
               array70->refC++;
               DEBUG_COPY(array70->id);
            } else {
               array70 = (array_t*)malloc(sizeof(array_t));
               array70->size = 500;
               array70->refC = 1;
               array70->id = 70;
               array70->data = (unsigned int*)malloc(array70->size*sizeof(unsigned int));
               memset(array70->data, 0, array70->size*sizeof(unsigned int));
               DEBUG_NEW(array70->id);
            }
            array_t* array71;
            if (pCounter > 0) {
               array71 = vars->data[--pCounter];
               array71->refC++;
               DEBUG_COPY(array71->id);
            } else {
               array71 = (array_t*)malloc(sizeof(array_t));
               array71->size = 34;
               array71->refC = 1;
               array71->id = 71;
               array71->data = (unsigned int*)malloc(array71->size*sizeof(unsigned int));
               memset(array71->data, 0, array71->size*sizeof(unsigned int));
               DEBUG_NEW(array71->id);
            }
            array71->refC--;
            if(array71->refC == 0) {
               free(array71->data);
               free(array71);
               DEBUG_FREE(array71->id);
            }
            array70->refC--;
            if(array70->refC == 0) {
               free(array70->data);
               free(array70);
               DEBUG_FREE(array70->id);
            }
            array69->refC--;
            if(array69->refC == 0) {
               free(array69->data);
               free(array69);
               DEBUG_FREE(array69->id);
            }
            array68->refC--;
            if(array68->refC == 0) {
               free(array68->data);
               free(array68);
               DEBUG_FREE(array68->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 0;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            array_t* array72 = func9(&params0, loopsFactor);
            DEBUG_RETURN(array72->id);
            free(params0.data);
            array_t* array73;
            if (pCounter > 0) {
               array73 = vars->data[--pCounter];
               array73->refC++;
               DEBUG_COPY(array73->id);
            } else {
               array73 = (array_t*)malloc(sizeof(array_t));
               array73->size = 914;
               array73->refC = 1;
               array73->id = 73;
               array73->data = (unsigned int*)malloc(array73->size*sizeof(unsigned int));
               memset(array73->data, 0, array73->size*sizeof(unsigned int));
               DEBUG_NEW(array73->id);
            }
            array73->refC--;
            if(array73->refC == 0) {
               free(array73->data);
               free(array73);
               DEBUG_FREE(array73->id);
            }
            array72->refC--;
            if(array72->refC == 0) {
               free(array72->data);
               free(array72);
               DEBUG_FREE(array72->id);
            }
         }
         array_t_param params0;
         params0.size = 0;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         array_t* array74 = func6(&params0, rng(), loopsFactor);
         DEBUG_RETURN(array74->id);
         free(params0.data);
         array_t* array78;
         if (pCounter > 0) {
            array78 = vars->data[--pCounter];
            array78->refC++;
            DEBUG_COPY(array78->id);
         } else {
            array78 = (array_t*)malloc(sizeof(array_t));
            array78->size = 228;
            array78->refC = 1;
            array78->id = 78;
            array78->data = (unsigned int*)malloc(array78->size*sizeof(unsigned int));
            memset(array78->data, 0, array78->size*sizeof(unsigned int));
            DEBUG_NEW(array78->id);
         }
         array78->refC--;
         if(array78->refC == 0) {
            free(array78->data);
            free(array78);
            DEBUG_FREE(array78->id);
         }
         array74->refC--;
         if(array74->refC == 0) {
            free(array74->data);
            free(array74);
            DEBUG_FREE(array74->id);
         }
      }
   }
   array_t* array79;
   if (pCounter > 0) {
      array79 = vars->data[--pCounter];
      array79->refC++;
      DEBUG_COPY(array79->id);
   } else {
      array79 = (array_t*)malloc(sizeof(array_t));
      array79->size = 275;
      array79->refC = 1;
      array79->id = 79;
      array79->data = (unsigned int*)malloc(array79->size*sizeof(unsigned int));
      memset(array79->data, 0, array79->size*sizeof(unsigned int));
      DEBUG_NEW(array79->id);
   }
   return array79;
}

