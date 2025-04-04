
            
            int f(int a) {
                    if (a>0) {
                    printf("a is greater than 0\n");
                    }
                    else if (a==0) {
                    printf("a is equal to 0\n");
                    }
                    else if (a<0) {
                    printf("a is less than 0\n");
                    }
                    while(1) {
                    printf("This is a dead loop\n");
                    }
                    return 0;
                    }
            int main() {
            f(1);
            f(0);
            f(-1);
            return 0;
            }
            
            