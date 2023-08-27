#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) : numVertices(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        // For undirected graph, you can also set adjMatrix[dest][src] = 1;
    }

    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> stack;

        visited[startVertex] = true;
        stack.push(startVertex);

        cout << "DFS traversal starting from vertex " << startVertex << ": ";
        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            cout << currentVertex << " ";

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    Graph graph(numVertices);

    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    graph.DFS(startVertex);

    return 0;
}
