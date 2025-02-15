#include "outs/5_2_array.h" 
array_t* func13(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array85;
   if (pCounter > 0) {
      array85 = vars->data[--pCounter];
      array85->refC++;
      DEBUG_COPY(array85->id);
   } else {
      array85 = (array_t*)malloc(sizeof(array_t));
      array85->size = 529;
      array85->refC = 1;
      array85->id = 85;
      array85->data = (unsigned int*)malloc(array85->size*sizeof(unsigned int));
      memset(array85->data, 0, array85->size*sizeof(unsigned int));
      DEBUG_NEW(array85->id);
   }
   unsigned int loop17 = 0;
   unsigned int loopLimit17 = (rand()%loopsFactor)/3 + 1;
   for(; loop17 < loopLimit17; loop17++) {
      for (int i = 0; i < array85->size; i++) {
         array85->data[i]--;
      }
      unsigned int loop18 = 0;
      unsigned int loopLimit18 = (rand()%loopsFactor)/4 + 1;
      for(; loop18 < loopLimit18; loop18++) {
         array_t* array86;
         if (pCounter > 0) {
            array86 = vars->data[--pCounter];
            array86->refC++;
            DEBUG_COPY(array86->id);
         } else {
            array86 = (array_t*)malloc(sizeof(array_t));
            array86->size = 404;
            array86->refC = 1;
            array86->id = 86;
            array86->data = (unsigned int*)malloc(array86->size*sizeof(unsigned int));
            memset(array86->data, 0, array86->size*sizeof(unsigned int));
            DEBUG_NEW(array86->id);
         }
         if(PATH0 & 1) {
            array_t* array87;
            if (pCounter > 0) {
               array87 = vars->data[--pCounter];
               array87->refC++;
               DEBUG_COPY(array87->id);
            } else {
               array87 = (array_t*)malloc(sizeof(array_t));
               array87->size = 443;
               array87->refC = 1;
               array87->id = 87;
               array87->data = (unsigned int*)malloc(array87->size*sizeof(unsigned int));
               memset(array87->data, 0, array87->size*sizeof(unsigned int));
               DEBUG_NEW(array87->id);
            }
            array_t_param params0;
            params0.size = 3;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array85;
            params0.data[1] = array86;
            params0.data[2] = array87;
            array_t* array88 = func22(&params0, loopsFactor);
            DEBUG_RETURN(array88->id);
            free(params0.data);
            array_t* array89;
            if (pCounter > 0) {
               array89 = vars->data[--pCounter];
               array89->refC++;
               DEBUG_COPY(array89->id);
            } else {
               array89 = (array_t*)malloc(sizeof(array_t));
               array89->size = 538;
               array89->refC = 1;
               array89->id = 89;
               array89->data = (unsigned int*)malloc(array89->size*sizeof(unsigned int));
               memset(array89->data, 0, array89->size*sizeof(unsigned int));
               DEBUG_NEW(array89->id);
            }
            array_t* array90;
            if (pCounter > 0) {
               array90 = vars->data[--pCounter];
               array90->refC++;
               DEBUG_COPY(array90->id);
            } else {
               array90 = (array_t*)malloc(sizeof(array_t));
               array90->size = 606;
               array90->refC = 1;
               array90->id = 90;
               array90->data = (unsigned int*)malloc(array90->size*sizeof(unsigned int));
               memset(array90->data, 0, array90->size*sizeof(unsigned int));
               DEBUG_NEW(array90->id);
            }
            array90->refC--;
            if(array90->refC == 0) {
               free(array90->data);
               free(array90);
               DEBUG_FREE(array90->id);
            }
            array89->refC--;
            if(array89->refC == 0) {
               free(array89->data);
               free(array89);
               DEBUG_FREE(array89->id);
            }
            array88->refC--;
            if(array88->refC == 0) {
               free(array88->data);
               free(array88);
               DEBUG_FREE(array88->id);
            }
            array87->refC--;
            if(array87->refC == 0) {
               free(array87->data);
               free(array87);
               DEBUG_FREE(array87->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array85;
            params0.data[1] = array86;
            array_t* array91 = func23(&params0, loopsFactor);
            DEBUG_RETURN(array91->id);
            free(params0.data);
            array_t* array92;
            if (pCounter > 0) {
               array92 = vars->data[--pCounter];
               array92->refC++;
               DEBUG_COPY(array92->id);
            } else {
               array92 = (array_t*)malloc(sizeof(array_t));
               array92->size = 818;
               array92->refC = 1;
               array92->id = 92;
               array92->data = (unsigned int*)malloc(array92->size*sizeof(unsigned int));
               memset(array92->data, 0, array92->size*sizeof(unsigned int));
               DEBUG_NEW(array92->id);
            }
            array92->refC--;
            if(array92->refC == 0) {
               free(array92->data);
               free(array92);
               DEBUG_FREE(array92->id);
            }
            array91->refC--;
            if(array91->refC == 0) {
               free(array91->data);
               free(array91);
               DEBUG_FREE(array91->id);
            }
         }
         if(PATH0 & 2) {
            array_t* array93;
            if (pCounter > 0) {
               array93 = vars->data[--pCounter];
               array93->refC++;
               DEBUG_COPY(array93->id);
            } else {
               array93 = (array_t*)malloc(sizeof(array_t));
               array93->size = 128;
               array93->refC = 1;
               array93->id = 93;
               array93->data = (unsigned int*)malloc(array93->size*sizeof(unsigned int));
               memset(array93->data, 0, array93->size*sizeof(unsigned int));
               DEBUG_NEW(array93->id);
            }
            unsigned int loop19 = 0;
            unsigned int loopLimit19 = (rand()%loopsFactor)/5 + 1;
            for(; loop19 < loopLimit19; loop19++) {
               for (int i = 0; i < array85->size; i++) {
                  array85->data[i]++;
               }
               for (int i = 0; i < array85->size; i++) {
                  if (array85->data[i] == 17) { 
                     return array85;
                  }
               }
               if(PATH0 & 4) {
                  array_t_param params0;
                  params0.size = 3;
                  params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
                  params0.data[0] = array85;
                  params0.data[1] = array86;
                  params0.data[2] = array93;
                  array_t* array94 = func24(&params0, loopsFactor);
                  DEBUG_RETURN(array94->id);
                  free(params0.data);
                  array_t* array95;
                  if (pCounter > 0) {
                     array95 = vars->data[--pCounter];
                     array95->refC++;
                     DEBUG_COPY(array95->id);
                  } else {
                     array95 = (array_t*)malloc(sizeof(array_t));
                     array95->size = 324;
                     array95->refC = 1;
                     array95->id = 95;
                     array95->data = (unsigned int*)malloc(array95->size*sizeof(unsigned int));
                     memset(array95->data, 0, array95->size*sizeof(unsigned int));
                     DEBUG_NEW(array95->id);
                  }
                  array95->refC--;
                  if(array95->refC == 0) {
                     free(array95->data);
                     free(array95);
                     DEBUG_FREE(array95->id);
                  }
                  array94->refC--;
                  if(array94->refC == 0) {
                     free(array94->data);
                     free(array94);
                     DEBUG_FREE(array94->id);
                  }
               }
               else {
               }
            }
            array_t* array96;
            if (pCounter > 0) {
               array96 = vars->data[--pCounter];
               array96->refC++;
               DEBUG_COPY(array96->id);
            } else {
               array96 = (array_t*)malloc(sizeof(array_t));
               array96->size = 743;
               array96->refC = 1;
               array96->id = 96;
               array96->data = (unsigned int*)malloc(array96->size*sizeof(unsigned int));
               memset(array96->data, 0, array96->size*sizeof(unsigned int));
               DEBUG_NEW(array96->id);
            }
            array96->refC--;
            if(array96->refC == 0) {
               free(array96->data);
               free(array96);
               DEBUG_FREE(array96->id);
            }
            array93->refC--;
            if(array93->refC == 0) {
               free(array93->data);
               free(array93);
               DEBUG_FREE(array93->id);
            }
         }
         else {
            array_t_param params0;
            params0.size = 2;
            params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
            params0.data[0] = array85;
            params0.data[1] = array86;
            array_t* array97 = func25(&params0, loopsFactor);
            DEBUG_RETURN(array97->id);
            free(params0.data);
            for (int i = 0; i < array97->size; i++) {
               if (array97->data[i] == 99) { 
                  return array97;
               }
            }
            unsigned int loop20 = 0;
            unsigned int loopLimit20 = (rand()%loopsFactor)/5 + 1;
            for(; loop20 < loopLimit20; loop20++) {
               for (int i = 0; i < array86->size; i++) {
                  array86->data[i]--;
               }
               for (int i = 0; i < array97->size; i++) {
                  if (array97->data[i] == 44) { 
                     return array97;
                  }
               }
            }
            array_t_param params1;
            params1.size = 3;
            params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
            params1.data[0] = array85;
            params1.data[1] = array86;
            params1.data[2] = array97;
            array_t* array98 = func26(&params1, loopsFactor);
            DEBUG_RETURN(array98->id);
            free(params1.data);
            array_t* array99;
            if (pCounter > 0) {
               array99 = vars->data[--pCounter];
               array99->refC++;
               DEBUG_COPY(array99->id);
            } else {
               array99 = (array_t*)malloc(sizeof(array_t));
               array99->size = 139;
               array99->refC = 1;
               array99->id = 99;
               array99->data = (unsigned int*)malloc(array99->size*sizeof(unsigned int));
               memset(array99->data, 0, array99->size*sizeof(unsigned int));
               DEBUG_NEW(array99->id);
            }
            array_t* array100;
            if (pCounter > 0) {
               array100 = vars->data[--pCounter];
               array100->refC++;
               DEBUG_COPY(array100->id);
            } else {
               array100 = (array_t*)malloc(sizeof(array_t));
               array100->size = 954;
               array100->refC = 1;
               array100->id = 100;
               array100->data = (unsigned int*)malloc(array100->size*sizeof(unsigned int));
               memset(array100->data, 0, array100->size*sizeof(unsigned int));
               DEBUG_NEW(array100->id);
            }
            array100->refC--;
            if(array100->refC == 0) {
               free(array100->data);
               free(array100);
               DEBUG_FREE(array100->id);
            }
            array99->refC--;
            if(array99->refC == 0) {
               free(array99->data);
               free(array99);
               DEBUG_FREE(array99->id);
            }
            array98->refC--;
            if(array98->refC == 0) {
               free(array98->data);
               free(array98);
               DEBUG_FREE(array98->id);
            }
            array97->refC--;
            if(array97->refC == 0) {
               free(array97->data);
               free(array97);
               DEBUG_FREE(array97->id);
            }
         }
         for (int i = 0; i < array85->size; i++) {
            if (array85->data[i] == 69) { 
               return array85;
            }
         }
         array_t* array101;
         if (pCounter > 0) {
            array101 = vars->data[--pCounter];
            array101->refC++;
            DEBUG_COPY(array101->id);
         } else {
            array101 = (array_t*)malloc(sizeof(array_t));
            array101->size = 82;
            array101->refC = 1;
            array101->id = 101;
            array101->data = (unsigned int*)malloc(array101->size*sizeof(unsigned int));
            memset(array101->data, 0, array101->size*sizeof(unsigned int));
            DEBUG_NEW(array101->id);
         }
         array101->refC--;
         if(array101->refC == 0) {
            free(array101->data);
            free(array101);
            DEBUG_FREE(array101->id);
         }
         array86->refC--;
         if(array86->refC == 0) {
            free(array86->data);
            free(array86);
            DEBUG_FREE(array86->id);
         }
      }
   }
   return array85;
}

