#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "algorithms.h"
#include "../05heap/heap.h"

#define N 10
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
    FILE *ssort;
    /*------*/

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

    printf("insertion sort: %lf\n", get_execution_time(b_time, e_time));

    /*------*/
    double *QuickSorted = (double *)malloc(sizeof(double) * N);

    randomly_fill_double(QuickSorted, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    quick_sort(QuickSorted, 0, N - 1);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("quick sort: %lf\n", get_execution_time(b_time, e_time));

    /* qsort = fopen("quicksort.txt", "w");
    
    for(unsigned int i = 0; i < N; i++)
        fprintf(qsort, "%d %f \n", i, QuickSorted[i]);
    
    fclose(qsort);*/

    free(QuickSorted);

    /*------*/
    int *HeapSorted = (int *)malloc(sizeof(int) * N);

    randomly_fill_int(HeapSorted, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    HeapSort(HeapSorted, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("heap sort: %lf\n", get_execution_time(b_time, e_time));

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

    printf("counting sort: %lf\n", get_execution_time(b_time, e_time));

    //for(unsigned int i = 900; i < 910; i++) printf("%d\n", res_CountingSorted[i]);

    /*csort = fopen("countingsort.txt", "w");
    for(unsigned int i = 0; i < N; i++)
        fprintf(csort, "%d %d \n", i, res_CountingSorted[i]);
    fclose(csort);
    free(CountingSorted);*/
    free(res_CountingSorted);

    /*------*/
    int *RadixSorted = (int *)malloc(sizeof(int) * N);
    int *res_RadixSorted = (int *)malloc(sizeof(int) * N);
    randomly_fill_int(RadixSorted, N);

    clock_gettime(CLOCK_REALTIME, &b_time);
    RadixSort(RadixSorted, res_RadixSorted, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("radix sort: %lf\n", get_execution_time(b_time, e_time));

    //for(unsigned int i = 0; i < 100; i++) printf("%d\n", res_RadixSorted[i]);

    /*rsort = fopen("radixsorted.txt", "w");
    for(unsigned int i = 0; i < N; i++)
        fprintf(rsort, "%d %d \n", i, res_RadixSorted[i]);
    fclose(rsort);*/

    free(RadixSorted);
    free(res_RadixSorted);

    double *BucketSorted = (double *)malloc(sizeof(double) * N);

    randomly_fill_double(BucketSorted, N);

    for (unsigned int i = 0; i < N; i++)
        BucketSorted[i] /= (max + 1);

    clock_gettime(CLOCK_REALTIME, &b_time);
    BucketSort(BucketSorted, N);
    clock_gettime(CLOCK_REALTIME, &e_time);

    printf("Bucket sort: %lf\n", get_execution_time(b_time, e_time));

    /*bsort = fopen("bucketsort.txt", "w");
    for(unsigned int i = 0; i < N; i++)
        fprintf(bsort, "%d %f \n", i, BucketSorted[i]);
    fclose(bsort);*/

    free(BucketSorted);

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
        SelectSorted[i - 1] = Select(A, i, 0, N - 1);
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
