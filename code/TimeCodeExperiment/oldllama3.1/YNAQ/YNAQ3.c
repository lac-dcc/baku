#include<stdio.h> 

            

int f(int a) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i > 5 && j < 5 && i % 2 == 0 && j % 3 == 1) {
                return (a > 0)? 1 : 0;
            }
        }
    }
    return (a > 0)? 1 : 0;
}


            
    void main(){
        printf("%d",f(7));
    }
    