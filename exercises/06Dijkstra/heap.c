#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "heap.h"

struct heap *heap_constructor(int capacity)
{
    struct heap *H = (struct heap *)malloc(sizeof(struct heap));

    H->size = 0;

    H->capacity = capacity;

    H->tree = (struct Node *)malloc(sizeof(struct Node) * capacity);

    for (unsigned int i = 0; i < H->capacity; ++i)
        H->tree[i].distance = INT64_MAX;

    return H;
}

void hswap(struct heap *H, int i, int m)
{
    struct Node tmp = H->tree[i];
    H->tree[i] = H->tree[m];
    H->tree[m] = tmp;
}

int Left(int i) { return (2 * i) + 1; }

int Right(int i) { return (2 * i) + 2; }

int Parent(int i) { return floor(i / 2); }

int Get_Root(struct heap *H) { return 0; }

bool Is_Root(int i) { return i == 0; }

bool Is_Valid_Node(struct heap *H, int i) { return i <= H->size; }

struct Node *Minimum(struct heap *H) { return &H->tree[0]; }

void Heapify(struct heap *H, int i)
{
    int m = i;

    if (Is_Valid_Node(H, Left(i)) && H->tree[Left(i)].distance < H->tree[i].distance)
        m = Left(i);

    if (Is_Valid_Node(H, Right(i)) && H->tree[Right(i)].distance < H->tree[m].distance)
        m = Right(i);

    if (i != m)
    {
        hswap(H, i, m);
        Heapify(H, m);
    }
}
void Remove_Minimum(struct heap *H)
{

    H->tree[0] = H->tree[H->size - 1];

    H->size--;

    Heapify(H, 0);

    /*printf(" size: %d, return: %f\n", H->size, H->tree[0].distance);

    for (unsigned int i = 0; i < H->capacity; i++)
    {
        printf("queue%d: %f\n", i, H->tree[i].distance);
    }

    printf("----\n");*/
}

void Decrease_Key(struct heap *H, int i, struct Node *node)
{
    // if (H->tree[i].distance <= node->distance)
    //     printf("%f is not smaller than the node", H->tree[i].distance);

    H->tree[i] = *node;

    while (!(Is_Root(i) || H->tree[Parent(i)].distance <= H->tree[i].distance))
    {
        //tmp = Parent(i);

        hswap(H, i, Parent(i));
        i = Parent(i);
    }
}

void Insert_Key(struct heap *H, struct Node *node)
{
    H->size++;
    H->tree[H->size].distance = INT64_MAX;

    Decrease_Key(H, H->size - 1, node);
}

void destructor(struct heap *H)
{
    free(H->tree);
    free(H);
}