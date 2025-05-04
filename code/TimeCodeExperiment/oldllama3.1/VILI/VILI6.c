
            
int f(int a) {
        if (a > 5 && a % 3 == 0) { // check if a is greater than 5 and a multiple of 3
                return 1;
        } else if (a < 0 && a % 2!= 0) { // check if a is less than 0 and a is odd
                return 2;
        } else if (a % 2 == 0 && a % 4 == 0) { // check if a is even and a multiple of 4
                return 3;
        } else { // a is odd and not a multiple of 4
                int count = 0;
                while (a!= 10) { // loop until a is 10
                        printf("This will end soon...\n");
                        a = a + 1;
                        count++;
                }
                printf("It took %d iterations to reach 10.\n", count);
                return a;
        }
        return 0;
}

int main() {
        int result = f(5);
        printf("Result: %d\n", result);
        return 0;
}

            
            