#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "algorithms.h"
#include "../05heap/heap.h"

#define N 75000
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
    /* FILE* inssort;
    FILE* qsort;
    FILE* hsort;
    FILE* csort;
    FILE* rsort;
    FILE* bsort;*/
    /*------*/
    FILE *times = fopen("timing.txt", "a");

    fprintf(times, "%d ", N);

    double *InsertionSorted = (double *)malloc(sizeof(double) * N);

    randomly_fill_double(InsertionSorted, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    insertion_sort(InsertionSorted, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    /* inssort = fopen("insertionsort.txt", "w");
    for(unsigned int i = 0; i < N; i++)
        fprintf(inssort, "%d %f \n", i, InsertionSorted[i]);
    fclose(inssort);*/
    free(InsertionSorted);

    fprintf(times, "%.5lf ", get_execution_time(b_time, e_time));

    /*------*/

    double *InsertionSorted_worst = (double *)malloc(sizeof(double) * N);

    for (unsigned int i = 0; i < N; i++)
        InsertionSorted_worst[i] = N - i;

    clock_gettime(CLOCK_REALTIME, &b_time);
    insertion_sort(InsertionSorted_worst, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    /* inssort = fopen("insertionsort.txt", "w");
    for(unsigned int i = 0; i < N; i++)
        fprintf(inssort, "%d %f \n", i, InsertionSorted[i]);
    fclose(inssort);*/
    free(InsertionSorted_worst);

    fprintf(times, "\t %.5lf", get_execution_time(b_time, e_time));

    /*------*/

    double *InsertionSorted_best = (double *)malloc(sizeof(double) * N);

    for (unsigned int i = 0; i < N; i++)
        InsertionSorted_best[i] = i;

    clock_gettime(CLOCK_REALTIME, &b_time);
    insertion_sort(InsertionSorted_best, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    /* inssort = fopen("insertionsort.txt", "w");
    for(unsigned int i = 0; i < N; i++)
        fprintf(inssort, "%d %f \n", i, InsertionSorted[i]);
    fclose(inssort);*/
    free(InsertionSorted_best);

    fprintf(times, "\t %.5lf", get_execution_time(b_time, e_time));

    /*------*/

    double *QuickSorted = (double *)malloc(sizeof(double) * N);

    randomly_fill_double(QuickSorted, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    quick_sort(QuickSorted, 0, N - 1);
    clock_gettime(CLOCK_REALTIME, &e_time);

    fprintf(times, "\t %.5lf ", get_execution_time(b_time, e_time));

    /* qsort = fopen("quicksort.txt", "w");
    
    for(unsigned int i = 0; i < N; i++)
        fprintf(qsort, "%d %f \n", i, QuickSorted[i]);
    
    fclose(qsort);*/
    /*------*/

    free(QuickSorted);

    double *QuickSorted_worst = (double *)malloc(sizeof(double) * N);

    randomly_fill_double(QuickSorted_worst, N);

    int worst_pivot = FindMaxd(QuickSorted_worst, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    quick_sort_pivot(QuickSorted_worst, 0, N - 1, worst_pivot);
    clock_gettime(CLOCK_REALTIME, &e_time);

    fprintf(times, "\t %.5lf ", get_execution_time(b_time, e_time));

    free(QuickSorted_worst);

    /*------*/

    double *QuickSorted_best = (double *)malloc(sizeof(double) * N);

    randomly_fill_double(QuickSorted_best, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    quick_sort_pivot(QuickSorted_best, 0, N - 1, N / 2);
    clock_gettime(CLOCK_REALTIME, &e_time);

    fprintf(times, "\t %.5lf ", get_execution_time(b_time, e_time));

    free(QuickSorted_best);

    /*------*/
    int *HeapSorted = (int *)malloc(sizeof(int) * N);

    randomly_fill_int(HeapSorted, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    HeapSort(HeapSorted, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    fprintf(times, "\t %.5lf ", get_execution_time(b_time, e_time));

    /* hsort = fopen("heapsort.txt", "w");
    for(unsigned int i = 0; i < N; i++)
        fprintf(hsort, "%d %d \n", i, HeapSorted[i]);
    fclose(hsort);*/

    free(HeapSorted);

    /*------*/
    int *CountingSorted = (int *)malloc(sizeof(int) * N);
    int *res_CountingSorted = (int *)malloc(sizeof(int) * N);

    randomly_fill_int(CountingSorted, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    res_CountingSorted = CountingSort(CountingSorted, res_CountingSorted, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    free(res_CountingSorted);

    fprintf(times, "\t %.5lf\n ", get_execution_time(b_time, e_time));

    return 0;
}
