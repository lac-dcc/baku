#include<stdio.h> 
\n");
    printf("%s", " int f(int a) {\n");
    printf("%s", "        for(int i = 0; i < a; i++) {\n");
    printf("%s", "            for(int j = 0; j < a; j++) {\n");
    printf("%s", "                if(i == j) {\n");
    printf("%s", "                    return 1;\n");
    printf("%s", "                }\n");
    printf("%s", "            }\n");
    printf("%s", "        }\n");
    printf("%s", "        return 0;\n");
    printf("%s", " }\n");
    printf("%s", "
    void main(){
        printf("%d",f(7));
    }
    