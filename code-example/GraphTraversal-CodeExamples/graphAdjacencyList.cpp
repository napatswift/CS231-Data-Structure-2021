#include <iostream>
#include <vector>
using namespace std;
#define NMAX 500

vector<int>* createGraph()
{
    return new vector<int>[NMAX];
}

void addEdge(vector<int>* adjList, int u, int v)
{
    adjList[u].push_back(v);
}

void printGraph(vector<int>* adjList, int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "[" << v << "] head ";
        for(int i=0; i < adjList[v].size(); i++)
            cout << "-> " << adjList[v].at(i);
        cout << endl;
    }
    cout << endl;
}

void addVertex(int &n, int u) 
{
    n = u+1;
}

void removeEdge(vector<int>* adjList, int u, int v)
{
    for(int i=0; i<adjList[u].size(); i++)
        if(adjList[u].at(i) == v) {
            adjList[u].erase(adjList[u].begin()+i);
            return;
        } 
}

void removeVertex(vector<int>* adjList,int &n, int u) 
{
    if(u < n-1)
        return;
    for(int v=0; v<n; v++)
        removeEdge(adjList, v, u);
    adjList[u].clear();
    n--;
}

bool isAdjacent(vector<int>* adjList, int u, int v)
{
    for(int i=0; i<adjList[u].size(); i++)
        if(adjList[u].at(i) == v)
            return true;
    return false;
}

int inDegree(vector<int>* adjList, const int n,  int u) {
    int count = 0;
    for(int v=0; v<n; v++)
        for(int i=0; i<adjList[v].size(); i++)
            if(adjList[v].at(i) == u)
                count++;
    return count;
}

int outDegree(vector<int>* adjList, int u) {
    return adjList[u].size();
}

int main()
{
    int n = 5;

    vector<int>* adjList = createGraph();
    
    //Vertex numbers should be from 0 to 4.
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 4, 3);
    printGraph(adjList, n);

    addVertex(n, 5);
    addEdge(adjList, 5, 2);
    addEdge(adjList, 2, 5);
    printGraph(adjList, n);
    removeVertex(adjList, n, 5);
    printGraph(adjList, n);

    cout << "indeg(" << 1 <<") = " << inDegree(adjList, n, 1) << endl;
    cout << "outdeg(" << 1 <<") = " << outDegree(adjList, 1) << endl;

    removeEdge(adjList, 0, 3);
    removeEdge(adjList, 1, 2);
    removeEdge(adjList, 4, 3);

    printGraph(adjList, n);

    return 0;
}
