#ifndef __DIJKSTRA__
#define __DIJKSTRA__
#include <stdlib.h>
#include "heap.h"

//each node contains a pointer to the next node and the relative node id together with the weight of the edge: Also, it
//stores the previous node: this should be useful in the Dijkstra algorithm.

struct arrQueue *build_arrQueue(unsigned int capacity);

int is_empty_arrQueue(struct arrQueue *queue);

struct Node *extractmin_arrQueue(struct arrQueue *queue);

void enqueue(struct arrQueue *queue, struct Node *elem);

struct Node *newNode(int to_id, float weight);

void relax(struct Graph *graph, struct arrQueue *queue, struct Node *u, int v, float weight);

void dijkstra(struct Graph *graph, int source);

void dijkstra_heap(struct Graph *graph, int source);

void printPath(struct Graph *graph);

void free_queue(struct arrQueue *queue);

void relax_heap(struct Graph *graph, struct heap *queue, struct Node *node_u, int v, float weight);

#endif