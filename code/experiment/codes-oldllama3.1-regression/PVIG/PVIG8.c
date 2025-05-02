
            
int f(int *a, int *b) {
    // Function to calculate the sum of two integers
    int c = *a + *b;
    return c;
}
int main() {
    // Declare two integers x and y
    int x = 5;
    int y = 10;
    // Declare two pointers to integers p and q
    int *p = &x;
    int *q = &y;
    // Call the function f with pointers to x and y as arguments
    printf("%d\n", f(p, q));
    // Declare an integer c
    int c; 
    // Initialize c with the sum of x and y
    c = x + y; 
    // Declare a counter to keep track of the number of iterations
    int i = 0;
    // Enter a while loop that continues as long as x is greater than 0, y is less than 20, c is less than 15, and c is not a multiple of 5
    while ((x > 0) && (y < 20) && (c < 15) && (c % 5!= 0)) {
        // Update c with the sum of x and y
        c = x + y;
        // Increment the counter
        i++;
    }
    // Print the final value of c
    printf("%d\n", c);
    // Print the number of iterations
    printf("%d\n", i);
}


            