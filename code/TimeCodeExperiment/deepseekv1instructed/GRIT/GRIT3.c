#include<stdio.h> 
\n");
    printf("int f(int a) {\n");
    printf("    if (a > 10) {\n");
    printf("        if (a < 20) {\n");
    printf("            return 1;\n");
    printf("        } else {\n");
    printf("            return 0;\n");
    printf("        }\n");
    printf("    } else {\n");
    printf("        return 0;\n");
    printf("    }\n");
    printf("}\n");
    printf("
    void main(){
        printf("%d",f(7));
    }
    