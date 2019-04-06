#include <stdio.h>
#include <stdbool.h>

#include "heap.h"

int IntRandomNumber(int min, int max)
{
    return min + lrand48() % (max - min + 1);
}

int main()
{
    struct heap *H = constructor(11);
    //40 70 70 64 62 36 26 74 20 42

    for (int i = 0; i < 10; i++)
    {
        Insert_Key(H, IntRandomNumber(0, 20));
    }

    //printf("minimum is %d\n", Minimum(H));
    //Decrease_Key(H, 2, 1);
    //printf("minimum is %d\n", Minimum(H));
    for (size_t i = 0; i < H->size; i++)
        printf("%d ", H->node[i]);
    printf("\n");
    destructor(H);

    return 0;
}