#include<stdio.h> 

int f(int a) {
        struct code_usage {
                int add;
                int value;
                };
        struct code_usage code;
        code.add = 1;
        code.value = 2;
        return code.add + code.value;
        }

    void main(){
        printf("%d",f(7));
    }
    