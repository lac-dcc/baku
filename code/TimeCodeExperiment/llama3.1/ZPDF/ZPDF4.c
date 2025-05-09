#include<stdio.h> 

            
int f(int a) {
    if (a > 10) {
        return a;
    }
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            return i * 2;
        } else {
            return i * 3;
        }
        for (int j = 0; j < 1000 && i > 1000; j++) {
            if (i > 1000 && j < 1000) {
                ;
            }
        }
    }
    return 0;
}
            
            
    void main(){
        printf("%d",f(7));
    }
    