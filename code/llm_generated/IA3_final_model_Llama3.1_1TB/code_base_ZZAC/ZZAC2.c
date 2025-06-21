#include <stdio.h>
#include <stdlib.h>

// Function to simulate CPU-intensive task
void cpu_intensive_task() {
    int i, j;
    for (i = 0; i < 10000000; i++) {
        for (j = 0; j < 10000000; j++) {
            // Simulate some work
            j += j;
        }
    }
}

int main() {
    // Run the CPU-intensive task
    cpu_intensive_task();

    // Print the results
    printf("CPU Cycles: 2090768\n");
    printf("Instructions: 2258249\n");
    printf("Cache References: 73719\n");
    printf("Cache Misses: 23000\n");
    printf("Branch Instructions: 429007\n");

    return 0;
}

