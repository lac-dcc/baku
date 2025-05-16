
/**
 * @file    main.c
 * @brief   A simple program that demonstrates a loop with a complex condition and statement inside.
 * @author  [Your Name]
 * @date    [Today's Date]
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief   Prints a message to the console with a given value.
 * @param   value The value to be printed.
 */
void print_value(int value) {
    printf("Value: %d\n", value);
}

int main() {
    int i = 0;
    while (i < 10 && i > 0) {
        printf("%d ", i);
        i++;
        while (i > 10 || i < 5) {
            printf("Dead loop is running: %d\n", i);
            if (i % 2 == 0) {
                printf("Even value: %d\n", i);
            }
            i = 10; // This line will cause the dead loop to exit immediately
        }
    }
    printf("\n");
    return 0;
}
