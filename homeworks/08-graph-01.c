#include<stdio.h>
#include<stdlib.h>

int** creatMatrixNxN(int dim){
    int** adjMatrix = malloc(sizeof(int* ) * dim);
    int i, j;
    for (i=0;i<dim;i++){
        adjMatrix[i] = malloc(sizeof(int) * dim);
        for(j=0;j<dim;j++)
            adjMatrix[i][j] = 0;
    }
    return adjMatrix;
}

void addEdge(int** adjMatrix, int orig, int dest){
    // matrix is zero-indexed (zero-based) not one-indexed,
    // so subtracted by 1 to be zero-indexed
    adjMatrix[orig - 1][dest - 1] = 1;
}

void printGraph(int** adjMatrix, int dim){
    for (int i=0;i<dim;i++){
        for(int j=0;j<dim;j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

int main(){
    int n = 5;
    int** adjMatrix = creatMatrixNxN(n);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 5);
    addEdge(adjMatrix, 3, 4);
    addEdge(adjMatrix, 3, 1);
    addEdge(adjMatrix, 4, 5);
    printGraph(adjMatrix, n);
    return 0;
}
