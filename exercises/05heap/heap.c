#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "heap.h"

void hswap(struct heap *H, int i, int m)
{
    int tmp = H->node[i];
    H->node[i] = H->node[m];
    H->node[m] = tmp;
}

struct heap *constructor(int capacity)
{
    struct heap *H;
    H = malloc(sizeof(struct heap));
    H->node = (int *)malloc(sizeof(int) * capacity);

    H->size = 0;
    return H;
}

size_t Left(size_t i) { return (2 * i) + 1; }

size_t Right(size_t i) { return (2 * i) + 2; }

size_t Parent(size_t i) { return floor(i / 2); }

size_t Get_Root(struct heap *H) { return 0; }

bool Is_Root(size_t i) { return i == 0; }

bool Is_Valid_Node(struct heap *H, size_t i) { return i <= H->size; }

int Minimum(struct heap *H) { return H->node[0]; }

void Heapify(struct heap *H, size_t i)
{
    size_t m = i, j = -1;

    while (j != m)
    {
        j = m;
        size_t child[2];
        child[0] = Left(i);
        child[1] = Right(i);

        for (size_t k = 0; k < 2; k++)
        {
            if (Is_Valid_Node(H, child[k]) && H->node[child[k]] < H->node[i])
                m = child[k];
        }

        if (j != m)
        {
            hswap(H, j, m);
        }
    }
}

/*void Heapify(struct heap *H, size_t i)
{
    size_t m = i;

    if (Is_Valid_Node(H, Left(i)) && H->node[Left(i)] < H->node[i])
        m = Left(i);

    if (Is_Valid_Node(H, Right(i)) && H->node[Right(i)] < H->node[m])
        m = Right(i);

    if (i != m)
    {
        hswap(H, i, m);
        Heapify(H, m);
    }
}*/

void Max_Heapify(struct heap *H, size_t i)
{
    size_t m = i;

    if (Is_Valid_Node(H, Left(i)) && H->node[Left(i)] > H->node[m])
        m = Left(i);

    if (Is_Valid_Node(H, Right(i)) && H->node[Right(i)] > H->node[m])
        m = Right(i);

    if (i != m)
    {
        hswap(H, i, m);

        Max_Heapify(H, m);
    }
}

int Remove_Minimum(struct heap *H)
{
    int min = H->node[0];
    H->node[0] = H->node[H->size - 1];
    H->size -= 1;
    Heapify(H, 0);
    return min;
}

void Decrease_Key(struct heap *H, size_t i, int value)
{
    if (H->node[i] <= value)
        printf("%d is not smaller than the node (%d)\n", value, H->node[i]);

    H->node[i] = value;

    while (!(Is_Root(i) || H->node[Parent(i)] <= H->node[i]))
    {
        hswap(H, i, Parent(i));
        i = Parent(i);
    }
}

void Insert_Key(struct heap *H, int value)
{
    H->size += 1;
    H->node[H->size - 1] = value + 1;
    Decrease_Key(H, H->size - 1, value);
}

struct heap Build_Max_Heap(int *A, size_t length_of_A)
{
    struct heap alias = {A, length_of_A};

    for (size_t i = Parent(length_of_A) - 1; i >= 0; i--)
    {
        Heapify(&alias, i);
        if (i == 0)
            break;
    }

    return alias;
}

void destructor(struct heap *H)
{
    free(H->node);
    free(H);
}