#include <iostream>
#include <vector>
#include <queue>
#include <boost/lambda/lambda.hpp>
using namespace std;


vector<int>* createGraph(int n_node){
    return new vector<int>[n_node];
}

void addEdge(vector<int> adj[], int src, int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void find_paths(vector<vector<int> >& paths, vector<int>& path, vector<int> parent[], int n, int u)
{
    if (u == -1) {
        paths.push_back(path);
        return;
    }
    for (int par:parent[u]) {
        path.push_back(u);
        find_paths(paths, path, parent, n, par);
        path.pop_back();
    }
}

void bfs(vector<int>* adj, vector<int>* parent, int n, int start)
{
    vector<int> dist(n, INT_MAX);

    queue<int> q;

    q.push(start);
    parent[start] = { -1 };
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {

                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            else if (dist[v] == dist[u] + 1) {

                parent[v].push_back(u);
            }
        }
    }
}

void printShortestPath(vector<int>* adjList, int n, int start, int end)
{
    vector<vector<int> > paths;
    vector<int> path;
    vector<int> parent[n];

    bfs(adjList, parent, n, start);

    find_paths(paths, path, parent, n, end);

    vector<int> temp, result;
    int i = 0, sum = INT_MAX;
    for (auto v : paths) {

        reverse(v.begin(), v.end());

        for (int u : v) 
            temp.push_back(u);
        
        if(accumulate(temp.begin(), temp.end(), 0) < sum){
            sum = accumulate(temp.begin(), temp.end(), 0);
            result = temp;
            temp.clear();
        }
    }

    vector<int>::iterator it;
    int counter;
    if(result.size() != 0){
        cout << "Shortest road length is: " << result.size()-1 << endl;
        cout << "Road path: ";
        for(it = result.begin(), counter = 0; it != result.end(); it++, counter++)
            printf("%d%s", *it, counter < result.size()-1 ? " -> " : "");
    } else
        cout << "Both towns are not connected";
}

int main()
{
    int n;
    int edge;

    cin >> n;
    cin >> edge;

    vector<int>* graph = createGraph(n);

    int u, v;
    int i;
    for(i = 0; i < edge; i++){
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    scanf("%d %d", &u, &v);

    printShortestPath(graph, n, u, v);

    return 0;
}
