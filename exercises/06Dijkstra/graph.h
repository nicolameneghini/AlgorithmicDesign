#ifndef __GRAPH__
#define __GRAPH__
#include <stdlib.h>

struct Node
{
    int id;
    int to_id;
    float weight;
    float distance;
    struct Node *pred;
    struct Node *next;
};

//each list contains a pointer to the head

struct List
{
    struct Node *head;
};

//the graph contains a vector of lists

struct Graph
{
    int V;                    //number of nodes
    struct List *adjencyList; //the graph is an array of lists
};

struct Graph *newGraph(int V);

void addEdge(struct Graph *graph, int from_id, int to_id, int weight);

void printGraph(struct Graph *graph);

void init_SSSP(struct Graph *graph);

void node_swap(struct Node *a, struct Node *b);

void free_graph(struct Graph *graph);

void free_node(struct Node *node);

void free_list(struct List *list);

#endif