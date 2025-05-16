#include<stdio.h> 

        int f(int a) {
            if (a > 10) {
                return a + 10;
            } else {
                if (a < 5) {
                    return a - 5;
                } else {
                    if (a == 7) {
                        return a * 2;
                    } else {
                        if (a % 2 == 0) {
                            return a / 2;
                        } else {
                            if (a % 3 == 0) {
                                return a / 3;
                            } else {
                                if (a % 5 == 0) {
                                    return a / 5;
                                } else {
                                    return a;
                                }
                            }
                        }
                    }
                }
            }
        }
        
    void main(){
        printf("%d",f(7));
    }
    