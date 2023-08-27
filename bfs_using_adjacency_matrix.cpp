#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS using adjacency matrix
void bfs(const vector<vector<int>>& graph, int startNode, vector<bool>& visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (graph[currentNode][neighbor] == 1 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes, 0));
    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        adjacencyMatrix[node1][node2] = 1;
        adjacencyMatrix[node2][node1] = 1; // For undirected graph
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    vector<bool> visited(numNodes, false);
    cout << "BFS traversal starting from node " << startNode << ": ";
    bfs(adjacencyMatrix, startNode, visited);

    return 0;
}
