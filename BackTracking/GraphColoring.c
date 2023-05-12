#include <stdio.h>
#include <stdbool.h>

#define MAX 100
int n_vertices, n_edges, n_colors;
int colors[MAX];
int graph[MAX][MAX];

//bounding function checks if color is valid
bool isSafe(int vertex, int color) {
    for (int i=0; i<n_vertices; i++) {    // i < vertex ??
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// recursive function that checks all colors until success 
bool graphColoring(int vertex) {
    if (vertex == n_vertices) { // we reached till last depth all assigned colors
        return true;
    }

    for (int i=1; i<=n_colors; i++) {
        if (isSafe(vertex, i)) {
            colors[vertex] = i; 
        
            if (graphColoring(vertex + 1)) { // true is returned continuously  till some node 
                return true;
            }    
            //if false is returned by v+1 then the given v is assigned invaid color so reset and try other colors
            colors[vertex] = 0;
        }
    }
    // all colors tried and no color available
    return false;
}

int main() {
    printf("Enter the number of vertices : ");
    scanf("%d",&n_vertices);
    printf("Enter the number of edges : ");
    scanf("%d",&n_edges);
    printf("Enter the number of colors : ");
    scanf("%d",&n_colors);
    int i, j;

    // set array of colors to 0 and graph to 0
    for (i=0; i<n_vertices; i++) {
        colors[i] = 0;
        for (j=0; j<n_vertices; j++) {
            graph[i][j] = 0;
        }
    }
    // edges to 1
    for (i=0; i<n_edges; i++) {
        int u, v;
        printf("Enter the edge %d (both vertices) : ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    // we received true meaning all vertices have been allocated a color
    if (graphColoring(0)) {
        printf("The vertices can be coloured with %d colours\n",n_colors);
        for (i=0; i<n_vertices; i++) {
            printf("Vertex %d : %d \n", i, colors[i]);
        }
    }
    else {
        printf("The vertices cannot be coloured with %d colours.\n");
    }

    return 0;
}
