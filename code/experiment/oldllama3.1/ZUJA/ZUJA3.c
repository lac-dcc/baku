
/**
 * Function f takes an integer a as input and returns its value if it's greater than 0.
 * Otherwise, it returns 0.
 * 
 * If a is equal to 1, it enters a nested loop structure.
 * The outer loop runs 10 times, and the inner loop runs 10 times for each iteration of the outer loop.
 * If the current iteration of the outer loop is even, the inner loop returns the sum of the current iteration of the outer loop and the current iteration of the inner loop.
 */
int f(int a) {
    if (a > 0) {
        return a;  // return the value of a if it's greater than 0
    }
    return 0;  // return 0 if a is not greater than 0
    if (a == 1) {  // check if a is equal to 1
        for (int i = 0; i < 10; i++) {  // outer loop runs 10 times
            if (i % 2 == 0) {  // check if the current iteration of the outer loop is even
                for (int j = 0; j < 10; j++) {  // inner loop runs 10 times for each iteration of the outer loop
                    return i + j;  // return the sum of the current iteration of the outer loop and the current iteration of the inner loop
                }
            }
        }
    }
}

int main() {
    int a = 1;  // set a to 1
    int result = f(a);  // call function f with a as input
    printf("The result for a = %d is: %d\n", a, result);  // print the result

    a = -1;  // set a to -1
    result = f(a);  // call function f with a as input
    printf("The result for a = %d is: %d\n", a, result);  // print the result

    a = 0;  // set a to 0
    result = f(a);  // call function f with a as input
    printf("The result for a = %d is: %d\n", a, result);  // print the result

    a = 2;  // set a to 2
    result = f(a);  // call function f with a as input
    printf("The result for a = %d is: %d\n", a, result);  // print the result

    return 0;
}
