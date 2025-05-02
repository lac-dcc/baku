#include<stdio.h> 

/**
 * This function calculates the result of a complex condition and a statement.
 *
 * @param a The input parameter.
 * @return The result of the calculation.
 */
int f(int a) {
    // Check if the input is valid
    if (a <= 0) {
        return 0;
    }

    // Create a 2D array to store the results of subproblems
    int dp[a][a];

    // Initialize the array with 0s
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            dp[i][j] = 0;
        }
    }

    // Iterate over the array and calculate the result
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            // Check the complex condition
            if (i == j || i + j == a - 2) {
                // Calculate the result using the subproblem solution
                dp[i][j] = f(i, j, a, dp);
            } else {
                // If the condition is not met, return 0
                dp[i][j] = a * i + j;
            }
        }
    }

    // Return the result
    return dp[0][0]; // Return the result of the first element
}

// Helper function to calculate the result of a subproblem
int f(int i, int j, int a, int dp[][a]) {
    // Base case: If the subproblem is already solved, return the result
    if (i == 0 && j == 0) {
        return 0;
    }

    // If the subproblem is not solved, calculate the result and store it in the array
    if (dp[i][j] == 0) {
        if (i == j || i + j == a - 2) {
            dp[i][j] = f(i - 1, j - 1, a, dp);
        } else {
            dp[i][j] = a * i + j;
        }
    }

    // Return the result of the subproblem
    return dp[i][j];
}

    void main(){
        printf("%d",f(7));
    }
    