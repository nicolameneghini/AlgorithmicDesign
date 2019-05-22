#ifndef __HEAP__
#define __HEAP__

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "graph.h"

struct heap
{
    struct Node *tree;
    int size;
    int capacity;
};
struct heap *heap_constructor(int capacity);

int Left(int i);

int Right(int i);

int Parent(int i);

int Get_Root(struct heap *H);

bool Is_Root(int i);

bool Is_Valid_Node(struct heap *H, int i);

struct Node *Minimum(struct heap *H);

void Heapify(struct heap *H, int i);

void h_swap(struct heap *H, int i, int m);

void Max_Heapify(struct heap *H, int i);

void Remove_Minimum(struct heap *H);

void Decrease_Key(struct heap *H, int i, struct Node *node);

void Insert_Key(struct heap *H, struct Node *node);

void destructor(struct heap *H);

void hswap(struct heap *H, int i, int m);

struct heap Build_Max_Heap(int *A, int length_of_A);

#endif // __HEAP__