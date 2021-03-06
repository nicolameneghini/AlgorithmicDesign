#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "algorithms.h"
#include "../05heap/heap.h"

void swap(double *A, unsigned int i, unsigned int k)
{
    double tmp;
    tmp = A[i];
    A[i] = A[k];
    A[k] = tmp;
}

void int_swap(int *A, unsigned int i, unsigned int k)
{
    int tmp;
    tmp = A[i];
    A[i] = A[k];
    A[k] = tmp;
}

int FindMax(int *A, size_t length_of_A)
{
    int max = A[0];

    for (unsigned int i = 1; i < length_of_A; i++)
        if (A[i] > max)
            max = A[i];

    return max;
}

int FindMaxd(double *A, int length_of_A)
{
    double max = A[0];
    unsigned int i = 0;

    for (i = 1; i < length_of_A; i++)
        if (A[i] > max)
            max = A[i];

    return i;
}

void insertion_sort(double *A, unsigned int n)
{

    unsigned int j;

    for (unsigned int i = 1; i < n; i++)
    {
        j = i;

        while (j >= 0 && A[j] < A[j - 1])
        {
            swap(A, j - 1, j);
            j--;
        }
    }
}

unsigned int partition(double *A, unsigned int l, unsigned int n, unsigned int ind_pivot)
{
    // pivot (Element to be placed at right position)
    double pivot = A[ind_pivot];

    unsigned int i = (l - 1); // Index of smaller element

    for (unsigned int j = l; j <= n - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (A[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(A, i, j);
        }
    }
    swap(A, i + 1, n);
    return i + 1;
}

void quick_sort(double *A, unsigned int l, unsigned int n)
{
    unsigned int pi;

    while (l < n)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(A, l, n, n);

        quick_sort(A, l, pi - 1); // Before pi
        l = pi + 1;               // After pi
    }
}

void quick_sort_pivot(double *A, unsigned int l, unsigned int n, unsigned int pivot)
{
    unsigned int pi;

    while (l < n)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        pi = partition(A, l, n, pivot);

        quick_sort(A, l, pi - 1); // Before pi
        l = pi + 1;               // After pi
    }
}

void bubble_sort(double *A, unsigned int n)
{

    while (n > 0)
    {
        unsigned int max_index = 0;
        for (unsigned int i = 0; i < n; i++)
        {
            if (A[i] > A[max_index])
                max_index = i;
        }

        swap(A, max_index, n - 1);
        n--;
    }
}

/*unsigned int di_find(double *A, unsigned int l, unsigned int n, double a)
{

    while (n >= l)
    {
        unsigned int middle = (unsigned int)(n - l) / 2;

        if (A[middle] == a)
            return middle;
        if (A[middle] > a)
            n = middle - 1;
        else
            l = middle + 1;
    }

    return -1;
}*/

void HeapSort(int *A, size_t n)
{

    struct heap H;
    H = Build_Max_Heap(A, n);
    H.size -= 1; //serve perché senno parte da n anziché n-1

    for (int i = n - 1; i > 0; i--)
    {
        hswap(&H, 0, i);
        H.size -= 1;
        Max_Heapify(&H, 0);
    }

    A = H.node;
}

int *CountingSort(int *A, int *B, size_t length_of_A)
{
    int k = FindMax(A, length_of_A);

    int *C = (int *)calloc(sizeof(int), k);

    for (unsigned int i = 0; i < length_of_A; i++)
        C[A[i]] = C[A[i]] + 1;

    for (unsigned int j = 1; j < k; j++)
        C[j] += C[j - 1];

    for (unsigned int i = length_of_A - 1; i >= 0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] = C[A[i]] - 1;

        if (i == 0)
            break;
    }

    return B;
}

void RadixSort(int *A, int *B, size_t length_of_A)
{

    int max = FindMax(A, length_of_A);

    for (unsigned int i = 1; max / i > 0; i *= 10)
    {

        int *count = (int *)calloc(sizeof(int), 10);

        for (unsigned int j = 0; j < length_of_A; j++)
            count[(A[j] / i) % 10]++;

        for (unsigned int j = 1; j < 10; j++)
            count[j] += count[j - 1];

        for (unsigned int j = length_of_A; j > 0; j--)
        {
            B[count[(A[j] / i) % 10] - 1] = A[j];
            count[(A[j] / i) % 10]--;
        }

        B[count[(A[0] / i) % 10] - 1] = A[0];
        count[(A[0] / i) % 10]--;

        for (int j = 0; j < length_of_A; j++)
            A[j] = B[j];

        free(count);
    }
}

void BucketSort(double *A, size_t length_of_A)
{
    struct vector *B = (struct vector *)malloc(sizeof(struct vector) * length_of_A); //ho fatto la struct vector per poter usare append. In append c'è bisogno
    //di passare la dimensione dell'array e l'unico modo per farlo è immagazzinarla nella struct

    for (unsigned int i = 0; i < length_of_A; i++)
    {
        int index = floor(A[i] * length_of_A);
        append(A[i], &B[index]);
    }

    int i = 0;

    for (unsigned int index = 0; index < length_of_A; index++)
    {
        for (unsigned int v = 0; v < B[index].size; v++)
        {
            insertion_sort(B[index].elem, B[index].size);

            A[i] = B[index].elem[v];
            i++;
        }
    }
}

void append(double value, struct vector *vec)
{
    //int length = sizeof(array) / sizeof(array[0]);

    double *tmp = (double *)malloc(sizeof(double) * (vec->size + 1));

    for (unsigned int i = 0; i < vec->size; i++)
    {
        tmp[i] = vec->elem[i];
    }

    free(vec->elem);

    tmp[vec->size] = value;
    vec->size++;
    vec->elem = tmp;
}

size_t select_pivot(double *A, size_t group_by, size_t begin, size_t end)
{
    //if only one chunk return the median

    if ((end - begin) <= group_by)
        return 0;
    else
    {
        double *medians = (double *)malloc(sizeof(double) * (end - begin) / group_by);

        for (unsigned int i = begin; i < end; i += group_by)
        {
            quick_sort((A + i * group_by), i, i + group_by - 1); //sorting each chunk
            size_t median = (i + (i + group_by - 1)) / 2;        //taking the median of each chunk
            medians[i / group_by] = A[median];
            //printf("begin %zu, end: %zu, median %zu, medians[i]: %f\n", begin, end, median, medians[i / group_by]);
        }

        size_t index = find_in_array(A, medians[((end - begin) / group_by) / 2], begin, end);

        // printf("index = %zu\n", index);

        return index;
        free(medians);
    }
}

size_t find_in_array(double *A, double target, size_t begin, size_t end)
{
    for (size_t i = begin; i <= end; i++)
        if (A[i] == target)
        {
            return i;
            break;
        }

    return (end - begin) / 2;
}

double Select(double *A, unsigned int i, unsigned int l, unsigned int length_of_A)
{
    size_t j;

    if (length_of_A - l <= 10)
        j = 0;

    else
        j = select_pivot(A, 5, l, length_of_A);

    unsigned int k = partition(A, l, length_of_A, j);

    if (i == k)
        return A[k];

    if (i < k)
        return Select(A, i, l, k - 1);

    return Select(A, i, k + 1, length_of_A);
}
