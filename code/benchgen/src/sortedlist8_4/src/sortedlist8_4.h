#ifndef sortedlist8_4
#define sortedlist8_4
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
sortedlist_t* func6(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor);
sortedlist_t* func7(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func8(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func9(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func11(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func16(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor);
sortedlist_t* func17(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func18(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func19(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func21(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func26(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor);
sortedlist_t* func27(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func28(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func29(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func1(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func2(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor);
sortedlist_t* func3(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func4(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func5(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func10(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func12(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor);
sortedlist_t* func13(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func14(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func15(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func20(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func22(sortedlist_t_param* vars, const unsigned long PATH0, int loopsFactor);
sortedlist_t* func23(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func24(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func25(sortedlist_t_param* vars, int loopsFactor);
sortedlist_t* func30(sortedlist_t_param* vars, int loopsFactor);
#endif