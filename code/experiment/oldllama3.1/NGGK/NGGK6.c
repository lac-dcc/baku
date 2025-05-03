
            
            #include <stdio.h>
            
            int f(int a) {
                return a;  // Return the sum of a
            }
            
            int check_condition(int x, int y) {
                int i = 0;
                while(i < 1000000) {
                    if(i % 2 == 0) {
                        if(x > y && y > 5) {
                            return 1;
                        } else if (x < y) {
                            return 2;
                        } else {
                            return 3;
                        }
                    }
                    i++;
                }
                int j = 0;
                while(j < 1000000) {
                    if(j % 2 == 0) {
                        if(check_condition(x, y) == 1) {
                            return 5;
                        } else if (check_condition(x, y) == 2) {
                            return 6;
                        } else {
                            return 7;
                        }
                    }
                    j++;
                }
                return 8;
            }
            
            int main() {
                int x = 10;
                int y = 5;
                int condition = check_condition(x, y);
                switch(condition) {
                    case 1:
                        printf("x is greater than y and y is greater than 5");
                        break;
                    case 2:
                        printf("x is less than y");
                        break;
                    case 3:
                        printf("x is equal to y");
                        break;
                    case 4:
                        printf("x and y are not related");
                        break;
                    case 5:
                        printf("x is greater than y and y is greater than 5 and x is even");
                        break;
                    case 6:
                        printf("x is less than y and x is even");
                        break;
                    case 7:
                        printf("x is equal to y and x is even");
                        break;
                    case 8:
                        printf("x and y are not related and x is even");
                        break;
                }
                printf("x is not greater than y");
                int result = f(x + y);  // Call f with the sum of x and y
                printf("%d", result);
                int i = 0;
                while(i < 1000000) {
                    if(i % 2 == 0) {
                        printf("i is even: %d", i);
                    } else {
                        printf("i is odd: %d", i);
                    }
                    i++;
                }
                return 0;
            }
        
            