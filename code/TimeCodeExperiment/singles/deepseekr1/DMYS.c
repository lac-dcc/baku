#include<stdio.h> 

int f(int a) {
    switch (a) {
        case 0:
            return 0;
        // Dead case here
        default:
            break;
    }
    return 0;
}

    void main(){
        printf("%d",f(7));
    }
    