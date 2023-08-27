#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void DFS(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    // Uncomment the line below if the graph is undirected
    // adjacencyList[v].push_back(u);
}

void Graph::DFS(int startVertex) {
    vector<bool> visited(vertices, false);
    stack<int> dfsStack;

    dfsStack.push(startVertex);

    while (!dfsStack.empty()) {
        int currentVertex = dfsStack.top();
        dfsStack.pop();

        if (!visited[currentVertex]) {
            cout << currentVertex << " ";
            visited[currentVertex] = true;
        }

        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                dfsStack.push(neighbor);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter " << edges << " edges in the format (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS traversal starting from vertex " << startVertex << ":\n";
    graph.DFS(startVertex);

    return 0;
}
