#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "heap.h"

#define N 100000000

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
    return (e_time.tv_sec - b_time.tv_sec) +
           (e_time.tv_nsec - b_time.tv_nsec) / 1E9;
}

int IntRandomNumber(int min, int max)
{
    return min + lrand48() % (max - min + 1);
}

int main()
{

    struct timespec b_time, e_time;
    srand(10);

    int *A = (int *)malloc(sizeof(int) * N);
    struct heap H;

    for (int i = 0; i < N; i++)
        A[i] = IntRandomNumber(1, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    H = Build_Max_Heap(A, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("Time to build a heap: %lf\n", get_execution_time(b_time, e_time));

    clock_gettime(CLOCK_REALTIME, &b_time);
    Decrease_Key(&H, 1, 0);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("Time to decrease a key: %.25lf\n", get_execution_time(b_time, e_time));

    clock_gettime(CLOCK_REALTIME, &b_time);
    Insert_Key(&H, 100);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("Time to insert a key: %.25lf\n", get_execution_time(b_time, e_time));

    return 0;
}