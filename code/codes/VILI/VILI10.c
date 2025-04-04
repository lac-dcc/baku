
int f(int a, int b, int c) {
        if (a > 5 && a % 3 == 0 && b > 5 && b % 3 == 0 && c > 5 && c % 3 == 0) { // check if a is greater than 5 and a multiple of 3, and b is greater than 5 and a multiple of 3, and c is greater than 5 and a multiple of 3
                return 1;
        } else if (a < 0 && a % 2!= 0 && c < 0 && c % 2!= 0 && b > 0 && b % 2 == 0) { // check if a is less than 0 and a is odd, and c is less than 0 and a is odd, and b is greater than 0 and even
                return 2;
        } else if (a % 2 == 0 && a % 4 == 0 && b % 2 == 0 && b % 4 == 0 && c % 2 == 0 && c % 4 == 0) { // check if a is even and a multiple of 4, and b is even and a multiple of 4, and c is even and a multiple of 4
                return 3;
        } else { // a is odd and not a multiple of 4, or b is odd and not a multiple of 4, or c is odd and not a multiple of 4
                if (a == 10 && b == 10 && c == 10) { // check if a, b, and c are all already 10
                        return 10;
                }
                int count = 0;
                while (a!= 10 || b!= 10 || c!= 10) { // loop until a, b, and c are all 10
                        printf("This will end soon...\n");
                        a = a + 1;
                        b = b + 1;
                        c = c + 1;
                        count++;
                }
                printf("It took %d iterations to reach 10.\n", count);
                return a;
        }
        return 0;
}

int main() {
        int result = f(5, 10, 15);
        printf("Result: %d\n", result);
        return 0;
}
