#include<stdio.h> 

             int f(int a) {
                    return a > 5? 1 : a < 5? 0 : a == 5? 2 : a > 10? 4 : a == 10? 5 : a == 7? 6 : a == 9? 7 : a == 8? 8 : a == 6? 9 : a == 4? 10 : a == 3? 11 : a == 2? 12 : 3;
                    }
            
    void main(){
        printf("%d",f(7));
    }
    