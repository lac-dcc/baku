#include<stdio.h> 


int f(int a) {
        if (a > 5) {
                return 1;
        } else if (a < 0) {
                return 2;
        } else {
                while (a == 5) {
                        printf("This will never end...\n");
                        a = a + 1;
                }
                return a;
        }
        return 0;
}


    void main(){
        printf("%d",f(7));
    }
    