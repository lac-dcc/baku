Do me a code in c for compilers, with 1024 of tokens max, that contains 40% bandwidth utilization. Without coments, please.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j;
    int n = 1024;
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *c = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i] += a[j] * b[i - j];
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j;
    int n = 1024;
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *c = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i] += a[j] * b[i - j];
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j;
    int n = 1024;
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *c = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i] += a[j] * b[i - j];
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j;
    int n = 1024;
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *c = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i] += a[j] * b[i - j];
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", c