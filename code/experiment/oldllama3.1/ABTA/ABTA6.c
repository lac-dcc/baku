

/**
 * This function returns a value based on the condition i > j in two nested loops.
 * The function returns a when i is greater than j, and 0 otherwise.
 */
int f(int a) {
    int result = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i > j) {
                result = a;
            }
        }
    }
    return result;
}

int main() {
    int result = f(1); // Call the f function with a value
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i > j && j % 2 == 0) || (i < j && j % 3 == 0)) {
                printf("i: %d, j: %d\n", i, j);
                count++;
                if (count > 100) {
                    break; // Break the loop after 100 iterations
                }
            }
        }
    }
    return 0;
}

