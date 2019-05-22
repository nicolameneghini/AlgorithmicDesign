#include <stdlib.h>
#include <stdio.h>
#include "Dijkstra.h"
#include "queue.h"

//------------------- ***** DIJKSTRA ***** ---------------------------

void init_SSSP(struct Graph *graph)
{

    for (unsigned int i = 0; i < graph->V; ++i)
    {
        struct Node *node = graph->adjencyList[i].head;
        node->id = i;
        while (node)
        {
            node->distance = INT64_MAX;
            node->pred = NULL;
            node = node->next;
        }
    }
}

//update distances if smaller than the previous and then enqueues the node

void relax(struct Graph *graph, struct arrQueue *queue, struct Node *node_u, int v, float weight)
{

    struct Node *node_v = graph->adjencyList[v].head;

    if (node_u->distance + weight < node_v->distance)
    {

        while (node_v)
        {
            node_v->distance = node_u->distance + weight;
            node_v->pred = node_u;
            enqueue(queue, node_v);
            struct Node *node = graph->adjencyList[node_v->to_id].head;
            node->distance = node_v->distance + node_v->weight;
            //node_u = node_v;
            enqueue(queue, node);
            node_v = node_v->next;
        }
    }
}

void dijkstra(struct Graph *graph, int source)
{

    init_SSSP(graph);
    struct arrQueue *queue = build_arrQueue(graph->V);

    struct Node *node_s = graph->adjencyList[source].head;

    while (node_s)
    {
        node_s->distance = 0;
        struct Node *node = graph->adjencyList[node_s->to_id].head;
        node->distance = node_s->weight;
        enqueue(queue, node);
        node_s = node_s->next;
    }

    while (queue->size >= 0)
    {
        struct Node *node_u = extractmin_arrQueue(queue);

        while (node_u)
        {
            relax(graph, queue, node_u, node_u->to_id, node_u->weight);
            node_u = node_u->next;
        }
    }
}

void relax_heap(struct Graph *graph, struct heap *queue, struct Node *node_u, int v, float weight)
{

    struct Node *node_v = graph->adjencyList[v].head;

    if (node_u->distance + weight < node_v->distance)
    {

        while (node_v)
        {
            node_v->distance = node_u->distance + weight;
            node_v->pred = node_u;
            Insert_Key(queue, node_v);
            struct Node *node = graph->adjencyList[node_v->to_id].head;
            node->distance = node_v->distance + node_v->weight;
            //node_u = node_v;
            Insert_Key(queue, node);
            node_v = node_v->next;
        }
    }
}

void dijkstra_heap(struct Graph *graph, int source)
{
    init_SSSP(graph);
    struct heap *queue = heap_constructor(graph->V);

    struct Node *node_s = graph->adjencyList[source].head;

    int count = 0;
    while (node_s)
    {
        node_s->distance = 0;
        struct Node *node = graph->adjencyList[node_s->to_id].head;
        node->distance = node_s->weight;
        Insert_Key(queue, node);
        count++;
        node_s = node_s->next;
    }
    Heapify(queue, 0);

    while (queue->size > 0)
    {

        struct Node *node_u = Minimum(queue); //Remove_Minimum(queue);

        while (node_u)
        {
            relax_heap(graph, queue, node_u, node_u->to_id, node_u->weight);
            node_u = node_u->next;
        }

        Remove_Minimum(queue);
    }

    destructor(queue);
}

void printPath(struct Graph *graph)
{

    for (unsigned int i = 0; i < graph->V; ++i)
    {
        struct Node *node = graph->adjencyList[i].head;
        printf("Vertex          Distance from source\n");

        printf("%d               %f\n", i, node->distance);
        node = node->next;

        printf("\n");
    }
}
