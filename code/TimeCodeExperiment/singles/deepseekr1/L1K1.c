#include<stdio.h> 

    int f(int a) {
        if (a > 5 && a < 3) {
            // Dead code
        }
        return 0;
    }

    void main(){
        printf("%d",f(7));
    }
    