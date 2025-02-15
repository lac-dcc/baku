#include "outs/5_6_array.h" 
array_t* func0(array_t_param* vars, const unsigned long PATH0, int loopsFactor) {
   size_t pCounter = vars->size;
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
   unsigned int loop0 = 0;
   unsigned int loopLimit0 = (rand()%loopsFactor)/1 + 1;
   for(; loop0 < loopLimit0; loop0++) {
      if(PATH0 & 1) {
         if(PATH0 & 2) {
            if(PATH0 & 4) {
               if(PATH0 & 8) {
                  if(PATH0 & 16) {
                  }
                  else {
                     array_t* array3;
                     if (pCounter > 0) {
                        array3 = vars->data[--pCounter];
                        array3->refC++;
                        DEBUG_COPY(array3->id);
                     } else {
                        array3 = (array_t*)malloc(sizeof(array_t));
                        array3->size = 649;
                        array3->refC = 1;
                        array3->id = 3;
                        array3->data = (unsigned int*)malloc(array3->size*sizeof(unsigned int));
                        memset(array3->data, 0, array3->size*sizeof(unsigned int));
                        DEBUG_NEW(array3->id);
                     }
                     array_t* array4;
                     if (pCounter > 0) {
                        array4 = vars->data[--pCounter];
                        array4->refC++;
                        DEBUG_COPY(array4->id);
                     } else {
                        array4 = (array_t*)malloc(sizeof(array_t));
                        array4->size = 421;
                        array4->refC = 1;
                        array4->id = 4;
                        array4->data = (unsigned int*)malloc(array4->size*sizeof(unsigned int));
                        memset(array4->data, 0, array4->size*sizeof(unsigned int));
                        DEBUG_NEW(array4->id);
                     }
                     array_t* array5;
                     if (pCounter > 0) {
                        array5 = vars->data[--pCounter];
                        array5->refC++;
                        DEBUG_COPY(array5->id);
                     } else {
                        array5 = (array_t*)malloc(sizeof(array_t));
                        array5->size = 362;
                        array5->refC = 1;
                        array5->id = 5;
                        array5->data = (unsigned int*)malloc(array5->size*sizeof(unsigned int));
                        memset(array5->data, 0, array5->size*sizeof(unsigned int));
                        DEBUG_NEW(array5->id);
                     }
                     array5->refC--;
                     if(array5->refC == 0) {
                        free(array5->data);
                        free(array5);
                        DEBUG_FREE(array5->id);
                     }
                     array4->refC--;
                     if(array4->refC == 0) {
                        free(array4->data);
                        free(array4);
                        DEBUG_FREE(array4->id);
                     }
                     array3->refC--;
                     if(array3->refC == 0) {
                        free(array3->data);
                        free(array3);
                        DEBUG_FREE(array3->id);
                     }
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
                     array6->size = 27;
                     array6->refC = 1;
                     array6->id = 6;
                     array6->data = (unsigned int*)malloc(array6->size*sizeof(unsigned int));
                     memset(array6->data, 0, array6->size*sizeof(unsigned int));
                     DEBUG_NEW(array6->id);
                  }
                  array_t* array7;
                  if (pCounter > 0) {
                     array7 = vars->data[--pCounter];
                     array7->refC++;
                     DEBUG_COPY(array7->id);
                  } else {
                     array7 = (array_t*)malloc(sizeof(array_t));
                     array7->size = 690;
                     array7->refC = 1;
                     array7->id = 7;
                     array7->data = (unsigned int*)malloc(array7->size*sizeof(unsigned int));
                     memset(array7->data, 0, array7->size*sizeof(unsigned int));
                     DEBUG_NEW(array7->id);
                  }
                  array_t* array8;
                  if (pCounter > 0) {
                     array8 = vars->data[--pCounter];
                     array8->refC++;
                     DEBUG_COPY(array8->id);
                  } else {
                     array8 = (array_t*)malloc(sizeof(array_t));
                     array8->size = 59;
                     array8->refC = 1;
                     array8->id = 8;
                     array8->data = (unsigned int*)malloc(array8->size*sizeof(unsigned int));
                     memset(array8->data, 0, array8->size*sizeof(unsigned int));
                     DEBUG_NEW(array8->id);
                  }
                  array8->refC--;
                  if(array8->refC == 0) {
                     free(array8->data);
                     free(array8);
                     DEBUG_FREE(array8->id);
                  }
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
            }
            else {
               array_t* array9;
               if (pCounter > 0) {
                  array9 = vars->data[--pCounter];
                  array9->refC++;
                  DEBUG_COPY(array9->id);
               } else {
                  array9 = (array_t*)malloc(sizeof(array_t));
                  array9->size = 763;
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
                  array10->size = 926;
                  array10->refC = 1;
                  array10->id = 10;
                  array10->data = (unsigned int*)malloc(array10->size*sizeof(unsigned int));
                  memset(array10->data, 0, array10->size*sizeof(unsigned int));
                  DEBUG_NEW(array10->id);
               }
               array_t* array11;
               if (pCounter > 0) {
                  array11 = vars->data[--pCounter];
                  array11->refC++;
                  DEBUG_COPY(array11->id);
               } else {
                  array11 = (array_t*)malloc(sizeof(array_t));
                  array11->size = 540;
                  array11->refC = 1;
                  array11->id = 11;
                  array11->data = (unsigned int*)malloc(array11->size*sizeof(unsigned int));
                  memset(array11->data, 0, array11->size*sizeof(unsigned int));
                  DEBUG_NEW(array11->id);
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
            }
         }
         else {
            array_t* array12;
            if (pCounter > 0) {
               array12 = vars->data[--pCounter];
               array12->refC++;
               DEBUG_COPY(array12->id);
            } else {
               array12 = (array_t*)malloc(sizeof(array_t));
               array12->size = 426;
               array12->refC = 1;
               array12->id = 12;
               array12->data = (unsigned int*)malloc(array12->size*sizeof(unsigned int));
               memset(array12->data, 0, array12->size*sizeof(unsigned int));
               DEBUG_NEW(array12->id);
            }
            array_t* array13;
            if (pCounter > 0) {
               array13 = vars->data[--pCounter];
               array13->refC++;
               DEBUG_COPY(array13->id);
            } else {
               array13 = (array_t*)malloc(sizeof(array_t));
               array13->size = 172;
               array13->refC = 1;
               array13->id = 13;
               array13->data = (unsigned int*)malloc(array13->size*sizeof(unsigned int));
               memset(array13->data, 0, array13->size*sizeof(unsigned int));
               DEBUG_NEW(array13->id);
            }
            array_t* array14;
            if (pCounter > 0) {
               array14 = vars->data[--pCounter];
               array14->refC++;
               DEBUG_COPY(array14->id);
            } else {
               array14 = (array_t*)malloc(sizeof(array_t));
               array14->size = 736;
               array14->refC = 1;
               array14->id = 14;
               array14->data = (unsigned int*)malloc(array14->size*sizeof(unsigned int));
               memset(array14->data, 0, array14->size*sizeof(unsigned int));
               DEBUG_NEW(array14->id);
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
            array12->refC--;
            if(array12->refC == 0) {
               free(array12->data);
               free(array12);
               DEBUG_FREE(array12->id);
            }
         }
      }
      else {
         array_t* array15;
         if (pCounter > 0) {
            array15 = vars->data[--pCounter];
            array15->refC++;
            DEBUG_COPY(array15->id);
         } else {
            array15 = (array_t*)malloc(sizeof(array_t));
            array15->size = 211;
            array15->refC = 1;
            array15->id = 15;
            array15->data = (unsigned int*)malloc(array15->size*sizeof(unsigned int));
            memset(array15->data, 0, array15->size*sizeof(unsigned int));
            DEBUG_NEW(array15->id);
         }
         array_t* array16;
         if (pCounter > 0) {
            array16 = vars->data[--pCounter];
            array16->refC++;
            DEBUG_COPY(array16->id);
         } else {
            array16 = (array_t*)malloc(sizeof(array_t));
            array16->size = 368;
            array16->refC = 1;
            array16->id = 16;
            array16->data = (unsigned int*)malloc(array16->size*sizeof(unsigned int));
            memset(array16->data, 0, array16->size*sizeof(unsigned int));
            DEBUG_NEW(array16->id);
         }
         array_t* array17;
         if (pCounter > 0) {
            array17 = vars->data[--pCounter];
            array17->refC++;
            DEBUG_COPY(array17->id);
         } else {
            array17 = (array_t*)malloc(sizeof(array_t));
            array17->size = 567;
            array17->refC = 1;
            array17->id = 17;
            array17->data = (unsigned int*)malloc(array17->size*sizeof(unsigned int));
            memset(array17->data, 0, array17->size*sizeof(unsigned int));
            DEBUG_NEW(array17->id);
         }
         array17->refC--;
         if(array17->refC == 0) {
            free(array17->data);
            free(array17);
            DEBUG_FREE(array17->id);
         }
         array16->refC--;
         if(array16->refC == 0) {
            free(array16->data);
            free(array16);
            DEBUG_FREE(array16->id);
         }
         array15->refC--;
         if(array15->refC == 0) {
            free(array15->data);
            free(array15);
            DEBUG_FREE(array15->id);
         }
      }
   }
   array_t* array18;
   if (pCounter > 0) {
      array18 = vars->data[--pCounter];
      array18->refC++;
      DEBUG_COPY(array18->id);
   } else {
      array18 = (array_t*)malloc(sizeof(array_t));
      array18->size = 429;
      array18->refC = 1;
      array18->id = 18;
      array18->data = (unsigned int*)malloc(array18->size*sizeof(unsigned int));
      memset(array18->data, 0, array18->size*sizeof(unsigned int));
      DEBUG_NEW(array18->id);
   }
   array_t* array19;
   if (pCounter > 0) {
      array19 = vars->data[--pCounter];
      array19->refC++;
      DEBUG_COPY(array19->id);
   } else {
      array19 = (array_t*)malloc(sizeof(array_t));
      array19->size = 782;
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
      array20->size = 530;
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
   array18->refC--;
   if(array18->refC == 0) {
      free(array18->data);
      free(array18);
      DEBUG_FREE(array18->id);
   }
   array2->refC--;
   if(array2->refC == 0) {
      free(array2->data);
      free(array2);
      DEBUG_FREE(array2->id);
   }
   return array19;
}

