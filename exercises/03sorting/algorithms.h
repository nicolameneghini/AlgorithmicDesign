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

unsigned int partition(double *A, unsigned int l, unsigned int n, unsigned int ind_pivot);

void quick_sort(double *A, unsigned int l, unsigned int n);

void bubble_sort(double *A, unsigned int n);

//unsigned int di_find(double *A, unsigned int l, unsigned int n, double a);

void HeapSort(int *A, size_t n);

int *CountingSort(int *A, int *B, size_t length_of_A);

void RadixSort(int *A, int *B, size_t length_of_A);

void BucketSort(double *A, size_t length_of_A);

void append(double value, struct vector *vec);


size_t find_in_array(double *A, double target, size_t length_of_A);
double Select(double *A, size_t i, size_t l, size_t length_of_A);

size_t select_pivot(double *A, size_t group_by, size_t begin, size_t end);
#endif //__ALGORITHMS__