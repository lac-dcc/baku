
int f(int a) {
    int b = 0;
    // Initialize a counter for the number of times the number is divisible by 2
    while (a > 0 && a % 2 == 0 && b < 10) {
        // Check if the number is even
        if (a % 2 == 0) {
            // Increment the counter and divide the number by 2
            b++;
            a = a / 2;
        } else {
            // If the number is not even, break the loop
            break;
        }
    }
    // Return the count of iterations
    return b;
}

int main() {
    int num = 16;
    int result = f(num);
    printf("The number %d is divisible by 2 %d times.\n", num, result);
    return 0;
}

