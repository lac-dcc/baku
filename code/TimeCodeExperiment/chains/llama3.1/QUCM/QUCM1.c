#include<stdio.h> 

             int f(int a) {
                    return a == 0? 0 : a == 1? 1 : a == 2? 2 : a == 3? 3 : a == 4? 4 : a == 5? 5 : a == 6? 6 : a == 7? 7 : a == 8? 8 : a == 9? 9 : a == 10? 10 : a == 11? 11 : 12;
                    }
            
    void main(){
        printf("%d",f(7));
    }
    