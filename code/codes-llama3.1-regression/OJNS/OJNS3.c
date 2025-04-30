
/**
 * @file    main.c
 * @brief   A simple program that demonstrates a loop with a complex condition and statement inside.
 * @author  [Your Name]
 * @date    [Today's Date]
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0;
    while (i < 10 && i > 0) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
    return 0;
}
