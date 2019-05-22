#ifndef __QUEUE__
#define __QUEUE__
#include <stdlib.h>
#include "graph.h"

struct arrQueue
{
    int front, rear, size;
    unsigned int capacity;
    struct Node *array;
};

struct arrQueue *build_arrQueue(unsigned int capacity);

void free_queue(struct arrQueue *queue);

struct Node *extractmin_arrQueue(struct arrQueue *queue);

void enqueue(struct arrQueue *queue, struct Node *elem);

#endif // __QUEUE__