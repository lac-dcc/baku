#include<stdio.h> 
\n");
    printf(" int f(int a) {\n");
    printf("    while(1) {\n");
    printf("        if(a > 0) {\n");
    printf("            a = a - 1;\n");
    printf("        } else {\n");
    printf("            a = a + 1;\n");
    printf("        }\n");
    printf("    }\n");
    printf("    return 0;\n");
    printf(" }\n");
    printf("
    void main(){
        printf("%d",f(7));
    }
    