#include <stdio.h>
#include <math.h>
#include "Dijkstra.h"

int main()
{
    int j = 1;
    int V = 6;
    int source = 0;

    struct Graph *graph = newGraph(V);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 5, 15);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 5, 5, 0);

    dijkstra(graph, source);

    printGraph(graph);
    printPath(graph);
    free_graph(graph);

    printf("---END OF GRAPH1---\n");

    int V1 = 7;
    struct Graph *graph1 = newGraph(V1);
    addEdge(graph1, 0, 1, 5);
    addEdge(graph1, 1, 2, 3);
    addEdge(graph1, 2, 3, 12);
    addEdge(graph1, 3, 6, 1);
    addEdge(graph1, 0, 4, 6);
    addEdge(graph1, 4, 5, 4);
    addEdge(graph1, 5, 6, 2);
    addEdge(graph1, 6, 6, 0);

    source = 0;

    dijkstra(graph1, source);

    printGraph(graph1);
    printPath(graph1);
    free_graph(graph1);

    printf("---END OF GRAPH2---\n");

    int V2 = 5;
    struct Graph *graph2 = newGraph(V2);
    addEdge(graph2, 0, 2, 6);
    addEdge(graph2, 2, 1, 3);
    addEdge(graph2, 2, 3, 1);
    addEdge(graph2, 0, 1, 2);
    addEdge(graph2, 1, 4, 9);
    addEdge(graph2, 3, 4, 4);
    addEdge(graph2, 4, 4, 0);

    source = 0;

    dijkstra(graph2, source);

    printGraph(graph2);

    printPath(graph2);

    free_graph(graph2);

    printf("---END OF GRAPH2---\n");

    return 0;
}