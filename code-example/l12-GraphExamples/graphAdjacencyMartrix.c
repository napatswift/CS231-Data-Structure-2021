#include <stdio.h>
#include <stdlib.h>

int** createGraph(const int n) {
    int** adjMatrix = malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++) {
        adjMatrix[i] = malloc(sizeof(int)*n);
        for (int j=0; j<n; j++)
            adjMatrix[i][j] = 0;
    }
    return adjMatrix;
}


void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}


void printGraph(int** adjMatrix, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void deleteGraph(int** adjMatrix, int n){
    for (int i=0; i<n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}

int** addVertex(int** adjMatrix, int *n, int u) { 
    int** adjMatrix_new = createGraph(u+1);
    for (int i=0; i<*n; i++) {
        for (int j=0; j<*n; j++) 
            if(adjMatrix[i][j] == 1)
                adjMatrix_new[i][j] = 1;
    }
    deleteGraph(adjMatrix, *n);
    *n = u+1;
    return adjMatrix_new;
}

void removeEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 0;
}

int** removeVertex(int** adjMatrix, int* n, int u) {
    for (int i=0; i<*n; i++)
        for (int j=u; j<*n-1; j++)
            adjMatrix[i][j] = adjMatrix[i][j+1];

    for (int i=0; i<*n; i++)
        for (int j=u; j<*n-1; j++)
            adjMatrix[j][i] = adjMatrix[j+1][i];

    int** adjMatrix_new = createGraph(*n-1);
    for (int i=0; i<*n-1; i++)
        for (int j=0; j<*n-1; j++) 
            adjMatrix_new[i][j] = adjMatrix[i][j];
    deleteGraph(adjMatrix, *n);
    (*n)--;
    return adjMatrix_new;
}

int isAdjacent(int** adjMatrix, int u, int v) {
    if(adjMatrix[u][v] == 1)
        return 1;
    else
        return 0;
}

int outDegree(int** adjMatrix, const int n, int u) {
    int out_deg = 0;
    for(int i=0; i<n; i++) {
        if(adjMatrix[u][i])
            out_deg++;
    }
    return out_deg;
}

int inDegree(int** adjMatrix, const int n, int u) {
    int in_deg = 0;
    for(int i=0; i<n; i++) {
        if(adjMatrix[i][u])
            in_deg++;
    }
    return in_deg;
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

    adjMatrix = addVertex(adjMatrix, &n, 5);
    addEdge(adjMatrix, 5, 1);
    printGraph(adjMatrix, n);

    printf("indeg(%d) = %d \n", 1, inDegree(adjMatrix, n, 1));
    printf("outdeg(%d) = %d \n", 1, outDegree(adjMatrix, n, 1));


    removeEdge(adjMatrix, 4, 3);
    printGraph(adjMatrix, n);

    adjMatrix = removeVertex(adjMatrix, &n, 5);

    printGraph(adjMatrix, n);
    
    deleteGraph(adjMatrix, n);
    return 0;
}
