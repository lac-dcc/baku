#include<stdio.h> 

            
int f(int a) {
    if (a < 0) {
        // handle negative input
        return 0;
    }
    if (a == 0) {
        // handle edge case where a is 0
        return 0;
    }
    if (a > 1000) {
        // handle large input
        return 0;
    }
    if ((a > 0) && (a < 1000)) {
        // handle normal input
        int sum = 0;
        for (int i = 0; i < a; i++) {
            sum += i;
        }
        if (a % 2 == 0) {
            // handle even number
            return sum + 1;
        } else {
            // handle odd number
            return sum - 1;
        }
    }
    return 0;
}

            
    void main(){
        printf("%d",f(7));
    }
    