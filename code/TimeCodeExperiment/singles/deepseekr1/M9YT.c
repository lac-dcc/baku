#include<stdio.h> 

struct Point {
    int x;
    int y;
};

struct Point* f(int a) {
    struct Point* p = (struct Point*)malloc(sizeof(struct Point));
    p->x = a;
    p->y = 0;
    return p;
}

    void main(){
        printf("%d",f(7));
    }
    