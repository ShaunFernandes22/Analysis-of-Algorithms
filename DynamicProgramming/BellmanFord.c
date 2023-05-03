#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Vertices 5

//function to initialize the distances to infinity and parents to null initially
void initializeSingleSource(int distance[], int parent[], int source)
{
    int i;
    for (i=0; i< Vertices; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[source] = 0; //source to itself
}

// the algorithm for all combinations of vertices edges
void bellmanFord(int graph[][Vertices], int distance[], int parent[], int source)
{
    int u, v;
    for (u=0; u<Vertices; u++)
    {
        for (v=0; v<Vertices; v++)
        {
            if (graph[u][v]!=0 && distance[u]+graph[u][v] < distance[v]) // relax
            {
                distance[v] = distance[u]+graph[u][v];
                parent[v] = u;
            }
        }
    }
}

void printTable(int distance[], int parent[])
{
    printf("Vertex\tDistance\tparent\n");
    for(int i=0; i<Vertices; i++)
    {
        printf("\t%d\t\t%d\t\t%d\n", i, distance[i], parent[i]);
    }
}

int main () {
                                //   s  t  x  y  z  
   int graph[Vertices][Vertices] = {{0, 6, 0, 7, 0},  //s
                                    {0, 0, 5, 8, -4}, //t
                                    {0, -2, 0, 0, 0}, //x
                                    {0, 0, -3, 0, 9}, //y          
                                    {2, 0, 7, 0, 0}}; //z          
    
    int source = 0;
    int distance[Vertices], parent[Vertices];

    initializeSingleSource(distance, parent, source);

    // A node can be having at most V-1 edges from source
    for (int i=0; i<Vertices-1; i++)
        bellmanFord(graph, distance, parent, source);

    printTable(distance, parent);
    
    return 0;                                   
}                                
