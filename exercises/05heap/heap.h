#ifndef __HEAP__
#define __HEAP__

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct heap
{
    int *node;
    size_t size;
};
struct heap *constructor(int capacity);
size_t Left(size_t i);
size_t Right(size_t i);
size_t Parent(size_t i);
size_t Get_Root(struct heap *H);
bool Is_Root(size_t i);
bool Is_Valid_Node(struct heap *H, size_t i);
int Minimum(struct heap *H);
void Heapify(struct heap *H, size_t i);
void Max_Heapify(struct heap *H, size_t i);
int Remove_Minimum(struct heap *H);
void Decrease_Key(struct heap *H, size_t i, int value);
void Insert_Key(struct heap *H, int value);
void destructor(struct heap *H);
void hswap(struct heap *H, int i, int m);
struct heap Build_Max_Heap(int *A, size_t length_of_A);
#endif // __HEAP__