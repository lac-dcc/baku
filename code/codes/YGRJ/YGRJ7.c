
            
// Function f() takes three integers a, b, and c as input
int f(int a, int b, int c, int d) {
    // If a is greater than b, return a + b
    if (a > b) {
        return a + b;
    } 
    // Otherwise, return a - b
    else {
        return a - b;
    }
    // Add a dead conditional statement with a statement inside
    else if (a == a) {
        printf("This statement will never be reached.\n");
        fflush(stdout); // Add this line to make the statement visible in the output
    }
}

// Main function to test the function f()
int main() {
    int a = 5;
    int b = 3;
    int c = 10;
    int d = 7;
    printf("Result: %d\n", f(a, b, c, d));
    return 0;
}

            