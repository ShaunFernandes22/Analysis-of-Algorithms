#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define Vertices 9

void initializeSingleSource();
int minDistance();
void dijkstra();
void printTable();

int main () {
                                    //  0   1  2  3  4  5  6  7  8   adjacency matrix of weights
    int graph[Vertices][Vertices] = { { 0, 11, 0, 0, 0, 0, 0, 8, 0 },   // 0
                                      { 11, 0, 8, 0, 0, 0, 0, 11, 0 },  // 1
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },    // 2
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },   // 3
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },   // 4
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },  // 5
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },    // 6
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },   // 7
                                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};   // 8
                
    int source = 0;

    int distance[Vertices], parent[Vertices];
    bool visited[Vertices];

    initializeSingleSource(distance, parent, visited, source);

    dijkstra(graph, distance, visited, parent, source);
    
    printTable(distance, parent);
   
}

//function to initialize the distances to infinity and parents to null initially
void initializeSingleSource(int distance[], int parent[], bool visited[], int source)
{
    int i;
    for (i=0; i< Vertices; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    //source to itself
    distance[source] = 0;
}

//function which identifies the vertex not visited and having minimum distance from source 
int minDistance(int distance[], bool visited[]) {
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < Vertices; v++)
        if (visited[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;
 
    return min_index;
}

/*function which updates the value of distance 
     void relax(int u, int v, int graph[][Vertices], int distance[], int parent[])
    {
        distance[v] = distance[u] + graph[u][v];
        parent[v] = u;   
    }*/

//function to identify whether the  condition is applicable for given pair of nodes
void dijkstra(int graph[][Vertices], int distance[], bool visited[], int parent[], int source)
{
    int u, count;
    for (count = 0; count < Vertices - 1; count++) {
        int u = minDistance(distance, visited);

        int v;
        for (int v = 0; v < Vertices; v++)
        {
            //included relax inside for reducing complexity
            if (graph[u][v] && distance[v] > distance[u] + graph[u][v])
            {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
                //relax(u, v, graph, distance, parent);
            }
        }
        visited[u] = true;
    }
}

void printTable(int distance[], int parent[])
{
    printf("Vertex\tDistance\tparent\n");
    for(int i=0; i<Vertices; i++)
        printf("\t%d\t\t%d\t\t%d\n", i, distance[i], parent[i]);
}
