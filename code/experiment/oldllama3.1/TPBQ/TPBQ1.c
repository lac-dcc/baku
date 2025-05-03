#include<stdio.h> 

            int f(int a) {
                int i = 0;
                while ((i < a) && (a - i) > i) {
                    i = i + (a - i);
                }
                return i;
            }
            
    void main(){
        printf("%d",f(7));
    }
    