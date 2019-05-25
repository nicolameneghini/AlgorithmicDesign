#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "algorithms.h"
#include "../05heap/heap.h"

#define N 2000
#define min 0
#define max 10000

void randomly_fill_double(double *A, int length_of_A)
{
    for (unsigned int i = 0; i < length_of_A; i++)
        A[i] = min + (max - min) * lrand48() / RAND_MAX;
}

void randomly_fill_int(int *A, int length_of_A)
{
    for (unsigned int i = 0; i < length_of_A; i++)
        A[i] = min + lrand48() % (max - min + 1);
}

double get_execution_time(const struct timespec b_time,
                          const struct timespec e_time)
{
    return (e_time.tv_sec - b_time.tv_sec) +
           (e_time.tv_nsec - b_time.tv_nsec) / 1E9;
}

int main()
{
    struct timespec b_time, e_time;
    srand(10);

    FILE *ssort;

    double *SelectSorted = (double *)malloc(sizeof(double) * N);
    double *A = (double *)malloc(sizeof(double) * N);

    for (int i = 0; i < N; i++)
        A[i] = i;

    for (int i = 0; i < N; i++)
    { // shuffle array
        double temp = A[i];
        int randomIndex = rand() % N;
        A[i] = A[randomIndex];
        A[randomIndex] = temp;
    }

    clock_gettime(CLOCK_REALTIME, &b_time);
    for (unsigned int i = 1; i <= N; i++)
        SelectSorted[i - 1] = Select(A, i, 1, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("Select algorithm: %lf\n", get_execution_time(b_time, e_time));

    ssort = fopen("select.txt", "w");
    for (unsigned int i = 0; i < N; i++)
        fprintf(ssort, "%d %f \n", i, SelectSorted[i]);
    fclose(ssort);

    free(A);
    free(SelectSorted);
    return 0;
}
