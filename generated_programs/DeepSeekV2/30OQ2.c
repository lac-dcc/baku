
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
    char buffer[256];

    /* Set up the performance event */
    memset(&pe, 0, sizeof(pe));
    pe.type = PERF_TYPE_HARDWARE;
    pe.size = sizeof(pe);
    pe.config = PERF_COUNT_HW_CPU_CYCLES;
    pe.sample_period = 1000000;
    pe.sample_type = PERF_SAMPLE_READ;

    /* Open the performance event */
    fd = perf_event_open(&pe, 0, -1, -1, 0);
    if (fd < 0) {
        perror("perf_event_open");
        exit(EXIT_FAILURE);
    }

    /* Enable the performance event */
    if (perf_event_enable(fd) < 0) {
        perror("perf_event_enable");
        exit(EXIT_FAILURE);
    }

    /* Read the performance event */
    while (1) {
        read(fd, buffer, sizeof(buffer));
        counter_value = perf_event_read(fd);
        printf("CPU Cycles: %llu\n", counter_value);
    }

    /* Close the performance event */
    close(fd);

    return 0;
}
