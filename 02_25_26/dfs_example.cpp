#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Remove for directed graph
    }

    // DFS using recursion (iterative approach below)
    void dfsRecursive(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor : adjList[start]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    // DFS using stack (iterative approach)
    void dfsIterative(int start) {
        vector<bool> visited(numVertices, false);
        stack<int> stk;

        stk.push(start);

        while (!stk.empty()) {
            int vertex = stk.top();
            stk.pop();

            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;

                // Add neighbors in reverse order to maintain left-to-right traversal
                for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); ++it) {
                    if (!visited[*it]) {
                        stk.push(*it);
                    }
                }
            }
        }
    }

    // DFS with path tracking
    void dfsWithPath(int start, int end) {
        vector<bool> visited(numVertices, false);
        vector<int> path;

        if (dfsHelper(start, end, visited, path)) {
            cout << "Path found: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            cout << "No path exists from " << start << " to " << end << endl;
        }
    }

private:
    bool dfsHelper(int current, int target, vector<bool>& visited, vector<int>& path) {
        visited[current] = true;
        path.push_back(current);

        if (current == target) {
            return true;
        }

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                if (dfsHelper(neighbor, target, visited, path)) {
                    return true;
                }
            }
        }

        // Backtrack
        path.pop_back();
        return false;
    }
};

int main() {
    cout << "=== DFS Example ===" << endl << endl;

    // Create a sample graph
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 4);

    cout << "Graph structure:" << endl;
    cout << "    0" << endl;
    cout << "   / \\" << endl;
    cout << "  1    2" << endl;
    cout << " / \\   |" << endl;
    cout << "3    4  5" << endl << endl;

    // Iterative DFS
    cout << "Iterative DFS from vertex 0: ";
    g.dfsIterative(0);
    cout << endl << endl;

    // Recursive DFS
    vector<bool> visited(6, false);
    cout << "Recursive DFS from vertex 0: ";
    g.dfsRecursive(0, visited);
    cout << endl << endl;

    // Path finding
    cout << "Path from 0 to 5:" << endl;
    g.dfsWithPath(0, 5);

    cout << "\nPath from 0 to 4:" << endl;
    g.dfsWithPath(0, 4);

    cout << "\nPath from 1 to 5 (no path):" << endl;
    g.dfsWithPath(1, 5);

    return 0;
}
