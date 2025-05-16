#include<stdio.h> 
\n");
    printf("%s", "int f(int a) {\n");
    printf("%s", "    if (a > 10) {\n");
    printf("%s", "        if (a < 20) {\n");
    printf("%s", "            return 1;\n");
    printf("%s", "        } else {\n");
    printf("%s", "            return 0;\n");
    printf("%s", "        }\n");
    printf("%s", "    } else {\n");
    printf("%s", "        return 0;\n");
    printf("%s", "    }\n");
    printf("%s", "}\n");
    printf("%s", "
    void main(){
        printf("%d",f(7));
    }
    