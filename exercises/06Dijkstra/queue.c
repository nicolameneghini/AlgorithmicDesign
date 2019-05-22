#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

//------------------- ***** QUEUES ***** ---------------------------

//allocates space for  a queue and initializes its parameters
struct arrQueue *build_arrQueue(unsigned int capacity)
{
    struct arrQueue *queue = malloc(sizeof(struct arrQueue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node *)malloc(sizeof(struct Node) * capacity);

    for (unsigned int i = 0; i < queue->capacity; ++i)
        queue->array[i].distance = INT64_MAX;

    return queue;
}

void free_queue(struct arrQueue *queue)
{
    for (unsigned int i = 0; i < queue->capacity; i++)
        free_node(&queue->array[i]);
}

//it finds the nodes whose distance is the minimum. Also it puts this node at the end of the queue and since it also decreases the size by one,
//this is equivalent to taking it off. This beacuase the next for cycle won't reach it
struct Node *extractmin_arrQueue(struct arrQueue *queue)
{
    unsigned int min_index = queue->front;
    struct Node tmp = queue->array[min_index];
    int min = tmp.weight;

    for (unsigned int i = queue->front; i < queue->size + queue->front; i++)
    {
        tmp = queue->array[i];

        if (tmp.weight < min)
        {
            min = tmp.weight;
            min_index = i;
        }
    }

    /*  printf("front: %d, size: %d, return: %d\n", queue->front, queue->size, min);
    for (unsigned int i = 0; i < queue->capacity; i++)
    {
        printf("queue %f: \n", queue->array[i].distance);
    }
    printf("---\n");*/

    node_swap(&queue->array[min_index], &queue->array[0]);
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return &queue->array[min_index];
}

//puts a new element
void enqueue(struct arrQueue *queue, struct Node *elem)
{

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = *elem;
    queue->size += 1;
}

int is_empty_arrQueue(struct arrQueue *queue) { return queue->size == 0; }