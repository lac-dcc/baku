
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/perf_event.h>
#include <linux/perf.h>

int main() {
    int fd;
    struct perf_event_attr pe;
    long long unsigned int counter_value;

    /* Set up the performance counter */
    memset(&pe, 0, sizeof(pe));
    pe.type = PERF_TYPE_HARDWARE;
    pe.size = sizeof(pe);
    pe.config = PERF_COUNT_HW_CPU_CYCLES;
    pe.sample_period = 1000000;
    pe.sample_period = 1000000;
    pe.wakeup_events = 1;

    /* Open the performance counter */
    fd = perf_event_open(&pe, 0, -1, -1, 0);
    if (fd < 0) {
        perror("perf_event_open");
        exit(EXIT_FAILURE);
    }

    /* Enable the performance counter */
    if (perf_event_enable(fd) < 0) {
        perror("perf_event_enable");
        exit(EXIT_FAILURE);
    }

    /* Read the performance counter */
    while (1) {
        if (perf_read_user(fd, &counter_value) < 0) {
            perror("perf_read_user");
            exit(EXIT_FAILURE);
        }
        printf("CPU Cycles: %llu\n", counter_value);
    }

    /* Close the performance counter */
    if (perf_event_disable(fd) < 0) {
        perror("perf_event_disable");
        exit(EXIT_FAILURE);
    }
    close(fd);

    return 0;
}
