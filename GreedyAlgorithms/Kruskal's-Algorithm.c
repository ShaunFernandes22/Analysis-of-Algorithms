#include <stdio.h>
#define VER 5
# define MAX 9000

// Disjoint set : union, find 

//finds the absolute parent
int find(int i, int parent[]) {
    int j;
    while (parent[i] != i) {
        j = parent[i];
        parent[i] = parent[j];
        i = j;
    }
}

// gives union of two disjoint sets by making their absolute parent one
void union1(int i, int j, int parent[], int rank[])  {
    int a = find(i, parent);
    int b = find(j, parent);
    if (rank[a] < rank[b]) // rank of bigger is made the absolute parent of the other and nochange in rank
        parent[a] = b;
    else if (rank[a] > rank[b]) 
        parent[b] = a;
    else { // rank is same so we can make anyone parent but the parent's rank increments by 1
        parent[a] = b;
        rank[b]++;
    }
}

//implements kruskal algo
void kruskal(int graph[][VER]) {
    int i, j, min, edges = 0;
    int a, b;
    int parent[VER], rank[VER];
    int min_cost = 0; // total min spanning tree weight

    for (i=0; i<VER; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    while (edges < VER - 1) {  // there are V-1 edges in a spanning tree
        min = MAX, a=-1, b=-1;
        for (i=0; i<VER; i++) {
            for (j=0; j<VER; j++) {
                //pick min edge from graph such that both vertices are disjoint i.e. their absolute parents are different
                // this avoids cycles
                if ((find(i, parent) != find(j, parent)) && graph[i][j] < min) {
                    a = i;
                    b = j;
                    min = graph[i][j];
                }
            }
        }
        // include a and b in a single set
        union1(a, b, parent, rank);
        edges++;
        min_cost += min; 
        printf("Edge %d : %d -- %d \t= %d\n",edges, a, b, graph[a][b]);
    }

    printf("Minimum cost (i.e. total weight of tree) = %d\n",min_cost);
}

int main() {
    // all nonexistent edges are MAX so that it is easier to pick the min edge
    int graph[][VER] = {{MAX, 2, MAX, 6, MAX},
                        {2, MAX, 3, 8, 5},
                        {MAX, 3, MAX, MAX, 7},
                        {6, 8, MAX, MAX, 9},
                        {MAX, 5, 7, 9, MAX}};
    
    kruskal(graph);                    
    
    return 0;
}
