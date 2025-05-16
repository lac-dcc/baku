#include<stdio.h> 

             int f(int a) {
                    if (a == 0) {
                    if (a < 0) {
                    return 0;
                    } else {
                    return 1;
                    }
                    } else {
                    if (a < 0) {
                    return 0;
                    } else {
                    return a;
                    }
                    }
                    }
            
    void main(){
        printf("%d",f(7));
    }
    