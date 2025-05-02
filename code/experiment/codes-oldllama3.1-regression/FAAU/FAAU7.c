
            
            int f(int a) {
                    if (a > 10) {
                            return 1;
                            }
                    if (a % 2 == 0) {
                            printf("a is even\n");
                            }
                    printf("%d\n", a);
                    return 0;
                    }
         
            int main() {
                    int b = 1;
                    int counter = 0;
                    while (b < 10) {
                            while (b > 0 && counter < 10) {
                                    if (0 == 0) { // dead conditional statement
                                            printf("This will never be printed\n"); // statement inside
                                            }
                                    while (counter % 2 == 0 && b % 2!= 0 && 0 == 1) {
                                            printf("%d\n", b);
                                            }
                                    b = f(b);
                                    counter++;
                                    }
                            b++;
                            counter = 0;
                            }
                    return 0;
                    }
         
            
            