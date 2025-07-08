#include "array10_5.h" 
array_t* func30(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
   if(PATH0 & 1) {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array43 = func31(&params0, loopsFactor);
      DEBUG_RETURN(array43->id);
      free(params0.data);
      array43->refC--;
      if(array43->refC == 0) {
         free(array43->data);
         free(array43);
         DEBUG_FREE(array43->id);
      }
   }
   else {
      array_t_param params0;
      params0.size = 0;
      params0.data = (array_t**)malloc(params0.size*sizeof(array_t*));
      array_t* array45 = func32(&params0, loopsFactor);
      DEBUG_RETURN(array45->id);
      free(params0.data);
      array45->refC--;
      if(array45->refC == 0) {
         free(array45->data);
         free(array45);
         DEBUG_FREE(array45->id);
      }
   }
   array_t* array47;
   if (pCounter > 0) {
      array47 = vars->data[--pCounter];
      array47->refC++;
      DEBUG_COPY(array47->id);
   } else {
      array47 = (array_t*)malloc(sizeof(array_t));
      array47->size = 555;
      array47->refC = 1;
      array47->id = 47;
      array47->data = (unsigned int*)malloc(array47->size*sizeof(unsigned int));
      memset(array47->data, 0, array47->size*sizeof(unsigned int));
      DEBUG_NEW(array47->id);
   }
   return array47;
}

