#include "outs/5_2_array.h" 
array_t* func14(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   unsigned int loop22 = 0;
   unsigned int loopLimit22 = (rand()%loopsFactor)/4 + 1;
   for(; loop22 < loopLimit22; loop22++) {
      array_t* array105;
      if (pCounter > 0) {
         array105 = vars->data[--pCounter];
         array105->refC++;
         DEBUG_COPY(array105->id);
      } else {
         array105 = (array_t*)malloc(sizeof(array_t));
         array105->size = 299;
         array105->refC = 1;
         array105->id = 105;
         array105->data = (unsigned int*)malloc(array105->size*sizeof(unsigned int));
         memset(array105->data, 0, array105->size*sizeof(unsigned int));
         DEBUG_NEW(array105->id);
      }
      if(PATH0 & 1) {
         array_t* array106;
         if (pCounter > 0) {
            array106 = vars->data[--pCounter];
            array106->refC++;
            DEBUG_COPY(array106->id);
         } else {
            array106 = (array_t*)malloc(sizeof(array_t));
            array106->size = 343;
            array106->refC = 1;
            array106->id = 106;
            array106->data = (unsigned int*)malloc(array106->size*sizeof(unsigned int));
            memset(array106->data, 0, array106->size*sizeof(unsigned int));
            DEBUG_NEW(array106->id);
         }
         array_t_param params0;
         params0.size = 2;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array105;
         params0.data[1] = array106;
         array_t* array107 = func22(&params0, loopsFactor);
         DEBUG_RETURN(array107->id);
         free(params0.data);
         array_t* array108;
         if (pCounter > 0) {
            array108 = vars->data[--pCounter];
            array108->refC++;
            DEBUG_COPY(array108->id);
         } else {
            array108 = (array_t*)malloc(sizeof(array_t));
            array108->size = 340;
            array108->refC = 1;
            array108->id = 108;
            array108->data = (unsigned int*)malloc(array108->size*sizeof(unsigned int));
            memset(array108->data, 0, array108->size*sizeof(unsigned int));
            DEBUG_NEW(array108->id);
         }
         array_t* array109;
         if (pCounter > 0) {
            array109 = vars->data[--pCounter];
            array109->refC++;
            DEBUG_COPY(array109->id);
         } else {
            array109 = (array_t*)malloc(sizeof(array_t));
            array109->size = 422;
            array109->refC = 1;
            array109->id = 109;
            array109->data = (unsigned int*)malloc(array109->size*sizeof(unsigned int));
            memset(array109->data, 0, array109->size*sizeof(unsigned int));
            DEBUG_NEW(array109->id);
         }
         array109->refC--;
         if(array109->refC == 0) {
            free(array109->data);
            free(array109);
            DEBUG_FREE(array109->id);
         }
         array108->refC--;
         if(array108->refC == 0) {
            free(array108->data);
            free(array108);
            DEBUG_FREE(array108->id);
         }
         array107->refC--;
         if(array107->refC == 0) {
            free(array107->data);
            free(array107);
            DEBUG_FREE(array107->id);
         }
         array106->refC--;
         if(array106->refC == 0) {
            free(array106->data);
            free(array106);
            DEBUG_FREE(array106->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array105;
         array_t* array110 = func23(&params0, loopsFactor);
         DEBUG_RETURN(array110->id);
         free(params0.data);
         array_t* array111;
         if (pCounter > 0) {
            array111 = vars->data[--pCounter];
            array111->refC++;
            DEBUG_COPY(array111->id);
         } else {
            array111 = (array_t*)malloc(sizeof(array_t));
            array111->size = 605;
            array111->refC = 1;
            array111->id = 111;
            array111->data = (unsigned int*)malloc(array111->size*sizeof(unsigned int));
            memset(array111->data, 0, array111->size*sizeof(unsigned int));
            DEBUG_NEW(array111->id);
         }
         array111->refC--;
         if(array111->refC == 0) {
            free(array111->data);
            free(array111);
            DEBUG_FREE(array111->id);
         }
         array110->refC--;
         if(array110->refC == 0) {
            free(array110->data);
            free(array110);
            DEBUG_FREE(array110->id);
         }
      }
      if(PATH0 & 2) {
         array_t* array112;
         if (pCounter > 0) {
            array112 = vars->data[--pCounter];
            array112->refC++;
            DEBUG_COPY(array112->id);
         } else {
            array112 = (array_t*)malloc(sizeof(array_t));
            array112->size = 801;
            array112->refC = 1;
            array112->id = 112;
            array112->data = (unsigned int*)malloc(array112->size*sizeof(unsigned int));
            memset(array112->data, 0, array112->size*sizeof(unsigned int));
            DEBUG_NEW(array112->id);
         }
         unsigned int loop23 = 0;
         unsigned int loopLimit23 = (rand()%loopsFactor)/5 + 1;
         for(; loop23 < loopLimit23; loop23++) {
            for (int i = 0; i < array112->size; i++) {
               array112->data[i]++;
            }
            for (int i = 0; i < array105->size; i++) {
               if (array105->data[i] == 78) { 
                  return array105;
               }
            }
            if(PATH0 & 4) {
               array_t_param params0;
               params0.size = 2;
               params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
               params0.data[0] = array105;
               params0.data[1] = array112;
               array_t* array113 = func24(&params0, loopsFactor);
               DEBUG_RETURN(array113->id);
               free(params0.data);
               array_t* array114;
               if (pCounter > 0) {
                  array114 = vars->data[--pCounter];
                  array114->refC++;
                  DEBUG_COPY(array114->id);
               } else {
                  array114 = (array_t*)malloc(sizeof(array_t));
                  array114->size = 736;
                  array114->refC = 1;
                  array114->id = 114;
                  array114->data = (unsigned int*)malloc(array114->size*sizeof(unsigned int));
                  memset(array114->data, 0, array114->size*sizeof(unsigned int));
                  DEBUG_NEW(array114->id);
               }
               array114->refC--;
               if(array114->refC == 0) {
                  free(array114->data);
                  free(array114);
                  DEBUG_FREE(array114->id);
               }
               array113->refC--;
               if(array113->refC == 0) {
                  free(array113->data);
                  free(array113);
                  DEBUG_FREE(array113->id);
               }
            }
            else {
            }
         }
         array_t* array115;
         if (pCounter > 0) {
            array115 = vars->data[--pCounter];
            array115->refC++;
            DEBUG_COPY(array115->id);
         } else {
            array115 = (array_t*)malloc(sizeof(array_t));
            array115->size = 444;
            array115->refC = 1;
            array115->id = 115;
            array115->data = (unsigned int*)malloc(array115->size*sizeof(unsigned int));
            memset(array115->data, 0, array115->size*sizeof(unsigned int));
            DEBUG_NEW(array115->id);
         }
         array115->refC--;
         if(array115->refC == 0) {
            free(array115->data);
            free(array115);
            DEBUG_FREE(array115->id);
         }
         array112->refC--;
         if(array112->refC == 0) {
            free(array112->data);
            free(array112);
            DEBUG_FREE(array112->id);
         }
      }
      else {
         array_t_param params0;
         params0.size = 1;
         params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
         params0.data[0] = array105;
         array_t* array116 = func25(&params0, loopsFactor);
         DEBUG_RETURN(array116->id);
         free(params0.data);
         for (int i = 0; i < array116->size; i++) {
            if (array116->data[i] == 8) { 
               return array116;
            }
         }
         unsigned int loop24 = 0;
         unsigned int loopLimit24 = (rand()%loopsFactor)/5 + 1;
         for(; loop24 < loopLimit24; loop24++) {
            for (int i = 0; i < array105->size; i++) {
               array105->data[i]--;
            }
            for (int i = 0; i < array105->size; i++) {
               if (array105->data[i] == 58) { 
                  return array105;
               }
            }
         }
         array_t_param params1;
         params1.size = 2;
         params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
         params1.data[0] = array105;
         params1.data[1] = array116;
         array_t* array117 = func26(&params1, loopsFactor);
         DEBUG_RETURN(array117->id);
         free(params1.data);
         array_t* array118;
         if (pCounter > 0) {
            array118 = vars->data[--pCounter];
            array118->refC++;
            DEBUG_COPY(array118->id);
         } else {
            array118 = (array_t*)malloc(sizeof(array_t));
            array118->size = 62;
            array118->refC = 1;
            array118->id = 118;
            array118->data = (unsigned int*)malloc(array118->size*sizeof(unsigned int));
            memset(array118->data, 0, array118->size*sizeof(unsigned int));
            DEBUG_NEW(array118->id);
         }
         array_t* array119;
         if (pCounter > 0) {
            array119 = vars->data[--pCounter];
            array119->refC++;
            DEBUG_COPY(array119->id);
         } else {
            array119 = (array_t*)malloc(sizeof(array_t));
            array119->size = 624;
            array119->refC = 1;
            array119->id = 119;
            array119->data = (unsigned int*)malloc(array119->size*sizeof(unsigned int));
            memset(array119->data, 0, array119->size*sizeof(unsigned int));
            DEBUG_NEW(array119->id);
         }
         array119->refC--;
         if(array119->refC == 0) {
            free(array119->data);
            free(array119);
            DEBUG_FREE(array119->id);
         }
         array118->refC--;
         if(array118->refC == 0) {
            free(array118->data);
            free(array118);
            DEBUG_FREE(array118->id);
         }
         array117->refC--;
         if(array117->refC == 0) {
            free(array117->data);
            free(array117);
            DEBUG_FREE(array117->id);
         }
         array116->refC--;
         if(array116->refC == 0) {
            free(array116->data);
            free(array116);
            DEBUG_FREE(array116->id);
         }
      }
      for (int i = 0; i < array105->size; i++) {
         if (array105->data[i] == 36) { 
            return array105;
         }
      }
      array_t* array120;
      if (pCounter > 0) {
         array120 = vars->data[--pCounter];
         array120->refC++;
         DEBUG_COPY(array120->id);
      } else {
         array120 = (array_t*)malloc(sizeof(array_t));
         array120->size = 452;
         array120->refC = 1;
         array120->id = 120;
         array120->data = (unsigned int*)malloc(array120->size*sizeof(unsigned int));
         memset(array120->data, 0, array120->size*sizeof(unsigned int));
         DEBUG_NEW(array120->id);
      }
      array120->refC--;
      if(array120->refC == 0) {
         free(array120->data);
         free(array120);
         DEBUG_FREE(array120->id);
      }
      array105->refC--;
      if(array105->refC == 0) {
         free(array105->data);
         free(array105);
         DEBUG_FREE(array105->id);
      }
   }
   array_t* array121;
   if (pCounter > 0) {
      array121 = vars->data[--pCounter];
      array121->refC++;
      DEBUG_COPY(array121->id);
   } else {
      array121 = (array_t*)malloc(sizeof(array_t));
      array121->size = 899;
      array121->refC = 1;
      array121->id = 121;
      array121->data = (unsigned int*)malloc(array121->size*sizeof(unsigned int));
      memset(array121->data, 0, array121->size*sizeof(unsigned int));
      DEBUG_NEW(array121->id);
   }
   return array121;
}

