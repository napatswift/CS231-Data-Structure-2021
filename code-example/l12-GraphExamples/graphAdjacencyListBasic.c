// A simple adjacency-list representation of graph
#include <stdio.h>
#include <stdlib.h>

// Implementation of singly linked list
struct Node
{
    int adj_vertex;
    struct Node* next;
    
};

// Function to create a graph with n vertices
struct Node** createGraph(int n)
{
    // Return array of n lists (vectors)
    struct Node** adjList = malloc(sizeof(struct Node*)*n);
    for(int i=0; i<n; i++) {
        adjList[i] = NULL;
    }
    return adjList;
}

// Function to add a directed edge into the graph
void addEdge(struct Node** adjList, int u, int v)
{
    struct Node* node = adjList[u];
    if(node == NULL) {
        node = malloc(sizeof(struct Node));
        node->adj_vertex = v;
        node->next = NULL;
        adjList[u] = node;
    } else {
        while(node->next != NULL)
            node =  node->next;
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->adj_vertex = v;
        new_node->next = NULL;
        node->next = new_node;
    }
}

//Function to print the adjacency list representation of the graph
void printGraph(struct Node** adjList, int n)
{
    for (int u = 0; u < n; u++)
    {
        printf("[%d] head: ", u);

        struct Node* node = adjList[u];
        
        while(node) {
            printf("-> %d ", node->adj_vertex);
            node = node->next;
        }

        printf("-> NULL \n");
    }
}

void deleteGraph(struct Node** adjList, int n){
    for (int u=0; u<n; u++) {
        struct Node* node = adjList[u];
        while(node != NULL) {
            struct Node* next_node = node->next;
            free(node);
            node = next_node;
        } 
    }
    free(adjList);
}

// Driver code
int main()
{
    int n = 5;

    struct Node** adjList = createGraph(n);
    
    //Vertex numbers should be from 0 to 4.
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 4, 3);
   
    printGraph(adjList, n);
    deleteGraph(adjList, n);
    return 0;
}
