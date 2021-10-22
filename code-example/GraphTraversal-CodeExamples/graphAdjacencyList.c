#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int adj_vertex;
	struct Node* next;
	
};

struct Node** createGraph(int n)
{
	struct Node** adjList = malloc(sizeof(struct Node*)*n);
	for(int i=0; i<n; i++) {
		adjList[i] = NULL;
	}
    return adjList;
}


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
    printf("\n");
}

void deleteGraph(struct Node** adjList, int n) {
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

struct Node** addVertex(struct Node** adjList, int *n, int u) { 
    struct Node** new_adjList = createGraph(u+1);
    for (int i=0; i<*n; i++) {
        new_adjList[i] = adjList[i];
        adjList[i] = NULL;
    }
    deleteGraph(adjList, *n);
    *n = u+1;
    return new_adjList;
}

void removeEdge(struct Node** adjList, int u, int v)
{
    struct Node* node = adjList[u];
    if(node->adj_vertex == v) {
        adjList[u] = node->next;
        free(node);
    } else {
        struct Node* prev_node = node;
        node = node->next;
        while(node->adj_vertex != v) {
            prev_node = node;
            node = node->next;
        }
        prev_node->next = node->next;
        free(node);
    }
}

int isAdjacent(struct Node** adjList, int u, int v) {
    struct Node* node = adjList[u];
    int ret = 0;
    while(node != NULL) {
        if(node->adj_vertex == v)
            ret = 1;
        node = node->next;
    }
    return ret;   
}

void removeVertex(struct Node** adjList, int *n, int u) { 
    
    for(int v=0; v<*n; v++) {
        if(isAdjacent(adjList, v, u) == 1)
            removeEdge(adjList, u, v);
    }
    struct Node* node = adjList[u];
    while(node != NULL) {
        struct Node* next_node = node->next;
        free(node);
        node = next_node;
    } 
    adjList[u] = NULL;
    if(u < *n-1)
        return;
    (*n)--;
}



int inDegree(struct Node** adjList, int n, int u) {
    int in_deg = 0;

    for(int i=0; i<n; i++) {
         struct Node* node = adjList[i];
         while(node) {
            if(node->adj_vertex == u)
                in_deg++;
            node = node->next;
         }
    }
    return in_deg;   
}



int outDegree(struct Node** adjList, int n, int u) {
    struct Node* node = adjList[u];
    int out_deg = 0;
    while(node != NULL) {
        out_deg++;
        node = node->next;
    }
    return out_deg;   
}


// Driver code
int main()
{
    int n = 5;
    
    struct Node** adjList = createGraph(n);
    
    //Vertex numbers should be from 0 to 4
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 4, 3);
    printGraph(adjList, n);

    adjList = addVertex(adjList, &n, 5);
    
    addEdge(adjList, 5, 1);
    printGraph(adjList, n);

    
    printf("indeg(%d) = %d \n", 1, inDegree(adjList, n, 1));
    printf("outdeg(%d) = %d \n", 1, outDegree(adjList, n, 1));

    removeEdge(adjList, 4, 3);
    printGraph(adjList, n);

    removeVertex(adjList, &n, 5);

    printGraph(adjList, n);
    
    deleteGraph(adjList, n);
    
    return 0;
}
