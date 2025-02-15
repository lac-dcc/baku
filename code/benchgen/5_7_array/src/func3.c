#include "outs/5_7_array.h" 
array_t* func3(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   array_t* array114;
   if (pCounter > 0) {
      array114 = vars->data[--pCounter];
      array114->refC++;
      DEBUG_COPY(array114->id);
   } else {
      array114 = (array_t*)malloc(sizeof(array_t));
      array114->size = 624;
      array114->refC = 1;
      array114->id = 114;
      array114->data = (unsigned int*)malloc(array114->size*sizeof(unsigned int));
      memset(array114->data, 0, array114->size*sizeof(unsigned int));
      DEBUG_NEW(array114->id);
   }
   array_t_param params0;
   params0.size = 1;
   params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
   params0.data[0] = array114;
   array_t* array115 = func12(&params0, loopsFactor);
   DEBUG_RETURN(array115->id);
   free(params0.data);
   array_t* array116;
   if (pCounter > 0) {
      array116 = vars->data[--pCounter];
      array116->refC++;
      DEBUG_COPY(array116->id);
   } else {
      array116 = (array_t*)malloc(sizeof(array_t));
      array116->size = 452;
      array116->refC = 1;
      array116->id = 116;
      array116->data = (unsigned int*)malloc(array116->size*sizeof(unsigned int));
      memset(array116->data, 0, array116->size*sizeof(unsigned int));
      DEBUG_NEW(array116->id);
   }
   if(PATH0 & 1) {
      unsigned int loop28 = 0;
      unsigned int loopLimit28 = (rand()%loopsFactor)/1 + 1;
      for(; loop28 < loopLimit28; loop28++) {
      }
   }
   else {
      array_t* array117;
      if (pCounter > 0) {
         array117 = vars->data[--pCounter];
         array117->refC++;
         DEBUG_COPY(array117->id);
      } else {
         array117 = (array_t*)malloc(sizeof(array_t));
         array117->size = 899;
         array117->refC = 1;
         array117->id = 117;
         array117->data = (unsigned int*)malloc(array117->size*sizeof(unsigned int));
         memset(array117->data, 0, array117->size*sizeof(unsigned int));
         DEBUG_NEW(array117->id);
      }
      array_t_param params1;
      params1.size = 4;
      params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
      params1.data[0] = array114;
      params1.data[1] = array115;
      params1.data[2] = array116;
      params1.data[3] = array117;
      array_t* array118 = func13(&params1, loopsFactor);
      DEBUG_RETURN(array118->id);
      free(params1.data);
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
   }
   for (int i = 0; i < array116->size; i++) {
      if (array116->data[i] == 71) { 
         return array116;
      }
   }
   array_t* array119;
   if (pCounter > 0) {
      array119 = vars->data[--pCounter];
      array119->refC++;
      DEBUG_COPY(array119->id);
   } else {
      array119 = (array_t*)malloc(sizeof(array_t));
      array119->size = 973;
      array119->refC = 1;
      array119->id = 119;
      array119->data = (unsigned int*)malloc(array119->size*sizeof(unsigned int));
      memset(array119->data, 0, array119->size*sizeof(unsigned int));
      DEBUG_NEW(array119->id);
   }
   array_t* array120;
   if (pCounter > 0) {
      array120 = vars->data[--pCounter];
      array120->refC++;
      DEBUG_COPY(array120->id);
   } else {
      array120 = (array_t*)malloc(sizeof(array_t));
      array120->size = 131;
      array120->refC = 1;
      array120->id = 120;
      array120->data = (unsigned int*)malloc(array120->size*sizeof(unsigned int));
      memset(array120->data, 0, array120->size*sizeof(unsigned int));
      DEBUG_NEW(array120->id);
   }
   for (int i = 0; i < array115->size; i++) {
      array115->data[i]++;
   }
   unsigned int loop29 = 0;
   unsigned int loopLimit29 = (rand()%loopsFactor)/1 + 1;
   for(; loop29 < loopLimit29; loop29++) {
      for (int i = 0; i < array114->size; i++) {
         array114->data[i]--;
      }
   }
   array_t_param params1;
   params1.size = 5;
   params1.data = (array_t**)malloc(params1.size*sizeof(array_t*));
   params1.data[0] = array114;
   params1.data[1] = array115;
   params1.data[2] = array116;
   params1.data[3] = array119;
   params1.data[4] = array120;
   array_t* array121 = func14(&params1, loopsFactor);
   DEBUG_RETURN(array121->id);
   free(params1.data);
   array_t* array122;
   if (pCounter > 0) {
      array122 = vars->data[--pCounter];
      array122->refC++;
      DEBUG_COPY(array122->id);
   } else {
      array122 = (array_t*)malloc(sizeof(array_t));
      array122->size = 660;
      array122->refC = 1;
      array122->id = 122;
      array122->data = (unsigned int*)malloc(array122->size*sizeof(unsigned int));
      memset(array122->data, 0, array122->size*sizeof(unsigned int));
      DEBUG_NEW(array122->id);
   }
   array_t_param params2;
   params2.size = 7;
   params2.data = (array_t**)malloc(params2.size*sizeof(array_t*));
   params2.data[0] = array114;
   params2.data[1] = array115;
   params2.data[2] = array116;
   params2.data[3] = array119;
   params2.data[4] = array120;
   params2.data[5] = array121;
   params2.data[6] = array122;
   array_t* array123 = func6(&params2, rng(), loopsFactor);
   DEBUG_RETURN(array123->id);
   free(params2.data);
   array_t* array124;
   if (pCounter > 0) {
      array124 = vars->data[--pCounter];
      array124->refC++;
      DEBUG_COPY(array124->id);
   } else {
      array124 = (array_t*)malloc(sizeof(array_t));
      array124->size = 981;
      array124->refC = 1;
      array124->id = 124;
      array124->data = (unsigned int*)malloc(array124->size*sizeof(unsigned int));
      memset(array124->data, 0, array124->size*sizeof(unsigned int));
      DEBUG_NEW(array124->id);
   }
   if(PATH0 & 2) {
      unsigned int loop30 = 0;
      unsigned int loopLimit30 = (rand()%loopsFactor)/1 + 1;
      for(; loop30 < loopLimit30; loop30++) {
         for (int i = 0; i < array116->size; i++) {
            if (array116->data[i] == 96) { 
               return array116;
            }
         }
         array_t* array125;
         if (pCounter > 0) {
            array125 = vars->data[--pCounter];
            array125->refC++;
            DEBUG_COPY(array125->id);
         } else {
            array125 = (array_t*)malloc(sizeof(array_t));
            array125->size = 959;
            array125->refC = 1;
            array125->id = 125;
            array125->data = (unsigned int*)malloc(array125->size*sizeof(unsigned int));
            memset(array125->data, 0, array125->size*sizeof(unsigned int));
            DEBUG_NEW(array125->id);
         }
         array_t_param params3;
         params3.size = 10;
         params3.data = (array_t**)malloc(params3.size*sizeof(array_t*));
         params3.data[0] = array114;
         params3.data[1] = array115;
         params3.data[2] = array116;
         params3.data[3] = array119;
         params3.data[4] = array120;
         params3.data[5] = array121;
         params3.data[6] = array122;
         params3.data[7] = array123;
         params3.data[8] = array124;
         params3.data[9] = array125;
         array_t* array126 = func12(&params3, loopsFactor);
         DEBUG_RETURN(array126->id);
         free(params3.data);
         array_t* array127;
         if (pCounter > 0) {
            array127 = vars->data[--pCounter];
            array127->refC++;
            DEBUG_COPY(array127->id);
         } else {
            array127 = (array_t*)malloc(sizeof(array_t));
            array127->size = 668;
            array127->refC = 1;
            array127->id = 127;
            array127->data = (unsigned int*)malloc(array127->size*sizeof(unsigned int));
            memset(array127->data, 0, array127->size*sizeof(unsigned int));
            DEBUG_NEW(array127->id);
         }
         if(PATH0 & 4) {
            unsigned int loop31 = 0;
            unsigned int loopLimit31 = (rand()%loopsFactor)/2 + 1;
            for(; loop31 < loopLimit31; loop31++) {
            }
         }
         else {
            array_t* array128;
            if (pCounter > 0) {
               array128 = vars->data[--pCounter];
               array128->refC++;
               DEBUG_COPY(array128->id);
            } else {
               array128 = (array_t*)malloc(sizeof(array_t));
               array128->size = 190;
               array128->refC = 1;
               array128->id = 128;
               array128->data = (unsigned int*)malloc(array128->size*sizeof(unsigned int));
               memset(array128->data, 0, array128->size*sizeof(unsigned int));
               DEBUG_NEW(array128->id);
            }
            array_t_param params4;
            params4.size = 13;
            params4.data = (array_t**)malloc(params4.size*sizeof(array_t*));
            params4.data[0] = array114;
            params4.data[1] = array115;
            params4.data[2] = array116;
            params4.data[3] = array119;
            params4.data[4] = array120;
            params4.data[5] = array121;
            params4.data[6] = array122;
            params4.data[7] = array123;
            params4.data[8] = array124;
            params4.data[9] = array125;
            params4.data[10] = array126;
            params4.data[11] = array127;
            params4.data[12] = array128;
            array_t* array129 = func13(&params4, loopsFactor);
            DEBUG_RETURN(array129->id);
            free(params4.data);
            array129->refC--;
            if(array129->refC == 0) {
               free(array129->data);
               free(array129);
               DEBUG_FREE(array129->id);
            }
            array128->refC--;
            if(array128->refC == 0) {
               free(array128->data);
               free(array128);
               DEBUG_FREE(array128->id);
            }
         }
         for (int i = 0; i < array116->size; i++) {
            if (array116->data[i] == 84) { 
               return array116;
            }
         }
         array_t* array130;
         if (pCounter > 0) {
            array130 = vars->data[--pCounter];
            array130->refC++;
            DEBUG_COPY(array130->id);
         } else {
            array130 = (array_t*)malloc(sizeof(array_t));
            array130->size = 340;
            array130->refC = 1;
            array130->id = 130;
            array130->data = (unsigned int*)malloc(array130->size*sizeof(unsigned int));
            memset(array130->data, 0, array130->size*sizeof(unsigned int));
            DEBUG_NEW(array130->id);
         }
         array_t* array131;
         if (pCounter > 0) {
            array131 = vars->data[--pCounter];
            array131->refC++;
            DEBUG_COPY(array131->id);
         } else {
            array131 = (array_t*)malloc(sizeof(array_t));
            array131->size = 90;
            array131->refC = 1;
            array131->id = 131;
            array131->data = (unsigned int*)malloc(array131->size*sizeof(unsigned int));
            memset(array131->data, 0, array131->size*sizeof(unsigned int));
            DEBUG_NEW(array131->id);
         }
         for (int i = 0; i < array120->size; i++) {
            array120->data[i]++;
         }
         unsigned int loop32 = 0;
         unsigned int loopLimit32 = (rand()%loopsFactor)/2 + 1;
         for(; loop32 < loopLimit32; loop32++) {
            for (int i = 0; i < array126->size; i++) {
               array126->data[i]--;
            }
         }
         array_t_param params4;
         params4.size = 14;
         params4.data = (array_t**)malloc(params4.size*sizeof(array_t*));
         params4.data[0] = array114;
         params4.data[1] = array115;
         params4.data[2] = array116;
         params4.data[3] = array119;
         params4.data[4] = array120;
         params4.data[5] = array121;
         params4.data[6] = array122;
         params4.data[7] = array123;
         params4.data[8] = array124;
         params4.data[9] = array125;
         params4.data[10] = array126;
         params4.data[11] = array127;
         params4.data[12] = array130;
         params4.data[13] = array131;
         array_t* array132 = func14(&params4, loopsFactor);
         DEBUG_RETURN(array132->id);
         free(params4.data);
         array132->refC--;
         if(array132->refC == 0) {
            free(array132->data);
            free(array132);
            DEBUG_FREE(array132->id);
         }
         array131->refC--;
         if(array131->refC == 0) {
            free(array131->data);
            free(array131);
            DEBUG_FREE(array131->id);
         }
         array130->refC--;
         if(array130->refC == 0) {
            free(array130->data);
            free(array130);
            DEBUG_FREE(array130->id);
         }
         array127->refC--;
         if(array127->refC == 0) {
            free(array127->data);
            free(array127);
            DEBUG_FREE(array127->id);
         }
         array126->refC--;
         if(array126->refC == 0) {
            free(array126->data);
            free(array126);
            DEBUG_FREE(array126->id);
         }
         array125->refC--;
         if(array125->refC == 0) {
            free(array125->data);
            free(array125);
            DEBUG_FREE(array125->id);
         }
      }
   }
   else {
      array_t* array133;
      if (pCounter > 0) {
         array133 = vars->data[--pCounter];
         array133->refC++;
         DEBUG_COPY(array133->id);
      } else {
         array133 = (array_t*)malloc(sizeof(array_t));
         array133->size = 107;
         array133->refC = 1;
         array133->id = 133;
         array133->data = (unsigned int*)malloc(array133->size*sizeof(unsigned int));
         memset(array133->data, 0, array133->size*sizeof(unsigned int));
         DEBUG_NEW(array133->id);
      }
      array_t* array134;
      if (pCounter > 0) {
         array134 = vars->data[--pCounter];
         array134->refC++;
         DEBUG_COPY(array134->id);
      } else {
         array134 = (array_t*)malloc(sizeof(array_t));
         array134->size = 445;
         array134->refC = 1;
         array134->id = 134;
         array134->data = (unsigned int*)malloc(array134->size*sizeof(unsigned int));
         memset(array134->data, 0, array134->size*sizeof(unsigned int));
         DEBUG_NEW(array134->id);
      }
      array_t* array135;
      if (pCounter > 0) {
         array135 = vars->data[--pCounter];
         array135->refC++;
         DEBUG_COPY(array135->id);
      } else {
         array135 = (array_t*)malloc(sizeof(array_t));
         array135->size = 756;
         array135->refC = 1;
         array135->id = 135;
         array135->data = (unsigned int*)malloc(array135->size*sizeof(unsigned int));
         memset(array135->data, 0, array135->size*sizeof(unsigned int));
         DEBUG_NEW(array135->id);
      }
      for (int i = 0; i < array123->size; i++) {
         array123->data[i]++;
      }
      unsigned int loop33 = 0;
      unsigned int loopLimit33 = (rand()%loopsFactor)/1 + 1;
      for(; loop33 < loopLimit33; loop33++) {
         for (int i = 0; i < array122->size; i++) {
            array122->data[i]--;
         }
      }
      array_t_param params3;
      params3.size = 12;
      params3.data = (array_t**)malloc(params3.size*sizeof(array_t*));
      params3.data[0] = array114;
      params3.data[1] = array115;
      params3.data[2] = array116;
      params3.data[3] = array119;
      params3.data[4] = array120;
      params3.data[5] = array121;
      params3.data[6] = array122;
      params3.data[7] = array123;
      params3.data[8] = array124;
      params3.data[9] = array133;
      params3.data[10] = array134;
      params3.data[11] = array135;
      array_t* array136 = func10(&params3, loopsFactor);
      DEBUG_RETURN(array136->id);
      free(params3.data);
      array_t_param params4;
      params4.size = 13;
      params4.data = (array_t**)malloc(params4.size*sizeof(array_t*));
      params4.data[0] = array114;
      params4.data[1] = array115;
      params4.data[2] = array116;
      params4.data[3] = array119;
      params4.data[4] = array120;
      params4.data[5] = array121;
      params4.data[6] = array122;
      params4.data[7] = array123;
      params4.data[8] = array124;
      params4.data[9] = array133;
      params4.data[10] = array134;
      params4.data[11] = array135;
      params4.data[12] = array136;
      array_t* array137 = func7(&params4, loopsFactor);
      DEBUG_RETURN(array137->id);
      free(params4.data);
      array137->refC--;
      if(array137->refC == 0) {
         free(array137->data);
         free(array137);
         DEBUG_FREE(array137->id);
      }
      array136->refC--;
      if(array136->refC == 0) {
         free(array136->data);
         free(array136);
         DEBUG_FREE(array136->id);
      }
      array135->refC--;
      if(array135->refC == 0) {
         free(array135->data);
         free(array135);
         DEBUG_FREE(array135->id);
      }
      array134->refC--;
      if(array134->refC == 0) {
         free(array134->data);
         free(array134);
         DEBUG_FREE(array134->id);
      }
      array133->refC--;
      if(array133->refC == 0) {
         free(array133->data);
         free(array133);
         DEBUG_FREE(array133->id);
      }
   }
   for (int i = 0; i < array119->size; i++) {
      if (array119->data[i] == 9) { 
         return array119;
      }
   }
   array_t* array138;
   if (pCounter > 0) {
      array138 = vars->data[--pCounter];
      array138->refC++;
      DEBUG_COPY(array138->id);
   } else {
      array138 = (array_t*)malloc(sizeof(array_t));
      array138->size = 336;
      array138->refC = 1;
      array138->id = 138;
      array138->data = (unsigned int*)malloc(array138->size*sizeof(unsigned int));
      memset(array138->data, 0, array138->size*sizeof(unsigned int));
      DEBUG_NEW(array138->id);
   }
   array_t* array139;
   if (pCounter > 0) {
      array139 = vars->data[--pCounter];
      array139->refC++;
      DEBUG_COPY(array139->id);
   } else {
      array139 = (array_t*)malloc(sizeof(array_t));
      array139->size = 210;
      array139->refC = 1;
      array139->id = 139;
      array139->data = (unsigned int*)malloc(array139->size*sizeof(unsigned int));
      memset(array139->data, 0, array139->size*sizeof(unsigned int));
      DEBUG_NEW(array139->id);
   }
   for (int i = 0; i < array124->size; i++) {
      array124->data[i]++;
   }
   unsigned int loop34 = 0;
   unsigned int loopLimit34 = (rand()%loopsFactor)/1 + 1;
   for(; loop34 < loopLimit34; loop34++) {
      for (int i = 0; i < array114->size; i++) {
         array114->data[i]--;
      }
   }
   array_t_param params3;
   params3.size = 11;
   params3.data = (array_t**)malloc(params3.size*sizeof(array_t*));
   params3.data[0] = array114;
   params3.data[1] = array115;
   params3.data[2] = array116;
   params3.data[3] = array119;
   params3.data[4] = array120;
   params3.data[5] = array121;
   params3.data[6] = array122;
   params3.data[7] = array123;
   params3.data[8] = array124;
   params3.data[9] = array138;
   params3.data[10] = array139;
   array_t* array140 = func8(&params3, rng(), loopsFactor);
   DEBUG_RETURN(array140->id);
   free(params3.data);
   for (int i = 0; i < array115->size; i++) {
      if (array115->data[i] == 72) { 
         return array115;
      }
   }
   array140->refC--;
   if(array140->refC == 0) {
      free(array140->data);
      free(array140);
      DEBUG_FREE(array140->id);
   }
   array139->refC--;
   if(array139->refC == 0) {
      free(array139->data);
      free(array139);
      DEBUG_FREE(array139->id);
   }
   array138->refC--;
   if(array138->refC == 0) {
      free(array138->data);
      free(array138);
      DEBUG_FREE(array138->id);
   }
   array124->refC--;
   if(array124->refC == 0) {
      free(array124->data);
      free(array124);
      DEBUG_FREE(array124->id);
   }
   array123->refC--;
   if(array123->refC == 0) {
      free(array123->data);
      free(array123);
      DEBUG_FREE(array123->id);
   }
   array122->refC--;
   if(array122->refC == 0) {
      free(array122->data);
      free(array122);
      DEBUG_FREE(array122->id);
   }
   array121->refC--;
   if(array121->refC == 0) {
      free(array121->data);
      free(array121);
      DEBUG_FREE(array121->id);
   }
   array120->refC--;
   if(array120->refC == 0) {
      free(array120->data);
      free(array120);
      DEBUG_FREE(array120->id);
   }
   array119->refC--;
   if(array119->refC == 0) {
      free(array119->data);
      free(array119);
      DEBUG_FREE(array119->id);
   }
   array116->refC--;
   if(array116->refC == 0) {
      free(array116->data);
      free(array116);
      DEBUG_FREE(array116->id);
   }
   array114->refC--;
   if(array114->refC == 0) {
      free(array114->data);
      free(array114);
      DEBUG_FREE(array114->id);
   }
   return array115;
}

