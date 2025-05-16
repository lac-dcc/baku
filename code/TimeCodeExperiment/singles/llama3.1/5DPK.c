#include<stdio.h> 

             int f(int a) {
                int i;
                for (i = 0; i < a; i++) {
                    if (i % 2 == 0) {
                        if (i % 3 == 0) {
                            if (i % 5 == 0) {
                                return i;
                            }
                        } else {
                            return i;
                        }
                    } else {
                        return i;
                    }
                }
                return 0;
                }
            
    void main(){
        printf("%d",f(7));
    }
    