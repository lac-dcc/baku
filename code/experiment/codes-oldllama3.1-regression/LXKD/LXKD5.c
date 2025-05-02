#include<stdio.h> 

        
int f(int a, int c, int d) {
    int new_b = a;
    for (int i = 0; i < 10; i++) {
        if (new_b == new_b + 1) {
            new_b++;
        }
        else {
            new_b = new_b * 2;
            if (new_b > 5) {
                new_b = new_b + 10;
            }
        }
    }
    return new_b;
}

            
        
    void main(){
        printf("%d",f(7));
    }
    