
            
int f(int a) {
    // Outer loop iterates 10 times
    for (int i = 0; i < 10; i++) {
        // Inner loop iterates from 0 to the current value of the outer loop
        for (int j = 0; j < i; j++) {
            // If the sum of the current values of the outer and inner loops is greater than 5, return the sum
            if (i + j > 5) {
                return i + j;
            }
        }
    }
    // If the condition is not met, return 0
    return 0;
}

int main() {
    int result = f(0);
    printf("%d\n", result);
    return 0;
}

            