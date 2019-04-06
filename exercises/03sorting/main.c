#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algorithms.h"
#include "../05heap/heap.h"

double FloatRandomNumber(double min, double max)
{
    return min + (max - min) * lrand48() / RAND_MAX;
}

int IntRandomNumber(int min, int max)
{
    return min + lrand48() % (max - min + 1);
}

int main()
{

    size_t n = 10;

    int *A = malloc(sizeof(*A) * n);

    for (unsigned int i = 0; i < n; i++)
    {
        A[i] = IntRandomNumber(0, 20);
        printf("%d ", A[i]);
    }
    printf("\n");

    SelectSort(A, n);

    for (unsigned int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    free(A);
    return 0;
}
