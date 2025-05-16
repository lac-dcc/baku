
            int f(int a, int b) {
                    if (a>0) {
                    printf("a is greater than 0\n");
                    }
                    else if (a==0) {
                    printf("a is equal to 0\n");
                    }
                    else if (a<0) {
                    printf("a is less than 0\n");
                    }
                    if (a%2==0) {
                    printf("a is even\n");
                    }
                    else {
                    printf("a is odd\n");
                    }
                    if (b > 10) {
                    printf("b is greater than 10\n");
                    }
                    while(1) {
                    printf("This is a dead loop\n");
                    }
                    return 0;
                    }
            int main() {
            f(1, 10);
            f(0, 20);
            f(-1, 30);
            f(2, 40);
            f(3, 50);
            return 0;
            }
            