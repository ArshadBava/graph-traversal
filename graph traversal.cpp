#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int v) : vertices(v) {
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter starting vertex for BFS: ";
    cin >> startVertex;
    cout << "BFS Traversal: ";
    g.BFS(startVertex);

    cout << "Enter starting vertex for DFS: ";
    cin >> startVertex;
    cout << "DFS Traversal: ";
    g.DFS(startVertex);

    return 0;
}

