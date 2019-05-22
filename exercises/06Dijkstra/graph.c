#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

struct Node *newNode(int to_id, float weight)
{
    struct Node *my_newNode = (struct Node *)malloc(sizeof(struct Node));

    my_newNode->to_id = to_id;
    my_newNode->weight = weight;
    my_newNode->next = NULL;

    return my_newNode;
}

void node_swap(struct Node *a, struct Node *b)
{
    struct Node tmp = *b;
    *b = *a;
    *a = tmp;
}

//allocate space for a new graph. This also implues I have to allocate the space for a list of nodes (all intitalized to NULL)
struct Graph *newGraph(int V)
{
    struct Graph *newGraph = (struct Graph *)malloc(sizeof(struct Graph));
    newGraph->V = V;
    newGraph->adjencyList = (struct List *)malloc(V * sizeof(struct List));

    for (unsigned int i = 0; i < newGraph->V; i++)
        newGraph->adjencyList[i].head = NULL;

    return newGraph;
}

void free_list(struct List *list)
{
    free_node(list->head);
}

void free_graph(struct Graph *graph)
{
    for (unsigned int i = 0; i < graph->V; i++)
        free_list(&graph->adjencyList[i]);
}

//prints the graph
void printGraph(struct Graph *graph)
{
    for (unsigned int i = 0; i < graph->V; ++i)
    {
        struct Node *node = graph->adjencyList[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);

        while (node)
        {
            printf("-> %d, %f", node->to_id, node->weight);
            node = node->next;
        }
        printf("\n");
    }
}

void free_node(struct Node *node)
{
    free(node);
}

//creates the next node and inittalizes the weight (by calling newNode)
void addEdge(struct Graph *graph, int from_id, int to_id, int weight)
{
    struct Node *my_newNode = newNode(to_id, weight);
    my_newNode->next = graph->adjencyList[from_id].head;
    graph->adjencyList[from_id].head = my_newNode;
}
