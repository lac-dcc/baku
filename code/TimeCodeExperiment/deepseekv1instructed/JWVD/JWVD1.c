#include<stdio.h> 
\n");
    printf(" int f(int a) {\n");
    printf("         for(int i = 0; i < a; i++) {\n");
    printf("             if(i % 2 == 0) {\n");
    printf("                 return 1;\n");
    printf("             }\n");
    printf("         }\n");
    printf("         return 0;\n");
    printf("         }\n");
    printf("
    void main(){
        printf("%d",f(7));
    }
    