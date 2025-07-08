#ifndef sortedlist5_3
#define sortedlist5_3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef DEBUG
    #define DEBUG_NEW(id) printf("[NEW]\t\tId %d created\n", id)
    #define DEBUG_COPY(id) printf("[COPY]\t\tId %d copied\n", id)
    #define DEBUG_RETURN(id) printf("[RETURN]\tId %d returned\n", id)
    #define DEBUG_FREE(id) printf("[FREE]\t\tId %d freed\n", id)
#else
    #define DEBUG_NEW(id)
    #define DEBUG_COPY(id)
    #define DEBUG_RETURN(id)
    #define DEBUG_FREE(id)
#endif
#include <stdbool.h>
typedef struct cell_t {
     struct cell_t* next;
     unsigned int val;
} cell_t;
typedef struct sortedlist_t {
     cell_t* root;
     size_t refC;
     int id;
     unsigned int n;
} sortedlist_t;
typedef struct {
   sortedlist_t** data;
   size_t size;
} sortedlist_t_param;

unsigned long get_path();
sortedlist_t* func0(sortedlist_t_param* vars, int loopsFactor);
#endif