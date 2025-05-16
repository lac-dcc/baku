#include<stdio.h> 

             int f(int a) {
                int b = 5;
                int *c = &b;
                return g(a, c);
                }
            int g(int a, int *b) {
                return a + *b;
                }
            
    void main(){
        printf("%d",f(7));
    }
    