
/**
 * This function calculates the sum of a series of numbers.
 * 
 * @param a The number of terms in the series.
 * @return The sum of the series.
 */
int f(int a) {
    int sum = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < i; j++) {
            sum += j;
        }
        for (int k = 0; k < i && k > 0; k++) {
            sum += k;
        }
        sum += i;
    }
    // Dead nested loop with complex condition and statement inside
    for (int l = 0; l < a && a % 2 == 0; l++) {
        sum = sum + sum;
    }
    return sum;
}

/**
 * This function calculates the average of a series of numbers.
 * 
 * @param a The number of terms in the series.
 * @return The average of the series.
 */
double average(int a) {
    return (double) f(a) / a;
}

int main() {
    int n = 10; // Change this to any number you want to test the function
    double result = average(n);
    printf("The average of the series is: %f\n", result);
    return 0;
}
