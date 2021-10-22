 // A simple adjacency-matrix representation of graph using 2D array
#include<stdio.h>
#include<stdlib.h>
// Function to create a graph with n vertices
int** createGraph(const int n) {
    // Return 2D array of size n*n
    int** adjMatrix = malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++) {
        adjMatrix[i] = malloc(sizeof(int)*n);
        for (int j=0; j<n; j++)
            adjMatrix[i][j] = 0;
    }
    return adjMatrix;
}

//Function to add a directed edge into the graph
void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}
// Function to print the adjacency list representation of graph
void printGraph(int** adjMatrix, int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void deleteGraph(int** adjMatrix, int n){
    for (int i=0; i<n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

// Driver code
int main()
{
    int n = 5;

    int** adjMatrix = createGraph(n);
    
    //Vertex numbers should be from 0 to 4
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 4, 3);
    
    printGraph(adjMatrix, n);
    deleteGraph(adjMatrix, n);
    return 0;
}
