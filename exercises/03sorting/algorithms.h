#ifndef __ALGORITHMS__

#define __ALGORITHMS__

#include <stdlib.h>

void swap(double *A, unsigned int i, unsigned int j);
void int_swap(int *A, unsigned int i, unsigned int k);
int FindMax(int *A, size_t length_of_A);

struct vector
{
    size_t size;
    double *elem;
};

void insertion_sort(double *A, unsigned int n);

unsigned int partition(double *A, unsigned int l, unsigned int n);

void quick_sort(double *A, unsigned int l, unsigned int n);

void bubble_sort(double *A, unsigned int n);

//unsigned int di_find(double *A, unsigned int l, unsigned int n, double a);

void HeapSort(int *A, size_t n);

int *CountingSort(int *A, int *B, size_t length_of_A);

void BucketSort(double *A, size_t length_of_A);

void append(double value, struct vector *vec);

void SelectSort(int *arr, int n);

#endif //__ALGORITHMS__