#include <stdio.h>
#include <stdbool.h>

#define VER 9
#define INFINITY 10000

int minKey(int key[], bool mst_set[]) {
    int min=INFINITY, min_index;

    for (int i=0; i<VER; i++) {
        if (key[i]<min && mst_set[i]== false) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printEdges(int key[], int parent[]) {
    printf("Edge \t Weight\n");
    for (int v=1; v<VER; v++) {
        printf("%d - %d \t\t%d\n",parent[v], v, key[v]);
    }
}

void prims(int graph[][VER]) {
    bool mst_set[20];
    int key[20], parent[20];
    int i;

    for (i=0; i<VER; i++) {
        mst_set[i] = false;
        key[i] = INFINITY;
    }

    key[0] = 0;
    parent[0] = -1;

    for (i=0; i<VER-1; i++) {
        int u = minKey(key, mst_set);
        mst_set[u] = true;

        for (int v=0; v<VER; v++) {
            if (graph[u][v] && mst_set[v]==false && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printEdges(key, parent);
}

int main() {
    int graph[][VER] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}};
                        
    prims(graph);
    
    return 0;
}
